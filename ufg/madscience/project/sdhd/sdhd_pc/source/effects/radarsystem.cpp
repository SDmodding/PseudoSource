// File Line: 44
// RVA: 0x14E76F0
void dynamic_initializer_for__UFG::RadarSystem::sRevealParams__()
{
  UFG::qSymbol::create_from_string((UFG::qSymbol *)UFG::RadarSystem::sRevealParams, "RimLight");
  unk_1423DC2F4 = 0x3F800000;
  unk_1423DC2F8 = 1103626240;
  unk_1423DC2FC = 1;
  unk_1423DC300 = 1058642330;
  unk_1423DC304 = 0;
  UFG::qSymbol::create_from_string(&stru_1423DC308, "Weapon");
  unk_1423DC30C = 0x3F800000;
  unk_1423DC310 = 0x41C80000;
  unk_1423DC314 = 1;
  unk_1423DC318 = 0x3F19999A;
  unk_1423DC31C = 0;
  UFG::qSymbol::create_from_string(&stru_1423DC320, "CombatProp");
  unk_1423DC324 = 1065353216;
  unk_1423DC328 = 1103626240;
  unk_1423DC32C = 1;
  unk_1423DC330 = 1048576000;
  unk_1423DC334 = 0;
  UFG::qSymbol::create_from_string(&stru_1423DC338, "Explodable");
  unk_1423DC340 = LODWORD(FLOAT_40_0);
  unk_1423DC348 = LODWORD(FLOAT_0_40000001);
  unk_1423DC33C = 1065353216;
  unk_1423DC344 = 1;
  unk_1423DC34C = 1;
  UFG::qSymbol::create_from_string(&stru_1423DC350, "Interactable");
  unk_1423DC354 = 1065353216;
  unk_1423DC358 = 1103626240;
  unk_1423DC35C = 1;
  unk_1423DC360 = 1048576000;
  unk_1423DC364 = 0;
  UFG::qSymbol::create_from_string(&stru_1423DC368, "ParkourHandle");
  unk_1423DC370 = LODWORD(FLOAT_20_0);
  unk_1423DC36C = 1065353216;
  unk_1423DC374 = 1;
  unk_1423DC378 = 1048576000;
  unk_1423DC37C = 1;
  UFG::qSymbol::create_from_string(&stru_1423DC380, "PokerTile");
  unk_1423DC384 = LODWORD(FLOAT_0_1);
  unk_1423DC388 = LODWORD(FLOAT_10_0);
  unk_1423DC38C = 0;
  unk_1423DC390 = 1058642330;
  unk_1423DC394 = 256;
  UFG::qSymbol::create_from_string(&stru_1423DC398, "CashMoney");
  unk_1423DC39C = 1065353216;
  unk_1423DC3A0 = 1103626240;
  unk_1423DC3A4 = 1;
  unk_1423DC3A8 = 1058642330;
  unk_1423DC3AC = 0;
  UFG::qSymbol::create_from_string(&stru_1423DC3B0, "AttackingCharacter");
  JUMPOUT(*(_QWORD *)&flt_1414E7934);
}

// File Line: 76
// RVA: 0x14E7970
__int64 dynamic_initializer_for__UFG::RadarComponent::s_RadarComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RadarComponent::s_RadarComponentList__);
}

// File Line: 77
// RVA: 0x400A80
UFG::ComponentIDDesc *__fastcall UFG::RadarComponent::GetDesc(UFG::RadarComponent *this)
{
  return &UFG::RadarComponent::_TypeIDesc;
}

// File Line: 84
// RVA: 0x3FDBF0
void __fastcall UFG::RadarComponent::RadarComponent(UFG::RadarComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::RadarComponent *v3; // rdi
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v4; // r8
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v5; // rax
  UFG::SimObjectModifier v6; // [rsp+28h] [rbp-30h]

  v2 = pSceneObj;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v4 = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RadarComponent::`vftable;
  v3->mRadarHighlightType = UFG::gNullQSymbol;
  v5 = UFG::RadarComponent::s_RadarComponentList.mNode.mPrev;
  UFG::RadarComponent::s_RadarComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&UFG::RadarComponent::s_RadarComponentList;
  UFG::RadarComponent::s_RadarComponentList.mNode.mPrev = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::RadarComponent::_RadarComponentTypeUID,
    "RadarComponent");
  v3->mRadarHighlightType.mUID = PropertyUtils::Get<UFG::qSymbol>(v2, (UFG::qSymbol *)&sHighlightType.mUID)->mFlags;
  UFG::SimObjectModifier::SimObjectModifier(&v6, v2->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v6, (UFG::SimComponent *)&v3->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v6);
  UFG::SimObjectModifier::~SimObjectModifier(&v6);
}

// File Line: 94
// RVA: 0x3FE110
void __fastcall UFG::RadarComponent::~RadarComponent(UFG::RadarComponent *this)
{
  UFG::RadarComponent *v1; // r8
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v2; // rdx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v3; // rcx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v4; // rax
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v5; // rcx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RadarComponent::`vftable;
  if ( this == UFG::RadarComponent::s_RadarComponentpCurrentIterator )
    UFG::RadarComponent::s_RadarComponentpCurrentIterator = (UFG::RadarComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 101
// RVA: 0x400AD0
bool __fastcall UFG::RadarComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&SimSymX_propset_componentRadar.mUID);
}

// File Line: 108
// RVA: 0x400E50
void __fastcall UFG::RadarComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x58ui64, "RadarComponent", 0i64, 1u);
  if ( v3 )
    UFG::RadarComponent::RadarComponent((UFG::RadarComponent *)v3, v1);
}

