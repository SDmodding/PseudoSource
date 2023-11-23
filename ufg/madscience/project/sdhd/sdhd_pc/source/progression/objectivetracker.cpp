// File Line: 19
// RVA: 0x151C890
__int64 dynamic_initializer_for__ObjectiveSym_INACTIVE__()
{
  ASymbol::create(&ObjectiveSym_INACTIVE, "INACTIVE", 0xFFFFFFFF, ATerm_long);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ObjectiveSym_INACTIVE__);
}

// File Line: 31
// RVA: 0x151B6D0
__int64 UFG::_dynamic_initializer_for__CoronaInfos__()
{
  unsigned int v0; // eax
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  __int64 result; // rax

  UFG::CoronaInfos[0].coronaName = UFG::qStringHashUpper32("Corona_walkEvent", -1);
  UFG::CoronaInfos[0].coronaHeight = 0.02;
  UFG::CoronaInfos[1].typeName = "social_job";
  v0 = UFG::qStringHashUpper32("Marker_Social", -1);
  UFG::CoronaInfos[1].coronaHeight = FLOAT_2_5;
  UFG::CoronaInfos[1].coronaName = v0;
  UFG::CoronaInfos[2].typeName = "drive_lead";
  UFG::CoronaInfos[2].coronaName = UFG::qStringHashUpper32("Corona_Event_Drive", -1);
  UFG::CoronaInfos[3].typeName = "cop_job";
  UFG::CoronaInfos[2].coronaHeight = 0.02;
  UFG::CoronaInfos[3].coronaName = UFG::qStringHashUpper32("Corona_Job_Drive", -1);
  UFG::CoronaInfos[3].coronaHeight = 0.02;
  UFG::CoronaInfos[4].typeName = "arrow_enemy";
  UFG::CoronaInfos[4].coronaName = UFG::qStringHashUpper32("HK_UI_ReticleTarget_Effect", -1);
  UFG::CoronaInfos[4].coronaHeight = 2.75;
  UFG::CoronaInfos[5].typeName = "arrow_objective";
  UFG::CoronaInfos[5].coronaName = UFG::qStringHashUpper32("Marker_Mission", -1);
  UFG::CoronaInfos[6].typeName = "arrow_hostile";
  UFG::CoronaInfos[5].coronaHeight = 2.75;
  v1 = UFG::qStringHashUpper32("Marker_Enemy", -1);
  UFG::CoronaInfos[6].coronaHeight = FLOAT_2_25;
  UFG::CoronaInfos[6].coronaName = v1;
  UFG::CoronaInfos[7].typeName = "arrow_hostile_truck";
  v2 = UFG::qStringHashUpper32("Marker_Enemy", -1);
  UFG::CoronaInfos[7].coronaHeight = FLOAT_3_75;
  UFG::CoronaInfos[7].coronaName = v2;
  UFG::CoronaInfos[8].typeName = "arrow_store";
  UFG::CoronaInfos[8].coronaName = UFG::qStringHashUpper32("Marker_Social", -1);
  UFG::CoronaInfos[9].typeName = "arrow_social";
  UFG::CoronaInfos[8].coronaHeight = 2.75;
  UFG::CoronaInfos[9].coronaName = UFG::qStringHashUpper32("Marker_Social", -1);
  UFG::CoronaInfos[9].coronaHeight = 2.75;
  UFG::CoronaInfos[10].typeName = "arrow_friendly";
  v3 = UFG::qStringHashUpper32("Marker_Friendly", -1);
  UFG::CoronaInfos[10].coronaHeight = 2.75;
  UFG::CoronaInfos[10].coronaName = v3;
  UFG::CoronaInfos[11].typeName = "arrow_race";
  UFG::CoronaInfos[11].coronaName = UFG::qStringHashUpper32("Marker_Mission", -1);
  UFG::CoronaInfos[11].coronaHeight = 2.75;
  UFG::CoronaInfos[12].typeName = "arrow_case";
  UFG::CoronaInfos[12].coronaName = UFG::qStringHashUpper32("Case_Arrow", -1);
  UFG::CoronaInfos[13].typeName = "walk_mission";
  UFG::CoronaInfos[12].coronaHeight = 2.75;
  UFG::CoronaInfos[13].coronaName = UFG::qStringHashUpper32("Corona_Mission_Walk", -1);
  UFG::CoronaInfos[13].coronaHeight = 0.02;
  UFG::CoronaInfos[14].typeName = "walk_event";
  UFG::CoronaInfos[14].coronaName = UFG::qStringHashUpper32("Corona_Event_Walk", -1);
  UFG::CoronaInfos[14].coronaHeight = 0.02;
  UFG::CoronaInfos[15].typeName = "walk_race";
  UFG::CoronaInfos[15].coronaName = UFG::qStringHashUpper32("Corona_Race_Walk", -1);
  UFG::CoronaInfos[16].typeName = "walk_case";
  UFG::CoronaInfos[15].coronaHeight = 0.02;
  UFG::CoronaInfos[16].coronaName = UFG::qStringHashUpper32("Corona_Case_Walk", -1);
  UFG::CoronaInfos[16].coronaHeight = 0.02;
  UFG::CoronaInfos[17].typeName = "walk_cop_job";
  UFG::CoronaInfos[17].coronaName = UFG::qStringHashUpper32("Corona_Case_Walk", -1);
  UFG::CoronaInfos[17].coronaHeight = 0.02;
  UFG::CoronaInfos[18].typeName = "walk_job";
  UFG::CoronaInfos[18].coronaName = UFG::qStringHashUpper32("Corona_Job_Walk", -1);
  UFG::CoronaInfos[19].typeName = "walk_hiding";
  UFG::CoronaInfos[18].coronaHeight = 0.02;
  UFG::CoronaInfos[19].coronaName = UFG::qStringHashUpper32("Corona_HidingSpot_Walk", -1);
  UFG::CoronaInfos[19].coronaHeight = 0.02;
  UFG::CoronaInfos[20].typeName = "walk_generic";
  UFG::CoronaInfos[20].coronaName = UFG::qStringHashUpper32("Corona_Generic_Walk", -1);
  UFG::CoronaInfos[20].coronaHeight = 0.02;
  UFG::CoronaInfos[21].typeName = "walk_store";
  UFG::CoronaInfos[21].coronaName = UFG::qStringHashUpper32("Corona_Store_Walk", -1);
  UFG::CoronaInfos[22].typeName = "walk_parking";
  UFG::CoronaInfos[21].coronaHeight = 0.02;
  UFG::CoronaInfos[22].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", -1);
  UFG::CoronaInfos[22].coronaHeight = 0.02;
  UFG::CoronaInfos[23].typeName = "walk_offensive";
  UFG::CoronaInfos[23].coronaName = UFG::qStringHashUpper32("Corona_Job_Walk", -1);
  UFG::CoronaInfos[24].typeName = "walk_defensive";
  UFG::CoronaInfos[23].coronaHeight = 0.02;
  UFG::CoronaInfos[24].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", -1);
  UFG::CoronaInfos[24].coronaHeight = 0.02;
  UFG::CoronaInfos[25].typeName = "walk_disabled";
  UFG::CoronaInfos[25].coronaName = UFG::qStringHashUpper32("Corona_walk_disabled", -1);
  UFG::CoronaInfos[25].coronaHeight = 0.02;
  UFG::CoronaInfos[26].typeName = "walk_bus_stop";
  UFG::CoronaInfos[26].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", -1);
  UFG::CoronaInfos[27].typeName = "walk_ferry";
  UFG::CoronaInfos[26].coronaHeight = 0.02;
  UFG::CoronaInfos[27].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", -1);
  UFG::CoronaInfos[27].coronaHeight = 0.02;
  UFG::CoronaInfos[28].typeName = "drive_mission";
  UFG::CoronaInfos[28].coronaName = UFG::qStringHashUpper32("Corona_Mission_Drive", -1);
  UFG::CoronaInfos[28].coronaHeight = 0.02;
  UFG::CoronaInfos[29].typeName = "drive_event";
  UFG::CoronaInfos[29].coronaName = UFG::qStringHashUpper32("Corona_Event_Drive", -1);
  UFG::CoronaInfos[30].typeName = "drive_race";
  UFG::CoronaInfos[29].coronaHeight = 0.02;
  UFG::CoronaInfos[30].coronaName = UFG::qStringHashUpper32("Corona_Race_Drive", -1);
  UFG::CoronaInfos[30].coronaHeight = 0.02;
  UFG::CoronaInfos[31].typeName = "drive_case";
  UFG::CoronaInfos[31].coronaName = UFG::qStringHashUpper32("Corona_Case_Drive", -1);
  UFG::CoronaInfos[31].coronaHeight = 0.02;
  UFG::CoronaInfos[32].typeName = "drive_job";
  UFG::CoronaInfos[32].coronaName = UFG::qStringHashUpper32("Corona_Job_Drive", -1);
  UFG::CoronaInfos[33].typeName = "drive_cop_job";
  UFG::CoronaInfos[32].coronaHeight = 0.02;
  UFG::CoronaInfos[33].coronaName = UFG::qStringHashUpper32("Corona_Case_Drive", -1);
  UFG::CoronaInfos[33].coronaHeight = 0.02;
  UFG::CoronaInfos[34].typeName = "drive_hiding";
  UFG::CoronaInfos[34].coronaName = UFG::qStringHashUpper32("Corona_HidingSpot_Drive", -1);
  UFG::CoronaInfos[34].coronaHeight = 0.02;
  UFG::CoronaInfos[35].typeName = "drive_generic";
  UFG::CoronaInfos[35].coronaName = UFG::qStringHashUpper32("Corona_Generic_Drive", -1);
  UFG::CoronaInfos[36].typeName = "drive_disabled";
  UFG::CoronaInfos[35].coronaHeight = 0.02;
  UFG::CoronaInfos[36].coronaName = UFG::qStringHashUpper32("Corona_drive_disabled", -1);
  UFG::CoronaInfos[36].coronaHeight = 0.02;
  UFG::CoronaInfos[37].typeName = "tiffanys_gun";
  result = UFG::qStringHashUpper32("Corona_tiffanys_gun", -1);
  UFG::CoronaInfos[37].coronaHeight = 0.02;
  UFG::CoronaInfos[37].coronaName = result;
  return result;
}

