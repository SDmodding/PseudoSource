// File Line: 23
// RVA: 0x155ED80
__int64 dynamic_initializer_for__UFG::UELComponent::s_UELComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UELComponent::s_UELComponentList__);
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
  UFG::UELComponent *v2; // rdi
  UFG::qNode<UFG::UELComponent,UFG::UELComponent> *v3; // rbx
  UFG::qNode<UFG::UELComponent,UFG::UELComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, uid);
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v3 = (UFG::qNode<UFG::UELComponent,UFG::UELComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::UELComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UELComponent::`vftable{for `UFG::UpdateInterface};
  v2->mParameters.PropertiesUELLookup.m_Closure.m_pthis = 0i64;
  v2->mParameters.PropertiesUELLookup.m_Closure.m_pFunction = 0i64;
  v2->mParameters.GangMember2UELGetter.m_Closure.m_pthis = 0i64;
  v2->mParameters.GangMember2UELGetter.m_Closure.m_pFunction = 0i64;
  v2->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  v2->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  v2->mParameters.RangedWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  v2->mParameters.RangedWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  v2->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pthis = 0i64;
  v2->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pFunction = 0i64;
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0>::RebindingComponentHandle<UFG::TriadWarsComponent,0>(&v2->mTriadWarsComponent);
  v4 = UFG::UELComponent::s_UELComponentList.mNode.mPrev;
  UFG::UELComponent::s_UELComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::UELComponent,UFG::UELComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::UELComponent,UFG::UELComponent> *)&UFG::UELComponent::s_UELComponentList;
  UFG::UELComponent::s_UELComponentList.mNode.mPrev = (UFG::qNode<UFG::UELComponent,UFG::UELComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v2->vfptr, UFG::UELComponent::_UELComponentTypeUID, "UELComponent");
}

// File Line: 47
// RVA: 0x5B7E30
bool __fastcall UFG::UELComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v3; // dx

  v1 = (UFG::SimObjectGame *)pSceneObj->m_pSimObject;
  if ( !v1 )
    return 0;
  v3 = v1->m_Flags;
  if ( (v3 >> 14) & 1 || (v3 & 0x8000u) != 0 )
    return v1->m_Components.p[7].m_pComponent != 0i64;
  if ( (v3 >> 13) & 1 )
    return v1->m_Components.p[6].m_pComponent != 0i64;
  if ( (v3 >> 12) & 1 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::ActionTreeComponent::_TypeUID) != 0i64;
  return UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::ActionTreeComponent::_TypeUID) != 0i64;
}

// File Line: 53
// RVA: 0x5BD1B0
UFG::SimComponent *__fastcall UFG::UELComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rsi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  unsigned int v4; // ebx
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x128ui64, "UELComponent", 0i64, 1u);
  v4 = 0;
  if ( v3 )
  {
    UFG::UELComponent::UELComponent((UFG::UELComponent *)v3, v1->m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  v8 = v7->m_Flags;
  if ( !((v8 >> 14) & 1) && (v8 & 0x8000u) == 0 && !((v8 >> 13) & 1) )
    v4 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v4);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v6;
}

// File Line: 68
// RVA: 0x5BCFE0
void __fastcall UFG::UELComponent::OnAttach(UFG::UELComponent *this, UFG::SimObject *object)
{
  UFG::UELComponent *v2; // rbx
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *v3; // rcx
  UFG::SimObject *v4; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rax
  hkSeekableStreamReader *v9; // rax
  hkSeekableStreamReader *v10; // rax
  hkSeekableStreamReader *v11; // rax
  hkSeekableStreamReader *v12; // rax
  hkSeekableStreamReader *v13; // rax

  v2 = this;
  v3 = &this->mTriadWarsComponent;
  v4 = object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mPrev;
    v6 = v3->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v3->m_pSimComponent = 0i64;
LABEL_7:
    v3->m_pSimObject = 0i64;
    v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
    goto LABEL_8;
  }
  if ( v3->m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *)v3->mPrev != v3
     || (UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *)v3->mNext != v3) )
  {
    v7 = v3->mPrev;
    v8 = v3->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    goto LABEL_7;
  }
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = v4;
  v3->m_TypeUID = UFG::TriadWarsComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0>::BindInternal<UFG::SimObject>(v3, v4);
  v9 = Assembly::GetRCX(v2);
  v2->mParameters.PropertiesUELLookup.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::LookupProperties;
  v2->mParameters.PropertiesUELLookup.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v9;
  v10 = Assembly::GetRCX(v2);
  v2->mParameters.GangMember2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterGangMember2;
  v2->mParameters.GangMember2UELGetter.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v10;
  v11 = Assembly::GetRCX(v2);
  v2->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterMeleeWeapon2;
  v2->mParameters.MeleeWeapon2UELGetter.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v11;
  v12 = Assembly::GetRCX(v2);
  v2->mParameters.RangedWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterRangedWeapon2;
  v2->mParameters.RangedWeapon2UELGetter.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v12;
  v13 = Assembly::GetRCX(v2);
  v2->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *))UFG::UELComponent::GetterThrownWeapon2;
  v2->mParameters.ThrownWeapon2UELGetter.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v13;
  v2->mParameters.Health = 0i64;
  v2->mParameters.Aiming = 0i64;
  v2->mParameters.Intention = 0i64;
  v2->mParameters.Character = 0i64;
  v2->mParameters.Item = 0i64;
  v2->mParameters.Targeting = 0i64;
  v2->mParameters.GangMember = 0i64;
  v2->mParameters.MeleeWeapon = 0i64;
  v2->mParameters.RangedWeapon = 0i64;
  v2->mParameters.ThrownWeapon = 0i64;
}

