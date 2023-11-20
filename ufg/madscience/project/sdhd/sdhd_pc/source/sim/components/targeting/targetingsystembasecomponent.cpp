// File Line: 35
// RVA: 0x15440C0
__int64 dynamic_initializer_for__UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList__);
}

// File Line: 36
// RVA: 0x532590
const char *__fastcall UFG::TargetingSystemBaseComponent::GetTypeName(UFG::TargetingSystemBaseComponent *this)
{
  return "TargetingSystemBaseComponent";
}

// File Line: 66
// RVA: 0x5506E0
void UFG::TargetingSystemBaseComponent::StaticInit(void)
{
  UFG::TargetingSystemPedBaseComponent::StaticInit();
  UFG::TargetingSystemPedNPCCombatantComponent::StaticInit();
  UFG::TargetingSystemPedNPCAmbientComponent::StaticInit();
  UFG::TargetingSystemPedPlayerComponent::StaticInit();
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[1] = UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[54] = LOBYTE(UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                 + 1;
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[26] = LOBYTE(UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                 + 2;
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_Map.p[70] = LOBYTE(UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                 + 3;
  UFG::TargetingSystemItemComponent::ms_TargetingMap.m_uNumValidTargetTypes += 4;
  UFG::TargetingSystemVehicleComponent::StaticInit();
  UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[59] = UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes;
  UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_Map.p[60] = LOBYTE(UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes)
                                                                  + 1;
  UFG::TargetingSystemCraneComponent::ms_TargetingMap.m_uNumValidTargetTypes += 2;
}

// File Line: 127
// RVA: 0x519860
void __fastcall UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(UFG::TargetingSystemBaseComponent *this, UFG::TargetingMap *pTargetingMap, unsigned int name_uid, UFG::qPropertySet *properties)
{
  UFG::TargetingMap *v4; // rbx
  UFG::TargetingSystemBaseComponent *v5; // rdi
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v6; // rdx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v7; // rax
  unsigned __int64 v8; // rsi
  signed __int64 v9; // rax
  unsigned __int8 v10; // cf
  unsigned __int64 v11; // rax
  UFG::allocator::free_link *v12; // rax
  signed __int64 v13; // rbx
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *v14; // [rsp+58h] [rbp+10h]

  v4 = pTargetingMap;
  v5 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable';
  v6 = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&v5->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  v5->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemBaseComponent::`vftable'{for `UFG::SimComponent'};
  v5->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemBaseComponent::`vftable'{for `UFG::UpdateInterface'};
  v5->m_pTargetingMap = v4;
  v14 = &v5->m_TargetedBy;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v7 = UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&v5->mPrev;
  v6->mPrev = v7;
  v5->mNext = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList;
  UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&v5->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v5->vfptr,
    UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID,
    "TargetingSystemBaseComponent");
  v8 = v5->m_pTargetingMap->m_uNumValidTargetTypes;
  v9 = 56 * v8;
  if ( !is_mul_ok(v8, 0x38ui64) )
    v9 = -1i64;
  v10 = __CFADD__(v9, 8i64);
  v11 = v9 + 8;
  if ( v10 )
    v11 = -1i64;
  v12 = UFG::qMalloc(v11, "TargetingSystemBaseComponent.TargetingSimObject", 0i64);
  if ( v12 )
  {
    LODWORD(v12->mNext) = v8;
    v13 = (signed __int64)&v12[1];
    `eh vector constructor iterator'(
      &v12[1],
      0x38ui64,
      v8,
      (void (__fastcall *)(void *))UFG::TargetingSimObject::TargetingSimObject);
  }
  else
  {
    v13 = 0i64;
  }
  v5->m_pTargets = (UFG::TargetingSimObject *)v13;
  UFG::TargetingSystemBaseComponent::initialize(v5);
}

// File Line: 140
// RVA: 0x51CCA0
void __fastcall UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent(UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSystemBaseComponent *v1; // rdi
  UFG::TargetingSimObject *v2; // rcx
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *v3; // rbx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v4; // r9
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v5; // rcx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v6; // rax
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *v7; // r8
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *v8; // rdx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v9; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v10; // rax
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v11; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v12; // rax
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v13; // rcx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v14; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemBaseComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemBaseComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::TargetingSystemBaseComponent::shutdown(this);
  v2 = v1->m_pTargets;
  if ( v2 )
  {
    v3 = &v2[-1].m_eTargetType;
    `eh vector destructor iterator'(
      v2,
      0x38ui64,
      *(_DWORD *)&v2[-1].m_eTargetType.mValue,
      (void (__fastcall *)(void *))UFG::TargetingSimObject::~TargetingSimObject);
    operator delete[](v3);
  }
  if ( v1 == UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator )
    UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator = (UFG::TargetingSystemBaseComponent *)&v1->mPrev[-5].mNext;
  v4 = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
  v7 = &v1->m_TargetedBy;
  v8 = (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)v1->m_TargetedBy.mNode.mNext;
  if ( v8 != &v1->m_TargetedBy )
  {
    do
    {
      v9 = v8->mNode.mPrev;
      v10 = v8->mNode.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mNode.mPrev = &v8->mNode;
      v8->mNode.mNext = &v8->mNode;
      v8 = (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)v1->m_TargetedBy.mNode.mNext;
    }
    while ( v8 != v7 );
  }
  v11 = v7->mNode.mPrev;
  v12 = v1->m_TargetedBy.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v7->mNode.mPrev = &v7->mNode;
  v1->m_TargetedBy.mNode.mNext = &v1->m_TargetedBy.mNode;
  v13 = v4->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v4->mPrev = v4;
  v1->mNext = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 151
// RVA: 0x56A000
void __fastcall UFG::TargetingSystemBaseComponent::initialize(UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSystemBaseComponent *v1; // rsi
  __int64 v2; // rbx
  unsigned __int8 v3; // cl
  signed __int64 v4; // rdi
  UFG::TargetingSimObject *v5; // rax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl

  v1 = this;
  v2 = 0i64;
  do
  {
    v3 = v1->m_pTargetingMap->m_Map.p[v2];
    if ( v3 )
    {
      v4 = v3;
      v1->m_pTargets[v4].m_pTSBC = v1;
      v1->m_pTargets[v4].m_eTargetType.mValue = v2;
      UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v4], 0i64);
      v5 = v1->m_pTargets;
      if ( v5[v4].m_bLock )
        v5[v4].m_bLock = 0;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (signed int)v2 < 91 );
  v6 = v1->m_pTargetingMap->m_Map.p[31];
  if ( v6 )
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v6], (UFG::SimObject *)&LocalPlayer->vfptr);
  v7 = v1->m_pTargetingMap->m_Map.p[1];
  if ( v7 )
    UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v7], v1->m_pSimObject);
}