// File Line: 114
// RVA: 0x14E8DE0
__int64 UFG::_dynamic_initializer_for__sHighlightType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RadarHighlightType", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sHighlightType, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sHighlightType__);
}

// File Line: 124
// RVA: 0x400AE0
void __fastcall UFG::RadarElement::Highlight(UFG::RadarElement *this, bool enable, float alpha)
{
  UFG::RadarElement *v3; // rax
  UFG::SimObject *v4; // rcx
  __int64 v5; // rax
  float v6; // xmm1_4
  float v7; // xmm3_4
  float v8; // xmm4_4
  UFG::HighlightParams highlight_params; // [rsp+20h] [rbp-28h]

  v3 = this;
  v4 = this->mDrawable.m_pPointer;
  if ( v4 )
  {
    v5 = v3->mType;
    v6 = UFG::RadarSystem::sRadarTypeColors[v5].r;
    v7 = UFG::RadarSystem::sRadarTypeColors[v5].g;
    v8 = UFG::RadarSystem::sRadarTypeColors[v5].b;
    highlight_params.mColour.a = UFG::RadarSystem::sRadarTypeColors[v5].a;
    if ( enable )
    {
      highlight_params.mColour.r = v6;
      highlight_params.mIsDepthEnabled = 1;
      highlight_params.mColour.g = v7;
      highlight_params.mColour.b = v8;
      highlight_params.mColour.a = alpha;
      highlight_params.mXrayStrength = 0.0;
      highlight_params.mOutlineStrength = FLOAT_1_5;
      UFG::HighlightSimObject(v4, &highlight_params);
    }
    else
    {
      UFG::UnHighlightSimObject(v4);
    }
  }
}

// File Line: 140
// RVA: 0x400B80
void UFG::RadarSystem::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::RadarSystem *v1; // rcx
  UFG::allocator::free_link *v2; // [rsp+48h] [rbp+10h]
  UFG::allocator::free_link *v3; // [rsp+48h] [rbp+10h]
  UFG::allocator::free_link *v4; // [rsp+48h] [rbp+10h]
  UFG::allocator::free_link *v5; // [rsp+48h] [rbp+10h]

  v0 = UFG::qMalloc(0x58ui64, "RadarSystem", 0i64);
  v1 = (UFG::RadarSystem *)v0;
  if ( v0 )
  {
    LOWORD(v0->mNext) = 0;
    HIDWORD(v0->mNext) = 1;
    LODWORD(v0[1].mNext) = 1060320051;
    HIDWORD(v0[1].mNext) = 1106247680;
    v0[2].mNext = (UFG::allocator::free_link *)1094713344;
    v2 = v0 + 3;
    v2->mNext = v2;
    v2[1].mNext = v2;
    v3 = v0 + 5;
    v3->mNext = v3;
    v3[1].mNext = v3;
    v4 = v0 + 7;
    v4->mNext = v4;
    v4[1].mNext = v4;
    v5 = v0 + 9;
    v5->mNext = v5;
    v5[1].mNext = v5;
  }
  else
  {
    v1 = 0i64;
  }
  UFG::RadarSystem::sInstance = v1;
  UFG::RadarSystem::sRadarTypeColors[0] = (UFG::qColour)_xmm;
  xmmword_1423DC480 = _xmm;
  xmmword_1423DC490 = _xmm;
  xmmword_1423DC4A0 = (__int128)UFG::qColour::Red;
  xmmword_1423DC4B0 = *(_OWORD *)_xmm;
  xmmword_1423DC4C0 = (__int128)UFG::qColour::Green;
  xmmword_1423DC4D0 = _xmm;
  xmmword_1423DC4E0 = _xmm;
  xmmword_1423DC4F0 = _xmm;
}

// File Line: 161
// RVA: 0x400310
void UFG::RadarSystem::Destroy(void)
{
  UFG::RadarSystem *v0; // rbx

  v0 = UFG::RadarSystem::sInstance;
  if ( UFG::RadarSystem::sInstance )
  {
    UFG::RadarSystem::~RadarSystem(UFG::RadarSystem::sInstance);
    operator delete[](v0);
  }
  UFG::RadarSystem::sInstance = 0i64;
}

// File Line: 170
// RVA: 0x400CF0
UFG::RadarSystem *__fastcall UFG::RadarSystem::Instance()
{
  return UFG::RadarSystem::sInstance;
}

// File Line: 204
// RVA: 0x3FE190
void __fastcall UFG::RadarSystem::~RadarSystem(UFG::RadarSystem *this)
{
  UFG::RadarSystem *v1; // rdi
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v2; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v3; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v4; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v5; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v6; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v7; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v8; // rax
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v9; // rcx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v10; // rax

  v1 = this;
  v2 = &this->mPokerTiles;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mPokerTiles);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mCombatProps);
  v5 = v1->mCombatProps.mNode.mPrev;
  v6 = v1->mCombatProps.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mCombatProps.mNode.mPrev = &v1->mCombatProps.mNode;
  v1->mCombatProps.mNode.mNext = &v1->mCombatProps.mNode;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mRimLightObjects);
  v7 = v1->mRimLightObjects.mNode.mPrev;
  v8 = v1->mRimLightObjects.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mRimLightObjects.mNode.mPrev = &v1->mRimLightObjects.mNode;
  v1->mRimLightObjects.mNode.mNext = &v1->mRimLightObjects.mNode;
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(&v1->mElements);
  v9 = v1->mElements.mNode.mPrev;
  v10 = v1->mElements.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v1->mElements.mNode.mPrev = &v1->mElements.mNode;
  v1->mElements.mNode.mNext = &v1->mElements.mNode;
}