// File Line: 150
// RVA: 0x5BD140
void __fastcall UFG::UELComponent::OnDetach(UFG::UELComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->mTriadWarsComponent;
  if ( this->mTriadWarsComponent.m_pSimComponent )
  {
    v2 = this->mTriadWarsComponent.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->mTriadWarsComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::TriadWarsComponent,0> *)this->mTriadWarsComponent.mNext != &this->mTriadWarsComponent) )
    {
      v4 = this->mTriadWarsComponent.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 188
// RVA: 0x155EE00
__int64 dynamic_initializer_for__symGangMember2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("GangMemberStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symGangMember2, v0);
  return atexit(dynamic_atexit_destructor_for__symGangMember2__);
}

// File Line: 190
// RVA: 0x5B7CF0
UEL::Value *__fastcall UFG::UELComponent::GetterGangMember2(UFG::UELComponent *this, UEL::Value *result)
{
  UEL::Value *v2; // rbx
  unsigned int v3; // eax

  v2 = result;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v3 = symGangMember2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = v3;
  result->integer = (__int64)UFG::TriadWarsComponent::GetGangMemberStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return v2;
}

// File Line: 196
// RVA: 0x155EE40
__int64 dynamic_initializer_for__symMeleeWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symMeleeWeapon2, v0);
  return atexit(dynamic_atexit_destructor_for__symMeleeWeapon2__);
}

// File Line: 198
// RVA: 0x5B7D40
UEL::Value *__fastcall UFG::UELComponent::GetterMeleeWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  UEL::Value *v2; // rbx
  unsigned int v3; // eax

  v2 = result;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v3 = symMeleeWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = v3;
  result->integer = (__int64)UFG::TriadWarsComponent::GetMeleeWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return v2;
}

// File Line: 204
// RVA: 0x155EE80
__int64 dynamic_initializer_for__symRangedWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("RangedWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symRangedWeapon2, v0);
  return atexit(dynamic_atexit_destructor_for__symRangedWeapon2__);
}

// File Line: 206
// RVA: 0x5B7D90
UEL::Value *__fastcall UFG::UELComponent::GetterRangedWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  UEL::Value *v2; // rbx
  unsigned int v3; // eax

  v2 = result;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v3 = symRangedWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = v3;
  result->integer = (__int64)UFG::TriadWarsComponent::GetRangedWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return v2;
}

// File Line: 212
// RVA: 0x155EEC0
__int64 dynamic_initializer_for__symThrownWeapon2__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("ThrownWeaponStatData2", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symThrownWeapon2, v0);
  return atexit(dynamic_atexit_destructor_for__symThrownWeapon2__);
}

// File Line: 214
// RVA: 0x5B7DE0
UEL::Value *__fastcall UFG::UELComponent::GetterThrownWeapon2(UFG::UELComponent *this, UEL::Value *result)
{
  UEL::Value *v2; // rbx
  unsigned int v3; // eax

  v2 = result;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v3 = symThrownWeapon2.mUID;
  result->type.mBaseType.mValue = 8;
  result->type.mDetailedType.mUID = v3;
  result->integer = (__int64)UFG::TriadWarsComponent::GetThrownWeaponStatData2((UFG::TriadWarsComponent *)this->mTriadWarsComponent.m_pSimComponent);
  return v2;
}

