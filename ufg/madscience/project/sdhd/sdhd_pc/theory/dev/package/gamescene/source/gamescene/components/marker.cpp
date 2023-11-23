// File Line: 62
// RVA: 0x14755E0
__int64 UFG::_dynamic_initializer_for__symAIFleeToPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FleeToPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIFleeToPoint, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAIFleeToPoint__);
}

// File Line: 63
// RVA: 0x1475620
__int64 UFG::_dynamic_initializer_for__symAIJumpPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AIJumpPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIJumpPoint, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAIJumpPoint__);
}

// File Line: 64
// RVA: 0x14756E0
__int64 UFG::_dynamic_initializer_for__symAISeedPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AISeedPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAISeedPoint, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAISeedPoint__);
}

// File Line: 65
// RVA: 0x1475660
__int64 UFG::_dynamic_initializer_for__symAIPathMarker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AIPathMarker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIPathMarker, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAIPathMarker__);
}

// File Line: 66
// RVA: 0x14756A0
__int64 UFG::_dynamic_initializer_for__symAIReinforcementPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ReinforcementPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIReinforcementPoint, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symAIReinforcementPoint__);
}

// File Line: 72
// RVA: 0x23D5F0
UFG::ComponentIDDesc *__fastcall UFG::MarkerBase::GetDesc(UFG::MarkerBase *this)
{
  return &UFG::MarkerBase::_TypeIDesc;
}

// File Line: 76
// RVA: 0x1470B60
__int64 dynamic_initializer_for__UFG::MarkerBase::msMarkers__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::MarkerBase::msMarkers.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MarkerBase::msMarkers__);
}

// File Line: 120
// RVA: 0x2374E0
void __fastcall UFG::MarkerBase::MarkerBase(
        UFG::MarkerBase *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj,
        unsigned int flags)
{
  unsigned int mUID; // eax

  UFG::SimComponent::SimComponent(this, name->mUID);
  this->i_name = (UFG::qSymbol)name->mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HintComponentBase::`vftable;
  this->mFlags = flags;
  UFG::SimComponent::AddType(this, UFG::HintComponentBase::_HintComponentBaseTypeUID, "HintComponentBase");
  mUID = name->mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = mUID;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable;
  this->mpXformNode = 0i64;
  UFG::SimComponent::AddType(this, UFG::MarkerBase::_MarkerBaseTypeUID, "MarkerBase");
  if ( pSimObj )
    UFG::MarkerBase::Initialize(this, pSimObj);
}

// File Line: 133
// RVA: 0x23E740
void __fastcall UFG::MarkerBase::Initialize(UFG::MarkerBase *this, UFG::SimObject *pSimObj)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rax
  UFG::SimObjectModifier v4; // [rsp+28h] [rbp-30h] BYREF

  if ( !this->mpXformNode )
  {
    if ( pSimObj )
      m_pTransformNodeComponent = pSimObj->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    this->mpXformNode = m_pTransformNodeComponent;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v4, pSimObj, 1);
  UFG::SimObjectModifier::AttachComponent(&v4, this, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v4);
  UFG::SimObjectModifier::~SimObjectModifier(&v4);
  if ( (this->mFlags & 0x10000) != 0 )
    UFG::qBaseTreeRB::Add(&UFG::MarkerBase::msMarkers.mTree, &this->mNode);
}

// File Line: 153
// RVA: 0x2381D0
void __fastcall UFG::MarkerBase::~MarkerBase(UFG::MarkerBase *this)
{
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable;
  if ( (this->mFlags & 0x10000) != 0 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::MarkerBase>);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 164
// RVA: 0x23D940
UFG::qBaseTreeRB *__fastcall UFG::MarkerBase::GetNamed(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax

  if ( name->mUID && (v1 = UFG::qBaseTreeRB::Get(&UFG::MarkerBase::msMarkers.mTree, name->mUID)) != 0i64 )
    return v1 - 1;
  else
    return 0i64;
}

// File Line: 169
// RVA: 0x23D8F0
UFG::qTreeRB<UFG::MarkerBase,UFG::MarkerBase,1> *__fastcall UFG::MarkerBase::GetMarkers()
{
  return &UFG::MarkerBase::msMarkers;
}

// File Line: 283
// RVA: 0x23D5E0
UFG::ComponentIDDesc *__fastcall UFG::Marker::GetDesc(UFG::Marker *this)
{
  return &UFG::Marker::_TypeIDesc;
}

// File Line: 328
// RVA: 0x23E3C0
bool __fastcall UFG::Marker::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::SchemaDef *Schema; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  Schema = UFG::PropertySetManager::GetSchema((UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentMarker);
  if ( Schema )
    return UFG::qPropertySet::PropertyExists(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&Schema->mPropertyName,
             DEPTH_RECURSE) != 0i64;
  else
    return UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentMarker,
             DEPTH_RECURSE) != 0i64;
}

// File Line: 338
// RVA: 0x243FC0
UFG::allocator::free_link *__fastcall UFG::Marker::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v8; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x70ui64, "Marker", 0i64, 1u);
  v8 = v3;
  if ( !v3 )
    return 0i64;
  m_pSimObject = pSceneObj->m_pSimObject;
  v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)v3, v5, m_pSimObject, 0x10000u);
  v3->mNext = (UFG::allocator::free_link *)&UFG::Marker::`vftable;
  UFG::SimComponent::AddType((UFG::SimComponent *)v3, UFG::Marker::_MarkerTypeUID, "Marker");
  return v3;
}