// File Line: 188
// RVA: 0x56D660
void __fastcall UFG::TargetingSystemBaseComponent::shutdown(UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSystemBaseComponent *v1; // rsi
  __int64 v2; // rdi
  unsigned __int8 v3; // r8
  signed __int64 v4; // rbx
  UFG::TargetingSimObject *v5; // rax
  signed __int64 v6; // rdi
  __int64 *v7; // rax
  __int64 v8; // rdx
  _QWORD *v9; // rcx
  __int64 v10; // rsi
  unsigned __int8 v11; // cl
  signed __int64 v12; // rbx
  __int64 v13; // rax

  v1 = this;
  v2 = 0i64;
  do
  {
    v3 = v1->m_pTargetingMap->m_Map.p[v2];
    if ( v3 )
    {
      v4 = v3;
      UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v4], 0i64);
      v5 = v1->m_pTargets;
      if ( v5[v4].m_bLock )
        v5[v4].m_bLock = 0;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (signed int)v2 < 91 );
  v6 = (signed __int64)&v1->m_TargetedBy;
  if ( (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)v1->m_TargetedBy.mNode.mNext != &v1->m_TargetedBy )
  {
    do
    {
      v7 = *(__int64 **)v6;
      v8 = **(_QWORD **)v6;
      v9 = *(_QWORD **)(*(_QWORD *)v6 + 8i64);
      *(_QWORD *)(v8 + 8) = v9;
      *v9 = v8;
      *v7 = (__int64)v7;
      v7[1] = (__int64)v7;
      v10 = v7[2];
      if ( v10 )
      {
        v11 = *(_BYTE *)(*(_QWORD *)(v10 + 96) + *((unsigned __int8 *)v7 + 48) + 8i64);
        if ( v11 )
        {
          v12 = 56i64 * v11;
          UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v12 + *(_QWORD *)(v10 + 88)), 0i64);
          v13 = *(_QWORD *)(v10 + 88);
          if ( *(_BYTE *)(v12 + v13 + 49) )
            *(_BYTE *)(v12 + v13 + 49) = 0;
        }
      }
    }
    while ( *(_QWORD *)(v6 + 8) != v6 );
  }
}

