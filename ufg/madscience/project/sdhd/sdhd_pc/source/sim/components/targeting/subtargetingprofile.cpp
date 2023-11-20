// File Line: 39
// RVA: 0x536A20
void __fastcall UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *this, UFG::qPropertySet *pAngularInputToSubTargetingLocationPropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *v3; // rbx
  unsigned int v4; // eax
  float *v5; // rsi
  UFG::qPropertyList *v6; // rax
  float v7; // xmm0_4

  if ( pAngularInputToSubTargetingLocationPropertySet )
  {
    v2 = pAngularInputToSubTargetingLocationPropertySet;
    v3 = this;
    v4 = _S51;
    if ( !(_S51 & 1) )
    {
      _S51 |= 1u;
      UFG::qSymbol::create_from_string(&symMaxAngularInput, "MaxAngularInput");
      atexit(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symMaxAngularInput__);
      v4 = _S51;
    }
    if ( !(v4 & 2) )
    {
      _S51 = v4 | 2;
      UFG::qSymbol::create_from_string(&symSubTargetingLocations, "SubTargetingLocations");
      atexit(UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingLocations__);
    }
    v5 = UFG::qPropertySet::Get<float>(v2, &symMaxAngularInput, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &symSubTargetingLocations, DEPTH_RECURSE);
    if ( v5 )
      v7 = (float)(*v5 * 3.1415927) * 0.0055555557;
    else
      v7 = FLOAT_N1_0;
    v3->m_fMaxAngularInputRad = v7;
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&v3->m_SubTargetingLocationDynamic, v6);
  }
}

// File Line: 63
// RVA: 0x538090
void __fastcall UFG::SubTargetingProfileInfo::InitFromPropertySet(UFG::SubTargetingProfileInfo *this, UFG::qPropertySet *pSubTargetingProfilePropertySet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::SubTargetingProfileInfo *v3; // rbx
  unsigned int v4; // eax
  float *v5; // rbp
  float *v6; // rsi
  UFG::qPropertyList *v7; // rax
  float v8; // xmm0_4
  double v9; // xmm1_8

  if ( pSubTargetingProfilePropertySet )
  {
    v2 = pSubTargetingProfilePropertySet;
    v3 = this;
    v4 = _S52;
    if ( !(_S52 & 1) )
    {
      _S52 |= 1u;
      UFG::qSymbol::create_from_string(&symTargetHeadingRelativeToCameraDeg, "TargetHeadingRelativeToCamera");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symTargetHeadingRelativeToCameraDeg__);
      v4 = _S52;
    }
    if ( !(v4 & 2) )
    {
      _S52 = v4 | 2;
      UFG::qSymbol::create_from_string(&symAngularHalfWidth, "AngularHalfWidth");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAngularHalfWidth__);
      v4 = _S52;
    }
    if ( !(v4 & 4) )
    {
      _S52 = v4 | 4;
      UFG::qSymbol::create_from_string(&symAngularInputToSubTargetingLocations, "AngularInputToSubTargetingLocations");
      atexit(UFG::SubTargetingProfileInfo::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symAngularInputToSubTargetingLocations__);
    }
    v5 = UFG::qPropertySet::Get<float>(v2, &symTargetHeadingRelativeToCameraDeg, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<float>(v2, &symAngularHalfWidth, DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &symAngularInputToSubTargetingLocations, DEPTH_RECURSE);
    if ( v5 )
      v8 = (float)(*v5 * 3.1415927) * 0.0055555557;
    else
      v8 = FLOAT_N1_0;
    v3->m_fTargetHeadingRelativeToCameraRad = v8;
    if ( v6 )
      v9 = (float)((float)(*v6 * 3.1415927) * 0.0055555557) + 0.05;
    else
      v9 = DOUBLE_N1_0;
    v3->m_fAngularHalfWidthRad = v9;
    UFG::SubTargetingProfileInfo::InitAngularInputToSubTargetingLocations(v3, v7);
  }
}

