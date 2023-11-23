// File Line: 35
// RVA: 0x15440C0
__int64 dynamic_initializer_for__UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList__);
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
void __fastcall UFG::TargetingSystemBaseComponent::TargetingSystemBaseComponent(
        UFG::TargetingSystemBaseComponent *this,
        UFG::TargetingMap *pTargetingMap,
        unsigned int name_uid,
        UFG::qPropertySet *properties)
{
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *mPrev; // rax
  unsigned __int64 m_uNumValidTargetTypes; // rsi
  __int64 v8; // rax
  bool v9; // cf
  unsigned __int64 v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::TargetingSimObject *v12; // rbx

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  this->mNext = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemBaseComponent::`vftable{for `UFG::UpdateInterface};
  this->m_pTargetingMap = pTargetingMap;
  this->m_TargetedBy.mNode.mPrev = &this->m_TargetedBy.mNode;
  this->m_TargetedBy.mNode.mNext = &this->m_TargetedBy.mNode;
  mPrev = UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev;
  UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *)&UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList;
  UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::TargetingSystemBaseComponent::_TargetingSystemBaseComponentTypeUID,
    "TargetingSystemBaseComponent");
  m_uNumValidTargetTypes = this->m_pTargetingMap->m_uNumValidTargetTypes;
  v8 = 56 * m_uNumValidTargetTypes;
  if ( !is_mul_ok(m_uNumValidTargetTypes, 0x38ui64) )
    v8 = -1i64;
  v9 = __CFADD__(v8, 8i64);
  v10 = v8 + 8;
  if ( v9 )
    v10 = -1i64;
  v11 = UFG::qMalloc(v10, "TargetingSystemBaseComponent.TargetingSimObject", 0i64);
  if ( v11 )
  {
    LODWORD(v11->mNext) = m_uNumValidTargetTypes;
    v12 = (UFG::TargetingSimObject *)&v11[1];
    `eh vector constructor iterator(
      &v11[1],
      0x38ui64,
      m_uNumValidTargetTypes,
      (void (__fastcall *)(void *))UFG::TargetingSimObject::TargetingSimObject);
  }
  else
  {
    v12 = 0i64;
  }
  this->m_pTargets = v12;
  UFG::TargetingSystemBaseComponent::initialize(this);
}

// File Line: 140
// RVA: 0x51CCA0
void __fastcall UFG::TargetingSystemBaseComponent::~TargetingSystemBaseComponent(
        UFG::TargetingSystemBaseComponent *this)
{
  UFG::TargetingSimObject *m_pTargets; // rcx
  qEnum<enum UFG::eTargetTypeEnum,unsigned char> *p_m_eTargetType; // rbx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v4; // r9
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *mPrev; // rcx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *mNext; // rax
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *p_m_TargetedBy; // r8
  UFG::TargetingSystemBaseComponent *v8; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v11; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v12; // rax
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v13; // rcx
  UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent> *v14; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TargetingSystemBaseComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TargetingSystemBaseComponent::`vftable{for `UFG::UpdateInterface};
  UFG::TargetingSystemBaseComponent::shutdown(this);
  m_pTargets = this->m_pTargets;
  if ( m_pTargets )
  {
    p_m_eTargetType = &m_pTargets[-1].m_eTargetType;
    `eh vector destructor iterator(
      m_pTargets,
      0x38ui64,
      *(_DWORD *)&m_pTargets[-1].m_eTargetType.mValue,
      (void (__fastcall *)(void *))UFG::TargetingSimObject::~TargetingSimObject);
    operator delete[](p_m_eTargetType);
  }
  if ( this == UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator )
    UFG::TargetingSystemBaseComponent::s_TargetingSystemBaseComponentpCurrentIterator = (UFG::TargetingSystemBaseComponent *)&this->mPrev[-5].mNext;
  v4 = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  this->mNext = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  p_m_TargetedBy = &this->m_TargetedBy;
  v8 = (UFG::TargetingSystemBaseComponent *)this->m_TargetedBy.mNode.mNext;
  if ( v8 != (UFG::TargetingSystemBaseComponent *)&this->m_TargetedBy )
  {
    do
    {
      vfptr = v8->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr;
      v10 = v8->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      vfptr[1].__vecDelDtor = (void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int))v10;
      v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)vfptr;
      v8->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v8;
      v8->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v8;
      v8 = (UFG::TargetingSystemBaseComponent *)this->m_TargetedBy.mNode.mNext;
    }
    while ( v8 != (UFG::TargetingSystemBaseComponent *)p_m_TargetedBy );
  }
  v11 = p_m_TargetedBy->mNode.mPrev;
  v12 = this->m_TargetedBy.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_m_TargetedBy->mNode.mPrev = &p_m_TargetedBy->mNode;
  this->m_TargetedBy.mNode.mNext = &this->m_TargetedBy.mNode;
  v13 = v4->mPrev;
  v14 = this->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v4->mPrev = v4;
  this->mNext = &this->UFG::qNode<UFG::TargetingSystemBaseComponent,UFG::TargetingSystemBaseComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 151
