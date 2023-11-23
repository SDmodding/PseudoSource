// File Line: 21
// RVA: 0x1543880
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mVehicleType__()
{
  UFG::VehiclesBlipComponent::mVehicleType.mUID = UFG::gNullQSymbol.mUID;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mVehicleType__);
}

// File Line: 22
// RVA: 0x1543820
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mBlipType__()
{
  UFG::qString::qString(&UFG::VehiclesBlipComponent::mBlipType, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mBlipType__);
}

// File Line: 23
// RVA: 0x1543850
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::mMapCaption__()
{
  UFG::qString::qString(&UFG::VehiclesBlipComponent::mMapCaption, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::mMapCaption__);
}

// File Line: 26
// RVA: 0x15441C0
__int64 dynamic_initializer_for__UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList__);
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
void __fastcall UFG::VehiclesBlipComponent::VehiclesBlipComponent(
        UFG::VehiclesBlipComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent>;
  this->mNext = &this->UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehiclesBlipComponent::`vftable;
  mPrev = UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev;
  UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *)&UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList;
  UFG::VehiclesBlipComponent::s_VehiclesBlipComponentList.mNode.mPrev = &this->UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent>;
  UFG::SimComponent::AddType(this, UFG::VehiclesBlipComponent::_VehiclesBlipComponentTypeUID, "VehiclesBlipComponent");
}

// File Line: 37
// RVA: 0x51D5A0
void __fastcall UFG::VehiclesBlipComponent::~VehiclesBlipComponent(UFG::VehiclesBlipComponent *this)
{
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v2; // rdx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *mPrev; // rcx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *mNext; // rax
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v5; // rcx
  UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehiclesBlipComponent::`vftable;
  if ( this == UFG::VehiclesBlipComponent::s_VehiclesBlipComponentpCurrentIterator )
    UFG::VehiclesBlipComponent::s_VehiclesBlipComponentpCurrentIterator = (UFG::VehiclesBlipComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::VehiclesBlipComponent,UFG::VehiclesBlipComponent>;
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

// File Line: 43
// RVA: 0x53F340
void __fastcall UFG::VehiclesBlipComponent::OnAttach(UFG::VehiclesBlipComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *m_pSimObject; // rbx

  m_pSimObject = this->m_pSimObject;
  if ( UFG::VehiclesBlipComponent::mIsBlipOn && m_pSimObject )
  {
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType) )
      UFG::SimObjectUtility::AttachHudSymbol(
        m_pSimObject,
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
  UFG::SimObject *m_pSimObject; // rbx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType) )
      UFG::SimObjectUtility::DetachHudSymbol(m_pSimObject);
  }
}

// File Line: 71
// RVA: 0x526860
void __fastcall UFG::VehiclesBlipComponent::Enable(UFG::VehiclesBlipComponent *this, bool enable)
{
  UFG::SimObject *m_pSimObject; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v6; // rdx
  __int64 i; // rdx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject
    && (UFG::VehiclesBlipComponent::mVehicleType.mUID == -1
     || UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &UFG::VehiclesBlipComponent::mVehicleType)) )
  {
    vfptr = (unsigned int)m_pSimObject[1].vfptr;
    size = m_pSimObject->m_Components.size;
    if ( enable )
    {
      if ( vfptr >= size )
        goto LABEL_12;
      v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
           || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v6 += 16i64;
        if ( vfptr >= size )
          goto LABEL_12;
      }
      if ( !*(_QWORD *)v6 )
LABEL_12:
        UFG::SimObjectUtility::AttachHudSymbol(
          m_pSimObject,
          UFG::VehiclesBlipComponent::mBlipType.mData,
          0,
          0.0,
          UFG::VehiclesBlipComponent::mMapCaption.mData);
    }
    else if ( vfptr < size )
    {
      for ( i = (__int64)&m_pSimObject->m_Components.p[vfptr];
            (*(_DWORD *)(i + 8) & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
         || (UFG::HudComponent::_TypeUID & ~*(_DWORD *)(i + 8) & 0x1FFFFFF) != 0;
            i += 16i64 )
      {
        if ( ++vfptr >= size )
          return;
      }
      if ( *(_QWORD *)i )
        UFG::SimObjectUtility::DetachHudSymbol(m_pSimObject);
    }
  }
}

// File Line: 110
// RVA: 0x547170
UFG::VehiclesBlipComponent *__fastcall UFG::VehiclesBlipComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v13; // ebx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_VehiclesBlip::sPropertyName,
         DEPTH_RECURSE);
  if ( (!v5 || !UFG::qPropertySet::GetMemImagePtr(v5)) && !required )
    return 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x50ui64, "VehiclesBlipComponent", 0i64, 1u);
  if ( v8 )
  {
    UFG::VehiclesBlipComponent::VehiclesBlipComponent((UFG::VehiclesBlipComponent *)v8, pSceneObj->m_NameUID);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v13 = -1;
  else
    v13 = 29;
  UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v14, v10, v13);
  UFG::SimObjectModifier::Close(&v14);
  UFG::SimObjectModifier::~SimObjectModifier(&v14);
  return (UFG::VehiclesBlipComponent *)v10;
}

