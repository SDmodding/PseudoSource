// File Line: 44
// RVA: 0x14E76F0
void dynamic_initializer_for__UFG::RadarSystem::sRevealParams__()
{
  UFG::qSymbol::create_from_string(&UFG::RadarSystem::sRevealParams[0].mTypeSymbol, "RimLight");
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
  JUMPOUT(0x1414E7934i64);
}

// File Line: 76
// RVA: 0x14E7970
__int64 dynamic_initializer_for__UFG::RadarComponent::s_RadarComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RadarComponent::s_RadarComponentList__);
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
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *mPrev; // rax
  UFG::SimObjectModifier v5; // [rsp+28h] [rbp-30h] BYREF

  UFG::SimComponent::SimComponent(this, 0);
  this->mPrev = &this->UFG::qNode<UFG::RadarComponent,UFG::RadarComponent>;
  this->mNext = &this->UFG::qNode<UFG::RadarComponent,UFG::RadarComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RadarComponent::`vftable;
  this->mRadarHighlightType = UFG::gNullQSymbol;
  mPrev = UFG::RadarComponent::s_RadarComponentList.mNode.mPrev;
  UFG::RadarComponent::s_RadarComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RadarComponent,UFG::RadarComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *)&UFG::RadarComponent::s_RadarComponentList;
  UFG::RadarComponent::s_RadarComponentList.mNode.mPrev = &this->UFG::qNode<UFG::RadarComponent,UFG::RadarComponent>;
  UFG::SimComponent::AddType(this, UFG::RadarComponent::_RadarComponentTypeUID, "RadarComponent");
  this->mRadarHighlightType.mUID = PropertyUtils::Get<UFG::qSymbol>(
                                     pSceneObj,
                                     (UFG::qArray<unsigned long,0> *)&sHighlightType)->mFlags;
  UFG::SimObjectModifier::SimObjectModifier(&v5, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v5, this, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v5);
  UFG::SimObjectModifier::~SimObjectModifier(&v5);
}

// File Line: 94
// RVA: 0x3FE110
void __fastcall UFG::RadarComponent::~RadarComponent(UFG::RadarComponent *this)
{
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v2; // rdx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *mPrev; // rcx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *mNext; // rax
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v5; // rcx
  UFG::qNode<UFG::RadarComponent,UFG::RadarComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RadarComponent::`vftable;
  if ( this == UFG::RadarComponent::s_RadarComponentpCurrentIterator )
    UFG::RadarComponent::s_RadarComponentpCurrentIterator = (UFG::RadarComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::RadarComponent,UFG::RadarComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 101
// RVA: 0x400AD0
bool __fastcall UFG::RadarComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentRadar);
}

// File Line: 108
// RVA: 0x400E50
void __fastcall UFG::RadarComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "RadarComponent", 0i64, 1u);
  if ( v3 )
    UFG::RadarComponent::RadarComponent((UFG::RadarComponent *)v3, pSceneObj);
}

// File Line: 114
// RVA: 0x14E8DE0
__int64 UFG::_dynamic_initializer_for__sHighlightType__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RadarHighlightType", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sHighlightType, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sHighlightType__);
}

// File Line: 124
// RVA: 0x400AE0
void __fastcall UFG::RadarElement::Highlight(UFG::RadarElement *this, bool enable, float alpha)
{
  UFG::SimObject *m_pPointer; // rcx
  __int64 mType; // rax
  float r; // xmm1_4
  float g; // xmm3_4
  float b; // xmm4_4
  UFG::HighlightParams highlight_params; // [rsp+20h] [rbp-28h] BYREF

  m_pPointer = this->mDrawable.m_pPointer;
  if ( m_pPointer )
  {
    mType = this->mType;
    r = UFG::RadarSystem::sRadarTypeColors[mType].r;
    g = UFG::RadarSystem::sRadarTypeColors[mType].g;
    b = UFG::RadarSystem::sRadarTypeColors[mType].b;
    highlight_params.mColour.a = UFG::RadarSystem::sRadarTypeColors[mType].a;
    if ( enable )
    {
      highlight_params.mColour.r = r;
      highlight_params.mIsDepthEnabled = 1;
      highlight_params.mColour.g = g;
      highlight_params.mColour.b = b;
      highlight_params.mColour.a = alpha;
      highlight_params.mXrayStrength = 0.0;
      highlight_params.mOutlineStrength = FLOAT_1_5;
      UFG::HighlightSimObject(m_pPointer, &highlight_params);
    }
    else
    {
      UFG::UnHighlightSimObject(m_pPointer);
    }
  }
}