// File Line: 227
// RVA: 0x528910
void __fastcall UFG::TargetingSystemBaseComponent::FindMatrix(UFG::TransformNodeComponent *pTNC, UFG::SimObject *pSimObject, UFG::qMatrix44 *matSimObject)
{
  UFG::qMatrix44 *v3; // rsi
  UFG::SimObject *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  unsigned __int16 v9; // cx
  unsigned int v10; // edx
  unsigned int v11; // er8
  signed __int64 v12; // rbx
  UFG::RigidBody *v13; // rbx
  unsigned int v14; // edx
  unsigned int v15; // er8
  unsigned int v16; // edx
  unsigned int v17; // er8
  unsigned int v18; // edx
  unsigned int v19; // er8
  float v20; // xmm1_4
  float v21; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v3 = matSimObject;
  v4 = pSimObject;
  v5 = pTNC;
  if ( pTNC )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTNC);
    v6 = v5->mWorldTransform.v1;
    v7 = v5->mWorldTransform.v2;
    v8 = v5->mWorldTransform.v3;
    v3->v0 = v5->mWorldTransform.v0;
    v3->v1 = v6;
    v3->v2 = v7;
    v3->v3 = v8;
    return;
  }
  if ( !pSimObject )
    goto LABEL_36;
  v9 = pSimObject->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = (unsigned int)pSimObject[1].vfptr;
    v11 = v4->m_Components.size;
    if ( v10 < v11 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v10];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v10;
        v12 += 16i64;
        if ( v10 >= v11 )
          goto LABEL_10;
      }
