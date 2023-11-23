// File Line: 39
// RVA: 0x536A20
void __fastcall UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet(
        UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *this,
        UFG::qPropertySet *pAngularInputToSubTargetingLocationPropertySet)
{
  unsigned int v4; // eax
  float *v5; // rsi
  UFG::qPropertyList *v6; // rax
  float v7; // xmm0_4

  if ( pAngularInputToSubTargetingLocationPropertySet )
  {
    v4 = _S51;
    if ( (_S51 & 1) == 0 )
    {
      _S51 |= 1u;
      UFG::qSymbol::create_from_string(&symMaxAngularInput, "MaxAngularInput");
      atexit(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symMaxAngularInput__);
      v4 = _S51;
    }
    if ( (v4 & 2) == 0 )
    {
      _S51 = v4 | 2;
      UFG::qSymbol::create_from_string(&symSubTargetingLocations, "SubTargetingLocations");
      atexit(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingLocations__);
    }
    v5 = UFG::qPropertySet::Get<float>(
           pAngularInputToSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symMaxAngularInput,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           pAngularInputToSubTargetingLocationPropertySet,
           (UFG::qArray<unsigned long,0> *)&symSubTargetingLocations,
           DEPTH_RECURSE);
    if ( v5 )
      v7 = (float)(*v5 * 3.1415927) * 0.0055555557;
    else
      v7 = FLOAT_N1_0;
    this->m_fMaxAngularInputRad = v7;
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&this->m_SubTargetingLocationDynamic, v6);
  }
}

// File Line: 63
// RVA: 0x538090
void __fastcall UFG::SubTargetingProfileInfo::InitFromPropertySet(
        UFG::SubTargetingProfileInfo *this,
        UFG::qPropertySet *pSubTargetingProfilePropertySet)
{
  unsigned int v4; // eax
  float *v5; // rbp
  float *v6; // rsi
  UFG::qPropertyList *v7; // rax
  float v8; // xmm0_4
  double v9; // xmm1_8

  if ( pSubTargetingProfilePropertySet )
  {
    v4 = _S52;
    if ( (_S52 & 1) == 0 )
    {
      _S52 |= 1u;
      UFG::qSymbol::create_from_string(&symTargetHeadingRelativeToCameraDeg, "TargetHeadingRelativeToCamera");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symTargetHeadingRelativeToCameraDeg__);
      v4 = _S52;
    }
    if ( (v4 & 2) == 0 )
    {
      _S52 = v4 | 2;
      UFG::qSymbol::create_from_string(&symAngularHalfWidth, "AngularHalfWidth");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAngularHalfWidth__);
      v4 = _S52;
    }
    if ( (v4 & 4) == 0 )
    {
      _S52 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAngularInputToSubTargetingLocations, "AngularInputToSubTargetingLocations");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAngularInputToSubTargetingLocations__);
    }
    v5 = UFG::qPropertySet::Get<float>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symTargetHeadingRelativeToCameraDeg,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<float>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symAngularHalfWidth,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symAngularInputToSubTargetingLocations,
           DEPTH_RECURSE);
    if ( v5 )
      v8 = (float)(*v5 * 3.1415927) * 0.0055555557;
    else
      v8 = FLOAT_N1_0;
    this->m_fTargetHeadingRelativeToCameraRad = v8;
    if ( v6 )
      v9 = (float)((float)(*v6 * 3.1415927) * 0.0055555557) + 0.05;
    else
      v9 = DOUBLE_N1_0;
    this->m_fAngularHalfWidthRad = v9;
    UFG::SubTargetingProfileInfo::InitAngularInputToSubTargetingLocations(this, v7);
  }
}

// File Line: 90
// RVA: 0x5365D0
void __fastcall UFG::SubTargetingProfileInfo::InitAngularInputToSubTargetingLocations(
        UFG::SubTargetingProfileInfo *this,
        UFG::qPropertyList *pAngularInputToSubTargetingLocations)
{
  unsigned int v2; // ebx
  unsigned int mNumElements; // esi
  char *ValuePtr; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *v9; // rcx

  v2 = 0;
  this->m_AngularInputToSubTargetingLocations.size = 0;
  if ( pAngularInputToSubTargetingLocations )
  {
    mNumElements = pAngularInputToSubTargetingLocations->mNumElements;
    if ( mNumElements )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(pAngularInputToSubTargetingLocations, 0x1Au, v2);
        if ( ValuePtr )
        {
          v7 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            v8 = (UFG::qPropertySet *)&ValuePtr[v7];
            if ( &ValuePtr[v7] )
            {
              v9 = &this->m_AngularInputToSubTargetingLocations.p[this->m_AngularInputToSubTargetingLocations.size++];
              UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < mNumElements );
    }
  }
}