// File Line: 140
// RVA: 0x400B80
void UFG::RadarSystem::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::RadarSystem *v1; // rcx

  v0 = UFG::qMalloc(0x58ui64, "RadarSystem", 0i64);
  v1 = (UFG::RadarSystem *)v0;
  if ( v0 )
  {
    LOWORD(v0->mNext) = 0;
    HIDWORD(v0->mNext) = 1;
    LODWORD(v0[1].mNext) = 1060320051;
    HIDWORD(v0[1].mNext) = 1106247680;
    v0[2].mNext = (UFG::allocator::free_link *)1094713344;
    v0[3].mNext = v0 + 3;
    v0[4].mNext = v0 + 3;
    v0[5].mNext = v0 + 5;
    v0[6].mNext = v0 + 5;
    v0[7].mNext = v0 + 7;
    v0[8].mNext = v0 + 7;
    v0[9].mNext = v0 + 9;
    v0[10].mNext = v0 + 9;
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
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *p_mPokerTiles; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mPrev; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v5; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v6; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v7; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v8; // rax
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v9; // rcx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v10; // rax

  p_mPokerTiles = &this->mPokerTiles;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mPokerTiles);
  mPrev = p_mPokerTiles->mNode.mPrev;
  mNext = p_mPokerTiles->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mPokerTiles->mNode.mPrev = &p_mPokerTiles->mNode;
  p_mPokerTiles->mNode.mNext = &p_mPokerTiles->mNode;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mCombatProps);
  v5 = this->mCombatProps.mNode.mPrev;
  v6 = this->mCombatProps.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mCombatProps.mNode.mPrev = &this->mCombatProps.mNode;
  this->mCombatProps.mNode.mNext = &this->mCombatProps.mNode;
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mRimLightObjects);
  v7 = this->mRimLightObjects.mNode.mPrev;
  v8 = this->mRimLightObjects.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mRimLightObjects.mNode.mPrev = &this->mRimLightObjects.mNode;
  this->mRimLightObjects.mNode.mNext = &this->mRimLightObjects.mNode;
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(&this->mElements);
  v9 = this->mElements.mNode.mPrev;
  v10 = this->mElements.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mElements.mNode.mPrev = &this->mElements.mNode;
  this->mElements.mNode.mNext = &this->mElements.mNode;
}

// File Line: 210
// RVA: 0x400170
void __fastcall UFG::RadarSystem::Clear(UFG::RadarSystem *this)
{
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(&this->mElements);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mRimLightObjects);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mCombatProps);
  UFG::qList<UFG::BoostRegionTracker,UFG::BoostRegionTracker,1,0>::DeleteNodes((UFG::qList<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,1,0> *)&this->mPokerTiles);
}

// File Line: 235
// RVA: 0x4017B0
void __fastcall UFG::RadarSystem::SetInGrappleMode(UFG::RadarSystem *this, bool inGrapple)
{
  this->mGrappleModeActive = inGrapple;
}

// File Line: 250
// RVA: 0x3FE780
void __fastcall UFG::RadarSystem::AddRimLight(
        UFG::RadarSystem *this,
        UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *object)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rax

  v4 = UFG::qMalloc(0x28ui64, "SimObjectListEntry", 0x800ui64);
  v5 = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v4;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v4[2].mNext = v4 + 2;
    v4[3].mNext = v4 + 2;
    v4[4].mNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5[1];
  if ( v5[2].mPrev )
  {
    mPrev = v6->mPrev;
    mNext = v5[1].mNext;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mNext;
    mNext->mPrev = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)mPrev;
    v6->mPrev = v6;
    v5[1].mNext = v5 + 1;
  }
  v5[2].mPrev = object;
  if ( object )
  {
    v9 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)object->mNext;
    v9->mNext = v6;
    v6->mPrev = v9;
    v5[1].mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)&object->mNext;
    object->mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v6;
  }
  v10 = this->mRimLightObjects.mNode.mPrev;
  v10->mNext = v5;
  v5->mPrev = v10;
  v5->mNext = &this->mRimLightObjects.mNode;
  this->mRimLightObjects.mNode.mPrev = v5;
}

// File Line: 260
// RVA: 0x401050
void __fastcall UFG::RadarSystem::RemoveRimLight(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *i; // rsi
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mPrev; // rdi
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v6; // rax

  mNext = this->mRimLightObjects.mNode.mNext;
  for ( i = &this->mRimLightObjects;
        mNext != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)i;
        mNext = mNext->mNext )
  {
    if ( object == (UFG::SimObject *)mNext[2].mPrev )
    {
      mPrev = mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext);
      operator delete[](mNext);
      mNext = mPrev;
    }
  }
}