// File Line: 90
// RVA: 0x5365D0
void __fastcall UFG::SubTargetingProfileInfo::InitAngularInputToSubTargetingLocations(UFG::SubTargetingProfileInfo *this, UFG::qPropertyList *pAngularInputToSubTargetingLocations)
{
  unsigned int v2; // ebx
  UFG::qPropertyList *v3; // rbp
  UFG::SubTargetingProfileInfo *v4; // rdi
  unsigned int v5; // esi
  char *v6; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation *v9; // rcx

  v2 = 0;
  v3 = pAngularInputToSubTargetingLocations;
  v4 = this;
  this->m_AngularInputToSubTargetingLocations.size = 0;
  if ( pAngularInputToSubTargetingLocations )
  {
    v5 = pAngularInputToSubTargetingLocations->mNumElements;
    if ( v5 )
    {
      do
      {
        v6 = UFG::qPropertyList::GetValuePtr(v3, 0x1Au, v2);
        if ( v6 )
        {
          v7 = *(_QWORD *)v6;
          if ( *(_QWORD *)v6 )
          {
            v8 = (UFG::qPropertySet *)&v6[v7];
            if ( &v6[v7] )
            {
              v9 = &v4->m_AngularInputToSubTargetingLocations.p[v4->m_AngularInputToSubTargetingLocations.size++];
              UFG::SubTargetingProfileInfo::AngularInputToSubTargetingLocation::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < v5 );
    }
  }
}

// File Line: 119
// RVA: 0x537ED0
void __fastcall UFG::SubTargetingProfile::InitFromPropertySet(UFG::SubTargetingProfile *this, UFG::qPropertySet *pSubTargetingProfilePropertySet)
{
  UFG::qPropertySet *v2; // rbp
  UFG::SubTargetingProfile *v3; // rsi
  unsigned int v4; // eax
  UFG::qPropertyList *v5; // rdi
  UFG::qPropertyList *v6; // rbx
  float *v7; // r14
  UFG::qPropertyList *v8; // rbp
  float v9; // xmm0_4

  if ( pSubTargetingProfilePropertySet )
  {
    v2 = pSubTargetingProfilePropertySet;
    v3 = this;
    this->mNode.mUID = pSubTargetingProfilePropertySet->mName.mUID;
    v4 = _S53_0;
    if ( !(_S53_0 & 1) )
    {
      _S53_0 |= 1u;
      UFG::qSymbol::create_from_string(&symDefaultSubTargetingLocations, "DefaultSubTargetingLocations");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symDefaultSubTargetingLocations__);
      v4 = _S53_0;
    }
    if ( !(v4 & 2) )
    {
      _S53_0 = v4 | 2;
      UFG::qSymbol::create_from_string(&symHeadLookAtSubTargetingLocations, "HeadLookAtSubTargetingLocations");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symHeadLookAtSubTargetingLocations__);
      v4 = _S53_0;
    }
    if ( !(v4 & 4) )
    {
      _S53_0 = v4 | 4;
      UFG::qSymbol::create_from_string(&symSoftLockExtraCapsuleRadius, "SoftLockExtraCapsuleRadius");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSoftLockExtraCapsuleRadius__);
      v4 = _S53_0;
    }
    if ( !(v4 & 8) )
    {
      _S53_0 = v4 | 8;
      UFG::qSymbol::create_from_string(&symSubTargetingProfileInfos, "SubTargetingProfileInfos");
      atexit(UFG::SubTargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symSubTargetingProfileInfos__);
    }
    v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &symDefaultSubTargetingLocations, DEPTH_RECURSE);
    v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &symHeadLookAtSubTargetingLocations, DEPTH_RECURSE);
    v7 = UFG::qPropertySet::Get<float>(v2, &symSoftLockExtraCapsuleRadius, DEPTH_RECURSE);
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, &symSubTargetingProfileInfos, DEPTH_RECURSE);
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&v3->m_DefaultSubTargetingLocationDynamic, v5);
    UFG::SubTargetingLocationDynamic::InitFromPropertySet(&v3->m_HeadLookAtSubTargetingLocationDynamic, v6);
    if ( v7 )
      v9 = *v7;
    else
      v9 = 0.0;
    v3->m_fSoftLockExtraCapsuleRadius = v9;
    UFG::SubTargetingProfile::InitSubTargetingProfileInfosFromPropertySet(v3, v8);
  }
}

// File Line: 171
// RVA: 0x539220
void __fastcall UFG::SubTargetingProfile::InitSubTargetingProfileInfosFromPropertySet(UFG::SubTargetingProfile *this, UFG::qPropertyList *pSubTargetingProfileInfos)
{
  unsigned int v2; // ebx
  UFG::qFixedArray<UFG::SubTargetingProfileInfo,4> *v3; // rdi
  UFG::qPropertyList *v4; // rbp
  unsigned int v5; // esi
  char *v6; // rax
  __int64 v7; // rcx
  UFG::qPropertySet *v8; // rdx
  UFG::SubTargetingProfileInfo *v9; // rcx

  v2 = 0;
  v3 = &this->m_SubTargetingProfileInfos;
  v4 = pSubTargetingProfileInfos;
  this->m_SubTargetingProfileInfos.size = 0;
  if ( pSubTargetingProfileInfos )
  {
    v5 = pSubTargetingProfileInfos->mNumElements;
    if ( v5 )
    {
      do
      {
        v6 = UFG::qPropertyList::GetValuePtr(v4, 0x1Au, v2);
        if ( v6 )
        {
          v7 = *(_QWORD *)v6;
          if ( *(_QWORD *)v6 )
          {
            v8 = (UFG::qPropertySet *)&v6[v7];
            if ( &v6[v7] )
            {
              v9 = &v3->p[v3->size++];
              UFG::SubTargetingProfileInfo::InitFromPropertySet(v9, v8);
            }
          }
        }
        ++v2;
      }
      while ( v2 < v5 );
    }
  }
}