// File Line: 210
// RVA: 0x400170
void __fastcall UFG::RadarSystem::Clear(UFG::RadarSystem *this)
{
  UFG::RadarSystem *v1; // rbx

  v1 = this;
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(&this->mElements);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mRimLightObjects);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mCombatProps);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&v1->mPokerTiles);
}

// File Line: 235
// RVA: 0x4017B0
void __fastcall UFG::RadarSystem::SetInGrappleMode(UFG::RadarSystem *this, bool inGrapple)
{
  this->mGrappleModeActive = inGrapple;
}

// File Line: 250
// RVA: 0x3FE780
void __fastcall UFG::RadarSystem::AddRimLight(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbx
  UFG::RadarSystem *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rax
  UFG::allocator::free_link *v11; // [rsp+48h] [rbp+10h]

  v2 = object;
  v3 = this;
  v4 = UFG::qMalloc(0x28ui64, "SimObjectListEntry", 0x800ui64);
  v5 = v4;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v11 = v4 + 2;
    v11->mNext = v11;
    v11[1].mNext = v11;
    v4[4].mNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5[2];
  if ( v5[4].mNext )
  {
    v7 = v6->mPrev;
    v8 = v5[3].mNext;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v8;
    v8->mNext = (UFG::allocator::free_link *)v7;
    v6->mPrev = v6;
    v5[3].mNext = v5 + 2;
  }
  v5[4].mNext = (UFG::allocator::free_link *)v2;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = v6;
    v6->mPrev = v9;
    v5[3].mNext = (UFG::allocator::free_link *)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = v6;
  }
  v10 = v3->mRimLightObjects.mNode.mPrev;
  v10->mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v5;
  v5->mNext = (UFG::allocator::free_link *)v10;
  v5[1].mNext = (UFG::allocator::free_link *)&v3->mRimLightObjects;
  v3->mRimLightObjects.mNode.mPrev = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v5;
}

// File Line: 260
// RVA: 0x401050
void __fastcall UFG::RadarSystem::RemoveRimLight(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v2; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v3; // rsi
  UFG::SimObject *v4; // rbp
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v5; // rdi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax

  v2 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)this->mRimLightObjects.mNode.mNext;
  v3 = &this->mRimLightObjects;
  v4 = object;
  if ( v2 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)&this->mRimLightObjects )
  {
    do
    {
      if ( v4 == (UFG::SimObject *)v2->mValue.m_pPointer )
      {
        v5 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v2->mPrev;
        v6 = v2->mNext;
        v5->mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v5->mPrev;
        v2->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v2->mPrev;
        UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry(v2);
        operator delete[](v2);
        v2 = v5;
      }
      v2 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v2->mNext;
    }
    while ( v2 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v3 );
  }
}

// File Line: 277
// RVA: 0x3FE6C0
void __fastcall UFG::RadarSystem::AddCombatProp(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbx
  UFG::RadarSystem *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::allocator::free_link *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rax
  UFG::allocator::free_link *v11; // [rsp+48h] [rbp+10h]

  v2 = object;
  v3 = this;
  v4 = UFG::qMalloc(0x28ui64, "SimObjectListEntry", 0x800ui64);
  v5 = v4;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v11 = v4 + 2;
    v11->mNext = v11;
    v11[1].mNext = v11;
    v4[4].mNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5[2];
  if ( v5[4].mNext )
  {
    v7 = v6->mPrev;
    v8 = v5[3].mNext;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v8;
    v8->mNext = (UFG::allocator::free_link *)v7;
    v6->mPrev = v6;
    v5[3].mNext = v5 + 2;
  }
  v5[4].mNext = (UFG::allocator::free_link *)v2;
  if ( v2 )
  {
    v9 = v2->m_SafePointerList.mNode.mPrev;
    v9->mNext = v6;
    v6->mPrev = v9;
    v5[3].mNext = (UFG::allocator::free_link *)&v2->m_SafePointerList;
    v2->m_SafePointerList.mNode.mPrev = v6;
  }
  v10 = v3->mCombatProps.mNode.mPrev;
  v10->mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v5;
  v5->mNext = (UFG::allocator::free_link *)v10;
  v5[1].mNext = (UFG::allocator::free_link *)&v3->mCombatProps;
  v3->mCombatProps.mNode.mPrev = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v5;
}

// File Line: 286
// RVA: 0x400FE0
void __fastcall UFG::RadarSystem::RemoveCombatProp(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v2; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v3; // rsi
  UFG::SimObject *v4; // rbp
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v5; // rdi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax

  v2 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)this->mCombatProps.mNode.mNext;
  v3 = &this->mCombatProps;
  v4 = object;
  if ( v2 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)&this->mCombatProps )
  {
    do
    {
      if ( v4 == (UFG::SimObject *)v2->mValue.m_pPointer )
      {
        v5 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v2->mPrev;
        v6 = v2->mNext;
        v5->mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v5->mPrev;
        v2->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v2->mPrev;
        UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry(v2);
        operator delete[](v2);
        v2 = v5;
      }
      v2 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v2->mNext;
    }
    while ( v2 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v3 );
  }
}