// File Line: 277
// RVA: 0x3FE6C0
void __fastcall UFG::RadarSystem::AddCombatProp(
        UFG::RadarSystem *this,
        UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *object)
{
  UFG::allocator::free_link *v4; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rax

  v4 = UFG::qMalloc(0x28ui64, "SimObjectListEntry", 0x800ui64);
  v5 = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v4;
  if ( v4 )
  {
    v4->mNext = v4;
    v4[1].mNext = v4;
    v4[2].mNext = v4 + 2;
    v4[3].mNext = v4 + 2;
    v4[4].mNext = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5[1];
  if ( v5[2].mPrev )
  {
    mPrev = v6->mPrev;
    mNext = v5[1].mNext;
    mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)mNext;
    mNext->mPrev = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)mPrev;
    v6->mPrev = v6;
    v5[1].mNext = v5 + 1;
  }
  v5[2].mPrev = object;
  if ( object )
  {
    v9 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)object->mNext;
    v9->mNext = v6;
    v6->mPrev = v9;
    v5[1].mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)&object->mNext;
    object->mNext = (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)v6;
  }
  v10 = this->mCombatProps.mNode.mPrev;
  v10->mNext = v5;
  v5->mPrev = v10;
  v5->mNext = &this->mCombatProps.mNode;
  this->mCombatProps.mNode.mPrev = v5;
}

// File Line: 286
// RVA: 0x400FE0
void __fastcall UFG::RadarSystem::RemoveCombatProp(UFG::RadarSystem *this, UFG::SimObject *object)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *i; // rsi
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mPrev; // rdi
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v6; // rax

  mNext = this->mCombatProps.mNode.mNext;
  for ( i = &this->mCombatProps;
        mNext != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)i;
        mNext = mNext->mNext )
  {
    if ( object == (UFG::SimObject *)mNext[2].mPrev )
    {
      mPrev = mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext);
      operator delete[](mNext);
      mNext = mPrev;
    }
  }
}