// File Line: 356
// RVA: 0x23E220
const char *__fastcall UFG::CameraMarker::GetTypeName(UFG::CameraMarker *this)
{
  return "CameraMarker";
}

// File Line: 380
// RVA: 0x243F00
UFG::allocator::free_link *__fastcall UFG::CameraMarker::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v8; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x70ui64, "CameraMarker", 0i64, 1u);
  v8 = v3;
  if ( !v3 )
    return 0i64;
  m_pSimObject = sceneObj->m_pSimObject;
  v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, sceneObj->m_NameUID);
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)v3, v5, m_pSimObject, 0x10000u);
  v3->mNext = (UFG::allocator::free_link *)&UFG::CameraMarker::`vftable;
  UFG::SimComponent::AddType((UFG::SimComponent *)v3, UFG::CameraMarker::_CameraMarkerTypeUID, "CameraMarker");
  return v3;
}

// File Line: 408
// RVA: 0x23D7C0
float __fastcall UFG::CameraMarker::GetFovH(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymFovH,
            DEPTH_RECURSE);
}

// File Line: 413
// RVA: 0x23D6C0
float __fastcall UFG::CameraMarker::GetDofFocalDist(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofFocalDist,
            DEPTH_RECURSE);
}

// File Line: 418
// RVA: 0x23D700
float __fastcall UFG::CameraMarker::GetDofInFocusRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofInFocusRange,
            DEPTH_RECURSE);
}

// File Line: 423
// RVA: 0x23D780
float __fastcall UFG::CameraMarker::GetDofNearRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofNearRange,
            DEPTH_RECURSE);
}

// File Line: 428
// RVA: 0x23D740
float __fastcall UFG::CameraMarker::GetDofNearBlurRadius(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofNearBlurRadius,
            DEPTH_RECURSE);
}

// File Line: 433
// RVA: 0x23D680
float __fastcall UFG::CameraMarker::GetDofFarRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofFarRange,
            DEPTH_RECURSE);
}

// File Line: 438
// RVA: 0x23D640
float __fastcall UFG::CameraMarker::GetDofFarBlurRadius(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  return *UFG::qPropertySet::Get<float>(
            mpWritableProperties,
            (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymDofFarBlurRadius,
            DEPTH_RECURSE);
}

// File Line: 454
// RVA: 0x23D5B0
UFG::ComponentIDDesc *__fastcall UFG::AIMarker::GetDesc(UFG::AIMarker *this)
{
  return &UFG::AIMarker::_TypeIDesc;
}

// File Line: 456
// RVA: 0x1470CD0
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIFleeToPointColour__()
{
  UFG::AIMarker::s_AIFleeToPointColour = UFG::qColour::Gold;
  return LODWORD(UFG::qColour::Gold.a);
}

// File Line: 457
// RVA: 0x1470D30
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIJumpPointColour__()
{
  UFG::AIMarker::s_AIJumpPointColour = UFG::qColour::Maroon;
  return LODWORD(UFG::qColour::Maroon.a);
}

// File Line: 458
// RVA: 0x1470D90
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIPathMarkerColour__()
{
  UFG::AIMarker::s_AIPathMarkerColour = UFG::qColour::Yellow;
  return LODWORD(UFG::qColour::Yellow.a);
}

// File Line: 459
// RVA: 0x1470DF0
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIReinforcementPointColour__()
{
  UFG::AIMarker::s_AIReinforcementPointColour = UFG::qColour::Blue;
  return LODWORD(UFG::qColour::Blue.a);
}

// File Line: 461
// RVA: 0x1470D10
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIFleeToPointList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIMarker::s_AIFleeToPointList__);
}

// File Line: 462
// RVA: 0x1470D70
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIJumpPointList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIMarker::s_AIJumpPointList__);
}

// File Line: 463
// RVA: 0x1470DD0
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIPathMarkerList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIMarker::s_AIPathMarkerList__);
}

// File Line: 464
// RVA: 0x1470E30
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIReinforcementPointList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIMarker::s_AIReinforcementPointList__);
}

// File Line: 505
// RVA: 0x2373C0
void __fastcall UFG::AIMarker::AIMarker(
        UFG::AIMarker *this,
        UFG::qSymbol *name,
        UFG::AIMarker::EAIMarkerType type,
        UFG::SimObject *pSimObj)
{
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v6; // rdi
  UFG::AIMarker::EAIMarkerType m_eType; // ecx
  __int32 v8; // ecx
  __int32 v9; // ecx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *mPrev; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v11; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v12; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v13; // rax

  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x10000u);
  v6 = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  this->mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  this->mNext = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIMarker::`vftable;
  this->m_eType = type;
  UFG::SimComponent::AddType(this, UFG::AIMarker::_AIMarkerTypeUID, "AIMarker");
  m_eType = this->m_eType;
  if ( m_eType )
  {
    v8 = m_eType - 1;
    if ( v8 )
    {
      v9 = v8 - 2;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          mPrev = UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev;
          UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev->mNext = v6;
          v6->mPrev = mPrev;
          this->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIReinforcementPointList;
          UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
        }
      }
      else
      {
        v11 = UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev;
        UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev->mNext = v6;
        v6->mPrev = v11;
        this->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIPathMarkerList;
        UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
      }
    }
    else
    {
      v12 = UFG::AIMarker::s_AIJumpPointList.mNode.mPrev;
      UFG::AIMarker::s_AIJumpPointList.mNode.mPrev->mNext = v6;
      v6->mPrev = v12;
      this->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIJumpPointList;
      UFG::AIMarker::s_AIJumpPointList.mNode.mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
    }
  }
  else
  {
    v13 = UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev;
    UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev->mNext = v6;
    v6->mPrev = v13;
    this->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIFleeToPointList;
    UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  }
}