// File Line: 196
// RVA: 0x528460
bool __fastcall UFG::SubTargetingProfile::FindDefaultTargetablePosWS(UFG::SubTargetingProfile *this, UFG::qVector3 *vDefaultTargetablePosWS, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v3; // rbx
  UFG::qVector3 *v4; // rdi
  UFG::SubTargetingProfile *v5; // rsi
  unsigned __int16 v6; // r9
  UFG::SimComponent *v7; // r8
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  UFG::CharacterAnimationComponent *v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // er9
  UFG::SimComponentHolder *v13; // r8
  Creature *v14; // r9

  v3 = pSimObject;
  v4 = vDefaultTargetablePosWS;
  v5 = this;
  if ( !pSimObject )
    return 0;
  v6 = pSimObject->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = pSimObject->m_Components.p[9].m_pComponent;
    if ( !v7 )
      goto LABEL_6;
    v8 = v7->m_TypeUID;
    if ( (v8 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v8 & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v6 & 0x8000u) != 0 )
  {
    v7 = pSimObject->m_Components.p[9].m_pComponent;
    if ( !v7 )
      goto LABEL_6;
    v9 = v7->m_TypeUID;
    if ( (v9 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v9 & 0x1FFFFFF )
      v7 = 0i64;
    goto LABEL_24;
  }
  if ( (v6 >> 13) & 1 )
  {
    v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)pSimObject);
LABEL_23:
    v7 = (UFG::SimComponent *)&v10->vfptr;
    goto LABEL_24;
  }
  if ( !((v6 >> 12) & 1) )
  {
    v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                pSimObject,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v11 = (unsigned int)pSimObject[1].vfptr;
  v12 = pSimObject->m_Components.size;
  if ( v11 >= v12 )
  {
LABEL_6:
    v7 = 0i64;
    goto LABEL_24;
  }
  v13 = &pSimObject->m_Components.p[v11];
  while ( (v13->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF )
  {
    ++v11;
    ++v13;
    if ( v11 >= v12 )
    {
      v7 = 0i64;
      goto LABEL_24;
    }
  }
  v7 = v13->m_pComponent;
LABEL_24:
  if ( v7 )
  {
    v14 = *(Creature **)&v7[2].m_TypeUID;
    if ( v14 )
      return UFG::SubTargetingProfile::FindDefaultTargetablePosWS(v5, v4, v3, v14);
  }
  return 0;
}

// File Line: 212
// RVA: 0x528600
bool __fastcall UFG::SubTargetingProfile::FindDefaultTargetablePosWS(UFG::SubTargetingProfile *this, UFG::qVector3 *vDefaultTargetablePosWS, UFG::SimObject *pSimObject, Creature *pCreature)
{
  UFG::SimObject *v4; // rbx
  UFG::qVector3 *v5; // rbp
  Creature *v6; // rsi
  UFG::SubTargetingProfile *v7; // rdi
  UFG::SubTargetingProfileInfo *v8; // rax
  UFG::SubTargetingLocation *v9; // rax
  float fDownedPedCameraOffsetRad; // [rsp+30h] [rbp-18h]

  v4 = pSimObject;
  v5 = vDefaultTargetablePosWS;
  v6 = pCreature;
  v7 = this;
  fDownedPedCameraOffsetRad = 0.0;
  v8 = UFG::SubTargetingProfile::getSubTargetingProfileInfo(this, pSimObject, &fDownedPedCameraOffsetRad);
  if ( v8 )
  {
    v9 = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
           &v8->m_AngularInputToSubTargetingLocations.p[0].m_SubTargetingLocationDynamic,
           v4);
    LOBYTE(v8) = UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(v7, v5, v9, v4, v6);
  }
  return (char)v8;
}

// File Line: 252
// RVA: 0x529EA0
char __usercall UFG::SubTargetingProfile::FindSubTargetingLocationPosWS@<al>(UFG::SubTargetingProfile *this@<rcx>, UFG::qVector3 *vSubTargetingLocationWS@<rdx>, UFG::SubTargetingLocation *pSubTargetingLocation@<r8>, UFG::SimObject *pSimObject@<r9>, __int128 a5@<xmm7>, Creature *pCreature)
{
  __int64 v6; // rdi
  UFG::SubTargetingLocation *v7; // rsi
  UFG::qVector3 *v8; // rbp
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  unsigned int v11; // er8
  unsigned int v12; // er11
  UFG::SimComponentHolder *v13; // rdx
  unsigned int v14; // er8
  unsigned int v15; // er11
  UFG::SimObjectProp *v16; // rbx
  unsigned __int16 v17; // cx
  UFG::CharacterAnimationComponent *v18; // rcx
  UFG::CharacterAnimationComponent *v19; // rax
  unsigned int v20; // er8
  unsigned int v21; // er10
  signed __int64 v22; // rdx
  Creature *v23; // rdi
  UFG::TransformNodeComponent *v24; // rbx
  UFG::qVector4 v25; // xmm2
  UFG::qVector4 v26; // xmm1
  UFG::qVector4 v27; // xmm0
  int v28; // eax
  float v29; // xmm2_4
  float v30; // xmm5_4
  char result; // al
  float v32; // xmm1_4
  float v33; // xmm0_4
  UFG::qMatrix44 transform; // [rsp+20h] [rbp-58h]
  __int128 v35; // [rsp+60h] [rbp-18h]

  v6 = (unsigned int)pSubTargetingLocation->m_eTargetType;
  v7 = pSubTargetingLocation;
  v8 = vSubTargetingLocationWS;
  if ( !(_DWORD)v6 )
    goto LABEL_51;
  if ( !pSimObject )
    return 0;
  v9 = pSimObject->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (v9 & 0x8000u) != 0 )
  {
    v10 = pSimObject->m_Components.p[20].m_pComponent;
    goto LABEL_23;
  }
  if ( (v9 >> 13) & 1 )
  {
    v11 = (unsigned int)pSimObject[1].vfptr;
    v12 = pSimObject->m_Components.size;
    if ( v11 < v12 )
    {
      v13 = &pSimObject->m_Components.p[v11];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF )
      {
        ++v11;
        ++v13;
        if ( v11 >= v12 )
          goto LABEL_13;
      }
LABEL_14:
      v10 = v13->m_pComponent;
      goto LABEL_23;
    }
    goto LABEL_13;
  }
  if ( (v9 >> 12) & 1 )
  {
    v14 = (unsigned int)pSimObject[1].vfptr;
    v15 = pSimObject->m_Components.size;
    if ( v14 < v15 )
    {
      v13 = &pSimObject->m_Components.p[v14];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF )
      {
        ++v14;
        ++v13;
        if ( v14 >= v15 )
        {
          v10 = 0i64;
          goto LABEL_23;
        }
      }
      goto LABEL_14;
    }