// File Line: 310
// RVA: 0x401C40
void __fastcall UFG::RadarSystem::Update(UFG::RadarSystem *this, float deltaTime)
{
  float v2; // xmm1_4
  bool v4; // cc
  bool v5; // zf
  float v6; // xmm11_4
  float v7; // xmm12_4
  float v8; // xmm10_4
  UFG::SimObjectCharacter *LocalPlayer; // rax
  float *m_pTransformNodeComponent; // rbx
  float v11; // xmm9_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *v13; // rcx
  UFG::Camera *p_mCamera; // rbp
  UFG::BaseCameraComponent *v15; // rcx
  _DWORD *p_mFOVOffset; // rcx
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  UFG::qVector3 *ScreenCoord; // rax
  UFG::RadarElement *mNext; // rdi
  float x; // xmm14_4
  float i; // xmm15_4
  __m128 y_low; // xmm2
  __int64 mType; // rax
  __int64 v26; // rbx
  float v27; // xmm3_4
  float a; // xmm6_4
  float mPulseFadeMinDist; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  UFG::qVector3 *v32; // rax
  __m128 v33; // xmm1
  float v34; // xmm2_4
  Render::DebugDrawContext *Context; // rax
  Render::DebugDrawContext *v36; // rdi
  float v37; // xmm3_4
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v38; // rbx
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0> *j; // rsi
  UFG::qVector3 world_pos; // [rsp+40h] [rbp-F8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-E8h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+140h] [rbp+8h] BYREF
  bool is_on_screen; // [rsp+148h] [rbp+10h] BYREF

  v2 = deltaTime + this->mPulseCurrentDuration;
  v4 = v2 <= this->mPulseDuration;
  this->mPulseCurrentDuration = v2;
  if ( !v4 )
  {
    v5 = this->mPingType == Critical;
    this->mPulseCurrentDuration = 0.0;
    if ( v5 )
      this->mPingType = Reserved;
  }
  UFG::RadarSystem::DeterminePingMode(this);
  UFG::RadarSystem::RefreshRadarList(this);
  v6 = 0.0;
  v7 = 0.0;
  v8 = 0.0;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_pTransformNodeComponent = (float *)LocalPlayer->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(LocalPlayer->m_pTransformNodeComponent);
      v6 = m_pTransformNodeComponent[44];
      v7 = m_pTransformNodeComponent[45];
      v8 = m_pTransformNodeComponent[46];
    }
  }
  v11 = (float)(this->mPulseCurrentDuration / this->mPulseDuration) * this->mPulseMaxRadius;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera && mCurrentCamera != (UFG::BaseCameraComponent *)-80i64 )
  {
    is_on_screen = 0;
    v13 = UFG::Director::Get()->mCurrentCamera;
    p_mCamera = &v13->mCamera;
    if ( !v13 )
      p_mCamera = 0i64;
    v15 = UFG::Director::Get()->mCurrentCamera;
    if ( v15 )
      p_mFOVOffset = (_DWORD *)&v15->mCamera.mFOVOffset;
    else
      p_mFOVOffset = 0i64;
    v17 = (float)(COERCE_FLOAT(p_mFOVOffset[42] ^ _xmm[0]) * 10.0) + p_mCamera->mTransformation.v3.z;
    v18 = (float)(COERCE_FLOAT(p_mFOVOffset[41] ^ _xmm[0]) * 10.0) + p_mCamera->mTransformation.v3.y;
    v19 = (float)(COERCE_FLOAT(p_mFOVOffset[40] ^ _xmm[0]) * 10.0) + p_mCamera->mTransformation.v3.x;
    viewport_scale.x = 1.0;
    viewport_scale.y = 1.0;
    world_pos.x = v19;
    world_pos.y = v18;
    world_pos.z = v17;
    ScreenCoord = UFG::Camera::GetScreenCoord(p_mCamera, &result, &world_pos, &viewport_scale, &is_on_screen);
    mNext = (UFG::RadarElement *)this->mElements.mNode.mNext;
    x = ScreenCoord->x;
    for ( i = ScreenCoord->y; mNext != (UFG::RadarElement *)&this->mElements; mNext = (UFG::RadarElement *)mNext->mNext )
    {
      y_low = (__m128)LODWORD(mNext->mPosition.y);
      mType = mNext->mType;
      v26 = mType;
      y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v7) * (float)(y_low.m128_f32[0] - v7))
                                + (float)((float)(mNext->mPosition.x - v6) * (float)(mNext->mPosition.x - v6)))
                        + (float)((float)(mNext->mPosition.z - v8) * (float)(mNext->mPosition.z - v8));
      v27 = _mm_sqrt_ps(y_low).m128_f32[0];
      a = 1.0 - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v27 - v11) & _xmm) / this->mPulseActiveRange);
      if ( a <= 0.0 )
      {
        a = 0.0;
      }
      else if ( a >= 1.0 )
      {
        a = *(float *)&FLOAT_1_0;
      }
      if ( UFG::RadarSystem::sRevealParams[mType].mUseDistanceScalar )
      {
        mPulseFadeMinDist = UFG::RadarSystem::sRevealParams[mType].mPulseFadeMinDist;
        v30 = v27 - mPulseFadeMinDist;
        if ( v30 <= 0.0 )
          v30 = 0.0;
        v31 = 1.0 - (float)(v30 / (float)(UFG::RadarSystem::sRevealParams[mType].mPulseFadeMaxDist - mPulseFadeMinDist));
        if ( v31 <= 0.0 )
        {
          v31 = 0.0;
        }
        else if ( v31 >= 1.0 )
        {
          v31 = *(float *)&FLOAT_1_0;
        }
        a = v31 * a;
      }
      if ( UFG::RadarSystem::sRevealParams[mType].mUseScreenSpaceScalar )
      {
        v32 = UFG::Camera::GetScreenCoord(p_mCamera, &result, &mNext->mPosition, &viewport_scale, &is_on_screen);
        v33 = (__m128)LODWORD(v32->y);
        v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] - i) * (float)(v33.m128_f32[0] - i))
                        + (float)((float)(v32->x - x) * (float)(v32->x - x));
        v34 = 1.0
            - (float)(_mm_sqrt_ps(v33).m128_f32[0] / UFG::RadarSystem::sRevealParams[v26].mScreenSpaceRevealRadius);
        if ( v34 <= 0.0 )
        {
          v34 = 0.0;
        }
        else if ( v34 >= 1.0 )
        {
          v34 = *(float *)&FLOAT_1_0;
        }
        a = a * v34;
      }
      if ( UFG::RadarSystem::sRevealParams[v26].mAlwaysOn )
        a = UFG::RadarSystem::sRadarTypeColors[mNext->mType].a;
      UFG::RadarElement::Highlight(mNext, a >= 0.0, a);
    }
  }
  if ( UFG::RadarSystem::sDebugRender )
  {
    world_pos.x = v6;
    world_pos.y = v7;
    world_pos.z = v8 + 0.5;
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
    v36 = Context;
    v37 = v11 - this->mPulseActiveRange;
    if ( v37 <= 0.0 )
      v37 = 0.0;
    Render::DebugDrawContext::DrawCircle(
      Context,
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
      v11 + this->mPulseActiveRange,
      &UFG::qColour::Red,
      &UFG::qMatrix44::msIdentity,
      0i64);
    v38 = this->mElements.mNode.mNext;
    for ( j = &this->mElements; v38 != (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)j; v38 = v38->mNext )
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
  UFG::PingType::Enum v2; // ebx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCVBase *v4; // rsi
  int m_ControllerID; // ebp
  UFG::AICharacterControllerComponent *v6; // rax
  UFG::InputActionData *v7; // rcx
  UFG::TargetingSystemPedPlayerComponent *v8; // rax
  UFG::eFocusModeEnum m_eFocusMode; // edx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimObjectCharacterPropertiesComponent *ComponentOfTypeHK; // rax

  if ( !UFG::RadarSystem::sDebugOverridePingType && this->mPingType != Critical )
  {
    if ( NISManager::GetInstance()->mState )
    {
      this->mPingType = UnReferenced;
    }
    else
    {
      v2 = Reserved;
      LocalPlayer = UFG::GetLocalPlayer();
      v4 = LocalPlayer;
      if ( LocalPlayer )
      {
        m_ControllerID = 0;
        v6 = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerComponent>(LocalPlayer);
        if ( v6 )
          m_ControllerID = v6->m_ControllerID;
        v7 = UFG::ActionDef_Freerun.mDataPerController[m_ControllerID];
        if ( v7 && v7->mActionTrue )
          v2 = Count;
        v8 = UFG::SimObjectCVBase::GetComponent<UFG::TargetingSystemPedPlayerComponent>(v4);
        if ( v8 )
        {
          if ( v8->m_bIsAimingActive )
          {
            m_eFocusMode = v8->m_eFocusMode;
            if ( (unsigned int)(m_eFocusMode - 1) <= 1 || (unsigned int)(m_eFocusMode - 3) <= 1 )
              v2 = Low;
          }
          if ( this->mGrappleModeActive )
          {
            m_pPointer = (UFG::SimObjectCVBase *)v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[23]].m_pTarget.m_pPointer;
            if ( m_pPointer )
            {
              m_Flags = m_pPointer->m_Flags;
              if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
              {
                ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pPointer);
              }
              else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              {
                ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                    m_pPointer,
                                                                                    UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              else
              {
                ComponentOfTypeHK = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                                    m_pPointer,
                                                                                    UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
              }
              if ( ComponentOfTypeHK && (ComponentOfTypeHK->mBooleans.mBits[0] & 4) != 0 )
                v2 = Low|Critical;
            }
          }
        }
        if ( this->mbPokerDiceMode )
          v2 = High;
      }
      if ( this->mPingType != v2 )
      {
        this->mPingType = v2;
        this->mPulseCurrentDuration = 0.0;
      }
    }
  }
}