// File Line: 310
// RVA: 0x401C40
void __fastcall UFG::RadarSystem::Update(UFG::RadarSystem *this, float deltaTime)
{
  float v2; // xmm1_4
  UFG::RadarSystem *v3; // rsi
  bool v4; // cf
  bool v5; // zf
  float v6; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm10_4
  UFG::SimObjectCharacter *v9; // rax
  float *v10; // rbx
  float v11; // xmm9_4
  UFG::BaseCameraComponent *v12; // rax
  UFG::BaseCameraComponent *v13; // rcx
  UFG::Camera *v14; // rbp
  UFG::BaseCameraComponent *v15; // rcx
  _DWORD *v16; // rcx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  UFG::qVector3 *v20; // rax
  UFG::RadarElement *v21; // rdi
  float v22; // xmm14_4
  float i; // xmm15_4
  __m128 v24; // xmm2
  __int64 v25; // rax
  __int64 v26; // rbx
  float v27; // xmm3_4
  float v28; // xmm6_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  UFG::qVector3 *v32; // rax
  __m128 v33; // xmm1
  float v34; // xmm2_4
  Render::DebugDrawContext *v35; // rax
  Render::DebugDrawContext *v36; // rdi
  float v37; // xmm3_4
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v38; // rbx
  signed __int64 j; // rsi
  UFG::qVector3 world_pos; // [rsp+40h] [rbp-F8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-E8h]
  UFG::qVector2 viewport_scale; // [rsp+140h] [rbp+8h]
  bool is_on_screen; // [rsp+148h] [rbp+10h]

  v2 = deltaTime + this->mPulseCurrentDuration;
  v3 = this;
  v4 = v2 < this->mPulseDuration;
  v5 = v2 == this->mPulseDuration;
  this->mPulseCurrentDuration = v2;
  if ( !v4 && !v5 )
  {
    v5 = this->mPingType == 2;
    this->mPulseCurrentDuration = 0.0;
    if ( v5 )
      this->mPingType = 1;
  }
  UFG::RadarSystem::DeterminePingMode(this);
  UFG::RadarSystem::RefreshRadarList(v3);
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = UFG::GetLocalPlayer();
  if ( v9 )
  {
    v10 = (float *)v9->m_pTransformNodeComponent;
    if ( v10 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
      v6 = v10[44];
      v7 = v10[45];
      v8 = v10[46];
    }
  }
  v11 = (float)(v3->mPulseCurrentDuration / v3->mPulseDuration) * v3->mPulseMaxRadius;
  v12 = UFG::Director::Get()->mCurrentCamera;
  if ( v12 && v12 != (UFG::BaseCameraComponent *)-80i64 )
  {
    is_on_screen = 0;
    v13 = UFG::Director::Get()->mCurrentCamera;
    v14 = &v13->mCamera;
    if ( !v13 )
      v14 = 0i64;
    v15 = UFG::Director::Get()->mCurrentCamera;
    if ( v15 )
      v16 = (_DWORD *)&v15->mCamera.mFOVOffset;
    else
      v16 = 0i64;
    v17 = (float)(COERCE_FLOAT(v16[42] ^ _xmm[0]) * 10.0) + v14->mTransformation.v3.z;
    v18 = (float)(COERCE_FLOAT(v16[41] ^ _xmm[0]) * 10.0) + v14->mTransformation.v3.y;
    v19 = (float)(COERCE_FLOAT(v16[40] ^ _xmm[0]) * 10.0) + v14->mTransformation.v3.x;
    viewport_scale.x = 1.0;
    viewport_scale.y = 1.0;
    world_pos.x = v19;
    world_pos.y = v18;
    world_pos.z = v17;
    v20 = UFG::Camera::GetScreenCoord(v14, &result, &world_pos, &viewport_scale, &is_on_screen);
    v21 = (UFG::RadarElement *)v3->mElements.mNode.mNext;
    v22 = v20->x;
    for ( i = v20->y; v21 != (UFG::RadarElement *)&v3->mElements; v21 = (UFG::RadarElement *)v21->mNext )
    {
      v24 = (__m128)LODWORD(v21->mPosition.y);
      v25 = v21->mType;
      v26 = v25;
      v24.m128_f32[0] = (float)((float)((float)(v24.m128_f32[0] - v7) * (float)(v24.m128_f32[0] - v7))
                              + (float)((float)(v21->mPosition.x - v6) * (float)(v21->mPosition.x - v6)))
                      + (float)((float)(v21->mPosition.z - v8) * (float)(v21->mPosition.z - v8));
      LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v24);
      v28 = 1.0 - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v27 - v11) & _xmm) / v3->mPulseActiveRange);
      if ( v28 <= 0.0 )
      {
        v28 = 0.0;
      }
      else if ( v28 >= 1.0 )
      {
        v28 = *(float *)&FLOAT_1_0;
      }
      if ( UFG::RadarSystem::sRevealParams[v25].mUseDistanceScalar )
      {
        v29 = UFG::RadarSystem::sRevealParams[v25].mPulseFadeMinDist;
        v30 = v27 - v29;
        if ( v30 <= 0.0 )
          v30 = 0.0;
        v31 = 1.0 - (float)(v30 / (float)(UFG::RadarSystem::sRevealParams[v25].mPulseFadeMaxDist - v29));
        if ( v31 <= 0.0 )
        {
          v31 = 0.0;
        }
        else if ( v31 >= 1.0 )
        {
          v31 = *(float *)&FLOAT_1_0;
        }
        v28 = v31 * v28;
      }
      if ( UFG::RadarSystem::sRevealParams[v25].mUseScreenSpaceScalar )
      {
        v32 = UFG::Camera::GetScreenCoord(v14, &result, &v21->mPosition, &viewport_scale, &is_on_screen);
        v33 = (__m128)LODWORD(v32->y);
        v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] - i) * (float)(v33.m128_f32[0] - i))
                        + (float)((float)(v32->x - v22) * (float)(v32->x - v22));
        v34 = 1.0
            - (float)(COERCE_FLOAT(_mm_sqrt_ps(v33)) / UFG::RadarSystem::sRevealParams[v26].mScreenSpaceRevealRadius);
        if ( v34 <= 0.0 )
        {
          v34 = 0.0;
        }
        else if ( v34 >= 1.0 )
        {
          v34 = *(float *)&FLOAT_1_0;
        }
        v28 = v28 * v34;
      }
      if ( UFG::RadarSystem::sRevealParams[v26].mAlwaysOn )
        v28 = UFG::RadarSystem::sRadarTypeColors[v21->mType].a;
      UFG::RadarElement::Highlight(v21, v28 >= 0.0, v28);
    }
  }
  if ( UFG::RadarSystem::sDebugRender )
  {
    world_pos.x = v6;
    world_pos.y = v7;
    world_pos.z = v8 + 0.5;
    v35 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v36 = v35;
    v37 = v11 - v3->mPulseActiveRange;
    if ( v37 <= 0.0 )
      v37 = 0.0;
    Render::DebugDrawContext::DrawCircle(
      v35,
      &world_pos,
      &UFG::qVector3::msDirUp,
      v37,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64);
    Render::DebugDrawContext::DrawCircle(
      v36,
      &world_pos,
      &UFG::qVector3::msDirUp,
      v11,
      &UFG::qColour::Green,
      &UFG::qMatrix44::msIdentity,
      0i64);
    Render::DebugDrawContext::DrawCircle(
      v36,
      &world_pos,
      &UFG::qVector3::msDirUp,
      v11 + v3->mPulseActiveRange,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64);
    v38 = v3->mElements.mNode.mNext;
    for ( j = (signed __int64)&v3->mElements; v38 != (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)j; v38 = v38->mNext )
      Render::DebugDrawContext::DrawPoint(
        v36,
        (UFG::qVector3 *)((char *)&v38[1].mPrev + 4),
        &UFG::RadarSystem::sRadarTypeColors[SLODWORD(v38[1].mPrev)],
        &UFG::qMatrix44::msIdentity,
        0i64);
  }
}

