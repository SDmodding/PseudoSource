// File Line: 23
// RVA: 0x155ED80
__int64 dynamic_initializer_for__UFG::UELComponent::s_UELComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UELComponent::s_UELComponentList__);
}

// File Line: 24
// RVA: 0x5B7CD0
const char *__fastcall UFG::UELComponent::GetTypeName(UFG::UELComponent *this)
{
  return "UELComponent";
}

// File Line: 37
// RVA: 0x5B7AD0
void __fastcall UFG::UELComponent::UELComponent(UFG::UELComponent *this, unsigned int uid)
{
  UFG::qNode<UFG::UELComponent,UFG::UELComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::UELComponent,UFG::UELComponent>;
  this->mNext = &this->UFG::qNode<UFG::UELComponent,UFG::UELComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::UELComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UELComponent::`vftable{for `UFG::UpdateInterface};
  this->mParameters.PropertiesUELLookup.m_Closure.m_pthis = 0i64;
  this->mParameters.PropertiesUELLookup.m_Closure.m_pFunction = 0i64;
  this->mParameters.GangMember2UELGetter.m_Closure.m_pthis = 0i64;
  this->mParameters.GangMember2UELGetter.m_Closure.m_pFunction = 0i64;
  this->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  this->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  this->mParameters.RangedWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  this->mParameters.RangedWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  this->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  this->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0>::RebindingComponentHandle<UFG::TriadWarsComponent,0>(&this->mTriadWarsComponent);
  mPrev = UFG::UELComponent::s_UELComponentList.mNode.mPrev;
  UFG::UELComponent::s_UELComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::UELComponent,UFG::UELComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::UELComponent,UFG::UELComponent> *)&UFG::UELComponent::s_UELComponentList;
  UFG::UELComponent::s_UELComponentList.mNode.mPrev = &this->UFG::qNode<UFG::UELComponent,UFG::UELComponent>;
  UFG::SimComponent::AddType(this, UFG::UELComponent::_UELComponentTypeUID, "UELComponent");
}

// File Line: 47
// RVA: 0x5B7E30
bool __fastcall UFG::UELComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx

  m_pSimObject = (UFG::SimObjectGame *)pSceneObj->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return m_pSimObject->m_Components.p[7].m_pComponent != 0i64;
  if ( (m_Flags & 0x2000) != 0 )
    return m_pSimObject->m_Components.p[6].m_pComponent != 0i64;
  if ( (m_Flags & 0x1000) != 0 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::ActionTreeComponent::_TypeUID) != 0i64;
  return UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActionTreeComponent::_TypeUID) != 0i64;
}

// File Line: 53
// RVA: 0x5BD1B0
UFG::UELComponent *__fastcall UFG::UELComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  unsigned int v4; // ebx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x128ui64, "UELComponent", 0i64, 1u);
  v4 = 0;
  if ( v3 )
  {
    UFG::UELComponent::UELComponent((UFG::UELComponent *)v3, pSceneObj->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 && (m_Flags & 0x2000) == 0 )
    v4 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v4);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::UELComponent *)v6;
}