// File Line: 471
// RVA: 0x4015C0
void __fastcall UFG::RadarSystem::ScanPokerTileLights(UFG::RadarSystem *this)
{
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *mNext; // rbx
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *i; // rsi
  UFG::SimObjectGame *m_pPointer; // rdx
  UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *mPrev; // rdi
  UFG::qNode<UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> >,UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > > *v6; // rax

  mNext = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)this->mPokerTiles.mNode.mNext;
  for ( i = &this->mPokerTiles;
        mNext != (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)i;
        mNext = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext->mNext )
  {
    m_pPointer = (UFG::SimObjectGame *)mNext->mValue.m_pPointer;
    if ( m_pPointer )
    {
      UFG::RadarSystem::AddSimObject(this, m_pPointer, Low|Critical);
    }
    else
    {
      mPrev = (UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry(mNext);
      operator delete[](mNext);
      mNext = mPrev;
    }
  }
}

// File Line: 492
// RVA: 0x401650
void __fastcall UFG::RadarSystem::ScanRimLights(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rdi
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *i; // rsi
  UFG::SimObjectGame *mPrev; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v7; // ecx
  UFG::RadarType::Enum v8; // r8d
  UFG::RadarSystem::ElementRevealParams *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v11; // rax

  mNext = this->mRimLightObjects.mNode.mNext;
  for ( i = &this->mRimLightObjects;
        mNext != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)i;
        mNext = mNext->mNext )
  {
    mPrev = (UFG::SimObjectGame *)mNext[2].mPrev;
    if ( mPrev )
    {
      m_Flags = mPrev->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(mPrev, UFG::RadarComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mPrev, UFG::RadarComponent::_TypeUID);
      if ( ComponentOfTypeHK )
      {
        v7 = (int)ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext;
        v8 = UnReferenced;
        v9 = UFG::RadarSystem::sRevealParams;
        while ( v9->mTypeSymbol.mUID != v7 )
        {
          ++v8;
          ++v9;
          if ( (unsigned int)v8 >= 9 )
          {
            UFG::RadarSystem::AddSimObject(this, (UFG::SimObjectGame *)mNext[2].mPrev, UnReferenced);
            goto LABEL_19;
          }
        }
      }
      else
      {
        v8 = UnReferenced;
        if ( (WORD2(mNext[2].mPrev[4].mNext) & 0x4000) != 0 )
          v8 = 8;
      }
      UFG::RadarSystem::AddSimObject(this, (UFG::SimObjectGame *)mNext[2].mPrev, v8);
    }
    else
    {
      v10 = mNext->mPrev;
      v11 = mNext->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext);
      operator delete[](mNext);
      mNext = v10;
    }
