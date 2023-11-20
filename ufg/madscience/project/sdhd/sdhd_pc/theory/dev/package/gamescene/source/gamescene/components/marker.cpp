// File Line: 62
// RVA: 0x14755E0
__int64 UFG::_dynamic_initializer_for__symAIFleeToPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("FleeToPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIFleeToPoint, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAIFleeToPoint__);
}

// File Line: 63
// RVA: 0x1475620
__int64 UFG::_dynamic_initializer_for__symAIJumpPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AIJumpPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIJumpPoint, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAIJumpPoint__);
}

// File Line: 64
// RVA: 0x14756E0
__int64 UFG::_dynamic_initializer_for__symAISeedPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AISeedPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAISeedPoint, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAISeedPoint__);
}

// File Line: 65
// RVA: 0x1475660
__int64 UFG::_dynamic_initializer_for__symAIPathMarker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("AIPathMarker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIPathMarker, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAIPathMarker__);
}

// File Line: 66
// RVA: 0x14756A0
__int64 UFG::_dynamic_initializer_for__symAIReinforcementPoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ReinforcementPoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symAIReinforcementPoint, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symAIReinforcementPoint__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::MarkerBase::msMarkers__);
}

// File Line: 120
// RVA: 0x2374E0
void __fastcall UFG::MarkerBase::MarkerBase(UFG::MarkerBase *this, UFG::qSymbol *name, UFG::SimObject *pSimObj, unsigned int flags)
{
  unsigned int v4; // ebx
  UFG::SimObject *v5; // rbp
  UFG::qSymbol *v6; // rdi
  UFG::MarkerBase *v7; // rsi
  unsigned int v8; // eax

  v4 = flags;
  v5 = pSimObj;
  v6 = name;
  v7 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name->mUID);
  v7->i_name = (UFG::qSymbol)v6->mUID;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HintComponentBase::`vftable';
  v7->mFlags = v4;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v7->vfptr,
    UFG::HintComponentBase::_HintComponentBaseTypeUID,
    "HintComponentBase");
  v8 = v6->mUID;
  v7->mNode.mParent = 0i64;
  v7->mNode.mChild[0] = 0i64;
  v7->mNode.mChild[1] = 0i64;
  v7->mNode.mUID = v8;
  v7->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable';
  v7->mpXformNode = 0i64;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v7->vfptr, UFG::MarkerBase::_MarkerBaseTypeUID, "MarkerBase");
  if ( v5 )
    UFG::MarkerBase::Initialize(v7, v5);
}

// File Line: 133
// RVA: 0x23E740
void __fastcall UFG::MarkerBase::Initialize(UFG::MarkerBase *this, UFG::SimObject *pSimObj)
{
  UFG::MarkerBase *v2; // rbx
  UFG::TransformNodeComponent *v3; // rax
  UFG::SimObjectModifier v4; // [rsp+28h] [rbp-30h]

  v2 = this;
  if ( !this->mpXformNode )
  {
    if ( pSimObj )
      v3 = pSimObj->m_pTransformNodeComponent;
    else
      v3 = 0i64;
    this->mpXformNode = v3;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v4, pSimObj, 1);
  UFG::SimObjectModifier::AttachComponent(&v4, (UFG::SimComponent *)&v2->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v4);
  UFG::SimObjectModifier::~SimObjectModifier(&v4);
  if ( v2->mFlags & 0x10000 )
    UFG::qBaseTreeRB::Add(&UFG::MarkerBase::msMarkers.mTree, &v2->mNode);
}

// File Line: 153
// RVA: 0x2381D0
void __fastcall UFG::MarkerBase::~MarkerBase(UFG::MarkerBase *this)
{
  UFG::MarkerBase *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable';
  if ( this->mFlags & 0x10000 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->mNode);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 164
// RVA: 0x23D940
UFG::qBaseTreeRB *__fastcall UFG::MarkerBase::GetNamed(UFG::qSymbol *name)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseTreeRB *result; // rax

  if ( name->mUID && (v1 = UFG::qBaseTreeRB::Get(&UFG::MarkerBase::msMarkers.mTree, name->mUID)) != 0i64 )
    result = v1 - 1;
  else
    result = 0i64;
  return result;
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
  UFG::qPropertySet *v1; // rbx
  UFG::SchemaDef *v2; // rax
  bool result; // al

  v1 = pSceneObj->mpWritableProperties;
  if ( !v1 )
    v1 = pSceneObj->mpConstProperties;
  v2 = UFG::PropertySetManager::GetSchema((UFG::qSymbol *)&SimSymX_propset_componentMarker.mUID);
  if ( v2 )
    result = UFG::qPropertySet::PropertyExists(v1, &v2->mPropertyName, DEPTH_RECURSE) != 0i64;
  else
    result = UFG::qPropertySet::GetParentFromName(
               v1,
               (UFG::qSymbol *)&SimSymX_propset_componentMarker.mUID,
               DEPTH_RECURSE) != 0i64;
  return result;
}

// File Line: 338
// RVA: 0x243FC0
UFG::allocator::free_link *__fastcall UFG::Marker::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v8; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x70ui64, "Marker", 0i64, 1u);
  v8 = v3;
  if ( !v3 )
    return 0i64;
  v4 = v1->m_pSimObject;
  v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)v3, v5, v4, 0x10000u);
  v3->mNext = (UFG::allocator::free_link *)&UFG::Marker::`vftable';
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
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rsi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v8; // [rsp+70h] [rbp+18h]

  v1 = sceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x70ui64, "CameraMarker", 0i64, 1u);
  v8 = v3;
  if ( !v3 )
    return 0i64;
  v4 = v1->m_pSimObject;
  v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)v3, v5, v4, 0x10000u);
  v3->mNext = (UFG::allocator::free_link *)&UFG::CameraMarker::`vftable';
  UFG::SimComponent::AddType((UFG::SimComponent *)v3, UFG::CameraMarker::_CameraMarkerTypeUID, "CameraMarker");
  return v3;
}

// File Line: 408
// RVA: 0x23D7C0
float __fastcall UFG::CameraMarker::GetFovH(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&UFG::Editor::gsymFovH.mUID, DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 413
// RVA: 0x23D6C0
float __fastcall UFG::CameraMarker::GetDofFocalDist(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofFocalDist.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 418
// RVA: 0x23D700
float __fastcall UFG::CameraMarker::GetDofInFocusRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofInFocusRange.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 423
// RVA: 0x23D780
float __fastcall UFG::CameraMarker::GetDofNearRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofNearRange.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 428
// RVA: 0x23D740
float __fastcall UFG::CameraMarker::GetDofNearBlurRadius(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofNearBlurRadius.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 433
// RVA: 0x23D680
float __fastcall UFG::CameraMarker::GetDofFarRange(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofFarRange.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
}

// File Line: 438
// RVA: 0x23D640
float __fastcall UFG::CameraMarker::GetDofFarBlurRadius(UFG::CameraMarker *this)
{
  UFG::SceneObjectProperties *v1; // rdx
  UFG::qPropertySet *v2; // rcx
  __int128 v3; // xmm0

  v1 = this->m_pSimObject->m_pSceneObj;
  v2 = v1->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                          v2,
                          (UFG::qSymbol *)&UFG::Editor::gsymDofFarBlurRadius.mUID,
                          DEPTH_RECURSE);
  return *(float *)&v3;
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
  return atexit(dynamic_atexit_destructor_for__UFG::AIMarker::s_AIFleeToPointList__);
}

// File Line: 462
// RVA: 0x1470D70
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIJumpPointList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIMarker::s_AIJumpPointList__);
}

// File Line: 463
// RVA: 0x1470DD0
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIPathMarkerList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIMarker::s_AIPathMarkerList__);
}

// File Line: 464
// RVA: 0x1470E30
__int64 dynamic_initializer_for__UFG::AIMarker::s_AIReinforcementPointList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIMarker::s_AIReinforcementPointList__);
}

// File Line: 505
// RVA: 0x2373C0
void __fastcall UFG::AIMarker::AIMarker(UFG::AIMarker *this, UFG::qSymbol *name, UFG::AIMarker::EAIMarkerType type, UFG::SimObject *pSimObj)
{
  UFG::AIMarker::EAIMarkerType v4; // ebx
  UFG::AIMarker *v5; // rsi
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v6; // rdi
  UFG::AIMarker::EAIMarkerType v7; // ecx
  int v8; // ecx
  int v9; // ecx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v10; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v11; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v12; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v13; // rax

  v4 = type;
  v5 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x10000u);
  v6 = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIMarker::`vftable';
  v5->m_eType = v4;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v5->vfptr, UFG::AIMarker::_AIMarkerTypeUID, "AIMarker");
  v7 = v5->m_eType;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      v9 = v8 - 2;
      if ( v9 )
      {
        if ( v9 == 1 )
        {
          v10 = UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev;
          UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev->mNext = v6;
          v6->mPrev = v10;
          v5->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIReinforcementPointList;
          UFG::AIMarker::s_AIReinforcementPointList.mNode.mPrev = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v5->mPrev;
        }
      }
      else
      {
        v11 = UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev;
        UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev->mNext = v6;
        v6->mPrev = v11;
        v5->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIPathMarkerList;
        UFG::AIMarker::s_AIPathMarkerList.mNode.mPrev = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v5->mPrev;
      }
    }
    else
    {
      v12 = UFG::AIMarker::s_AIJumpPointList.mNode.mPrev;
      UFG::AIMarker::s_AIJumpPointList.mNode.mPrev->mNext = v6;
      v6->mPrev = v12;
      v5->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIJumpPointList;
      UFG::AIMarker::s_AIJumpPointList.mNode.mPrev = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v5->mPrev;
    }
  }
  else
  {
    v13 = UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev;
    UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev->mNext = v6;
    v6->mPrev = v13;
    v5->mNext = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&UFG::AIMarker::s_AIFleeToPointList;
    UFG::AIMarker::s_AIFleeToPointList.mNode.mPrev = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v5->mPrev;
  }
}