// File Line: 79
// RVA: 0x4A0550
__int64 __fastcall UFG::FindCoronaTypeByName(UFG::qString *name)
{
  unsigned int v2; // edi
  UFG::CoronaInfo *v3; // rbx

  if ( name->mLength <= 0 )
    return 0xFFFFFFFFi64;
  v2 = 0;
  v3 = UFG::CoronaInfos;
  while ( (unsigned int)UFG::qStringCompareInsensitive(name->mData, v3->typeName, -1) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)&`anonymous namespace::gDebugGUI_ProgressionView_Colour_Locked )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 99
// RVA: 0x4A09F0
char __fastcall UFG::FindTargetBySymbol(UFG::qSymbol *name, UFG::SimObject **simObj)
{
  UFG::TSActor *instance; // rax
  UFG::SimObject *m_pPointer; // rax
  UFG::qBaseTreeRB *Named; // rax
  UFG::SimObject *v8; // rax

  instance = UFG::TSActor::find_instance(name);
  if ( instance )
  {
    m_pPointer = instance->mpSimObj.m_pPointer;
    if ( m_pPointer )
    {
      *simObj = m_pPointer;
      return 1;
    }
  }
  else
  {
    Named = UFG::MarkerBase::GetNamed(name);
    if ( Named )
    {
      v8 = (UFG::SimObject *)Named->mNULL.mChild[0];
      if ( v8 )
      {
        *simObj = v8;
        return 1;
      }
    }
  }
  return 0;
}

// File Line: 130
// RVA: 0x48D030
void __fastcall UFG::ObjectiveIndicator::ObjectiveIndicator(
        UFG::ObjectiveIndicator *this,
        UFG::qSymbol *identifier,
        UFG::qString *blip,
        UFG::qString *corona,
        bool temporary)
{
  unsigned int mUID; // eax

  mUID = identifier->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->vfptr = (UFG::ObjectiveIndicatorVtbl *)&UFG::ObjectiveIndicator::`vftable;
  this->mIdentifier = (UFG::qSymbol)identifier->mUID;
  UFG::qSharedString::qSharedString(&this->mBlipType, blip->mData);
  this->mpEffectTransform.mPrev = &this->mpEffectTransform;
  this->mpEffectTransform.mNext = &this->mpEffectTransform;
  this->mpEffectTransform.m_pPointer = 0i64;
  this->mEffectId = -1;
  this->mEnabled = 0;
  this->mTemporary = temporary;
  this->mCoronaType = UFG::FindCoronaTypeByName(corona);
}