// File Line: 68
// RVA: 0x5BCFE0
void __fastcall UFG::UELComponent::OnAttach(UFG::UELComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *p_mTriadWarsComponent; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::detail::GenericClass *v10; // rax
  fastdelegate::detail::GenericClass *v11; // rax
  fastdelegate::detail::GenericClass *v12; // rax
  fastdelegate::detail::GenericClass *v13; // rax

  p_mTriadWarsComponent = &this->mTriadWarsComponent;
  if ( p_mTriadWarsComponent->m_pSimComponent )
  {
    mPrev = p_mTriadWarsComponent->mPrev;
    mNext = p_mTriadWarsComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTriadWarsComponent->m_pSimComponent = 0i64;
LABEL_7:
    p_mTriadWarsComponent->m_pSimObject = 0i64;
    p_mTriadWarsComponent->mNext = p_mTriadWarsComponent;
    p_mTriadWarsComponent->mPrev = p_mTriadWarsComponent;
    goto LABEL_8;
  }
  if ( p_mTriadWarsComponent->m_pSimObject
    && (p_mTriadWarsComponent->mPrev != p_mTriadWarsComponent || p_mTriadWarsComponent->mNext != p_mTriadWarsComponent) )
  {
    v7 = p_mTriadWarsComponent->mPrev;
    v8 = p_mTriadWarsComponent->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  p_mTriadWarsComponent->m_Changed = 1;
  p_mTriadWarsComponent->m_pSimObject = object;
  p_mTriadWarsComponent->m_TypeUID = UFG::TriadWarsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0>::BindInternal<UFG::SimObject>(p_mTriadWarsComponent, object);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mParameters.PropertiesUELLookup.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::LookupProperties;
  this->mParameters.PropertiesUELLookup.m_Closure.m_pthis = RCX;
  v10 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mParameters.GangMember2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterGangMember2;
  this->mParameters.GangMember2UELGetter.m_Closure.m_pthis = v10;
  v11 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterMeleeWeapon2;
  this->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pthis = v11;
  v12 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mParameters.RangedWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterRangedWeapon2;
  this->mParameters.RangedWeapon2UELGetter.m_Closure.m_pthis = v12;
  v13 = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  this->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterThrownWeapon2;
  this->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pthis = v13;
  this->mParameters.Health = 0i64;
  this->mParameters.Aiming = 0i64;
  this->mParameters.Intention = 0i64;
  this->mParameters.Character = 0i64;
  this->mParameters.Item = 0i64;
  this->mParameters.Targeting = 0i64;
  this->mParameters.GangMember = 0i64;
  this->mParameters.MeleeWeapon = 0i64;
  this->mParameters.RangedWeapon = 0i64;
  this->mParameters.ThrownWeapon = 0i64;
}

// File Line: 150
// RVA: 0x5BD140
void __fastcall UFG::UELComponent::OnDetach(UFG::UELComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *p_mTriadWarsComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_mTriadWarsComponent = &this->mTriadWarsComponent;
  if ( this->mTriadWarsComponent.m_pSimComponent )
  {
    mNext = this->mTriadWarsComponent.mNext;
    mPrev = p_mTriadWarsComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTriadWarsComponent->mNext = p_mTriadWarsComponent;
    p_mTriadWarsComponent->mPrev = p_mTriadWarsComponent;
    p_mTriadWarsComponent->m_Changed = 1;
    p_mTriadWarsComponent->m_pSimComponent = 0i64;
    p_mTriadWarsComponent->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mTriadWarsComponent.m_pSimObject
      && (p_mTriadWarsComponent->mPrev != p_mTriadWarsComponent
       || this->mTriadWarsComponent.mNext != &this->mTriadWarsComponent) )
    {
      v4 = this->mTriadWarsComponent.mNext;
      v5 = p_mTriadWarsComponent->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_mTriadWarsComponent->mNext = p_mTriadWarsComponent;
      p_mTriadWarsComponent->mPrev = p_mTriadWarsComponent;
      p_mTriadWarsComponent->m_pSimObject = 0i64;
    }
    p_mTriadWarsComponent->m_Changed = 1;
  }
}

// File Line: 188
// RVA: 0x155EE00
__int64 dynamic_initializer_for__symGangMember2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("GangMemberStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symGangMember2, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symGangMember2__);
}

// File Line: 190
// RVA: 0x5B7CF0
UEL::Value *__fastcall UFG::UELComponent::GetterGangMember2(UFG::UELComponent *this, UEL::Value *result)
{
  unsigned int mUID; // eax

  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = symGangMember2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = mUID;
  result->integer = (__int64)UFG::TriadWarsComponent::GetGangMemberStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return result;
}

// File Line: 196
// RVA: 0x155EE40
__int64 dynamic_initializer_for__symMeleeWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symMeleeWeapon2, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symMeleeWeapon2__);
}

// File Line: 198
// RVA: 0x5B7D40
UEL::Value *__fastcall UFG::UELComponent::GetterMeleeWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  unsigned int mUID; // eax

  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = symMeleeWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = mUID;
  result->integer = (__int64)UFG::TriadWarsComponent::GetMeleeWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return result;
}

// File Line: 204
// RVA: 0x155EE80
__int64 dynamic_initializer_for__symRangedWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RangedWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symRangedWeapon2, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symRangedWeapon2__);
}

// File Line: 206
// RVA: 0x5B7D90
UEL::Value *__fastcall UFG::UELComponent::GetterRangedWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  unsigned int mUID; // eax

  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = symRangedWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = mUID;
  result->integer = (__int64)UFG::TriadWarsComponent::GetRangedWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return result;
}

// File Line: 212
// RVA: 0x155EEC0
__int64 dynamic_initializer_for__symThrownWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ThrownWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symThrownWeapon2, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__symThrownWeapon2__);
}

// File Line: 214
// RVA: 0x5B7DE0
UEL::Value *__fastcall UFG::UELComponent::GetterThrownWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  unsigned int mUID; // eax

  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  mUID = symThrownWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = mUID;
  result->integer = (__int64)UFG::TriadWarsComponent::GetThrownWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return result;
}