// File Line: 393
// RVA: 0x400350
void __fastcall UFG::RadarSystem::DeterminePingMode(UFG::RadarSystem *this)
{
  UFG::RadarSystem *v1; // rdi
  signed int v2; // ebx
  UFG::SimObjectCharacter *v3; // rax
  UFG::SimObjectCVBase *v4; // rsi
  int v5; // ebp
  UFG::AICharacterControllerComponent *v6; // rax
  UFG::InputActionData *v7; // rcx
  UFG::TargetingSystemPedPlayerComponent *v8; // rax
  UFG::eFocusModeEnum v9; // edx
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimObjectCharacterPropertiesComponent *v12; // rax

  v1 = this;
  if ( !UFG::RadarSystem::sDebugOverridePingType && this->mPingType != 2 )
  {
    if ( NISManager::GetInstance()->mState )
    {
      v1->mPingType = 0;
    }
    else
    {
      v2 = 1;
      v3 = UFG::GetLocalPlayer();
      v4 = (UFG::SimObjectCVBase *)&v3->vfptr;
      if ( v3 )
      {
        v5 = 0;
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>((UFG::SimObjectCVBase *)&v3->vfptr);
        if ( v6 )
          v5 = v6->m_ControllerID;
        v7 = UFG::ActionDef_Freerun.mDataPerController[v5];
        if ( v7 && v7->mActionTrue )
          v2 = 5;
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v4);
        if ( v8 )
        {
          if ( v8->m_bIsAimingActive )
          {
            v9 = v8->m_eFocusMode;
            if ( (unsigned int)(v9 - 1) <= 1 || (unsigned int)(v9 - 3) <= 1 )
              v2 = 4;
          }
          if ( v1->mGrappleModeActive )
          {
            v10 = (UFG::SimObjectCVBase *)v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[23]].m_pTarget.m_pPointer;
            if ( v10 )
            {
              v11 = v10->m_Flags;
              if ( (v11 >> 14) & 1 )
              {
                v12 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v10);
              }
              else if ( (v11 & 0x8000u) == 0 )
              {
                if ( (v11 >> 13) & 1 )
                  v12 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        (UFG::SimObjectGame *)&v10->vfptr,
                                                                        UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
                else
                  v12 = (UFG::SimObjectCharacterPropertiesComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                           (UFG::SimObjectGame *)&v10->vfptr,
                                                                                           UFG::SimObjectCharacterPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::SimObjectCharacterPropertiesComponent::_TypeUID));
              }
              else
              {
                v12 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(v10);
              }
              if ( v12 && (LOBYTE(v12->mBooleans.mBits[0]) >> 2) & 1 )
                v2 = 6;
            }
          }
        }
        if ( v1->mbPokerDiceMode )
          v2 = 3;
      }
      if ( v1->mPingType != v2 )
      {
        v1->mPingType = v2;
        v1->mPulseCurrentDuration = 0.0;
      }
    }
  }
}

// File Line: 471
// RVA: 0x4015C0
void __fastcall UFG::RadarSystem::ScanPokerTileLights(UFG::RadarSystem *this)
{
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v1; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v2; // rsi
  UFG::RadarSystem *v3; // rbp
  UFG::SimObject *v4; // rdx
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *v5; // rdi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax

  v1 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)this->mPokerTiles.mNode.mNext;
  v2 = &this->mPokerTiles;
  v3 = this;
  if ( v1 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)&this->mPokerTiles )
  {
    do
    {
      v4 = (UFG::SimObject *)v1->mValue.m_pPointer;
      if ( v4 )
      {
        UFG::RadarSystem::AddSimObject(v3, v4, Low|Critical);
      }
      else
      {
        v5 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v1->mPrev;
        v6 = v1->mNext;
        v5->mNext = v6;
        v6->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v5->mPrev;
        v1->mPrev = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v1->mPrev;
        v1->mNext = (UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *)&v1->mPrev;
        UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry(v1);
        operator delete[](v1);
        v1 = v5;
      }
      v1 = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v1->mNext;
    }
    while ( v1 != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v2 );
  }
}