LABEL_13:
    v10 = 0i64;
    goto LABEL_23;
  }
  v10 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_23:
  if ( !v10 )
    return 0;
  v16 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v10[1].m_Flags + v6 + 8)
                               + *(_QWORD *)&v10[1].m_TypeUID
                               + 40);
  if ( !v16 )
    goto LABEL_51;
  v17 = v16->m_Flags;
  if ( (v17 >> 14) & 1 )
  {
    v18 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v18
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_29;
    }
    goto LABEL_47;
  }
  if ( (v17 & 0x8000u) != 0 )
  {
    v18 = (UFG::CharacterAnimationComponent *)v16->m_Components.p[9].m_pComponent;
    if ( !v18 || (UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000 )
      goto LABEL_29;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF )
      v18 = 0i64;
    goto LABEL_47;
  }
  if ( (v17 >> 13) & 1 )
  {
    v19 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v16);
LABEL_46:
    v18 = v19;
    goto LABEL_47;
  }
  if ( !((v17 >> 12) & 1) )
  {
    v19 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v16->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_46;
  }
  v20 = v16->mComponentTableEntryCount;
  v21 = v16->m_Components.size;
  if ( v20 >= v21 )
  {
LABEL_29:
    v18 = 0i64;
    goto LABEL_47;
  }
  v22 = (signed __int64)&v16->m_Components.p[v20];
  while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
  {
    ++v20;
    v22 += 16i64;
    if ( v20 >= v21 )
    {
      v18 = 0i64;
      goto LABEL_47;
    }
  }
  v18 = *(UFG::CharacterAnimationComponent **)v22;
LABEL_47:
  if ( !v18 || (v23 = v18->mCreature) == 0i64 )
  {
    v24 = v16->m_pTransformNodeComponent;
    if ( v24 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v24);
      v25 = v24->mWorldTransform.v2;
      v26 = v24->mWorldTransform.v3;
      v27 = v24->mWorldTransform.v0;
      transform.v1 = v24->mWorldTransform.v1;
      transform.v2 = v25;
      transform.v0 = v27;
      transform.v3 = v26;
LABEL_55:
      v29 = v7->m_vOffset.x;
      v30 = v7->m_vOffset.y;
      v35 = a5;
      result = 1;
      v32 = transform.v3.y
          + (float)((float)((float)(transform.v0.y * v29) + (float)(transform.v1.y * v30))
                  + (float)(transform.v2.y * v7->m_vOffset.z));
      v33 = transform.v3.z
          + (float)((float)((float)(transform.v0.z * v29) + (float)(transform.v1.z * v30))
                  + (float)(transform.v2.z * v7->m_vOffset.z));
      v8->x = transform.v3.x
            + (float)((float)((float)(transform.v0.x * v29) + (float)(transform.v1.x * v30))
                    + (float)(transform.v2.x * v7->m_vOffset.z));
      v8->y = v32;
      v8->z = v33;
      return result;
    }
LABEL_51:
    v23 = pCreature;
    if ( !pCreature )
      return 0;
  }
  if ( v23->mPose.mRigHandle.mData )
  {
    v28 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, v7->m_symBoneName.mUID);
    if ( v28 >= 0 )
    {
      Creature::GetTransform(v23, v28, &transform);
      goto LABEL_55;
    }
  }
  return 0;
}