LABEL_19:
    ;
  }
}

// File Line: 522
// RVA: 0x401200
void __fastcall UFG::RadarSystem::ScanCombatProps(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *mNext; // rdi
  UFG::qList<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry,1,0> *i; // rsi
  UFG::SimObjectGame *mPrev; // rcx
  __int16 m_Flags; // dx
  UFG::RadarType::Enum v6; // ebx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v8; // ecx
  UFG::RadarSystem::ElementRevealParams *v9; // rax
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v10; // rbx
  UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *v11; // rax

  mNext = this->mCombatProps.mNode.mNext;
  for ( i = &this->mCombatProps;
        mNext != (UFG::qNode<UFG::RadarSystem::SimObjectListEntry,UFG::RadarSystem::SimObjectListEntry> *)i;
        mNext = mNext->mNext )
  {
    mPrev = (UFG::SimObjectGame *)mNext[2].mPrev;
    if ( mPrev )
    {
      m_Flags = mPrev->m_Flags;
      v6 = Critical;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(mPrev, UFG::RadarComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mPrev, UFG::RadarComponent::_TypeUID);
      if ( ComponentOfTypeHK )
      {
        v8 = (int)ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext;
        v6 = UnReferenced;
        v9 = UFG::RadarSystem::sRevealParams;
        while ( v9->mTypeSymbol.mUID != v8 )
        {
          ++v6;
          ++v9;
          if ( (unsigned int)v6 >= 9 )
          {
            v6 = UnReferenced;
            break;
          }
        }
      }
      UFG::RadarSystem::AddSimObject(this, (UFG::SimObjectGame *)mNext[2].mPrev, v6);
    }
    else
    {
      v10 = mNext->mPrev;
      v11 = mNext->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadarSystem::SimObjectListEntry::~SimObjectListEntry((UFG::qValueNode<UFG::qSafePointer<UFG::Editor::Terminal,UFG::Editor::Terminal> > *)mNext);
      operator delete[](mNext);
      mNext = v10;
    }
  }
}

// File Line: 548
// RVA: 0x401340
void __fastcall UFG::RadarSystem::ScanForExploadables(UFG::RadarSystem *this)
{
  UFG::RigidBody *p_mNext; // rbx
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v3; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v4; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  double v8; // xmm0_8
  float v9; // xmm1_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *v11; // rcx
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject **p_m_pSimObject; // rbx
  bool IsHighlightSimObject; // al
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v20; // rax
  UFG::qVector3 result; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 v22; // [rsp+50h] [rbp-88h] BYREF
  UFG::qReflectHandleBase v23; // [rsp+60h] [rbp-78h] BYREF
  bool is_on_screen; // [rsp+E8h] [rbp+10h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+F0h] [rbp+18h] BYREF
  UFG::allocator::free_link *v26; // [rsp+F8h] [rbp+20h]

  p_mNext = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    do
    {
      v3 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[1].m_SafePointerList.mNode.mPrev[-18].mNext;
      UFG::qReflectHandleBase::qReflectHandleBase(&v23);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v4);
      v23.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = p_mNext->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v23, &mCollisionMeshData->mObjectProperties);
      mPrev = p_mNext[1].mCollisionMeshBundle.mPrev;
      if ( mPrev )
        v8 = *((float *)&mPrev[16].mNext + 1);
      else
        v8 = DOUBLE_1_0;
      if ( v23.mData )
      {
        if ( LODWORD(v23.mData[2].mBaseNode.mNeighbours[1]) == 1 )
        {
          v9 = v8;
          if ( v9 > 0.0 )
          {
            UFG::RigidBody::GetCentreOfMass(p_mNext, &result);
            viewport_scale.x = 1.0;
            viewport_scale.y = 1.0;
            is_on_screen = 0;
            mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
            v11 = mCurrentCamera ? &mCurrentCamera->mCamera : 0i64;
            UFG::Camera::GetScreenCoord(v11, &v22, &result, &viewport_scale, &is_on_screen);
            if ( is_on_screen )
            {
              m_pSimObject = p_mNext->m_pSimObject;
              if ( m_pSimObject )
              {
                ComponentOfType = UFG::SimObject::GetComponentOfType(
                                    p_mNext->m_pSimObject,
                                    UFG::DynamicSceneryInstance::_TypeUID);
                p_m_pSimObject = &ComponentOfType[-1].m_pSimObject;
                if ( !ComponentOfType )
                  p_m_pSimObject = 0i64;
                IsHighlightSimObject = UFG::IsHighlightSimObject(m_pSimObject);
                if ( p_m_pSimObject && !IsHighlightSimObject )
                {
                  v16 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
                  v17 = v16;
                  v26 = v16;
                  if ( v16 )
                  {
                    v16->mNext = v16;
                    v16[1].mNext = v16;
                    LODWORD(v16[2].mNext) = 2;
                    v16[4].mNext = v16 + 4;
                    v16[5].mNext = v16 + 4;
                    v16[6].mNext = 0i64;
                  }
                  else
                  {
                    v17 = 0i64;
                  }
                  LODWORD(v17[2].mNext) = 3;
                  y = result.y;
                  z = result.z;
                  HIDWORD(v17[2].mNext) = LODWORD(result.x);
                  *(float *)&v17[3].mNext = y;
                  *((float *)&v17[3].mNext + 1) = z;
                  UFG::qSafePointer<Creature,Creature>::operator=(
                    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v17[4],
                    (UFG::SimComponent *)m_pSimObject);
                  v20 = this->mElements.mNode.mPrev;
                  v20->mNext = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v17;
                  v17->mNext = (UFG::allocator::free_link *)v20;
                  v17[1].mNext = (UFG::allocator::free_link *)&this->mElements;
                  this->mElements.mNode.mPrev = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v17;
                }
              }
            }
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v23);
      p_mNext = (UFG::RigidBody *)v3;
    }
    while ( v3 != (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                    - 280) );
  }
}