// RVA: 0x56A000
void __fastcall UFG::TargetingSystemBaseComponent::initialize(UFG::TargetingSystemBaseComponent *this)
{
  __int64 v2; // rbx
  unsigned __int8 v3; // cl
  __int64 v4; // rdi
  UFG::TargetingSimObject *m_pTargets; // rax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // cl

  v2 = 0i64;
  do
  {
    v3 = this->m_pTargetingMap->m_Map.p[v2];
    if ( v3 )
    {
      v4 = v3;
      this->m_pTargets[v4].m_pTSBC = this;
      this->m_pTargets[v4].m_eTargetType.mValue = v2;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v4], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v4].m_bLock )
        m_pTargets[v4].m_bLock = 0;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (int)v2 < 91 );
  v6 = this->m_pTargetingMap->m_Map.p[31];
  if ( v6 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v6], LocalPlayer);
  v7 = this->m_pTargetingMap->m_Map.p[1];
  if ( v7 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v7], this->m_pSimObject);
}

// File Line: 188
// RVA: 0x56D660
void __fastcall UFG::TargetingSystemBaseComponent::shutdown(UFG::TargetingSystemBaseComponent *this)
{
  __int64 v2; // rdi
  unsigned __int8 v3; // r8
  unsigned __int64 v4; // rbx
  UFG::TargetingSimObject *m_pTargets; // rax
  UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *p_m_TargetedBy; // rdi
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mPrev; // rax
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v8; // rdx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mNext; // rcx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v10; // rsi
  unsigned __int8 v11; // cl
  __int64 v12; // rbx
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *v13; // rax

  v2 = 0i64;
  do
  {
    v3 = this->m_pTargetingMap->m_Map.p[v2];
    if ( v3 )
    {
      v4 = v3;
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v4], 0i64);
      m_pTargets = this->m_pTargets;
      if ( m_pTargets[v4].m_bLock )
        m_pTargets[v4].m_bLock = 0;
    }
    v2 = (unsigned int)(v2 + 1);
  }
  while ( (int)v2 < 91 );
  p_m_TargetedBy = &this->m_TargetedBy;
  if ( (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)this->m_TargetedBy.mNode.mNext != &this->m_TargetedBy )
  {
    do
    {
      mPrev = p_m_TargetedBy->mNode.mPrev;
      v8 = p_m_TargetedBy->mNode.mPrev->mPrev;
      mNext = p_m_TargetedBy->mNode.mPrev->mNext;
      v8->mNext = mNext;
      mNext->mPrev = v8;
      mPrev->mPrev = mPrev;
      mPrev->mNext = mPrev;
      v10 = mPrev[1].mPrev;
      if ( v10 )
      {
        v11 = *((_BYTE *)&v10[6].mPrev->mNext + LOBYTE(mPrev[3].mPrev));
        if ( v11 )
        {
          v12 = 56i64 * v11;
          UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)((char *)v10[5].mNext + v12), 0i64);
          v13 = v10[5].mNext;
          if ( *((_BYTE *)&v13[3].mPrev + v12 + 1) )
            *((_BYTE *)&v13[3].mPrev + v12 + 1) = 0;
        }
      }
    }
    while ( (UFG::qList<UFG::TargetingSimObject,UFG::TargetingSimObject,0,0> *)p_m_TargetedBy->mNode.mNext != p_m_TargetedBy );
  }
}