// File Line: 135
// RVA: 0x490C60
void __fastcall UFG::ObjectiveIndicator::~ObjectiveIndicator(UFG::ObjectiveIndicator *this)
{
  unsigned int mEffectId; // edx
  UFG::SimComponent *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpEffectTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  this->vfptr = (UFG::ObjectiveIndicatorVtbl *)&UFG::ObjectiveIndicator::`vftable;
  if ( this->mEnabled )
  {
    this->mEnabled = 0;
    mEffectId = this->mEffectId;
    if ( mEffectId != -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, mEffectId, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
      this->mEffectId = -1;
    }
    m_pPointer = this->mpEffectTransform.m_pPointer;
    if ( m_pPointer )
    {
      UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pPointer);
      p_mpEffectTransform = &this->mpEffectTransform;
      if ( this->mpEffectTransform.m_pPointer )
      {
        mPrev = p_mpEffectTransform->mPrev;
        mNext = this->mpEffectTransform.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpEffectTransform->mPrev = p_mpEffectTransform;
        this->mpEffectTransform.mNext = &this->mpEffectTransform;
      }
      this->mpEffectTransform.m_pPointer = 0i64;
    }
  }
  v7 = &this->mpEffectTransform;
  if ( this->mpEffectTransform.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = this->mpEffectTransform.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = v7;
    this->mpEffectTransform.mNext = &this->mpEffectTransform;
  }
  this->mpEffectTransform.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = this->mpEffectTransform.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = v7;
  this->mpEffectTransform.mNext = &this->mpEffectTransform;
  UFG::qSharedString::~qSharedString(&this->mBlipType);
}

// File Line: 140
// RVA: 0x4BC1A0
void __fastcall UFG::ObjectiveIndicator::SetEnabled(UFG::ObjectiveIndicator *this, bool enabled)
{
  UFG::TSActor *instance; // rax
  UFG::SimObjectGame *v4; // rbx
  UFG::qBaseTreeRB *Named; // rax
  __int16 m_Flags; // cx
  UFG::HealthComponent *m_pComponent; // rsi
  UFG::SimComponent *v8; // rax
  UFG::CoronaInfo *v9; // r14
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v11; // rax
  __int16 v12; // cx
  unsigned int v13; // esi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdx
  unsigned int Effect; // eax
  unsigned int mEffectId; // edx
  UFG::SimComponent *m_pPointer; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpEffectTransform; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qVector3 pos; // [rsp+38h] [rbp-50h] BYREF
  UFG::SimObjectModifier v22; // [rsp+48h] [rbp-40h] BYREF

  if ( this->mEnabled != enabled )
  {
    this->mEnabled = enabled;
    if ( !enabled || this->mCoronaType == -1 )
    {
      mEffectId = this->mEffectId;
      if ( mEffectId != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, mEffectId, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        this->mEffectId = -1;
      }
      m_pPointer = this->mpEffectTransform.m_pPointer;
      if ( m_pPointer )
      {
        UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pPointer);
        p_mpEffectTransform = &this->mpEffectTransform;
        if ( p_mpEffectTransform->m_pPointer )
        {
          mPrev = p_mpEffectTransform->mPrev;
          mNext = p_mpEffectTransform->mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mpEffectTransform->mPrev = p_mpEffectTransform;
          p_mpEffectTransform->mNext = p_mpEffectTransform;
        }
        p_mpEffectTransform->m_pPointer = 0i64;
      }
    }
    else
    {
      instance = UFG::TSActor::find_instance(&this->mIdentifier);
      if ( instance )
      {
        v4 = (UFG::SimObjectGame *)instance->mpSimObj.m_pPointer;
      }
      else
      {
        Named = UFG::MarkerBase::GetNamed(&this->mIdentifier);
        if ( !Named )
          return;
        v4 = (UFG::SimObjectGame *)Named->mNULL.mChild[0];
      }
      if ( v4 )
      {
        m_Flags = v4->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
             ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID)
             : UFG::SimObject::GetComponentOfType(v4, UFG::HealthComponent::_TypeUID);
          m_pComponent = (UFG::HealthComponent *)v8;
        }
        else
        {
          m_pComponent = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
        }
        if ( !m_pComponent || !UFG::HealthComponent::GetIsKilled(m_pComponent) && !m_pComponent->m_bIsKnockedOut )
        {
          v9 = &UFG::CoronaInfos[this->mCoronaType];
          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
          v11 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "ObjectiveIndicator.Indicator", 0i64, 1u);
          if ( v11 )
            UFG::TransformNodeComponent::TransformNodeComponent(
              (UFG::TransformNodeComponent *)v11,
              v4->mNode.mUID,
              0i64,
              0);
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mpEffectTransform,
            (UFG::SimComponent *)v11);
          v12 = v4->m_Flags;
          if ( (v12 & 0x4000) != 0 )
          {
            v13 = 2;
          }
          else if ( v12 >= 0 )
          {
            if ( (v12 & 0x2000) != 0 )
            {
              v13 = 2;
            }
            else
            {
              v13 = -1;
              if ( (v12 & 0x1000) != 0 )
                v13 = 1;
            }
          }
          else
          {
            v13 = 2;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v22, v4, 1);
          UFG::SimObjectModifier::AttachComponent(&v22, this->mpEffectTransform.m_pPointer, v13);
          UFG::SimObjectModifier::Close(&v22);
          UFG::SimObjectModifier::~SimObjectModifier(&v22);
          m_pTransformNodeComponent = v4->m_pTransformNodeComponent;
          if ( m_pTransformNodeComponent )
            UFG::TransformNodeComponent::SetParent(
              (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer,
              m_pTransformNodeComponent,
              eInheritXform_Translation);
          Effect = Render::FXManager::CreateEffect(
                     &Render::gFXManager,
                     v9->coronaName,
                     (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer,
                     0xFFFFFFFF,
                     0i64);
          this->mEffectId = Effect;
          Render::FXManager::EnableOcclusionCulling(&Render::gFXManager, Effect);
          *(_QWORD *)&pos.x = 0i64;
          pos.z = v9->coronaHeight;
          UFG::TransformNodeComponent::SetLocalTranslation(
            (UFG::TransformNodeComponent *)this->mpEffectTransform.m_pPointer,
            &pos);
        }
      }
    }
  }
}

// File Line: 212
// RVA: 0x48CF30
void __fastcall UFG::Objective::Objective(
        UFG::Objective *this,
        unsigned int loadId,
        UFG::GameSlice *pGameSlice,
        const char *identifier,
        const char *caption,
        const char *locationCaption,
        const char *log,
        const char *gpsMarker)
{
  unsigned int v12; // eax

  v12 = UFG::qStringHash32(identifier, 0xFFFFFFFF);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v12;
  this->vfptr = (UFG::ObjectiveVtbl *)&UFG::Objective::`vftable;
  this->mpGameSlice = pGameSlice;
  UFG::qString::qString(&this->mIdentifier, identifier);
  UFG::qString::qString(&this->mCaption, caption);
  UFG::qSharedString::qSharedString(&this->mLocationCaption, locationCaption);
  UFG::qSharedString::qSharedString(&this->mLog, log);
  UFG::qSharedString::qSharedString(&this->mGPSMarker, gpsMarker);
  *(_DWORD *)&this->mAutoflash = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mIndicators.mTree);
  this->mDisplayPriority = 0;
  *(_QWORD *)&this->mLoadId = loadId;
}