// File Line: 524
// RVA: 0x238110
void __fastcall UFG::AIMarker::~AIMarker(UFG::AIMarker *this)
{
  UFG::AIMarker *v1; // rbx
  UFG::AIMarker::EAIMarkerType v2; // ecx
  int v3; // ecx
  int v4; // ecx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v5; // rdx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v6; // rcx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v7; // rax
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v8; // rdx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v9; // rcx
  UFG::qNode<UFG::AIMarker,UFG::AIMarker> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIMarker::`vftable';
  v2 = this->m_eType;
  if ( v2 == EAIMarkerType_AIFleeToPoint || (v3 = v2 - 1) == 0 || (v4 = v3 - 2) == 0 || v4 == 1 )
  {
    v5 = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v1->mPrev;
    v6 = v1->mPrev;
    v7 = v1->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mNext = v5;
    v5->mPrev = v5;
  }
  v8 = (UFG::qNode<UFG::AIMarker,UFG::AIMarker> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MarkerBase::`vftable';
  if ( v1->mFlags & 0x10000 )
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::MarkerBase::msMarkers,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v1->mNode);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 538
// RVA: 0x23E350
bool __fastcall UFG::AIMarker::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *v1; // rbx
  UFG::SchemaDef *v2; // rax
  bool result; // al

  v1 = pSceneObj->mpWritableProperties;
  if ( !v1 )
    v1 = pSceneObj->mpConstProperties;
  v2 = UFG::PropertySetManager::GetSchema((UFG::qSymbol *)&SimSymX_propset_componentAIMarker.mUID);
  if ( v2 )
    result = UFG::qPropertySet::PropertyExists(v1, &v2->mPropertyName, DEPTH_RECURSE) != 0i64;
  else
    result = UFG::qPropertySet::GetParentFromName(
               v1,
               (UFG::qSymbol *)&SimSymX_propset_componentAIMarker.mUID,
               DEPTH_RECURSE) != 0i64;
  return result;
}