// File Line: 227
// RVA: 0x528910
void __fastcall UFG::TargetingSystemBaseComponent::FindMatrix(
        UFG::TransformNodeComponent *pTNC,
        UFG::SimObject *pSimObject,
        UFG::qMatrix44 *matSimObject)
{
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  signed __int16 m_Flags; // cx
  unsigned int vfptr; // edx
  unsigned int size; // r8d
  UFG::SimComponentHolder *v12; // rbx
  UFG::RigidBody *m_pComponent; // rbx
  unsigned int v14; // edx
  unsigned int v15; // r8d
  unsigned int v16; // edx
  unsigned int v17; // r8d
  unsigned int v18; // edx
  unsigned int v19; // r8d
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( pTNC )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(pTNC);
    v6 = pTNC->mWorldTransform.v1;
    v7 = pTNC->mWorldTransform.v2;
    v8 = pTNC->mWorldTransform.v3;
    matSimObject->v0 = pTNC->mWorldTransform.v0;
    matSimObject->v1 = v6;
    matSimObject->v2 = v7;
    matSimObject->v3 = v8;
    return;
  }
  if ( !pSimObject )
    goto LABEL_36;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v12 = &pSimObject->m_Components.p[vfptr];
      while ( (v12->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || (UFG::RigidBodyComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v12;
        if ( vfptr >= size )
          goto LABEL_10;
      }
LABEL_11:
      m_pComponent = (UFG::RigidBody *)v12->m_pComponent;
      goto LABEL_34;
    }
    goto LABEL_10;
  }
  if ( m_Flags < 0 )
  {
    v14 = (unsigned int)pSimObject[1].vfptr;
    v15 = pSimObject->m_Components.size;
    if ( v14 < v15 )
    {
      v12 = &pSimObject->m_Components.p[v14];
      while ( (v12->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || (UFG::RigidBodyComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v14;
        ++v12;
        if ( v14 >= v15 )
        {
          m_pComponent = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
LABEL_10:
    m_pComponent = 0i64;
    goto LABEL_34;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v16 = (unsigned int)pSimObject[1].vfptr;
    v17 = pSimObject->m_Components.size;
    if ( v16 < v17 )
    {
      v12 = &pSimObject->m_Components.p[v16];
      while ( (v12->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || (UFG::RigidBodyComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v16;
        ++v12;
        if ( v16 >= v17 )
        {
          m_pComponent = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v18 = (unsigned int)pSimObject[1].vfptr;
    v19 = pSimObject->m_Components.size;
    if ( v18 < v19 )
    {
      v12 = &pSimObject->m_Components.p[v18];
      while ( (v12->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
           || (UFG::RigidBodyComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v18;
        ++v12;
        if ( v18 >= v19 )
        {
          m_pComponent = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  m_pComponent = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(pSimObject, UFG::RigidBodyComponent::_TypeUID);
LABEL_34:
  if ( m_pComponent )
  {
    UFG::RigidBody::GetTransform(m_pComponent, matSimObject);
    UFG::RigidBody::GetCentreOfMass(m_pComponent, &result);
    matSimObject->v3.w = 1.0;
    y = result.y;
    matSimObject->v3.x = result.x;
    z = result.z;
    matSimObject->v3.y = y;
    matSimObject->v3.z = z;
    return;
  }
LABEL_36:
  UFG::qPrintf("WARNING: TargetingSystemBaseComponent::FindMatrix failed on SimObject: %s\n", (const char *)pSimObject);
}n;
  }
LABEL_36:
  UFG::qPrintf("WARNING: TargetingSystem

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
  UFG::TargetingSystemBaseComponent::shutdown(this);
  UFG::TargetingSystemBaseComponent::initialize(this);
}

// File Line: 273
// RVA: 0x53E980
void __fastcall UFG::TargetingSystemBaseComponent::OnAttach(
        UFG::TargetingSystemBaseComponent *this,
        UFG::SimObject *pSimObject)
{
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // cl
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rdi
  hkSeekableStreamReader *RCX; // rax

  v3 = this->m_pTargetingMap->m_Map.p[31];
  if ( v3 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v3], LocalPlayer);
  v4 = this->m_pTargetingMap->m_Map.p[1];
  if ( v4 )
    UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v4], this->m_pSimObject);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_20:
          m_pComponent = 0i64;
        }
        else
        {
          p = m_pSimObject->m_Components.p;
          while ( (p[vfptr].m_TypeUID & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~p[vfptr].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++vfptr >= size )
              goto LABEL_20;
          }
          m_pComponent = p[vfptr].m_pComponent;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(this->m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
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
      m_pComponent[3].m_SafePointerList.mNode.mNext = v12;
      RCX = Assembly::GetRCX(this);
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)UFG::TargetingSystemBaseComponent::GetGrappleTarget_UEL;
      v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)RCX;
    }
  }
}

// File Line: 288
// RVA: 0x540C00
void __fastcall UFG::TargetingSystemBaseComponent::OnDetach(UFG::TargetingSystemBaseComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v6; // rdx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pSimObject[1].vfptr;
        size = m_pSimObject->m_Components.size;
        if ( vfptr >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v6 = (__int64)&m_pSimObject->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v6 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v6 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v6 += 16i64;
            if ( vfptr >= size )
              goto LABEL_14;
          }
          m_pComponent = *(UFG::SimComponent **)v6;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pSimObject->m_Components.p->m_pComponent;
    }
    if ( m_pComponent )
    {
      operator delete[](m_pComponent[3].m_SafePointerList.mNode.mNext);
      m_pComponent[3].m_SafePointerList.mNode.mNext = 0i64;
    }
  }
}

// File Line: 305
// RVA: 0x54ED20
void __fastcall UFG::TargetingSystemBaseComponent::SetTarget(
        UFG::TargetingSystemBaseComponent *this,
        unsigned int eTargetType,
        UFG::SimObject *pSimObject)
{
  __int64 v3; // rdi
  UFG::TargetingMap *m_pTargetingMap; // rdx
  signed __int16 m_Flags; // cx
  UFG::InterestPoint *m_pComponent; // rax
  UFG::TargetingSimObject *v9; // rdx
  UFG::SimObject *ParentObject; // rax

  v3 = eTargetType;
  m_pTargetingMap = this->m_pTargetingMap;
  if ( m_pTargetingMap->m_Map.p[v3] )
  {
    do
    {
      UFG::TargetingSimObject::SetTarget(
        &this->m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[(unsigned int)v3]],
        pSimObject);
      if ( !pSimObject || (_DWORD)v3 != 26 )
        break;
      m_Flags = pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InterestPoint *)pSimObject->m_Components.p[25].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = (UFG::InterestPoint *)pSimObject->m_Components.p[10].m_pComponent;
        else
          m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                              ? pSimObject->m_Components.p[3].m_pComponent
                                              : UFG::SimObject::GetComponentOfType(
                                                  pSimObject,
                                                  UFG::InterestPoint::_TypeUID));
      }
      else
      {
        m_pComponent = (UFG::InterestPoint *)pSimObject->m_Components.p[25].m_pComponent;
      }
      v9 = &this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[27]];
      if ( v9->m_pTarget.m_pPointer )
      {
        if ( v9->m_bLock )
          break;
      }
      ParentObject = (UFG::SimObject *)UFG::InterestPoint::GetParentObject(m_pComponent);
      m_pTargetingMap = this->m_pTargetingMap;
      LODWORD(v3) = 27;
      pSimObject = ParentObject;
    }
    while ( m_pTargetingMap->m_Map.p[27] );
  }
}

// File Line: 341
// RVA: 0x53C250
char __fastcall UFG::TargetingSystemBaseComponent::IsTargetedByType(
        UFG::TargetingSystemBaseComponent *this,
        UFG::eTargetTypeEnum eTargetType)
{
  UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *mNext; // rax

  mNext = this->m_TargetedBy.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->m_TargetedBy )
    return 0;
  while ( LOBYTE(mNext[3].mPrev) != eTargetType )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::TargetingSimObject,UFG::TargetingSimObject> *)&this->m_TargetedBy )
      return 0;
  }
  return 1;
}