// File Line: 331
// RVA: 0x529DB0
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingProfile::FindSubTargetingLocationByInput(UFG::SubTargetingProfile *this, UFG::SimObject *pTargetSimObject, float fInputAngle)
{
  UFG::SimObject *v3; // rbp
  UFG::SubTargetingProfile *v4; // r14
  UFG::SubTargetingProfileInfo *v5; // rax
  UFG::SubTargetingProfileInfo *v6; // rsi
  float v7; // xmm6_4
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned int v10; // edx
  signed __int64 v11; // rcx
  UFG::SubTargetingLocation *result; // rax
  signed __int64 v13; // rcx
  float fDownedPedCameraOffsetRad; // [rsp+70h] [rbp+18h]

  v3 = pTargetSimObject;
  v4 = this;
  if ( fInputAngle < 0.0 )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  fDownedPedCameraOffsetRad = 0.0;
  v5 = UFG::SubTargetingProfile::getSubTargetingProfileInfo(this, pTargetSimObject, &fDownedPedCameraOffsetRad);
  v6 = v5;
  if ( !v5 )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  v7 = fInputAngle - fDownedPedCameraOffsetRad;
  if ( (float)(fInputAngle - fDownedPedCameraOffsetRad) < 0.0 )
    v7 = v7 + 6.2831855;
  v8 = v5->m_AngularInputToSubTargetingLocations.size;
  v9 = 0;
  v10 = 0;
  if ( !v5->m_AngularInputToSubTargetingLocations.size )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  v11 = (signed __int64)v5->m_AngularInputToSubTargetingLocations.p;
  while ( *(float *)v11 < 0.0 || v7 > *(float *)v11 )
  {
    ++v10;
    v11 += 112i64;
    if ( v10 >= v8 )
      goto LABEL_12;
  }
  result = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation((UFG::SubTargetingLocationDynamic *)(v11 + 8), v3);
  if ( result )
    return result;
LABEL_12:
  if ( !v8 )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  v13 = (signed __int64)v6->m_AngularInputToSubTargetingLocations.p;
  while ( *(float *)v13 < 0.0 )
  {
    ++v9;
    v13 += 112i64;
    if ( v9 >= v8 )
      return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  }
  result = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation((UFG::SubTargetingLocationDynamic *)(v13 + 8), v3);
  if ( !result )
    return UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(&v4->m_DefaultSubTargetingLocationDynamic, v3);
  return result;
}

// File Line: 406
// RVA: 0x529A20
UFG::SubTargetingLocation *__fastcall UFG::SubTargetingProfile::FindSubTargetingLocationByAimOffset(UFG::SubTargetingProfile *this, UFG::SimObject *pTargetSimObject, UFG::qVector3 *vAimOffset, const float fRadiusMultiplier)
{
  UFG::qVector3 *v4; // r14
  UFG::SimObjectProp *v5; // rdi
  UFG::SubTargetingProfile *v6; // r12
  UFG::SubTargetingLocation *v7; // r15
  UFG::BaseCameraComponent *v8; // rax
  UFG::BaseCameraComponent *v9; // rax
  signed __int64 v10; // rax
  UFG::qVector3 *v11; // r13
  UFG::TransformNodeComponent *v12; // rbp
  unsigned __int16 v13; // cx
  UFG::CharacterAnimationComponent *v14; // rsi
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  UFG::CharacterAnimationComponent *v18; // rax
  unsigned int v19; // edx
  unsigned int v20; // er8
  signed __int64 v21; // rsi
  UFG::SubTargetingProfileInfo *v22; // rbx
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  Creature *pCreature; // rbp
  UFG::SubTargetingProfileInfo *v29; // rax
  UFG::SubTargetingLocation *v30; // rax
  unsigned int v31; // eax
  signed __int64 v32; // rbx
  __int64 v33; // r14
  UFG::SubTargetingLocation *v34; // rbp
  UFG::qVector3 *v35; // rax
  float v36; // xmm2_4
  float fDownedPedCameraOffsetRad; // [rsp+30h] [rbp-98h]
  UFG::qVector3 vSubTargetingLocationWS; // [rsp+38h] [rbp-90h]
  UFG::qVector3 end; // [rsp+48h] [rbp-80h]
  UFG::qVector3 result; // [rsp+58h] [rbp-70h]

  v4 = vAimOffset;
  v5 = (UFG::SimObjectProp *)pTargetSimObject;
  v6 = this;
  v7 = 0i64;
  v8 = UFG::Director::Get()->mCurrentCamera;
  if ( !v8 || v8 == (UFG::BaseCameraComponent *)-80i64 )
    return 0i64;
  v9 = UFG::Director::Get()->mCurrentCamera;
  if ( v9 )
    v10 = (signed __int64)&v9->mCamera;
  else
    v10 = 0i64;
  v11 = (UFG::qVector3 *)(v10 + 176);
  if ( !v5 )
    return v7;
  v12 = v5->m_pTransformNodeComponent;
  if ( !v12 )
    return v7;
  v13 = v5->m_Flags;
  if ( !((v13 >> 14) & 1) )
  {
    if ( (v13 & 0x8000u) != 0 )
    {
      v14 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
      if ( v14 )
      {
        v16 = v14->m_TypeUID;
        v15 = UFG::CharacterAnimationComponent::_TypeUID;
        v17 = UFG::CharacterAnimationComponent::_TypeUID ^ v14->m_TypeUID;
        goto LABEL_11;
      }
LABEL_13:
      v14 = 0i64;
      goto LABEL_29;
    }
    if ( (v13 >> 13) & 1 )
    {
      v18 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v5);
    }
    else
    {
      if ( (v13 >> 12) & 1 )
      {
        v19 = v5->mComponentTableEntryCount;
        v20 = v5->m_Components.size;
        if ( v19 < v20 )
        {
          v21 = (signed __int64)&v5->m_Components.p[v19];
          while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF )
          {
            ++v19;
            v21 += 16i64;
            if ( v19 >= v20 )
            {
              v14 = 0i64;
              goto LABEL_29;
            }
          }
          v14 = *(UFG::CharacterAnimationComponent **)v21;
          goto LABEL_29;
        }
        goto LABEL_13;
      }
      v18 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v5->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v14 = v18;
    goto LABEL_29;
  }
  v14 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
  if ( !v14 )
    goto LABEL_13;
  v15 = UFG::CharacterAnimationComponent::_TypeUID;
  v16 = v14->m_TypeUID;
  v17 = v16 ^ UFG::CharacterAnimationComponent::_TypeUID;