// File Line: 548
// RVA: 0x243E00
void __fastcall UFG::AIMarker::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // r14
  unsigned int v2; // eax
  UFG::AIMarker::EAIMarkerType v3; // esi
  UFG::qMemoryPool *v4; // rax
  UFG::allocator::free_link *v5; // rbp
  UFG::SimObject *v6; // rbx
  UFG::qSymbol *v7; // rax
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::allocator::free_link *v9; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = PropertyUtils::Get<UFG::qSymbol>(pSceneObj, (UFG::qSymbol *)&qSymbol_ObjectType.mUID)->mFlags;
  if ( v2 == UFG::symAIFleeToPoint.mUID )
  {
    v3 = 0;
  }
  else if ( v2 == UFG::symAIJumpPoint.mUID )
  {
    v3 = 1;
  }
  else if ( v2 == UFG::symAISeedPoint.mUID )
  {
    v3 = 2;
  }
  else if ( v2 == UFG::symAIPathMarker.mUID )
  {
    v3 = 3;
  }
  else
  {
    v3 = 0;
    if ( v2 == UFG::symAIReinforcementPoint.mUID )
      v3 = 4;
  }
  v4 = UFG::GetSimulationMemoryPool();
  v5 = UFG::qMemoryPool::Allocate(v4, 0x88ui64, "AIMarker", 0i64, 1u);
  v9 = v5;
  if ( v5 )
  {
    v6 = v1->m_pSimObject;
    v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v1->m_NameUID);
    UFG::AIMarker::AIMarker((UFG::AIMarker *)v5, v7, v3, v6);
  }
}