// File Line: 524
// RVA: 0x238110
void __fastcall UFG::AIMarker::~AIMarker(UFG::AIMarker *this)
{
  UFG::AIMarker::EAIMarkerType m_eType; // ecx
  __int32 v3; // ecx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *mPrev; // rcx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *mNext; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v6; // rcx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v7; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIMarker::`vftable;
  m_eType = this->m_eType;
  if ( m_eType == EAIMarkerType_AIFleeToPoint || (v3 = m_eType - 1) == 0 || (unsigned int)(v3 - 2) <= 1 )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mNext = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
    this->mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  }
  v6 = this->mPrev;
  v7 = this->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->mPrev = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  this->mNext = &this->UFG::qNode<UFG::AIMarker,UFG::AIMarker>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable;
  if ( (this->mFlags & 0x10000) != 0 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::MarkerBase>);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 538
// RVA: 0x23E350
bool __fastcall UFG::AIMarker::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rbx
  UFG::SchemaDef *Schema; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  Schema = UFG::PropertySetManager::GetSchema((UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAIMarker);
  if ( Schema )
    return UFG::qPropertySet::PropertyExists(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&Schema->mPropertyName,
             DEPTH_RECURSE) != 0i64;
  else
    return UFG::qPropertySet::GetParentFromName(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAIMarker,
             DEPTH_RECURSE) != 0i64;
}

// File Line: 548
// RVA: 0x243E00
void __fastcall UFG::AIMarker::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  unsigned int mFlags; // eax
  UFG::AIMarker::EAIMarkerType v3; // esi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v5; // rbp
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v7; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  mFlags = PropertyUtils::Get<UFG::qSymbol>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_ObjectType)->mFlags;
  if ( mFlags == UFG::symAIFleeToPoint.mUID )
  {
    v3 = EAIMarkerType_AIFleeToPoint;
  }
  else if ( mFlags == UFG::symAIJumpPoint.mUID )
  {
    v3 = EAIMarkerType_AIJumpPoint;
  }
  else if ( mFlags == UFG::symAISeedPoint.mUID )
  {
    v3 = EAIMarkerType_AISeedPoint;
  }
  else if ( mFlags == UFG::symAIPathMarker.mUID )
  {
    v3 = EAIMarkerType_AIPathMarker;
  }
  else
  {
    v3 = EAIMarkerType_AIFleeToPoint;
    if ( mFlags == UFG::symAIReinforcementPoint.mUID )
      v3 = EAIMarkerType_AIReinforcementPoint;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x88ui64, "AIMarker", 0i64, 1u);
  v9 = v5;
  if ( v5 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, pSceneObj->m_NameUID);
    UFG::AIMarker::AIMarker((UFG::AIMarker *)v5, v7, v3, m_pSimObject);
  }
}