LABEL_11:
  if ( v17 & 0xFE000000 || v15 & ~v16 & 0x1FFFFFF )
    goto LABEL_13;
LABEL_29:
  if ( !v14 )
    return v7;
  fDownedPedCameraOffsetRad = 0.0;
  v22 = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
          v6,
          (UFG::SimObject *)&v5->vfptr,
          &fDownedPedCameraOffsetRad);
  if ( !v22 )
    return v7;
  v23 = FLOAT_3_4028235e38;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  v24 = v12->mWorldTransform.v3.x;
  v25 = v12->mWorldTransform.v3.y;
  fDownedPedCameraOffsetRad = 0.0;
  v26 = v25 + v4->y;
  end.x = v24 + v4->x;
  v27 = v12->mWorldTransform.v3.z;
  end.y = v26;
  pCreature = v14->mCreature;
  end.z = v27 + v4->z;
  v29 = UFG::SubTargetingProfile::getSubTargetingProfileInfo(
          v6,
          (UFG::SimObject *)&v5->vfptr,
          &fDownedPedCameraOffsetRad);
  if ( v29 )
  {
    v30 = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
            &v29->m_AngularInputToSubTargetingLocations.p[0].m_SubTargetingLocationDynamic,
            (UFG::SimObject *)&v5->vfptr);
    if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
           v6,
           &vSubTargetingLocationWS,
           v30,
           (UFG::SimObject *)&v5->vfptr,
           pCreature) )
    {
      v31 = v22->m_AngularInputToSubTargetingLocations.size;
      if ( v22->m_AngularInputToSubTargetingLocations.size )
      {
        v32 = (signed __int64)v22->m_AngularInputToSubTargetingLocations.p;
        v33 = v31;
        do
        {
          if ( *(float *)v32 >= 0.0 )
          {
            v34 = UFG::SubTargetingLocationDynamic::GetSubTargetingLocation(
                    (UFG::SubTargetingLocationDynamic *)(v32 + 8),
                    (UFG::SimObject *)&v5->vfptr);
            if ( UFG::SubTargetingProfile::FindSubTargetingLocationPosWS(
                   v6,
                   &vSubTargetingLocationWS,
                   v34,
                   (UFG::SimObject *)&v5->vfptr,
                   v14->mCreature) )
            {
              v35 = UFG::qNearestSegPoint(&result, v11, &end, &vSubTargetingLocationWS);
              v36 = (float)((float)((float)(vSubTargetingLocationWS.y - v35->y)
                                  * (float)(vSubTargetingLocationWS.y - v35->y))
                          + (float)((float)(vSubTargetingLocationWS.x - v35->x)
                                  * (float)(vSubTargetingLocationWS.x - v35->x)))
                  + (float)((float)(vSubTargetingLocationWS.z - v35->z) * (float)(vSubTargetingLocationWS.z - v35->z));
              if ( v36 < v23
                && v36 < (float)((float)(fRadiusMultiplier * v34->m_fRadius)
                               * (float)(fRadiusMultiplier * v34->m_fRadius)) )
              {
                v23 = (float)((float)((float)(vSubTargetingLocationWS.y - v35->y)
                                    * (float)(vSubTargetingLocationWS.y - v35->y))
                            + (float)((float)(vSubTargetingLocationWS.x - v35->x)
                                    * (float)(vSubTargetingLocationWS.x - v35->x)))
                    + (float)((float)(vSubTargetingLocationWS.z - v35->z) * (float)(vSubTargetingLocationWS.z - v35->z));
                v7 = v34;
              }
            }
          }
          v32 += 112i64;
          --v33;
        }
        while ( v33 );
      }
      return v7;
    }
  }
  return 0i64;
}