// File Line: 119
// RVA: 0x537ED0
void __fastcall UFG::SubTargetingProfile::InitFromPropertySet(
        UFG::SubTargetingProfile *this,
        UFG::qPropertySet *pSubTargetingProfilePropertySet)
{
  unsigned int v4; // eax
  UFG::qPropertyList *v5; // rdi
  UFG::qPropertyList *v6; // rbx
  float *v7; // r14
  UFG::qPropertyList *v8; // rbp
  float v9; // xmm0_4

  if ( pSubTargetingProfilePropertySet )
  {
    this->mNode.mUID = pSubTargetingProfilePropertySet->mName.mUID;
    v4 = _S53_0;
    if ( (_S53_0 & 1) == 0 )
    {
      _S53_0 |= 1u;
      UFG::qSymbol::create_from_string(&symDefaultSubTargetingLocations, "DefaultSubTargetingLocations");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDefaultSubTargetingLocations__);
      v4 = _S53_0;
    }
    if ( (v4 & 2) == 0 )
    {
      _S53_0 = v4 | 2;
      UFG::qSymbol::create_from_string(&symHeadLookAtSubTargetingLocations, "HeadLookAtSubTargetingLocations");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symHeadLookAtSubTargetingLocations__);
      v4 = _S53_0;
    }
    if ( (v4 & 4) == 0 )
    {
      _S53_0 = v4 | 4;
      UFG::qSymbol::create_from_string(&symSoftLockExtraCapsuleRadius, "SoftLockExtraCapsuleRadius");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSoftLockExtraCapsuleRadius__);
      v4 = _S53_0;
    }
    if ( (v4 & 8) == 0 )
    {
      _S53_0 = v4 | 8;
      UFG::qSymbol::create_from_string(&symSubTargetingProfileInfos, "SubTargetingProfileInfos");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingProfileInfos__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symDefaultSubTargetingLocations,
           DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symHeadLookAtSubTargetingLocations,
           DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symSoftLockExtraCapsuleRadius,
           DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           pSubTargetingProfilePropertySet,
           (UFG::qArray<unsigned long,0> *)&symSubTargetingProfileInfos,
           DEPTH_RECURSE);
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&this->m_DefaultSubTargetingLocationDynamic, v5);
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&this->m_HeadLookAtSubTargetingLocationDynamic, v6);
    if ( v7 )
      v9 = *v7;
    else
      v9 = 0.0;
    this->m_fSoftLockExtraCapsuleRadius = v9;
    UFG::SubTargetingProfile::InitSubTargetingProfileInfosFromPropertySet(this, v8);
  }
}