// File Line: 586
// RVA: 0x23E1A0
__int64 __fastcall UFG::AIMarker::GetType(UFG::AIMarker *this)
{
  UFG::AIMarker::EAIMarkerType m_eType; // edx
  __int32 v2; // edx
  __int32 v3; // edx
  __int32 v4; // edx

  m_eType = this->m_eType;
  if ( m_eType )
  {
    v2 = m_eType - 1;
    if ( !v2 )
      return 0x40000i64;
    v3 = v2 - 1;
    if ( !v3 )
      return 0x4000000i64;
    v4 = v3 - 1;
    if ( !v4 )
      return 0x100000i64;
    if ( v4 == 1 )
      return 0x200000i64;
  }
  return 0x20000i64;
}

// File Line: 628
// RVA: 0x23C0F0
float __fastcall UFG::AIMarker::GetArrivalTolerance(UFG::AIMarker *this, UFG::SimObject *pObject)
{
  UFG::SimObject *m_pSimObject; // rbx
  float *v3; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rax

  m_pSimObject = pObject;
  if ( pObject )
  {
    while ( 1 )
    {
      v3 = PropertyUtils::Get<float>(
             m_pSimObject->m_pSceneObj,
             (UFG::qArray<unsigned long,0> *)&qSymbol_AIPathMarker_ArrivalTolerance);
      if ( !v3 )
        break;
      if ( *v3 >= 0.0 )
        return *v3;
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
        m_pTransformNodeComponent = m_pTransformNodeComponent->mParent;
      if ( m_pTransformNodeComponent )
      {
        m_pSimObject = m_pTransformNodeComponent->m_pSimObject;
        if ( m_pSimObject )
          continue;
      }
      return FLOAT_N1_0;
    }
  }
  return FLOAT_N1_0;
}

// File Line: 654
// RVA: 0x23E120
UFG::qSymbol *__fastcall UFG::AIMarker::GetSpeed(UFG::AIMarker *this, UFG::qSymbol *result, UFG::SimObject *pObject)
{
  UFG::qPropertySet *v6; // rax
  unsigned int mUID; // eax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r8
  UFG::qSymbol resulta; // [rsp+40h] [rbp+18h] BYREF

  if ( !pObject
    || (v6 = PropertyUtils::Get<UFG::qSymbol>(
               pObject->m_pSceneObj,
               (UFG::qArray<unsigned long,0> *)&qSymbol_AIPathMarker_Speed)) == 0i64 )
  {
LABEL_8:
    mUID = UFG::MoveTypeSymbols[0].mUID;
    goto LABEL_9;
  }
  mUID = v6->mFlags;
  if ( mUID == UFG::MoveTypeSymbols[0].mUID )
  {
    m_pTransformNodeComponent = pObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
      m_pTransformNodeComponent = m_pTransformNodeComponent->mParent;
    if ( m_pTransformNodeComponent )
      UFG::AIMarker::GetSpeed(this, &resulta, m_pTransformNodeComponent->m_pSimObject);
    goto LABEL_8;
  }
LABEL_9:
  result->mUID = mUID;
  return result;
}

// File Line: 681
// RVA: 0x23D900
__int64 __fastcall UFG::AIMarker::GetMoveType(UFG::AIMarker *this, UFG::SimObject *pObject)
{
  __int64 v2; // rax
  UFG::qStaticSymbol *v3; // rdx
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  UFG::AIMarker::GetSpeed(this, &result, pObject);
  v2 = 0i64;
  v3 = UFG::MoveTypeSymbols;
  while ( result.mUID != v3->mUID )
  {
    ++v3;
    v2 = (unsigned int)(v2 + 1);
    if ( (__int64)v3 >= (__int64)&UI_HASH_STATS_3 )
      return 0i64;
  }
  return v2;
}