// File Line: 482
// RVA: 0x5691F0
UFG::SubTargetingProfileInfo *__fastcall UFG::SubTargetingProfile::getSubTargetingProfileInfo(UFG::SubTargetingProfile *this, UFG::SimObject *pTargetSimObject, float *fDownedPedCameraOffsetRad)
{
  float *v3; // r12
  UFG::SimObjectProp *v4; // rbx
  unsigned int v5; // esi
  unsigned __int16 v6; // dx
  UFG::CharacterAnimationComponent *v7; // rcx
  UFG::CharacterAnimationComponent *v8; // rax
  unsigned int v9; // er8
  unsigned int v10; // er10
  UFG::SimComponentHolder *v11; // rdi
  Creature *v12; // rdi
  UFG::TransformNodeComponent *v13; // r15
  UFG::qVector3 *v14; // r15
  UFG::BaseCameraComponent *v15; // r14
  signed __int64 v16; // r14
  int v17; // xmm7_4
  int v18; // xmm8_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  int v21; // eax
  signed int v22; // er13
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  unsigned int v25; // er8
  unsigned int v26; // er10
  UFG::SimComponentHolder *v27; // rbx
  signed __int64 v28; // rdx
  unsigned int v29; // er8
  unsigned int v30; // er10
  unsigned int v31; // er8
  unsigned int v32; // er10
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm4_4
  unsigned int v36; // er12
  __int64 v37; // rax
  float *v38; // rdi
  float v39; // xmm2_4
  float v40; // xmm7_4
  __m128 v41; // xmm8
  float v42; // xmm9_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  bool v45; // bl
  float v46; // xmm0_4
  float v47; // xmm2_4
  bool v48; // bl
  float v49; // xmm2_4
  UFG::qVector3 v1; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v52; // [rsp+30h] [rbp-98h]
  UFG::qVector3 v2; // [rsp+40h] [rbp-88h]
  float v54; // [rsp+4Ch] [rbp-7Ch]
  UFG::qVector3 v55; // [rsp+50h] [rbp-78h]
  UFG::qMatrix44 transform; // [rsp+60h] [rbp-68h]
  __int64 v57; // [rsp+128h] [rbp+60h]
  __int64 v58; // [rsp+130h] [rbp+68h]

  *(_QWORD *)&transform.v0.z = -2i64;
  v3 = fDownedPedCameraOffsetRad;
  v4 = (UFG::SimObjectProp *)pTargetSimObject;
  v5 = 0;
  *fDownedPedCameraOffsetRad = 0.0;
  if ( !pTargetSimObject )
    return 0i64;
  v6 = pTargetSimObject->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v7
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v7->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_6;
    }
    goto LABEL_24;
  }
  if ( (v6 & 0x8000u) != 0 )
  {
    v7 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v7 || (UFG::CharacterAnimationComponent::_TypeUID ^ v7->m_TypeUID) & 0xFE000000 )
      goto LABEL_6;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF )
      v7 = 0i64;
    goto LABEL_24;
  }
  if ( (v6 >> 13) & 1 )
  {
    v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v4);