// File Line: 222
// RVA: 0x5BCD20
UEL::Value *__fastcall UFG::UELComponent::LookupProperties(
        UFG::UELComponent *this,
        UEL::Value *result,
        UFG::qArray<unsigned long,0> *symPropertyName)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rdx
  UFG::qPropertySet *mpWritableProperties; // rcx
  unsigned int PropertyTypeFromName; // eax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::qPropertySet *mpConstProperties; // rcx
  int *v11; // rax
  __int64 v12; // rcx
  unsigned int mUID; // eax
  UFG::SceneObjectProperties *v14; // rdx
  UFG::qPropertySet *v15; // rcx
  bool *v16; // rax
  bool v17; // cl
  unsigned int v18; // eax
  UFG::SceneObjectProperties *v19; // rdx
  UFG::qPropertySet *v20; // rcx
  unsigned int *v21; // rax
  unsigned int v22; // xmm0_4
  unsigned int v23; // eax
  UFG::SceneObjectProperties *v24; // rdx
  UFG::qPropertySet *v25; // rcx
  UFG::qVector4 *v26; // rax
  unsigned int v27; // ecx
  UFG::SceneObjectProperties *v28; // rdx
  UFG::qPropertySet *v29; // rcx
  UFG::qSymbol *v30; // rax
  unsigned int v31; // ecx
  UFG::SceneObjectProperties *v32; // rdx
  UFG::qPropertySet *v33; // rcx
  char *v34; // rax
  char *v35; // rax
  char *v36; // rax

  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  PropertyTypeFromName = UFG::qPropertySet::GetPropertyTypeFromName(
                           mpWritableProperties,
                           symPropertyName,
                           DEPTH_RECURSE);
  if ( PropertyTypeFromName == 29 )
  {
    v36 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symPropertyName);
    UFG::qPrintf("Warning: Couldnt find property %s when looking it up for an expression!\n", v36);
  }
  else
  {
    switch ( PropertyTypeFromName )
    {
      case 0u:
      case 1u:
      case 2u:
      case 5u:
      case 6u:
      case 7u:
      case 0xEu:
      case 0xFu:
        v9 = this->m_pSimObject->m_pSceneObj;
        mpConstProperties = v9->mpWritableProperties;
        if ( !mpConstProperties )
          mpConstProperties = v9->mpConstProperties;
        v11 = UFG::qPropertySet::GetWithSchema<long>(mpConstProperties, (UFG::qSymbol *)symPropertyName, DEPTH_RECURSE);
        if ( v11 )
        {
          v12 = *v11;
          mUID = UFG::gNullQSymbol.mUID;
          result->type.mBaseType.mValue = 1;
          result->type.mDetailedType.mUID = mUID;
          result->integer = v12;
        }
        break;
      case 9u:
        v14 = this->m_pSimObject->m_pSceneObj;
        v15 = v14->mpWritableProperties;
        if ( !v15 )
          v15 = v14->mpConstProperties;
        v16 = UFG::qPropertySet::GetWithSchema<bool>(v15, (UFG::qSymbol *)symPropertyName, DEPTH_RECURSE);
        if ( v16 )
        {
          v17 = *v16;
          v18 = UFG::gNullQSymbol.mUID;
          result->type.mBaseType.mValue = 5;
          result->type.mDetailedType.mUID = v18;
          result->boolean = v17;
        }
        break;
      case 0xAu:
      case 0xBu:
      case 0xDu:
        v19 = this->m_pSimObject->m_pSceneObj;
        v20 = v19->mpWritableProperties;
        if ( !v20 )
          v20 = v19->mpConstProperties;
        v21 = (unsigned int *)UFG::qPropertySet::GetWithSchema<float>(
                                v20,
                                (UFG::qSymbol *)symPropertyName,
                                DEPTH_RECURSE);
        if ( v21 )
        {
          v22 = *v21;
          v23 = UFG::gNullQSymbol.mUID;
          result->type.mBaseType.mValue = 4;
          result->type.mDetailedType.mUID = v23;
          result->qSymbol_mUID = v22;
        }
        break;
      case 0xCu:
        v32 = this->m_pSimObject->m_pSceneObj;
        v33 = v32->mpWritableProperties;
        if ( !v33 )
          v33 = v32->mpConstProperties;
        v34 = UFG::qPropertySet::GetWithSchema<char const *>(v33, (UFG::qSymbol *)symPropertyName, DEPTH_RECURSE);
        if ( v34 )
          UEL::Value::SetString(result, v34);
        break;
      case 0x12u:
      case 0x13u:
        v24 = this->m_pSimObject->m_pSceneObj;
        v25 = v24->mpWritableProperties;
        if ( !v25 )
          v25 = v24->mpConstProperties;
        v26 = UFG::qPropertySet::GetWithSchema<UFG::qVector4>(v25, (UFG::qSymbol *)symPropertyName, DEPTH_RECURSE);
        if ( v26 )
        {
          v27 = UFG::gNullQSymbol.mUID;
          result->type.mBaseType.mValue = 7;
          result->type.mDetailedType.mUID = v27;
          result->qSymbol_mUID = LODWORD(v26->x);
          result->qVector_y = v26->y;
          result->qVector_z = v26->z;
          result->qVector_w = v26->w;
        }
        break;
      case 0x16u:
      case 0x17u:
      case 0x18u:
        v28 = this->m_pSimObject->m_pSceneObj;
        v29 = v28->mpWritableProperties;
        if ( !v29 )
          v29 = v28->mpConstProperties;
        v30 = UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(v29, (UFG::qSymbol *)symPropertyName, DEPTH_RECURSE);
        if ( v30 )
        {
          v31 = UFG::gNullQSymbol.mUID;
          result->type.mBaseType.mValue = 2;
          result->type.mDetailedType.mUID = v31;
          LODWORD(result->integer) = (UFG::qSymbol)v30->mUID;
        }
        break;
      default:
        v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)symPropertyName);
        UFG::qPrintf("Warning: Invalid property type for %s when looking it up for an expression!\n", v35);
        break;
    }
  }
  return result;
}