// File Line: 586
// RVA: 0x23E1A0
signed __int64 __fastcall UFG::AIMarker::GetType(UFG::AIMarker *this)
{
  UFG::AIMarker::EAIMarkerType v1; // edx
  int v2; // edx
  int v3; // edx
  int v4; // edx

  v1 = this->m_eType;
  if ( v1 )
  {
    v2 = v1 - 1;
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
  UFG::SimObject *v2; // rbx
  UFG::qPropertySet *v3; // rax
  UFG::TransformNodeComponent *v4; // rax

  v2 = pObject;
  if ( pObject )
  {
    while ( 1 )
    {
      v3 = PropertyUtils::Get<float>(v2->m_pSceneObj, (UFG::qSymbol *)&qSymbol_AIPathMarker_ArrivalTolerance.mUID);
      if ( !v3 )
        break;
      if ( *(float *)&v3->mFlags >= 0.0 )
        return *(float *)&v3->mFlags;
      v4 = v2->m_pTransformNodeComponent;
      if ( v4 )
        v4 = v4->mParent;
      if ( v4 )
      {
        v2 = v4->m_pSimObject;
        if ( v2 )
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
  UFG::SimObject *v3; // rdi
  UFG::qSymbol *v4; // rbx
  UFG::AIMarker *v5; // rsi
  UFG::qPropertySet *v6; // rax
  unsigned int v7; // eax
  UFG::TransformNodeComponent *v8; // r8
  UFG::qSymbol resulta; // [rsp+40h] [rbp+18h]

  v3 = pObject;
  v4 = result;
  v5 = this;
  if ( !pObject
    || (v6 = PropertyUtils::Get<UFG::qSymbol>(pObject->m_pSceneObj, (UFG::qSymbol *)&qSymbol_AIPathMarker_Speed.mUID)) == 0i64 )
  {
LABEL_8:
    v7 = UFG::MoveTypeSymbols[0].mUID;
    goto LABEL_9;
  }
  v7 = v6->mFlags;
  if ( v7 == UFG::MoveTypeSymbols[0].mUID )
  {
    v8 = v3->m_pTransformNodeComponent;
    if ( v8 )
      v8 = v8->mParent;
    if ( v8 )
      UFG::AIMarker::GetSpeed(v5, &resulta, v8->m_pSimObject);
    goto LABEL_8;
  }
LABEL_9:
  v4->mUID = v7;
  return v4;
}

// File Line: 681
// RVA: 0x23D900
__int64 __fastcall UFG::AIMarker::GetMoveType(UFG::AIMarker *this, UFG::SimObject *pObject)
{
  __int64 v2; // rax
  UFG::qStaticSymbol *v3; // rdx
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  UFG::AIMarker::GetSpeed(this, &result, pObject);
  v2 = 0i64;
  v3 = UFG::MoveTypeSymbols;
  while ( result.mUID != v3->mUID )
  {
    ++v3;
    v2 = (unsigned int)(v2 + 1);
    if ( (signed __int64)v3 >= (signed __int64)&UI_HASH_STATS_3 )
      return 0i64;
  }
  return v2;
}