// File Line: 222
// RVA: 0x5BCD20
UEL::Value *__fastcall UFG::UELComponent::LookupProperties(UFG::UELComponent *this, UEL::Value *result, UFG::qSymbol *symPropertyName)
{
  UEL::Value *v3; // rbx
  UFG::UELComponent *v4; // rdi
  UFG::qSymbol *v5; // rsi
  UFG::SceneObjectProperties *v6; // rdx
  UFG::qPropertySet *v7; // rcx
  unsigned int v8; // eax
  UFG::SceneObjectProperties *v9; // rdx
  UFG::qPropertySet *v10; // rcx
  int *v11; // rax
  __int64 v12; // rcx
  unsigned int v13; // eax
  UFG::SceneObjectProperties *v14; // rdx
  UFG::qPropertySet *v15; // rcx
  bool *v16; // rax
  bool v17; // cl
  unsigned int v18; // eax
  UFG::SceneObjectProperties *v19; // rdx
  UFG::qPropertySet *v20; // rcx
  float *v21; // rax
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
  const char *v36; // rcx

  v3 = result;
  v4 = this;
  result->type.mBaseType.mValue = 0;
  v5 = symPropertyName;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v6 = this->m_pSimObject->m_pSceneObj;
  v7 = v6->mpWritableProperties;
  if ( !v7 )
    v7 = v6->mpConstProperties;
  v8 = UFG::qPropertySet::GetPropertyTypeFromName(v7, symPropertyName, DEPTH_RECURSE);
  if ( v8 == 29 )
  {
    v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v5);
    v36 = "Warning: Couldnt find property %s when looking it up for an expression!\n";
LABEL_31:
    UFG::qPrintf(v36, v35);
  }
  else
  {
    switch ( v8 )
    {
      case 0u:
      case 1u:
      case 2u:
      case 5u:
      case 6u:
      case 7u:
      case 0xEu:
      case 0xFu:
        v9 = v4->m_pSimObject->m_pSceneObj;
        v10 = v9->mpWritableProperties;
        if ( !v10 )
          v10 = v9->mpConstProperties;
        v11 = UFG::qPropertySet::GetWithSchema<long>(v10, v5, DEPTH_RECURSE);
        if ( v11 )
        {
          v12 = *v11;
          v13 = UFG::gNullQSymbol.mUID;
          v3->type.mBaseType.mValue = 1;
          v3->type.mDetailedType.mUID = v13;
          v3->integer = v12;
        }
        break;
      case 9u:
        v14 = v4->m_pSimObject->m_pSceneObj;
        v15 = v14->mpWritableProperties;
        if ( !v15 )
          v15 = v14->mpConstProperties;
        v16 = UFG::qPropertySet::GetWithSchema<bool>(v15, v5, DEPTH_RECURSE);
        if ( v16 )
        {
          v17 = *v16;
          v18 = UFG::gNullQSymbol.mUID;
          v3->type.mBaseType.mValue = 5;
          v3->type.mDetailedType.mUID = v18;
          v3->boolean = v17 != 0;
        }
        break;
      case 0xAu:
      case 0xBu:
      case 0xDu:
        v19 = v4->m_pSimObject->m_pSceneObj;
        v20 = v19->mpWritableProperties;
        if ( !v20 )
          v20 = v19->mpConstProperties;
        v21 = UFG::qPropertySet::GetWithSchema<float>(v20, v5, DEPTH_RECURSE);
        if ( v21 )
        {
          v22 = *(_DWORD *)v21;
          v23 = UFG::gNullQSymbol.mUID;
          v3->type.mBaseType.mValue = 4;
          v3->type.mDetailedType.mUID = v23;
          v3->qSymbol_mUID = v22;
        }
        break;
      case 0xCu:
        v32 = v4->m_pSimObject->m_pSceneObj;
        v33 = v32->mpWritableProperties;
        if ( !v33 )
          v33 = v32->mpConstProperties;
        v34 = UFG::qPropertySet::GetWithSchema<char const *>(v33, v5, DEPTH_RECURSE);
        if ( v34 )
          UEL::Value::SetString(v3, v34);
        break;
      case 0x12u:
      case 0x13u:
        v24 = v4->m_pSimObject->m_pSceneObj;
        v25 = v24->mpWritableProperties;
        if ( !v25 )
          v25 = v24->mpConstProperties;
        v26 = UFG::qPropertySet::GetWithSchema<UFG::qVector4>(v25, v5, DEPTH_RECURSE);
        if ( v26 )
        {
          v27 = UFG::gNullQSymbol.mUID;
          v3->type.mBaseType.mValue = 7;
          v3->type.mDetailedType.mUID = v27;
          v3->qSymbol_mUID = LODWORD(v26->x);
          v3->qVector_y = v26->y;
          v3->qVector_z = v26->z;
          v3->qVector_w = v26->w;
        }
        break;
      case 0x16u:
      case 0x17u:
      case 0x18u:
        v28 = v4->m_pSimObject->m_pSceneObj;
        v29 = v28->mpWritableProperties;
        if ( !v29 )
          v29 = v28->mpConstProperties;
        v30 = UFG::qPropertySet::GetWithSchema<UFG::qSymbol>(v29, v5, DEPTH_RECURSE);
        if ( v30 )
        {
          v31 = UFG::gNullQSymbol.mUID;
          v3->type.mBaseType.mValue = 2;
          v3->type.mDetailedType.mUID = v31;
          LODWORD(v3->integer) = (UFG::qSymbol)v30->mUID;
        }
        break;
      default:
        v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v5);
        v36 = "Warning: Invalid property type for %s when looking it up for an expression!\n";
        goto LABEL_31;
    }
  }
  return v3;
}

