// File Line: 110
// RVA: 0x54A260
void __fastcall UFG::SimObjectUtility::ResetSimObject(
        UFG::SimObjectProp *pSimObjectResetting,
        UFG::SimObjectProp *pSimObjectToReset,
        bool bKeepItems)
{
  const char *v6; // rbx
  char *v7; // rdi
  char *v8; // rax
  signed __int16 m_Flags; // cx
  UFG::WorldContextComponent *ComponentOfType; // rdi
  UFG::SimComponent *m_pComponent; // rbp
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v14; // rdx
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  signed __int16 v17; // dx
  UFG::SimComponent *v18; // rdx
  UFG::CharacterAnimationComponent *v19; // rax
  unsigned int v20; // r8d
  unsigned int v21; // r9d
  UFG::SimComponentHolder *v22; // rdx
  Creature *v23; // r14
  __int64 p_mNext; // r10
  __int64 v25; // r9
  unsigned __int8 *v26; // rcx
  __int64 v27; // r8
  __int64 v28; // rbx
  signed __int16 v29; // cx
  unsigned int v30; // r8d
  unsigned int v31; // r10d
  UFG::SimComponentHolder *v32; // rdx
  unsigned int v33; // r8d
  unsigned int v34; // r10d
  unsigned int v35; // r8d
  unsigned int v36; // r10d

  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    if ( bKeepItems )
      v6 = "True";
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectResetting->m_Name);
    UFG::qPrintf(
      "ResetSimObject: %s(0x%x) Resetting %s(0x%x), Keep Items: %s\n",
      v8,
      pSimObjectResetting,
      v7,
      pSimObjectToReset,
      v6);
  }
  if ( pSimObjectResetting )
  {
    m_Flags = pSimObjectResetting->m_Flags;
    ComponentOfType = 0i64;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pSimObjectResetting->m_Components.p[20].m_pComponent;
      goto LABEL_26;
    }
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObjectResetting->m_Components.p[20].m_pComponent;
      goto LABEL_26;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      mComponentTableEntryCount = pSimObjectResetting->mComponentTableEntryCount;
      size = pSimObjectResetting->m_Components.size;
      if ( mComponentTableEntryCount < size )
      {
        v14 = &pSimObjectResetting->m_Components.p[mComponentTableEntryCount];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++mComponentTableEntryCount;
          ++v14;
          if ( mComponentTableEntryCount >= size )
            goto LABEL_16;
        }