// File Line: 615
// RVA: 0x400EB0
void __fastcall UFG::RadarSystem::RefreshRadarList(UFG::RadarSystem *this)
{
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *mNext; // rbx
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0> *i; // rsi
  UFG::SimObject *mPrev; // rcx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v5; // r8
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v6; // rdx
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v7; // rax

  mNext = this->mElements.mNode.mNext;
  for ( i = &this->mElements; mNext != (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)i; mNext = mNext->mNext )
  {
    mPrev = (UFG::SimObject *)mNext[3].mPrev;
    if ( mPrev )
    {
      UFG::UnHighlightSimObject(mPrev);
      v5 = mNext + 2;
      if ( mNext[3].mPrev )
      {
        v6 = v5->mPrev;
        v7 = mNext[2].mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v5->mPrev = v5;
        mNext[2].mNext = mNext + 2;
      }
      mNext[3].mPrev = 0i64;
    }
  }
  UFG::qList<UFG::RadarElement,UFG::RadarElement,1,0>::DeleteNodes(i);
  if ( !UFG::RadarSystem::sDisableRadarSystem )
  {
    switch ( this->mPingType )
    {
      case Reserved:
      case Count:
        UFG::RadarSystem::ScanRimLights(this);
        break;
      case Critical:
        UFG::RadarSystem::ScanRimLights(this);
        UFG::RadarSystem::ScanCombatProps(this);
        UFG::RadarSystem::ScanForExploadables(this);
        break;
      case High:
        UFG::RadarSystem::ScanPokerTileLights(this);
        break;
      case Low:
        UFG::RadarSystem::ScanRimLights(this);
        UFG::RadarSystem::ScanForExploadables(this);
        break;
      case Low|Critical:
        UFG::RadarSystem::ScanRimLights(this);
        UFG::RadarSystem::ScanCombatProps(this);
        break;
      default:
        return;
    }
  }
}