// File Line: 171
// RVA: 0x539220
void __fastcall UFG::SubTargetingProfile::InitSubTargetingProfileInfosFromPropertySet(
        UFG::SubTargetingProfile *this,
        UFG::qPropertyList *pSubTargetingProfileInfos)
{
  unsigned int v2; // ebx
  UFG::qFixedArray<UFG::SubTargetingProfileInfo,4> *p_m_SubTargetingProfileInfos; // rdi
  unsigned int mNumElements; // esi
  char *ValuePtr; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingProfileInfo *v9; // rcx

  v2 = 0;
  p_m_SubTargetingProfileInfos = &this->m_SubTargetingProfileInfos;
  this->m_SubTargetingProfileInfos.size = 0;
  if ( pSubTargetingProfileInfos )
  {
    mNumElements = pSubTargetingProfileInfos->mNumElements;
    if ( mNumElements )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(pSubTargetingProfileInfos, 0x1Au, v2);
        if ( ValuePtr )
        {
          v7 = *(_QWORD *)ValuePtr;
          if ( *(_QWORD *)ValuePtr )
          {
            v8 = (UFG::qPropertySet *)&ValuePtr[v7];
            if ( &ValuePtr[v7] )
            {
              v9 = &p_m_SubTargetingProfileInfos->p[p_m_SubTargetingProfileInfos->size++];
              UFG::SubTargetingProfileInfo::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < mNumElements );
    }
  }
}

// File Line: 196
// RVA: 0x528460
bool __fastcall UFG::SubTargetingProfile::FindDefaultTargetablePosWS(
        UFG::SubTargetingProfile *this,
        UFG::qVector3 *vDefaultTargetablePosWS,
        UFG::SimObjectProp *pSimObject)
{
  signed __int16 m_Flags; // r9
  UFG::SimComponent *m_pComponent; // r8
  unsigned int m_TypeUID; // ecx
  unsigned int v9; // ecx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // edx
  unsigned int size; // r9d
  UFG::SimComponentHolder *v13; // r8
  Creature *v14; // r9

  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    m_TypeUID = m_pComponent->m_TypeUID;
    if ( ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = pSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent )
      goto LABEL_6;
    v9 = m_pComponent->m_TypeUID;
    if ( ((v9 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v9 & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pSimObject);
LABEL_23:
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            pSimObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = pSimObject->mComponentTableEntryCount;
  size = pSimObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  v13 = &pSimObject->m_Components.p[mComponentTableEntryCount];
  while ( (v13->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    ++v13;
    if ( mComponentTableEntryCount >= size )
    {
      m_pComponent = 0i64;
      goto LABEL_24;
    }
  }
  m_pComponent = v13->m_pComponent;
LABEL_24:
  if ( m_pComponent )
  {
    v14 = *(Creature **)&m_pComponent[2].m_TypeUID;
    if ( v14 )
      return UFG::SubTargetingProfile::FindDefaultTargetablePosWS(this, vDefaultTargetablePosWS, pSimObject, v14);
  }
  return 0;
}

// File Line: 212
// RVA: 0x528600
bool __fastcall UFG::SubTargetingProfile::FindDefaultTargetablePosWS(
        UFG::SubTargetingProfile *this,
        UFG::qVector3 *vDefaultTargetablePosWS,
        UFG::SimObject *pSimObject,
        Creature *pCreature)
{
  UFG::SubTargetingProfileInfo *SubTargetingProfileInfo; // rax
  UFG::SubTargetingLocation *SubTargetingLocation; // rax
  float fDownedPedCameraOffsetRad[6]; // [rsp+30h] [rbp-18h] BYREF

  fDownedPedCameraOffsetRad[0] = 0.0;
  SubTargetingProfileInfo = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
                              this,
                              pSimObject,
                              fDownedPedCameraOffsetRad);
  if ( SubTargetingProfileInfo )
  {
    SubTargetingLocation = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
                             &SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.p[0].m_SubTargetingLocationDynamic,
                             pSimObject);
    LOBYTE(SubTargetingProfileInfo) = UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                                        this,
                                        vDefaultTargetablePosWS,
                                        SubTargetingLocation,
                                        pSimObject,
                                        pCreature);
  }
  return (char)SubTargetingProfileInfo;
}

// File Line: 252
// RVA: 0x529EA0
bool __fastcall UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
        UFG::SubTargetingProfile *this,
        UFG::qVector3 *vSubTargetingLocationWS,
        UFG::SubTargetingLocation *pSubTargetingLocation,
        UFG::SimObject *pSimObject,
        Creature *pCreature)
{
  __int128 v5; // xmm7
  __int64 m_eTargetType; // rdi
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r11d
  UFG::SimComponentHolder *v13; // rdx
  unsigned int v14; // r8d
  unsigned int v15; // r11d
  UFG::SimObjectProp *v16; // rbx
  __int16 v17; // cx
  UFG::CharacterAnimationComponent *v18; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int v21; // r10d
  __int64 v22; // rdx
  Creature *mCreature; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm0
  int BoneID; // eax
  float x; // xmm2_4
  float y; // xmm5_4
  bool result; // al
  float v32; // xmm1_4
  float v33; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-58h] BYREF
  __int128 v35; // [rsp+60h] [rbp-18h]

  m_eTargetType = (unsigned int)pSubTargetingLocation->m_eTargetType;
  if ( !(_DWORD)m_eTargetType )
    goto LABEL_51;
  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v13 = &pSimObject->m_Components.p[vfptr];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v13;
        if ( vfptr >= size )
          goto LABEL_13;
      }
LABEL_14:
      m_pComponent = v13->m_pComponent;
      goto LABEL_23;
    }
    goto LABEL_13;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v14 = (unsigned int)pSimObject[1].vfptr;
    v15 = pSimObject->m_Components.size;
    if ( v14 < v15 )
    {
      v13 = &pSimObject->m_Components.p[v14];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v14;
        ++v13;
        if ( v14 >= v15 )
        {
          m_pComponent = 0i64;
          goto LABEL_23;
        }
      }
      goto LABEL_14;
    }
LABEL_13:
    m_pComponent = 0i64;
    goto LABEL_23;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
  if ( !m_pComponent )
    return 0;
  v16 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + m_eTargetType + 8)
                               + *(_QWORD *)&m_pComponent[1].m_TypeUID
                               + 40);
  if ( !v16 )
    goto LABEL_51;
  v17 = v16->m_Flags;
  if ( (v17 & 0x4000) != 0 )
  {
    v18 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v18
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_29;
    }
    goto LABEL_47;
  }
  if ( v17 < 0 )
  {
    v18 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v18 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_29;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) != 0 )
      v18 = 0i64;
    goto LABEL_47;
  }
  if ( (v17 & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
LABEL_46:
    v18 = ComponentOfType;
    goto LABEL_47;
  }
  if ( (v17 & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v16,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_46;
  }
  mComponentTableEntryCount = v16->mComponentTableEntryCount;
  v21 = v16->m_Components.size;
  if ( mComponentTableEntryCount >= v21 )
  {
LABEL_29:
    v18 = 0i64;
    goto LABEL_47;
  }
  v22 = (__int64)&v16->m_Components.p[mComponentTableEntryCount];
  while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF) != 0 )
  {
    ++mComponentTableEntryCount;
    v22 += 16i64;
    if ( mComponentTableEntryCount >= v21 )
    {
      v18 = 0i64;
      goto LABEL_47;
    }
  }
  v18 = *(UFG::CharacterAnimationComponent **)v22;
