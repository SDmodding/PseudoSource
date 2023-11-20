// File Line: 21
// RVA: 0x1543880
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mVehicleType__()
{
  UFG::VehiclesBlipComponent::mVehicleType.mUID = UFG::gNullQSymbol.mUID;
  return atexit(dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mVehicleType__);
}

// File Line: 22
// RVA: 0x1543820
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mBlipType__()
{
  UFG::qString::qString(&UFG::VehiclesBlipComponent::mBlipType, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mBlipType__);
}

// File Line: 23
// RVA: 0x1543850
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mMapCaption__()
{
  UFG::qString::qString(&UFG::VehiclesBlipComponent::mMapCaption, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mMapCaption__);
}

// File Line: 26
// RVA: 0x15441C0
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList__);
}

// File Line: 27
// RVA: 0x15437C0
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::VehiclesBlipComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::VehiclesBlipComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::VehiclesBlipComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::VehiclesBlipComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 30
// RVA: 0x51A130
void __fastcall UFG::VehiclesBlipComponent::VehiclesBlipComponent(UFG::VehiclesBlipComponent *this, unsigned int name_uid)
{
  UFG::VehiclesBlipComponent *v2; // rbx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v3; // rdx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehiclesBlipComponent::`vftable;
  v4 = UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev;
  UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList;
  UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::VehiclesBlipComponent::_VehiclesBlipComponentTypeUID,
    "VehiclesBlipComponent");
}

// File Line: 37
// RVA: 0x51D5A0
void __fastcall UFG::VehiclesBlipComponent::~VehiclesBlipComponent(UFG::VehiclesBlipComponent *this)
{
  UFG::VehiclesBlipComponent *v1; // r8
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v2; // rdx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v3; // rcx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v4; // rax
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v5; // rcx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehiclesBlipComponent::`vftable;
  if ( this == UFG::VehiclesBlipComponent::s_VehiclesBlipComponentpCurrentIterator )
    UFG::VehiclesBlipComponent::s_VehiclesBlipComponentpCurrentIterator = (UFG::VehiclesBlipComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&this->mPrev;
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

// File Line: 43
// RVA: 0x53F340
void __fastcall UFG::VehiclesBlipComponent::OnAttach(UFG::VehiclesBlipComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *v2; // rbx

  v2 = this->m_pSimObject;
  if ( UFG::VehiclesBlipComponent::mIsBlipOn && v2 )
  {
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType) )
      UFG::SimObjectUtility::AttachHudSymbol(
        v2,
        UFG::VehiclesBlipComponent::mBlipType.mData,
        0,
        0.0,
        UFG::VehiclesBlipComponent::mMapCaption.mData);
  }
}

// File Line: 58
// RVA: 0x5412A0
void __fastcall UFG::VehiclesBlipComponent::OnDetach(UFG::VehiclesBlipComponent *this)
{
  UFG::SimObject *v1; // rbx

  v1 = this->m_pSimObject;
  if ( v1 )
  {
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType) )
      UFG::SimObjectUtility::DetachHudSymbol(v1);
  }
}

// File Line: 71
// RVA: 0x526860
void __fastcall UFG::VehiclesBlipComponent::Enable(UFG::VehiclesBlipComponent *this, bool enable)
{
  UFG::SimObject *v2; // rbx
  bool v3; // di
  unsigned int v4; // er8
  unsigned int v5; // er9
  __int64 v6; // rdx
  signed __int64 v7; // rdx
  signed __int64 v8; // rdx

  v2 = this->m_pSimObject;
  v3 = enable;
  if ( v2
    && (UFG::VehiclesBlipComponent::mVehicleType.mUID == -1
     || UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType)) )
  {
    v4 = (unsigned int)v2[1].vfptr;
    v5 = v2->m_Components.size;
    v6 = LODWORD(v2[1].vfptr);
    if ( v3 )
    {
      if ( v4 >= v5 )
        goto LABEL_12;
      v7 = (signed __int64)&v2->m_Components.p[v6];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v4;
        v7 += 16i64;
        if ( v4 >= v5 )
          goto LABEL_12;
      }
      if ( !*(_QWORD *)v7 )
LABEL_12:
        UFG::SimObjectUtility::AttachHudSymbol(
          v2,
          UFG::VehiclesBlipComponent::mBlipType.mData,
          0,
          0.0,
          UFG::VehiclesBlipComponent::mMapCaption.mData);
    }
    else if ( v4 < v5 )
    {
      v8 = (signed __int64)&v2->m_Components.p[v6];
      while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
      {
        ++v4;
        v8 += 16i64;
        if ( v4 >= v5 )
          return;
      }
      if ( *(_QWORD *)v8 )
        UFG::SimObjectUtility::DetachHudSymbol(v2);
    }
  }
}

// File Line: 110
// RVA: 0x547170
UFG::SimComponent *__fastcall UFG::VehiclesBlipComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // di
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi
  UFG::SimObject *v11; // rdx
  unsigned __int16 v12; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_VehiclesBlip::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( (!v5 || !UFG::qPropertySet::GetMemImagePtr(v5)) && !v2 )
    return 0i64;
  v7 = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(v7, 0x50ui64, "VehiclesBlipComponent", 0i64, 1u);
  if ( v8 )
  {
    UFG::VehiclesBlipComponent::VehiclesBlipComponent((UFG::VehiclesBlipComponent *)v8, v3->m_NameUID);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = v3->m_pSimObject;
  v12 = v11->m_Flags;
  if ( (v12 >> 14) & 1 || (v12 & 0x8000u) == 0 )
    v13 = -1;
  else
    v13 = 29;
  UFG::SimObjectModifier::SimObjectModifier(&v14, v11, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v10, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return v10;
}