// File Line: 492
// RVA: 0x401650
void __fastcall UFG::RadarSystem::ScanRimLights(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v1; // rdi
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v2; // rsi
  UFG::RadarSystem *v3; // rbp
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RadarComponent *v6; // rax
  unsigned int v7; // ecx
  UFG::RadarType::Enum v8; // er8
  UFG::RadarSystem::ElementRevealParams *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v11; // rax

  v1 = this->mRimLightObjects.mNode.mNext;
  v2 = &this->mRimLightObjects;
  v3 = this;
  if ( v1 != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)&this->mRimLightObjects )
  {
    do
    {
      v4 = (UFG::SimObjectGame *)v1[2].mPrev;
      if ( v4 )
      {
        v5 = v4->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v6 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
          }
          else if ( (v5 >> 12) & 1 )
          {
            v6 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
          }
          else
          {
            v6 = (UFG::RadarComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::RadarComponent::_TypeUID);
          }
        }
        else
        {
          v6 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
        }
        if ( v6 )
        {
          v7 = v6->mRadarHighlightType.mUID;
          v8 = 0;
          v9 = UFG::RadarSystem::sRevealParams;
          while ( v9->mTypeSymbol.mUID != v7 )
          {
            ++v8;
            ++v9;
            if ( (unsigned int)v8 >= 9 )
            {
              UFG::RadarSystem::AddSimObject(v3, (UFG::SimObject *)v1[2].mPrev, 0);
              goto LABEL_21;
            }
          }
        }
        else
        {
          v8 = 0;
          if ( (WORD2(v1[2].mPrev[4].mNext) >> 14) & 1 )
            v8 = 8;
        }
        UFG::RadarSystem::AddSimObject(v3, (UFG::SimObject *)v1[2].mPrev, v8);
      }
      else
      {
        v10 = v1->mPrev;
        v11 = v1->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v1->mPrev = v1;
        v1->mNext = v1;
        UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v1);
        operator delete[](v1);
        v1 = v10;
      }
LABEL_21:
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v2 );
  }
}

// File Line: 522
// RVA: 0x401200
void __fastcall UFG::RadarSystem::ScanCombatProps(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v1; // rdi
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *v2; // rsi
  UFG::RadarSystem *v3; // rbp
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RadarType::Enum v6; // ebx
  UFG::RadarComponent *v7; // rax
  unsigned int v8; // ecx
  UFG::RadarSystem::ElementRevealParams *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v11; // rax

  v1 = this->mCombatProps.mNode.mNext;
  v2 = &this->mCombatProps;
  v3 = this;
  if ( v1 != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)&this->mCombatProps )
  {
    do
    {
      v4 = (UFG::SimObjectGame *)v1[2].mPrev;
      if ( v4 )
      {
        v5 = v4->m_Flags;
        v6 = 2;
        if ( (v5 >> 14) & 1 )
        {
          v7 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
          {
            v7 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
          }
          else if ( (v5 >> 12) & 1 )
          {
            v7 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
          }
          else
          {
            v7 = (UFG::RadarComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::RadarComponent::_TypeUID);
          }
        }
        else
        {
          v7 = (UFG::RadarComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RadarComponent::_TypeUID);
        }
        if ( v7 )
        {
          v8 = v7->mRadarHighlightType.mUID;
          v6 = 0;
          v9 = UFG::RadarSystem::sRevealParams;
          while ( v9->mTypeSymbol.mUID != v8 )
          {
            ++v6;
            ++v9;
            if ( (unsigned int)v6 >= 9 )
            {
              v6 = 0;
              break;
            }
          }
        }
        UFG::RadarSystem::AddSimObject(v3, (UFG::SimObject *)v1[2].mPrev, v6);
      }
      else
      {
        v10 = v1->mPrev;
        v11 = v1->mNext;
        v10->mNext = v11;
        v11->mPrev = v10;
        v1->mPrev = v1;
        v1->mNext = v1;
        UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)v1);
        operator delete[](v1);
        v1 = v10;
      }
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v2 );
  }
}