LABEL_47:
  if ( !v18 || (mCreature = v18->mCreature) == 0i64 )
  {
    m_pTransformNodeComponent = v16->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v25 = m_pTransformNodeComponent->mWorldTransform.v2;
      v26 = m_pTransformNodeComponent->mWorldTransform.v3;
      v27 = m_pTransformNodeComponent->mWorldTransform.v0;
      transform.v1 = m_pTransformNodeComponent->mWorldTransform.v1;
      transform.v2 = v25;
      transform.v0 = v27;
      transform.v3 = v26;
LABEL_55:
      x = pSubTargetingLocation->m_vOffset.x;
      y = pSubTargetingLocation->m_vOffset.y;
      v35 = v5;
      result = 1;
      v32 = transform.v3.y
          + (float)((float)((float)(transform.v0.y * x) + (float)(transform.v1.y * y))
                  + (float)(transform.v2.y * pSubTargetingLocation->m_vOffset.z));
      v33 = transform.v3.z
          + (float)((float)((float)(transform.v0.z * x) + (float)(transform.v1.z * y))
                  + (float)(transform.v2.z * pSubTargetingLocation->m_vOffset.z));
      vSubTargetingLocationWS->x = transform.v3.x
                                 + (float)((float)((float)(transform.v0.x * x) + (float)(transform.v1.x * y))
                                         + (float)(transform.v2.x * pSubTargetingLocation->m_vOffset.z));
      vSubTargetingLocationWS->y = v32;
      vSubTargetingLocationWS->z = v33;
      return result;
    }
LABEL_51:
    mCreature = pCreature;
    if ( !pCreature )
      return 0;
  }
  if ( mCreature->mPose.mRigHandle.mData )
  {
    BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, pSubTargetingLocation->m_symBoneName.mUID);
    if ( BoneID >= 0 )
    {
      Creature::GetTransform(mCreature, BoneID, &transform);
      goto LABEL_55;
    }
  }
  return 0;
}

// File Line: 331
// RVA: 0x529DB0
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingProfile::FindSubTargetingLocationByInput(
        UFG::SubTargetingProfile *this,
        UFG::SimObject *pTargetSimObject,
        float fInputAngle)
{
  UFG::SubTargetingProfileInfo *SubTargetingProfileInfo; // rax
  UFG::SubTargetingProfileInfo *v6; // rsi
  float v7; // xmm6_4
  unsigned int size; // edi
  int v9; // ebx
  unsigned int v10; // edx
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *p; // rcx
  UFG::SubTargetingLocation *result; // rax
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *i; // rcx
  float fDownedPedCameraOffsetRad; // [rsp+70h] [rbp+18h] BYREF

  if ( fInputAngle < 0.0 )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &this->m_DefaultSubTargetingLocationDynamic,
             pTargetSimObject);
  fDownedPedCameraOffsetRad = 0.0;
  SubTargetingProfileInfo = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
                              this,
                              pTargetSimObject,
                              &fDownedPedCameraOffsetRad);
  v6 = SubTargetingProfileInfo;
  if ( !SubTargetingProfileInfo )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &this->m_DefaultSubTargetingLocationDynamic,
             pTargetSimObject);
  v7 = fInputAngle - fDownedPedCameraOffsetRad;
  if ( (float)(fInputAngle - fDownedPedCameraOffsetRad) < 0.0 )
    v7 = v7 + 6.2831855;
  size = SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.size;
  v9 = 0;
  v10 = 0;
  if ( !SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.size )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &this->m_DefaultSubTargetingLocationDynamic,
             pTargetSimObject);
  p = SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.p;
  while ( p->m_fMaxAngularInputRad < 0.0 || v7 > p->m_fMaxAngularInputRad )
  {
    ++v10;
    ++p;
    if ( v10 >= size )
      goto LABEL_12;
  }
  result = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &p->m_SubTargetingLocationDynamic,
             pTargetSimObject);
  if ( result )
    return result;
LABEL_12:
  if ( !size )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &this->m_DefaultSubTargetingLocationDynamic,
             pTargetSimObject);
  for ( i = v6->m_AngularInputToSubTargetingLocations.p; i->m_fMaxAngularInputRad < 0.0; ++i )
  {
    if ( ++v9 >= size )
      return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
               &this->m_DefaultSubTargetingLocationDynamic,
               pTargetSimObject);
  }
  result = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &i->m_SubTargetingLocationDynamic,
             pTargetSimObject);
  if ( !result )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
             &this->m_DefaultSubTargetingLocationDynamic,
             pTargetSimObject);
  return result;
}