LABEL_23:
    v7 = v8;
    goto LABEL_24;
  }
  if ( !((v6 >> 12) & 1) )
  {
    v8 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v4->vfptr,
                                               UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_23;
  }
  v9 = v4->mComponentTableEntryCount;
  v10 = v4->m_Components.size;
  if ( v9 >= v10 )
  {
LABEL_6:
    v7 = 0i64;
    goto LABEL_24;
  }
  v11 = v4->m_Components.p;
  while ( (v11[v9].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~v11[v9].m_TypeUID & 0x1FFFFFF )
  {
    if ( ++v9 >= v10 )
      goto LABEL_6;
  }
  v7 = (UFG::CharacterAnimationComponent *)v11[v9].m_pComponent;
LABEL_24:
  if ( !v7 )
    return 0i64;
  v12 = v7->mCreature;
  if ( !v12 )
    return 0i64;
  v13 = v4->m_pTransformNodeComponent;
  if ( !v13 )
    return 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v4->m_pTransformNodeComponent);
  v14 = (UFG::qVector3 *)&v13->mWorldTransform;
  v15 = UFG::Director::Get()->mCurrentCamera;
  if ( v15 )
    v16 = (signed __int64)&v15->mCamera;
  else
    v16 = 0i64;
  v17 = *(_DWORD *)(v16 + 164) ^ _xmm[0];
  v18 = *(_DWORD *)(v16 + 160) ^ _xmm[0];
  v19 = v14[4].z - *(float *)(v16 + 184);
  v20 = v14[4].y - *(float *)(v16 + 180);
  v55.x = v14[4].x - *(float *)(v16 + 176);
  v55.y = v20;
  v55.z = v19;
  if ( !(_S55 & 1) )
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
  v21 = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, pelvis_name.mUID);
  v22 = v21;
  if ( v21 < 0 )
    goto LABEL_66;
  Creature::GetTransform(v12, v21, &transform);
  v1.x = transform.v0.x;
  v1.y = transform.v0.y;
  v1.z = transform.v0.z;
  v2 = UFG::qVector3::msAxisZ;
  v23 = v4->m_Flags;
  if ( !((v23 >> 14) & 1) )
  {
    if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
      {
        v29 = v4->mComponentTableEntryCount;
        v30 = v4->m_Components.size;
        if ( v29 < v30 )
        {
          v27 = v4->m_Components.p;
          do
          {
            v28 = v29;
            if ( (v27[v29].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v29].m_TypeUID & 0x1FFFFFF) )
            {
              goto LABEL_43;
            }
          }
          while ( ++v29 < v30 );
        }
      }
      else
      {
        if ( !((v23 >> 12) & 1) )
        {
          v24 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v4->vfptr,
                  UFG::CharacterPhysicsComponent::_TypeUID);
          goto LABEL_60;
        }
        v31 = v4->mComponentTableEntryCount;
        v32 = v4->m_Components.size;
        if ( v31 < v32 )
        {
          v27 = v4->m_Components.p;
          do
          {
            v28 = v31;
            if ( (v27[v31].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
              && !(UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v31].m_TypeUID & 0x1FFFFFF) )
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
      v25 = v4->mComponentTableEntryCount;
      v26 = v4->m_Components.size;
      if ( v25 < v26 )
      {
        v27 = v4->m_Components.p;
        while ( 1 )
        {
          v28 = v25;
          if ( (v27[v25].m_TypeUID & 0xFE000000) == (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
            && !(UFG::CharacterPhysicsComponent::_TypeUID & ~v27[v25].m_TypeUID & 0x1FFFFFF) )
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
  v24 = v4->m_Components.p[27].m_pComponent;
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
    *v3 = v35;
    if ( (float)((float)((float)(v1.y * *(float *)(v16 + 132)) + (float)(v1.x * *(float *)(v16 + 128)))
               + (float)(v1.z * *(float *)(v16 + 136))) <= 0.0 )
      *v3 = 6.2831855 - v35;
  }
LABEL_66:
  v36 = *(_DWORD *)(v57 + 240);
  v37 = v22;
  v58 = v22;
  if ( !v36 )
    return 0i64;
  v38 = (float *)(v57 + 932);
  while ( 1 )
  {
    if ( v37 < 0 )
    {
      v48 = (float)((float)((float)(*(float *)(v16 + 132) * v14->y) + (float)(v14->x * *(float *)(v16 + 128)))
                  + (float)(*(float *)(v16 + 136) * v14->z)) <= 0.0;
      v47 = UFG::qAngleBetween(v14, &v55);
      if ( v48 )
        v47 = 6.2831855 - v47;
    }
    else
    {
      v41 = (__m128)LODWORD(v55.y);
      v39 = (float)((float)(transform.v0.y * v55.y) + (float)(transform.v0.x * v55.x)) + (float)(transform.v0.z * v55.z);
      v40 = v55.x - (float)(transform.v0.x * v39);
      v41.m128_f32[0] = v55.y - (float)(transform.v0.y * v39);
      v42 = v55.z - (float)(transform.v0.z * v39);
      v43 = v41;
      v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40)) + (float)(v42 * v42);
      if ( v43.m128_f32[0] == 0.0 )
        v44 = 0.0;
      else
        v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
      v52.x = v40 * v44;
      v52.y = v41.m128_f32[0] * v44;
      v52.z = v42 * v44;
      v45 = (float)((float)((float)(v54 * (float)(v41.m128_f32[0] * v44)) + (float)(v2.z * (float)(v40 * v44)))
                  + (float)(v55.x * (float)(v42 * v44))) <= 0.0;
      v46 = UFG::qAngleBetween((UFG::qVector3 *)&transform.v1, &v52);
      v47 = v46;
      if ( v45 )
        v47 = 6.2831855 - v46;
    }
    v49 = v47 - *(v38 - 1);
    if ( v49 < 0.0 )
      v49 = v49 + 6.2831855;
    if ( v49 >= 3.1415927 )
      v49 = 6.2831855 - v49;
    if ( v49 <= *v38 )
      break;
    ++v5;
    v38 += 172;
    v37 = v58;
    if ( v5 >= v36 )
      return 0i64;
  }
  return (UFG::SubTargetingProfileInfo *)(v38 - 171);
}

// File Line: 804
// RVA: 0x1543980
__int64 dynamic_initializer_for__UFG::SubTargetingProfiles::ms_SubTargetingProfilePool__()
{
  `eh vector constructor iterator(
    UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.p,
    0xBC0ui64,
    10,
    (void (__fastcall *)(void *))UFG::SubTargetingProfile::SubTargetingProfile);
  UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::SubTargetingProfiles::ms_SubTargetingProfilePool__);
}

// File Line: 805
// RVA: 0x15439E0
__int64 dynamic_initializer_for__UFG::SubTargetingProfiles::ms_SubTargetingProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::SubTargetingProfiles::ms_SubTargetingProfiles__);
}

// File Line: 808
// RVA: 0x5503E0
void UFG::SubTargetingProfiles::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int v3; // esi
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // ecx
  UFG::qBaseNodeRB *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "Targeting-SubTargetingProfiles-manifest");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( v0 )
  {
    UFG::qSymbol::create_from_string(&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      v3 = v1->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, v4);
          v6 = (UFG::qSymbolUC *)v5;
          if ( v5 )
          {
            v7 = UFG::PropertySetManager::GetPropertySet(v5);
            if ( v7 )
            {
              v8 = UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size;
              if ( UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size >= 0xA )
              {
                v10 = UFG::qSymbol::as_cstr_dbg(v6);
                UFG::qPrintf(
                  "WARNING: SubTargetingProfile::StaticInit: Pool is Full (%d) Not Adding (%s)\n",
                  10i64,
                  v10);
              }
              else
              {
                ++UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.size;
                v9 = &UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.p[v8].mNode;
                UFG::SubTargetingProfile::InitFromPropertySet(
                  &UFG::SubTargetingProfiles::ms_SubTargetingProfilePool.p[v8],
                  v7);
                UFG::qBaseTreeRB::Add(&UFG::SubTargetingProfiles::ms_SubTargetingProfiles.mTree, v9);
              }
            }
            else
            {
              v11 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Profile Not Found: %s\n", v11);
            }
          }
          ++v4;
        }
        while ( v4 < v3 );
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
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qPrintf("WARNING: SubTargetingProfile::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