// File Line: 216
// RVA: 0x490B80
void __fastcall UFG::Objective::~Objective(UFG::Objective *this)
{
  Render::Skinning *p_mIndicators; // rdi
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  this->vfptr = (UFG::ObjectiveVtbl *)&UFG::Objective::`vftable;
  p_mIndicators = (Render::Skinning *)&this->mIndicators;
  if ( this->mIndicators.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mIndicators->mSkinnedVertexBuffers);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mIndicators->mSkinnedVertexBuffers.mTree, p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !p_mIndicators->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)p_mIndicators);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mIndicators);
  UFG::qSharedString::~qSharedString(&this->mGPSMarker);
  UFG::qSharedString::~qSharedString(&this->mLog);
  UFG::qSharedString::~qSharedString(&this->mLocationCaption);
  UFG::qString::~qString(&this->mCaption);
  UFG::qString::~qString(&this->mIdentifier);
}

// File Line: 245
// RVA: 0x4C7810
void __fastcall UFG::Objective::UpdateIndicators(UFG::Objective *this)
{
  UFG::qTreeRB<UFG::ObjectiveIndicator,UFG::ObjectiveIndicator,1> *p_mIndicators; // rdi
  bool v2; // si
  Render::SkinningCacheNode *Head; // rax
  UFG::ObjectiveIndicator *p_mCachedBufferPtr; // rbx
  UFG::qBaseTreeRB *Next; // rax

  p_mIndicators = &this->mIndicators;
  v2 = (unsigned int)(this->mStatus - 1) <= 1;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( Head )
  {
    p_mCachedBufferPtr = (UFG::ObjectiveIndicator *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        UFG::ObjectiveIndicator::SetEnabled(p_mCachedBufferPtr, v2);
        Next = UFG::qBaseTreeRB::GetNext(&p_mIndicators->mTree, &p_mCachedBufferPtr->mNode);
        if ( !Next )
          break;
        p_mCachedBufferPtr = (UFG::ObjectiveIndicator *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qBaseTreeRB *)8 );
    }
  }
}

// File Line: 273
// RVA: 0x492DB0
void __fastcall UFG::Objective::AddIndicator(
        UFG::Objective *this,
        UFG::qSymbolUC *identifier,
        UFG::qString *blip,
        UFG::qString *corona,
        bool temporary)
{
  UFG::qTreeRB<UFG::ObjectiveIndicator,UFG::ObjectiveIndicator,1> *p_mIndicators; // rsi
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rcx
  UFG::qBaseTreeRB *Next; // rax
  char *v12; // rax
  Render::SkinningCacheNode *v13; // rax
  char *p_mCount; // rbx
  UFG::qBaseNodeRB *v15; // rdx
  UFG::qBaseTreeRB *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::qBaseNodeRB *v18; // rbx
  __int64 v19; // rax

  p_mIndicators = &this->mIndicators;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( Head )
  {
    p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      while ( *((_DWORD *)p_mCachedBufferPtr + 10) != identifier->mUID )
      {
        Next = UFG::qBaseTreeRB::GetNext(&p_mIndicators->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
        if ( Next )
        {
          p_mCachedBufferPtr = (char *)&Next[-1].mCount;
          if ( Next != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        goto LABEL_14;
      }
      v12 = UFG::qSymbol::as_cstr_dbg(identifier);
      UFG::qPrintf("WARNING: Duplicate objective indicator found!  (%s)\n", v12);
      v13 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)p_mIndicators);
      if ( v13 )
      {
        p_mCount = (char *)&v13[-1].mCachedBufferPtr;
        if ( v13 != (Render::SkinningCacheNode *)8 )
        {
          while ( 1 )
          {
            v15 = (UFG::qBaseNodeRB *)(p_mCount + 8);
            if ( *((_DWORD *)p_mCount + 10) == identifier->mUID )
              break;
            v16 = UFG::qBaseTreeRB::GetNext(&p_mIndicators->mTree, v15);
            if ( v16 )
            {
              p_mCount = (char *)&v16[-1].mCount;
              if ( v16 != (UFG::qBaseTreeRB *)8 )
                continue;
            }
            goto LABEL_14;
          }
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mIndicators,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v15);
          (**(void (__fastcall ***)(char *, __int64))p_mCount)(p_mCount, 1i64);
        }
      }
    }
  }
LABEL_14:
  v17 = UFG::qMalloc(0x60ui64, "ObjectiveTracker", 0i64);
  v18 = 0i64;
  if ( v17 )
    UFG::ObjectiveIndicator::ObjectiveIndicator(
      (UFG::ObjectiveIndicator *)v17,
      (UFG::qSymbol *)identifier,
      blip,
      corona,
      temporary);
  else
    v19 = 0i64;
  if ( v19 )
    v18 = (UFG::qBaseNodeRB *)(v19 + 8);
  UFG::qBaseTreeRB::Add(&p_mIndicators->mTree, v18);
}

// File Line: 287
// RVA: 0x4B6430
void __fastcall UFG::Objective::RemoveIndicator(UFG::Objective *this, UFG::qSymbol *name, bool removeTemporaryOnly)
{
  UFG::qTreeRB<UFG::ObjectiveIndicator,UFG::ObjectiveIndicator,1> *p_mIndicators; // rsi
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rbx
  UFG::qBaseTreeRB *Next; // rax

  p_mIndicators = &this->mIndicators;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( Head )
  {
    p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      while ( *((_DWORD *)p_mCachedBufferPtr + 10) != name->mUID )
      {
        Next = UFG::qBaseTreeRB::GetNext(&p_mIndicators->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
        if ( Next )
        {
          p_mCachedBufferPtr = (char *)&Next[-1].mCount;
          if ( Next != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        return;
      }
      if ( !removeTemporaryOnly || p_mCachedBufferPtr[89] )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)p_mIndicators,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)(p_mCachedBufferPtr + 8));
        (**(void (__fastcall ***)(char *, __int64))p_mCachedBufferPtr)(p_mCachedBufferPtr, 1i64);
      }
    }
  }
}

// File Line: 318
// RVA: 0x4A28D0
Render::SkinningCacheNode *__fastcall UFG::Objective::GetFirstIndicator(UFG::Objective *this)
{
  Render::SkinningCacheNode *result; // rax

  result = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( result )
    return (Render::SkinningCacheNode *)((char *)result - 8);
  return result;
}

// File Line: 324
// RVA: 0x4A54B0
UFG::qBaseTreeRB *__fastcall UFG::Objective::GetNextIndicator(UFG::Objective *this, UFG::ObjectiveIndicator *pPrevious)
{
  UFG::qBaseTreeRB *result; // rax

  if ( pPrevious )
    pPrevious = (UFG::ObjectiveIndicator *)((char *)pPrevious + 8);
  result = UFG::qBaseTreeRB::GetNext(&this->mIndicators.mTree, (UFG::qBaseNodeRB *)pPrevious);
  if ( result )
    return (UFG::qBaseTreeRB *)((char *)result - 8);
  return result;
}

// File Line: 332
// RVA: 0x4B0CD0
__int64 __fastcall UFG::Objective::MapSymbolToStatus(ASymbol *symbol)
{
  unsigned int i_uid; // eax
  unsigned int v2; // edx

  i_uid = symbol->i_uid;
  v2 = 0;
  if ( symbol->i_uid != ObjectiveSym_INACTIVE.i_uid )
  {
    if ( i_uid == ObjectiveSym_ACTIVE.i_uid )
      return 1i64;
    if ( i_uid == ObjectiveSym_HIGHLIGHT.i_uid )
      return 2i64;
    if ( i_uid == ObjectiveSym_COMPLETED.i_uid )
      return 3i64;
    if ( i_uid == ObjectiveSym_FAILED.i_uid )
      return 4;
  }
  return v2;
}

// File Line: 374
// RVA: 0x490D40
void __fastcall UFG::ObjectiveTracker::~ObjectiveTracker(UFG::ObjectiveTracker *this)
{
  UFG::Objective **p; // rcx
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx
  UFG::Objective **v9; // rcx

  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager::mInstance);
  p = this->mLoadedOrderObjectives.p;
  if ( p )
    operator delete[](p);
  this->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&this->mLoadedOrderObjectives.size = 0i64;
  if ( this->mObjectives.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      p_mNode = &Head->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mObjectives,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !this->mObjectives.mTree.mCount )
        goto LABEL_14;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_10:
    p_mNode = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  if ( this->mObjectiveHints.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectiveHints);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_19;
      v8 = &v6->mNode;
LABEL_20:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mObjectiveHints,
        v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !this->mObjectiveHints.mTree.mCount )
        goto LABEL_23;
    }
    v7 = 0i64;
LABEL_19:
    v8 = 0i64;
    goto LABEL_20;
  }
LABEL_23:
  this->mLastLoadId = 0;
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&this->mObjectiveHints);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mObjectiveHints);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&this->mObjectives);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mObjectives);
  v9 = this->mLoadedOrderObjectives.p;
  if ( v9 )
    operator delete[](v9);
  this->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&this->mLoadedOrderObjectives.size = 0i64;
}

// File Line: 388
// RVA: 0x497950
void __fastcall UFG::ObjectiveTracker::Clear(UFG::ObjectiveTracker *this)
{
  UFG::Objective **p; // rcx
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx

  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager::mInstance);
  p = this->mLoadedOrderObjectives.p;
  if ( p )
    operator delete[](p);
  this->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&this->mLoadedOrderObjectives.size = 0i64;
  if ( this->mObjectives.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      p_mNode = &Head->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mObjectives,
        p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !this->mObjectives.mTree.mCount )
        goto LABEL_14;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_10:
    p_mNode = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  if ( this->mObjectiveHints.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectiveHints);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_19;
      v8 = &v6->mNode;
LABEL_20:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mObjectiveHints,
        v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !this->mObjectiveHints.mTree.mCount )
        goto LABEL_23;
    }
    v7 = 0i64;
LABEL_19:
    v8 = 0i64;
    goto LABEL_20;
  }
LABEL_23:
  this->mLastLoadId = 0;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
}

// File Line: 462
// RVA: 0x4936B0
UFG::Objective *__fastcall UFG::ObjectiveTracker::AddObjective(
        UFG::ObjectiveTracker *this,
        const char *identifier,
        const char *caption,
        const char *locationCaption,
        const char *log,
        const char *gpsMarker,
        UFG::GameSlice *pGameSlice)
{
  unsigned int mStringHash32; // eax
  UFG::qBaseNodeRB *p_mNode; // rbx
  UFG::qBaseTreeRB *v13; // rax
  UFG::Objective *p_mCount; // rsi
  UFG::allocator::free_link *v15; // rax
  UFG::Objective *v16; // rax
  __int64 size; // rbp
  unsigned int v18; // ebx
  unsigned int capacity; // edx
  unsigned int v20; // edx
  UFG::qString v22; // [rsp+50h] [rbp-48h] BYREF

  UFG::qString::qString(&v22, identifier);
  mStringHash32 = v22.mStringHash32;
  if ( v22.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(v22.mData, 0xFFFFFFFF);
    v22.mStringHash32 = mStringHash32;
  }
  p_mNode = 0i64;
  if ( !mStringHash32
    || (v13 = UFG::qBaseTreeRB::Get(&this->mObjectives.mTree, mStringHash32),
        p_mCount = (UFG::Objective *)&v13[-1].mCount,
        !v13) )
  {
    p_mCount = 0i64;
  }
  UFG::qString::~qString(&v22);
  if ( !p_mCount )
  {
    v15 = UFG::qMalloc(0xF8ui64, "ObjectiveTracker", 0i64);
    if ( v15 )
    {
      UFG::Objective::Objective(
        (UFG::Objective *)v15,
        this->mLastLoadId,
        pGameSlice,
        identifier,
        caption,
        locationCaption,
        log,
        gpsMarker);
      p_mCount = v16;
    }
    else
    {
      p_mCount = 0i64;
    }
    if ( p_mCount )
      p_mNode = &p_mCount->mNode;
    UFG::qBaseTreeRB::Add(&this->mObjectives.mTree, p_mNode);
    size = this->mLoadedOrderObjectives.size;
    v18 = size + 1;
    capacity = this->mLoadedOrderObjectives.capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v20 = 2 * capacity;
      else
        v20 = 1;
      for ( ; v20 < v18; v20 *= 2 )
        ;
      if ( v20 <= 2 )
        v20 = 2;
      if ( v20 - v18 > 0x10000 )
        v20 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this,
        v20,
        "qArray.Add");
    }
    this->mLoadedOrderObjectives.size = v18;
    this->mLoadedOrderObjectives.p[size] = p_mCount;
    ++this->mLastLoadId;
  }
  return p_mCount;
}

// File Line: 480
// RVA: 0x4C5890
void __fastcall UFG::ObjectiveTracker::UpdateCaption(
        UFG::ObjectiveTracker *this,
        UFG::qString *identifier,
        UFG::qString *caption,
        UFG::GameSlice *pGameSlice)
{
  unsigned int mStringHash32; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Objective *p_mCount; // rbx
  UFG::UIHKPlayerObjectiveManager *v11; // rdi

  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  mStringHash32 = identifier->mStringHash32;
  if ( mStringHash32 )
  {
    v9 = UFG::qBaseTreeRB::Get(&this->mObjectives.mTree, mStringHash32);
    if ( v9 )
    {
      p_mCount = (UFG::Objective *)&v9[-1].mCount;
      if ( v9 != (UFG::qBaseTreeRB *)8 )
      {
        if ( pGameSlice )
          p_mCount->mpGameSlice = pGameSlice;
        UFG::qString::Set(&p_mCount->mCaption, caption->mData, caption->mLength, 0i64, 0);
        if ( (unsigned int)(p_mCount->mStatus - 1) <= 1 )
        {
          v11 = UFG::UIHKPlayerObjectiveManager::mInstance;
          if ( UFG::UIHKPlayerObjectiveManager::mInstance )
          {
            UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
            if ( p_mCount->mAutoflash )
              UFG::UIHKPlayerObjectiveManager::FlashObjective(v11, p_mCount, 0);
          }
        }
      }
    }
  }
}

// File Line: 503
// RVA: 0x4C8930
void __fastcall UFG::ObjectiveTracker::UpdateStatus(
        UFG::ObjectiveTracker *this,
        UFG::qString *identifier,
        UFG::Objective::Status status,
        UFG::GameSlice *pGameSlice)
{
  unsigned int mStringHash32; // edx
  UFG::qBaseTreeRB *v9; // rax
  UFG::Objective *p_mCount; // rbx
  UFG::UIHKPlayerObjectiveManager *v11; // rdi

  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  mStringHash32 = identifier->mStringHash32;
  if ( mStringHash32 )
  {
    v9 = UFG::qBaseTreeRB::Get(&this->mObjectives.mTree, mStringHash32);
    if ( v9 )
    {
      p_mCount = (UFG::Objective *)&v9[-1].mCount;
      if ( v9 != (UFG::qBaseTreeRB *)8 )
      {
        if ( pGameSlice )
          p_mCount->mpGameSlice = pGameSlice;
        p_mCount->mStatus = status;
        UFG::Objective::UpdateIndicators((UFG::Objective *)&v9[-1].mCount);
        if ( (unsigned int)(status - 1) > 1 )
        {
          if ( UFG::UIHKPlayerObjectiveManager::mInstance )
            UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
        }
        else
        {
          v11 = UFG::UIHKPlayerObjectiveManager::mInstance;
          if ( UFG::UIHKPlayerObjectiveManager::mInstance )
          {
            UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
            if ( p_mCount->mAutoflash )
              UFG::UIHKPlayerObjectiveManager::FlashObjective(v11, p_mCount, 0);
          }
        }
      }
    }
  }
}

// File Line: 529
// RVA: 0x4C8A00
void __fastcall UFG::ObjectiveTracker::UpdateStatus(
        UFG::ObjectiveTracker *this,
        UFG::Objective *pObjective,
        bool refreshFlash)
{
  UFG::ObjectiveTracker::UpdateStatus(this, pObjective, pObjective->mStatus, pObjective->mpGameSlice, refreshFlash);
}

// File Line: 535
// RVA: 0x4C88A0
void __fastcall UFG::ObjectiveTracker::UpdateStatus(
        UFG::ObjectiveTracker *this,
        UFG::Objective *pObjective,
        UFG::Objective::Status status,
        UFG::GameSlice *pGameSlice,
        bool updateFlash)
{
  UFG::UIHKPlayerObjectiveManager *v7; // rdi

  if ( pGameSlice )
    pObjective->mpGameSlice = pGameSlice;
  pObjective->mStatus = status;
  UFG::Objective::UpdateIndicators(pObjective);
  if ( updateFlash && (unsigned int)(status - 1) <= 1 )
  {
    v7 = UFG::UIHKPlayerObjectiveManager::mInstance;
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    {
      UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
      if ( pObjective->mAutoflash )
        UFG::UIHKPlayerObjectiveManager::FlashObjective(v7, pObjective, 0);
    }
  }
  else if ( UFG::UIHKPlayerObjectiveManager::mInstance )
  {
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
  }
}

// File Line: 555
// RVA: 0x4B1BE0
void __fastcall UFG::ObjectiveTracker::OnRestore(UFG::ObjectiveTracker *this)
{
  UFG::qTreeRB<UFG::Objective,UFG::Objective,1> *p_mObjectives; // r14
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rbp
  Render::SkinningCacheNode *v4; // rax
  char *p_mCount; // rbx
  char *v6; // rdi
  UFG::qBaseTreeRB *Next; // rax
  int v8; // eax
  Render::SkinningCacheNode *v9; // rax
  UFG::ObjectiveIndicator *v10; // rbx
  UFG::qBaseTreeRB *v11; // rax
  UFG::qBaseTreeRB *v12; // rax

  p_mObjectives = &this->mObjectives;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( Head )
  {
    p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(p_mCachedBufferPtr + 160));
        if ( v4 )
        {
          p_mCount = (char *)&v4[-1].mCachedBufferPtr;
          if ( v4 != (Render::SkinningCacheNode *)8 )
          {
            do
            {
              v6 = 0i64;
              if ( p_mCount[89] )
                v6 = p_mCount;
              Next = UFG::qBaseTreeRB::GetNext(
                       (UFG::qBaseTreeRB *)(p_mCachedBufferPtr + 160),
                       (UFG::qBaseNodeRB *)(p_mCount + 8));
              p_mCount = (char *)&Next[-1].mCount;
              if ( !Next )
                p_mCount = 0i64;
              if ( v6 )
              {
                UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                  (UFG::qBaseTreeVariableRB<unsigned __int64> *)(p_mCachedBufferPtr + 160),
                  (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v6 + 8));
                (**(void (__fastcall ***)(char *, __int64))v6)(v6, 1i64);
              }
            }
            while ( p_mCount );
          }
        }
        v8 = *((_DWORD *)p_mCachedBufferPtr + 60);
        if ( v8 )
        {
          if ( (unsigned int)(v8 - 3) > 1 )
          {
            *((_DWORD *)p_mCachedBufferPtr + 60) = 0;
            UFG::Objective::UpdateIndicators((UFG::Objective *)p_mCachedBufferPtr);
          }
        }
        else
        {
          *((_DWORD *)p_mCachedBufferPtr + 60) = 0;
          v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(p_mCachedBufferPtr + 160));
          if ( v9 )
          {
            v10 = (UFG::ObjectiveIndicator *)&v9[-1].mCachedBufferPtr;
            if ( v9 != (Render::SkinningCacheNode *)8 )
            {
              do
              {
                UFG::ObjectiveIndicator::SetEnabled(v10, 0);
                v11 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(p_mCachedBufferPtr + 160), &v10->mNode);
                if ( !v11 )
                  break;
                v10 = (UFG::ObjectiveIndicator *)&v11[-1].mCount;
              }
              while ( v11 != (UFG::qBaseTreeRB *)8 );
            }
          }
        }
        v12 = UFG::qBaseTreeRB::GetNext(&p_mObjectives->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
        if ( !v12 )
          break;
        p_mCachedBufferPtr = (char *)&v12[-1].mCount;
      }
      while ( v12 != (UFG::qBaseTreeRB *)8 );
    }
  }
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
}

// File Line: 590
// RVA: 0x4B1750
void __fastcall UFG::ObjectiveTracker::OnFail(UFG::ObjectiveTracker *this)
{
  UFG::qTreeRB<UFG::Objective,UFG::Objective,1> *p_mObjectives; // rbp
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rdi
  Render::SkinningCacheNode *v4; // rax
  UFG::ObjectiveIndicator *p_mCount; // rbx
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseTreeRB *v7; // rax

  p_mObjectives = &this->mObjectives;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( Head )
  {
    p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        if ( !*((_DWORD *)p_mCachedBufferPtr + 60) )
        {
          *((_DWORD *)p_mCachedBufferPtr + 60) = 0;
          v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(p_mCachedBufferPtr + 160));
          if ( v4 )
          {
            p_mCount = (UFG::ObjectiveIndicator *)&v4[-1].mCachedBufferPtr;
            if ( v4 != (Render::SkinningCacheNode *)8 )
            {
              do
              {
                UFG::ObjectiveIndicator::SetEnabled(p_mCount, 0);
                Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(p_mCachedBufferPtr + 160), &p_mCount->mNode);
                if ( !Next )
                  break;
                p_mCount = (UFG::ObjectiveIndicator *)&Next[-1].mCount;
              }
              while ( Next != (UFG::qBaseTreeRB *)8 );
            }
          }
        }
        v7 = UFG::qBaseTreeRB::GetNext(&p_mObjectives->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
        if ( !v7 )
          break;
        p_mCachedBufferPtr = (char *)&v7[-1].mCount;
      }
      while ( v7 != (UFG::qBaseTreeRB *)8 );
    }
  }
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
}

// File Line: 605
// RVA: 0x4B1AD0
void __fastcall UFG::ObjectiveTracker::OnGameSliceCleanup(UFG::ObjectiveTracker *this, UFG::GameSlice *pGameSlice)
{
  UFG::qTreeRB<UFG::Objective,UFG::Objective,1> *p_mObjectives; // r14
  char v4; // bl
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rdi
  Render::SkinningCacheNode *v7; // rax
  UFG::ObjectiveIndicator *p_mCount; // rbx
  UFG::qBaseTreeRB *Next; // rax
  UFG::qBaseTreeRB *v10; // rax

  p_mObjectives = &this->mObjectives;
  v4 = 0;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( !Head )
    return;
  p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
  if ( Head == (Render::SkinningCacheNode *)8 )
    return;
  do
  {
    if ( *((UFG::GameSlice **)p_mCachedBufferPtr + 5) == pGameSlice )
    {
      if ( ((pGameSlice->mCompletionStatus - 1) & 0xFFFFFFFD) == 0 )
      {
        *((_DWORD *)p_mCachedBufferPtr + 60) = 0;
        v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(p_mCachedBufferPtr + 160));
        if ( v7 )
        {
          p_mCount = (UFG::ObjectiveIndicator *)&v7[-1].mCachedBufferPtr;
          if ( v7 != (Render::SkinningCacheNode *)8 )
          {
            do
            {
              UFG::ObjectiveIndicator::SetEnabled(p_mCount, 0);
              Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(p_mCachedBufferPtr + 160), &p_mCount->mNode);
              if ( !Next )
                break;
              p_mCount = (UFG::ObjectiveIndicator *)&Next[-1].mCount;
            }
            while ( Next != (UFG::qBaseTreeRB *)8 );
          }
        }
        goto LABEL_11;
      }
      if ( *((_DWORD *)p_mCachedBufferPtr + 60) == 3 )
      {
        *((_DWORD *)p_mCachedBufferPtr + 60) = 0;
        UFG::Objective::UpdateIndicators((UFG::Objective *)p_mCachedBufferPtr);
LABEL_11:
        v4 = 1;
      }
    }
    v10 = UFG::qBaseTreeRB::GetNext(&p_mObjectives->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
    if ( !v10 )
      break;
    p_mCachedBufferPtr = (char *)&v10[-1].mCount;
  }
  while ( v10 != (UFG::qBaseTreeRB *)8 );
  if ( v4 )
  {
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
      UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
  }
}

// File Line: 632
// RVA: 0x4A0730
UFG::Objective *__fastcall UFG::ObjectiveTracker::FindObjective(UFG::ObjectiveTracker *this, UFG::qString *identifier)
{
  unsigned int mStringHash32; // edx
  UFG::qBaseTreeRB *v5; // rax

  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  mStringHash32 = identifier->mStringHash32;
  if ( mStringHash32 && (v5 = UFG::qBaseTreeRB::Get(&this->mObjectives.mTree, mStringHash32)) != 0i64 )
    return (UFG::Objective *)&v5[-1].mCount;
  else
    return 0i64;
}

// File Line: 637
// RVA: 0x4A2900
UFG::Objective *__fastcall UFG::ObjectiveTracker::GetFirstObjective(UFG::ObjectiveTracker *this)
{
  __int64 v2; // rbx
  UFG::Objective *v3; // rdi
  UFG::GameStatTracker *v4; // rcx
  UFG::PersistentData::MapInt *v5; // rsi
  UFG::qSymbol *v6; // rcx
  __int64 v7; // rax
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *p; // rcx
  int mIntValue; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  v2 = 0i64;
  if ( !this->mLastLoadId )
    return 0i64;
  while ( 1 )
  {
    v3 = this->mLoadedOrderObjectives.p[v2];
    if ( v3->mStatus )
    {
      if ( !v3->mTextUnlockable )
        return v3;
      if ( (_S12_6 & 1) == 0 )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v4 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v4 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v4;
      v5 = v4->mpSnapshots[0]->mpMapInts[16];
      v6 = UFG::qSymbol::create_from_string(&result, v3->mIdentifier.mData);
      v7 = 0i64;
      if ( !v5->mValues.size )
        goto LABEL_15;
      mUID = v6->mUID;
      p = v5->mValues.p;
      while ( p->mKey.mUID != mUID )
      {
        v7 = (unsigned int)(v7 + 1);
        ++p;
        if ( (unsigned int)v7 >= v5->mValues.size )
          goto LABEL_15;
      }
      if ( (_DWORD)v7 == -1 )
LABEL_15:
        mIntValue = 0;
      else
        mIntValue = v5->mValues.p[v7].mIntValue;
      if ( mIntValue > 0 )
        return v3;
    }
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= this->mLastLoadId )
      return 0i64;
  }
}

// File Line: 650
// RVA: 0x4A54E0
UFG::Objective *__fastcall UFG::ObjectiveTracker::GetNextObjective(
        UFG::ObjectiveTracker *this,
        UFG::Objective *pPrevious)
{
  __int64 v3; // rbx
  UFG::Objective *v4; // rdi
  UFG::GameStatTracker *v5; // rcx
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::qSymbol *v7; // rcx
  __int64 v8; // rax
  unsigned int mUID; // edx
  UFG::PersistentData::KeyValue *p; // rcx
  int mIntValue; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h] BYREF

  v3 = pPrevious->mLoadId + 1;
  if ( (unsigned int)v3 >= this->mLastLoadId )
    return 0i64;
  while ( 1 )
  {
    v4 = this->mLoadedOrderObjectives.p[v3];
    if ( v4->mStatus )
    {
      if ( !v4->mTextUnlockable )
        return v4;
      if ( (_S12_6 & 1) == 0 )
      {
        _S12_6 |= 1u;
        UFG::GameStatTracker::GameStatTracker(&sGameStatTracker);
        atexit(UFG::GameStatTracker::Instance_::_2_::_dynamic_atexit_destructor_for__sGameStatTracker__);
      }
      v5 = &sGameStatTracker;
      if ( UFG::GameStatTracker::mspInstance )
        v5 = UFG::GameStatTracker::mspInstance;
      UFG::GameStatTracker::mspInstance = v5;
      v6 = v5->mpSnapshots[0]->mpMapInts[16];
      v7 = UFG::qSymbol::create_from_string(&result, v4->mIdentifier.mData);
      v8 = 0i64;
      if ( !v6->mValues.size )
        goto LABEL_15;
      mUID = v7->mUID;
      p = v6->mValues.p;
      while ( p->mKey.mUID != mUID )
      {
        v8 = (unsigned int)(v8 + 1);
        ++p;
        if ( (unsigned int)v8 >= v6->mValues.size )
          goto LABEL_15;
      }
      if ( (_DWORD)v8 == -1 )
LABEL_15:
        mIntValue = 0;
      else
        mIntValue = v6->mValues.p[v8].mIntValue;
      if ( mIntValue > 0 )
        return v4;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= this->mLastLoadId )
      return 0i64;
  }
}

// File Line: 665
// RVA: 0x49DCC0
void __fastcall UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(
        UFG::ObjectiveTracker *this,
        UFG::qSymbol *name,
        bool isEnable)
{
  UFG::qTreeRB<UFG::Objective,UFG::Objective,1> *p_mObjectives; // rbp
  Render::SkinningCacheNode *Head; // rax
  char *p_mCachedBufferPtr; // rbx
  Render::SkinningCacheNode *v8; // rax
  UFG::ObjectiveIndicator *p_mCount; // rcx
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *Next; // rax

  p_mObjectives = &this->mObjectives;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( Head )
  {
    p_mCachedBufferPtr = (char *)&Head[-1].mCachedBufferPtr;
    if ( Head != (Render::SkinningCacheNode *)8 )
    {
      while ( 1 )
      {
        if ( *((_DWORD *)p_mCachedBufferPtr + 60) == 1 )
        {
          v8 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(p_mCachedBufferPtr + 160));
          if ( v8 )
          {
            p_mCount = (UFG::ObjectiveIndicator *)&v8[-1].mCachedBufferPtr;
            if ( v8 != (Render::SkinningCacheNode *)8 )
              break;
          }
        }
LABEL_9:
        Next = UFG::qBaseTreeRB::GetNext(&p_mObjectives->mTree, (UFG::qBaseNodeRB *)(p_mCachedBufferPtr + 8));
        if ( Next )
        {
          p_mCachedBufferPtr = (char *)&Next[-1].mCount;
          if ( Next != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        return;
      }
      while ( p_mCount->mIdentifier.mUID != name->mUID )
      {
        v10 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(p_mCachedBufferPtr + 160), &p_mCount->mNode);
        if ( v10 )
        {
          p_mCount = (UFG::ObjectiveIndicator *)&v10[-1].mCount;
          if ( v10 != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        goto LABEL_9;
      }
      UFG::ObjectiveIndicator::SetEnabled(p_mCount, isEnable);
    }
  }
}

// File Line: 713
// RVA: 0x4A0790
UFG::ObjectiveHint *__fastcall UFG::ObjectiveTracker::FindObjectiveHint(
        UFG::ObjectiveTracker *this,
        UFG::qString *identifier)
{
  unsigned int mStringHash32; // edx
  UFG::qBaseTreeRB *v5; // rax

  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  mStringHash32 = identifier->mStringHash32;
  if ( mStringHash32 && (v5 = UFG::qBaseTreeRB::Get(&this->mObjectiveHints.mTree, mStringHash32)) != 0i64 )
    return (UFG::ObjectiveHint *)&v5[-1].mCount;
  else
    return 0i64;
}