// File Line: 406
// RVA: 0x529A20
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingProfile::FindSubTargetingLocationByAimOffset(
        UFG::SubTargetingProfile *this,
        UFG::SimObjectProp *pTargetSimObject,
        UFG::qVector3 *vAimOffset,
        const float fRadiusMultiplier)
{
  UFG::SubTargetingLocation *v7; // r15
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *v9; // rax
  UFG::Camera *p_mCamera; // rax
  UFG::qVector3 *v11; // r13
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rsi
  unsigned int v15; // edx
  unsigned int m_TypeUID; // ecx
  unsigned int v17; // eax
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // edx
  unsigned int v20; // r8d
  UFG::SimComponentHolder *v21; // rsi
  UFG::SubTargetingProfileInfo *SubTargetingProfileInfo; // rbx
  float v23; // xmm6_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v26; // xmm1_4
  float z; // xmm0_4
  Creature *pCreature; // rbp
  UFG::SubTargetingProfileInfo *v29; // rax
  UFG::SubTargetingLocation *SubTargetingLocation; // rax
  unsigned int size; // eax
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *p; // rbx
  __int64 v33; // r14
  UFG::SubTargetingLocation *v34; // rbp
  UFG::qVector3 *v35; // rax
  float v36; // xmm2_4
  float fDownedPedCameraOffsetRad; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+38h] [rbp-90h] BYREF
  UFG::qVector3 end; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector3 result; // [rsp+58h] [rbp-70h] BYREF

  v7 = 0i64;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( !mCurrentCamera || mCurrentCamera == (UFG::BaseCameraComponent *)-80i64 )
    return 0i64;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    p_mCamera = &v9->mCamera;
  else
    p_mCamera = 0i64;
  v11 = (UFG::qVector3 *)&p_mCamera->mTransformation.v3;
  if ( pTargetSimObject )
  {
    m_pTransformNodeComponent = pTargetSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      m_Flags = pTargetSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = pTargetSimObject->m_Components.p[9].m_pComponent;
        if ( m_pComponent )
        {
          v15 = UFG::CharacterAnimationComponent::_TypeUID;
          m_TypeUID = m_pComponent->m_TypeUID;
          v17 = m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_11:
          if ( (v17 & 0xFE000000) != 0 || (v15 & ~m_TypeUID & 0x1FFFFFF) != 0 )
            goto LABEL_13;
LABEL_29:
          if ( m_pComponent )
          {
            fDownedPedCameraOffsetRad = 0.0;
            SubTargetingProfileInfo = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
                                        this,
                                        pTargetSimObject,
                                        &fDownedPedCameraOffsetRad);
            if ( SubTargetingProfileInfo )
            {
              v23 = FLOAT_3_4028235e38;
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              x = m_pTransformNodeComponent->mWorldTransform.v3.x;
              y = m_pTransformNodeComponent->mWorldTransform.v3.y;
              fDownedPedCameraOffsetRad = 0.0;
              v26 = y + vAimOffset->y;
              end.x = x + vAimOffset->x;
              z = m_pTransformNodeComponent->mWorldTransform.v3.z;
              end.y = v26;
              pCreature = *(Creature **)&m_pComponent[2].m_TypeUID;
              end.z = z + vAimOffset->z;
              v29 = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
                      this,
                      pTargetSimObject,
                      &fDownedPedCameraOffsetRad);
              if ( !v29 )
                return 0i64;
              SubTargetingLocation = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
                                       &v29->m_AngularInputToSubTargetingLocations.p[0].m_SubTargetingLocationDynamic,
                                       pTargetSimObject);
              if ( !UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                      this,
                      &vSubTargetingLocationWS,
                      SubTargetingLocation,
                      pTargetSimObject,
                      pCreature) )
                return 0i64;
              size = SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.size;
              if ( SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.size )
              {
                p = SubTargetingProfileInfo->m_AngularInputToSubTargetingLocations.p;
                v33 = size;
                do
                {
                  if ( p->m_fMaxAngularInputRad >= 0.0 )
                  {
                    v34 = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
                            &p->m_SubTargetingLocationDynamic,
                            pTargetSimObject);
                    if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                           this,
                           &vSubTargetingLocationWS,
                           v34,
                           pTargetSimObject,
                           *(Creature **)&m_pComponent[2].m_TypeUID) )
                    {
                      v35 = UFG::qNearestSegPoint(&result, v11, &end, &vSubTargetingLocationWS);
                      v36 = (float)((float)((float)(vSubTargetingLocationWS.y - v35->y)
                                          * (float)(vSubTargetingLocationWS.y - v35->y))
                                  + (float)((float)(vSubTargetingLocationWS.x - v35->x)
                                          * (float)(vSubTargetingLocationWS.x - v35->x)))
                          + (float)((float)(vSubTargetingLocationWS.z - v35->z)
                                  * (float)(vSubTargetingLocationWS.z - v35->z));
                      if ( v36 < v23
                        && v36 < (float)((float)(fRadiusMultiplier * v34->m_fRadius)
                                       * (float)(fRadiusMultiplier * v34->m_fRadius)) )
                      {
                        v23 = (float)((float)((float)(vSubTargetingLocationWS.y - v35->y)
                                            * (float)(vSubTargetingLocationWS.y - v35->y))
                                    + (float)((float)(vSubTargetingLocationWS.x - v35->x)
                                            * (float)(vSubTargetingLocationWS.x - v35->x)))
                            + (float)((float)(vSubTargetingLocationWS.z - v35->z)
                                    * (float)(vSubTargetingLocationWS.z - v35->z));
                        v7 = v34;
                      }
                    }
                  }
                  ++p;
                  --v33;
                }
                while ( v33 );
              }
            }
          }
          return v7;
        }
      }
      else
      {
        if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pTargetSimObject);
          }
          else
          {
            if ( (m_Flags & 0x1000) != 0 )
            {
              mComponentTableEntryCount = pTargetSimObject->mComponentTableEntryCount;
              v20 = pTargetSimObject->m_Components.size;
              if ( mComponentTableEntryCount < v20 )
              {
                v21 = &pTargetSimObject->m_Components.p[mComponentTableEntryCount];
                while ( (v21->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                     || (UFG::CharacterAnimationComponent::_TypeUID & ~v21->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++mComponentTableEntryCount;
                  ++v21;
                  if ( mComponentTableEntryCount >= v20 )
                  {
                    m_pComponent = 0i64;
                    goto LABEL_29;
                  }
                }
                m_pComponent = v21->m_pComponent;
                goto LABEL_29;
              }
              goto LABEL_13;
            }
            ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                    pTargetSimObject,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
          }
          m_pComponent = ComponentOfType;
          goto LABEL_29;
        }
        m_pComponent = pTargetSimObject->m_Components.p[9].m_pComponent;
        if ( m_pComponent )
        {
          m_TypeUID = m_pComponent->m_TypeUID;
          v15 = UFG::CharacterAnimationComponent::_TypeUID;
          v17 = UFG::CharacterAnimationComponent::_TypeUID ^ m_TypeUID;
          goto LABEL_11;
        }
      }