LABEL_17:
        m_pComponent = v14->m_pComponent;
        goto LABEL_26;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(
                         pSimObjectResetting,
                         UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_26:
        v17 = pSimObjectResetting->m_Flags;
        if ( (v17 & 0x4000) != 0 )
        {
          v18 = pSimObjectResetting->m_Components.p[9].m_pComponent;
LABEL_28:
          if ( v18
            && ((UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000) == 0
            && (UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) == 0 )
          {
            goto LABEL_46;
          }
          goto LABEL_31;
        }
        if ( v17 < 0 )
        {
          v18 = pSimObjectResetting->m_Components.p[9].m_pComponent;
          goto LABEL_28;
        }
        if ( (v17 & 0x2000) != 0 )
        {
          v19 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pSimObjectResetting);
        }
        else
        {
          if ( (v17 & 0x1000) != 0 )
          {
            v20 = pSimObjectResetting->mComponentTableEntryCount;
            v21 = pSimObjectResetting->m_Components.size;
            if ( v20 >= v21 )
            {
LABEL_31:
              v18 = 0i64;
              goto LABEL_46;
            }
            v22 = &pSimObjectResetting->m_Components.p[v20];
            while ( (v22->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || (UFG::CharacterAnimationComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
            {
              ++v20;
              ++v22;
              if ( v20 >= v21 )
              {
                v18 = 0i64;
                goto LABEL_46;
              }
            }
            v18 = v22->m_pComponent;
LABEL_46:
            if ( v18 )
              v23 = *(Creature **)&v18[2].m_TypeUID;
            else
              v23 = 0i64;
            if ( v23 )
            {
              p_mNext = (__int64)&v23->mAttachments.mNode.mNext[-1].mNext;
              if ( v23->mAttachments.mNode.mNext != (UFG::qNode<Attachment,Attachment> *)8 )
              {
                do
                {
                  if ( (Creature *)p_mNext == (Creature *)&v23->mGroundNormal.z )
                    break;
                  if ( m_pComponent
                    && bKeepItems
                    && (v25 = *(_QWORD *)(p_mNext + 104)) != 0
                    && (v26 = *(unsigned __int8 **)&m_pComponent[1].m_Flags,
                        v27 = *(_QWORD *)&m_pComponent[1].m_TypeUID,
                        v25 == *(_QWORD *)(56i64 * v26[25] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[26] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[27] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[28] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[50] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[51] + v27 + 40)) )
                  {
                    p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
                  }
                  else
                  {
                    v28 = *(_QWORD *)(p_mNext + 16);
                    if ( pSimObjectResetting == pSimObjectToReset
                      || pSimObjectToReset == *(UFG::SimObjectProp **)(p_mNext + 104) )
                    {
                      Creature::RemoveAttachment(
                        v23,
                        pSimObjectResetting,
                        *(_DWORD *)(p_mNext + 32),
                        *(UFG::SimObject **)(p_mNext + 104));
                    }
                    p_mNext = v28 - 8;
                  }
                }
                while ( p_mNext );
              }
            }
            v29 = pSimObjectResetting->m_Flags;
            if ( (v29 & 0x4000) != 0 )
            {
              ComponentOfType = (UFG::WorldContextComponent *)pSimObjectResetting->m_Components.p[28].m_pComponent;
              goto LABEL_87;
            }
            if ( v29 < 0 )
            {
              v30 = pSimObjectResetting->mComponentTableEntryCount;
              v31 = pSimObjectResetting->m_Components.size;
              if ( v30 >= v31 )
                goto LABEL_87;
              v32 = &pSimObjectResetting->m_Components.p[v30];
              while ( (v32->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                   || (UFG::WorldContextComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v30;
                ++v32;
                if ( v30 >= v31 )
                  goto LABEL_87;
              }
              goto LABEL_71;
            }
            if ( (v29 & 0x2000) != 0 )
            {
              v33 = pSimObjectResetting->mComponentTableEntryCount;
              v34 = pSimObjectResetting->m_Components.size;
              if ( v33 < v34 )
              {
                v32 = &pSimObjectResetting->m_Components.p[v33];
                while ( (v32->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || (UFG::WorldContextComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v33;
                  ++v32;
                  if ( v33 >= v34 )
                    goto LABEL_87;
                }
LABEL_71:
                ComponentOfType = (UFG::WorldContextComponent *)v32->m_pComponent;
              }
            }
            else if ( (v29 & 0x1000) != 0 )
            {
              v35 = pSimObjectResetting->mComponentTableEntryCount;
              v36 = pSimObjectResetting->m_Components.size;
              if ( v35 < v36 )
              {
                v32 = &pSimObjectResetting->m_Components.p[v35];
                while ( (v32->m_TypeUID & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || (UFG::WorldContextComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v35;
                  ++v32;
                  if ( v35 >= v36 )
                    goto LABEL_87;
                }
                goto LABEL_71;
              }
            }
            else
            {
              ComponentOfType = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                                pSimObjectResetting,
                                                                UFG::WorldContextComponent::_TypeUID);
            }
LABEL_87:
            if ( ComponentOfType )
              UFG::WorldContextComponent::DetachAll(ComponentOfType);
            return;
          }
          v19 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      pSimObjectResetting,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v18 = v19;
        goto LABEL_46;
      }
      v15 = pSimObjectResetting->mComponentTableEntryCount;
      v16 = pSimObjectResetting->m_Components.size;
      if ( v15 < v16 )
      {
        v14 = &pSimObjectResetting->m_Components.p[v15];
        while ( (v14->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v14->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v15;
          ++v14;
          if ( v15 >= v16 )
          {
            m_pComponent = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_16:
    m_pComponent = 0i64;
    goto LABEL_26;
  }
}

// File Line: 185
// RVA: 0x54A8D0
void __fastcall UFG::SimObjectUtility::ResetState(
        UFG::SimObjectCharacter *pSimObjectToReset,
        bool bKeepItems,
        bool bDeleteItems)
{
  const char *v6; // rdi
  const char *v7; // rbx
  char *v8; // rax
  __int64 mComponentTableEntryCount; // r8
  __int64 size; // r9
  signed __int16 m_Flags; // cx
  UFG::TargetingSystemBaseComponent *m_pComponent; // r15
  UFG::SimComponentHolder *v13; // rdx
  int v14; // ecx
  __int64 v15; // r14
  __int64 v16; // rdx
  UFG::TargetingMap *m_pTargetingMap; // rax
  UFG::SimObjectProp *m_pPointer; // rbx
  __int16 v19; // cx
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v21; // rdx
  signed __int16 v22; // cx
  UFG::InventoryComponent *v23; // rax
  unsigned int v24; // r8d
  unsigned int v25; // r9d
  UFG::SimComponentHolder *v26; // rdx
  unsigned int v27; // r8d
  unsigned int v28; // r9d
  unsigned int v29; // r8d
  unsigned int v30; // r9d
  char v31; // di
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v33; // rcx
  UFG::SimObjectProp *v34; // rbx
  signed __int16 v35; // cx
  UFG::InventoryComponent *v36; // rax
  UFG::SimComponentHolder *v37; // rdx
  __int16 v38; // cx
  __int64 v39; // rdx
  UFG::PropInteractComponent *v40; // rax
  unsigned __int8 v41; // cl
  __int64 v42; // rbx
  UFG::TargetingSimObject *v43; // rax
  signed __int16 v44; // cx
  UFG::SimComponent *v45; // rbx
  unsigned int v46; // r8d
  unsigned int v47; // r9d
  UFG::SimComponentHolder *v48; // rdx
  unsigned int v49; // r8d
  unsigned int v50; // r9d
  unsigned int v51; // r8d
  unsigned int v52; // r9d
  float gravity; // xmm0_4
  signed __int16 v54; // cx
  UFG::SimComponent *v55; // rbx
  unsigned int v56; // edx
  unsigned int v57; // r8d
  UFG::SimComponentHolder *v58; // rbx
  unsigned int v59; // edx
  unsigned int v60; // r8d
  unsigned int v61; // edx
  unsigned int v62; // r8d
  UFG::qPropertySet *WritableProperties; // rax
  UFG::qPropertySet *v64; // rax
  int m_pSimObject; // eax
  signed __int16 v66; // cx
  UFG::CompositeDrawableComponent *v67; // rax
  unsigned int v68; // r8d
  unsigned int v69; // r9d
  UFG::SimComponentHolder *v70; // rdx
  signed __int16 v71; // cx
  UFG::SimComponent *v72; // rcx
  unsigned int v73; // r8d
  unsigned int v74; // r10d
  UFG::SimComponentHolder *v75; // rdx
  Creature *v76; // rcx
  signed __int16 v77; // cx
  UFG::SimComponent *v78; // rax
  unsigned int v79; // r8d
  unsigned int v80; // r10d
  UFG::SimComponentHolder *v81; // rdx
  signed __int16 v82; // cx
  UFG::SimComponent *v83; // rbx
  unsigned int v84; // r8d
  unsigned int v85; // r10d
  UFG::SimComponentHolder *v86; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rcx
  void *(__fastcall *vecDelDtor)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  ActionNodeRoot *v89; // rax
  signed __int16 v90; // cx
  UFG::ActorAudioComponent *v91; // rcx
  unsigned int v92; // r8d
  unsigned int v93; // r10d
  UFG::SimComponentHolder *v94; // rdx
  unsigned int v95; // r8d
  unsigned int v96; // r10d
  unsigned int v97; // r8d
  unsigned int v98; // r10d
  signed __int16 v99; // cx
  UFG::PowerManagementComponent *ComponentOfTypeHK; // rax

  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    v7 = "False";
    if ( bDeleteItems )
      v7 = "True";
    if ( bKeepItems )
      v6 = "True";
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    UFG::qPrintf("ResetState: %s(0x%x), Keep Items: %s Delete Items: %s\n", v8, pSimObjectToReset, v6, v7);
  }
  UFG::VehicleUtility::ExitVehicleNow(pSimObjectToReset, 0, 1, 1);
  UFG::IsAnyLocalPlayer(pSimObjectToReset);
  if ( !pSimObjectToReset )
    goto LABEL_247;
  m_Flags = pSimObjectToReset->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)pSimObjectToReset->m_Components.p[20].m_pComponent;
    goto LABEL_28;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::TargetingSystemBaseComponent *)pSimObjectToReset->m_Components.p[20].m_pComponent;
    goto LABEL_28;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
    size = pSimObjectToReset->m_Components.size;
    if ( (unsigned int)mComponentTableEntryCount < (unsigned int)size )
    {
      v13 = &pSimObjectToReset->m_Components.p[(unsigned int)mComponentTableEntryCount];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
        ++v13;
        if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
          goto LABEL_18;
      }
LABEL_19:
      m_pComponent = (UFG::TargetingSystemBaseComponent *)v13->m_pComponent;
      goto LABEL_28;
    }
    goto LABEL_18;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
    size = pSimObjectToReset->m_Components.size;
    if ( (unsigned int)mComponentTableEntryCount < (unsigned int)size )
    {
      v13 = &pSimObjectToReset->m_Components.p[(unsigned int)mComponentTableEntryCount];
      while ( (v13->m_TypeUID & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || (UFG::TargetingSystemBaseComponent::_TypeUID & ~v13->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
        ++v13;
        if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
        {
          m_pComponent = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_19;
    }
LABEL_18:
    m_pComponent = 0i64;
    goto LABEL_28;
  }
  m_pComponent = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                        pSimObjectToReset,
                                                        UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_28:
  if ( m_pComponent )
  {
    v14 = -2147483638;
    v15 = 0i64;
    v16 = 0xC0000160000i64;
    do
    {
      m_pTargetingMap = m_pComponent->m_pTargetingMap;
      if ( m_pTargetingMap->m_Map.p[v15] && ((unsigned int)v15 > 0x1F || !_bittest(&v14, v15)) )
      {
        if ( (_DWORD)v15 == 19 )
        {
          m_pPointer = (UFG::SimObjectProp *)m_pComponent->m_pTargets[(unsigned __int8)m_pTargetingMap->m_Map.p[19]].m_pTarget.m_pPointer;
          if ( m_pPointer )
          {
            v19 = m_pPointer->m_Flags;
            if ( (v19 & 0x4000) == 0 && v19 >= 0 )
            {
              if ( (v19 & 0x2000) != 0 )
              {
                ComponentOfType = m_pPointer->m_Components.p[11].m_pComponent;
              }
              else if ( (v19 & 0x1000) != 0 )
              {
                mComponentTableEntryCount = m_pPointer->mComponentTableEntryCount;
                size = m_pPointer->m_Components.size;
                if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                {
LABEL_45:
                  ComponentOfType = 0i64;
                }
                else
                {
                  v21 = (__int64)&m_pPointer->m_Components.p[(unsigned int)mComponentTableEntryCount];
                  while ( (*(_DWORD *)(v21 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                       || (UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v21 + 8) & 0x1FFFFFF) != 0 )
                  {
                    mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                    v21 += 16i64;
                    if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                      goto LABEL_45;
                  }
                  ComponentOfType = *(UFG::SimComponent **)v21;
                }
              }
              else
              {
                ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryItemComponent::_TypeUID);
              }
              if ( ComponentOfType && LODWORD(ComponentOfType[1].m_pSimObject) == 111 )
              {
                v22 = pSimObjectToReset->m_Flags;
                if ( (v22 & 0x4000) != 0 )
                {
                  v23 = (UFG::InventoryComponent *)pSimObjectToReset->m_Components.p[39].m_pComponent;
LABEL_75:
                  if ( v23 )
                  {
                    UFG::InventoryComponent::RemoveObjectFromInventory(v23, m_pPointer);
                    UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, eTARGET_TYPE_EQUIPPED_HAT);
                  }
                  UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
                  goto LABEL_144;
                }
                if ( v22 >= 0 )
                {
                  if ( (v22 & 0x2000) != 0 )
                  {
                    v27 = pSimObjectToReset->mComponentTableEntryCount;
                    v28 = pSimObjectToReset->m_Components.size;
                    if ( v27 < v28 )
                    {
                      v26 = &pSimObjectToReset->m_Components.p[v27];
                      while ( (v26->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                           || (UFG::InventoryComponent::_TypeUID & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
                      {
                        ++v27;
                        ++v26;
                        if ( v27 >= v28 )
                        {
                          v23 = 0i64;
                          goto LABEL_75;
                        }
                      }
                      goto LABEL_59;
                    }
                  }
                  else
                  {
                    if ( (v22 & 0x1000) == 0 )
                    {
                      v23 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                         pSimObjectToReset,
                                                         UFG::InventoryComponent::_TypeUID);
                      goto LABEL_75;
                    }
                    v29 = pSimObjectToReset->mComponentTableEntryCount;
                    v30 = pSimObjectToReset->m_Components.size;
                    if ( v29 < v30 )
                    {
                      v26 = &pSimObjectToReset->m_Components.p[v29];
                      while ( (v26->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                           || (UFG::InventoryComponent::_TypeUID & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
                      {
                        ++v29;
                        ++v26;
                        if ( v29 >= v30 )
                        {
                          v23 = 0i64;
                          goto LABEL_75;
                        }
                      }
                      goto LABEL_59;
                    }
                  }
                }
                else
                {
                  v24 = pSimObjectToReset->mComponentTableEntryCount;
                  v25 = pSimObjectToReset->m_Components.size;
                  if ( v24 < v25 )
                  {
                    v26 = &pSimObjectToReset->m_Components.p[v24];
                    while ( (v26->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                         || (UFG::InventoryComponent::_TypeUID & ~v26->m_TypeUID & 0x1FFFFFF) != 0 )
                    {
                      ++v24;
                      ++v26;
                      if ( v24 >= v25 )
                        goto LABEL_58;
                    }
LABEL_59:
                    v23 = (UFG::InventoryComponent *)v26->m_pComponent;
                    goto LABEL_75;
                  }
                }
LABEL_58:
                v23 = 0i64;
                goto LABEL_75;
              }
            }
          }
        }
        else if ( (unsigned int)v15 > 0x2B || !_bittest64(&v16, (int)v15) )
        {
          v31 = 0;
LABEL_83:
          m_pTargets = m_pComponent->m_pTargets;
          v33 = (unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v15];
          if ( m_pTargets[v33].m_pTarget.m_pPointer && m_pTargets[v33].m_bLock )
          {
            v34 = (UFG::SimObjectProp *)m_pTargets[v33].m_pTarget.m_pPointer;
            if ( v34 )
            {
              if ( pSimObjectToReset == LocalPlayer )
                UFG::GameStatAction::Inventory::UnEquip(0);
              v35 = pSimObjectToReset->m_Flags;
              if ( (v35 & 0x4000) != 0 )
              {
                v36 = (UFG::InventoryComponent *)pSimObjectToReset->m_Components.p[39].m_pComponent;
                goto LABEL_113;
              }
              if ( v35 >= 0 )
              {
                if ( (v35 & 0x2000) != 0 )
                {
                  mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
                  size = pSimObjectToReset->m_Components.size;
                  if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    goto LABEL_96;
                  v37 = &pSimObjectToReset->m_Components.p[(unsigned int)mComponentTableEntryCount];
                  while ( (v37->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || (UFG::InventoryComponent::_TypeUID & ~v37->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                    ++v37;
                    if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    {
                      v36 = 0i64;
                      goto LABEL_113;
                    }
                  }
                }
                else
                {
                  if ( (v35 & 0x1000) == 0 )
                  {
                    v36 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                       pSimObjectToReset,
                                                       UFG::InventoryComponent::_TypeUID);
                    goto LABEL_113;
                  }
                  mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
                  size = pSimObjectToReset->m_Components.size;
                  if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    goto LABEL_96;
                  v37 = &pSimObjectToReset->m_Components.p[(unsigned int)mComponentTableEntryCount];
                  while ( (v37->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || (UFG::InventoryComponent::_TypeUID & ~v37->m_TypeUID & 0x1FFFFFF) != 0 )
                  {
                    mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                    ++v37;
                    if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    {
                      v36 = 0i64;
                      goto LABEL_113;
                    }
                  }
                }
LABEL_97:
                v36 = (UFG::InventoryComponent *)v37->m_pComponent;
                goto LABEL_113;
              }
              mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
              size = pSimObjectToReset->m_Components.size;
              if ( (unsigned int)mComponentTableEntryCount < (unsigned int)size )
              {
                v37 = &pSimObjectToReset->m_Components.p[(unsigned int)mComponentTableEntryCount];
                while ( (v37->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                     || (UFG::InventoryComponent::_TypeUID & ~v37->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                  ++v37;
                  if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    goto LABEL_96;
                }
                goto LABEL_97;
              }
LABEL_96:
              v36 = 0i64;
LABEL_113:
              if ( v36 )
                UFG::InventoryComponent::RemoveObjectFromInventory(v36, v34);
              v38 = v34->m_Flags;
              if ( (v38 & 0x4000) != 0 )
              {
                mComponentTableEntryCount = v34->mComponentTableEntryCount;
                size = v34->m_Components.size;
                if ( (unsigned int)mComponentTableEntryCount < (unsigned int)size )
                {
                  v39 = (__int64)&v34->m_Components.p[(unsigned int)mComponentTableEntryCount];
                  while ( (*(_DWORD *)(v39 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                       || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v39 + 8) & 0x1FFFFFF) != 0 )
                  {
                    mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                    v39 += 16i64;
                    if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                      goto LABEL_121;
                  }
                  goto LABEL_122;
                }
LABEL_121:
                v40 = 0i64;
              }
              else if ( v38 >= 0 )
              {
                if ( (v38 & 0x2000) != 0 )
                {
                  v40 = (UFG::PropInteractComponent *)v34->m_Components.p[13].m_pComponent;
                }
                else if ( (v38 & 0x1000) != 0 )
                {
                  mComponentTableEntryCount = v34->mComponentTableEntryCount;
                  size = v34->m_Components.size;
                  if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    goto LABEL_121;
                  v39 = (__int64)&v34->m_Components.p[(unsigned int)mComponentTableEntryCount];
                  while ( (*(_DWORD *)(v39 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                       || (UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v39 + 8) & 0x1FFFFFF) != 0 )
                  {
                    mComponentTableEntryCount = (unsigned int)(mComponentTableEntryCount + 1);
                    v39 += 16i64;
                    if ( (unsigned int)mComponentTableEntryCount >= (unsigned int)size )
                    {
                      v40 = 0i64;
                      goto LABEL_135;
                    }
                  }
LABEL_122:
                  v40 = *(UFG::PropInteractComponent **)v39;
                }
                else
                {
                  v40 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                        v34,
                                                        UFG::PropInteractComponent::_TypeUID);
                }
              }
              else
              {
                v40 = (UFG::PropInteractComponent *)v34->m_Components.p[33].m_pComponent;
              }
LABEL_135:
              if ( v40 )
                UFG::PropInteractComponent::DetachFromObject(v40, pSimObjectToReset, mComponentTableEntryCount, size);
              UFG::SimObjectUtility::ResetSimObject(v34, (UFG::SimObjectProp *)pSimObjectToReset, 0);
              if ( v31 && bDeleteItems )
                UFG::SimObject::Destroy(v34);
            }
            LOBYTE(size) = 1;
            ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, const char *, _QWORD, _QWORD))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
              m_pComponent,
              (unsigned int)v15,
              0i64,
              size,
              0,
              "SimObjectUtility::ResetState",
              0i64,
              0i64);
          }
          v41 = m_pComponent->m_pTargetingMap->m_Map.p[v15];
          if ( v41 )
          {
            v42 = v41;
            UFG::TargetingSimObject::SetTarget(&m_pComponent->m_pTargets[v42], 0i64);
            v43 = m_pComponent->m_pTargets;
            if ( v43[v42].m_bLock )
              v43[v42].m_bLock = 0;
          }
          goto LABEL_144;
        }
        v31 = 1;
        if ( !bKeepItems )
          goto LABEL_83;
      }
LABEL_144:
      v15 = (unsigned int)(v15 + 1);
      v14 = -2147483638;
      v16 = 0xC0000160000i64;
    }
    while ( (int)v15 < 91 );
  }
  v44 = pSimObjectToReset->m_Flags;
  if ( (v44 & 0x4000) != 0 )
  {
    v45 = pSimObjectToReset->m_Components.p[27].m_pComponent;
    goto LABEL_170;
  }
  if ( v44 < 0 )
  {
    v46 = pSimObjectToReset->mComponentTableEntryCount;
    v47 = pSimObjectToReset->m_Components.size;
    if ( v46 < v47 )
    {
      v48 = &pSimObjectToReset->m_Components.p[v46];
      while ( (v48->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v48->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v46;
        ++v48;
        if ( v46 >= v47 )
          goto LABEL_153;
      }
LABEL_154:
      v45 = v48->m_pComponent;
      goto LABEL_170;
    }
    goto LABEL_153;
  }
  if ( (v44 & 0x2000) != 0 )
  {
    v49 = pSimObjectToReset->mComponentTableEntryCount;
    v50 = pSimObjectToReset->m_Components.size;
    if ( v49 < v50 )
    {
      v48 = &pSimObjectToReset->m_Components.p[v49];
      while ( (v48->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v48->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v49;
        ++v48;
        if ( v49 >= v50 )
        {
          v45 = 0i64;
          goto LABEL_170;
        }
      }
      goto LABEL_154;
    }
LABEL_153:
    v45 = 0i64;
    goto LABEL_170;
  }
  if ( (v44 & 0x1000) != 0 )
  {
    v51 = pSimObjectToReset->mComponentTableEntryCount;
    v52 = pSimObjectToReset->m_Components.size;
    if ( v51 < v52 )
    {
      v48 = &pSimObjectToReset->m_Components.p[v51];
      while ( (v48->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v48->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v51;
        ++v48;
        if ( v51 >= v52 )
        {
          v45 = 0i64;
          goto LABEL_170;
        }
      }
      goto LABEL_154;
    }
    goto LABEL_153;
  }
  v45 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_170:
  if ( v45 )
  {
    UFG::CharacterPhysicsComponent::SetCollisionModel((UFG::CharacterPhysicsComponent *)v45, CP_WALK);
    gravity = UFG::BasePhysicsSystem::mParam.gravity;
    v45[9].m_NameUID &= ~1u;
    *(float *)&v45[9].m_SafePointerList.mNode.mPrev = gravity;
  }
  v54 = pSimObjectToReset->m_Flags;
  if ( (v54 & 0x4000) != 0 )
  {
    v55 = pSimObjectToReset->m_Components.p[42].m_pComponent;
    goto LABEL_197;
  }
  if ( v54 < 0 )
  {
    v56 = pSimObjectToReset->mComponentTableEntryCount;
    v57 = pSimObjectToReset->m_Components.size;
    if ( v56 < v57 )
    {
      v58 = &pSimObjectToReset->m_Components.p[v56];
      while ( (v58->m_TypeUID & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || (UFG::RagdollComponent::_TypeUID & ~v58->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v56;
        ++v58;
        if ( v56 >= v57 )
          goto LABEL_180;
      }
LABEL_181:
      v55 = v58->m_pComponent;
      goto LABEL_197;
    }
    goto LABEL_180;
  }
  if ( (v54 & 0x2000) != 0 )
  {
    v59 = pSimObjectToReset->mComponentTableEntryCount;
    v60 = pSimObjectToReset->m_Components.size;
    if ( v59 < v60 )
    {
      v58 = &pSimObjectToReset->m_Components.p[v59];
      while ( (v58->m_TypeUID & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || (UFG::RagdollComponent::_TypeUID & ~v58->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v59;
        ++v58;
        if ( v59 >= v60 )
        {
          v55 = 0i64;
          goto LABEL_197;
        }
      }
      goto LABEL_181;
    }
LABEL_180:
    v55 = 0i64;
    goto LABEL_197;
  }
  if ( (v54 & 0x1000) != 0 )
  {
    v61 = pSimObjectToReset->mComponentTableEntryCount;
    v62 = pSimObjectToReset->m_Components.size;
    if ( v61 < v62 )
    {
      v58 = &pSimObjectToReset->m_Components.p[v61];
      while ( (v58->m_TypeUID & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || (UFG::RagdollComponent::_TypeUID & ~v58->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v61;
        ++v58;
        if ( v61 >= v62 )
        {
          v55 = 0i64;
          goto LABEL_197;
        }
      }
      goto LABEL_181;
    }
    goto LABEL_180;
  }
  v55 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::RagdollComponent::_TypeUID);
LABEL_197:
  if ( v55 )
  {
    UFG::RagdollComponent::ClearConstraints((UFG::RagdollComponent *)v55);
    WritableProperties = UFG::SceneObjectProperties::GetWritableProperties(pSimObjectToReset->m_pSceneObj);
    v64 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            WritableProperties,
            (UFG::qArray<unsigned long,0> *)&component_Ragdoll::sPropertyName,
            DEPTH_RECURSE);
    if ( v64 && UFG::qPropertySet::GetMemImagePtr(v64) )
    {
      if ( LODWORD(v55[2].m_SafePointerList.mNode.mPrev) != 5 )
      {
        m_pSimObject = (int)v55[3].m_pSimObject;
        if ( m_pSimObject > 1 )
        {
          do
            --m_pSimObject;
          while ( m_pSimObject > 1 );
          LODWORD(v55[3].m_pSimObject) = m_pSimObject;
        }
      }
      UFG::RagdollComponent::ResetState((UFG::RagdollComponent *)v55);
    }
    else
    {
      UFG::RagdollComponent::Release((UFG::RagdollComponent *)v55, 1);
    }
  }
  v66 = pSimObjectToReset->m_Flags;
  if ( (v66 & 0x4000) != 0 )
  {
    v67 = (UFG::CompositeDrawableComponent *)pSimObjectToReset->m_Components.p[14].m_pComponent;
  }
  else if ( v66 >= 0 )
  {
    if ( (v66 & 0x2000) != 0 )
    {
      v67 = (UFG::CompositeDrawableComponent *)pSimObjectToReset->m_Components.p[9].m_pComponent;
    }
    else if ( (v66 & 0x1000) != 0 )
    {
      v68 = pSimObjectToReset->mComponentTableEntryCount;
      v69 = pSimObjectToReset->m_Components.size;
      if ( v68 >= v69 )
      {
LABEL_218:
        v67 = 0i64;
      }
      else
      {
        v70 = &pSimObjectToReset->m_Components.p[v68];
        while ( (v70->m_TypeUID & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
             || (UFG::CompositeDrawableComponent::_TypeUID & ~v70->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v68;
          ++v70;
          if ( v68 >= v69 )
            goto LABEL_218;
        }
        v67 = (UFG::CompositeDrawableComponent *)v70->m_pComponent;
      }
    }
    else
    {
      v67 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                 pSimObjectToReset,
                                                 UFG::CompositeDrawableComponent::_TypeUID);
    }
  }
  else
  {
    v67 = (UFG::CompositeDrawableComponent *)pSimObjectToReset->m_Components.p[14].m_pComponent;
  }
  if ( v67 )
    UFG::CompositeDrawableComponent::Reset(v67);
  v71 = pSimObjectToReset->m_Flags;
  if ( (v71 & 0x4000) != 0 )
  {
    v72 = pSimObjectToReset->m_Components.p[9].m_pComponent;
LABEL_225:
    if ( !v72
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v72->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v72->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_228;
    }
    goto LABEL_245;
  }
  if ( v71 < 0 )
  {
    v72 = pSimObjectToReset->m_Components.p[9].m_pComponent;
    if ( !v72 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v72->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_228;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v72->m_TypeUID & 0x1FFFFFF) != 0 )
      v72 = 0i64;
    goto LABEL_245;
  }
  if ( (v71 & 0x2000) != 0 )
  {
    v72 = pSimObjectToReset->m_Components.p[8].m_pComponent;
    goto LABEL_225;
  }
  if ( (v71 & 0x1000) != 0 )
  {
    v73 = pSimObjectToReset->mComponentTableEntryCount;
    v74 = pSimObjectToReset->m_Components.size;
    if ( v73 >= v74 )
    {
LABEL_228:
      v72 = 0i64;
      goto LABEL_245;
    }
    v75 = &pSimObjectToReset->m_Components.p[v73];
    while ( (v75->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
         || (UFG::CharacterAnimationComponent::_TypeUID & ~v75->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      ++v73;
      ++v75;
      if ( v73 >= v74 )
      {
        v72 = 0i64;
        goto LABEL_245;
      }
    }
    v72 = v75->m_pComponent;
  }
  else
  {
    v72 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::CharacterAnimationComponent::_TypeUID);
  }
LABEL_245:
  if ( v72 )
  {
    v76 = *(Creature **)&v72[2].m_TypeUID;
    goto LABEL_248;
  }
LABEL_247:
  v76 = 0i64;
LABEL_248:
  if ( v76 )
    Creature::MakeUpright(v76, 0.0);
  if ( pSimObjectToReset )
  {
    v77 = pSimObjectToReset->m_Flags;
    if ( (v77 & 0x4000) != 0 )
    {
      v78 = pSimObjectToReset->m_Components.p[7].m_pComponent;
    }
    else if ( v77 >= 0 )
    {
      if ( (v77 & 0x2000) != 0 )
      {
        v78 = pSimObjectToReset->m_Components.p[6].m_pComponent;
      }
      else if ( (v77 & 0x1000) != 0 )
      {
        v79 = pSimObjectToReset->mComponentTableEntryCount;
        v80 = pSimObjectToReset->m_Components.size;
        if ( v79 >= v80 )
        {
LABEL_263:
          v78 = 0i64;
        }
        else
        {
          v81 = &pSimObjectToReset->m_Components.p[v79];
          while ( (v81->m_TypeUID & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
               || (UFG::ActionTreeComponent::_TypeUID & ~v81->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v79;
            ++v81;
            if ( v79 >= v80 )
              goto LABEL_263;
          }
          v78 = v81->m_pComponent;
        }
      }
      else
      {
        v78 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v78 = pSimObjectToReset->m_Components.p[7].m_pComponent;
    }
    if ( v78 )
      ActionController::Stop((ActionController *)&v78[3]);
    v82 = pSimObjectToReset->m_Flags;
    if ( (v82 & 0x4000) != 0 )
    {
      v83 = pSimObjectToReset->m_Components.p[31].m_pComponent;
    }
    else
    {
      if ( v82 < 0 || (v82 & 0x2000) != 0 )
        goto LABEL_286;
      if ( (v82 & 0x1000) != 0 )
      {
        v84 = pSimObjectToReset->mComponentTableEntryCount;
        v85 = pSimObjectToReset->m_Components.size;
        if ( v84 >= v85 )
        {
LABEL_278:
          v83 = 0i64;
        }
        else
        {
          v86 = &pSimObjectToReset->m_Components.p[v84];
          while ( (v86->m_TypeUID & 0xFE000000) != (UFG::FacialActionTreeComponent::_TypeUID & 0xFE000000)
               || (UFG::FacialActionTreeComponent::_TypeUID & ~v86->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v84;
            ++v86;
            if ( v84 >= v85 )
              goto LABEL_278;
          }
          v83 = v86->m_pComponent;
        }
      }
      else
      {
        v83 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::FacialActionTreeComponent::_TypeUID);
      }
    }
    if ( v83 )
    {
      if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
      {
        ActionController::Stop((ActionController *)&v83[3].m_SafePointerList);
        vfptr = v83[3].vfptr;
        if ( vfptr )
        {
          vecDelDtor = vfptr[3].__vecDelDtor;
          if ( vecDelDtor )
          {
            v89 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(void *(__fastcall *)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int)))(*(_QWORD *)vecDelDtor + 144i64))(vecDelDtor);
            ActionNodeRoot::Init(v89, (ActionContext *)v83[3].vfptr);
          }
        }
      }
    }
LABEL_286:
    v90 = pSimObjectToReset->m_Flags;
    if ( (v90 & 0x4000) != 0 )
    {
      v91 = (UFG::ActorAudioComponent *)pSimObjectToReset->m_Components.p[40].m_pComponent;
      if ( v91
        && ((UFG::ActorAudioComponent::_TypeUID ^ v91->m_TypeUID) & 0xFE000000) == 0
        && (UFG::ActorAudioComponent::_TypeUID & ~v91->m_TypeUID & 0x1FFFFFF) == 0 )
      {
        goto LABEL_314;
      }
      goto LABEL_290;
    }
    if ( v90 >= 0 )
    {
      if ( (v90 & 0x2000) == 0 )
      {
        if ( (v90 & 0x1000) == 0 )
        {
          v91 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                              pSimObjectToReset,
                                              UFG::ActorAudioComponent::_TypeUID);
          goto LABEL_314;
        }
        v97 = pSimObjectToReset->mComponentTableEntryCount;
        v98 = pSimObjectToReset->m_Components.size;
        if ( v97 >= v98 )
          goto LABEL_290;
        v94 = &pSimObjectToReset->m_Components.p[v97];
        while ( (v94->m_TypeUID & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || (UFG::ActorAudioComponent::_TypeUID & ~v94->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v97;
          ++v94;
          if ( v97 >= v98 )
          {
            v91 = 0i64;
            goto LABEL_314;
          }
        }
LABEL_298:
        v91 = (UFG::ActorAudioComponent *)v94->m_pComponent;
        goto LABEL_314;
      }
      v95 = pSimObjectToReset->mComponentTableEntryCount;
      v96 = pSimObjectToReset->m_Components.size;
      if ( v95 < v96 )
      {
        v94 = &pSimObjectToReset->m_Components.p[v95];
        while ( (v94->m_TypeUID & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || (UFG::ActorAudioComponent::_TypeUID & ~v94->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v95;
          ++v94;
          if ( v95 >= v96 )
          {
            v91 = 0i64;
            goto LABEL_314;
          }
        }
        goto LABEL_298;
      }
    }
    else
    {
      v92 = pSimObjectToReset->mComponentTableEntryCount;
      v93 = pSimObjectToReset->m_Components.size;
      if ( v92 < v93 )
      {
        v94 = &pSimObjectToReset->m_Components.p[v92];
        while ( (v94->m_TypeUID & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || (UFG::ActorAudioComponent::_TypeUID & ~v94->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v92;
          ++v94;
          if ( v92 >= v93 )
          {
            v91 = 0i64;
            goto LABEL_314;
          }
        }
        goto LABEL_298;
      }
    }
LABEL_290:
    v91 = 0i64;
LABEL_314:
    if ( v91 )
      UFG::ActorAudioComponent::Reset(v91);
    v99 = pSimObjectToReset->m_Flags;
    if ( (v99 & 0x4000) != 0 || v99 < 0 || (v99 & 0x2000) != 0 || (v99 & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             pSimObjectToReset,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             pSimObjectToReset,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::PowerManagementComponent::Reset(ComponentOfTypeHK);
  }
  UFG::SimObjectUtility::ResetSimObject(
    (UFG::SimObjectProp *)pSimObjectToReset,
    (UFG::SimObjectProp *)pSimObjectToReset,
    bKeepItems);
}( v91 )
      UFG::ActorAudioComponent::Reset(v91);
    v99 = pSimObjectToReset->m_Flags;
    if ( (v99 & 0x4000) != 0 || v99 < 0 || (v99 & 0x2000) != 0 || (v99 & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             pSimObjectToReset,
                                                             UFG::PowerManagementComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             pSimObjectToReset,
                                                             UFG::PowerManagementComponent::_TypeUID);
    if ( ComponentOfTy

// File Line: 392
// RVA: 0x563620
void __fastcall UFG::SimObjectUtility::UpgradeModelResolution(UFG::SimObjectProp *pObject)
{
  int v1; // esi
  signed __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v7; // rdx
  UFG::PedSpawnManager *Instance; // rax
  UFG::SimComponent *PedInfoFromSimObject; // rax
  UFG::SimComponent *v10; // rdi

  v1 = 0;
  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = pObject->mComponentTableEntryCount;
        size = pObject->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v7 = &pObject->m_Components.p[mComponentTableEntryCount];
          while ( (v7->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || (UFG::StreamedResourceComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            ++v7;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_14;
          }
          m_pComponent = (UFG::StreamedResourceComponent *)v7->m_pComponent;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                           pObject,
                                                           UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::UpgradeResolution(m_pComponent);
  }
  Instance = UFG::PedSpawnManager::GetInstance();
  PedInfoFromSimObject = UFG::PedSpawnManager::FindPedInfoFromSimObject(Instance, pObject);
  v10 = PedInfoFromSimObject;
  if ( PedInfoFromSimObject )
    v1 = *(_DWORD *)(&PedInfoFromSimObject[10].m_SimObjIndex + 1);
  UFG::SimObjectUtility::PostRigChangeReset(pObject);
  if ( v10 )
    *(_DWORD *)(&v10[10].m_SimObjIndex + 1) = v1;
}

// File Line: 418
// RVA: 0x526650
void __fastcall UFG::SimObjectUtility::DowngradeModelResolution(UFG::SimObjectGame *pObject)
{
  int v1; // esi
  signed __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v7; // rdx
  UFG::PedSpawnManager *Instance; // rax
  UFG::SimComponent *PedInfoFromSimObject; // rax
  UFG::SimComponent *v10; // rdi

  v1 = 0;
  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = pObject->mComponentTableEntryCount;
        size = pObject->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_14:
          m_pComponent = 0i64;
        }
        else
        {
          v7 = &pObject->m_Components.p[mComponentTableEntryCount];
          while ( (v7->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || (UFG::StreamedResourceComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            ++v7;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_14;
          }
          m_pComponent = (UFG::StreamedResourceComponent *)v7->m_pComponent;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                           pObject,
                                                           UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pObject->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::DowngradeResolution(m_pComponent);
  }
  Instance = UFG::PedSpawnManager::GetInstance();
  PedInfoFromSimObject = UFG::PedSpawnManager::FindPedInfoFromSimObject(Instance, pObject);
  v10 = PedInfoFromSimObject;
  if ( PedInfoFromSimObject )
    v1 = *(_DWORD *)(&PedInfoFromSimObject[10].m_SimObjIndex + 1);
  UFG::SimObjectUtility::PostRigChangeReset(pObject);
  if ( v10 )
    *(_DWORD *)(&v10[10].m_SimObjIndex + 1) = v1;
}

// File Line: 442
// RVA: 0x542830
void __fastcall UFG::SimObjectUtility::PostRigChangeReset(UFG::SimObjectProp *pObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rcx
  unsigned int v4; // edx
  unsigned int m_TypeUID; // edx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int mComponentTableEntryCount; // ecx
  unsigned int size; // r9d
  UFG::SimComponentHolder *p; // rdi
  CharacterDamageRig *v10; // rdx
  signed __int16 v11; // cx
  UFG::CompositeDrawableComponent *v12; // rax
  unsigned int v13; // ecx
  unsigned int v14; // r9d
  UFG::SimComponentHolder *v15; // rdi
  signed __int16 v16; // cx
  UFG::RagdollComponent *v17; // rax
  unsigned int v18; // ecx
  unsigned int v19; // r9d
  UFG::SimComponentHolder *v20; // rdi
  __int64 v21; // r8
  unsigned int v22; // ecx
  unsigned int v23; // r9d
  unsigned int v24; // ecx
  unsigned int v25; // r9d
  signed __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  unsigned int v28; // ecx
  unsigned int v29; // r9d
  UFG::SimComponentHolder *v30; // rdi
  signed __int16 v31; // cx
  UFG::SimComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // ecx
  unsigned int v35; // r9d
  UFG::SimComponentHolder *v36; // rdi
  CharacterDamageRig *v37; // rcx
  CharacterDamageRig source; // [rsp+30h] [rbp-318h] BYREF

  CharacterDamageRig::CharacterDamageRig(&source);
  if ( !pObject )
    goto LABEL_27;
  m_Flags = pObject->m_Flags;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = pObject->m_Components.p[9].m_pComponent;
      if ( m_pComponent )
      {
        m_TypeUID = m_pComponent->m_TypeUID;
        if ( ((m_TypeUID ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) == 0 )
        {
          if ( (UFG::CharacterAnimationComponent::_TypeUID & ~m_TypeUID & 0x1FFFFFF) != 0 )
            m_pComponent = 0i64;
          goto LABEL_24;
        }
      }
      goto LABEL_6;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pObject);
    }
    else
    {
      if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = pObject->mComponentTableEntryCount;
        size = pObject->m_Components.size;
        if ( mComponentTableEntryCount < size )
        {
          p = pObject->m_Components.p;
          while ( (p[mComponentTableEntryCount].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~p[mComponentTableEntryCount].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++mComponentTableEntryCount >= size )
              goto LABEL_6;
          }
          m_pComponent = p[mComponentTableEntryCount].m_pComponent;
          goto LABEL_24;
        }
        goto LABEL_6;
      }
      ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                              pObject,
                                                              UFG::CharacterAnimationComponent::_TypeUID);
    }
    m_pComponent = ComponentOfType;
    goto LABEL_24;
  }
  m_pComponent = pObject->m_Components.p[9].m_pComponent;
  if ( !m_pComponent
    || (v4 = m_pComponent->m_TypeUID, ((v4 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) != 0)
    || (UFG::CharacterAnimationComponent::_TypeUID & ~v4 & 0x1FFFFFF) != 0 )
  {
LABEL_6:
    m_pComponent = 0i64;
  }
LABEL_24:
  if ( m_pComponent )
  {
    v10 = *(CharacterDamageRig **)&m_pComponent[3].m_Flags;
    if ( v10 )
      CharacterDamageRig::Clone(&source, v10);
  }
LABEL_27:
  UFG::SimObjectUtility::ReinitializeSimObject(pObject, 0, 1);
  if ( !pObject )
    goto LABEL_117;
  v11 = pObject->m_Flags;
  if ( (v11 & 0x4000) != 0 )
  {
    v12 = (UFG::CompositeDrawableComponent *)pObject->m_Components.p[14].m_pComponent;
  }
  else if ( v11 >= 0 )
  {
    if ( (v11 & 0x2000) != 0 )
    {
      v12 = (UFG::CompositeDrawableComponent *)pObject->m_Components.p[9].m_pComponent;
    }
    else if ( (v11 & 0x1000) != 0 )
    {
      v13 = pObject->mComponentTableEntryCount;
      v14 = pObject->m_Components.size;
      if ( v13 >= v14 )
      {
LABEL_42:
        v12 = 0i64;
      }
      else
      {
        v15 = pObject->m_Components.p;
        while ( (v15[v13].m_TypeUID & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
             || (UFG::CompositeDrawableComponent::_TypeUID & ~v15[v13].m_TypeUID & 0x1FFFFFF) != 0 )
        {
          if ( ++v13 >= v14 )
            goto LABEL_42;
        }
        v12 = (UFG::CompositeDrawableComponent *)v15[v13].m_pComponent;
      }
    }
    else
    {
      v12 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                 pObject,
                                                 UFG::CompositeDrawableComponent::_TypeUID);
    }
  }
  else
  {
    v12 = (UFG::CompositeDrawableComponent *)pObject->m_Components.p[14].m_pComponent;
  }
  if ( v12 )
    UFG::CompositeDrawableComponent::ResetModelType(v12);
  v16 = pObject->m_Flags;
  if ( (v16 & 0x4000) != 0 )
  {
    v17 = (UFG::RagdollComponent *)pObject->m_Components.p[42].m_pComponent;
    goto LABEL_72;
  }
  if ( v16 < 0 )
  {
    v18 = pObject->mComponentTableEntryCount;
    v19 = pObject->m_Components.size;
    if ( v18 < v19 )
    {
      v20 = pObject->m_Components.p;
      while ( 1 )
      {
        v21 = v18;
        if ( (v20[v18].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && (UFG::RagdollComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          break;
        }
        if ( ++v18 >= v19 )
          goto LABEL_56;
      }
LABEL_55:
      v17 = (UFG::RagdollComponent *)v20[v21].m_pComponent;
      goto LABEL_72;
    }
    goto LABEL_56;
  }
  if ( (v16 & 0x2000) != 0 )
  {
    v22 = pObject->mComponentTableEntryCount;
    v23 = pObject->m_Components.size;
    if ( v22 < v23 )
    {
      v20 = pObject->m_Components.p;
      while ( 1 )
      {
        v21 = v22;
        if ( (v20[v22].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && (UFG::RagdollComponent::_TypeUID & ~v20[v22].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_55;
        }
        if ( ++v22 >= v23 )
          goto LABEL_56;
      }
    }
    goto LABEL_56;
  }
  if ( (v16 & 0x1000) != 0 )
  {
    v24 = pObject->mComponentTableEntryCount;
    v25 = pObject->m_Components.size;
    if ( v24 < v25 )
    {
      v20 = pObject->m_Components.p;
      do
      {
        v21 = v24;
        if ( (v20[v24].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && (UFG::RagdollComponent::_TypeUID & ~v20[v24].m_TypeUID & 0x1FFFFFF) == 0 )
        {
          goto LABEL_55;
        }
      }
      while ( ++v24 < v25 );
    }
LABEL_56:
    v17 = 0i64;
    goto LABEL_72;
  }
  v17 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(pObject, UFG::RagdollComponent::_TypeUID);
LABEL_72:
  if ( v17 )
  {
    UFG::RagdollComponent::Release(v17, 1);
    UFG::RagdollComponent::Acquire(pObject);
  }
  v26 = pObject->m_Flags;
  if ( (v26 & 0x4000) != 0 )
  {
    v27 = pObject->m_Components.p[9].m_pComponent;
  }
  else if ( v26 >= 0 )
  {
    if ( (v26 & 0x2000) != 0 )
    {
      v27 = pObject->m_Components.p[8].m_pComponent;
    }
    else if ( (v26 & 0x1000) != 0 )
    {
      v28 = pObject->mComponentTableEntryCount;
      v29 = pObject->m_Components.size;
      if ( v28 >= v29 )
      {
LABEL_88:
        v27 = 0i64;
      }
      else
      {
        v30 = pObject->m_Components.p;
        while ( (v30[v28].m_TypeUID & 0xFE000000) != (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
             || (UFG::BaseAnimationComponent::_TypeUID & ~v30[v28].m_TypeUID & 0x1FFFFFF) != 0 )
        {
          if ( ++v28 >= v29 )
            goto LABEL_88;
        }
        v27 = v30[v28].m_pComponent;
      }
    }
    else
    {
      v27 = UFG::SimObject::GetComponentOfType(pObject, UFG::BaseAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v27 = pObject->m_Components.p[9].m_pComponent;
  }
  if ( v27 )
    ((void (__fastcall *)(UFG::SimComponent *))v27->vfptr[17].__vecDelDtor)(v27);
  v31 = pObject->m_Flags;
  if ( (v31 & 0x4000) == 0 )
  {
    if ( v31 < 0 )
    {
      v32 = pObject->m_Components.p[9].m_pComponent;
      if ( v32 && ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) == 0 )
      {
        if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
          v32 = 0i64;
        goto LABEL_114;
      }
      goto LABEL_96;
    }
    if ( (v31 & 0x2000) != 0 )
    {
      v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(pObject);
    }
    else
    {
      if ( (v31 & 0x1000) != 0 )
      {
        v34 = pObject->mComponentTableEntryCount;
        v35 = pObject->m_Components.size;
        if ( v34 < v35 )
        {
          v36 = pObject->m_Components.p;
          while ( (v36[v34].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterAnimationComponent::_TypeUID & ~v36[v34].m_TypeUID & 0x1FFFFFF) != 0 )
          {
            if ( ++v34 >= v35 )
              goto LABEL_96;
          }
          v32 = v36[v34].m_pComponent;
          goto LABEL_114;
        }
        goto LABEL_96;
      }
      v33 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  pObject,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v32 = v33;
    goto LABEL_114;
  }
  v32 = pObject->m_Components.p[9].m_pComponent;
  if ( !v32
    || ((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) != 0
    || (UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF) != 0 )
  {
LABEL_96:
    v32 = 0i64;
  }
LABEL_114:
  if ( v32 )
  {
    v37 = *(CharacterDamageRig **)&v32[3].m_Flags;
    if ( v37 )
      CharacterDamageRig::Clone(v37, &source);
  }
LABEL_117:
  if ( pObject == (UFG::SimObjectProp *)LocalPlayer )
    UFG::CustomizeBindings::OnResetLocalPlayer((UFG::SimObjectCVBase *)pObject);
  CharacterDamageRig::~CharacterDamageRig(&source);
}

// File Line: 521
// RVA: 0x547560
char __fastcall UFG::SimObjectUtility::ReinitializeSimObject(
        UFG::SimObjectCharacter *pSimObjectToReset,
        bool bDeleteItems,
        bool bSoft)
{
  const char *v6; // rbx
  char *v7; // rax
  signed __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v12; // rdx
  signed __int16 v13; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  UFG::SimComponentHolder *v17; // rdx
  signed __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  unsigned int v20; // r8d
  unsigned int v21; // r9d
  UFG::SimComponentHolder *v22; // rdx
  unsigned int v23; // r8d
  unsigned int v24; // r9d
  unsigned int v25; // r8d
  unsigned int v26; // r9d
  signed __int16 v27; // cx
  UFG::AttackRightsComponent *v28; // rax
  unsigned int v29; // r8d
  unsigned int v30; // r9d
  UFG::SimComponentHolder *v31; // rdx
  unsigned int v32; // r8d
  unsigned int v33; // r9d
  unsigned int v34; // r8d
  unsigned int v35; // r9d
  signed __int16 v36; // cx
  UFG::AIScriptInterfaceComponent *v37; // rax
  unsigned int v38; // r8d
  unsigned int v39; // r9d
  UFG::SimComponentHolder *v40; // rdx
  unsigned int v41; // r8d
  unsigned int v42; // r9d
  signed __int16 v43; // cx
  UFG::HealthComponent *v44; // rax
  unsigned int v45; // r8d
  unsigned int v46; // r9d
  UFG::SimComponentHolder *v47; // rdx
  unsigned int v48; // r8d
  unsigned int v49; // r9d
  signed __int16 v50; // cx
  UFG::SimObjectCharacterPropertiesComponent *v51; // rcx
  unsigned int v52; // r8d
  unsigned int v53; // r9d
  UFG::SimComponentHolder *v54; // rdx
  unsigned int v55; // r8d
  unsigned int v56; // r9d
  signed __int16 v57; // cx
  UFG::InventoryComponent *v58; // rax
  unsigned int v59; // r8d
  unsigned int v60; // r9d
  UFG::SimComponentHolder *v61; // rdx
  unsigned int v62; // r8d
  unsigned int v63; // r9d
  unsigned int v64; // r8d
  unsigned int v65; // r9d
  UFG::SceneObjectProperties *m_pSceneObj; // r8
  UFG::qPropertySet *mpWritableProperties; // rdx
  signed __int16 v68; // cx
  UFG::FaceActionComponent *v69; // rsi
  unsigned int v70; // edx
  unsigned int v71; // r8d
  UFG::SimComponentHolder *v72; // rsi
  unsigned int v73; // edx
  unsigned int v74; // r8d
  unsigned int v75; // edx
  unsigned int v76; // r8d
  UFG::SceneObjectProperties *v77; // rbx
  signed __int16 v78; // cx
  UFG::PedFormationManagerComponent *v79; // rax
  unsigned int v80; // r8d
  unsigned int v81; // r9d
  UFG::SimComponentHolder *v82; // rdx
  unsigned int v83; // r8d
  unsigned int v84; // r9d
  unsigned int v85; // r8d
  unsigned int v86; // r9d
  signed __int16 v87; // cx
  UFG::GetInFormationComponent *v88; // rax
  unsigned int v89; // r8d
  unsigned int v90; // r9d
  UFG::SimComponentHolder *v91; // rdx
  unsigned int v92; // r8d
  unsigned int v93; // r9d
  unsigned int v94; // r8d
  unsigned int v95; // r9d
  signed __int16 v96; // cx
  UFG::ActiveAIEntityComponent *v97; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  signed __int16 v99; // cx
  UFG::InterestPointUserComponent *v100; // rax
  signed __int16 v101; // cx
  UFG::InteractableComponent *v102; // rbx
  UFG::SimComponent *v103; // rax
  UFG::qPropertySet *DataPtr; // rax
  signed __int16 v105; // cx
  UFG::SimComponent *v106; // rax
  bool v107; // zf
  signed __int16 v108; // cx
  UFG::AiDriverComponent *v109; // rcx
  UFG::SimComponent *v110; // rax
  signed __int16 v111; // cx
  UFG::HitReactionComponent *v112; // rax
  signed __int16 v113; // cx
  UFG::SimComponent *v114; // rcx
  UFG::SimComponent *v115; // rax
  signed __int16 v116; // cx
  UFG::ActionTreeComponent *v117; // rax
  signed __int16 v118; // cx
  UFG::SimComponent *v119; // rax
  signed __int16 v120; // cx
  signed __int16 v121; // cx
  UFG::SimComponent *v122; // rcx
  UFG::SimComponent *v123; // rax
  signed __int16 v124; // cx
  UFG::FaceMeterComponent *v125; // rax
  signed __int16 v126; // cx
  UFG::TSActorComponent *v127; // rbx
  UFG::TSActor *i_obj_p; // rax
  UFG::TSActor *Actor; // rax
  UFG::TSActor *v130; // rax
  signed __int16 v131; // cx
  UFG::CharacterEffectsComponent *v132; // rbx
  UFG::SimComponent *v133; // rax
  UFG::PedSpawnManager *Instance; // rax

  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    if ( bDeleteItems )
      v6 = "True";
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    UFG::qPrintf("ReinitializeSimObject: %s(0x%x) Delete Items %s\n", v7, pSimObjectToReset, v6);
  }
  if ( pSimObjectToReset )
  {
    m_Flags = pSimObjectToReset->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pSimObjectToReset->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)pSimObjectToReset->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        mComponentTableEntryCount = pSimObjectToReset->mComponentTableEntryCount;
        size = pSimObjectToReset->m_Components.size;
        if ( mComponentTableEntryCount >= size )
        {
LABEL_18:
          m_pComponent = 0i64;
        }
        else
        {
          v12 = &pSimObjectToReset->m_Components.p[mComponentTableEntryCount];
          while ( (v12->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || (UFG::StreamedResourceComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++mComponentTableEntryCount;
            ++v12;
            if ( mComponentTableEntryCount >= size )
              goto LABEL_18;
          }
          m_pComponent = (UFG::StreamedResourceComponent *)v12->m_pComponent;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                           pSimObjectToReset,
                                                           UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)pSimObjectToReset->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
      UFG::StreamedResourceComponent::ResetPropertyPtr(m_pComponent);
    v13 = pSimObjectToReset->m_Flags;
    if ( (v13 & 0x4000) != 0 )
    {
      ComponentOfType = pSimObjectToReset->m_Components.p[18].m_pComponent;
    }
    else if ( v13 >= 0 )
    {
      if ( (v13 & 0x2000) != 0 )
      {
        ComponentOfType = pSimObjectToReset->m_Components.p[5].m_pComponent;
      }
      else if ( (v13 & 0x1000) != 0 )
      {
        v15 = pSimObjectToReset->mComponentTableEntryCount;
        v16 = pSimObjectToReset->m_Components.size;
        if ( v15 >= v16 )
        {
LABEL_35:
          ComponentOfType = 0i64;
        }
        else
        {
          v17 = &pSimObjectToReset->m_Components.p[v15];
          while ( (v17->m_TypeUID & 0xFE000000) != (UFG::PhantomVolumeComponent::_TypeUID & 0xFE000000)
               || (UFG::PhantomVolumeComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v15;
            ++v17;
            if ( v15 >= v16 )
              goto LABEL_35;
          }
          ComponentOfType = v17->m_pComponent;
        }
      }
      else
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::PhantomVolumeComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = pSimObjectToReset->m_Components.p[18].m_pComponent;
    }
    if ( ComponentOfType )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, ComponentOfType);
    v18 = pSimObjectToReset->m_Flags;
    if ( (v18 & 0x4000) != 0 )
    {
      v19 = pSimObjectToReset->m_Components.p[36].m_pComponent;
      goto LABEL_65;
    }
    if ( v18 >= 0 )
    {
      if ( (v18 & 0x2000) != 0 )
      {
        v23 = pSimObjectToReset->mComponentTableEntryCount;
        v24 = pSimObjectToReset->m_Components.size;
        if ( v23 < v24 )
        {
          v22 = &pSimObjectToReset->m_Components.p[v23];
          while ( (v22->m_TypeUID & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
               || (UFG::NavComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v23;
            ++v22;
            if ( v23 >= v24 )
            {
              v19 = 0i64;
              goto LABEL_65;
            }
          }
          goto LABEL_49;
        }
      }
      else
      {
        if ( (v18 & 0x1000) == 0 )
        {
          v19 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::NavComponent::_TypeUID);
LABEL_65:
          if ( v19 )
            v19->vfptr[15].__vecDelDtor(v19, bSoft);
          v27 = pSimObjectToReset->m_Flags;
          if ( (v27 & 0x4000) != 0 )
          {
            v28 = (UFG::AttackRightsComponent *)pSimObjectToReset->m_Components.p[46].m_pComponent;
            goto LABEL_92;
          }
          if ( v27 >= 0 )
          {
            if ( (v27 & 0x2000) != 0 )
            {
              v32 = pSimObjectToReset->mComponentTableEntryCount;
              v33 = pSimObjectToReset->m_Components.size;
              if ( v32 < v33 )
              {
                v31 = &pSimObjectToReset->m_Components.p[v32];
                while ( (v31->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                     || (UFG::AttackRightsComponent::_TypeUID & ~v31->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v32;
                  ++v31;
                  if ( v32 >= v33 )
                  {
                    v28 = 0i64;
                    goto LABEL_92;
                  }
                }
                goto LABEL_76;
              }
            }
            else
            {
              if ( (v27 & 0x1000) == 0 )
              {
                v28 = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                      pSimObjectToReset,
                                                      UFG::AttackRightsComponent::_TypeUID);
LABEL_92:
                if ( v28 )
                  UFG::AttackRightsComponent::Reset(v28);
                goto LABEL_94;
              }
              v34 = pSimObjectToReset->mComponentTableEntryCount;
              v35 = pSimObjectToReset->m_Components.size;
              if ( v34 < v35 )
              {
                v31 = &pSimObjectToReset->m_Components.p[v34];
                while ( (v31->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                     || (UFG::AttackRightsComponent::_TypeUID & ~v31->m_TypeUID & 0x1FFFFFF) != 0 )
                {
                  ++v34;
                  ++v31;
                  if ( v34 >= v35 )
                  {
                    v28 = 0i64;
                    goto LABEL_92;
                  }
                }
                goto LABEL_76;
              }
            }
          }
          else
          {
            v29 = pSimObjectToReset->mComponentTableEntryCount;
            v30 = pSimObjectToReset->m_Components.size;
            if ( v29 < v30 )
            {
              v31 = &pSimObjectToReset->m_Components.p[v29];
              while ( (v31->m_TypeUID & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                   || (UFG::AttackRightsComponent::_TypeUID & ~v31->m_TypeUID & 0x1FFFFFF) != 0 )
              {
                ++v29;
                ++v31;
                if ( v29 >= v30 )
                  goto LABEL_75;
              }
LABEL_76:
              v28 = (UFG::AttackRightsComponent *)v31->m_pComponent;
              goto LABEL_92;
            }
          }
LABEL_75:
          v28 = 0i64;
          goto LABEL_92;
        }
        v25 = pSimObjectToReset->mComponentTableEntryCount;
        v26 = pSimObjectToReset->m_Components.size;
        if ( v25 < v26 )
        {
          v22 = &pSimObjectToReset->m_Components.p[v25];
          while ( (v22->m_TypeUID & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
               || (UFG::NavComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v25;
            ++v22;
            if ( v25 >= v26 )
            {
              v19 = 0i64;
              goto LABEL_65;
            }
          }
          goto LABEL_49;
        }
      }
    }
    else
    {
      v20 = pSimObjectToReset->mComponentTableEntryCount;
      v21 = pSimObjectToReset->m_Components.size;
      if ( v20 < v21 )
      {
        v22 = &pSimObjectToReset->m_Components.p[v20];
        while ( (v22->m_TypeUID & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
             || (UFG::NavComponent::_TypeUID & ~v22->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v20;
          ++v22;
          if ( v20 >= v21 )
            goto LABEL_48;
        }
LABEL_49:
        v19 = v22->m_pComponent;
        goto LABEL_65;
      }
    }
LABEL_48:
    v19 = 0i64;
    goto LABEL_65;
  }
LABEL_94:
  if ( bSoft )
    goto LABEL_140;
  if ( !pSimObjectToReset )
    goto LABEL_316;
  v36 = pSimObjectToReset->m_Flags;
  if ( (v36 & 0x4000) != 0 )
  {
    v37 = (UFG::AIScriptInterfaceComponent *)pSimObjectToReset->m_Components.p[5].m_pComponent;
    goto LABEL_116;
  }
  if ( v36 < 0 )
  {
    v37 = (UFG::AIScriptInterfaceComponent *)pSimObjectToReset->m_Components.p[5].m_pComponent;
    goto LABEL_116;
  }
  if ( (v36 & 0x2000) != 0 )
  {
    v38 = pSimObjectToReset->mComponentTableEntryCount;
    v39 = pSimObjectToReset->m_Components.size;
    if ( v38 < v39 )
    {
      v40 = &pSimObjectToReset->m_Components.p[v38];
      while ( (v40->m_TypeUID & 0xFE000000) != (UFG::AIScriptInterfaceComponent::_TypeUID & 0xFE000000)
           || (UFG::AIScriptInterfaceComponent::_TypeUID & ~v40->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v38;
        ++v40;
        if ( v38 >= v39 )
          goto LABEL_106;
      }
LABEL_107:
      v37 = (UFG::AIScriptInterfaceComponent *)v40->m_pComponent;
      goto LABEL_116;
    }
    goto LABEL_106;
  }
  if ( (v36 & 0x1000) != 0 )
  {
    v41 = pSimObjectToReset->mComponentTableEntryCount;
    v42 = pSimObjectToReset->m_Components.size;
    if ( v41 < v42 )
    {
      v40 = &pSimObjectToReset->m_Components.p[v41];
      while ( (v40->m_TypeUID & 0xFE000000) != (UFG::AIScriptInterfaceComponent::_TypeUID & 0xFE000000)
           || (UFG::AIScriptInterfaceComponent::_TypeUID & ~v40->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v41;
        ++v40;
        if ( v41 >= v42 )
        {
          v37 = 0i64;
          goto LABEL_116;
        }
      }
      goto LABEL_107;
    }
LABEL_106:
    v37 = 0i64;
    goto LABEL_116;
  }
  v37 = (UFG::AIScriptInterfaceComponent *)UFG::SimObject::GetComponentOfType(
                                             pSimObjectToReset,
                                             UFG::AIScriptInterfaceComponent::_TypeUID);
LABEL_116:
  if ( v37 )
    UFG::AIScriptInterfaceComponent::Reset(v37);
  v43 = pSimObjectToReset->m_Flags;
  if ( (v43 & 0x4000) != 0 )
  {
    v44 = (UFG::HealthComponent *)pSimObjectToReset->m_Components.p[6].m_pComponent;
    goto LABEL_138;
  }
  if ( v43 < 0 )
  {
    v44 = (UFG::HealthComponent *)pSimObjectToReset->m_Components.p[6].m_pComponent;
    goto LABEL_138;
  }
  if ( (v43 & 0x2000) != 0 )
  {
    v45 = pSimObjectToReset->mComponentTableEntryCount;
    v46 = pSimObjectToReset->m_Components.size;
    if ( v45 < v46 )
    {
      v47 = &pSimObjectToReset->m_Components.p[v45];
      while ( (v47->m_TypeUID & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~v47->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v45;
        ++v47;
        if ( v45 >= v46 )
          goto LABEL_128;
      }
LABEL_129:
      v44 = (UFG::HealthComponent *)v47->m_pComponent;
      goto LABEL_138;
    }
    goto LABEL_128;
  }
  if ( (v43 & 0x1000) != 0 )
  {
    v48 = pSimObjectToReset->mComponentTableEntryCount;
    v49 = pSimObjectToReset->m_Components.size;
    if ( v48 < v49 )
    {
      v47 = &pSimObjectToReset->m_Components.p[v48];
      while ( (v47->m_TypeUID & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || (UFG::HealthComponent::_TypeUID & ~v47->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v48;
        ++v47;
        if ( v48 >= v49 )
        {
          v44 = 0i64;
          goto LABEL_138;
        }
      }
      goto LABEL_129;
    }
LABEL_128:
    v44 = 0i64;
    goto LABEL_138;
  }
  v44 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::HealthComponent::_TypeUID);
LABEL_138:
  if ( v44 )
    UFG::HealthComponent::Reset(v44);
LABEL_140:
  if ( !pSimObjectToReset )
    goto LABEL_316;
  v50 = pSimObjectToReset->m_Flags;
  if ( (v50 & 0x4000) == 0 )
  {
    if ( v50 < 0 )
    {
      v51 = (UFG::SimObjectCharacterPropertiesComponent *)pSimObjectToReset->m_Components.p[3].m_pComponent;
      if ( !v51 || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v51->m_TypeUID) & 0xFE000000) != 0 )
        goto LABEL_145;
      if ( (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v51->m_TypeUID & 0x1FFFFFF) != 0 )
        v51 = 0i64;
      goto LABEL_167;
    }
    if ( (v50 & 0x2000) != 0 )
    {
      v52 = pSimObjectToReset->mComponentTableEntryCount;
      v53 = pSimObjectToReset->m_Components.size;
      if ( v52 < v53 )
      {
        v54 = &pSimObjectToReset->m_Components.p[v52];
        while ( (v54->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v54->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v52;
          ++v54;
          if ( v52 >= v53 )
          {
            v51 = 0i64;
            goto LABEL_167;
          }
        }
LABEL_158:
        v51 = (UFG::SimObjectCharacterPropertiesComponent *)v54->m_pComponent;
        goto LABEL_167;
      }
    }
    else
    {
      if ( (v50 & 0x1000) == 0 )
      {
        v51 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              pSimObjectToReset,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_167;
      }
      v55 = pSimObjectToReset->mComponentTableEntryCount;
      v56 = pSimObjectToReset->m_Components.size;
      if ( v55 < v56 )
      {
        v54 = &pSimObjectToReset->m_Components.p[v55];
        while ( (v54->m_TypeUID & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v54->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v55;
          ++v54;
          if ( v55 >= v56 )
          {
            v51 = 0i64;
            goto LABEL_167;
          }
        }
        goto LABEL_158;
      }
    }
LABEL_145:
    v51 = 0i64;
    goto LABEL_167;
  }
  v51 = (UFG::SimObjectCharacterPropertiesComponent *)pSimObjectToReset->m_Components.p[3].m_pComponent;
  if ( !v51
    || ((UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v51->m_TypeUID) & 0xFE000000) != 0
    || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v51->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    goto LABEL_145;
  }
LABEL_167:
  if ( v51 )
    UFG::SimObjectCharacterPropertiesComponent::Reset(v51, bSoft);
  v57 = pSimObjectToReset->m_Flags;
  if ( (v57 & 0x4000) == 0 )
  {
    if ( v57 >= 0 )
    {
      if ( (v57 & 0x2000) != 0 )
      {
        v62 = pSimObjectToReset->mComponentTableEntryCount;
        v63 = pSimObjectToReset->m_Components.size;
        if ( v62 < v63 )
        {
          v61 = &pSimObjectToReset->m_Components.p[v62];
          while ( (v61->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v62;
            ++v61;
            if ( v62 >= v63 )
            {
              v58 = 0i64;
              goto LABEL_194;
            }
          }
          goto LABEL_178;
        }
      }
      else
      {
        if ( (v57 & 0x1000) == 0 )
        {
          v58 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                             pSimObjectToReset,
                                             UFG::InventoryComponent::_TypeUID);
          goto LABEL_194;
        }
        v64 = pSimObjectToReset->mComponentTableEntryCount;
        v65 = pSimObjectToReset->m_Components.size;
        if ( v64 < v65 )
        {
          v61 = &pSimObjectToReset->m_Components.p[v64];
          while ( (v61->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || (UFG::InventoryComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v64;
            ++v61;
            if ( v64 >= v65 )
            {
              v58 = 0i64;
              goto LABEL_194;
            }
          }
          goto LABEL_178;
        }
      }
    }
    else
    {
      v59 = pSimObjectToReset->mComponentTableEntryCount;
      v60 = pSimObjectToReset->m_Components.size;
      if ( v59 < v60 )
      {
        v61 = &pSimObjectToReset->m_Components.p[v59];
        while ( (v61->m_TypeUID & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
             || (UFG::InventoryComponent::_TypeUID & ~v61->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v59;
          ++v61;
          if ( v59 >= v60 )
            goto LABEL_177;
        }
LABEL_178:
        v58 = (UFG::InventoryComponent *)v61->m_pComponent;
        goto LABEL_194;
      }
    }
LABEL_177:
    v58 = 0i64;
    goto LABEL_194;
  }
  v58 = (UFG::InventoryComponent *)pSimObjectToReset->m_Components.p[39].m_pComponent;
LABEL_194:
  if ( v58 )
  {
    m_pSceneObj = v58->m_pSimObject->m_pSceneObj;
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( mpWritableProperties || (mpWritableProperties = m_pSceneObj->mpConstProperties) != 0i64 )
      UFG::InventoryComponent::ResetFromProperties(v58, mpWritableProperties);
  }
  v68 = pSimObjectToReset->m_Flags;
  if ( (v68 & 0x4000) != 0 )
  {
    v69 = (UFG::FaceActionComponent *)pSimObjectToReset->m_Components.p[45].m_pComponent;
    goto LABEL_223;
  }
  if ( v68 < 0 )
  {
    v70 = pSimObjectToReset->mComponentTableEntryCount;
    v71 = pSimObjectToReset->m_Components.size;
    if ( v70 < v71 )
    {
      v72 = &pSimObjectToReset->m_Components.p[v70];
      while ( (v72->m_TypeUID & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || (UFG::FaceActionComponent::_TypeUID & ~v72->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v70;
        ++v72;
        if ( v70 >= v71 )
          goto LABEL_206;
      }
LABEL_207:
      v69 = (UFG::FaceActionComponent *)v72->m_pComponent;
      goto LABEL_223;
    }
    goto LABEL_206;
  }
  if ( (v68 & 0x2000) != 0 )
  {
    v73 = pSimObjectToReset->mComponentTableEntryCount;
    v74 = pSimObjectToReset->m_Components.size;
    if ( v73 < v74 )
    {
      v72 = &pSimObjectToReset->m_Components.p[v73];
      while ( (v72->m_TypeUID & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || (UFG::FaceActionComponent::_TypeUID & ~v72->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v73;
        ++v72;
        if ( v73 >= v74 )
        {
          v69 = 0i64;
          goto LABEL_223;
        }
      }
      goto LABEL_207;
    }
LABEL_206:
    v69 = 0i64;
    goto LABEL_223;
  }
  if ( (v68 & 0x1000) != 0 )
  {
    v75 = pSimObjectToReset->mComponentTableEntryCount;
    v76 = pSimObjectToReset->m_Components.size;
    if ( v75 < v76 )
    {
      v72 = &pSimObjectToReset->m_Components.p[v75];
      while ( (v72->m_TypeUID & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || (UFG::FaceActionComponent::_TypeUID & ~v72->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v75;
        ++v72;
        if ( v75 >= v76 )
        {
          v69 = 0i64;
          goto LABEL_223;
        }
      }
      goto LABEL_207;
    }
    goto LABEL_206;
  }
  v69 = (UFG::FaceActionComponent *)UFG::SimObject::GetComponentOfType(
                                      pSimObjectToReset,
                                      UFG::FaceActionComponent::_TypeUID);
LABEL_223:
  if ( v69 )
  {
    v77 = v69->m_pSimObject->m_pSceneObj;
    UFG::FaceActionComponent::ResetState(v69);
    v69->vfptr[12].__vecDelDtor(v69, (unsigned int)v77);
  }
  v78 = pSimObjectToReset->m_Flags;
  if ( (v78 & 0x4000) != 0 )
  {
    v79 = (UFG::PedFormationManagerComponent *)pSimObjectToReset->m_Components.p[33].m_pComponent;
    goto LABEL_250;
  }
  if ( v78 < 0 )
  {
    v80 = pSimObjectToReset->mComponentTableEntryCount;
    v81 = pSimObjectToReset->m_Components.size;
    if ( v80 < v81 )
    {
      v82 = &pSimObjectToReset->m_Components.p[v80];
      while ( (v82->m_TypeUID & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || (UFG::PedFormationManagerComponent::_TypeUID & ~v82->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v80;
        ++v82;
        if ( v80 >= v81 )
          goto LABEL_233;
      }
LABEL_234:
      v79 = (UFG::PedFormationManagerComponent *)v82->m_pComponent;
      goto LABEL_250;
    }
    goto LABEL_233;
  }
  if ( (v78 & 0x2000) != 0 )
  {
    v83 = pSimObjectToReset->mComponentTableEntryCount;
    v84 = pSimObjectToReset->m_Components.size;
    if ( v83 < v84 )
    {
      v82 = &pSimObjectToReset->m_Components.p[v83];
      while ( (v82->m_TypeUID & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || (UFG::PedFormationManagerComponent::_TypeUID & ~v82->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v83;
        ++v82;
        if ( v83 >= v84 )
        {
          v79 = 0i64;
          goto LABEL_250;
        }
      }
      goto LABEL_234;
    }
LABEL_233:
    v79 = 0i64;
    goto LABEL_250;
  }
  if ( (v78 & 0x1000) != 0 )
  {
    v85 = pSimObjectToReset->mComponentTableEntryCount;
    v86 = pSimObjectToReset->m_Components.size;
    if ( v85 < v86 )
    {
      v82 = &pSimObjectToReset->m_Components.p[v85];
      while ( (v82->m_TypeUID & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || (UFG::PedFormationManagerComponent::_TypeUID & ~v82->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v85;
        ++v82;
        if ( v85 >= v86 )
        {
          v79 = 0i64;
          goto LABEL_250;
        }
      }
      goto LABEL_234;
    }
    goto LABEL_233;
  }
  v79 = (UFG::PedFormationManagerComponent *)UFG::SimObject::GetComponentOfType(
                                               pSimObjectToReset,
                                               UFG::PedFormationManagerComponent::_TypeUID);
LABEL_250:
  if ( v79 )
    UFG::PedFormationManagerComponent::Reset(v79);
  v87 = pSimObjectToReset->m_Flags;
  if ( (v87 & 0x4000) != 0 )
  {
    v88 = (UFG::GetInFormationComponent *)pSimObjectToReset->m_Components.p[34].m_pComponent;
    goto LABEL_277;
  }
  if ( v87 < 0 )
  {
    v89 = pSimObjectToReset->mComponentTableEntryCount;
    v90 = pSimObjectToReset->m_Components.size;
    if ( v89 < v90 )
    {
      v91 = &pSimObjectToReset->m_Components.p[v89];
      while ( (v91->m_TypeUID & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || (UFG::GetInPedFormationComponent::_TypeUID & ~v91->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v89;
        ++v91;
        if ( v89 >= v90 )
          goto LABEL_260;
      }
LABEL_261:
      v88 = (UFG::GetInFormationComponent *)v91->m_pComponent;
      goto LABEL_277;
    }
    goto LABEL_260;
  }
  if ( (v87 & 0x2000) != 0 )
  {
    v92 = pSimObjectToReset->mComponentTableEntryCount;
    v93 = pSimObjectToReset->m_Components.size;
    if ( v92 < v93 )
    {
      v91 = &pSimObjectToReset->m_Components.p[v92];
      while ( (v91->m_TypeUID & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || (UFG::GetInPedFormationComponent::_TypeUID & ~v91->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v92;
        ++v91;
        if ( v92 >= v93 )
        {
          v88 = 0i64;
          goto LABEL_277;
        }
      }
      goto LABEL_261;
    }
LABEL_260:
    v88 = 0i64;
    goto LABEL_277;
  }
  if ( (v87 & 0x1000) != 0 )
  {
    v94 = pSimObjectToReset->mComponentTableEntryCount;
    v95 = pSimObjectToReset->m_Components.size;
    if ( v94 < v95 )
    {
      v91 = &pSimObjectToReset->m_Components.p[v94];
      while ( (v91->m_TypeUID & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || (UFG::GetInPedFormationComponent::_TypeUID & ~v91->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v94;
        ++v91;
        if ( v94 >= v95 )
        {
          v88 = 0i64;
          goto LABEL_277;
        }
      }
      goto LABEL_261;
    }
    goto LABEL_260;
  }
  v88 = (UFG::GetInFormationComponent *)UFG::SimObject::GetComponentOfType(
                                          pSimObjectToReset,
                                          UFG::GetInPedFormationComponent::_TypeUID);
LABEL_277:
  if ( v88 )
    UFG::GetInPedFormationComponent::DeleteList(v88);
  v96 = pSimObjectToReset->m_Flags;
  if ( (v96 & 0x4000) != 0 )
  {
    v97 = (UFG::ActiveAIEntityComponent *)pSimObjectToReset->m_Components.p[22].m_pComponent;
    if ( !v97
      || ((UFG::ActiveAIEntityComponent::_TypeUID ^ v97->m_TypeUID) & 0xFE000000) != 0
      || (UFG::ActiveAIEntityComponent::_TypeUID & ~v97->m_TypeUID & 0x1FFFFFF) != 0 )
    {
LABEL_283:
      v97 = 0i64;
    }
  }
  else if ( v96 >= 0 )
  {
    if ( (v96 & 0x2000) != 0 || (v96 & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            pSimObjectToReset,
                            UFG::ActiveAIEntityComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::ActiveAIEntityComponent::_TypeUID);
    v97 = (UFG::ActiveAIEntityComponent *)ComponentOfTypeHK;
  }
  else
  {
    v97 = (UFG::ActiveAIEntityComponent *)pSimObjectToReset->m_Components.p[22].m_pComponent;
    if ( !v97 || ((UFG::ActiveAIEntityComponent::_TypeUID ^ v97->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_283;
    if ( (UFG::ActiveAIEntityComponent::_TypeUID & ~v97->m_TypeUID & 0x1FFFFFF) != 0 )
      v97 = 0i64;
  }
  if ( v97 )
  {
    UFG::ActiveAIEntityComponent::ResetAndLoadProperties(v97);
    UFG::AIEntityComponent::OnSiblingsChanged(v97);
  }
  v99 = pSimObjectToReset->m_Flags;
  if ( (v99 & 0x4000) != 0 )
  {
    v100 = (UFG::InterestPointUserComponent *)pSimObjectToReset->m_Components.p[43].m_pComponent;
    goto LABEL_303;
  }
  if ( v99 >= 0 )
  {
    if ( (v99 & 0x2000) != 0 )
    {
      v100 = (UFG::InterestPointUserComponent *)pSimObjectToReset->m_Components.p[12].m_pComponent;
      goto LABEL_303;
    }
    if ( (v99 & 0x1000) == 0 )
    {
      v100 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                  pSimObjectToReset,
                                                  UFG::InterestPointUserComponent::_TypeUID);
LABEL_303:
      if ( v100 )
        UFG::InterestPointUserComponent::Reset(v100);
    }
  }
  v101 = pSimObjectToReset->m_Flags;
  if ( (v101 & 0x4000) != 0 )
  {
    v102 = (UFG::InteractableComponent *)pSimObjectToReset->m_Components.p[12].m_pComponent;
  }
  else if ( v101 >= 0 )
  {
    if ( (v101 & 0x2000) != 0 || (v101 & 0x1000) != 0 )
      v103 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::InteractableComponent::_TypeUID);
    else
      v103 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::InteractableComponent::_TypeUID);
    v102 = (UFG::InteractableComponent *)v103;
  }
  else
  {
    v102 = (UFG::InteractableComponent *)pSimObjectToReset->m_Components.p[12].m_pComponent;
  }
  if ( v102 )
  {
    UFG::InteractableComponent::DestroyInteractionPoints(v102);
    DataPtr = UFG::InteractableComponent::GetDataPtr(v102->m_pSimObject->m_pSceneObj);
    UFG::InteractableComponent::InitFromData(v102, (component_Interactable *)DataPtr);
  }
LABEL_316:
  UFG::SimObjectUtility::ResetState(pSimObjectToReset, 0, bDeleteItems);
  if ( !pSimObjectToReset )
    goto LABEL_355;
  v105 = pSimObjectToReset->m_Flags;
  if ( (v105 & 0x4000) != 0 )
  {
    v106 = pSimObjectToReset->m_Components.p[8].m_pComponent;
  }
  else if ( v105 >= 0 )
  {
    if ( (v105 & 0x2000) != 0 || (v105 & 0x1000) != 0 )
      v106 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::MissionFailConditionComponent::_TypeUID);
    else
      v106 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::MissionFailConditionComponent::_TypeUID);
  }
  else
  {
    v106 = pSimObjectToReset->m_Components.p[8].m_pComponent;
  }
  if ( v106 )
  {
    v107 = HIBYTE(v106[1].m_BoundComponentHandles.mNode.mPrev) == 0;
    LOBYTE(v106[1].m_Flags) = 0;
    *(_QWORD *)(&v106[1].m_SimObjIndex + 1) = 0i64;
    if ( !v107 )
      UFG::MissionFailConditionComponent::EnableDistanceFailTrigger((UFG::MissionFailConditionComponent *)v106, 1);
  }
  v108 = pSimObjectToReset->m_Flags;
  if ( (v108 & 0x4000) != 0 )
  {
    v109 = (UFG::AiDriverComponent *)pSimObjectToReset->m_Components.p[23].m_pComponent;
    if ( v109
      && ((UFG::AiDriverComponent::_TypeUID ^ v109->m_TypeUID) & 0xFE000000) == 0
      && (UFG::AiDriverComponent::_TypeUID & ~v109->m_TypeUID & 0x1FFFFFF) == 0 )
    {
      goto LABEL_343;
    }
  }
  else
  {
    if ( v108 >= 0 )
    {
      if ( (v108 & 0x2000) != 0 || (v108 & 0x1000) != 0 )
        v110 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::AiDriverComponent::_TypeUID);
      else
        v110 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::AiDriverComponent::_TypeUID);
      v109 = (UFG::AiDriverComponent *)v110;
      goto LABEL_343;
    }
    v109 = (UFG::AiDriverComponent *)pSimObjectToReset->m_Components.p[23].m_pComponent;
    if ( v109 && ((UFG::AiDriverComponent::_TypeUID ^ v109->m_TypeUID) & 0xFE000000) == 0 )
    {
      if ( (UFG::AiDriverComponent::_TypeUID & ~v109->m_TypeUID & 0x1FFFFFF) != 0 )
        v109 = 0i64;
      goto LABEL_343;
    }
  }
  v109 = 0i64;
LABEL_343:
  if ( v109 )
    UFG::AiDriverComponent::SetDrivingMode(v109, 0);
  v111 = pSimObjectToReset->m_Flags;
  if ( (v111 & 0x4000) != 0 )
  {
    v112 = (UFG::HitReactionComponent *)pSimObjectToReset->m_Components.p[15].m_pComponent;
  }
  else if ( v111 >= 0 )
  {
    if ( (v111 & 0x2000) != 0 || (v111 & 0x1000) != 0 )
      v112 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            pSimObjectToReset,
                                            UFG::HitReactionComponent::_TypeUID);
    else
      v112 = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                            pSimObjectToReset,
                                            UFG::HitReactionComponent::_TypeUID);
  }
  else
  {
    v112 = (UFG::HitReactionComponent *)pSimObjectToReset->m_Components.p[15].m_pComponent;
  }
  if ( v112 )
    UFG::HitReactionComponent::Reset(v112);
LABEL_355:
  if ( !bSoft )
  {
    if ( !pSimObjectToReset )
      goto LABEL_444;
    v113 = pSimObjectToReset->m_Flags;
    if ( (v113 & 0x4000) != 0 )
    {
      v114 = pSimObjectToReset->m_Components.p[20].m_pComponent;
    }
    else if ( v113 >= 0 )
    {
      if ( (v113 & 0x2000) != 0 || (v113 & 0x1000) != 0 )
        v115 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v115 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::TargetingSystemBaseComponent::_TypeUID);
      v114 = v115;
    }
    else
    {
      v114 = pSimObjectToReset->m_Components.p[20].m_pComponent;
    }
    if ( v114 )
      ((void (__fastcall *)(UFG::SimComponent *))v114->vfptr[20].__vecDelDtor)(v114);
  }
  if ( pSimObjectToReset )
  {
    v116 = pSimObjectToReset->m_Flags;
    if ( (v116 & 0x4000) != 0 )
    {
      v117 = (UFG::ActionTreeComponent *)pSimObjectToReset->m_Components.p[7].m_pComponent;
    }
    else if ( v116 >= 0 )
    {
      if ( (v116 & 0x2000) != 0 )
      {
        v117 = (UFG::ActionTreeComponent *)pSimObjectToReset->m_Components.p[6].m_pComponent;
      }
      else if ( (v116 & 0x1000) != 0 )
      {
        v117 = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             pSimObjectToReset,
                                             UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v117 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                             pSimObjectToReset,
                                             UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v117 = (UFG::ActionTreeComponent *)pSimObjectToReset->m_Components.p[7].m_pComponent;
    }
    if ( v117 )
      UFG::ActionTreeComponent::Reset(v117);
    v118 = pSimObjectToReset->m_Flags;
    if ( (v118 & 0x4000) != 0 || v118 < 0 || (v118 & 0x2000) != 0 || (v118 & 0x1000) != 0 )
      v119 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::StimulusEmitterComponent::_TypeUID);
    else
      v119 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::StimulusEmitterComponent::_TypeUID);
    while ( v119 )
    {
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v119);
      v120 = pSimObjectToReset->m_Flags;
      if ( (v120 & 0x4000) != 0 || v120 < 0 || (v120 & 0x2000) != 0 || (v120 & 0x1000) != 0 )
        v119 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::StimulusEmitterComponent::_TypeUID);
      else
        v119 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::StimulusEmitterComponent::_TypeUID);
    }
    v121 = pSimObjectToReset->m_Flags;
    if ( (v121 & 0x4000) != 0 )
    {
      v122 = pSimObjectToReset->m_Components.p[9].m_pComponent;
    }
    else if ( v121 >= 0 )
    {
      if ( (v121 & 0x2000) != 0 )
      {
        v122 = pSimObjectToReset->m_Components.p[8].m_pComponent;
      }
      else
      {
        if ( (v121 & 0x1000) != 0 )
          v123 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::BaseAnimationComponent::_TypeUID);
        else
          v123 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::BaseAnimationComponent::_TypeUID);
        v122 = v123;
      }
    }
    else
    {
      v122 = pSimObjectToReset->m_Components.p[9].m_pComponent;
    }
    if ( v122 )
      ((void (__fastcall *)(UFG::SimComponent *))v122->vfptr[17].__vecDelDtor)(v122);
    v124 = pSimObjectToReset->m_Flags;
    if ( (v124 & 0x4000) != 0 || v124 < 0 || (v124 & 0x2000) != 0 || (v124 & 0x1000) != 0 )
      v125 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          pSimObjectToReset,
                                          UFG::FaceMeterComponent::_TypeUID);
    else
      v125 = (UFG::FaceMeterComponent *)UFG::SimObject::GetComponentOfType(
                                          pSimObjectToReset,
                                          UFG::FaceMeterComponent::_TypeUID);
    if ( v125 )
      UFG::FaceMeterComponent::Reset(v125);
    v126 = pSimObjectToReset->m_Flags;
    if ( (v126 & 0x4000) != 0 )
    {
      v127 = (UFG::TSActorComponent *)pSimObjectToReset->m_Components.p[4].m_pComponent;
    }
    else if ( v126 >= 0 )
    {
      if ( (v126 & 0x2000) != 0 )
      {
        v127 = (UFG::TSActorComponent *)pSimObjectToReset->m_Components.p[3].m_pComponent;
      }
      else if ( (v126 & 0x1000) != 0 )
      {
        v127 = (UFG::TSActorComponent *)pSimObjectToReset->m_Components.p[2].m_pComponent;
      }
      else
      {
        v127 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                          pSimObjectToReset,
                                          UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v127 = (UFG::TSActorComponent *)pSimObjectToReset->m_Components.p[4].m_pComponent;
    }
    if ( v127 )
    {
      i_obj_p = v127->mpActor.i_obj_p;
      if ( i_obj_p )
      {
        if ( v127->mpActor.i_ptr_id == i_obj_p->i_ptr_id )
        {
          Actor = UFG::TSActorComponent::GetActor(v127);
          SSActor::clear_coroutines(Actor);
          v130 = UFG::TSActorComponent::GetActor(v127);
          SSActor::enable_behavior(v130, 1);
        }
      }
    }
    v131 = pSimObjectToReset->m_Flags;
    if ( (v131 & 0x4000) != 0 )
    {
      v132 = (UFG::CharacterEffectsComponent *)pSimObjectToReset->m_Components.p[38].m_pComponent;
    }
    else
    {
      if ( v131 < 0 || (v131 & 0x2000) != 0 || (v131 & 0x1000) != 0 )
        v133 = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObjectToReset, UFG::CharacterEffectsComponent::_TypeUID);
      else
        v133 = UFG::SimObject::GetComponentOfType(pSimObjectToReset, UFG::CharacterEffectsComponent::_TypeUID);
      v132 = (UFG::CharacterEffectsComponent *)v133;
    }
    if ( v132 )
    {
      if ( v132->mIsOnFire )
        UFG::CharacterEffectsComponent::ExtinguishFire(v132);
      if ( v132->mIsSmoldering )
        UFG::CharacterEffectsComponent::ExtinguishSmolder(v132);
    }
  }
LABEL_444:
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(Instance, pSimObjectToReset, SuspendAllowed);
  if ( pSimObjectToReset == LocalPlayer )
    UFG::CustomizeBindings::OnResetLocalPlayer(pSimObjectToReset);
  return 1;
}

// File Line: 770
// RVA: 0x5233D0
void __fastcall UFG::SimObjectUtility::ConditionSimObjectForAmbientWorld(UFG::SimObject *pObject)
{
  signed __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSActor *i_obj_p; // rcx
  UFG::TSActor *Actor; // rax
  signed __int16 v6; // cx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v10; // rdx
  unsigned int v11; // r8d
  unsigned int v12; // r9d

  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)pObject->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)pObject->m_Components.p[3].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)pObject->m_Components.p[2].m_pComponent;
      }
      else
      {
        m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                  pObject,
                                                  UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)pObject->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent )
    {
      i_obj_p = m_pComponent->mpActor.i_obj_p;
      if ( i_obj_p )
      {
        if ( m_pComponent->mpActor.i_ptr_id == i_obj_p->i_ptr_id )
        {
          Actor = UFG::TSActorComponent::GetActor(m_pComponent);
          SSActor::clear_coroutines(Actor);
        }
      }
    }
    v6 = pObject->m_Flags;
    if ( (v6 & 0x4000) != 0 )
    {
      ComponentOfType = pObject->m_Components.p[8].m_pComponent;
      goto LABEL_35;
    }
    if ( v6 < 0 )
    {
      ComponentOfType = pObject->m_Components.p[8].m_pComponent;
      goto LABEL_35;
    }
    if ( (v6 & 0x2000) != 0 )
    {
      vfptr = (unsigned int)pObject[1].vfptr;
      size = pObject->m_Components.size;
      if ( vfptr < size )
      {
        v10 = &pObject->m_Components.p[vfptr];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
             || (UFG::MissionFailConditionComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v10;
          if ( vfptr >= size )
            goto LABEL_25;
        }
LABEL_26:
        ComponentOfType = v10->m_pComponent;
        goto LABEL_35;
      }
    }
    else
    {
      if ( (v6 & 0x1000) == 0 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(pObject, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_35:
        if ( ComponentOfType )
        {
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_ArrestFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_DeathFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_DamageFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_DistanceFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_PanicWeaponFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_PanicVehicleFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_VehicleFlipFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(pObject, &qSymbol_BoatStuckFailTrigger, 0);
          UFG::MissionFailConditionComponent::SetFailThreshold(pObject, &qSymbol_DamageHealthThreshold, 0.0);
        }
        return;
      }
      v11 = (unsigned int)pObject[1].vfptr;
      v12 = pObject->m_Components.size;
      if ( v11 < v12 )
      {
        v10 = &pObject->m_Components.p[v11];
        while ( (v10->m_TypeUID & 0xFE000000) != (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
             || (UFG::MissionFailConditionComponent::_TypeUID & ~v10->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v11;
          ++v10;
          if ( v11 >= v12 )
          {
            ComponentOfType = 0i64;
            goto LABEL_35;
          }
        }
        goto LABEL_26;
      }
    }
LABEL_25:
    ComponentOfType = 0i64;
    goto LABEL_35;
  }
}

// File Line: 798
// RVA: 0x5223E0
void __fastcall UFG::SimObjectUtility::AttachHudSymbol(
        UFG::SimObject *pObject,
        const char *symbolName,
        bool useCustomFilterDistance,
        float customFilterDistance,
        const char *customWorldMapCaption)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-40h] BYREF

  if ( (_S12_8 & 1) == 0 )
  {
    _S12_8 |= 1u;
    name_uid_2 = UFG::qStringHash32("hud_component", 0xFFFFFFFF);
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x118ui64, "HudComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::HudComponent::HudComponent(
      (UFG::HudComponent *)v9,
      name_uid_2,
      symbolName,
      useCustomFilterDistance,
      customFilterDistance,
      customWorldMapCaption);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, pObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v11, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
}

// File Line: 810
// RVA: 0x525C70
void __fastcall UFG::SimObjectUtility::DetachHudSymbol(UFG::SimObject *pObject)
{
  signed __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v4; // rdx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v6; // r8d
  unsigned int v7; // r9d
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d

  if ( pObject )
  {
    m_Flags = pObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      vfptr = (unsigned int)pObject[1].vfptr;
      size = pObject->m_Components.size;
      if ( vfptr < size )
      {
        v4 = &pObject->m_Components.p[vfptr];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
             || (UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v4;
          if ( vfptr >= size )
            goto LABEL_8;
        }
LABEL_9:
        m_pComponent = v4->m_pComponent;
        goto LABEL_32;
      }
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v8 = (unsigned int)pObject[1].vfptr;
        v9 = pObject->m_Components.size;
        if ( v8 < v9 )
        {
          v4 = &pObject->m_Components.p[v8];
          while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
               || (UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v8;
            ++v4;
            if ( v8 >= v9 )
              goto LABEL_8;
          }
          goto LABEL_9;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(pObject, UFG::HudComponent::_TypeUID);
LABEL_32:
          if ( m_pComponent )
            UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pComponent);
          return;
        }
        v10 = (unsigned int)pObject[1].vfptr;
        v11 = pObject->m_Components.size;
        if ( v10 < v11 )
        {
          v4 = &pObject->m_Components.p[v10];
          while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
               || (UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v10;
            ++v4;
            if ( v10 >= v11 )
              goto LABEL_8;
          }
          goto LABEL_9;
        }
      }
    }
    else
    {
      v6 = (unsigned int)pObject[1].vfptr;
      v7 = pObject->m_Components.size;
      if ( v6 < v7 )
      {
        v4 = &pObject->m_Components.p[v6];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
             || (UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v6;
          ++v4;
          if ( v6 >= v7 )
            goto LABEL_8;
        }
        goto LABEL_9;
      }
    }
LABEL_8:
    m_pComponent = 0i64;
    goto LABEL_32;
  }
}

// File Line: 823
// RVA: 0x52A360
UFG::qSymbol *__fastcall UFG::SimObjectUtility::GenerateUniqueActorName(UFG::qSymbol *result, UFG::qSymbol *basename)
{
  int v4; // ebx
  char dest[40]; // [rsp+20h] [rbp-28h] BYREF
  UFG::qSymbol instance_name; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol resulta; // [rsp+60h] [rbp+18h] BYREF

  v4 = 0;
  instance_name.mUID = -1;
  UFG::qSPrintf(dest, "_%d", 0i64);
  for ( instance_name.mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&resulta, basename, dest)->mUID;
        UFG::TSActor::find_instance((ASymbol *)&instance_name);
        instance_name.mUID = UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&resulta, basename, dest)->mUID )
  {
    UFG::qSPrintf(dest, "_%d", (unsigned int)++v4);
  }
  result->mUID = instance_name.mUID;
  return result;
}

// File Line: 875
// RVA: 0x556870
void __fastcall UFG::SimObjectUtility::Teleport(UFG::SimObject *pSimObject, UFG::qMatrix44 *xform)
{
  UFG::allocator::free_link *v4; // rax

  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      xform,
      pSimObject->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
}

// File Line: 894
// RVA: 0x53B940
bool __fastcall UFG::SimObjectUtility::IsPositionOnScreen(
        UFG::qVector3 *position,
        float radius,
        bool want_fully_on_screen)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rdx
  UFG::Camera *p_mCamera; // rdi
  UFG::qMatrix44 *ViewProjection; // rbx
  UFG::qMatrix44 *WorldView; // rax
  float v9; // xmm12_4
  float v10; // xmm11_4
  float v11; // xmm10_4
  float v12; // xmm13_4
  float v13; // xmm14_4
  float v14; // xmm15_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  __m128 v22; // xmm2
  float v23; // xmm0_4
  float v24; // xmm4_4
  __m128 v25; // xmm2
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm8_4
  int v29; // eax
  float v31; // [rsp+20h] [rbp-B8h]
  float v32; // [rsp+24h] [rbp-B4h]
  float v33; // [rsp+30h] [rbp-A8h]
  float v34; // [rsp+38h] [rbp-A0h]
  float v35; // [rsp+44h] [rbp-94h]
  float v36; // [rsp+48h] [rbp-90h]
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h] BYREF
  float v38; // [rsp+90h] [rbp-48h]
  float v39; // [rsp+94h] [rbp-44h]
  float v40; // [rsp+98h] [rbp-40h]
  float v41; // [rsp+9Ch] [rbp-3Ch]
  float v42; // [rsp+A0h] [rbp-38h]
  float v43; // [rsp+A4h] [rbp-34h]
  float v44; // [rsp+A8h] [rbp-30h]
  float v45; // [rsp+ACh] [rbp-2Ch]
  float v46; // [rsp+B0h] [rbp-28h]
  float v47; // [rsp+B4h] [rbp-24h]
  float v48; // [rsp+B8h] [rbp-20h]
  float v49; // [rsp+BCh] [rbp-1Ch]
  float v50; // [rsp+C0h] [rbp-18h]
  float v51; // [rsp+C4h] [rbp-14h]
  float radiusa; // [rsp+1A0h] [rbp+C8h]
  unsigned int v53; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
    p_mCamera = &mCurrentCamera->mCamera;
  else
    p_mCamera = 0i64;
  ViewProjection = UFG::Camera::GetViewProjection(p_mCamera);
  WorldView = UFG::Camera::GetWorldView(p_mCamera);
  UFG::qMatrix44::operator*(WorldView, &result, ViewProjection);
  LODWORD(v9) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v35) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v36) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  v53 = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v32) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v33) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  LODWORD(v34) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v31) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v15 = fsqrt(
          (float)((float)(COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]))
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  v16 = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v1.z) ^ _xmm[0]);
  result.v2.y = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v15) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = v16;
  v17 = fsqrt((float)((float)(v10 * v10) + (float)(v9 * v9)) + (float)(v11 * v11));
  v18 = (float)(1.0 / v17) * v9;
  v19 = (float)(1.0 / v17) * v10;
  v20 = 1.0 / v17;
  result.v2.z = v18;
  result.v2.w = v19;
  result.v3.y = v20 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = v20 * v11;
  v21 = fsqrt((float)((float)(v13 * v13) + (float)(v12 * v12)) + (float)(v14 * v14));
  v39 = (float)(1.0 / v21) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v21) * v12;
  v38 = (float)(1.0 / v21) * v14;
  result.v3.w = (float)(1.0 / v21) * v13;
  v22 = (__m128)v53;
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(vars0 * vars0)) + (float)(v32 * v32);
  v23 = _mm_sqrt_ps(v22).m128_f32[0];
  LODWORD(v24) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  v40 = (float)(1.0 / v23) * vars0;
  v42 = (float)(1.0 / v23) * v32;
  v41 = (float)(1.0 / v23) * *(float *)&v53;
  v25 = (__m128)LODWORD(v36);
  v43 = (float)(1.0 / v23) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0]);
  v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v35 * v35);
  v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
  v47 = v26 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v44 = v26 * v24;
  v45 = v26 * v36;
  v46 = v26 * v35;
  v27 = (__m128)LODWORD(v34);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v33 * v33)) + (float)(v31 * v31);
  v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
  v51 = v28 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v48 = v28 * v33;
  v49 = v28 * v34;
  v50 = v28 * v31;
  v29 = IntersectSphereFrustum((UFG::qVector4 *)&result.v1.z, position, radiusa);
  if ( want_fully_on_screen )
    return v29 == 1;
  else
    return v29 != 2;
}

// File Line: 929
// RVA: 0x54FB40
char __fastcall UFG::SimObjectUtility_PlaceOnWater(
        UFG::qVector3 *out,
        UFG::qVector3 *position,
        float height_above_ground,
        float cast_distance)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v8; // xmm3_4
  unsigned __int64 v9; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *TypeName; // rax
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qReflectHandleBase v15; // [rsp+40h] [rbp-B8h] BYREF
  __int64 v16; // [rsp+68h] [rbp-90h]
  UFG::RayCastData data; // [rsp+70h] [rbp-88h] BYREF

  v16 = -2i64;
  if ( cast_distance == 0.0 )
    cast_distance = FLOAT_3_0;
  y = position->y;
  z = position->z;
  rayStart.x = position->x;
  rayStart.y = y;
  rayEnd.x = rayStart.x;
  rayEnd.y = y;
  v8 = cast_distance * 0.5;
  rayStart.z = v8 + z;
  rayEnd.z = z - v8;
  data.mInput.m_to.m_quad.m128_i8[8] = 0;
  data.mInput.m_to.m_quad.m128_i32[3] = 0;
  *(_QWORD *)&data.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
  data.mOutput.m_normal.m_quad.m128_u64[1] = (unsigned int)FLOAT_1_0 | 0xFFFFFFFF00000000ui64;
  data.mOutput.m_shapeKeys[6] = 0;
  data.mOutput.m_pad[0] = -1;
  *((_QWORD *)&data.mOutput.m_shapeKeyIndex + 1) = 0i64;
  *((_QWORD *)&data.mOutput.m_rootCollidable + 1) = "SimObjectUtility_PlaceOnWater";
  LODWORD(data.mDebugName) = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x19u);
  if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
  {
    v9 = *(_QWORD *)&data.hit;
    UFG::qReflectHandleBase::qReflectHandleBase(&v15);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
    v15.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, v9);
    if ( v15.mData && BYTE4(v15.mData[1].mHandles.mNode.mPrev) )
    {
      out->x = *((float *)&data.mDebugName + 1);
      LODWORD(out->y) = data.mCollisionModelName.mUID;
      out->z = data.point.x + height_above_ground;
      UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      return 1;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
  }
  return 0;
}

// File Line: 988
// RVA: 0x542470
char __fastcall UFG::SimObjectUtility::PlaceOnGround(
        UFG::qVector3 *out,
        UFG::qVector3 *position,
        float height_above_ground,
        float cast_distance)
{
  float v4; // xmm4_4
  float y; // xmm0_4
  float z; // xmm3_4
  float x; // xmm1_4
  float v9; // xmm1_4
  char result; // al
  float v11; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h] BYREF
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h] BYREF
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h] BYREF

  v4 = cast_distance;
  if ( cast_distance == 0.0 )
    v4 = FLOAT_3_0;
  y = position->y;
  z = position->z;
  x = position->x;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.y = y;
  rayEnd.y = y;
  data.mOutput.m_rootCollidable = 0i64;
  rayStart.x = x;
  rayEnd.x = x;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  rayEnd.z = z - v4;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mDebugName = "PlaceOnGround";
  rayStart.z = z + (float)(height_above_ground + 1.0);
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x11u);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v9 = data.point.y;
  result = 1;
  out->x = data.point.x;
  v11 = data.point.z;
  out->y = v9;
  out->z = v11 + height_above_ground;
  return result;
}

// File Line: 1036
// RVA: 0x528D90
__int64 __fastcall UFG::SimObjectUtility::FindSpawnCharacterPosition(
        UFG::qVector3 *origin,
        float minRange,
        float maxRange,
        bool offscreenOnly)
{
  float y; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  UFG::DaemonManager *v11; // rax
  unsigned __int8 v12; // bl
  __int64 v13; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 out; // [rsp+30h] [rbp-C8h] BYREF
  UFG::DaemonQueryOutput output; // [rsp+40h] [rbp-B8h] BYREF
  __int64 (__fastcall **v18)(_QWORD); // [rsp+60h] [rbp-98h]
  UFG::qVector3 v19; // [rsp+68h] [rbp-90h]
  __m128 v20; // [rsp+78h] [rbp-80h]
  __int64 v21; // [rsp+88h] [rbp-70h]
  __int64 v22; // [rsp+98h] [rbp-60h]
  __int64 v23; // [rsp+A8h] [rbp-50h]
  UFG::SpawnTraversalImmediateQuery v24; // [rsp+B8h] [rbp-40h] BYREF
  __int64 retaddr; // [rsp+178h] [rbp+80h] BYREF
  UFG::qVector3 *v26; // [rsp+198h] [rbp+A0h]

  v23 = -2i64;
  UFG::SpawnTraversalImmediateQuery::SpawnTraversalImmediateQuery((UFG::SpawnTraversalImmediateQuery *)&v24.m_daemonType);
  output.m_id = DaemonType_Navigation;
  *(_QWORD *)&output.m_internalType = 4i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::SpawnTraversalOutput::`vftable;
  v19 = UFG::qVector3::msZero;
  v18 = &UFG::HavokNavPosition::`vftable;
  v21 = -1i64;
  v20 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v22 = 0i64;
  y = origin->y;
  z = origin->z;
  v24.mSearchOrigin.m_vPosition.x = origin->x;
  v24.mSearchOrigin.m_vPosition.y = y;
  v24.mSearchOrigin.m_vPosition.z = z;
  v24.mSearchOrigin.m_bValid = 0;
  UFG::HavokNavPosition::Validate(
    &v24.mSearchOrigin,
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
    0.0);
  v24.mSearchRadius = UFG::qRandom(maxRange - minRange, (unsigned int *)&UFG::qDefaultSeed) + minRange;
  v9 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  v10 = cosf(v9);
  v24.mSearchDirection.x = sinf(v9);
  v24.mSearchDirection.y = v10;
  v24.mSearchDirection.z = 0.0;
  v24.mRoadCost = FLOAT_50000_0;
  retaddr = LODWORD(FLOAT_0_5) | 0xFF0000000000i64;
  v24.mpNavParams = (UFG::NavParams *)&retaddr;
  v11 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v11, &v24, &output);
  if ( output.m_status != Status_Completed
    || (position = v19, offscreenOnly) && UFG::SimObjectUtility::IsPositionOnScreen(&position, 2.0, 0)
    || !UFG::SimObjectUtility::PlaceOnGround(&out, &position, 0.050000001, 5.0) )
  {
    v12 = 0;
  }
  else
  {
    *v26 = out;
    v12 = 1;
  }
  v13 = v22;
  if ( v22 )
  {
    --*(_DWORD *)(v22 + 40);
    if ( !*(_DWORD *)(v13 + 40) )
      (**(void (__fastcall ***)(__int64, __int64))v13)(v13, 1i64);
  }
  return v12;
}

// File Line: 1089
// RVA: 0x528BD0
char __fastcall UFG::SimObjectUtility::FindSpawnBoatPosition(
        UFG::qVector3 *origin,
        float minRange,
        float maxRange,
        bool offscreenOnly,
        UFG::qVector3 *pResult)
{
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm0_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  int v17[4]; // [rsp+40h] [rbp-88h] BYREF
  int v18[4]; // [rsp+50h] [rbp-78h] BYREF
  UFG::qVector3 out; // [rsp+60h] [rbp-68h] BYREF
  UFG::qVector3 position; // [rsp+70h] [rbp-58h] BYREF

  v7 = UFG::qRandom(360.0, (unsigned int *)&UFG::qDefaultSeed);
  v8 = sinf(v7);
  v9 = cosf(v7);
  v10 = (float)(maxRange - minRange) * 0.5;
  v11 = (float)(v8 * (float)(v10 + minRange)) + origin->x;
  v12 = (float)(v9 * (float)(v10 + minRange)) + origin->y;
  v13 = (float)((float)(v10 + minRange) * 0.0) + origin->z;
  *(float *)v18 = v11 - v10;
  *(float *)&v18[1] = v12 - v10;
  *(float *)&v17[1] = v12 + v10;
  *(float *)&v18[2] = v13 - v10;
  *(float *)&v17[2] = v13 + v10;
  *(float *)v17 = v11 + v10;
  if ( !((unsigned __int8 (__fastcall *)(UFG::NavManager *, int *, int *, __int64, _DWORD, _DWORD, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->FindPointOnNavmesh)(
          UFG::NavManager::ms_pInstance,
          v18,
          v17,
          64i64,
          LODWORD(FLOAT_6_0),
          LODWORD(FLOAT_7_0),
          &position)
    || offscreenOnly && UFG::SimObjectUtility::IsPositionOnScreen(&position, 2.0, 0)
    || !UFG::SimObjectUtility_PlaceOnWater(&out, &position, 0.050000001, 8.0) )
  {
    return 0;
  }
  y = out.y;
  pResult->x = out.x;
  z = out.z;
  pResult->y = y;
  pResult->z = z;
  return 1;
}

// File Line: 1160
// RVA: 0x529020
__int64 __fastcall UFG::SimObjectUtility::FindSpawnVehicleTransformIterated(
        UFG::qVector3 *origin,
        float minRadius,
        float maxRadius,
        bool offscreenOnly)
{
  float v4; // xmm9_4
  float v5; // xmm7_4
  UFG::WheeledVehicleManager *v7; // rsi
  unsigned __int8 v8; // di
  UFG::RoadNetworkResource *RoadNetwork; // r14
  UFG::RoadNetworkSegment *ClosestSegment; // r15
  UFG::RoadNetworkGraph *RoadNetworkGraph; // rsi
  UFG::WayTraversal *WayTraversal; // rax
  UFG::WayTraversal *v13; // rax
  float x; // xmm10_4
  __int64 m_NumWayEdges; // rbx
  float v16; // xmm6_4
  float v17; // xmm11_4
  __int64 v18; // rax
  unsigned __int16 v19; // di
  unsigned __int16 v20; // bx
  UFG::RoadNetworkSegment *Segment; // rdi
  unsigned int mPropertyID1; // eax
  int v24; // eax
  UFG::RoadNetworkIntersection *Intersection; // rsi
  unsigned int v26; // ebx
  UFG::RoadNetworkGate *IncomingConnection; // r13
  UFG::RoadNetworkIntersection *mOffset; // rax
  __int64 v29; // rbx
  bool v30; // r14
  unsigned int v31; // r12d
  UFG::RoadNetworkConnection *OutgoingConnection; // rsi
  __int64 v33; // rax
  UFG::RoadNetworkConnection *v34; // r15
  unsigned int i; // r14d
  unsigned int j; // edi
  unsigned int v37; // r12d
  UFG::RoadNetworkConnection *v38; // rsi
  __int64 v39; // rax
  UFG::RoadNetworkConnection *v40; // r15
  unsigned int k; // r14d
  unsigned int m; // edi
  __int64 *v43; // rdi
  __int64 v44; // rsi
  float v45; // xmm14_4
  UFG::RoadNetworkLane *v46; // rbx
  float v47; // xmm15_4
  float y; // xmm8_4
  float v49; // xmm13_4
  int v50; // xmm9_4
  float *v51; // r14
  UFG::WheeledVehicleManager *v52; // rsi
  char v53; // di
  float v54; // xmm6_4
  __m128 y_low; // xmm3
  float v56; // xmm5_4
  float v57; // xmm2_4
  __m128 v58; // xmm4
  float v59; // xmm4_4
  float v60; // xmm3_4
  float v61; // xmm5_4
  float v62; // xmm1_4
  float v63; // xmm6_4
  float v64; // xmm3_4
  float v65; // xmm6_4
  UFG::RoadNetworkNode *v66; // rcx
  __m128 x_low; // xmm3
  float v68; // xmm1_4
  float v69; // xmm5_4
  float v70; // xmm7_4
  float v71; // xmm8_4
  __m128 v72; // xmm3
  float v73; // xmm3_4
  float v74; // xmm1_4
  float v75; // xmm9_4
  float v76; // xmm3_4
  float v77; // xmm10_4
  float v78; // xmm11_4
  float v79; // xmm9_4
  float v80; // xmm3_4
  float v81; // xmm3_4
  float v82; // xmm1_4
  float v83; // xmm9_4
  float v84; // xmm3_4
  float v85; // xmm4_4
  float v86; // xmm5_4
  float v87; // xmm2_4
  UFG::qVector4 v88; // xmm1
  UFG::qVector4 v89; // xmm2
  UFG::qVector4 v90; // xmm3
  _OWORD *v91; // rcx
  bool v93; // [rsp+30h] [rbp-90h]
  char v94; // [rsp+31h] [rbp-8Fh]
  float laneT; // [rsp+34h] [rbp-8Ch] BYREF
  int v96; // [rsp+38h] [rbp-88h]
  float v97; // [rsp+3Ch] [rbp-84h]
  UFG::qVector4 v98; // [rsp+40h] [rbp-80h] BYREF
  UFG::qVector4 v99; // [rsp+50h] [rbp-70h]
  float nearestT[4]; // [rsp+60h] [rbp-60h] BYREF
  UFG::qVector4 v101; // [rsp+70h] [rbp-50h]
  __int64 *v102; // [rsp+80h] [rbp-40h]
  __int64 v103; // [rsp+88h] [rbp-38h]
  __int64 v104; // [rsp+90h] [rbp-30h]
  UFG::RoadNetworkResource *v105; // [rsp+98h] [rbp-28h]
  UFG::RoadNetworkSegment *v106; // [rsp+A0h] [rbp-20h]
  UFG::qVector3 v107; // [rsp+A8h] [rbp-18h] BYREF
  __int64 v108; // [rsp+B8h] [rbp-8h]
  UFG::qVector3 result; // [rsp+C0h] [rbp+0h] BYREF
  UFG::WheeledVehicleManager *v110; // [rsp+D0h] [rbp+10h]
  __int64 v111; // [rsp+D8h] [rbp+18h]
  UFG::qVector3 v112; // [rsp+E0h] [rbp+20h] BYREF
  UFG::qVector3 v113; // [rsp+F0h] [rbp+30h] BYREF
  __int64 v114[12]; // [rsp+100h] [rbp+40h] BYREF
  UFG::VehicleWayFinderClient v115; // [rsp+160h] [rbp+A0h] BYREF
  __int16 v116[631]; // [rsp+5AAh] [rbp+4EAh]
  float *v117; // [rsp+AA0h] [rbp+9E0h]
  float v118; // [rsp+AA8h] [rbp+9E8h]
  float v119; // [rsp+AB0h] [rbp+9F0h]
  char v120; // [rsp+AB8h] [rbp+9F8h]
  _OWORD *v121; // [rsp+AC0h] [rbp+A00h]
  char v122; // [rsp+AC8h] [rbp+A08h]

  v111 = -2i64;
  v4 = maxRadius;
  v5 = minRadius;
  *(UFG::qVector4 *)nearestT = UFG::qMatrix44::msIdentity.v0;
  v101 = UFG::qMatrix44::msIdentity.v1;
  v98 = UFG::qMatrix44::msIdentity.v2;
  v99 = UFG::qMatrix44::msIdentity.v3;
  nearestT[3] = UFG::qVector3::msDirFront.x;
  v101.y = UFG::qVector3::msDirFront.y;
  nearestT[0] = UFG::qVector3::msDirFront.z;
  v7 = UFG::WheeledVehicleManager::m_Instance;
  v110 = UFG::WheeledVehicleManager::m_Instance;
  v8 = 0;
  v94 = 0;
  UFG::VehicleWayFinderClient::VehicleWayFinderClient(
    (UFG::VehicleWayFinderClient *)&v115.m_WayEdges[13],
    0i64,
    0xFFFFFFFF);
  v115.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayTraversalClient::`vftable;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(v7->m_NavigationData);
  v105 = RoadNetwork;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(RoadNetwork, origin, 0i64, 0);
  v106 = ClosestSegment;
  LODWORD(nearestT[2]) = (_DWORD)FLOAT_1_0;
  UFG::RoadNetworkNode::GetClosestPosition(ClosestSegment, &result, origin, &nearestT[2]);
  RoadNetworkGraph = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                       UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                       Traffic);
  *(_QWORD *)&v99.z = RoadNetworkGraph;
  UFG::VehicleWayFinderClient::SetRoadNetworkType(&v115, 0);
  UFG::GetWayTraversal()->pWayGraph = RoadNetworkGraph;
  WayTraversal = UFG::GetWayTraversal();
  UFG::WayTraversal::FindConnectedEdgesInRange(
    WayTraversal,
    (UFG::WayTraversalClient *)&v115,
    origin,
    &result,
    minRadius,
    maxRadius);
  v13 = UFG::GetWayTraversal();
  UFG::WayTraversal::Service(v13, 0.0);
  x = v5 * v5;
  v99.x = v5 * v5;
  nearestT[1] = maxRadius * maxRadius;
  m_NumWayEdges = v115.m_NumWayEdges;
  v16 = UFG::qRandom(6.2831855, (unsigned int *)&UFG::qDefaultSeed);
  v101.z = sinf(v16);
  v101.x = cosf(v16);
  v17 = FLOAT_N2_0;
  v97 = FLOAT_N2_0;
  v18 = 0i64;
  v103 = 0i64;
  v108 = m_NumWayEdges;
  if ( (int)m_NumWayEdges > 0 )
  {
    do
    {
      v19 = v115.m_WayEdges[v18];
      v20 = v116[v18];
      if ( !RoadNetworkGraph->vfptr->IsEdge(RoadNetworkGraph, v20) )
      {
        Segment = UFG::RoadNetworkResource::GetSegment(RoadNetwork, v19);
        mPropertyID1 = Segment->mPropertyID1;
        if ( mPropertyID1 )
        {
          if ( mPropertyID1 != 10 && !(mPropertyID1 == 20 ? v122 == 0 : mPropertyID1 == 750) )
          {
            if ( v20 )
            {
              v24 = RoadNetworkGraph->vfptr->GetNumEdges(RoadNetworkGraph);
              Intersection = UFG::RoadNetworkResource::GetIntersection(RoadNetwork, (unsigned int)v20 - v24);
            }
            else
            {
              Intersection = 0i64;
            }
            v26 = 0;
            if ( Segment->mNumGates )
            {
              while ( 1 )
              {
                IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                               (UFG::RoadNetworkGate *)Segment,
                                                               v26);
                mOffset = (UFG::RoadNetworkIntersection *)IncomingConnection->mConnectedNode.mOffset;
                if ( mOffset )
                  mOffset = (UFG::RoadNetworkIntersection *)((char *)&mOffset->mDataHash + (_QWORD)IncomingConnection);
                if ( mOffset == Intersection )
                  break;
                if ( ++v26 >= (unsigned __int8)Segment->mNumGates )
                  goto LABEL_81;
              }
              if ( IncomingConnection )
              {
                v29 = 0i64;
                v30 = Segment == ClosestSegment;
                v93 = Segment == ClosestSegment;
                v31 = 0;
                if ( IncomingConnection->mNumOutgoingConnections )
                {
                  do
                  {
                    OutgoingConnection = UFG::RoadNetworkGate::GetOutgoingConnection(IncomingConnection, v31);
                    v33 = OutgoingConnection->mConnection.mOffset;
                    if ( v33 )
                    {
                      v34 = (UFG::RoadNetworkConnection *)((char *)&OutgoingConnection->mConnection + v33);
                      if ( v34 )
                      {
                        for ( i = 0; i < v34->mNumLanes; ++i )
                        {
                          UFG::qBezierPathCollectionMemImaged::GetPath(v34, i);
                          for ( j = 0; j < OutgoingConnection->mNumLanes; ++j )
                          {
                            if ( (unsigned int)v29 < 0xC )
                            {
                              v114[v29] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(OutgoingConnection, j);
                              v29 = (unsigned int)(v29 + 1);
                            }
                          }
                        }
                      }
                    }
                    ++v31;
                  }
                  while ( v31 < IncomingConnection->mNumOutgoingConnections );
                  v30 = v93;
                }
                if ( v30 )
                {
                  v37 = 0;
                  if ( IncomingConnection->mNumIncomingConnections )
                  {
                    do
                    {
                      v38 = UFG::RoadNetworkGate::GetIncomingConnection(IncomingConnection, v37);
                      v39 = v38->mConnection.mOffset;
                      if ( v39 )
                      {
                        v40 = (UFG::RoadNetworkConnection *)((char *)&v38->mConnection + v39);
                        if ( v40 )
                        {
                          for ( k = 0; k < v40->mNumLanes; ++k )
                          {
                            UFG::qBezierPathCollectionMemImaged::GetPath(v40, k);
                            for ( m = 0; m < v38->mNumLanes; ++m )
                            {
                              if ( (unsigned int)v29 < 0xC )
                              {
                                v114[v29] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v38, m);
                                v29 = (unsigned int)(v29 + 1);
                              }
                            }
                          }
                        }
                      }
                      ++v37;
                    }
                    while ( v37 < IncomingConnection->mNumIncomingConnections );
                    v30 = v93;
                  }
                }
                Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
                Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
                if ( (_DWORD)v29 )
                {
                  v43 = v114;
                  v102 = v114;
                  v44 = (unsigned int)v29;
                  v104 = (unsigned int)v29;
                  do
                  {
                    v45 = 0.0;
                    v46 = (UFG::RoadNetworkLane *)*v43;
                    v47 = *(float *)&FLOAT_1_0;
                    y = 1.0 / UFG::RoadNetworkLane::GetLength((UFG::RoadNetworkLane *)*v43);
                    v99.y = y;
                    if ( v30 )
                    {
                      laneT = 0.0;
                      UFG::RoadNetworkLane::GetNearestPoint(v46, &v112, &result, &laneT);
                      UFG::RoadNetworkLane::GetPos(v46, &v113, laneT);
                      v47 = laneT;
                    }
                    v49 = 0.0;
                    if ( v47 > 0.0 )
                    {
                      *(float *)&v50 = v4 - v5;
                      v96 = v50;
                      v51 = v117;
                      v52 = v110;
                      v53 = v120;
                      do
                      {
                        UFG::RoadNetworkLane::GetPos(v46, (UFG::qVector3 *)&v98, v49);
                        v54 = v98.z - v51[2];
                        y_low = (__m128)LODWORD(v98.y);
                        y_low.m128_f32[0] = v98.y - v51[1];
                        v56 = v98.x - *v51;
                        v57 = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v56 * v56))
                            + (float)(v54 * v54);
                        v58 = y_low;
                        v58.m128_f32[0] = v57;
                        if ( v57 == 0.0 )
                          v59 = 0.0;
                        else
                          v59 = 1.0 / _mm_sqrt_ps(v58).m128_f32[0];
                        v60 = y_low.m128_f32[0] * v59;
                        v61 = v56 * v59;
                        v62 = (float)(v59 * v54) * nearestT[0];
                        v63 = (float)((float)((float)((float)(v61 * v101.x) + (float)(v60 * v101.z)) + v62) + 1.0) * 0.5;
                        v64 = (float)((float)((float)((float)(v60 * v101.y) + (float)(v61 * nearestT[3])) + v62) + 1.5)
                            * 0.40000001;
                        v5 = v118;
                        if ( v57 >= x
                          && v57 <= (float)((float)((float)(*(float *)&v50 * v64) + v118)
                                          * (float)((float)(*(float *)&v50 * v64) + v118)) )
                        {
                          v65 = (float)(v63 + 100.0) + (float)((float)(v57 - x) / (float)(nearestT[1] - x));
                          if ( v65 > v17 )
                          {
                            if ( v46->mNode.mOffset )
                              v66 = (UFG::RoadNetworkNode *)((char *)v46 + v46->mNode.mOffset);
                            else
                              v66 = 0i64;
                            UFG::RoadNetworkNode::GetTangent(v66, &v107, v46->mLaneIndex, v49);
                            x_low = (__m128)LODWORD(v107.x);
                            x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                                      + (float)(v107.y * v107.y))
                                              + (float)(v107.z * v107.z);
                            if ( x_low.m128_f32[0] == 0.0 )
                              v68 = 0.0;
                            else
                              v68 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
                            v69 = v107.z * v68;
                            v70 = v107.y * v68;
                            v71 = v107.x * v68;
                            nearestT[0] = v107.x * v68;
                            nearestT[1] = v107.y * v68;
                            nearestT[2] = v107.z * v68;
                            nearestT[3] = 0.0;
                            v72 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
                            v72.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0])
                                                    + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                                            + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
                            if ( v72.m128_f32[0] == 0.0 )
                              v73 = 0.0;
                            else
                              v73 = 1.0 / _mm_sqrt_ps(v72).m128_f32[0];
                            v74 = v73 * UFG::qVector3::msDirUp.z;
                            v75 = v73 * UFG::qVector3::msDirUp.y;
                            v76 = v73 * UFG::qVector3::msDirUp.x;
                            v77 = (float)(v76 * v70) - (float)(v71 * v75);
                            v78 = (float)(v71 * v74) - (float)(v76 * v69);
                            v79 = (float)(v75 * v69) - (float)(v74 * v70);
                            v80 = (float)((float)(v79 * v79) + (float)(v78 * v78)) + (float)(v77 * v77);
                            if ( v80 == 0.0 )
                              v81 = 0.0;
                            else
                              v81 = 1.0 / fsqrt(v80);
                            v82 = v81 * v78;
                            v101.x = v81 * v79;
                            v101.y = v81 * v78;
                            v101.z = v81 * v77;
                            v101.w = 0.0;
                            v83 = (float)((float)(v81 * v78) * v71) - (float)((float)(v81 * v79) * v70);
                            v84 = (float)(v101.x * v69) - (float)((float)(v81 * v77) * v71);
                            v85 = (float)(v101.z * v70) - (float)(v82 * v69);
                            v86 = (float)((float)(v85 * v85) + (float)(v84 * v84)) + (float)(v83 * v83);
                            if ( v86 == 0.0 )
                              v87 = 0.0;
                            else
                              v87 = 1.0 / fsqrt(v86);
                            v98.x = v85 * v87;
                            v98.y = v87 * v84;
                            v98.z = v87 * v83;
                            v98.w = 0.0;
                            v99.x = v85 * v87;
                            v99.y = v87 * v84;
                            v99.z = v87 * v83;
                            v99.w = 1.0;
                            if ( v53 && UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v98, 2.0, 0)
                              || !UFG::WheeledVehicleManager::CheckSpawnLocationSimple(v52, (UFG::qVector3 *)&v98) )
                            {
                              v65 = 0.0;
                              v17 = v97;
                            }
                            else
                            {
                              v17 = v65;
                              v97 = v65;
                              v94 = 1;
                            }
                            v5 = v118;
                            x = v99.x;
                            v50 = v96;
                            y = v99.y;
                          }
                          if ( v65 > v45 )
                            v45 = v65;
                        }
                        v49 = v49 + y;
                      }
                      while ( v49 < v47 );
                      v4 = v119;
                      v43 = v102;
                      v44 = v104;
                      v30 = v93;
                    }
                    v102 = ++v43;
                    v104 = --v44;
                  }
                  while ( v44 );
                }
                ClosestSegment = v106;
                RoadNetwork = v105;
              }
            }
LABEL_81:
            RoadNetworkGraph = *(UFG::RoadNetworkGraph **)&v99.z;
          }
        }
      }
      v18 = v103 + 1;
      v103 = v18;
    }
    while ( v18 < v108 );
    v8 = v94;
    if ( v94 )
    {
      v88 = v101;
      v89 = v98;
      v90 = v99;
      v91 = v121;
      *v121 = *(_OWORD *)nearestT;
      v91[1] = v88;
      v91[2] = v89;
      v91[3] = v90;
    }
  }
  return v8;
}

// File Line: 1590
// RVA: 0x528BC0
char __fastcall UFG::SimObjectUtility::FindRandomSidewalkPosition(
        UFG::qVector3 *origin,
        float minRange,
        float maxRange,
        bool offscreenOnly,
        UFG::qVector3 *pResult)
{
  char result; // al

  result = (char)pResult;
  if ( pResult )
    return UFG::AISidewalkGraph::FindNodeLocationInRange(origin, minRange, maxRange, offscreenOnly, pResult);
  return result;
}

// File Line: 1600
// RVA: 0x539A90
char __fastcall UFG::SimObjectUtility::IsClassType(UFG::SimObject *pSimObject, UFG::qSymbol *targetClassType)
{
  UFG::qPropertySet *mpWritableProperties; // rbx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v9; // rdx
  unsigned int mPrev; // ecx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax

  UFG::qGetTicks();
  mpWritableProperties = 0i64;
  if ( !pSimObject )
    return UFG::SimObjectUtility::IsClassType(mpWritableProperties, targetClassType);
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      size = pSimObject->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_14:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = &pSimObject->m_Components.p[vfptr];
        while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v9;
          if ( vfptr >= size )
            goto LABEL_14;
        }
        m_pComponent = v9->m_pComponent;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  if ( !m_pComponent )
  {
    m_pSceneObj = pSimObject->m_pSceneObj;
    if ( m_pSceneObj )
    {
      mpWritableProperties = m_pSceneObj->mpWritableProperties;
      if ( !mpWritableProperties )
        mpWritableProperties = m_pSceneObj->mpConstProperties;
    }
    return UFG::SimObjectUtility::IsClassType(mpWritableProperties, targetClassType);
  }
  mPrev = (unsigned int)m_pComponent[2].m_SafePointerList.mNode.mPrev;
  if ( mPrev )
  {
    mNext = m_pComponent[2].m_SafePointerList.mNode.mNext;
    while ( targetClassType->mUID != LODWORD(mNext->mPrev) )
    {
      LODWORD(mpWritableProperties) = (_DWORD)mpWritableProperties + 1;
      mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)mNext + 4);
      if ( (unsigned int)mpWritableProperties >= mPrev )
        goto LABEL_22;
    }
  }
  else
  {
LABEL_22:
    LODWORD(mpWritableProperties) = -1;
  }
  return (int)mpWritableProperties >= 0;
}

// File Line: 1619
// RVA: 0x52B140
__int64 __fastcall UFG::SimObjectUtility::GetClassTypes(
        UFG::qPropertySet *pPropertySet,
        UFG::qSymbol *classTypes,
        unsigned int maxClassTypes)
{
  UFG::qPropertySet *v4; // rax
  char *MemImagePtr; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::qPropertyList *v8; // rcx
  unsigned int mNumElements; // esi
  signed __int64 v10; // rdi
  __int64 v11; // rdx
  unsigned int v12; // ecx

  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pPropertySet,
         (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
         DEPTH_RECURSE);
  if ( !v4 )
    return 0i64;
  MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v4);
  v6 = MemImagePtr;
  if ( !MemImagePtr )
    return 0i64;
  v7 = *((_QWORD *)MemImagePtr + 1);
  if ( !v7 )
    return 0i64;
  v8 = (UFG::qPropertyList *)&v6[v7 + 8];
  if ( !v8 )
    return 0i64;
  mNumElements = v8->mNumElements;
  if ( mNumElements )
  {
    v10 = (char *)UFG::qPropertyList::Get<UFG::qSymbol>(v8, 0) - (char *)classTypes;
    v11 = mNumElements;
    do
    {
      v12 = *(unsigned int *)((char *)&classTypes->mUID + v10);
      ++classTypes;
      classTypes[-1].mUID = v12;
      --v11;
    }
    while ( v11 );
  }
  return mNumElements;
}

// File Line: 1642
// RVA: 0x539C00
char __fastcall UFG::SimObjectUtility::IsClassType(UFG::qPropertySet *pPropertySet, UFG::qSymbol *targetClassType)
{
  UFG::qPropertySet *v3; // rax
  char *MemImagePtr; // rax
  char *v5; // rcx
  __int64 v6; // rax
  UFG::qPropertyList *v7; // rcx
  unsigned int mNumElements; // edi
  int v9; // ebx
  UFG::qSymbol *v10; // rcx

  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pPropertySet,
         (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
         DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v3);
  v5 = MemImagePtr;
  if ( !MemImagePtr )
    return 0;
  v6 = *((_QWORD *)MemImagePtr + 1);
  if ( !v6 )
    return 0;
  v7 = (UFG::qPropertyList *)&v5[v6 + 8];
  if ( !v7 )
    return 0;
  mNumElements = v7->mNumElements;
  v9 = 0;
  v10 = mNumElements ? UFG::qPropertyList::Get<UFG::qSymbol>(v7, 0) : 0i64;
  if ( !mNumElements )
    return 0;
  while ( v10[v9].mUID != targetClassType->mUID )
  {
    if ( ++v9 >= mNumElements )
      return 0;
  }
  return 1;
}

// File Line: 1666
// RVA: 0x539CB0
char __fastcall UFG::SimObjectUtility::IsClassTypeInArray(
        UFG::SimObject *pSimObject,
        UFG::qArray<UFG::qSymbol,0> *array)
{
  __int64 size; // rbx
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // r10
  unsigned int vfptr; // r8d
  unsigned int v8; // r9d
  UFG::SimComponentHolder *v9; // rdx
  __int64 v10; // r9
  unsigned int mPrev; // edx
  int v12; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v17; // rax
  char *MemImagePtr; // rax
  char *v19; // rcx
  __int64 v20; // rax
  UFG::qPropertyList *v21; // rbp
  unsigned int mNumElements; // esi
  unsigned int v23; // edi
  UFG::qSymbol *v24; // rax
  __int64 v25; // rcx
  unsigned int mUID; // edx
  UFG::qSymbol *p; // rax

  size = array->size;
  if ( !(_DWORD)size || !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)pSimObject[1].vfptr;
      v8 = pSimObject->m_Components.size;
      if ( vfptr >= v8 )
      {
LABEL_15:
        m_pComponent = 0i64;
      }
      else
      {
        v9 = &pSimObject->m_Components.p[vfptr];
        while ( (v9->m_TypeUID & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || (UFG::SimObjectPropertiesComponent::_TypeUID & ~v9->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v9;
          if ( vfptr >= v8 )
            goto LABEL_15;
        }
        m_pComponent = v9->m_pComponent;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = pSimObject->m_Components.p[3].m_pComponent;
  }
  if ( m_pComponent )
  {
    v10 = 0i64;
    mPrev = (unsigned int)m_pComponent[2].m_SafePointerList.mNode.mPrev;
    while ( 1 )
    {
      v12 = 0;
      if ( mPrev )
      {
        mNext = m_pComponent[2].m_SafePointerList.mNode.mNext;
        while ( array->p[v10].mUID != LODWORD(mNext->mPrev) )
        {
          ++v12;
          mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)mNext + 4);
          if ( v12 >= mPrev )
            goto LABEL_27;
        }
        if ( v12 >= 0 )
          return 1;
      }
LABEL_27:
      if ( ++v10 >= size )
        return 0;
    }
  }
  m_pSceneObj = pSimObject->m_pSceneObj;
  if ( m_pSceneObj )
  {
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
  }
  else
  {
    mpWritableProperties = 0i64;
  }
  v17 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&schema_classlist::sPropertyName,
          DEPTH_RECURSE);
  if ( v17 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v17);
    v19 = MemImagePtr;
    if ( MemImagePtr )
    {
      v20 = *((_QWORD *)MemImagePtr + 1);
      if ( v20 )
      {
        v21 = (UFG::qPropertyList *)&v19[v20 + 8];
        if ( v21 )
        {
          mNumElements = v21->mNumElements;
          v23 = 0;
          if ( mNumElements )
          {
LABEL_39:
            v24 = UFG::qPropertyList::Get<UFG::qSymbol>(v21, v23);
            v25 = 0i64;
            mUID = v24->mUID;
            p = array->p;
            while ( p->mUID != mUID )
            {
              ++v25;
              ++p;
              if ( v25 >= size )
              {
                if ( ++v23 < mNumElements )
                  goto LABEL_39;
                return 0;
              }
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 1711
// RVA: 0x528680
UFG::qPropertySet *__fastcall UFG::SimObjectUtility::FindDriverProfile(UFG::qPropertySet *vehiclePropertySet)
{
  UFG::qPropertyList *v2; // rax
  UFG::qPropertyList *v3; // rbx
  unsigned int RandomIndex; // eax
  UFG::qSymbol *v5; // rax

  if ( !vehiclePropertySet )
    return 0i64;
  v2 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         vehiclePropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_DriverProfileList,
         DEPTH_RECURSE);
  v3 = v2;
  if ( !v2 || !v2->mNumElements )
    return 0i64;
  RandomIndex = UFG::qPropertyList::GetRandomIndex(v2);
  v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v3, RandomIndex);
  return UFG::PropertySetManager::FindPropertySet(v5);
}

// File Line: 1741
// RVA: 0x523EE0
void __fastcall UFG::SimObjectUtility::CreateAndAttachProp(
        UFG::qPropertySet *propertySet,
        UFG::SimObjectProp *attachTo,
        bool deletePhysicsFails)
{
  UFG::qSymbol *v6; // rax
  Creature *mCreature; // rdi
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  signed __int16 m_Flags; // cx
  unsigned int mComponentTableEntryCount; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v12; // rdx
  UFG::qSymbol *v13; // rax
  UFG::qPropertySet *AssetPropertySet; // r15
  UFG::SimObjectProp *v15; // rax
  UFG::SimObjectProp *v16; // rbx
  UFG::CharacterAnimationComponent *v17; // r14
  UFG::SimComponent *v18; // rax
  __int16 v19; // cx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  unsigned int v21; // r8d
  unsigned int v22; // r10d
  __int64 v23; // rdx
  __int16 v24; // cx
  unsigned int v25; // r8d
  unsigned int v26; // r10d
  __int64 v27; // rdx
  unsigned int v28; // r8d
  unsigned int v29; // r10d
  unsigned int v30; // r8d
  unsigned int v31; // r10d
  unsigned int v32; // r8d
  unsigned int v33; // r10d
  UFG::qResourceData *mData; // rcx
  UFG::qVector3 *v35; // r12
  UFG::qVector3 *v36; // r13
  UFG::qVector3 *v37; // r15
  float x; // xmm1_4
  float y; // xmm1_4
  signed __int16 v40; // cx
  UFG::SimComponent *v41; // rcx
  UFG::CharacterAnimationComponent *v42; // rax
  unsigned int v43; // r8d
  unsigned int v44; // r10d
  UFG::SimComponentHolder *v45; // rdx
  Creature *v46; // rsi
  int v47; // r14d
  int BoneID; // edi
  float v49; // xmm1_4
  float v50; // xmm0_4
  UFG::qVector3 radians; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qMatrix44 rot; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qMatrix44 relativeTransform; // [rsp+80h] [rbp-80h] BYREF
  char dest[176]; // [rsp+C0h] [rbp-40h] BYREF
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+180h] [rbp+80h] BYREF
  UFG::qSymbol objName; // [rsp+188h] [rbp+88h] BYREF
  UFG::qSymbol result; // [rsp+198h] [rbp+98h] BYREF

  UFG::qSPrintf(dest, "attachableProp:%x", propertySet->mName.mUID);
  v6 = UFG::qSymbol::create_from_string(&result, dest);
  UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v6);
  mCreature = 0i64;
  if ( !attachTo )
    goto LABEL_2;
  m_Flags = attachTo->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::StreamedResourceComponent *)attachTo->m_Components.p[10].m_pComponent;
    goto LABEL_18;
  }
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::StreamedResourceComponent *)attachTo->m_Components.p[10].m_pComponent;
    goto LABEL_18;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    m_pComponent = (UFG::StreamedResourceComponent *)attachTo->m_Components.p[7].m_pComponent;
    goto LABEL_18;
  }
  if ( (m_Flags & 0x1000) == 0 )
  {
    m_pComponent = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                       attachTo,
                                                       UFG::StreamedResourceComponent::_TypeUID);
    goto LABEL_18;
  }
  mComponentTableEntryCount = attachTo->mComponentTableEntryCount;
  size = attachTo->m_Components.size;
  if ( mComponentTableEntryCount < size )
  {
    v12 = &attachTo->m_Components.p[mComponentTableEntryCount];
    while ( (v12->m_TypeUID & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
         || (UFG::StreamedResourceComponent::_TypeUID & ~v12->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      ++mComponentTableEntryCount;
      ++v12;
      if ( mComponentTableEntryCount >= size )
      {
        m_pComponent = 0i64;
        goto LABEL_18;
      }
    }
    m_pComponent = (UFG::StreamedResourceComponent *)v12->m_pComponent;
  }
  else
  {
LABEL_2:
    m_pComponent = 0i64;
  }
LABEL_18:
  priority = UnReferenced;
  UFG::StreamedResourceComponent::GetSpawnPriority(m_pComponent, &priority);
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(
          propertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_AttachOffset,
          DEPTH_RECURSE);
  AssetPropertySet = 0i64;
  if ( v13 )
  {
    AssetPropertySet = UFG::StreamedResourceComponent::GetAssetPropertySet(
                         m_pComponent,
                         (UFG::qArray<unsigned long,0> *)v13);
    if ( !AssetPropertySet )
      return;
  }
  v15 = (UFG::SimObjectProp *)UFG::SpawnInfoInterface::SpawnObject(&objName, propertySet, priority, 0i64, 0i64, 0i64);
  v16 = v15;
  if ( !v15 )
  {
    v17 = 0i64;
LABEL_22:
    v18 = 0i64;
    goto LABEL_75;
  }
  v19 = v15->m_Flags;
  if ( (v19 & 0x4000) != 0 )
  {
    v17 = (UFG::CharacterAnimationComponent *)v15->m_Components.p[9].m_pComponent;
    if ( !v17
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_27;
    }
    goto LABEL_45;
  }
  if ( v19 < 0 )
  {
    v17 = (UFG::CharacterAnimationComponent *)v15->m_Components.p[9].m_pComponent;
    if ( !v17 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_27;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
      v17 = 0i64;
    goto LABEL_45;
  }
  if ( (v19 & 0x2000) != 0 )
  {
    ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v15);
LABEL_44:
    v17 = ComponentOfType;
    goto LABEL_45;
  }
  if ( (v19 & 0x1000) == 0 )
  {
    ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            v15,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_44;
  }
  v21 = v15->mComponentTableEntryCount;
  v22 = v15->m_Components.size;
  if ( v21 >= v22 )
  {
LABEL_27:
    v17 = 0i64;
    goto LABEL_45;
  }
  v23 = (__int64)&v15->m_Components.p[v21];
  while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF) != 0 )
  {
    ++v21;
    v23 += 16i64;
    if ( v21 >= v22 )
    {
      v17 = 0i64;
      goto LABEL_45;
    }
  }
  v17 = *(UFG::CharacterAnimationComponent **)v23;
LABEL_45:
  v24 = v16->m_Flags;
  if ( (v24 & 0x4000) != 0 )
  {
    v25 = v16->mComponentTableEntryCount;
    v26 = v16->m_Components.size;
    if ( v25 >= v26 )
      goto LABEL_22;
    v27 = (__int64)&v16->m_Components.p[v25];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v25;
      v27 += 16i64;
      if ( v25 >= v26 )
      {
        v18 = 0i64;
        goto LABEL_75;
      }
    }
    goto LABEL_52;
  }
  if ( v24 < 0 )
  {
    v28 = v16->mComponentTableEntryCount;
    v29 = v16->m_Components.size;
    if ( v28 >= v29 )
      goto LABEL_22;
    v27 = (__int64)&v16->m_Components.p[v28];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v28;
      v27 += 16i64;
      if ( v28 >= v29 )
      {
        v18 = 0i64;
        goto LABEL_75;
      }
    }
    goto LABEL_52;
  }
  if ( (v24 & 0x2000) != 0 )
  {
    v30 = v16->mComponentTableEntryCount;
    v31 = v16->m_Components.size;
    if ( v30 >= v31 )
      goto LABEL_22;
    v27 = (__int64)&v16->m_Components.p[v30];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v30;
      v27 += 16i64;
      if ( v30 >= v31 )
      {
        v18 = 0i64;
        goto LABEL_75;
      }
    }
    goto LABEL_52;
  }
  if ( (v24 & 0x1000) != 0 )
  {
    v32 = v16->mComponentTableEntryCount;
    v33 = v16->m_Components.size;
    if ( v32 >= v33 )
      goto LABEL_22;
    v27 = (__int64)&v16->m_Components.p[v32];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || (UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF) != 0 )
    {
      ++v32;
      v27 += 16i64;
      if ( v32 >= v33 )
      {
        v18 = 0i64;
        goto LABEL_75;
      }
    }
LABEL_52:
    v18 = *(UFG::SimComponent **)v27;
    goto LABEL_75;
  }
  v18 = UFG::SimObject::GetComponentOfType(v16, UFG::RigidBodyComponent::_TypeUID);
LABEL_75:
  if ( deletePhysicsFails )
  {
    if ( v17 )
    {
      mData = v17->mRigHandle.mData;
      if ( mData )
      {
        if ( *(_DWORD *)&mData[1].mDebugName[4] && !v18 )
          goto LABEL_124;
      }
    }
  }
  if ( !v16 )
    return;
  if ( !UFG::InventoryComponent::Equip(attachTo, v16) )
  {
LABEL_124:
    UFG::SimObject::Destroy(v16);
    return;
  }
  if ( !AssetPropertySet )
    return;
  relativeTransform = UFG::qMatrix44::msIdentity;
  v35 = UFG::qPropertySet::Get<UFG::qVector3>(
          AssetPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_Scale,
          DEPTH_RECURSE);
  v36 = UFG::qPropertySet::Get<UFG::qVector3>(
          AssetPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_Rotation,
          DEPTH_RECURSE);
  v37 = UFG::qPropertySet::Get<UFG::qVector3>(
          AssetPropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_Translation,
          DEPTH_RECURSE);
  if ( v36 )
  {
    x = v36->x;
    rot = UFG::qMatrix44::msIdentity;
    radians.z = (float)(x * -3.1415927) * 0.0055555557;
    radians.x = (float)(v36->z * 3.1415927) * 0.0055555557;
    radians.y = (float)(v36->y * 3.1415927) * 0.0055555557;
    UFG::qRotationMatrixXYZDepreciated(&rot, &radians);
    UFG::qMatrix44::operator*=(&relativeTransform, &rot);
  }
  if ( v37 )
  {
    y = v37->y;
    rot = UFG::qMatrix44::msIdentity;
    radians.y = y;
    radians.x = v37->z;
    LODWORD(radians.z) = LODWORD(v37->x) ^ _xmm[0];
    UFG::qTranslationMatrix(&rot, &radians);
    UFG::qMatrix44::operator*=(&relativeTransform, &rot);
  }
  if ( !attachTo )
    goto LABEL_112;
  v40 = attachTo->m_Flags;
  if ( (v40 & 0x4000) != 0 )
  {
    v41 = attachTo->m_Components.p[9].m_pComponent;
    if ( !v41
      || ((UFG::CharacterAnimationComponent::_TypeUID ^ v41->m_TypeUID) & 0xFE000000) != 0
      || (UFG::CharacterAnimationComponent::_TypeUID & ~v41->m_TypeUID & 0x1FFFFFF) != 0 )
    {
      goto LABEL_92;
    }
    goto LABEL_110;
  }
  if ( v40 < 0 )
  {
    v41 = attachTo->m_Components.p[9].m_pComponent;
    if ( !v41 || ((UFG::CharacterAnimationComponent::_TypeUID ^ v41->m_TypeUID) & 0xFE000000) != 0 )
      goto LABEL_92;
    if ( (UFG::CharacterAnimationComponent::_TypeUID & ~v41->m_TypeUID & 0x1FFFFFF) != 0 )
      v41 = 0i64;
    goto LABEL_110;
  }
  if ( (v40 & 0x2000) != 0 )
  {
    v42 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(attachTo);
LABEL_109:
    v41 = v42;
    goto LABEL_110;
  }
  if ( (v40 & 0x1000) == 0 )
  {
    v42 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                attachTo,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_109;
  }
  v43 = attachTo->mComponentTableEntryCount;
  v44 = attachTo->m_Components.size;
  if ( v43 >= v44 )
  {
LABEL_92:
    v41 = 0i64;
    goto LABEL_110;
  }
  v45 = &attachTo->m_Components.p[v43];
  while ( (v45->m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || (UFG::CharacterAnimationComponent::_TypeUID & ~v45->m_TypeUID & 0x1FFFFFF) != 0 )
  {
    ++v43;
    ++v45;
    if ( v43 >= v44 )
    {
      v41 = 0i64;
      goto LABEL_110;
    }
  }
  v41 = v45->m_pComponent;
LABEL_110:
  if ( !v41 )
  {
LABEL_112:
    v46 = 0i64;
    goto LABEL_113;
  }
  v46 = *(Creature **)&v41[2].m_TypeUID;
LABEL_113:
  if ( v17 )
    mCreature = v17->mCreature;
  if ( v46 && mCreature )
  {
    *(_QWORD *)&radians.x = -1i64;
    UFG::InventoryComponent::EquipInfo::init(
      (UFG::InventoryComponent::EquipInfo *)&radians,
      v16,
      0,
      eINVENTORY_EQUIP_SLOT_RIGHT_HAND);
    v47 = -1;
    if ( mCreature->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, LODWORD(radians.x));
    else
      BoneID = -1;
    if ( v46->mPose.mRigHandle.mData )
      v47 = Skeleton::GetBoneID(v46->mPose.mRigHandle.mUFGSkeleton, LODWORD(radians.y));
    Creature::AddRelativeTransform(v46, v47, v16, BoneID, &relativeTransform);
    if ( v35 )
    {
      v49 = v35->y;
      radians.x = v35->z;
      v50 = v35->x;
      radians.y = v49;
      radians.z = v50;
      Creature::AddRelativeScale(v46, v47, v16, BoneID, &radians);
    }
  }
}

// File Line: 1865
// RVA: 0x53AC30
char __fastcall UFG::SimObjectUtility::IsInWater(UFG::SimObject *pSimObject)
{
  signed __int16 m_Flags; // cx
  UFG::SimObject *mNext; // rdi
  UFG::CharacterPhysicsComponent *ComponentOfType; // rax
  unsigned int v5; // r8d
  unsigned int v6; // r9d
  UFG::SimComponentHolder *v7; // rdx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  signed __int16 v13; // cx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v15; // r8d
  unsigned int v16; // r9d
  UFG::SimComponentHolder *v17; // rdx
  unsigned int v18; // r8d
  unsigned int v19; // r9d
  unsigned int v20; // r8d
  unsigned int v21; // r9d
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx

  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  mNext = 0i64;
  if ( (m_Flags & 0x4000) == 0 )
  {
    if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        vfptr = (unsigned int)pSimObject[1].vfptr;
        size = pSimObject->m_Components.size;
        if ( vfptr < size )
        {
          v7 = &pSimObject->m_Components.p[vfptr];
          while ( (v7->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++vfptr;
            ++v7;
            if ( vfptr >= size )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( (m_Flags & 0x1000) == 0 )
        {
          ComponentOfType = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                                pSimObject,
                                                                UFG::CharacterPhysicsComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)pSimObject[1].vfptr;
        v11 = pSimObject->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = &pSimObject->m_Components.p[v10];
          while ( (v7->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || (UFG::CharacterPhysicsComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v10;
            ++v7;
            if ( v10 >= v11 )
            {
              ComponentOfType = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)pSimObject[1].vfptr;
      v6 = pSimObject->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = &pSimObject->m_Components.p[v5];
        while ( (v7->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || (UFG::CharacterPhysicsComponent::_TypeUID & ~v7->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v5;
          ++v7;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        ComponentOfType = (UFG::CharacterPhysicsComponent *)v7->m_pComponent;
        goto LABEL_27;
      }
    }
LABEL_10:
    ComponentOfType = 0i64;
    goto LABEL_27;
  }
  ComponentOfType = (UFG::CharacterPhysicsComponent *)pSimObject->m_Components.p[27].m_pComponent;
LABEL_27:
  if ( ComponentOfType && UFG::CharacterPhysicsComponent::IsInWater(ComponentOfType) )
    return 1;
  v13 = pSimObject->m_Flags;
  if ( (v13 & 0x4000) != 0 )
  {
    m_pComponent = pSimObject->m_Components.p[44].m_pComponent;
    goto LABEL_55;
  }
  if ( v13 < 0 )
  {
    v15 = (unsigned int)pSimObject[1].vfptr;
    v16 = pSimObject->m_Components.size;
    if ( v15 < v16 )
    {
      v17 = &pSimObject->m_Components.p[v15];
      while ( (v17->m_TypeUID & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v15;
        ++v17;
        if ( v15 >= v16 )
          goto LABEL_38;
      }
LABEL_39:
      m_pComponent = v17->m_pComponent;
      goto LABEL_55;
    }
    goto LABEL_38;
  }
  if ( (v13 & 0x2000) != 0 )
  {
    v18 = (unsigned int)pSimObject[1].vfptr;
    v19 = pSimObject->m_Components.size;
    if ( v18 < v19 )
    {
      v17 = &pSimObject->m_Components.p[v18];
      while ( (v17->m_TypeUID & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v18;
        ++v17;
        if ( v18 >= v19 )
        {
          m_pComponent = 0i64;
          goto LABEL_55;
        }
      }
      goto LABEL_39;
    }
LABEL_38:
    m_pComponent = 0i64;
    goto LABEL_55;
  }
  if ( (v13 & 0x1000) != 0 )
  {
    v20 = (unsigned int)pSimObject[1].vfptr;
    v21 = pSimObject->m_Components.size;
    if ( v20 < v21 )
    {
      v17 = &pSimObject->m_Components.p[v20];
      while ( (v17->m_TypeUID & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterOccupantComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v20;
        ++v17;
        if ( v20 >= v21 )
        {
          m_pComponent = 0i64;
          goto LABEL_55;
        }
      }
      goto LABEL_39;
    }
    goto LABEL_38;
  }
  m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_55:
  if ( !m_pComponent )
    return 0;
  mPrev = m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
  if ( mPrev )
    mNext = (UFG::SimObject *)mPrev[2].mNext;
  return UFG::SimObjectUtility::IsBoatInWater(mNext);
}

// File Line: 1887
// RVA: 0x5397C0
char __fastcall UFG::SimObjectUtility::IsBoat(UFG::SimObject *vehicle)
{
  signed __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v5; // rdx
  UFG::PhysicsBoat *mPhysicsVehicle; // rcx

  if ( !vehicle )
    return 0;
  m_Flags = vehicle->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)vehicle[1].vfptr;
      size = vehicle->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_12:
        m_pComponent = 0i64;
      }
      else
      {
        v5 = &vehicle->m_Components.p[vfptr];
        while ( (v5->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || (UFG::PhysicsMoverInterface::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v5;
          if ( vfptr >= size )
            goto LABEL_12;
        }
        m_pComponent = (UFG::PhysicsMoverInterface *)v5->m_pComponent;
      }
    }
    else
    {
      m_pComponent = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                     vehicle,
                                                     UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    m_pComponent = (UFG::PhysicsMoverInterface *)vehicle->m_Components.p[34].m_pComponent;
  }
  if ( m_pComponent )
  {
    mPhysicsVehicle = (UFG::PhysicsBoat *)m_pComponent->mPhysicsVehicle;
    if ( mPhysicsVehicle )
    {
      if ( (*((_BYTE *)&mPhysicsVehicle->UFG::PhysicsVehicle + 604) & 7) == 0 )
        return 1;
    }
  }
  return 0;
}

// File Line: 1903
// RVA: 0x5398B0
char __fastcall UFG::SimObjectUtility::IsBoatInWater(UFG::SimObject *pVehicle)
{
  signed __int16 m_Flags; // dx
  signed int v2; // ebx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdi
  float v8; // xmm6_4
  float FloatBuoyancy; // xmm0_4

  if ( !pVehicle )
    return 0;
  m_Flags = pVehicle->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return 0;
  v2 = 0;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
      return 0;
    if ( (m_Flags & 0x1000) != 0 )
    {
      vfptr = (unsigned int)pVehicle[1].vfptr;
      size = pVehicle->m_Components.size;
      if ( vfptr >= size )
      {
LABEL_12:
        m_pComponent = 0i64;
      }
      else
      {
        v6 = &pVehicle->m_Components.p[vfptr];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || (UFG::PhysicsMoverInterface::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++vfptr;
          ++v6;
          if ( vfptr >= size )
            goto LABEL_12;
        }
        m_pComponent = v6->m_pComponent;
      }
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(pVehicle, UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    m_pComponent = pVehicle->m_Components.p[34].m_pComponent;
  }
  if ( m_pComponent )
  {
    mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
    if ( mPrev )
    {
      if ( (BYTE4(mPrev[37].mNext) & 7) == 0 )
      {
        v8 = 0.0;
        do
        {
          FloatBuoyancy = UFG::PhysicsBoat::GetFloatBuoyancy((UFG::PhysicsBoat *)mPrev, v2++);
          v8 = v8 + FloatBuoyancy;
        }
        while ( v2 < 4 );
        if ( v8 > 0.001 )
          return 1;
      }
    }
  }
  return 0;
}

// File Line: 1939
// RVA: 0x53B780
char __fastcall UFG::SimObjectUtility::IsPlayerVehicle(UFG::SimObject *pSimObject)
{
  signed __int16 m_Flags; // dx
  unsigned int vfptr; // r8d
  unsigned int size; // r9d
  UFG::SimComponentHolder *v4; // rdx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int v6; // r8d
  unsigned int v7; // r9d
  unsigned int v8; // r8d
  unsigned int v9; // r9d
  UFG::SimObjectCharacter *Texture; // rbx

  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v4 = &pSimObject->m_Components.p[vfptr];
      while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || (UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v4;
        if ( vfptr >= size )
          goto LABEL_8;
      }
LABEL_9:
      m_pComponent = v4->m_pComponent;
      goto LABEL_27;
    }
  }
  else
  {
    if ( m_Flags < 0 )
    {
      m_pComponent = pSimObject->m_Components.p[30].m_pComponent;
      goto LABEL_27;
    }
    if ( (m_Flags & 0x2000) != 0 )
    {
      v6 = (unsigned int)pSimObject[1].vfptr;
      v7 = pSimObject->m_Components.size;
      if ( v6 < v7 )
      {
        v4 = &pSimObject->m_Components.p[v6];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v6;
          ++v4;
          if ( v6 >= v7 )
          {
            m_pComponent = 0i64;
            goto LABEL_27;
          }
        }
        goto LABEL_9;
      }
    }
    else
    {
      if ( (m_Flags & 0x1000) == 0 )
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_27;
      }
      v8 = (unsigned int)pSimObject[1].vfptr;
      v9 = pSimObject->m_Components.size;
      if ( v8 < v9 )
      {
        v4 = &pSimObject->m_Components.p[v8];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || (UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v8;
          ++v4;
          if ( v8 >= v9 )
          {
            m_pComponent = 0i64;
            goto LABEL_27;
          }
        }
        goto LABEL_9;
      }
    }
  }
LABEL_8:
  m_pComponent = 0i64;
LABEL_27:
  if ( m_pComponent )
  {
    Texture = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)m_pComponent);
    if ( Texture == UFG::GetLocalPlayer() )
      return 1;
  }
  return 0;
}

// File Line: 1945
// RVA: 0x539A60
bool __fastcall UFG::SimObjectUtility::IsCharacterInVehicle(UFG::SimObject *pSimObject)
{
  return pSimObject && UFG::SimObject::GetComponentOfType(pSimObject, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 1959
// RVA: 0x52EB50
char __fastcall UFG::SimObjectUtility::GetObjectCapsuleApproximation(
        UFG::SimObject *pSimObject,
        UFG::qMatrix44 **pXform,
        UFG::qVector3 *vSegA,
        UFG::qVector3 *vSegB,
        float *fRadius)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::qMatrix44 *p_mWorldTransform; // rdi
  signed __int16 m_Flags; // cx
  UFG::CharacterPhysicsComponent *m_pComponent; // rdi
  unsigned int vfptr; // r8d
  unsigned int size; // r10d
  UFG::SimComponentHolder *v15; // rdx
  unsigned int v16; // r8d
  unsigned int v17; // r10d
  unsigned int v18; // r8d
  unsigned int v19; // r10d
  float Height; // xmm6_4
  float Radius; // xmm0_4
  float *v22; // rcx
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  signed __int16 v30; // cx
  UFG::PhysicsMoverInterface *ComponentOfType; // rax
  unsigned int v32; // r8d
  unsigned int v33; // r10d
  UFG::SimComponentHolder *v34; // rdx
  signed __int16 v35; // cx
  unsigned int v36; // r8d
  unsigned int v37; // r10d
  UFG::SimComponentHolder *v38; // rdx
  UFG::RigidBody *v39; // rax
  unsigned int v40; // r8d
  unsigned int v41; // r10d
  unsigned int v42; // r8d
  unsigned int v43; // r10d
  unsigned int v44; // r8d
  unsigned int v45; // r10d
  float v46; // xmm2_4
  __m128 x_low; // xmm3
  __m128 y_low; // xmm1
  float x; // xmm5_4
  float v50; // xmm6_4
  float v51; // xmm7_4
  float v52; // xmm0_4
  float v53; // xmm8_4
  float v54; // xmm9_4
  float v55; // xmm10_4
  float v56; // xmm2_4
  float v57; // xmm8_4
  float v58; // xmm9_4
  float v59; // xmm10_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm5_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float v66; // ecx
  float y; // xmm1_4
  float z; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm1_4
  UFG::qVector3 min; // [rsp+20h] [rbp-78h] BYREF
  UFG::qVector3 max; // [rsp+30h] [rbp-68h] BYREF

  if ( !*pXform )
  {
    if ( pSimObject && (m_pTransformNodeComponent = pSimObject->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
      p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
    }
    else
    {
      p_mWorldTransform = 0i64;
    }
    *pXform = p_mWorldTransform;
  }
  if ( !*pXform )
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    vSegA->x = UFG::qVector3::msZero.x;
    vSegA->y = y;
    vSegA->z = z;
    v69 = UFG::qVector3::msZero.y;
    v70 = UFG::qVector3::msZero.z;
    vSegB->x = UFG::qVector3::msZero.x;
    vSegB->y = v69;
    vSegB->z = v70;
    *fRadius = 0.0;
    return 0;
  }
  if ( !pSimObject )
    goto LABEL_94;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterPhysicsComponent *)pSimObject->m_Components.p[27].m_pComponent;
    goto LABEL_34;
  }
  if ( m_Flags < 0 )
  {
    vfptr = (unsigned int)pSimObject[1].vfptr;
    size = pSimObject->m_Components.size;
    if ( vfptr < size )
    {
      v15 = &pSimObject->m_Components.p[vfptr];
      while ( (v15->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++vfptr;
        ++v15;
        if ( vfptr >= size )
          goto LABEL_17;
      }
LABEL_18:
      m_pComponent = (UFG::CharacterPhysicsComponent *)v15->m_pComponent;
      goto LABEL_34;
    }
    goto LABEL_17;
  }
  if ( (m_Flags & 0x2000) != 0 )
  {
    v16 = (unsigned int)pSimObject[1].vfptr;
    v17 = pSimObject->m_Components.size;
    if ( v16 < v17 )
    {
      v15 = &pSimObject->m_Components.p[v16];
      while ( (v15->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v16;
        ++v15;
        if ( v16 >= v17 )
        {
          m_pComponent = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_18;
    }
LABEL_17:
    m_pComponent = 0i64;
    goto LABEL_34;
  }
  if ( (m_Flags & 0x1000) != 0 )
  {
    v18 = (unsigned int)pSimObject[1].vfptr;
    v19 = pSimObject->m_Components.size;
    if ( v18 < v19 )
    {
      v15 = &pSimObject->m_Components.p[v18];
      while ( (v15->m_TypeUID & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || (UFG::CharacterPhysicsComponent::_TypeUID & ~v15->m_TypeUID & 0x1FFFFFF) != 0 )
      {
        ++v18;
        ++v15;
        if ( v18 >= v19 )
        {
          m_pComponent = 0i64;
          goto LABEL_34;
        }
      }
      goto LABEL_18;
    }
    goto LABEL_17;
  }
  m_pComponent = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                     pSimObject,
                                                     UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_34:
  if ( !m_pComponent )
  {
    v30 = pSimObject->m_Flags;
    if ( (v30 & 0x4000) != 0 )
      goto LABEL_51;
    if ( v30 >= 0 )
    {
      if ( (v30 & 0x2000) != 0 )
        goto LABEL_51;
      if ( (v30 & 0x1000) != 0 )
      {
        v32 = (unsigned int)pSimObject[1].vfptr;
        v33 = pSimObject->m_Components.size;
        if ( v32 >= v33 )
        {
LABEL_46:
          ComponentOfType = 0i64;
        }
        else
        {
          v34 = &pSimObject->m_Components.p[v32];
          while ( (v34->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
               || (UFG::PhysicsMoverInterface::_TypeUID & ~v34->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v32;
            ++v34;
            if ( v32 >= v33 )
              goto LABEL_46;
          }
          ComponentOfType = (UFG::PhysicsMoverInterface *)v34->m_pComponent;
        }
      }
      else
      {
        ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                          pSimObject,
                                                          UFG::PhysicsMoverInterface::_TypeUID);
      }
    }
    else
    {
      ComponentOfType = (UFG::PhysicsMoverInterface *)pSimObject->m_Components.p[34].m_pComponent;
    }
    if ( ComponentOfType )
    {
      UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(ComponentOfType, &min, &max);
LABEL_83:
      x_low = (__m128)LODWORD(max.x);
      y_low = (__m128)LODWORD(max.y);
      v46 = (float)(max.z - min.z) * 0.5;
      x_low.m128_f32[0] = (float)(max.x - min.x) * 0.5;
      y_low.m128_f32[0] = (float)(max.y - min.y) * 0.5;
      if ( v46 <= x_low.m128_f32[0] || v46 <= y_low.m128_f32[0] )
      {
        if ( y_low.m128_f32[0] > x_low.m128_f32[0] && y_low.m128_f32[0] > v46 )
        {
          x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v46 * v46);
          v46 = (float)(max.y - min.y) * 0.5;
          x = (*pXform)->v1.x;
          v50 = (*pXform)->v1.y;
          v51 = (*pXform)->v1.z;
          LODWORD(v52) = _mm_sqrt_ps(x_low).m128_u32[0];
LABEL_91:
          v53 = (float)(max.x + min.x) * 0.5;
          v54 = (float)(max.y + min.y) * 0.5;
          v55 = (float)(max.z + min.z) * 0.5;
          *fRadius = v52;
          v56 = v46 - v52;
          v57 = v53 + (*pXform)->v3.x;
          v58 = v54 + (*pXform)->v3.y;
          v59 = v55 + (*pXform)->v3.z;
          v60 = v51 * v56;
          v61 = v50 * v56;
          v62 = x * v56;
          vSegA->x = v62 + v57;
          vSegA->y = v61 + v58;
          vSegA->z = v60 + v59;
          vSegB->x = v57 - v62;
          vSegB->y = v58 - v61;
          vSegB->z = v59 - v60;
          return 1;
        }
        y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v46 * v46);
        v46 = (float)(max.x - min.x) * 0.5;
        x = (*pXform)->v0.x;
        v50 = (*pXform)->v0.y;
        v51 = (*pXform)->v0.z;
      }
      else
      {
        y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                          + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]);
        x = (*pXform)->v2.x;
        v50 = (*pXform)->v2.y;
        v51 = (*pXform)->v2.z;
      }
      LODWORD(v52) = _mm_sqrt_ps(y_low).m128_u32[0];
      goto LABEL_91;
    }
LABEL_51:
    v35 = pSimObject->m_Flags;
    if ( (v35 & 0x4000) != 0 )
    {
      v36 = (unsigned int)pSimObject[1].vfptr;
      v37 = pSimObject->m_Components.size;
      if ( v36 < v37 )
      {
        v38 = &pSimObject->m_Components.p[v36];
        while ( (v38->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
             || (UFG::RigidBodyComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v36;
          ++v38;
          if ( v36 >= v37 )
            goto LABEL_57;
        }
LABEL_58:
        v39 = (UFG::RigidBody *)v38->m_pComponent;
        goto LABEL_81;
      }
    }
    else if ( v35 >= 0 )
    {
      if ( (v35 & 0x2000) != 0 )
      {
        v42 = (unsigned int)pSimObject[1].vfptr;
        v43 = pSimObject->m_Components.size;
        if ( v42 < v43 )
        {
          v38 = &pSimObject->m_Components.p[v42];
          while ( (v38->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
               || (UFG::RigidBodyComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v42;
            ++v38;
            if ( v42 >= v43 )
            {
              v39 = 0i64;
              goto LABEL_81;
            }
          }
          goto LABEL_58;
        }
      }
      else
      {
        if ( (v35 & 0x1000) == 0 )
        {
          v39 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(pSimObject, UFG::RigidBodyComponent::_TypeUID);
LABEL_81:
          if ( v39 )
          {
            UFG::RigidBody::GetAabb(v39, &min, &max, WORLD_AABB);
            goto LABEL_83;
          }
LABEL_94:
          v64 = (*pXform)->v3.y;
          v65 = (*pXform)->v3.z;
          v66 = (*pXform)->v3.x;
          vSegA->x = v66;
          vSegA->y = v64;
          vSegA->z = v65;
          vSegB->y = v64;
          vSegB->x = v66;
          vSegB->z = v65;
          *fRadius = 0.0;
          return 0;
        }
        v44 = (unsigned int)pSimObject[1].vfptr;
        v45 = pSimObject->m_Components.size;
        if ( v44 < v45 )
        {
          v38 = &pSimObject->m_Components.p[v44];
          while ( (v38->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
               || (UFG::RigidBodyComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) != 0 )
          {
            ++v44;
            ++v38;
            if ( v44 >= v45 )
            {
              v39 = 0i64;
              goto LABEL_81;
            }
          }
          goto LABEL_58;
        }
      }
    }
    else
    {
      v40 = (unsigned int)pSimObject[1].vfptr;
      v41 = pSimObject->m_Components.size;
      if ( v40 < v41 )
      {
        v38 = &pSimObject->m_Components.p[v40];
        while ( (v38->m_TypeUID & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
             || (UFG::RigidBodyComponent::_TypeUID & ~v38->m_TypeUID & 0x1FFFFFF) != 0 )
        {
          ++v40;
          ++v38;
          if ( v40 >= v41 )
          {
            v39 = 0i64;
            goto LABEL_81;
          }
        }
        goto LABEL_58;
      }
    }
LABEL_57:
    v39 = 0i64;
    goto LABEL_81;
  }
  Height = UFG::CharacterPhysicsComponent::GetHeight(m_pComponent, m_pComponent->mCollisionModelType);
  Radius = UFG::CharacterPhysicsComponent::GetRadius(m_pComponent);
  v22 = (float *)*pXform;
  *fRadius = Radius;
  v23 = (float)(Radius * v22[8]) + v22[12];
  v24 = (float)(Radius * v22[9]) + v22[13];
  v25 = (float)(Radius * v22[10]) + v22[14];
  v26 = Height - (float)(Radius * 2.0);
  vSegA->x = v23;
  vSegA->y = v24;
  vSegA->z = v25;
  v27 = (float)(v26 * v22[8]) + v23;
  v28 = (float)(v26 * v22[9]) + v24;
  v29 = (float)(v26 * v22[10]) + v25;
  vSegB->x = v27;
  vSegB->y = v28;
  vSegB->z = v29;
  return 1;
}oat)(Radius * v22[8]) + v22[12];
  v24 = (float)(Radius * v22[9]) + v22[13];


// File Line: 2061
// RVA: 0x534640
char __fastcall UFG::SimObjectUtility::HandleSimObjectLeavingWorld(UFG::SimObjectCharacter *pSimObject)
{
  UFG::GameStatTracker *v2; // rbx
  UFG::qVector4 v3; // xmm3
  UFG::allocator::free_link *v4; // rax
  signed __int16 m_Flags; // cx
  UFG::TSActorComponent *m_pComponent; // rax
  UFG::TSCharacter *Actor; // rax
  UFG::qMatrix44 worldXform; // [rsp+40h] [rbp-68h] BYREF

  if ( !UFG::IsAnyLocalPlayer(pSimObject) )
    return 0;
  v2 = UFG::GameStatTracker::Instance();
  v3 = 0i64;
  v3.x = (float)1;
  worldXform.v0 = v3;
  worldXform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 81);
  worldXform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v3, (__m128)v3, 69);
  worldXform.v3.x = UFG::GameStatTracker::GetStat(v2, PlayerLastStableLocationX);
  worldXform.v3.y = UFG::GameStatTracker::GetStat(v2, PlayerLastStableLocationY);
  worldXform.v3.z = UFG::GameStatTracker::GetStat(v2, PlayerLastStableLocationZ);
  LODWORD(worldXform.v3.w) = (_DWORD)FLOAT_1_0;
  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v4,
      &worldXform,
      pSimObject->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[3].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[2].m_pComponent;
      }
      else
      {
        m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                  pSimObject,
                                                  UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent;
    }
    if ( m_pComponent )
    {
      Actor = (UFG::TSCharacter *)UFG::TSActorComponent::GetActor(m_pComponent);
      ((void (__fastcall *)(UFG::TSCharacter *))Actor->vfptr[2].get_data_by_name)(Actor);
    }
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  UFG::UIHK_NISOverlay::HideCurtains(5.0, 0);
  return 1;
}