// File Line: 359
// RVA: 0x53C280
char __fastcall UFG::TargetingSystemBaseComponent::IsTargetedByTypeAndLocked(
        UFG::TargetingSystemBaseComponent *this,
        UFG::eTargetTypeEnum eTargetType)
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
  UFG::SceneObjectProperties *m_pSceneObj; // rbx
  UFG::SimObject *m_pPointer; // rbx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  __int64 v7; // rdx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v9; // r8d
  unsigned int v10; // r9d
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  unsigned int v13; // r8d
  unsigned int v14; // r9d
  unsigned __int8 v15; // cl

  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  if ( !m_pSceneObj )
    return;
  m_pPointer = m_pSceneObj->mpOwner.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)m_pPointer[1].vfptr;
    size = m_pPointer->m_Components.size;
    if ( vfptr < size )
    {
      v7 = (__int64)&m_pPointer->m_Components.p[vfptr];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        v7 += 16i64;
        if ( vfptr >= size )
          goto LABEL_9;
      }
LABEL_10:
      ComponentOfType = *(UFG::SimComponent **)v7;
      goto LABEL_33;
    }
    goto LABEL_9;
  }
  if ( m_Flags < 0 )
  {
    v9 = (unsigned int)m_pPointer[1].vfptr;
    v10 = m_pPointer->m_Components.size;
    if ( v9 < v10 )
    {
      v7 = (__int64)&m_pPointer->m_Components.p[v9];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v9;
        v7 += 16i64;
        if ( v9 >= v10 )
        {
          ComponentOfType = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
LABEL_9:
    ComponentOfType = 0i64;
    goto LABEL_33;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v11 = (unsigned int)m_pPointer[1].vfptr;
    v12 = m_pPointer->m_Components.size;
    if ( v11 < v12 )
    {
      v7 = (__int64)&m_pPointer->m_Components.p[v11];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v11;
        v7 += 16i64;
        if ( v11 >= v12 )
        {
          ComponentOfType = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v13 = (unsigned int)m_pPointer[1].vfptr;
    v14 = m_pPointer->m_Components.size;
    if ( v13 < v14 )
    {
      v7 = (__int64)&m_pPointer->m_Components.p[v13];
      while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::SpawnPoint::_TypeUID & 0xFE000000)
           || (UFG::SpawnPoint::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF) != 0 )
      {
        ++v13;
        v7 += 16i64;
        if ( v13 >= v14 )
        {
          ComponentOfType = 0i64;
          goto LABEL_33;
        }
      }
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::SpawnPoint::_TypeUID);
LABEL_33:
  if ( ComponentOfType )
  {
    v15 = this->m_pTargetingMap->m_Map.p[61];
    if ( v15 )
      UFG::TargetingSimObject::SetTarget(&this->m_pTargets[v15], m_pPointer);
  }
}

// File Line: 455
// RVA: 0x52DB90
UEL::Value *__fastcall UFG::TargetingSystemBaseComponent::GetGrappleTarget_UEL(
        UFG::TargetingSystemBaseComponent *this,
        UEL::Value *result)
{
  UFG::SimComponent *m_pComponent; // r9
  UFG::SimObject *m_pPointer; // rcx
  __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  __int64 v8; // rdx
  unsigned int mUID; // ecx

  m_pComponent = 0i64;
  result->type.mBaseType.mValue = 0;
  result->type.mDetailedType = UFG::gNullQSymbol;
  m_pPointer = this->m_pTargets[(unsigned __int8)this->m_pTargetingMap->m_Map.p[23]].m_pTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p->m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p->m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        vfptr = (unsigned int)m_pPointer[1].vfptr;
        size = m_pPointer->m_Components.size;
        if ( vfptr < size )
        {
          v8 = (__int64)&m_pPointer->m_Components.p[vfptr];
          while ( (*(_DWORD *)(v8 + 8) & 0xFE000000) != (UFG::UELComponent::_TypeUID & 0xFE000000)
               || (UFG::UELComponent::_TypeUID & ~*(_DWORD *)(v8 + 8) & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            v8 += 16i64;
            if ( vfptr >= size )
              goto LABEL_17;
          }
          m_pComponent = *(UFG::SimComponent **)v8;
        }
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::UELComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p->m_pComponent;
    }
LABEL_17:
    if ( m_pComponent )
    {
      mUID = UFG::gNullQSymbol.mUID;
      result->type.mBaseType.mValue = 8;
      result->type.mDetailedType.mUID = mUID;
      result->integer = (__int64)&m_pComponent[1].m_TypeUID;
    }
  }
  return result;
}

// File Line: 1184
// RVA: 0x55EAE0
void __fastcall UFG::DebugTextGrid::UpdateColumnFormatData(UFG::DebugTextGrid *this)
{
  int v2; // r15d
  int v3; // ebp
  __int64 v4; // rdi
  UFG::DebugTextGrid::ColumnFormat *m_pColumnFormats; // rsi
  char *mData; // rbx
  char *v7; // r9
  int v8; // eax
  __int64 *v9; // r8
  int v10; // eax
  int v11; // eax
  __int64 v12[2]; // [rsp+28h] [rbp-50h] BYREF
  UFG::qString v13; // [rsp+38h] [rbp-40h] BYREF

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
      m_pColumnFormats = this->m_pColumnFormats;
      mData = this->m_pColumnFormats[v4].m_ColumnDataFormat.mData;
      v7 = &mData[this->m_pColumnFormats[v4].m_ColumnDataFormat.mLength];
      if ( mData <= v7 )
      {
        while ( *mData != 37 )
        {
          if ( ++mData > v7 )
            goto LABEL_10;
        }
        for ( ; mData <= v7; ++mData )
        {
          if ( *mData >= 65 && *mData <= 90 || *mData >= 97 && *mData <= 122 )
            break;
        }
      }
LABEL_10:
      UFG::qString::qString(&v13);
      v8 = *mData;
      if ( *mData <= 122 && *mData >= 97 )
        v8 -= 32;
      if ( v8 == 83 )
      {
        v9 = (__int64 *)&customCaption;
      }
      else
      {
        v10 = *mData;
        if ( *mData <= 122 && *mData >= 97 )
          v10 = *mData - 32;
        if ( v10 == 86 )
        {
          v12[0] = 0i64;
          v12[1] = 0i64;
          v9 = v12;
        }
        else
        {
          v9 = 0i64;
        }
      }
      UFG::qString::Format(&v13, m_pColumnFormats[v4].m_ColumnDataFormat.mData, v9);
      m_pColumnFormats[v4].m_iColumnWidth = v13.mLength;
      UFG::qString::~qString(&v13);
      v11 = m_pColumnFormats[v4].m_iColumnWidth + 1;
      m_pColumnFormats[v4].m_iColumnOffset = v2;
      v2 += v11;
      if ( m_pColumnFormats[v4].m_bColumnVisible )
        this->m_iTotalRowWidth += v11;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_iNumColumns );
    this->m_iTotalRowLength = v2;
  }
}