LABEL_13:
      m_pComponent = 0i64;
      goto LABEL_29;
    }
  }
  return v7;
}

// File Line: 482
// RVA: 0x5691F0
UFG::SubTargetingProfileInfo *__fastcall UFG::SubTargetingProfile::getSubTargetingProfileInfo(
        UFG::SubTargetingProfile *this,
        UFG::SimObjectProp *pTargetSimObject,
        float *fDownedPedCameraOffsetRad)
{
  unsigned int v5; // esi
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *p; // rdi
  Creature *v12; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  UFG::qVector3 *p_mWorldTransform; // r15
  UFG::BaseCameraComponent *mCurrentCamera; // r14
  UFG::Camera *p_mCamera; // r14
  int v17; // xmm7_4
  int v18; // xmm8_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  int BoneID; // eax
  int v22; // r13d
  signed __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  unsigned int v25; // r8d
  unsigned int v26; // r10d
  UFG::SimComponentHolder *v27; // rbx
  __int64 v28; // rdx
  unsigned int v29; // r8d
  unsigned int v30; // r10d
  unsigned int v31; // r8d
  unsigned int v32; // r10d
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm4_4
  unsigned int v36; // r12d
  __int64 v37; // rax
  float *i; // rdi
  float v39; // xmm2_4
  float v40; // xmm7_4
  __m128 y_low; // xmm8
  float v42; // xmm9_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  bool v45; // bl
  float v46; // xmm0_4
  float v47; // xmm2_4
  bool v48; // bl
  float v49; // xmm2_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v52; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 v2; // [rsp+40h] [rbp-88h] BYREF
  float v54; // [rsp+4Ch] [rbp-7Ch]
  UFG::qVector3 v55; // [rsp+50h] [rbp-78h] BYREF
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-68h] BYREF
  __int64 v57; // [rsp+128h] [rbp+60h]
  __int64 v58; // [rsp+130h] [rbp+68h]

  *(_QWORD *)&transform.v0.z = -2i64;
  v5 = 0;
  *fDownedPedCameraOffsetRad = 0.0;
  if ( !pTargetSimObject )
    return 0i64;
  m_Flags = pTargetSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pTargetSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = pTargetSimObject->m_Components.p[9].m_pComponent;
    if ( !m_pComponent || ((UFG::CharacterAnimationComponent::_TypeUID ^ m_pComponent->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_6;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_pComponent->m_TypeUID & 0x1FFFFFF) != 0 )
      m_pComponent = 0i64;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pTargetSimObject);
