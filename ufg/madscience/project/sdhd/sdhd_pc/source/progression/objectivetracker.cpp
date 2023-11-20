// File Line: 19
// RVA: 0x151C890
__int64 dynamic_initializer_for__ObjectiveSym_INACTIVE__()
{
  ASymbol::create(&ObjectiveSym_INACTIVE, "INACTIVE", 0xFFFFFFFF, ATerm_long);
  return atexit(dynamic_atexit_destructor_for__ObjectiveSym_INACTIVE__);
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

  UFG::CoronaInfos[0].coronaName = UFG::qStringHashUpper32("Corona_walkEvent", 0xFFFFFFFF);
  UFG::CoronaInfos[0].coronaHeight = 0.02;
  UFG::CoronaInfos[1].typeName = "social_job";
  v0 = UFG::qStringHashUpper32("Marker_Social", 0xFFFFFFFF);
  UFG::CoronaInfos[1].coronaHeight = FLOAT_2_5;
  UFG::CoronaInfos[1].coronaName = v0;
  UFG::CoronaInfos[2].typeName = "drive_lead";
  UFG::CoronaInfos[2].coronaName = UFG::qStringHashUpper32("Corona_Event_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[3].typeName = "cop_job";
  UFG::CoronaInfos[2].coronaHeight = 0.02;
  UFG::CoronaInfos[3].coronaName = UFG::qStringHashUpper32("Corona_Job_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[3].coronaHeight = 0.02;
  UFG::CoronaInfos[4].typeName = "arrow_enemy";
  UFG::CoronaInfos[4].coronaName = UFG::qStringHashUpper32("HK_UI_ReticleTarget_Effect", 0xFFFFFFFF);
  UFG::CoronaInfos[4].coronaHeight = 2.75;
  UFG::CoronaInfos[5].typeName = "arrow_objective";
  UFG::CoronaInfos[5].coronaName = UFG::qStringHashUpper32("Marker_Mission", 0xFFFFFFFF);
  UFG::CoronaInfos[6].typeName = "arrow_hostile";
  UFG::CoronaInfos[5].coronaHeight = 2.75;
  v1 = UFG::qStringHashUpper32("Marker_Enemy", 0xFFFFFFFF);
  UFG::CoronaInfos[6].coronaHeight = FLOAT_2_25;
  UFG::CoronaInfos[6].coronaName = v1;
  UFG::CoronaInfos[7].typeName = "arrow_hostile_truck";
  v2 = UFG::qStringHashUpper32("Marker_Enemy", 0xFFFFFFFF);
  UFG::CoronaInfos[7].coronaHeight = FLOAT_3_75;
  UFG::CoronaInfos[7].coronaName = v2;
  UFG::CoronaInfos[8].typeName = "arrow_store";
  UFG::CoronaInfos[8].coronaName = UFG::qStringHashUpper32("Marker_Social", 0xFFFFFFFF);
  UFG::CoronaInfos[9].typeName = "arrow_social";
  UFG::CoronaInfos[8].coronaHeight = 2.75;
  UFG::CoronaInfos[9].coronaName = UFG::qStringHashUpper32("Marker_Social", 0xFFFFFFFF);
  UFG::CoronaInfos[9].coronaHeight = 2.75;
  UFG::CoronaInfos[10].typeName = "arrow_friendly";
  v3 = UFG::qStringHashUpper32("Marker_Friendly", 0xFFFFFFFF);
  UFG::CoronaInfos[10].coronaHeight = 2.75;
  UFG::CoronaInfos[10].coronaName = v3;
  UFG::CoronaInfos[11].typeName = "arrow_race";
  UFG::CoronaInfos[11].coronaName = UFG::qStringHashUpper32("Marker_Mission", 0xFFFFFFFF);
  UFG::CoronaInfos[11].coronaHeight = 2.75;
  UFG::CoronaInfos[12].typeName = "arrow_case";
  UFG::CoronaInfos[12].coronaName = UFG::qStringHashUpper32("Case_Arrow", 0xFFFFFFFF);
  UFG::CoronaInfos[13].typeName = "walk_mission";
  UFG::CoronaInfos[12].coronaHeight = 2.75;
  UFG::CoronaInfos[13].coronaName = UFG::qStringHashUpper32("Corona_Mission_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[13].coronaHeight = 0.02;
  UFG::CoronaInfos[14].typeName = "walk_event";
  UFG::CoronaInfos[14].coronaName = UFG::qStringHashUpper32("Corona_Event_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[14].coronaHeight = 0.02;
  UFG::CoronaInfos[15].typeName = "walk_race";
  UFG::CoronaInfos[15].coronaName = UFG::qStringHashUpper32("Corona_Race_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[16].typeName = "walk_case";
  UFG::CoronaInfos[15].coronaHeight = 0.02;
  UFG::CoronaInfos[16].coronaName = UFG::qStringHashUpper32("Corona_Case_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[16].coronaHeight = 0.02;
  UFG::CoronaInfos[17].typeName = "walk_cop_job";
  UFG::CoronaInfos[17].coronaName = UFG::qStringHashUpper32("Corona_Case_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[17].coronaHeight = 0.02;
  UFG::CoronaInfos[18].typeName = "walk_job";
  UFG::CoronaInfos[18].coronaName = UFG::qStringHashUpper32("Corona_Job_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[19].typeName = "walk_hiding";
  UFG::CoronaInfos[18].coronaHeight = 0.02;
  UFG::CoronaInfos[19].coronaName = UFG::qStringHashUpper32("Corona_HidingSpot_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[19].coronaHeight = 0.02;
  UFG::CoronaInfos[20].typeName = "walk_generic";
  UFG::CoronaInfos[20].coronaName = UFG::qStringHashUpper32("Corona_Generic_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[20].coronaHeight = 0.02;
  UFG::CoronaInfos[21].typeName = "walk_store";
  UFG::CoronaInfos[21].coronaName = UFG::qStringHashUpper32("Corona_Store_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[22].typeName = "walk_parking";
  UFG::CoronaInfos[21].coronaHeight = 0.02;
  UFG::CoronaInfos[22].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[22].coronaHeight = 0.02;
  UFG::CoronaInfos[23].typeName = "walk_offensive";
  UFG::CoronaInfos[23].coronaName = UFG::qStringHashUpper32("Corona_Job_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[24].typeName = "walk_defensive";
  UFG::CoronaInfos[23].coronaHeight = 0.02;
  UFG::CoronaInfos[24].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[24].coronaHeight = 0.02;
  UFG::CoronaInfos[25].typeName = "walk_disabled";
  UFG::CoronaInfos[25].coronaName = UFG::qStringHashUpper32("Corona_walk_disabled", 0xFFFFFFFF);
  UFG::CoronaInfos[25].coronaHeight = 0.02;
  UFG::CoronaInfos[26].typeName = "walk_bus_stop";
  UFG::CoronaInfos[26].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[27].typeName = "walk_ferry";
  UFG::CoronaInfos[26].coronaHeight = 0.02;
  UFG::CoronaInfos[27].coronaName = UFG::qStringHashUpper32("Corona_ParkingSpot_Walk", 0xFFFFFFFF);
  UFG::CoronaInfos[27].coronaHeight = 0.02;
  UFG::CoronaInfos[28].typeName = "drive_mission";
  UFG::CoronaInfos[28].coronaName = UFG::qStringHashUpper32("Corona_Mission_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[28].coronaHeight = 0.02;
  UFG::CoronaInfos[29].typeName = "drive_event";
  UFG::CoronaInfos[29].coronaName = UFG::qStringHashUpper32("Corona_Event_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[30].typeName = "drive_race";
  UFG::CoronaInfos[29].coronaHeight = 0.02;
  UFG::CoronaInfos[30].coronaName = UFG::qStringHashUpper32("Corona_Race_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[30].coronaHeight = 0.02;
  UFG::CoronaInfos[31].typeName = "drive_case";
  UFG::CoronaInfos[31].coronaName = UFG::qStringHashUpper32("Corona_Case_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[31].coronaHeight = 0.02;
  UFG::CoronaInfos[32].typeName = "drive_job";
  UFG::CoronaInfos[32].coronaName = UFG::qStringHashUpper32("Corona_Job_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[33].typeName = "drive_cop_job";
  UFG::CoronaInfos[32].coronaHeight = 0.02;
  UFG::CoronaInfos[33].coronaName = UFG::qStringHashUpper32("Corona_Case_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[33].coronaHeight = 0.02;
  UFG::CoronaInfos[34].typeName = "drive_hiding";
  UFG::CoronaInfos[34].coronaName = UFG::qStringHashUpper32("Corona_HidingSpot_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[34].coronaHeight = 0.02;
  UFG::CoronaInfos[35].typeName = "drive_generic";
  UFG::CoronaInfos[35].coronaName = UFG::qStringHashUpper32("Corona_Generic_Drive", 0xFFFFFFFF);
  UFG::CoronaInfos[36].typeName = "drive_disabled";
  UFG::CoronaInfos[35].coronaHeight = 0.02;
  UFG::CoronaInfos[36].coronaName = UFG::qStringHashUpper32("Corona_drive_disabled", 0xFFFFFFFF);
  UFG::CoronaInfos[36].coronaHeight = 0.02;
  UFG::CoronaInfos[37].typeName = "tiffanys_gun";
  result = UFG::qStringHashUpper32("Corona_tiffanys_gun", 0xFFFFFFFF);
  UFG::CoronaInfos[37].coronaHeight = 0.02;
  UFG::CoronaInfos[37].coronaName = result;
  return result;
}

// File Line: 79
// RVA: 0x4A0550
signed __int64 __fastcall UFG::FindCoronaTypeByName(UFG::qString *name)
{
  UFG::qString *v1; // rsi
  unsigned int v2; // edi
  UFG::CoronaInfo *v3; // rbx

  v1 = name;
  if ( name->mLength <= 0 )
    return 0xFFFFFFFFi64;
  v2 = 0;
  v3 = UFG::CoronaInfos;
  while ( (unsigned int)UFG::qStringCompareInsensitive(v1->mData, v3->typeName, -1) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&`anonymous namespace::gDebugGUI_ProgressionView_Colour_Locked )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 99
// RVA: 0x4A09F0
char __fastcall UFG::FindTargetBySymbol(UFG::qSymbol *name, UFG::SimObject **simObj)
{
  UFG::SimObject **v2; // rbx
  UFG::qSymbol *v3; // rdi
  UFG::TSActor *v4; // rax
  UFG::SimObject *v5; // rax
  UFG::qBaseTreeRB *v7; // rax
  UFG::SimObject *v8; // rax

  v2 = simObj;
  v3 = name;
  v4 = UFG::TSActor::find_instance(name);
  if ( v4 )
  {
    v5 = v4->mpSimObj.m_pPointer;
    if ( v5 )
    {
      *v2 = v5;
      return 1;
    }
  }
  else
  {
    v7 = UFG::MarkerBase::GetNamed(v3);
    if ( v7 )
    {
      v8 = (UFG::SimObject *)v7->mNULL.mChild[0];
      if ( v8 )
      {
        *v2 = v8;
        return 1;
      }
    }
  }
  return 0;
}

// File Line: 130
// RVA: 0x48D030
void __fastcall UFG::ObjectiveIndicator::ObjectiveIndicator(UFG::ObjectiveIndicator *this, UFG::qSymbol *identifier, UFG::qString *blip, UFG::qString *corona, bool temporary)
{
  UFG::qString *v5; // rbx
  UFG::ObjectiveIndicator *v6; // rdi
  unsigned int v7; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v8; // [rsp+48h] [rbp+10h]

  v5 = corona;
  v6 = this;
  v7 = identifier->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v7;
  this->vfptr = (UFG::ObjectiveIndicatorVtbl *)&UFG::ObjectiveIndicator::`vftable;
  this->mIdentifier = (UFG::qSymbol)identifier->mUID;
  UFG::qSharedString::qSharedString(&this->mBlipType, blip->mData);
  v8 = &v6->mpEffectTransform;
  v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v8->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  v6->mpEffectTransform.m_pPointer = 0i64;
  v6->mEffectId = -1;
  v6->mEnabled = 0;
  v6->mTemporary = temporary;
  v6->mCoronaType = UFG::FindCoronaTypeByName(v5);
}

// File Line: 135
// RVA: 0x490C60
void __fastcall UFG::ObjectiveIndicator::~ObjectiveIndicator(UFG::ObjectiveIndicator *this)
{
  UFG::ObjectiveIndicator *v1; // rbx
  unsigned int v2; // edx
  UFG::SimComponent *v3; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::ObjectiveIndicatorVtbl *)&UFG::ObjectiveIndicator::`vftable;
  if ( this->mEnabled )
  {
    this->mEnabled = 0;
    v2 = this->mEffectId;
    if ( v2 != -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v2, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
      v1->mEffectId = -1;
    }
    v3 = v1->mpEffectTransform.m_pPointer;
    if ( v3 )
    {
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v3);
      v4 = &v1->mpEffectTransform;
      if ( v1->mpEffectTransform.m_pPointer )
      {
        v5 = v4->mPrev;
        v6 = v1->mpEffectTransform.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
        v1->mpEffectTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpEffectTransform.mPrev;
      }
      v1->mpEffectTransform.m_pPointer = 0i64;
    }
  }
  v7 = &v1->mpEffectTransform;
  if ( v1->mpEffectTransform.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mpEffectTransform.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mpEffectTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpEffectTransform.mPrev;
  }
  v1->mpEffectTransform.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mpEffectTransform.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mpEffectTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpEffectTransform.mPrev;
  UFG::qSharedString::~qSharedString(&v1->mBlipType);
}

// File Line: 140
// RVA: 0x4BC1A0
void __fastcall UFG::ObjectiveIndicator::SetEnabled(UFG::ObjectiveIndicator *this, bool enabled)
{
  UFG::ObjectiveIndicator *v2; // rdi
  UFG::TSActor *v3; // rax
  UFG::SimObjectGame *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax
  unsigned __int16 v6; // cx
  UFG::HealthComponent *v7; // rsi
  UFG::SimComponent *v8; // rax
  UFG::CoronaInfo *v9; // r14
  UFG::qMemoryPool *v10; // rax
  UFG::allocator::free_link *v11; // rax
  unsigned __int16 v12; // cx
  unsigned int v13; // esi
  UFG::TransformNodeComponent *v14; // rdx
  unsigned int v15; // eax
  unsigned int v16; // edx
  UFG::SimComponent *v17; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v18; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qVector3 pos; // [rsp+38h] [rbp-50h]
  UFG::SimObjectModifier v22; // [rsp+48h] [rbp-40h]

  v2 = this;
  if ( this->mEnabled != enabled )
  {
    this->mEnabled = enabled;
    if ( enabled && this->mCoronaType != -1 )
    {
      v3 = UFG::TSActor::find_instance(&this->mIdentifier);
      if ( v3 )
      {
        v4 = (UFG::SimObjectGame *)v3->mpSimObj.m_pPointer;
      }
      else
      {
        v5 = UFG::MarkerBase::GetNamed(&v2->mIdentifier);
        if ( !v5 )
          return;
        v4 = (UFG::SimObjectGame *)v5->mNULL.mChild[0];
      }
      if ( v4 )
      {
        v6 = v4->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
          else
            v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::HealthComponent::_TypeUID);
          v7 = (UFG::HealthComponent *)v8;
        }
        else
        {
          v7 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
        }
        if ( !v7 || !UFG::HealthComponent::GetIsKilled(v7) && !v7->m_bIsKnockedOut )
        {
          v9 = &UFG::CoronaInfos[v2->mCoronaType];
          v10 = UFG::GetSimulationMemoryPool();
          v11 = UFG::qMemoryPool::Allocate(v10, 0x110ui64, "ObjectiveIndicator.Indicator", 0i64, 1u);
          if ( v11 )
            UFG::TransformNodeComponent::TransformNodeComponent(
              (UFG::TransformNodeComponent *)v11,
              v4->mNode.mUID,
              0i64,
              0);
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v2->mpEffectTransform,
            (UFG::SimComponent *)v11);
          v12 = v4->m_Flags;
          if ( (v12 >> 14) & 1 )
          {
            v13 = 2;
          }
          else if ( (v12 & 0x8000u) == 0 )
          {
            if ( (v12 >> 13) & 1 )
            {
              v13 = 2;
            }
            else
            {
              v13 = -1;
              if ( (v12 >> 12) & 1 )
                v13 = 1;
            }
          }
          else
          {
            v13 = 2;
          }
          UFG::SimObjectModifier::SimObjectModifier(&v22, (UFG::SimObject *)&v4->vfptr, 1);
          UFG::SimObjectModifier::AttachComponent(&v22, v2->mpEffectTransform.m_pPointer, v13);
          UFG::SimObjectModifier::Close(&v22);
          UFG::SimObjectModifier::~SimObjectModifier(&v22);
          v14 = v4->m_pTransformNodeComponent;
          if ( v14 )
            UFG::TransformNodeComponent::SetParent(
              (UFG::TransformNodeComponent *)v2->mpEffectTransform.m_pPointer,
              v14,
              eInheritXform_Translation);
          v15 = Render::FXManager::CreateEffect(
                  &Render::gFXManager,
                  v9->coronaName,
                  (UFG::TransformNodeComponent *)v2->mpEffectTransform.m_pPointer,
                  0xFFFFFFFF,
                  0i64);
          v2->mEffectId = v15;
          Render::FXManager::EnableOcclusionCulling(&Render::gFXManager, v15);
          *(_QWORD *)&pos.x = 0i64;
          pos.z = v9->coronaHeight;
          UFG::TransformNodeComponent::SetLocalTranslation(
            (UFG::TransformNodeComponent *)v2->mpEffectTransform.m_pPointer,
            &pos);
        }
      }
    }
    else
    {
      v16 = this->mEffectId;
      if ( v16 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v16, FXKILLOPTION_ERASE_EMITTED_OBJECTS);
        v2->mEffectId = -1;
      }
      v17 = v2->mpEffectTransform.m_pPointer;
      if ( v17 )
      {
        UFG::Simulation::DestroySimComponent(&UFG::gSim, v17);
        v18 = &v2->mpEffectTransform;
        if ( v18->m_pPointer )
        {
          v19 = v18->mPrev;
          v20 = v18->mNext;
          v19->mNext = v20;
          v20->mPrev = v19;
          v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
          v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
        }
        v18->m_pPointer = 0i64;
      }
    }
  }
}

// File Line: 212
// RVA: 0x48CF30
void __fastcall UFG::Objective::Objective(UFG::Objective *this, unsigned int loadId, UFG::GameSlice *pGameSlice, const char *identifier, const char *caption, const char *locationCaption, const char *log, const char *gpsMarker)
{
  const char *v8; // rdi
  UFG::GameSlice *v9; // rbx
  unsigned int v10; // esi
  UFG::Objective *v11; // r14
  unsigned int v12; // eax

  v8 = identifier;
  v9 = pGameSlice;
  v10 = loadId;
  v11 = this;
  v12 = UFG::qStringHash32(identifier, 0xFFFFFFFF);
  v11->mNode.mParent = 0i64;
  v11->mNode.mChild[0] = 0i64;
  v11->mNode.mChild[1] = 0i64;
  v11->mNode.mUID = v12;
  v11->vfptr = (UFG::ObjectiveVtbl *)&UFG::Objective::`vftable;
  v11->mpGameSlice = v9;
  UFG::qString::qString(&v11->mIdentifier, v8);
  UFG::qString::qString(&v11->mCaption, caption);
  UFG::qSharedString::qSharedString(&v11->mLocationCaption, locationCaption);
  UFG::qSharedString::qSharedString(&v11->mLog, log);
  UFG::qSharedString::qSharedString(&v11->mGPSMarker, gpsMarker);
  *(_DWORD *)&v11->mAutoflash = 0;
  UFG::qBaseTreeRB::qBaseTreeRB(&v11->mIndicators.mTree);
  v11->mDisplayPriority = 0;
  v11->mLoadId = v10;
  v11->mStatus = 0;
}

// File Line: 216
// RVA: 0x490B80
void __fastcall UFG::Objective::~Objective(UFG::Objective *this)
{
  UFG::Objective *v1; // rsi
  Render::Skinning *v2; // rdi
  Render::SkinningCacheNode *v3; // rax
  Illusion::Buffer **v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx

  v1 = this;
  this->vfptr = (UFG::ObjectiveVtbl *)&UFG::Objective::`vftable;
  v2 = (Render::Skinning *)&this->mIndicators;
  if ( this->mIndicators.mTree.mCount )
  {
    while ( 1 )
    {
      v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v2->mSkinnedVertexBuffers);
      if ( !v3 )
        break;
      v4 = &v3[-1].mCachedBufferPtr;
      if ( v3 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v5 = &v3->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v2->mSkinnedVertexBuffers.mTree, v5);
      if ( v4 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v4)->mNode.mParent)(v4, 1i64);
      if ( !v2->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    v4 = 0i64;
LABEL_6:
    v5 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)v2);
  UFG::qBaseTreeRB::~qBaseTreeRB(v2);
  UFG::qSharedString::~qSharedString(&v1->mGPSMarker);
  UFG::qSharedString::~qSharedString(&v1->mLog);
  UFG::qSharedString::~qSharedString(&v1->mLocationCaption);
  UFG::qString::~qString(&v1->mCaption);
  UFG::qString::~qString(&v1->mIdentifier);
}

// File Line: 245
// RVA: 0x4C7810
void __fastcall UFG::Objective::UpdateIndicators(UFG::Objective *this)
{
  UFG::qBaseTreeRB *v1; // rdi
  bool v2; // si
  Render::SkinningCacheNode *v3; // rax
  UFG::ObjectiveIndicator *v4; // rbx
  UFG::qBaseTreeRB *v5; // rax

  v1 = &this->mIndicators.mTree;
  v2 = (unsigned int)(this->mStatus - 1) <= 1;
  v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( v3 )
  {
    v4 = (UFG::ObjectiveIndicator *)&v3[-1].mCachedBufferPtr;
    if ( v3 != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        UFG::ObjectiveIndicator::SetEnabled(v4, v2);
        v5 = UFG::qBaseTreeRB::GetNext(v1, &v4->mNode);
        if ( !v5 )
          break;
        v4 = (UFG::ObjectiveIndicator *)&v5[-1].mCount;
      }
      while ( v5 != (UFG::qBaseTreeRB *)8 );
    }
  }
}

// File Line: 273
// RVA: 0x492DB0
void __fastcall UFG::Objective::AddIndicator(UFG::Objective *this, UFG::qSymbol *identifier, UFG::qString *blip, UFG::qString *corona, bool temporary)
{
  UFG::qString *v5; // rbp
  UFG::qString *v6; // r14
  UFG::qSymbolUC *v7; // rdi
  UFG::qBaseTreeRB *v8; // rsi
  Render::SkinningCacheNode *v9; // rax
  signed __int64 v10; // rcx
  UFG::qBaseTreeRB *v11; // rax
  char *v12; // rax
  Render::SkinningCacheNode *v13; // rax
  signed __int64 v14; // rbx
  UFG::qBaseNodeRB *v15; // rdx
  UFG::qBaseTreeRB *v16; // rax
  UFG::allocator::free_link *v17; // rax
  UFG::qBaseNodeRB *v18; // rbx
  __int64 v19; // rax

  v5 = corona;
  v6 = blip;
  v7 = (UFG::qSymbolUC *)identifier;
  v8 = &this->mIndicators.mTree;
  v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( v9 )
  {
    v10 = (signed __int64)&v9[-1].mCachedBufferPtr;
    if ( v9 != (Render::SkinningCacheNode *)8 )
    {
      while ( *(_DWORD *)(v10 + 40) != v7->mUID )
      {
        v11 = UFG::qBaseTreeRB::GetNext(v8, (UFG::qBaseNodeRB *)(v10 + 8));
        if ( v11 )
        {
          v10 = (signed __int64)&v11[-1].mCount;
          if ( v11 != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        goto LABEL_14;
      }
      v12 = UFG::qSymbol::as_cstr_dbg(v7);
      UFG::qPrintf("WARNING: Duplicate objective indicator found!  (%s)\n", v12);
      v13 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v8);
      if ( v13 )
      {
        v14 = (signed __int64)&v13[-1].mCachedBufferPtr;
        if ( v13 != (Render::SkinningCacheNode *)8 )
        {
          while ( 1 )
          {
            v15 = (UFG::qBaseNodeRB *)(v14 + 8);
            if ( *(_DWORD *)(v14 + 40) == v7->mUID )
              break;
            v16 = UFG::qBaseTreeRB::GetNext(v8, v15);
            if ( v16 )
            {
              v14 = (signed __int64)&v16[-1].mCount;
              if ( v16 != (UFG::qBaseTreeRB *)8 )
                continue;
            }
            goto LABEL_14;
          }
          UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
            (UFG::qBaseTreeVariableRB<unsigned __int64> *)v8,
            (UFG::qBaseNodeVariableRB<unsigned __int64> *)v15);
          (**(void (__fastcall ***)(signed __int64, signed __int64))v14)(v14, 1i64);
        }
      }
    }
  }
LABEL_14:
  v17 = UFG::qMalloc(0x60ui64, "ObjectiveTracker", 0i64);
  v18 = 0i64;
  if ( v17 )
    UFG::ObjectiveIndicator::ObjectiveIndicator((UFG::ObjectiveIndicator *)v17, (UFG::qSymbol *)v7, v6, v5, temporary);
  else
    v19 = 0i64;
  if ( v19 )
    v18 = (UFG::qBaseNodeRB *)(v19 + 8);
  UFG::qBaseTreeRB::Add(v8, v18);
}

// File Line: 287
// RVA: 0x4B6430
void __fastcall UFG::Objective::RemoveIndicator(UFG::Objective *this, UFG::qSymbol *name, bool removeTemporaryOnly)
{
  UFG::qBaseTreeRB *v3; // rsi
  bool v4; // bp
  UFG::qSymbol *v5; // rdi
  Render::SkinningCacheNode *v6; // rax
  signed __int64 v7; // rbx
  UFG::qBaseTreeRB *v8; // rax

  v3 = &this->mIndicators.mTree;
  v4 = removeTemporaryOnly;
  v5 = name;
  v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mIndicators);
  if ( v6 )
  {
    v7 = (signed __int64)&v6[-1].mCachedBufferPtr;
    if ( v6 != (Render::SkinningCacheNode *)8 )
    {
      while ( *(_DWORD *)(v7 + 40) != v5->mUID )
      {
        v8 = UFG::qBaseTreeRB::GetNext(v3, (UFG::qBaseNodeRB *)(v7 + 8));
        if ( v8 )
        {
          v7 = (signed __int64)&v8[-1].mCount;
          if ( v8 != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        return;
      }
      if ( !v4 || *(_BYTE *)(v7 + 89) )
      {
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
          (UFG::qBaseTreeVariableRB<unsigned __int64> *)v3,
          (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v7 + 8));
        (**(void (__fastcall ***)(signed __int64, signed __int64))v7)(v7, 1i64);
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
    result = (Render::SkinningCacheNode *)((char *)result - 8);
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
    result = (UFG::qBaseTreeRB *)((char *)result - 8);
  return result;
}

// File Line: 332
// RVA: 0x4B0CD0
signed __int64 __fastcall UFG::Objective::MapSymbolToStatus(ASymbol *symbol)
{
  unsigned int v1; // eax
  unsigned int v2; // edx

  v1 = symbol->i_uid;
  v2 = 0;
  if ( symbol->i_uid != ObjectiveSym_INACTIVE.i_uid )
  {
    if ( v1 == ObjectiveSym_ACTIVE.i_uid )
      return 1i64;
    if ( v1 == ObjectiveSym_HIGHLIGHT.i_uid )
      return 2i64;
    if ( v1 == ObjectiveSym_COMPLETED.i_uid )
      return 3i64;
    if ( v1 == ObjectiveSym_FAILED.i_uid )
      v2 = 4;
  }
  return v2;
}

// File Line: 374
// RVA: 0x490D40
void __fastcall UFG::ObjectiveTracker::~ObjectiveTracker(UFG::ObjectiveTracker *this)
{
  UFG::ObjectiveTracker *v1; // rsi
  UFG::Objective **v2; // rcx
  Render::SkinningCacheNode *v3; // rax
  Illusion::Buffer **v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx
  UFG::Objective **v9; // rcx

  v1 = this;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager::mInstance);
  v2 = v1->mLoadedOrderObjectives.p;
  if ( v2 )
    operator delete[](v2);
  v1->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&v1->mLoadedOrderObjectives.size = 0i64;
  if ( v1->mObjectives.mTree.mCount )
  {
    while ( 1 )
    {
      v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mObjectives);
      if ( !v3 )
        break;
      v4 = &v3[-1].mCachedBufferPtr;
      if ( v3 == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      v5 = &v3->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mObjectives,
        v5);
      if ( v4 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v4)->mNode.mParent)(v4, 1i64);
      if ( !v1->mObjectives.mTree.mCount )
        goto LABEL_14;
    }
    v4 = 0i64;
LABEL_10:
    v5 = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  if ( v1->mObjectiveHints.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mObjectiveHints);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_19;
      v8 = &v6->mNode;
LABEL_20:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mObjectiveHints,
        v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !v1->mObjectiveHints.mTree.mCount )
        goto LABEL_23;
    }
    v7 = 0i64;
LABEL_19:
    v8 = 0i64;
    goto LABEL_20;
  }
LABEL_23:
  v1->mLastLoadId = 0;
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&v1->mObjectiveHints);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mObjectiveHints);
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)&v1->mObjectives);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mObjectives);
  v9 = v1->mLoadedOrderObjectives.p;
  if ( v9 )
    operator delete[](v9);
  v1->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&v1->mLoadedOrderObjectives.size = 0i64;
}

// File Line: 388
// RVA: 0x497950
void __fastcall UFG::ObjectiveTracker::Clear(UFG::ObjectiveTracker *this)
{
  UFG::ObjectiveTracker *v1; // rsi
  UFG::Objective **v2; // rcx
  Render::SkinningCacheNode *v3; // rax
  Illusion::Buffer **v4; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rdx
  Render::SkinningCacheNode *v6; // rax
  Illusion::Buffer **v7; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v8; // rdx

  v1 = this;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::Clear(UFG::UIHKPlayerObjectiveManager::mInstance);
  v2 = v1->mLoadedOrderObjectives.p;
  if ( v2 )
    operator delete[](v2);
  v1->mLoadedOrderObjectives.p = 0i64;
  *(_QWORD *)&v1->mLoadedOrderObjectives.size = 0i64;
  if ( v1->mObjectives.mTree.mCount )
  {
    while ( 1 )
    {
      v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mObjectives);
      if ( !v3 )
        break;
      v4 = &v3[-1].mCachedBufferPtr;
      if ( v3 == (Render::SkinningCacheNode *)8 )
        goto LABEL_10;
      v5 = &v3->mNode;
LABEL_11:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mObjectives,
        v5);
      if ( v4 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v4)->mNode.mParent)(v4, 1i64);
      if ( !v1->mObjectives.mTree.mCount )
        goto LABEL_14;
    }
    v4 = 0i64;
LABEL_10:
    v5 = 0i64;
    goto LABEL_11;
  }
LABEL_14:
  if ( v1->mObjectiveHints.mTree.mCount )
  {
    while ( 1 )
    {
      v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mObjectiveHints);
      if ( !v6 )
        break;
      v7 = &v6[-1].mCachedBufferPtr;
      if ( v6 == (Render::SkinningCacheNode *)8 )
        goto LABEL_19;
      v8 = &v6->mNode;
LABEL_20:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mObjectiveHints,
        v8);
      if ( v7 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v7)->mNode.mParent)(v7, 1i64);
      if ( !v1->mObjectiveHints.mTree.mCount )
        goto LABEL_23;
    }
    v7 = 0i64;
LABEL_19:
    v8 = 0i64;
    goto LABEL_20;
  }
LABEL_23:
  v1->mLastLoadId = 0;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
}

// File Line: 462
// RVA: 0x4936B0
UFG::Objective *__fastcall UFG::ObjectiveTracker::AddObjective(UFG::ObjectiveTracker *this, const char *identifier, const char *caption, const char *locationCaption, const char *log, const char *gpsMarker, UFG::GameSlice *pGameSlice)
{
  const char *v7; // r14
  const char *v8; // r15
  const char *v9; // rbp
  UFG::ObjectiveTracker *v10; // rdi
  int v11; // edx
  unsigned int v12; // eax
  UFG::qBaseNodeRB *v13; // rbx
  UFG::qBaseTreeRB *v14; // rax
  signed __int64 v15; // rsi
  UFG::allocator::free_link *v16; // rax
  signed __int64 v17; // rax
  __int64 v18; // rbp
  unsigned int v19; // ebx
  unsigned int v20; // edx
  unsigned int v21; // edx
  UFG::qString v23; // [rsp+50h] [rbp-48h]

  v7 = locationCaption;
  v8 = caption;
  v9 = identifier;
  v10 = this;
  UFG::qString::qString(&v23, identifier);
  v12 = v23.mStringHash32;
  if ( v23.mStringHash32 == -1 )
  {
    v12 = UFG::qStringHash32(v23.mData, v23.mStringHash32 | v11);
    v23.mStringHash32 = v12;
  }
  v13 = 0i64;
  if ( !v12 || (v14 = UFG::qBaseTreeRB::Get(&v10->mObjectives.mTree, v12), v15 = (signed __int64)&v14[-1].mCount, !v14) )
    v15 = 0i64;
  UFG::qString::~qString(&v23);
  if ( !v15 )
  {
    v16 = UFG::qMalloc(0xF8ui64, "ObjectiveTracker", 0i64);
    if ( v16 )
    {
      UFG::Objective::Objective((UFG::Objective *)v16, v10->mLastLoadId, pGameSlice, v9, v8, v7, log, gpsMarker);
      v15 = v17;
    }
    else
    {
      v15 = 0i64;
    }
    if ( v15 )
      v13 = (UFG::qBaseNodeRB *)(v15 + 8);
    UFG::qBaseTreeRB::Add(&v10->mObjectives.mTree, v13);
    v18 = v10->mLoadedOrderObjectives.size;
    v19 = v18 + 1;
    v20 = v10->mLoadedOrderObjectives.capacity;
    if ( (signed int)v18 + 1 > v20 )
    {
      if ( v20 )
        v21 = 2 * v20;
      else
        v21 = 1;
      for ( ; v21 < v19; v21 *= 2 )
        ;
      if ( v21 <= 2 )
        v21 = 2;
      if ( v21 - v19 > 0x10000 )
        v21 = v18 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)v10,
        v21,
        "qArray.Add");
    }
    v10->mLoadedOrderObjectives.size = v19;
    v10->mLoadedOrderObjectives.p[v18] = (UFG::Objective *)v15;
    ++v10->mLastLoadId;
  }
  return (UFG::Objective *)v15;
}

// File Line: 480
// RVA: 0x4C5890
void __fastcall UFG::ObjectiveTracker::UpdateCaption(UFG::ObjectiveTracker *this, UFG::qString *identifier, UFG::qString *caption, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v4; // rdi
  UFG::qString *v5; // rsi
  UFG::qString *v6; // rbx
  UFG::ObjectiveTracker *v7; // rbp
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  signed __int64 v10; // rbx
  UFG::UIHKPlayerObjectiveManager *v11; // rdi

  v4 = pGameSlice;
  v5 = caption;
  v6 = identifier;
  v7 = this;
  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  v8 = v6->mStringHash32;
  if ( v8 )
  {
    v9 = UFG::qBaseTreeRB::Get(&v7->mObjectives.mTree, v8);
    if ( v9 )
    {
      v10 = (signed __int64)&v9[-1].mCount;
      if ( v9 != (UFG::qBaseTreeRB *)8 )
      {
        if ( v4 )
          *(_QWORD *)(v10 + 40) = v4;
        UFG::qString::Set((UFG::qString *)(v10 + 88), v5->mData, v5->mLength, 0i64, 0);
        if ( (unsigned int)(*(_DWORD *)(v10 + 240) - 1) <= 1 )
        {
          v11 = UFG::UIHKPlayerObjectiveManager::mInstance;
          if ( UFG::UIHKPlayerObjectiveManager::mInstance )
          {
            UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
            if ( *(_BYTE *)(v10 + 152) )
              UFG::UIHKPlayerObjectiveManager::FlashObjective(v11, (UFG::Objective *)v10, 0);
          }
        }
      }
    }
  }
}

// File Line: 503
// RVA: 0x4C8930
void __fastcall UFG::ObjectiveTracker::UpdateStatus(UFG::ObjectiveTracker *this, UFG::qString *identifier, UFG::Objective::Status status, UFG::GameSlice *pGameSlice)
{
  UFG::GameSlice *v4; // rdi
  UFG::Objective::Status v5; // esi
  UFG::qString *v6; // rbx
  UFG::ObjectiveTracker *v7; // rbp
  unsigned int v8; // edx
  UFG::qBaseTreeRB *v9; // rax
  signed __int64 v10; // rbx
  UFG::UIHKPlayerObjectiveManager *v11; // rdi

  v4 = pGameSlice;
  v5 = status;
  v6 = identifier;
  v7 = this;
  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  v8 = v6->mStringHash32;
  if ( v8 )
  {
    v9 = UFG::qBaseTreeRB::Get(&v7->mObjectives.mTree, v8);
    if ( v9 )
    {
      v10 = (signed __int64)&v9[-1].mCount;
      if ( v9 != (UFG::qBaseTreeRB *)8 )
      {
        if ( v4 )
          *(_QWORD *)(v10 + 40) = v4;
        *(_DWORD *)(v10 + 240) = v5;
        UFG::Objective::UpdateIndicators((UFG::Objective *)&v9[-1].mCount);
        if ( (unsigned int)(v5 - 1) > 1 )
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
            if ( *(_BYTE *)(v10 + 152) )
              UFG::UIHKPlayerObjectiveManager::FlashObjective(v11, (UFG::Objective *)v10, 0);
          }
        }
      }
    }
  }
}

// File Line: 529
// RVA: 0x4C8A00
void __fastcall UFG::ObjectiveTracker::UpdateStatus(UFG::ObjectiveTracker *this, UFG::Objective *pObjective, bool refreshFlash)
{
  UFG::ObjectiveTracker::UpdateStatus(this, pObjective, pObjective->mStatus, pObjective->mpGameSlice, refreshFlash);
}

// File Line: 535
// RVA: 0x4C88A0
void __fastcall UFG::ObjectiveTracker::UpdateStatus(UFG::ObjectiveTracker *this, UFG::Objective *pObjective, UFG::Objective::Status status, UFG::GameSlice *pGameSlice, bool updateFlash)
{
  UFG::Objective::Status v5; // edi
  UFG::Objective *v6; // rbx
  UFG::UIHKPlayerObjectiveManager *v7; // rdi

  v5 = status;
  v6 = pObjective;
  if ( pGameSlice )
    pObjective->mpGameSlice = pGameSlice;
  pObjective->mStatus = status;
  UFG::Objective::UpdateIndicators(pObjective);
  if ( updateFlash && (unsigned int)(v5 - 1) <= 1 )
  {
    v7 = UFG::UIHKPlayerObjectiveManager::mInstance;
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    {
      UFG::UIHKPlayerObjectiveManager::UpdateObjectives(UFG::UIHKPlayerObjectiveManager::mInstance);
      if ( v6->mAutoflash )
        UFG::UIHKPlayerObjectiveManager::FlashObjective(v7, v6, 0);
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
  UFG::qBaseTreeRB *v1; // r14
  Render::SkinningCacheNode *v2; // rax
  signed __int64 v3; // rbp
  Render::SkinningCacheNode *v4; // rax
  signed __int64 v5; // rbx
  signed __int64 v6; // rdi
  UFG::qBaseTreeRB *v7; // rax
  int v8; // eax
  Render::SkinningCacheNode *v9; // rax
  UFG::ObjectiveIndicator *v10; // rbx
  UFG::qBaseTreeRB *v11; // rax
  UFG::qBaseTreeRB *v12; // rax

  v1 = &this->mObjectives.mTree;
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( v2 )
  {
    v3 = (signed __int64)&v2[-1].mCachedBufferPtr;
    if ( v2 != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v3 + 160));
        if ( v4 )
        {
          v5 = (signed __int64)&v4[-1].mCachedBufferPtr;
          if ( v4 != (Render::SkinningCacheNode *)8 )
          {
            do
            {
              v6 = 0i64;
              if ( *(_BYTE *)(v5 + 89) )
                v6 = v5;
              v7 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v3 + 160), (UFG::qBaseNodeRB *)(v5 + 8));
              v5 = (signed __int64)&v7[-1].mCount;
              if ( !v7 )
                v5 = 0i64;
              if ( v6 )
              {
                UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
                  (UFG::qBaseTreeVariableRB<unsigned __int64> *)(v3 + 160),
                  (UFG::qBaseNodeVariableRB<unsigned __int64> *)(v6 + 8));
                (**(void (__fastcall ***)(signed __int64, signed __int64))v6)(v6, 1i64);
              }
            }
            while ( v5 );
          }
        }
        v8 = *(_DWORD *)(v3 + 240);
        if ( v8 )
        {
          if ( (unsigned int)(v8 - 3) > 1 )
          {
            *(_DWORD *)(v3 + 240) = 0;
            UFG::Objective::UpdateIndicators((UFG::Objective *)v3);
          }
        }
        else
        {
          *(_DWORD *)(v3 + 240) = 0;
          v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v3 + 160));
          if ( v9 )
          {
            v10 = (UFG::ObjectiveIndicator *)&v9[-1].mCachedBufferPtr;
            if ( v9 != (Render::SkinningCacheNode *)8 )
            {
              do
              {
                UFG::ObjectiveIndicator::SetEnabled(v10, 0);
                v11 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v3 + 160), &v10->mNode);
                if ( !v11 )
                  break;
                v10 = (UFG::ObjectiveIndicator *)&v11[-1].mCount;
              }
              while ( v11 != (UFG::qBaseTreeRB *)8 );
            }
          }
        }
        v12 = UFG::qBaseTreeRB::GetNext(v1, (UFG::qBaseNodeRB *)(v3 + 8));
        if ( !v12 )
          break;
        v3 = (signed __int64)&v12[-1].mCount;
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
  UFG::qBaseTreeRB *v1; // rbp
  Render::SkinningCacheNode *v2; // rax
  signed __int64 v3; // rdi
  Render::SkinningCacheNode *v4; // rax
  UFG::ObjectiveIndicator *v5; // rbx
  UFG::qBaseTreeRB *v6; // rax
  UFG::qBaseTreeRB *v7; // rax

  v1 = &this->mObjectives.mTree;
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( v2 )
  {
    v3 = (signed __int64)&v2[-1].mCachedBufferPtr;
    if ( v2 != (Render::SkinningCacheNode *)8 )
    {
      do
      {
        if ( !*(_DWORD *)(v3 + 240) )
        {
          *(_DWORD *)(v3 + 240) = 0;
          v4 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v3 + 160));
          if ( v4 )
          {
            v5 = (UFG::ObjectiveIndicator *)&v4[-1].mCachedBufferPtr;
            if ( v4 != (Render::SkinningCacheNode *)8 )
            {
              do
              {
                UFG::ObjectiveIndicator::SetEnabled(v5, 0);
                v6 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v3 + 160), &v5->mNode);
                if ( !v6 )
                  break;
                v5 = (UFG::ObjectiveIndicator *)&v6[-1].mCount;
              }
              while ( v6 != (UFG::qBaseTreeRB *)8 );
            }
          }
        }
        v7 = UFG::qBaseTreeRB::GetNext(v1, (UFG::qBaseNodeRB *)(v3 + 8));
        if ( !v7 )
          break;
        v3 = (signed __int64)&v7[-1].mCount;
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
  UFG::qBaseTreeRB *v2; // r14
  UFG::GameSlice *v3; // rbp
  char v4; // bl
  Render::SkinningCacheNode *v5; // rax
  signed __int64 v6; // rdi
  Render::SkinningCacheNode *v7; // rax
  UFG::ObjectiveIndicator *v8; // rbx
  UFG::qBaseTreeRB *v9; // rax
  UFG::qBaseTreeRB *v10; // rax

  v2 = &this->mObjectives.mTree;
  v3 = pGameSlice;
  v4 = 0;
  v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( !v5 )
    return;
  v6 = (signed __int64)&v5[-1].mCachedBufferPtr;
  if ( v5 == (Render::SkinningCacheNode *)8 )
    return;
  do
  {
    if ( *(UFG::GameSlice **)(v6 + 40) == v3 )
    {
      if ( !((v3->mCompletionStatus - 1) & 0xFFFFFFFD) )
      {
        *(_DWORD *)(v6 + 240) = 0;
        v7 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v6 + 160));
        if ( v7 )
        {
          v8 = (UFG::ObjectiveIndicator *)&v7[-1].mCachedBufferPtr;
          if ( v7 != (Render::SkinningCacheNode *)8 )
          {
            do
            {
              UFG::ObjectiveIndicator::SetEnabled(v8, 0);
              v9 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v6 + 160), &v8->mNode);
              if ( !v9 )
                break;
              v8 = (UFG::ObjectiveIndicator *)&v9[-1].mCount;
            }
            while ( v9 != (UFG::qBaseTreeRB *)8 );
          }
        }
        goto LABEL_11;
      }
      if ( *(_DWORD *)(v6 + 240) == 3 )
      {
        *(_DWORD *)(v6 + 240) = 0;
        UFG::Objective::UpdateIndicators((UFG::Objective *)v6);
LABEL_11:
        v4 = 1;
        goto LABEL_12;
      }
    }
LABEL_12:
    v10 = UFG::qBaseTreeRB::GetNext(v2, (UFG::qBaseNodeRB *)(v6 + 8));
    if ( !v10 )
      break;
    v6 = (signed __int64)&v10[-1].mCount;
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
  UFG::qString *v2; // rbx
  UFG::ObjectiveTracker *v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::Objective *result; // rax

  v2 = identifier;
  v3 = this;
  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  v4 = v2->mStringHash32;
  if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&v3->mObjectives.mTree, v4)) != 0i64 )
    result = (UFG::Objective *)&v5[-1].mCount;
  else
    result = 0i64;
  return result;
}

// File Line: 637
// RVA: 0x4A2900
UFG::Objective *__fastcall UFG::ObjectiveTracker::GetFirstObjective(UFG::ObjectiveTracker *this)
{
  UFG::ObjectiveTracker *v1; // rbp
  __int64 v2; // rbx
  UFG::Objective *v3; // rdi
  UFG::GameStatTracker *v4; // rcx
  UFG::PersistentData::MapInt *v5; // rsi
  UFG::qSymbol *v6; // rcx
  __int64 v7; // rax
  unsigned int v8; // edx
  UFG::PersistentData::KeyValue *v9; // rcx
  float v10; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = 0i64;
  if ( !this->mLastLoadId )
    return 0i64;
  while ( 1 )
  {
    v3 = v1->mLoadedOrderObjectives.p[v2];
    if ( v3->mStatus )
    {
      if ( !v3->mTextUnlockable )
        return v3;
      if ( !(_S12_6 & 1) )
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
      v8 = v6->mUID;
      v9 = v5->mValues.p;
      while ( v9->mKey.mUID != v8 )
      {
        v7 = (unsigned int)(v7 + 1);
        ++v9;
        if ( (unsigned int)v7 >= v5->mValues.size )
          goto LABEL_15;
      }
      if ( (_DWORD)v7 != -1 )
        v10 = v5->mValues.p[v7].mFloatValue;
      else
LABEL_15:
        v10 = 0.0;
      if ( SLODWORD(v10) > 0 )
        return v3;
    }
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= v1->mLastLoadId )
      return 0i64;
  }
}

// File Line: 650
// RVA: 0x4A54E0
UFG::Objective *__fastcall UFG::ObjectiveTracker::GetNextObjective(UFG::ObjectiveTracker *this, UFG::Objective *pPrevious)
{
  UFG::ObjectiveTracker *v2; // rbp
  __int64 v3; // rbx
  UFG::Objective *v4; // rdi
  UFG::GameStatTracker *v5; // rcx
  UFG::PersistentData::MapInt *v6; // rsi
  UFG::qSymbol *v7; // rcx
  __int64 v8; // rax
  unsigned int v9; // edx
  UFG::PersistentData::KeyValue *v10; // rcx
  float v11; // eax
  UFG::qSymbol result; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = pPrevious->mLoadId + 1;
  if ( (unsigned int)v3 >= this->mLastLoadId )
    return 0i64;
  while ( 1 )
  {
    v4 = v2->mLoadedOrderObjectives.p[v3];
    if ( v4->mStatus )
    {
      if ( !v4->mTextUnlockable )
        return v4;
      if ( !(_S12_6 & 1) )
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
      v9 = v7->mUID;
      v10 = v6->mValues.p;
      while ( v10->mKey.mUID != v9 )
      {
        v8 = (unsigned int)(v8 + 1);
        ++v10;
        if ( (unsigned int)v8 >= v6->mValues.size )
          goto LABEL_15;
      }
      if ( (_DWORD)v8 != -1 )
        v11 = v6->mValues.p[v8].mFloatValue;
      else
LABEL_15:
        v11 = 0.0;
      if ( SLODWORD(v11) > 0 )
        return v4;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= v2->mLastLoadId )
      return 0i64;
  }
}

// File Line: 665
// RVA: 0x49DCC0
void __fastcall UFG::ObjectiveTracker::EnableObjectiveIndicatorCorona(UFG::ObjectiveTracker *this, UFG::qSymbol *name, bool isEnable)
{
  UFG::qBaseTreeRB *v3; // rbp
  bool v4; // r14
  UFG::qSymbol *v5; // rsi
  Render::SkinningCacheNode *v6; // rax
  signed __int64 v7; // rbx
  Render::SkinningCacheNode *v8; // rax
  UFG::ObjectiveIndicator *v9; // rcx
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *v11; // rax

  v3 = &this->mObjectives.mTree;
  v4 = isEnable;
  v5 = name;
  v6 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mObjectives);
  if ( v6 )
  {
    v7 = (signed __int64)&v6[-1].mCachedBufferPtr;
    if ( v6 != (Render::SkinningCacheNode *)8 )
    {
      while ( 1 )
      {
        if ( *(_DWORD *)(v7 + 240) == 1 )
        {
          v8 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)(v7 + 160));
          if ( v8 )
          {
            v9 = (UFG::ObjectiveIndicator *)&v8[-1].mCachedBufferPtr;
            if ( v8 != (Render::SkinningCacheNode *)8 )
              break;
          }
        }
LABEL_9:
        v11 = UFG::qBaseTreeRB::GetNext(v3, (UFG::qBaseNodeRB *)(v7 + 8));
        if ( v11 )
        {
          v7 = (signed __int64)&v11[-1].mCount;
          if ( v11 != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        return;
      }
      while ( v9->mIdentifier.mUID != v5->mUID )
      {
        v10 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)(v7 + 160), &v9->mNode);
        if ( v10 )
        {
          v9 = (UFG::ObjectiveIndicator *)&v10[-1].mCount;
          if ( v10 != (UFG::qBaseTreeRB *)8 )
            continue;
        }
        goto LABEL_9;
      }
      UFG::ObjectiveIndicator::SetEnabled(v9, v4);
    }
  }
}

// File Line: 713
// RVA: 0x4A0790
UFG::ObjectiveHint *__fastcall UFG::ObjectiveTracker::FindObjectiveHint(UFG::ObjectiveTracker *this, UFG::qString *identifier)
{
  UFG::qString *v2; // rbx
  UFG::ObjectiveTracker *v3; // rdi
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  UFG::ObjectiveHint *result; // rax

  v2 = identifier;
  v3 = this;
  if ( identifier->mStringHash32 == -1 )
    identifier->mStringHash32 = UFG::qStringHash32(identifier->mData, 0xFFFFFFFF);
  v4 = v2->mStringHash32;
  if ( v4 && (v5 = UFG::qBaseTreeRB::Get(&v3->mObjectiveHints.mTree, v4)) != 0i64 )
    result = (UFG::ObjectiveHint *)&v5[-1].mCount;
  else
    result = 0i64;
  return result;
}