// File Line: 1920
// RVA: 0x53F4C0
void __fastcall UFG::OnClickSimObject(
        UFG::DebugTextGrid *debugTextGrid,
        int iRow,
        int iColumn,
        UFG::DebugTextGrid::ElementData *elementData)
{
  UFG::qSymbolUC *m_pUserData; // rcx
  char *v5; // rax

  m_pUserData = (UFG::qSymbolUC *)elementData->m_pUserData;
  if ( m_pUserData )
  {
    v5 = UFG::qSymbol::as_cstr_dbg(m_pUserData + 18);
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ms_TargetingColumnFormats__);
}

// File Line: 1957
// RVA: 0x154A2A0
__int64 UFG::_dynamic_initializer_for__ms_TargetingDebugGrid__()
{
  unsigned __int64 v0; // rax
  __int64 v1; // r9
  UFG::DebugTextGrid::ColumnFormat *v2; // rdx
  UFG::qString v4; // [rsp+28h] [rbp-80h] BYREF
  UFG::qString v5; // [rsp+50h] [rbp-58h] BYREF
  UFG::qString v6; // [rsp+78h] [rbp-30h] BYREF

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
  while ( (__int64)v2 < (__int64)&ms_TargetingDebugGrid );
  UFG::qString::~qString(&v5);
  UFG::qString::~qString(&v6);
  UFG::qString::~qString(&v4);
  UFG::qString::qString(&v4, "%s\\Visual Layout", "\\Targeting\\Targeting Debug");
  UFG::qString::~qString(&v4);
  UFG::DebugTextGrid::UpdateColumnFormatData(&ms_TargetingDebugGrid);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__ms_TargetingDebugGrid__);
}