LABEL_23:
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            pTargetSimObject,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  mComponentTableEntryCount = pTargetSimObject->mComponentTableEntryCount;
  size = pTargetSimObject->m_Components.size;
  if ( mComponentTableEntryCount >= size )
  {
LABEL_6:
    m_pComponent = 0i64;
    goto LABEL_24;
  }
  p = pTargetSimObject->m_Components.p;
  while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
  {
    if ( ++mComponentTableEntryCount >= size )
      goto LABEL_6;
  }
  m_pComponent = p[mComponentTableEntryCount].m_pComponent;
LABEL_24:
  if ( !m_pComponent )
    return 0i64;
  v12 = *(Creature **)&m_pComponent[2].m_TypeUID;
  if ( !v12 )
    return 0i64;
  m_pTransformNodeComponent = pTargetSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent )
    return 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(pTargetSimObject->m_pTransformNodeComponent);
  p_mWorldTransform = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform;
  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  v17 = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
  v18 = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
  v19 = p_mWorldTransform[4].z - p_mCamera->mTransformation.v3.z;
  v20 = p_mWorldTransform[4].y - p_mCamera->mTransformation.v3.y;
  v55.x = p_mWorldTransform[4].x - p_mCamera->mTransformation.v3.x;
  v55.y = v20;
  v55.z = v19;
  if ( (_S55 & 1) == 0 )
  {
    _S55 |= 1u;
    UFG::qSymbolUC::create_from_string(&pelvis_name, "Bip01_Pelvis");
    atexit(UFG::SubTargetingProfile::getSubTargetingProfileInfo_::_11_::_dynamic_atexit_destructor_for__pelvis_name__);
  }
  if ( !v12->mPose.mRigHandle.mData )
  {
    v22 = -1;
    goto LABEL_66;
  }
  BoneID = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, pelvis_name.mUID);
  v22 = BoneID;
  if ( BoneID < 0 )
    goto LABEL_66;
  Creature::GetTransform(v12, BoneID, &transform);
  v1.x = transform.v0.x;
  v1.y = transform.v0.y;
  v1.z = transform.v0.z;
  v2 = UFG::qVector3::msAxisZ;
  v23 = pTargetSimObject->m_Flags;
  if ( (v23 & 0x4000) == 0 )
  {
    if ( v23 >= 0 )
    {
      if ( (v23 & 0x2000) != 0 )
      {
        v29 = pTargetSimObject->mComponentTableEntryCount;
        v30 = pTargetSimObject->m_Components.size;
        if ( v29 < v30 )
        {
          v27 = pTargetSimObject->m_Components.p;
          do
          {
            v28 = v29;
            if ( (v27[v29].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v29].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_43;
            }
          }
          while ( ++v29 < v30 );
        }
      }
      else
      {
        if ( (v23 & 0x1000) == 0 )
        {
          v24 = UFG::SimObject::GetComponentOfType(pTargetSimObject, UFG::CharacterPhysicsComponent::_TypeUID);
          goto LABEL_60;
        }
        v31 = pTargetSimObject->mComponentTableEntryCount;
        v32 = pTargetSimObject->m_Components.size;
        if ( v31 < v32 )
        {
          v27 = pTargetSimObject->m_Components.p;
          do
          {
            v28 = v31;
            if ( (v27[v31].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
              && (UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v31].m_TypeUID & 0x1FFFFFF) == 0 )
            {
              goto LABEL_43;
            }
          }
          while ( ++v31 < v32 );
        }
      }
    }
    else
    {
      v25 = pTargetSimObject->mComponentTableEntryCount;
      v26 = pTargetSimObject->m_Components.size;
      if ( v25 < v26 )
      {
        v27 = pTargetSimObject->m_Components.p;
        while ( 1 )
        {
          v28 = v25;
          if ( (v27[v25].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
            && (UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v25].m_TypeUID & 0x1FFFFFF) == 0 )
          {
            break;
          }
          if ( ++v25 >= v26 )
            goto LABEL_44;
        }
LABEL_43:
        v24 = v27[v28].m_pComponent;
        goto LABEL_60;
      }
    }
LABEL_44:
    v24 = 0i64;
    goto LABEL_60;
  }
  v24 = pTargetSimObject->m_Components.p[27].m_pComponent;
LABEL_60:
  if ( v24 )
  {
    v33 = *(float *)&v24[5].m_pSimObject;
    v34 = *((float *)&v24[5].m_pSimObject + 1);
    v2.x = *(float *)(&v24[5].m_SimObjIndex + 1);
    v2.y = v33;
    v2.z = v34;
  }
  if ( UFG::qAngleBetween(&v1, &v2) > 3437.7466 )
  {
    v1.z = 0.0;
    LODWORD(v52.x) = v18;
    LODWORD(v52.y) = v17;
    v52.z = 0.0;
    v35 = UFG::qAngleBetween(&v1, &v52);
    *fDownedPedCameraOffsetRad = v35;
    if ( (float)((float)((float)(v1.y * p_mCamera->mTransformation.v0.y)
                       + (float)(v1.x * p_mCamera->mTransformation.v0.x))
               + (float)(v1.z * p_mCamera->mTransformation.v0.z)) <= 0.0 )
      *fDownedPedCameraOffsetRad = 6.2831855 - v35;
  }