LABEL_11:
      v13 = *(UFG::RigidBody **)v12;
      goto LABEL_34;
    }
    goto LABEL_10;
  }
  if ( (v9 & 0x8000u) != 0 )
  {
    v14 = (unsigned int)pSimObject[1].vfptr;
    v15 = v4->m_Components.size;
    if ( v14 < v15 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v14];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v14;
        v12 += 16i64;
        if ( v14 >= v15 )
        {
          v13 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
LABEL_10:
    v13 = 0i64;
    goto LABEL_34;
  }
  if ( (v9 >> 13) & 1 )
  {
    v16 = (unsigned int)pSimObject[1].vfptr;
    v17 = v4->m_Components.size;
    if ( v16 < v17 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v16];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v16;
        v12 += 16i64;
        if ( v16 >= v17 )
        {
          v13 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  if ( (v9 >> 12) & 1 )
  {
    v18 = (unsigned int)pSimObject[1].vfptr;
    v19 = v4->m_Components.size;
    if ( v18 < v19 )
    {
      v12 = (signed __int64)&v4->m_Components.p[v18];
      while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
      {
        ++v18;
        v12 += 16i64;
        if ( v18 >= v19 )
        {
          v13 = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  v13 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(pSimObject, UFG::RigidBodyComponent::_TypeUID);
LABEL_34:
  if ( v13 )
  {
    UFG::RigidBody::GetTransform(v13, v3);
    UFG::RigidBody::GetCentreOfMass(v13, &result);
    v3->v3.w = 1.0;
    v20 = result.y;
    v3->v3.x = result.x;
    v21 = result.z;
    v3->v3.y = v20;
    v3->v3.z = v21;
    return;
  }
LABEL_36:
  UFG::qPrintf("WARNING: TargetingSystemBaseComponent::FindMatrix failed on SimObject: %s\n", v4);
}

// File Line: 252
// RVA: 0x5288E0
void __fastcall UFG::TargetingSystemBaseComponent::FindMatrix(UFG::SimObject *pSimObject, UFG::qMatrix44 *matSimObject)
{
  if ( pSimObject )
    UFG::TargetingSystemBaseComponent::FindMatrix(pSimObject->m_pTransformNodeComponent, pSimObject, matSimObject);
  else
    UFG::TargetingSystemBaseComponent::FindMatrix(0i64, 0i64, matSimObject);
}

// File Line: 260
// RVA: 0x549CB0
void __fastcall UFG::TargetingSystemBaseComponent::Reset(UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSystemBaseComponent *v1; // rbx

  v1 = this;
  UFG::TargetingSystemBaseComponent::shutdown(this);
  UFG::TargetingSystemBaseComponent::initialize(v1);
}

// File Line: 273
// RVA: 0x53E980
void __fastcall UFG::TargetingSystemBaseComponent::OnAttach(UFG::TargetingSystemBaseComponent *this, UFG::SimObject *pSimObject)
{
  UFG::TargetingSystemBaseComponent *v2; // rsi
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // cl
  UFG::SimObject *v5; // r8
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rbx
  unsigned int v8; // ecx
  unsigned int v9; // er9
  UFG::SimComponentHolder *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rdi
  hkSeekableStreamReader *v13; // rax

  v2 = this;
  v3 = this->m_pTargetingMap->m_Map.p[31];
  if ( v3 )
    UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v3], (UFG::SimObject *)&LocalPlayer->vfptr);
  v4 = v2->m_pTargetingMap->m_Map.p[1];
  if ( v4 )
    UFG::TargetingSimObject::SetTarget(&v2->m_pTargets[v4], v2->m_pSimObject);
  v5 = v2->m_pSimObject;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p->m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = v5->m_Components.p->m_pComponent;
      }
      else if ( (v6 >> 12) & 1 )
      {
        v8 = (unsigned int)v5[1].vfptr;
        v9 = v5->m_Components.size;
        if ( v8 >= v9 )
        {
LABEL_20:
          v7 = 0i64;
        }
        else
        {
          v10 = v5->m_Components.p;
          while ( (v10[v8].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~v10[v8].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v8 >= v9 )
              goto LABEL_20;
          }
          v7 = v10[v8].m_pComponent;
        }
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(v2->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v7 = v5->m_Components.p->m_pComponent;
    }
    if ( v7 )
    {
      v11 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
      v12 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
      if ( v11 )
      {
        v11->mNext = 0i64;
        v11[1].mNext = 0i64;
      }
      else
      {
        v12 = 0i64;
      }
      v7[3].m_SafePointerList.mNode.mNext = v12;
      v13 = Assembly::GetRCX(v2);
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::TargetingSystemBaseComponent::GetGrappleTarget_UEL;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v13;
    }
  }
}

// File Line: 288
// RVA: 0x540C00
void __fastcall UFG::TargetingSystemBaseComponent::OnDetach(UFG::TargetingSystemBaseComponent *this)
{
  UFG::SimObject *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rbx
  unsigned int v4; // er8
  unsigned int v5; // er9
  signed __int64 v6; // rdx

  v1 = this->m_pSimObject;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p->m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = v1->m_Components.p->m_pComponent;
      }
      else if ( (v2 >> 12) & 1 )
      {
        v4 = (unsigned int)v1[1].vfptr;
        v5 = v1->m_Components.size;
        if ( v4 >= v5 )
        {
LABEL_14:
          v3 = 0i64;
        }
        else
        {
          v6 = (signed __int64)&v1->m_Components.p[v4];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF )
          {
            ++v4;
            v6 += 16i64;
            if ( v4 >= v5 )
              goto LABEL_14;
          }
          v3 = *(UFG::SimComponent **)v6;
        }
      }
      else
      {
        v3 = UFG::SimObject::GetComponentOfType(v1, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v3 = v1->m_Components.p->m_pComponent;
    }
    if ( v3 )
    {
      operator delete[](v3[3].m_SafePointerList.mNode.mNext);
      v3[3].m_SafePointerList.mNode.mNext = 0i64;
    }
  }
}

// File Line: 305
// RVA: 0x54ED20
void __fastcall UFG::TargetingSystemBaseComponent::SetTarget(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eTargetType, UFG::SimObject *pSimObject)
{
  __int64 v3; // rdi
  UFG::TargetingMap *v4; // rdx
  UFG::SimObject *v5; // rbx
  UFG::TargetingSystemBaseComponent *v6; // rsi
  unsigned __int16 v7; // cx
  UFG::InterestPoint *v8; // rax
  signed __int64 v9; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rax

  v3 = (unsigned int)eTargetType;
  v4 = this->m_pTargetingMap;
  v5 = pSimObject;
  v6 = this;
  if ( v4->m_Map.p[v3] )
  {
    do
    {
      UFG::TargetingSimObject::SetTarget(&v6->m_pTargets[(unsigned __int8)v4->m_Map.p[(unsigned int)v3]], v5);
      if ( !v5 || (_DWORD)v3 != 26 )
        break;
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::InterestPoint *)v5->m_Components.p[25].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = (UFG::InterestPoint *)v5->m_Components.p[10].m_pComponent;
        else
          v8 = (UFG::InterestPoint *)((v7 >> 12) & 1 ? v5->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                              v5,
                                                                                              UFG::InterestPoint::_TypeUID));
      }
      else
      {
        v8 = (UFG::InterestPoint *)v5->m_Components.p[25].m_pComponent;
      }
      v9 = (signed __int64)&v6->m_pTargets[(unsigned __int8)v6->m_pTargetingMap->m_Map.p[27]];
      if ( *(_QWORD *)(v9 + 40) )
      {
        if ( *(_BYTE *)(v9 + 49) )
          break;
      }
      v10 = UFG::InterestPoint::GetParentObject(v8);
      v4 = v6->m_pTargetingMap;
      LODWORD(v3) = 27;
      v5 = (UFG::SimObject *)v10;
    }
    while ( v4->m_Map.p[27] );
  }
}