// File Line: 674
// RVA: 0x3FE840
void __fastcall UFG::RadarSystem::AddSimObject(
        UFG::RadarSystem *this,
        UFG::SimObjectGame *object,
        UFG::RadarType::Enum type)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbp
  UFG::SimComponent *ComponentOfTypeHK; // rax
  signed __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject **p_m_pSimObject; // rbx
  signed __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  UFG::RigidBody *v15; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v16; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  double v20; // xmm0_8
  float v21; // xmm1_4
  UFG::Camera *mCurrentCamera; // rcx
  UFG::allocator::free_link *v23; // rax
  UFG::allocator::free_link *v24; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *m_pSimObject; // rax
  float x; // xmm6_4
  float v29; // xmm7_4
  float v30; // xmm8_4
  UFG::allocator::free_link *v31; // rax
  UFG::qNode<UFG::RadarElement,UFG::RadarElement> *v32; // rax
  UFG::qVector3 v33; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-98h] BYREF
  UFG::qReflectHandleBase v35; // [rsp+60h] [rbp-88h] BYREF
  UFG::allocator::free_link *is_on_screen; // [rsp+F8h] [rbp+10h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+108h] [rbp+20h] BYREF

  if ( object )
  {
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = object->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = object->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                object,
                                UFG::CompositeDrawableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::CompositeDrawableComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = object->m_Components.p[14].m_pComponent;
    }
    v10 = object->m_Flags;
    if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
      ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::DynamicSceneryInstance::_TypeUID);
    else
      ComponentOfType = UFG::SimObject::GetComponentOfType(object, UFG::DynamicSceneryInstance::_TypeUID);
    if ( ComponentOfType )
      p_m_pSimObject = &ComponentOfType[-1].m_pSimObject;
    else
      p_m_pSimObject = 0i64;
    v13 = object->m_Flags;
    if ( (v13 & 0x4000) != 0 || v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
      v14 = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::RigidBodyComponent::_TypeUID);
    else
      v14 = UFG::SimObject::GetComponentOfType(object, UFG::RigidBodyComponent::_TypeUID);
    v15 = (UFG::RigidBody *)v14;
    if ( v14 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&v35);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v16);
      v35.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = v15->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v35, &mCollisionMeshData->mObjectProperties);
      mPrev = v15[1].mCollisionMeshBundle.mPrev;
      if ( mPrev )
        v20 = *((float *)&mPrev[16].mNext + 1);
      else
        v20 = DOUBLE_1_0;
      if ( v35.mData )
      {
        v21 = v20;
        if ( v21 <= 0.0 )
        {
          UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
          return;
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
    }
    if ( p_m_pSimObject && v15 )
    {
      UFG::RigidBody::GetCentreOfMass(v15, &result);
      viewport_scale.x = 1.0;
      viewport_scale.y = 1.0;
      LOBYTE(is_on_screen) = 0;
      mCurrentCamera = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        mCurrentCamera = (UFG::Camera *)((char *)mCurrentCamera + 80);
      UFG::Camera::GetScreenCoord(mCurrentCamera, &v33, &result, &viewport_scale, (bool *)&is_on_screen);
      if ( (_BYTE)is_on_screen )
      {
        v23 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
        v24 = v23;
        if ( v23 )
        {
          v23->mNext = v23;
          v23[1].mNext = v23;
          LODWORD(v23[2].mNext) = 2;
          *(_QWORD *)&v33.x = v23 + 4;
          v23[4].mNext = v23 + 4;
          v23[5].mNext = v23 + 4;
          v23[6].mNext = 0i64;
        }
        else
        {
          v24 = 0i64;
        }
        LODWORD(v24[2].mNext) = 3;
        y = result.y;
        z = result.z;
        HIDWORD(v24[2].mNext) = LODWORD(result.x);
        *(float *)&v24[3].mNext = y;
        *((float *)&v24[3].mNext + 1) = z;
LABEL_56:
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v24[4],
          (UFG::SimComponent *)object);
        v32 = this->mElements.mNode.mPrev;
        v32->mNext = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v24;
        v24->mNext = (UFG::allocator::free_link *)v32;
        v24[1].mNext = (UFG::allocator::free_link *)&this->mElements;
        this->mElements.mNode.mPrev = (UFG::qNode<UFG::RadarElement,UFG::RadarElement> *)v24;
      }
    }
    else if ( m_pTransformNodeComponent )
    {
      if ( m_pComponent )
      {
        m_pSimObject = m_pComponent[19].m_pSimObject;
        if ( m_pSimObject )
        {
          if ( LOBYTE(m_pSimObject->vfptr) <= 1u )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
            x = m_pTransformNodeComponent->mWorldTransform.v3.x;
            v29 = m_pTransformNodeComponent->mWorldTransform.v3.y;
            v30 = m_pTransformNodeComponent->mWorldTransform.v3.z;
            v31 = UFG::qMalloc(0x38ui64, "RadarSystem", 0x800ui64);
            v24 = v31;
            is_on_screen = v31;
            if ( v31 )
            {
              v31->mNext = v31;
              v31[1].mNext = v31;
              LODWORD(v31[2].mNext) = 2;
              viewport_scale = (UFG::qVector2)&v31[4];
              v31[4].mNext = v31 + 4;
              v31[5].mNext = v31 + 4;
              v31[6].mNext = 0i64;
            }
            else
            {
              v24 = 0i64;
            }
            LODWORD(v24[2].mNext) = type;
            *((float *)&v24[2].mNext + 1) = x;
            *(float *)&v24[3].mNext = v29;
            *((float *)&v24[3].mNext + 1) = v30;
            goto LABEL_56;
          }
        }
      }
    }
  }
}