LABEL_66:
  v36 = *(_DWORD *)(v57 + 240);
  v37 = v22;
  v58 = v22;
  if ( !v36 )
    return 0i64;
  for ( i = (float *)(v57 + 932); ; i += 172 )
  {
    if ( v37 < 0 )
    {
      v48 = (float)((float)((float)(p_mCamera->mTransformation.v0.y * p_mWorldTransform->y)
                          + (float)(p_mWorldTransform->x * p_mCamera->mTransformation.v0.x))
                  + (float)(p_mCamera->mTransformation.v0.z * p_mWorldTransform->z)) <= 0.0;
      v47 = UFG::qAngleBetween(p_mWorldTransform, &v55);
      if ( v48 )
        v47 = 6.2831855 - v47;
    }
    else
    {
      y_low = (__m128)LODWORD(v55.y);
      v39 = (float)((float)(transform.v0.y * v55.y) + (float)(transform.v0.x * v55.x)) + (float)(transform.v0.z * v55.z);
      v40 = v55.x - (float)(transform.v0.x * v39);
      y_low.m128_f32[0] = v55.y - (float)(transform.v0.y * v39);
      v42 = v55.z - (float)(transform.v0.z * v39);
      v43 = y_low;
      v43.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v40 * v40))
                      + (float)(v42 * v42);
      if ( v43.m128_f32[0] == 0.0 )
        v44 = 0.0;
      else
        v44 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
      v52.x = v40 * v44;
      v52.y = y_low.m128_f32[0] * v44;
      v52.z = v42 * v44;
      v45 = (float)((float)((float)(v54 * (float)(y_low.m128_f32[0] * v44)) + (float)(v2.z * (float)(v40 * v44)))
                  + (float)(v55.x * (float)(v42 * v44))) <= 0.0;
      v46 = UFG::qAngleBetween((UFG::qVector3 *)&transform.v1, &v52);
      v47 = v46;
      if ( v45 )
        v47 = 6.2831855 - v46;
    }
    v49 = v47 - *(i - 1);
    if ( v49 < 0.0 )
      v49 = v49 + 6.2831855;
    if ( v49 >= 3.1415927 )
      v49 = 6.2831855 - v49;
    if ( v49 <= *i )
      break;
    ++v5;
    v37 = v58;
    if ( v5 >= v36 )
      return 0i64;
  }
  return (UFG::SubTargetingProfileInfo *)(i - 171);
}

// File Line: 804
// RVA: 0x1543980
__int64 dynamic_initializer_for__UFG::SubTargetingProfiles::ms_SubTargetingProfilePool__()
{
  `eh vector constructor iterator(
    (char *)UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.p,
    0xBC0ui64,
    10,
    (void (__fastcall *)(void *))UFG::SubTargetingProfile::SubTargetingProfile);
  UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubTargetingProfiles::ms_SubTargetingProfilePool__);
}

// File Line: 805
// RVA: 0x15439E0
__int64 dynamic_initializer_for__UFG::SubTargetingProfiles::ms_SubTargetingProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SubTargetingProfiles::ms_SubTargetingProfiles__);
}

// File Line: 808
// RVA: 0x5503E0
void UFG::SubTargetingProfiles::StaticInit(void)
{
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int mNumElements; // esi
  unsigned int i; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int size; // ecx
  UFG::SubTargetingProfile *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qArray<unsigned long,0> name; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string((UFG::qSymbol *)&name.p, "Targeting-SubTargetingProfiles-manifest");
  PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&name.p);
  if ( PropertySet )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      mNumElements = v1->mNumElements;
      for ( i = 0; i < mNumElements; ++i )
      {
        v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, i);
        v6 = (UFG::qSymbolUC *)v5;
        if ( v5 )
        {
          v7 = UFG::PropertySetManager::GetPropertySet(v5);
          if ( v7 )
          {
            size = UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size;
            if ( UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size >= 0xA )
            {
              v10 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Pool is Full (%d) Not Adding (%s)\n", 10i64, v10);
            }
            else
            {
              ++UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size;
              v9 = &UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.p[size];
              UFG::SubTargetingProfile::InitFromPropertySet(v9, v7);
              UFG::qBaseTreeRB::Add(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree, &v9->mNode);
            }
          }
          else
          {
            v11 = UFG::qSymbol::as_cstr_dbg(v6);
            UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Profile Not Found: %s\n", v11);
          }
        }
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Property List Not Found: %s\n", v12);
    }
  }
  else
  {
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name.p);
    UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