// File Line: 341
// RVA: 0x53C250
char __fastcall UFG::TargetingSystemBaseComponent::IsTargetedByType(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eTargetType)
{
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v2; // rax

  v2 = this->m_TargetedBy.mNode.mNext;
  if ( v2 == (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->m_TargetedBy )
    return 0;
  while ( LOBYTE(v2[3].mPrev) != eTargetType )
  {
    v2 = v2->mNext;
    if ( v2 == (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->m_TargetedBy )
      return 0;
  }
  return 1;
}

// File Line: 359
// RVA: 0x53C280
char __fastcall UFG::TargetingSystemBaseComponent::IsTargetedByTypeAndLocked(UFG::TargetingSystemBaseComponent *this, UFG::eTargetTypeEnum eTargetType)
{
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *i; // rax

  for ( i = this->m_TargetedBy.mNode.mNext;
        i != (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->m_TargetedBy;
        i = i->mNext )
  {
    if ( LOBYTE(i[3].mPrev) == eTargetType && i[2].mNext && BYTE1(i[3].mPrev) )
      return 1;
  }
  return 0;
}

// File Line: 429
// RVA: 0x576430
void __fastcall UFG::TargetingSystemBaseComponent::updateMySpawnPointTarget(UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSystemBaseComponent *v1; // rdi
  UFG::SceneObjectProperties *v2; // rbx
  UFG::SimObject *v3; // rbx
  unsigned __int16 v4; // dx
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  UFG::SimComponent *v8; // rax
  unsigned int v9; // er8
  unsigned int v10; // er9
  unsigned int v11; // er8
  unsigned int v12; // er9
  unsigned int v13; // er8
  unsigned int v14; // er9
  unsigned __int8 v15; // cl

  v1 = this;
  v2 = this->m_pSimObject->m_pSceneObj;
  if ( !v2 )
    return;
  v3 = v2->mpOwner.m_pPointer;
  if ( !v3 )
    return;
  v4 = v3->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = (unsigned int)v3[1].vfptr;
    v6 = v3->m_Components.size;
    if ( v5 < v6 )
    {
      v7 = (signed __int64)&v3->m_Components.p[v5];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v5;
        v7 += 16i64;
        if ( v5 >= v6 )
          goto LABEL_9;
      }
LABEL_10:
      v8 = *(UFG::SimComponent **)v7;
      goto LABEL_33;
    }
    goto LABEL_9;
  }
  if ( (v4 & 0x8000u) != 0 )
  {
    v9 = (unsigned int)v3[1].vfptr;
    v10 = v3->m_Components.size;
    if ( v9 < v10 )
    {
      v7 = (signed __int64)&v3->m_Components.p[v9];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v9;
        v7 += 16i64;
        if ( v9 >= v10 )
        {
          v8 = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
LABEL_9:
    v8 = 0i64;
    goto LABEL_33;
  }
  if ( (v4 >> 13) & 1 )
  {
    v11 = (unsigned int)v3[1].vfptr;
    v12 = v3->m_Components.size;
    if ( v11 < v12 )
    {
      v7 = (signed __int64)&v3->m_Components.p[v11];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v11;
        v7 += 16i64;
        if ( v11 >= v12 )
        {
          v8 = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if ( (v4 >> 12) & 1 )
  {
    v13 = (unsigned int)v3[1].vfptr;
    v14 = v3->m_Components.size;
    if ( v13 < v14 )
    {
      v7 = (signed __int64)&v3->m_Components.p[v13];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
      {
        ++v13;
        v7 += 16i64;
        if ( v13 >= v14 )
        {
          v8 = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v8 = UFG::SimObject::GetComponentOfType(v3, UFG::SpawnPoint::_TypeUID);
LABEL_33:
  if ( v8 )
  {
    v15 = v1->m_pTargetingMap->m_Map.p[61];
    if ( v15 )
      UFG::TargetingSimObject::SetTarget(&v1->m_pTargets[v15], v3);
  }
}

// File Line: 455
// RVA: 0x52DB90
UEL::Value *__fastcall UFG::TargetingSystemBaseComponent::GetGrappleTarget_UEL(UFG::TargetingSystemBaseComponent *this, UEL::Value *result)
{
  UFG::SimComponent *v2; // r9
  UEL::Value *v3; // rbx
  UFG::SimObject *v4; // rcx
  unsigned __int16 v5; // dx
  unsigned int v6; // er8
  unsigned int v7; // er10
  signed __int64 v8; // rdx
  unsigned int v9; // ecx

  v2 = 0i64;
  v3 = result;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  v4 = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[23]].m_pTarget.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v2 = v4->m_Components.p->m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v2 = v4->m_Components.p->m_pComponent;
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (unsigned int)v4[1].vfptr;
        v7 = v4->m_Components.size;
        if ( v6 < v7 )
        {
          v8 = (signed __int64)&v4->m_Components.p[v6];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF )
          {
            ++v6;
            v8 += 16i64;
            if ( v6 >= v7 )
              goto LABEL_17;
          }
          v2 = *(UFG::SimComponent **)v8;
        }
      }
      else
      {
        v2 = UFG::SimObject::GetComponentOfType(v4, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      v2 = v4->m_Components.p->m_pComponent;
    }
LABEL_17:
    if ( v2 )
    {
      v9 = UFG::gNullQSymbol.mUID;
      v3->type.mBaseType.mValue = 8;
      v3->type.mDetailedType.mUID = v9;
      v3->integer = (__int64)&v2[1].m_TypeUID;
    }
  }
  return v3;
}

// File Line: 1184
// RVA: 0x55EAE0
void __fastcall UFG::DebugTextGrid::UpdateColumnFormatData(UFG::DebugTextGrid *this)
{
  UFG::DebugTextGrid *v1; // r14
  int v2; // er15
  int v3; // ebp
  __int64 v4; // rdi
  UFG::DebugTextGrid::ColumnFormat *v5; // rsi
  char *v6; // rbx
  char *v7; // r9
  int v8; // eax
  __int64 *v9; // r8
  int v10; // eax
  int v11; // eax
  __int64 v12; // [rsp+28h] [rbp-50h]
  __int64 v13; // [rsp+30h] [rbp-48h]
  UFG::qString v14; // [rsp+38h] [rbp-40h]

  v1 = this;
  this->m_iTotalRowWidth = 0;
  v2 = 0;
  v3 = 0;
  if ( this->m_iNumColumns <= 0 )
  {
    this->m_iTotalRowLength = 0;
  }
  else
  {
    v4 = 0i64;
    do
    {
      v5 = v1->m_pColumnFormats;
      v6 = v1->m_pColumnFormats[v4].m_ColumnDataFormat.mData;
      v7 = &v6[v1->m_pColumnFormats[v4].m_ColumnDataFormat.mLength];
      if ( v6 <= v7 )
      {
        while ( *v6 != 37 )
        {
          if ( ++v6 > v7 )
            goto LABEL_10;
        }
        for ( ; v6 <= v7; ++v6 )
        {
          if ( *v6 >= 65 && *v6 <= 90 || *v6 >= 97 && *v6 <= 122 )
            break;
        }
      }
LABEL_10:
      UFG::qString::qString(&v14);
      v8 = *v6;
      if ( *v6 <= 122 && *v6 >= 97 )
        v8 -= 32;
      if ( v8 == 83 )
      {
        v9 = (__int64 *)&customWorldMapCaption;
      }
      else
      {
        v10 = *v6;
        if ( *v6 <= 122 && *v6 >= 97 )
          v10 = *v6 - 32;
        if ( v10 == 86 )
        {
          v12 = 0i64;
          v13 = 0i64;
          v9 = &v12;
        }
        else
        {
          v9 = 0i64;
        }
      }
      UFG::qString::Format(&v14, v5[v4].m_ColumnDataFormat.mData, v9);
      v5[v4].m_iColumnWidth = v14.mLength;
      UFG::qString::~qString(&v14);
      v11 = v5[v4].m_iColumnWidth + 1;
      v5[v4].m_iColumnOffset = v2;
      v2 += v11;
      if ( v5[v4].m_bColumnVisible )
        v1->m_iTotalRowWidth += v11;
      ++v3;
      ++v4;
    }
    while ( v3 < v1->m_iNumColumns );
    v1->m_iTotalRowLength = v2;
  }
}

// File Line: 1920
// RVA: 0x53F4C0
void __fastcall UFG::OnClickSimObject(UFG::DebugTextGrid *debugTextGrid, int iRow, int iColumn, UFG::DebugTextGrid::ElementData *elementData)
{
  UFG::qSymbolUC *v4; // rcx
  char *v5; // rax

  v4 = (UFG::qSymbolUC *)elementData->m_pUserData;
  if ( v4 )
  {
    v5 = UFG::qSymbol::as_cstr_dbg(v4 + 18);
    UFG::qPrintf("Sim Object Clicked: %s\n", v5);
  }
}

// File Line: 1932
// RVA: 0x1549CF0
__int64 UFG::_dynamic_initializer_for__ms_TargetingColumnFormats__()
{
  UFG::allocator::free_link *v0; // rax

  UFG::qString::qString(&stru_142087DE0);
  UFG::qString::qString(&stru_142087E08);
  UFG::qString::qString(&stru_142087E30);
  UFG::qString::Set(&stru_142087DE0, "%3d");
  UFG::qString::Set(&stru_142087E08, "%3d");
  unk_142087E58.m_pColumnName = "IDX";
  unk_142087E60 = 0;
  unk_142087E68 = 0i64;
  unk_142087E70 = 0i64;
  UFG::qString::qString(&stru_142087E78);
  UFG::qString::qString(&stru_142087EA0);
  UFG::qString::qString(&stru_142087EC8);
  UFG::qString::Set(&stru_142087E78, "%3d");
  UFG::qString::Set(&stru_142087EA0, "%3d");
  unk_142087EF0.m_pColumnName = "LOCK";
  unk_142087EF8 = 257;
  unk_142087F00 = 0i64;
  unk_142087F08 = 0i64;
  UFG::qString::qString(&stru_142087F10);
  UFG::qString::qString(&stru_142087F38);
  UFG::qString::qString(&stru_142087F60);
  UFG::qString::Set(&stru_142087F10, "%-4s");
  UFG::qString::Set(&stru_142087F38, "%-4s");
  unk_142087F88.m_pColumnName = "REP";
  unk_142087F90 = 0;
  unk_142087F98 = 0i64;
  unk_142087FA0 = 0i64;
  UFG::qString::qString(&stru_142087FA8);
  UFG::qString::qString(&stru_142087FD0);
  UFG::qString::qString(&stru_142087FF8);
  UFG::qString::Set(&stru_142087FA8, "%-3s");
  UFG::qString::Set(&stru_142087FD0, "%-3s");
  unk_142088020.m_pColumnName = "TARGET TYPE";
  unk_142088028 = 257;
  unk_142088030 = 0i64;
  unk_142088038 = 0i64;
  UFG::qString::qString(&stru_142088040);
  UFG::qString::qString(&stru_142088068);
  UFG::qString::qString(&stru_142088090);
  UFG::qString::Set(&stru_142088040, "%-31s");
  UFG::qString::Set(&stru_142088068, "%-31s");
  v0 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
  if ( v0 )
  {
    v0->mNext = 0i64;
    v0[1].mNext = 0i64;
    if ( UFG::OnClickSimObject )
    {
      v0[1].mNext = (UFG::allocator::free_link *)fastdelegate::FastDelegate5<UFG::DebugTextGrid &,int,int,UFG::DebugTextGrid::ElementData &,char const *,void>::InvokeStaticFunction;
      v0->mNext = v0;
    }
    else
    {
      v0[1].mNext = 0i64;
    }
    v0->mNext = (UFG::allocator::free_link *)UFG::OnClickSimObject;
  }
  else
  {
    v0 = 0i64;
  }
  unk_1420880B8.m_pColumnName = "(S)IMOBJECT";
  unk_1420880C0 = 257;
  unk_1420880C8 = v0;
  unk_1420880D0 = 0i64;
  UFG::qString::qString(&stru_1420880D8);
  UFG::qString::qString(&stru_142088100);
  UFG::qString::qString(&stru_142088128);
  UFG::qString::Set(&stru_1420880D8, "%-50.50s");
  UFG::qString::Set(&stru_142088100, "%-50.50s");
  unk_142088150.m_pColumnName = "DIST 2D";
  unk_142088158 = 0;
  unk_142088160 = 0i64;
  unk_142088168 = 0i64;
  UFG::qString::qString(&stru_142088170);
  UFG::qString::qString(&stru_142088198);
  UFG::qString::qString(&stru_1420881C0);
  UFG::qString::Set(&stru_142088170, "%8.3fm");
  UFG::qString::Set(&stru_142088198, "%8.3fm");
  unk_1420881E8.m_pColumnName = "DIST 3D";
  unk_1420881F0 = 257;
  unk_1420881F8 = 0i64;
  unk_142088200 = 0i64;
  UFG::qString::qString(&stru_142088208);
  UFG::qString::qString(&stru_142088230);
  UFG::qString::qString(&stru_142088258);
  UFG::qString::Set(&stru_142088208, "%8.3fm");
  UFG::qString::Set(&stru_142088230, "%8.3fm");
  unk_142088280.m_pColumnName = "DIST Z";
  unk_142088288 = 0;
  unk_142088290 = 0i64;
  unk_142088298 = 0i64;
  UFG::qString::qString(&stru_1420882A0);
  UFG::qString::qString(&stru_1420882C8);
  UFG::qString::qString(&stru_1420882F0);
  UFG::qString::Set(&stru_1420882A0, "%8.3fm");
  UFG::qString::Set(&stru_1420882C8, "%8.3fm");
  unk_142088318.m_pColumnName = "FACING DIFF";
  unk_142088320 = 0;
  unk_142088328 = 0i64;
  unk_142088330 = 0i64;
  UFG::qString::qString(&stru_142088338);
  UFG::qString::qString(&stru_142088360);
  UFG::qString::qString(&stru_142088388);
  UFG::qString::Set(&stru_142088338, "%8.3fdeg");
  UFG::qString::Set(&stru_142088360, "%8.3fdeg");
  unk_1420883B0.m_pColumnName = "ANG DIFF";
  unk_1420883B8 = 0;
  unk_1420883C0 = 0i64;
  unk_1420883C8 = 0i64;
  UFG::qString::qString(&stru_1420883D0);
  UFG::qString::qString(&stru_1420883F8);
  UFG::qString::qString(&stru_142088420);
  UFG::qString::Set(&stru_1420883D0, "%8.3fdeg");
  UFG::qString::Set(&stru_1420883F8, "%8.3fdeg");
  unk_142088448 = "TIME DIFF";
  unk_142088450 = 0;
  unk_142088458 = 0i64;
  unk_142088460 = 0i64;
  UFG::qString::qString(&stru_142088468);
  UFG::qString::qString(&stru_142088490);
  UFG::qString::qString(&stru_1420884B8);
  UFG::qString::Set(&stru_142088468, "%8.3fs");
  UFG::qString::Set(&stru_142088490, "%8.3fs");
  return atexit(UFG::_dynamic_atexit_destructor_for__ms_TargetingColumnFormats__);
}

// File Line: 1957
// RVA: 0x154A2A0
__int64 UFG::_dynamic_initializer_for__ms_TargetingDebugGrid__()
{
  unsigned __int64 v0; // rax
  __int64 v1; // r9
  UFG::DebugTextGrid::ColumnFormat *v2; // rdx
  UFG::qString v4; // [rsp+28h] [rbp-80h]
  UFG::qString v5; // [rsp+50h] [rbp-58h]
  UFG::qString v6; // [rsp+78h] [rbp-30h]

  unk_14208850C = (_DWORD)FLOAT_1_0;
  unk_142088510 = 0;
  unk_142088514 = 0;
  unk_142088518 = LODWORD(FLOAT_0_5);
  unk_14208851C = 0;
  unk_142088520 = 0;
  unk_142088524 = (_DWORD)FLOAT_1_0;
  unk_142088528 = LODWORD(FLOAT_0_34999999);
  unk_14208852C = 0;
  unk_142088530 = 0;
  unk_142088534 = 0;
  unk_142088538 = LODWORD(FLOAT_0_34999999);
  UFG::qString::qString(&stru_142088578);
  unk_1420885C0 = 0;
  v0 = 96i64;
  if ( !is_mul_ok(0xCui64, 8ui64) )
    v0 = -1i64;
  qword_1420885B8 = UFG::qMalloc(v0, "DebugTextGrid.TweakerColumnNames", 0i64);
  UFG::qString::qString(&v4, "%s\\Column Filter", "\\Targeting\\Targeting Debug");
  UFG::qString::qString(&v6, "%s\\Column Format", "\\Targeting\\Targeting Debug");
  UFG::qString::qString(&v5, "%s\\Column Visibility", "\\Targeting\\Targeting Debug");
  v1 = 0i64;
  v2 = ms_TargetingColumnFormats;
  do
  {
    *(_QWORD *)((char *)qword_1420885B8 + v1) = v2->m_pColumnName;
    ++v2;
    v1 += 8i64;
  }
  while ( (signed __int64)v2 < (signed __int64)&ms_TargetingDebugGrid );
  UFG::qString::~qString(&v5);
  UFG::qString::~qString(&v6);
  UFG::qString::~qString(&v4);
  UFG::qString::qString(&v4, "%s\\Visual Layout", "\\Targeting\\Targeting Debug");
  UFG::qString::~qString(&v4);
  UFG::DebugTextGrid::UpdateColumnFormatData(&ms_TargetingDebugGrid);
  return atexit(UFG::_dynamic_atexit_destructor_for__ms_TargetingDebugGrid__);
}