// File Line: 548
// RVA: 0x401340
void __fastcall UFG::RadarSystem::ScanForExploadables(UFG::RadarSystem *this)
{
  UFG::RadarSystem *v1; // r14
  UFG::RigidBody *v2; // rbx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v4; // rcx
  const char *v5; // rax
  UFG::CollisionMeshData *v6; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax
  double v8; // xmm0_8
  float v9; // xmm1_4
  UFG::BaseCameraComponent *v10; // rcx
  UFG::Camera *v11; // rcx
  UFG::SimObject *v12; // rdi
  UFG::SimComponent *v13; // rax
  signed __int64 v14; // rbx
  bool v15; // al
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  UFG::allocator::free_link *v18; // ST38_8
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v21; // rax
  UFG::qVector3 result; // [rsp+40h] [rbp-98h]
  UFG::qVector3 v23; // [rsp+50h] [rbp-88h]
  UFG::qReflectHandleBase v24; // [rsp+60h] [rbp-78h]
  bool is_on_screen; // [rsp+E8h] [rbp+10h]
  UFG::qVector2 viewport_scale; // [rsp+F0h] [rbp+18h]
  UFG::allocator::free_link *v27; // [rsp+F8h] [rbp+20h]

  v1 = this;
  v2 = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v2[1].m_SafePointerList.mNode.mPrev[-18].mNext;
      UFG::qReflectHandleBase::qReflectHandleBase(&v24);
      v5 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v4);
      v24.mTypeUID = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
      v6 = v2->mCollisionMeshData;
      if ( v6 )
        UFG::qReflectHandleBase::operator=(&v24, (UFG::qReflectHandleBase *)&v6->mObjectProperties.mPrev);
      v7 = v2[1].mCollisionMeshBundle.mPrev;
      if ( v7 )
        v8 = *((float *)&v7[16].mNext + 1);
      else
        v8 = DOUBLE_1_0;
      if ( v24.mData )
      {
        if ( LODWORD(v24.mData[2].mBaseNode.mNeighbours[1]) == 1 )
        {
          v9 = v8;
          if ( v9 > 0.0 )
          {
            UFG::RigidBody::GetCentreOfMass(v2, &result);
            viewport_scale.x = 1.0;
            viewport_scale.y = 1.0;
            is_on_screen = 0;
            v10 = UFG::Director::Get()->mCurrentCamera;
            v11 = v10 ? &v10->mCamera : 0i64;
            UFG::Camera::GetScreenCoord(v11, &v23, &result, &viewport_scale, &is_on_screen);
            if ( is_on_screen )
            {
              v12 = v2->m_pSimObject;
              if ( v12 )
              {
                v13 = UFG::SimObject::GetComponentOfType(v2->m_pSimObject, UFG::DynamicSceneryInstance::_TypeUID);
                v14 = (signed __int64)&v13[-1].m_pSimObject;
                if ( !v13 )
                  v14 = 0i64;
                v15 = UFG::IsHighlightSimObject(v12);
                if ( v14 && !v15 )
                {
                  v16 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
                  v17 = v16;
                  v27 = v16;
                  if ( v16 )
                  {
                    v16->mNext = v16;
                    v16[1].mNext = v16;
                    LODWORD(v16[2].mNext) = 2;
                    v18 = v16 + 4;
                    v18->mNext = v18;
                    v18[1].mNext = v18;
                    v16[6].mNext = 0i64;
                  }
                  else
                  {
                    v17 = 0i64;
                  }
                  LODWORD(v17[2].mNext) = 3;
                  v19 = result.y;
                  v20 = result.z;
                  HIDWORD(v17[2].mNext) = LODWORD(result.x);
                  *(float *)&v17[3].mNext = v19;
                  *((float *)&v17[3].mNext + 1) = v20;
                  UFG::qSafePointer<Creature,Creature>::operator=(
                    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v17[4],
                    (UFG::SimComponent *)v12);
                  v21 = v1->mElements.mNode.mPrev;
                  v21->mNext = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v17;
                  v17->mNext = (UFG::allocator::free_link *)v21;
                  v17[1].mNext = (UFG::allocator::free_link *)&v1->mElements;
                  v1->mElements.mNode.mPrev = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v17;
                }
              }
            }
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v24);
      v2 = (UFG::RigidBody *)v3;
    }
    while ( v3 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
}

// File Line: 615
// RVA: 0x400EB0
void __fastcall UFG::RadarSystem::RefreshRadarList(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v1; // rbx
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0> *v2; // rsi
  UFG::RadarSystem *v3; // rdi
  UFG::SimObject *v4; // rcx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v5; // r8
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v6; // rdx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v7; // rax

  v1 = this->mElements.mNode.mNext;
  v2 = &this->mElements;
  v3 = this;
  if ( v1 != (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)&this->mElements )
  {
    do
    {
      v4 = (UFG::SimObject *)v1[3].mPrev;
      if ( v4 )
      {
        UFG::UnHighlightSimObject(v4);
        v5 = v1 + 2;
        if ( v1[3].mPrev )
        {
          v6 = v5->mPrev;
          v7 = v1[2].mNext;
          v6->mNext = v7;
          v7->mPrev = v6;
          v5->mPrev = v5;
          v1[2].mNext = v1 + 2;
        }
        v1[3].mPrev = 0i64;
      }
      v1 = v1->mNext;
    }
    while ( v1 != (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v2 );
  }
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(v2);
  if ( !UFG::RadarSystem::sDisableRadarSystem )
  {
    switch ( v3->mPingType )
    {
      case 1:
      case 5:
        UFG::RadarSystem::ScanRimLights(v3);
        break;
      case 2:
        UFG::RadarSystem::ScanRimLights(v3);
        UFG::RadarSystem::ScanCombatProps(v3);
        UFG::RadarSystem::ScanForExploadables(v3);
        break;
      case 3:
        UFG::RadarSystem::ScanPokerTileLights(v3);
        break;
      case 4:
        UFG::RadarSystem::ScanRimLights(v3);
        UFG::RadarSystem::ScanForExploadables(v3);
        break;
      case 6:
        UFG::RadarSystem::ScanRimLights(v3);
        UFG::RadarSystem::ScanCombatProps(v3);
        break;
      default:
        return;
    }
  }
}

// File Line: 674
// RVA: 0x3FE840
void __fastcall UFG::RadarSystem::AddSimObject(UFG::RadarSystem *this, UFG::SimObject *object, UFG::RadarType::Enum type)
{
  UFG::RadarType::Enum v3; // er12
  UFG::SimObjectGame *v4; // rdi
  UFG::RadarSystem *v5; // r15
  UFG::TransformNodeComponent *v6; // r14
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rbp
  UFG::SimComponent *v9; // rax
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  signed __int64 v12; // rbx
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  UFG::RigidBody *v15; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v16; // rcx
  const char *v17; // rax
  UFG::CollisionMeshData *v18; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v19; // rax
  double v20; // xmm0_8
  float v21; // xmm1_4
  UFG::Camera *v22; // rcx
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rbx
  UFG::allocator::free_link *v25; // rcx
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::SimObject *v28; // rax
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm8_4
  UFG::allocator::free_link *v32; // rax
  UFG::allocator::free_link *v33; // rcx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v34; // rax
  UFG::qVector3 v35; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-98h]
  UFG::qReflectHandleBase v37; // [rsp+60h] [rbp-88h]
  bool is_on_screen; // [rsp+F8h] [rbp+10h]
  UFG::qVector2 viewport_scale; // [rsp+108h] [rbp+20h]

  if ( object )
  {
    v3 = type;
    v4 = (UFG::SimObjectGame *)object;
    v5 = this;
    v6 = object->m_pTransformNodeComponent;
    v7 = object->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v4->m_Components.p[14].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v8 = v4->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v7 >> 12) & 1 )
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v9 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::CompositeDrawableComponent::_TypeUID);
        v8 = v9;
      }
    }
    else
    {
      v8 = v4->m_Components.p[14].m_pComponent;
    }
    v10 = v4->m_Flags;
    if ( (v10 >> 14) & 1 )
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::DynamicSceneryInstance::_TypeUID);
    }
    else if ( (v10 & 0x8000u) == 0 )
    {
      if ( (v10 >> 13) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::DynamicSceneryInstance::_TypeUID);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::DynamicSceneryInstance::_TypeUID);
      }
      else
      {
        v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::DynamicSceneryInstance::_TypeUID);
      }
    }
    else
    {
      v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::DynamicSceneryInstance::_TypeUID);
    }
    if ( v11 )
      v12 = (signed __int64)&v11[-1].m_pSimObject;
    else
      v12 = 0i64;
    v13 = v4->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v13 >> 12) & 1 )
      {
        v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RigidBodyComponent::_TypeUID);
    }
    v15 = (UFG::RigidBody *)v14;
    if ( v14 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v37);
      v17 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v16);
      v37.mTypeUID = UFG::qStringHash64(v17, 0xFFFFFFFFFFFFFFFFui64);
      v18 = v15->mCollisionMeshData;
      if ( v18 )
        UFG::qReflectHandleBase::operator=(&v37, (UFG::qReflectHandleBase *)&v18->mObjectProperties.mPrev);
      v19 = v15[1].mCollisionMeshBundle.mPrev;
      if ( v19 )
        v20 = *((float *)&v19[16].mNext + 1);
      else
        v20 = DOUBLE_1_0;
      if ( v37.mData )
      {
        v21 = v20;
        if ( v21 <= 0.0 )
        {
          UFG::qReflectHandleBase::~qReflectHandleBase(&v37);
          return;
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v37);
    }
    if ( v12 && v15 )
    {
      UFG::RigidBody::GetCentreOfMass(v15, &result);
      viewport_scale.x = 1.0;
      viewport_scale.y = 1.0;
      is_on_screen = 0;
      v22 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
      if ( v22 )
        v22 = (UFG::Camera *)((char *)v22 + 80);
      UFG::Camera::GetScreenCoord(v22, &v35, &result, &viewport_scale, &is_on_screen);
      if ( is_on_screen )
      {
        v23 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
        v24 = v23;
        if ( v23 )
        {
          v23->mNext = v23;
          v23[1].mNext = v23;
          LODWORD(v23[2].mNext) = 2;
          v25 = v23 + 4;
          *(_QWORD *)&v35.x = v25;
          v25->mNext = v25;
          v25[1].mNext = v25;
          v23[6].mNext = 0i64;
        }
        else
        {
          v24 = 0i64;
        }
        LODWORD(v24[2].mNext) = 3;
        v26 = result.y;
        v27 = result.z;
        HIDWORD(v24[2].mNext) = LODWORD(result.x);
        *(float *)&v24[3].mNext = v26;
        *((float *)&v24[3].mNext + 1) = v27;
LABEL_60:
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v24[4],
          (UFG::SimComponent *)v4);
        v34 = v5->mElements.mNode.mPrev;
        v34->mNext = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v24;
        v24->mNext = (UFG::allocator::free_link *)v34;
        v24[1].mNext = (UFG::allocator::free_link *)&v5->mElements;
        v5->mElements.mNode.mPrev = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v24;
        return;
      }
    }
    else if ( v6 )
    {
      if ( v8 )
      {
        v28 = v8[19].m_pSimObject;
        if ( v28 )
        {
          if ( LOBYTE(v28->vfptr) <= 1u )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(v6);
            v29 = v6->mWorldTransform.v3.x;
            v30 = v6->mWorldTransform.v3.y;
            v31 = v6->mWorldTransform.v3.z;
            v32 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
            v24 = v32;
            *(_QWORD *)&is_on_screen = v32;
            if ( v32 )
            {
              v32->mNext = v32;
              v32[1].mNext = v32;
              LODWORD(v32[2].mNext) = 2;
              v33 = v32 + 4;
              viewport_scale = (UFG::qVector2)v33;
              v33->mNext = v33;
              v33[1].mNext = v33;
              v32[6].mNext = 0i64;
            }
            else
            {
              v24 = 0i64;
            }
            LODWORD(v24[2].mNext) = v3;
            *((float *)&v24[2].mNext + 1) = v29;
            *(float *)&v24[3].mNext = v30;
            *((float *)&v24[3].mNext + 1) = v31;
            goto LABEL_60;
          }
        }
      }
    }
  }
}

