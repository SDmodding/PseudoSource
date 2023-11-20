// File Line: 110
// RVA: 0x54A260
void __fastcall UFG::SimObjectUtility::ResetSimObject(UFG::SimObject *pSimObjectResetting, UFG::SimObject *pSimObjectToReset, bool bKeepItems)
{
  bool v3; // r12
  UFG::SimObject *v4; // r13
  UFG::SimObject *v5; // rsi
  const char *v6; // rbx
  char *v7; // rdi
  char *v8; // rax
  unsigned __int16 v9; // cx
  UFG::WorldContextComponent *v10; // rdi
  UFG::SimComponent *v11; // rbp
  unsigned int v12; // er8
  unsigned int v13; // er9
  signed __int64 v14; // rdx
  unsigned int v15; // er8
  unsigned int v16; // er9
  unsigned __int16 v17; // dx
  UFG::CharacterAnimationComponent *v18; // rdx
  UFG::CharacterAnimationComponent *v19; // rax
  unsigned int v20; // er8
  unsigned int v21; // er9
  signed __int64 v22; // rdx
  Creature *v23; // r14
  signed __int64 v24; // r10
  __int64 v25; // r9
  unsigned __int8 *v26; // rcx
  __int64 v27; // r8
  __int64 v28; // rbx
  unsigned __int16 v29; // cx
  unsigned int v30; // er8
  unsigned int v31; // er10
  signed __int64 v32; // rdx
  unsigned int v33; // er8
  unsigned int v34; // er10
  unsigned int v35; // er8
  unsigned int v36; // er10

  v3 = bKeepItems;
  v4 = pSimObjectToReset;
  v5 = pSimObjectResetting;
  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    if ( v3 )
      v6 = "True";
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->m_Name);
    UFG::qPrintf("ResetSimObject: '%s'(0x%x) Resetting '%s'(0x%x), Keep Items: '%s'\n", v8, v5, v7, v4, v6);
  }
  if ( v5 )
  {
    v9 = v5->m_Flags;
    v10 = 0i64;
    if ( (v9 >> 14) & 1 )
    {
      v11 = v5->m_Components.p[20].m_pComponent;
      goto LABEL_26;
    }
    if ( (v9 & 0x8000u) != 0 )
    {
      v11 = v5->m_Components.p[20].m_pComponent;
      goto LABEL_26;
    }
    if ( (v9 >> 13) & 1 )
    {
      v12 = (unsigned int)v5[1].vfptr;
      v13 = v5->m_Components.size;
      if ( v12 < v13 )
      {
        v14 = (signed __int64)&v5->m_Components.p[v12];
        while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
        {
          ++v12;
          v14 += 16i64;
          if ( v12 >= v13 )
            goto LABEL_16;
        }
LABEL_17:
        v11 = *(UFG::SimComponent **)v14;
        goto LABEL_26;
      }
    }
    else
    {
      if ( !((v9 >> 12) & 1) )
      {
        v11 = UFG::SimObject::GetComponentOfType(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_26:
        v17 = v5->m_Flags;
        if ( (v17 >> 14) & 1 )
        {
          v18 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
LABEL_28:
          if ( v18
            && !((UFG::CharacterAnimationComponent::_TypeUID ^ v18->m_TypeUID) & 0xFE000000)
            && !(UFG::CharacterAnimationComponent::_TypeUID & ~v18->m_TypeUID & 0x1FFFFFF) )
          {
            goto LABEL_46;
          }
          goto LABEL_31;
        }
        if ( (v17 & 0x8000u) != 0 )
        {
          v18 = (UFG::CharacterAnimationComponent *)v5->m_Components.p[9].m_pComponent;
          goto LABEL_28;
        }
        if ( (v17 >> 13) & 1 )
        {
          v19 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
        }
        else
        {
          if ( (v17 >> 12) & 1 )
          {
            v20 = (unsigned int)v5[1].vfptr;
            v21 = v5->m_Components.size;
            if ( v20 >= v21 )
            {
LABEL_31:
              v18 = 0i64;
              goto LABEL_46;
            }
            v22 = (signed __int64)&v5->m_Components.p[v20];
            while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
                 || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
            {
              ++v20;
              v22 += 16i64;
              if ( v20 >= v21 )
              {
                v18 = 0i64;
                goto LABEL_46;
              }
            }
            v18 = *(UFG::CharacterAnimationComponent **)v22;
LABEL_46:
            if ( v18 )
              v23 = v18->mCreature;
            else
              v23 = 0i64;
            if ( v23 )
            {
              v24 = (signed __int64)&v23->mAttachments.mNode.mNext[-1].mNext;
              if ( v23->mAttachments.mNode.mNext != (UFG::qNode<Attachment,Attachment> *)8 )
              {
                do
                {
                  if ( (Creature *)v24 == (Creature *)&v23->mGroundNormal.z )
                    break;
                  if ( v11
                    && v3
                    && (v25 = *(_QWORD *)(v24 + 104)) != 0
                    && (v26 = *(unsigned __int8 **)&v11[1].m_Flags,
                        v27 = *(_QWORD *)&v11[1].m_TypeUID,
                        v25 == *(_QWORD *)(56i64 * v26[25] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[26] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[27] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[28] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[50] + v27 + 40)
                     || v25 == *(_QWORD *)(56i64 * v26[51] + v27 + 40)) )
                  {
                    v24 = *(_QWORD *)(v24 + 16) - 8i64;
                  }
                  else
                  {
                    v28 = *(_QWORD *)(v24 + 16);
                    if ( v5 == v4 || v4 == *(UFG::SimObject **)(v24 + 104) )
                      Creature::RemoveAttachment(v23, v5, *(_DWORD *)(v24 + 32), *(UFG::SimObject **)(v24 + 104));
                    v24 = v28 - 8;
                  }
                }
                while ( v24 );
              }
            }
            v29 = v5->m_Flags;
            if ( (v29 >> 14) & 1 )
            {
              v10 = (UFG::WorldContextComponent *)v5->m_Components.p[28].m_pComponent;
              goto LABEL_87;
            }
            if ( (v29 & 0x8000u) != 0 )
            {
              v30 = (unsigned int)v5[1].vfptr;
              v31 = v5->m_Components.size;
              if ( v30 >= v31 )
                goto LABEL_87;
              v32 = (signed __int64)&v5->m_Components.p[v30];
              while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                   || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
              {
                ++v30;
                v32 += 16i64;
                if ( v30 >= v31 )
                  goto LABEL_87;
              }
              goto LABEL_71;
            }
            if ( (v29 >> 13) & 1 )
            {
              v33 = (unsigned int)v5[1].vfptr;
              v34 = v5->m_Components.size;
              if ( v33 < v34 )
              {
                v32 = (signed __int64)&v5->m_Components.p[v33];
                while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
                {
                  ++v33;
                  v32 += 16i64;
                  if ( v33 >= v34 )
                    goto LABEL_87;
                }
LABEL_71:
                v10 = *(UFG::WorldContextComponent **)v32;
                goto LABEL_87;
              }
            }
            else if ( (v29 >> 12) & 1 )
            {
              v35 = (unsigned int)v5[1].vfptr;
              v36 = v5->m_Components.size;
              if ( v35 < v36 )
              {
                v32 = (signed __int64)&v5->m_Components.p[v35];
                while ( (*(_DWORD *)(v32 + 8) & 0xFE000000) != (UFG::WorldContextComponent::_TypeUID & 0xFE000000)
                     || UFG::WorldContextComponent::_TypeUID & ~*(_DWORD *)(v32 + 8) & 0x1FFFFFF )
                {
                  ++v35;
                  v32 += 16i64;
                  if ( v35 >= v36 )
                    goto LABEL_87;
                }
                goto LABEL_71;
              }
            }
            else
            {
              v10 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                    v5,
                                                    UFG::WorldContextComponent::_TypeUID);
            }
LABEL_87:
            if ( v10 )
              UFG::WorldContextComponent::DetachAll(v10);
            return;
          }
          v19 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      v5,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        v18 = v19;
        goto LABEL_46;
      }
      v15 = (unsigned int)v5[1].vfptr;
      v16 = v5->m_Components.size;
      if ( v15 < v16 )
      {
        v14 = (signed __int64)&v5->m_Components.p[v15];
        while ( (*(_DWORD *)(v14 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
             || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v14 + 8) & 0x1FFFFFF )
        {
          ++v15;
          v14 += 16i64;
          if ( v15 >= v16 )
          {
            v11 = 0i64;
            goto LABEL_26;
          }
        }
        goto LABEL_17;
      }
    }
LABEL_16:
    v11 = 0i64;
    goto LABEL_26;
  }
}

// File Line: 185
// RVA: 0x54A8D0
void __fastcall UFG::SimObjectUtility::ResetState(UFG::SimObject *pSimObjectToReset, bool bKeepItems, bool bDeleteItems)
{
  bool v3; // r12
  bool v4; // r13
  UFG::SimObjectCharacter *v5; // rsi
  const char *v6; // rdi
  const char *v7; // rbx
  char *v8; // rax
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // r9
  unsigned __int16 v12; // cx
  UFG::TargetingSystemBaseComponent *v13; // r15
  signed int v14; // ecx
  __int64 v15; // r14
  UFG::TargetingMap *v16; // rax
  UFG::SimObject *v17; // rbx
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  signed __int64 v20; // rdx
  unsigned __int16 v21; // cx
  UFG::InventoryComponent *v22; // rax
  unsigned int v23; // er8
  unsigned int v24; // er9
  signed __int64 v25; // rdx
  unsigned int v26; // er8
  unsigned int v27; // er9
  unsigned int v28; // er8
  unsigned int v29; // er9
  char v30; // di
  UFG::TargetingSimObject *v31; // rax
  signed __int64 v32; // rcx
  UFG::SimObject *v33; // rbx
  unsigned __int16 v34; // cx
  UFG::InventoryComponent *v35; // rax
  signed __int64 v36; // rdx
  unsigned __int16 v37; // cx
  signed __int64 v38; // rdx
  UFG::PropInteractComponent *v39; // rax
  unsigned __int8 v40; // cl
  signed __int64 v41; // rbx
  UFG::TargetingSimObject *v42; // rax
  unsigned __int16 v43; // cx
  UFG::SimComponent *v44; // rbx
  unsigned int v45; // er8
  unsigned int v46; // er9
  unsigned int v47; // er8
  unsigned int v48; // er9
  unsigned int v49; // er8
  unsigned int v50; // er9
  float v51; // xmm0_4
  unsigned __int16 v52; // cx
  UFG::SimComponent *v53; // rbx
  unsigned int v54; // er8
  signed __int64 v55; // rbx
  unsigned int v56; // er8
  unsigned int v57; // er8
  UFG::qPropertySet *v58; // rax
  UFG::qPropertySet *v59; // rax
  signed int v60; // eax
  unsigned __int16 v61; // cx
  UFG::CompositeDrawableComponent *v62; // rax
  unsigned int v63; // er8
  unsigned int v64; // er9
  unsigned __int16 v65; // cx
  UFG::SimComponent *v66; // rcx
  unsigned int v67; // er8
  unsigned int v68; // er10
  Creature *v69; // rcx
  unsigned __int16 v70; // cx
  UFG::SimComponent *v71; // rax
  unsigned int v72; // er8
  unsigned int v73; // er10
  signed __int64 v74; // rdx
  unsigned __int16 v75; // cx
  UFG::SimComponent *v76; // rbx
  unsigned int v77; // er8
  unsigned int v78; // er10
  signed __int64 v79; // rdx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v80; // rcx
  void *(__fastcall *v81)(UFG::qSafePointerNode<UFG::SimComponent> *, unsigned int); // rcx
  ActionNodeRoot *v82; // rax
  unsigned __int16 v83; // cx
  UFG::ActorAudioComponent *v84; // rcx
  unsigned int v85; // er8
  unsigned int v86; // er10
  signed __int64 v87; // rdx
  unsigned int v88; // er8
  unsigned int v89; // er10
  unsigned int v90; // er8
  unsigned int v91; // er10
  unsigned __int16 v92; // cx
  UFG::PowerManagementComponent *v93; // rax
  __int64 v94; // [rsp+20h] [rbp-58h]

  v3 = bDeleteItems;
  v4 = bKeepItems;
  v5 = (UFG::SimObjectCharacter *)pSimObjectToReset;
  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    v7 = "False";
    if ( bDeleteItems )
      v7 = "True";
    if ( bKeepItems )
      v6 = "True";
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    UFG::qPrintf("ResetState: '%s'(0x%x), Keep Items: '%s' Delete Items: '%s'\n", v8, v5, v6, v7);
  }
  UFG::VehicleUtility::ExitVehicleNow((UFG::SimObject *)&v5->vfptr, 0, 1, 1);
  UFG::IsAnyLocalPlayer((UFG::SimObject *)&v5->vfptr);
  if ( !v5 )
    goto LABEL_247;
  v12 = v5->m_Flags;
  if ( (v12 >> 14) & 1 )
  {
    v13 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    goto LABEL_28;
  }
  if ( (v12 & 0x8000u) != 0 )
  {
    v13 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    goto LABEL_28;
  }
  if ( (v12 >> 13) & 1 )
  {
    v10 = v5->mComponentTableEntryCount;
    v11 = v5->m_Components.size;
    v9 = (unsigned int)v10;
    if ( (unsigned int)v10 < (unsigned int)v11 )
    {
      v9 = (__int64)&v5->m_Components.p[(unsigned int)v10];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        v10 = (unsigned int)(v10 + 1);
        v9 += 16i64;
        if ( (unsigned int)v10 >= (unsigned int)v11 )
          goto LABEL_18;
      }
LABEL_19:
      v13 = *(UFG::TargetingSystemBaseComponent **)v9;
      goto LABEL_28;
    }
    goto LABEL_18;
  }
  if ( (v12 >> 12) & 1 )
  {
    v10 = v5->mComponentTableEntryCount;
    v11 = v5->m_Components.size;
    v9 = (unsigned int)v10;
    if ( (unsigned int)v10 < (unsigned int)v11 )
    {
      v9 = (__int64)&v5->m_Components.p[(unsigned int)v10];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::TargetingSystemBaseComponent::_TypeUID & 0xFE000000)
           || UFG::TargetingSystemBaseComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        v10 = (unsigned int)(v10 + 1);
        v9 += 16i64;
        if ( (unsigned int)v10 >= (unsigned int)v11 )
        {
          v13 = 0i64;
          goto LABEL_28;
        }
      }
      goto LABEL_19;
    }
LABEL_18:
    v13 = 0i64;
    goto LABEL_28;
  }
  v13 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v5->vfptr,
                                               UFG::TargetingSystemBaseComponent::_TypeUID);
LABEL_28:
  if ( v13 )
  {
    v14 = -2147483638;
    v15 = 0i64;
    v9 = 13194140975104i64;
    do
    {
      v16 = v13->m_pTargetingMap;
      if ( v16->m_Map.p[v15] && ((unsigned int)v15 > 0x1F || !_bittest(&v14, v15)) )
      {
        if ( (_DWORD)v15 == 19 )
        {
          v17 = v13->m_pTargets[(unsigned __int8)v16->m_Map.p[19]].m_pTarget.m_pPointer;
          if ( v17 )
          {
            v18 = v17->m_Flags;
            if ( !((v18 >> 14) & 1) && (v18 & 0x8000u) == 0 )
            {
              if ( (v18 >> 13) & 1 )
              {
                v19 = v17->m_Components.p[11].m_pComponent;
              }
              else if ( (v18 >> 12) & 1 )
              {
                v10 = LODWORD(v17[1].vfptr);
                v11 = v17->m_Components.size;
                if ( (unsigned int)v10 >= (unsigned int)v11 )
                {
LABEL_45:
                  v19 = 0i64;
                }
                else
                {
                  v20 = (signed __int64)&v17->m_Components.p[(unsigned int)v10];
                  while ( (*(_DWORD *)(v20 + 8) & 0xFE000000) != (UFG::InventoryItemComponent::_TypeUID & 0xFE000000)
                       || UFG::InventoryItemComponent::_TypeUID & ~*(_DWORD *)(v20 + 8) & 0x1FFFFFF )
                  {
                    v10 = (unsigned int)(v10 + 1);
                    v20 += 16i64;
                    if ( (unsigned int)v10 >= (unsigned int)v11 )
                      goto LABEL_45;
                  }
                  v19 = *(UFG::SimComponent **)v20;
                }
              }
              else
              {
                v19 = UFG::SimObject::GetComponentOfType(v17, UFG::InventoryItemComponent::_TypeUID);
              }
              if ( v19 && LODWORD(v19[1].m_pSimObject) == 111 )
              {
                v21 = v5->m_Flags;
                if ( (v21 >> 14) & 1 )
                {
                  v22 = (UFG::InventoryComponent *)v5->m_Components.p[39].m_pComponent;
LABEL_75:
                  if ( v22 )
                  {
                    UFG::InventoryComponent::RemoveObjectFromInventory(v22, v17, (__int64)v13);
                    UFG::TargetingSystemBaseComponent::ClearTarget(v13, eTARGET_TYPE_EQUIPPED_HAT);
                  }
                  UFG::Simulation::DestroySimObject(&UFG::gSim, v17);
                  goto LABEL_144;
                }
                if ( (v21 & 0x8000u) == 0 )
                {
                  if ( (v21 >> 13) & 1 )
                  {
                    v26 = v5->mComponentTableEntryCount;
                    v27 = v5->m_Components.size;
                    if ( v26 < v27 )
                    {
                      v25 = (signed __int64)&v5->m_Components.p[v26];
                      while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                           || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
                      {
                        ++v26;
                        v25 += 16i64;
                        if ( v26 >= v27 )
                        {
                          v22 = 0i64;
                          goto LABEL_75;
                        }
                      }
                      goto LABEL_59;
                    }
                  }
                  else
                  {
                    if ( !((v21 >> 12) & 1) )
                    {
                      v22 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v5->vfptr,
                                                         UFG::InventoryComponent::_TypeUID);
                      goto LABEL_75;
                    }
                    v28 = v5->mComponentTableEntryCount;
                    v29 = v5->m_Components.size;
                    if ( v28 < v29 )
                    {
                      v25 = (signed __int64)&v5->m_Components.p[v28];
                      while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                           || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
                      {
                        ++v28;
                        v25 += 16i64;
                        if ( v28 >= v29 )
                        {
                          v22 = 0i64;
                          goto LABEL_75;
                        }
                      }
                      goto LABEL_59;
                    }
                  }
                }
                else
                {
                  v23 = v5->mComponentTableEntryCount;
                  v24 = v5->m_Components.size;
                  if ( v23 < v24 )
                  {
                    v25 = (signed __int64)&v5->m_Components.p[v23];
                    while ( (*(_DWORD *)(v25 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                         || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v25 + 8) & 0x1FFFFFF )
                    {
                      ++v23;
                      v25 += 16i64;
                      if ( v23 >= v24 )
                        goto LABEL_58;
                    }
LABEL_59:
                    v22 = *(UFG::InventoryComponent **)v25;
                    goto LABEL_75;
                  }
                }
LABEL_58:
                v22 = 0i64;
                goto LABEL_75;
              }
            }
          }
        }
        else if ( (unsigned int)v15 > 0x2B || !_bittest64(&v9, (signed int)v15) )
        {
          v30 = 0;
LABEL_83:
          v31 = v13->m_pTargets;
          v32 = (unsigned __int8)v13->m_pTargetingMap->m_Map.p[v15];
          if ( v31[v32].m_pTarget.m_pPointer && v31[v32].m_bLock )
          {
            v33 = v31[v32].m_pTarget.m_pPointer;
            if ( v33 )
            {
              if ( v5 == LocalPlayer )
                UFG::GameStatAction::Inventory::UnEquip(0);
              v34 = v5->m_Flags;
              if ( (v34 >> 14) & 1 )
              {
                v35 = (UFG::InventoryComponent *)v5->m_Components.p[39].m_pComponent;
                goto LABEL_113;
              }
              if ( (v34 & 0x8000u) == 0 )
              {
                if ( (v34 >> 13) & 1 )
                {
                  v10 = v5->mComponentTableEntryCount;
                  v11 = v5->m_Components.size;
                  if ( (unsigned int)v10 >= (unsigned int)v11 )
                    goto LABEL_96;
                  v36 = (signed __int64)&v5->m_Components.p[(unsigned int)v10];
                  while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF )
                  {
                    v10 = (unsigned int)(v10 + 1);
                    v36 += 16i64;
                    if ( (unsigned int)v10 >= (unsigned int)v11 )
                    {
                      v35 = 0i64;
                      goto LABEL_113;
                    }
                  }
                }
                else
                {
                  if ( !((v34 >> 12) & 1) )
                  {
                    v35 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                       (UFG::SimObject *)&v5->vfptr,
                                                       UFG::InventoryComponent::_TypeUID);
                    goto LABEL_113;
                  }
                  v10 = v5->mComponentTableEntryCount;
                  v11 = v5->m_Components.size;
                  if ( (unsigned int)v10 >= (unsigned int)v11 )
                    goto LABEL_96;
                  v36 = (signed __int64)&v5->m_Components.p[(unsigned int)v10];
                  while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                       || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF )
                  {
                    v10 = (unsigned int)(v10 + 1);
                    v36 += 16i64;
                    if ( (unsigned int)v10 >= (unsigned int)v11 )
                    {
                      v35 = 0i64;
                      goto LABEL_113;
                    }
                  }
                }
LABEL_97:
                v35 = *(UFG::InventoryComponent **)v36;
                goto LABEL_113;
              }
              v10 = v5->mComponentTableEntryCount;
              v11 = v5->m_Components.size;
              if ( (unsigned int)v10 < (unsigned int)v11 )
              {
                v36 = (signed __int64)&v5->m_Components.p[(unsigned int)v10];
                while ( (*(_DWORD *)(v36 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
                     || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v36 + 8) & 0x1FFFFFF )
                {
                  v10 = (unsigned int)(v10 + 1);
                  v36 += 16i64;
                  if ( (unsigned int)v10 >= (unsigned int)v11 )
                    goto LABEL_96;
                }
                goto LABEL_97;
              }
LABEL_96:
              v35 = 0i64;
LABEL_113:
              if ( v35 )
                UFG::InventoryComponent::RemoveObjectFromInventory(v35, v33, (__int64)v13);
              v37 = v33->m_Flags;
              if ( (v37 >> 14) & 1 )
              {
                v10 = LODWORD(v33[1].vfptr);
                v11 = v33->m_Components.size;
                if ( (unsigned int)v10 < (unsigned int)v11 )
                {
                  v38 = (signed __int64)&v33->m_Components.p[(unsigned int)v10];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                       || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                  {
                    v10 = (unsigned int)(v10 + 1);
                    v38 += 16i64;
                    if ( (unsigned int)v10 >= (unsigned int)v11 )
                      goto LABEL_121;
                  }
                  goto LABEL_122;
                }
LABEL_121:
                v39 = 0i64;
              }
              else if ( (v37 & 0x8000u) == 0 )
              {
                if ( (v37 >> 13) & 1 )
                {
                  v39 = (UFG::PropInteractComponent *)v33->m_Components.p[13].m_pComponent;
                }
                else if ( (v37 >> 12) & 1 )
                {
                  v10 = LODWORD(v33[1].vfptr);
                  v11 = v33->m_Components.size;
                  if ( (unsigned int)v10 >= (unsigned int)v11 )
                    goto LABEL_121;
                  v38 = (signed __int64)&v33->m_Components.p[(unsigned int)v10];
                  while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::PropInteractComponent::_TypeUID & 0xFE000000)
                       || UFG::PropInteractComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                  {
                    v10 = (unsigned int)(v10 + 1);
                    v38 += 16i64;
                    if ( (unsigned int)v10 >= (unsigned int)v11 )
                    {
                      v39 = 0i64;
                      goto LABEL_135;
                    }
                  }
LABEL_122:
                  v39 = *(UFG::PropInteractComponent **)v38;
                }
                else
                {
                  v39 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                        v33,
                                                        UFG::PropInteractComponent::_TypeUID);
                }
              }
              else
              {
                v39 = (UFG::PropInteractComponent *)v33->m_Components.p[33].m_pComponent;
              }
LABEL_135:
              if ( v39 )
                UFG::PropInteractComponent::DetachFromObject(v39, (UFG::SimObject *)&v5->vfptr, v10, v11);
              UFG::SimObjectUtility::ResetSimObject(v33, (UFG::SimObject *)&v5->vfptr, 0);
              if ( v30 && v3 )
                UFG::SimObject::Destroy(v33);
            }
            LOBYTE(v11) = 1;
            LODWORD(v94) = 0;
            ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, __int64, const char *, _QWORD, _QWORD))v13->vfptr[14].__vecDelDtor)(
              v13,
              (unsigned int)v15,
              0i64,
              v11,
              v94,
              "SimObjectUtility::ResetState",
              0i64,
              0i64);
          }
          v40 = v13->m_pTargetingMap->m_Map.p[v15];
          if ( v40 )
          {
            v41 = v40;
            UFG::TargetingSimObject::SetTarget(&v13->m_pTargets[v41], 0i64);
            v42 = v13->m_pTargets;
            if ( v42[v41].m_bLock )
              v42[v41].m_bLock = 0;
          }
          goto LABEL_144;
        }
        v30 = 1;
        if ( !v4 )
          goto LABEL_83;
      }
LABEL_144:
      v15 = (unsigned int)(v15 + 1);
      v14 = -2147483638;
      v9 = 13194140975104i64;
    }
    while ( (signed int)v15 < 91 );
  }
  v43 = v5->m_Flags;
  if ( (v43 >> 14) & 1 )
  {
    v44 = v5->m_Components.p[27].m_pComponent;
    goto LABEL_170;
  }
  if ( (v43 & 0x8000u) != 0 )
  {
    v45 = v5->mComponentTableEntryCount;
    v46 = v5->m_Components.size;
    v9 = v45;
    if ( v45 < v46 )
    {
      v9 = (__int64)&v5->m_Components.p[v45];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v45;
        v9 += 16i64;
        if ( v45 >= v46 )
          goto LABEL_153;
      }
LABEL_154:
      v44 = *(UFG::SimComponent **)v9;
      goto LABEL_170;
    }
    goto LABEL_153;
  }
  if ( (v43 >> 13) & 1 )
  {
    v47 = v5->mComponentTableEntryCount;
    v48 = v5->m_Components.size;
    v9 = v47;
    if ( v47 < v48 )
    {
      v9 = (__int64)&v5->m_Components.p[v47];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v47;
        v9 += 16i64;
        if ( v47 >= v48 )
        {
          v44 = 0i64;
          goto LABEL_170;
        }
      }
      goto LABEL_154;
    }
LABEL_153:
    v44 = 0i64;
    goto LABEL_170;
  }
  if ( (v43 >> 12) & 1 )
  {
    v49 = v5->mComponentTableEntryCount;
    v50 = v5->m_Components.size;
    v9 = v49;
    if ( v49 < v50 )
    {
      v9 = (__int64)&v5->m_Components.p[v49];
      while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
      {
        ++v49;
        v9 += 16i64;
        if ( v49 >= v50 )
        {
          v44 = 0i64;
          goto LABEL_170;
        }
      }
      goto LABEL_154;
    }
    goto LABEL_153;
  }
  v44 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_170:
  if ( v44 )
  {
    UFG::CharacterPhysicsComponent::SetCollisionModel((UFG::CharacterPhysicsComponent *)v44, CP_WALK);
    v51 = UFG::BasePhysicsSystem::mParam.gravity;
    v44[9].m_NameUID &= 0xFFFFFFFE;
    *(float *)&v44[9].m_SafePointerList.mNode.mPrev = v51;
  }
  v52 = v5->m_Flags;
  if ( (v52 >> 14) & 1 )
  {
    v53 = v5->m_Components.p[42].m_pComponent;
    goto LABEL_197;
  }
  if ( (v52 & 0x8000u) != 0 )
  {
    v9 = v5->mComponentTableEntryCount;
    v54 = v5->m_Components.size;
    if ( (unsigned int)v9 < v54 )
    {
      v55 = (signed __int64)&v5->m_Components.p[(unsigned int)v9];
      while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF )
      {
        v9 = (unsigned int)(v9 + 1);
        v55 += 16i64;
        if ( (unsigned int)v9 >= v54 )
          goto LABEL_180;
      }
LABEL_181:
      v53 = *(UFG::SimComponent **)v55;
      goto LABEL_197;
    }
    goto LABEL_180;
  }
  if ( (v52 >> 13) & 1 )
  {
    v9 = v5->mComponentTableEntryCount;
    v56 = v5->m_Components.size;
    if ( (unsigned int)v9 < v56 )
    {
      v55 = (signed __int64)&v5->m_Components.p[(unsigned int)v9];
      while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF )
      {
        v9 = (unsigned int)(v9 + 1);
        v55 += 16i64;
        if ( (unsigned int)v9 >= v56 )
        {
          v53 = 0i64;
          goto LABEL_197;
        }
      }
      goto LABEL_181;
    }
LABEL_180:
    v53 = 0i64;
    goto LABEL_197;
  }
  if ( (v52 >> 12) & 1 )
  {
    v9 = v5->mComponentTableEntryCount;
    v57 = v5->m_Components.size;
    if ( (unsigned int)v9 < v57 )
    {
      v55 = (signed __int64)&v5->m_Components.p[(unsigned int)v9];
      while ( (*(_DWORD *)(v55 + 8) & 0xFE000000) != (UFG::RagdollComponent::_TypeUID & 0xFE000000)
           || UFG::RagdollComponent::_TypeUID & ~*(_DWORD *)(v55 + 8) & 0x1FFFFFF )
      {
        v9 = (unsigned int)(v9 + 1);
        v55 += 16i64;
        if ( (unsigned int)v9 >= v57 )
        {
          v53 = 0i64;
          goto LABEL_197;
        }
      }
      goto LABEL_181;
    }
    goto LABEL_180;
  }
  v53 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::RagdollComponent::_TypeUID);
LABEL_197:
  if ( v53 )
  {
    UFG::RagdollComponent::ClearConstraints((UFG::RagdollComponent *)v53);
    v58 = UFG::SceneObjectProperties::GetWritableProperties(v5->m_pSceneObj);
    v59 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v58,
            (UFG::qSymbol *)&component_Ragdoll::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v59 && UFG::qPropertySet::GetMemImagePtr(v59) )
    {
      if ( LODWORD(v53[2].m_SafePointerList.mNode.mPrev) != 5 )
      {
        v60 = (signed int)v53[3].m_pSimObject;
        if ( v60 > 1 )
        {
          do
            --v60;
          while ( v60 > 1 );
          LODWORD(v53[3].m_pSimObject) = v60;
        }
      }
      UFG::RagdollComponent::ResetState((UFG::RagdollComponent *)v53);
    }
    else
    {
      UFG::RagdollComponent::Release((UFG::RagdollComponent *)v53, 1);
    }
  }
  v61 = v5->m_Flags;
  if ( (v61 >> 14) & 1 )
  {
    v62 = (UFG::CompositeDrawableComponent *)v5->m_Components.p[14].m_pComponent;
  }
  else if ( (v61 & 0x8000u) == 0 )
  {
    if ( (v61 >> 13) & 1 )
    {
      v62 = (UFG::CompositeDrawableComponent *)v5->m_Components.p[9].m_pComponent;
    }
    else if ( (v61 >> 12) & 1 )
    {
      v63 = v5->mComponentTableEntryCount;
      v64 = v5->m_Components.size;
      v9 = v63;
      if ( v63 >= v64 )
      {
LABEL_218:
        v62 = 0i64;
      }
      else
      {
        v9 = (__int64)&v5->m_Components.p[v63];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
             || UFG::CompositeDrawableComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v63;
          v9 += 16i64;
          if ( v63 >= v64 )
            goto LABEL_218;
        }
        v62 = *(UFG::CompositeDrawableComponent **)v9;
      }
    }
    else
    {
      v62 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v5->vfptr,
                                                 UFG::CompositeDrawableComponent::_TypeUID);
    }
  }
  else
  {
    v62 = (UFG::CompositeDrawableComponent *)v5->m_Components.p[14].m_pComponent;
  }
  if ( v62 )
    UFG::CompositeDrawableComponent::Reset(v62);
  v65 = v5->m_Flags;
  if ( (v65 >> 14) & 1 )
  {
    v66 = v5->m_Components.p[9].m_pComponent;
LABEL_225:
    if ( !v66 )
      goto LABEL_228;
    v9 = v66->m_TypeUID;
    if ( (UFG::CharacterAnimationComponent::_TypeUID ^ v66->m_TypeUID) & 0xFE000000 )
      goto LABEL_228;
    v9 = UFG::CharacterAnimationComponent::_TypeUID & ~(_DWORD)v9;
    if ( v9 & 0x1FFFFFF )
      goto LABEL_228;
    goto LABEL_245;
  }
  if ( (v65 & 0x8000u) != 0 )
  {
    v66 = v5->m_Components.p[9].m_pComponent;
    if ( !v66 )
      goto LABEL_228;
    v9 = v66->m_TypeUID;
    if ( (UFG::CharacterAnimationComponent::_TypeUID ^ v66->m_TypeUID) & 0xFE000000 )
      goto LABEL_228;
    v9 = UFG::CharacterAnimationComponent::_TypeUID & ~(_DWORD)v9;
    if ( v9 & 0x1FFFFFF )
      v66 = 0i64;
    goto LABEL_245;
  }
  if ( (v65 >> 13) & 1 )
  {
    v66 = v5->m_Components.p[8].m_pComponent;
    goto LABEL_225;
  }
  if ( (v65 >> 12) & 1 )
  {
    v67 = v5->mComponentTableEntryCount;
    v68 = v5->m_Components.size;
    v9 = v67;
    if ( v67 >= v68 )
    {
LABEL_228:
      v66 = 0i64;
      goto LABEL_245;
    }
    v9 = (__int64)&v5->m_Components.p[v67];
    while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
         || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
    {
      ++v67;
      v9 += 16i64;
      if ( v67 >= v68 )
      {
        v66 = 0i64;
        goto LABEL_245;
      }
    }
    v66 = *(UFG::SimComponent **)v9;
  }
  else
  {
    v66 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::CharacterAnimationComponent::_TypeUID);
  }
LABEL_245:
  if ( v66 )
  {
    v69 = *(Creature **)&v66[2].m_TypeUID;
    goto LABEL_248;
  }
LABEL_247:
  v69 = 0i64;
LABEL_248:
  if ( v69 )
    Creature::MakeUpright(v69, 0.0, v9);
  if ( v5 )
  {
    v70 = v5->m_Flags;
    if ( (v70 >> 14) & 1 )
    {
      v71 = v5->m_Components.p[7].m_pComponent;
    }
    else if ( (v70 & 0x8000u) == 0 )
    {
      if ( (v70 >> 13) & 1 )
      {
        v71 = v5->m_Components.p[6].m_pComponent;
      }
      else if ( (v70 >> 12) & 1 )
      {
        v72 = v5->mComponentTableEntryCount;
        v73 = v5->m_Components.size;
        if ( v72 >= v73 )
        {
LABEL_263:
          v71 = 0i64;
        }
        else
        {
          v74 = (signed __int64)&v5->m_Components.p[v72];
          while ( (*(_DWORD *)(v74 + 8) & 0xFE000000) != (UFG::ActionTreeComponent::_TypeUID & 0xFE000000)
               || UFG::ActionTreeComponent::_TypeUID & ~*(_DWORD *)(v74 + 8) & 0x1FFFFFF )
          {
            ++v72;
            v74 += 16i64;
            if ( v72 >= v73 )
              goto LABEL_263;
          }
          v71 = *(UFG::SimComponent **)v74;
        }
      }
      else
      {
        v71 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v71 = v5->m_Components.p[7].m_pComponent;
    }
    if ( v71 )
      ActionController::Stop((ActionController *)&v71[3]);
    v75 = v5->m_Flags;
    if ( (v75 >> 14) & 1 )
    {
      v76 = v5->m_Components.p[31].m_pComponent;
    }
    else
    {
      if ( (v75 & 0x8000u) != 0 || (v75 >> 13) & 1 )
        goto LABEL_286;
      if ( (v75 >> 12) & 1 )
      {
        v77 = v5->mComponentTableEntryCount;
        v78 = v5->m_Components.size;
        if ( v77 >= v78 )
        {
LABEL_278:
          v76 = 0i64;
        }
        else
        {
          v79 = (signed __int64)&v5->m_Components.p[v77];
          while ( (*(_DWORD *)(v79 + 8) & 0xFE000000) != (UFG::FacialActionTreeComponent::_TypeUID & 0xFE000000)
               || UFG::FacialActionTreeComponent::_TypeUID & ~*(_DWORD *)(v79 + 8) & 0x1FFFFFF )
          {
            ++v77;
            v79 += 16i64;
            if ( v77 >= v78 )
              goto LABEL_278;
          }
          v76 = *(UFG::SimComponent **)v79;
        }
      }
      else
      {
        v76 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::FacialActionTreeComponent::_TypeUID);
      }
    }
    if ( v76 )
    {
      if ( !UFG::FacialActionTreeComponent::sDisableFacialAnimation )
      {
        ActionController::Stop((ActionController *)&v76[3].m_SafePointerList);
        v80 = v76[3].vfptr;
        if ( v80 )
        {
          v81 = v80[3].__vecDelDtor;
          if ( v81 )
          {
            v82 = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v81 + 144i64))();
            ActionNodeRoot::Init(v82, (ActionContext *)v76[3].vfptr);
          }
        }
      }
    }
LABEL_286:
    v83 = v5->m_Flags;
    if ( (v83 >> 14) & 1 )
    {
      v84 = (UFG::ActorAudioComponent *)v5->m_Components.p[40].m_pComponent;
      if ( v84
        && !((UFG::ActorAudioComponent::_TypeUID ^ v84->m_TypeUID) & 0xFE000000)
        && !(UFG::ActorAudioComponent::_TypeUID & ~v84->m_TypeUID & 0x1FFFFFF) )
      {
        goto LABEL_314;
      }
      goto LABEL_290;
    }
    if ( (v83 & 0x8000u) == 0 )
    {
      if ( !((v83 >> 13) & 1) )
      {
        if ( !((v83 >> 12) & 1) )
        {
          v84 = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v5->vfptr,
                                              UFG::ActorAudioComponent::_TypeUID);
          goto LABEL_314;
        }
        v90 = v5->mComponentTableEntryCount;
        v91 = v5->m_Components.size;
        if ( v90 >= v91 )
          goto LABEL_290;
        v87 = (signed __int64)&v5->m_Components.p[v90];
        while ( (*(_DWORD *)(v87 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v87 + 8) & 0x1FFFFFF )
        {
          ++v90;
          v87 += 16i64;
          if ( v90 >= v91 )
          {
            v84 = 0i64;
            goto LABEL_314;
          }
        }
LABEL_298:
        v84 = *(UFG::ActorAudioComponent **)v87;
        goto LABEL_314;
      }
      v88 = v5->mComponentTableEntryCount;
      v89 = v5->m_Components.size;
      if ( v88 < v89 )
      {
        v87 = (signed __int64)&v5->m_Components.p[v88];
        while ( (*(_DWORD *)(v87 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v87 + 8) & 0x1FFFFFF )
        {
          ++v88;
          v87 += 16i64;
          if ( v88 >= v89 )
          {
            v84 = 0i64;
            goto LABEL_314;
          }
        }
        goto LABEL_298;
      }
    }
    else
    {
      v85 = v5->mComponentTableEntryCount;
      v86 = v5->m_Components.size;
      if ( v85 < v86 )
      {
        v87 = (signed __int64)&v5->m_Components.p[v85];
        while ( (*(_DWORD *)(v87 + 8) & 0xFE000000) != (UFG::ActorAudioComponent::_TypeUID & 0xFE000000)
             || UFG::ActorAudioComponent::_TypeUID & ~*(_DWORD *)(v87 + 8) & 0x1FFFFFF )
        {
          ++v85;
          v87 += 16i64;
          if ( v85 >= v86 )
          {
            v84 = 0i64;
            goto LABEL_314;
          }
        }
        goto LABEL_298;
      }
    }
LABEL_290:
    v84 = 0i64;
LABEL_314:
    if ( v84 )
      UFG::ActorAudioComponent::Reset(v84);
    v92 = v5->m_Flags;
    if ( (v92 >> 14) & 1 )
    {
      v93 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v5->vfptr,
                                               UFG::PowerManagementComponent::_TypeUID);
    }
    else if ( (v92 & 0x8000u) == 0 )
    {
      if ( (v92 >> 13) & 1 )
      {
        v93 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v92 >> 12) & 1 )
      {
        v93 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v5->vfptr,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
      else
      {
        v93 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v5->vfptr,
                                                 UFG::PowerManagementComponent::_TypeUID);
      }
    }
    else
    {
      v93 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v5->vfptr,
                                               UFG::PowerManagementComponent::_TypeUID);
    }
    if ( v93 )
      UFG::PowerManagementComponent::Reset(v93);
  }
  UFG::SimObjectUtility::ResetSimObject((UFG::SimObject *)&v5->vfptr, (UFG::SimObject *)&v5->vfptr, v4);
}

// File Line: 392
// RVA: 0x563620
void __fastcall UFG::SimObjectUtility::UpgradeModelResolution(UFG::SimObject *pObject)
{
  int v1; // esi
  UFG::SimObject *v2; // rbx
  unsigned __int16 v3; // cx
  UFG::StreamedResourceComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  UFG::PedSpawnManager *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi

  v1 = 0;
  v2 = pObject;
  if ( pObject )
  {
    v3 = pObject->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (unsigned int)v2[1].vfptr;
        v6 = v2->m_Components.size;
        if ( v5 >= v6 )
        {
LABEL_14:
          v4 = 0i64;
        }
        else
        {
          v7 = (signed __int64)&v2->m_Components.p[v5];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v5;
            v7 += 16i64;
            if ( v5 >= v6 )
              goto LABEL_14;
          }
          v4 = *(UFG::StreamedResourceComponent **)v7;
        }
      }
      else
      {
        v4 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                 v2,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    if ( v4 )
      UFG::StreamedResourceComponent::UpgradeResolution(v4);
  }
  v8 = UFG::PedSpawnManager::GetInstance();
  v9 = UFG::PedSpawnManager::FindPedInfoFromSimObject(v8, v2);
  v10 = v9;
  if ( v9 )
    v1 = *(_DWORD *)(&v9[10].m_SimObjIndex + 1);
  UFG::SimObjectUtility::PostRigChangeReset(v2);
  if ( v10 )
    *(_DWORD *)(&v10[10].m_SimObjIndex + 1) = v1;
}

// File Line: 418
// RVA: 0x526650
void __fastcall UFG::SimObjectUtility::DowngradeModelResolution(UFG::SimObject *pObject)
{
  int v1; // esi
  UFG::SimObject *v2; // rbx
  unsigned __int16 v3; // cx
  UFG::StreamedResourceComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  UFG::PedSpawnManager *v8; // rax
  UFG::SimComponent *v9; // rax
  UFG::SimComponent *v10; // rdi

  v1 = 0;
  v2 = pObject;
  if ( pObject )
  {
    v3 = pObject->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[7].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (unsigned int)v2[1].vfptr;
        v6 = v2->m_Components.size;
        if ( v5 >= v6 )
        {
LABEL_14:
          v4 = 0i64;
        }
        else
        {
          v7 = (signed __int64)&v2->m_Components.p[v5];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v5;
            v7 += 16i64;
            if ( v5 >= v6 )
              goto LABEL_14;
          }
          v4 = *(UFG::StreamedResourceComponent **)v7;
        }
      }
      else
      {
        v4 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                 v2,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v4 = (UFG::StreamedResourceComponent *)v2->m_Components.p[10].m_pComponent;
    }
    if ( v4 )
      UFG::StreamedResourceComponent::DowngradeResolution(v4);
  }
  v8 = UFG::PedSpawnManager::GetInstance();
  v9 = UFG::PedSpawnManager::FindPedInfoFromSimObject(v8, v2);
  v10 = v9;
  if ( v9 )
    v1 = *(_DWORD *)(&v9[10].m_SimObjIndex + 1);
  UFG::SimObjectUtility::PostRigChangeReset(v2);
  if ( v10 )
    *(_DWORD *)(&v10[10].m_SimObjIndex + 1) = v1;
}

// File Line: 442
// RVA: 0x542830
void __fastcall UFG::SimObjectUtility::PostRigChangeReset(UFG::SimObject *pObject)
{
  UFG::SimObjectProp *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::CharacterAnimationComponent *v3; // rcx
  unsigned int v4; // edx
  unsigned int v5; // edx
  UFG::CharacterAnimationComponent *v6; // rax
  unsigned int v7; // ecx
  unsigned int v8; // er9
  UFG::SimComponentHolder *v9; // rdi
  CharacterDamageRig *v10; // rdx
  unsigned __int16 v11; // cx
  UFG::CompositeDrawableComponent *v12; // rax
  unsigned int v13; // ecx
  unsigned int v14; // er9
  UFG::SimComponentHolder *v15; // rdi
  unsigned __int16 v16; // cx
  UFG::RagdollComponent *v17; // rax
  unsigned int v18; // ecx
  unsigned int v19; // er9
  UFG::SimComponentHolder *v20; // rdi
  signed __int64 v21; // r8
  unsigned int v22; // ecx
  unsigned int v23; // er9
  unsigned int v24; // ecx
  unsigned int v25; // er9
  unsigned __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  unsigned int v28; // ecx
  unsigned int v29; // er9
  UFG::SimComponentHolder *v30; // rdi
  unsigned __int16 v31; // cx
  UFG::CharacterAnimationComponent *v32; // rcx
  UFG::CharacterAnimationComponent *v33; // rax
  unsigned int v34; // ecx
  unsigned int v35; // er9
  UFG::SimComponentHolder *v36; // rdi
  CharacterDamageRig *v37; // rcx
  CharacterDamageRig source; // [rsp+30h] [rbp-318h]

  v1 = (UFG::SimObjectProp *)pObject;
  CharacterDamageRig::CharacterDamageRig(&source);
  if ( !v1 )
    goto LABEL_27;
  v2 = v1->m_Flags;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) != 0 )
    {
      v3 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
      if ( v3 )
      {
        v5 = v3->m_TypeUID;
        if ( !((v5 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000) )
        {
          if ( UFG::CharacterAnimationComponent::_TypeUID & ~v5 & 0x1FFFFFF )
            v3 = 0i64;
          goto LABEL_24;
        }
      }
      goto LABEL_6;
    }
    if ( (v2 >> 13) & 1 )
    {
      v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v1);
    }
    else
    {
      if ( (v2 >> 12) & 1 )
      {
        v7 = v1->mComponentTableEntryCount;
        v8 = v1->m_Components.size;
        if ( v7 < v8 )
        {
          v9 = v1->m_Components.p;
          while ( (v9[v7].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~v9[v7].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v7 >= v8 )
              goto LABEL_6;
          }
          v3 = (UFG::CharacterAnimationComponent *)v9[v7].m_pComponent;
          goto LABEL_24;
        }
        goto LABEL_6;
      }
      v6 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v1->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
    v3 = v6;
    goto LABEL_24;
  }
  v3 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
  if ( !v3
    || (v4 = v3->m_TypeUID, (v4 ^ UFG::CharacterAnimationComponent::_TypeUID) & 0xFE000000)
    || UFG::CharacterAnimationComponent::_TypeUID & ~v4 & 0x1FFFFFF )
  {
LABEL_6:
    v3 = 0i64;
  }
LABEL_24:
  if ( v3 )
  {
    v10 = v3->mDamageRig;
    if ( v10 )
      CharacterDamageRig::Clone(&source, v10);
  }
LABEL_27:
  UFG::SimObjectUtility::ReinitializeSimObject((UFG::SimObject *)&v1->vfptr, 0, 1);
  if ( !v1 )
    goto LABEL_117;
  v11 = v1->m_Flags;
  if ( (v11 >> 14) & 1 )
  {
    v12 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v12 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[9].m_pComponent;
    }
    else if ( (v11 >> 12) & 1 )
    {
      v13 = v1->mComponentTableEntryCount;
      v14 = v1->m_Components.size;
      if ( v13 >= v14 )
      {
LABEL_42:
        v12 = 0i64;
      }
      else
      {
        v15 = v1->m_Components.p;
        while ( (v15[v13].m_TypeUID & 0xFE000000) != (UFG::CompositeDrawableComponent::_TypeUID & 0xFE000000)
             || UFG::CompositeDrawableComponent::_TypeUID & ~v15[v13].m_TypeUID & 0x1FFFFFF )
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
                                                 (UFG::SimObject *)&v1->vfptr,
                                                 UFG::CompositeDrawableComponent::_TypeUID);
    }
  }
  else
  {
    v12 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
  }
  if ( v12 )
    UFG::CompositeDrawableComponent::ResetModelType(v12);
  v16 = v1->m_Flags;
  if ( (v16 >> 14) & 1 )
  {
    v17 = (UFG::RagdollComponent *)v1->m_Components.p[42].m_pComponent;
    goto LABEL_72;
  }
  if ( (v16 & 0x8000u) != 0 )
  {
    v18 = v1->mComponentTableEntryCount;
    v19 = v1->m_Components.size;
    if ( v18 < v19 )
    {
      v20 = v1->m_Components.p;
      while ( 1 )
      {
        v21 = v18;
        if ( (v20[v18].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && !(UFG::RagdollComponent::_TypeUID & ~v20[v18].m_TypeUID & 0x1FFFFFF) )
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
  if ( (v16 >> 13) & 1 )
  {
    v22 = v1->mComponentTableEntryCount;
    v23 = v1->m_Components.size;
    if ( v22 < v23 )
    {
      v20 = v1->m_Components.p;
      while ( 1 )
      {
        v21 = v22;
        if ( (v20[v22].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && !(UFG::RagdollComponent::_TypeUID & ~v20[v22].m_TypeUID & 0x1FFFFFF) )
        {
          goto LABEL_55;
        }
        if ( ++v22 >= v23 )
          goto LABEL_56;
      }
    }
    goto LABEL_56;
  }
  if ( (v16 >> 12) & 1 )
  {
    v24 = v1->mComponentTableEntryCount;
    v25 = v1->m_Components.size;
    if ( v24 < v25 )
    {
      v20 = v1->m_Components.p;
      do
      {
        v21 = v24;
        if ( (v20[v24].m_TypeUID & 0xFE000000) == (UFG::RagdollComponent::_TypeUID & 0xFE000000)
          && !(UFG::RagdollComponent::_TypeUID & ~v20[v24].m_TypeUID & 0x1FFFFFF) )
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
  v17 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                   (UFG::SimObject *)&v1->vfptr,
                                   UFG::RagdollComponent::_TypeUID);
LABEL_72:
  if ( v17 )
  {
    UFG::RagdollComponent::Release(v17, 1);
    UFG::RagdollComponent::Acquire((UFG::SimObject *)&v1->vfptr);
  }
  v26 = v1->m_Flags;
  if ( (v26 >> 14) & 1 )
  {
    v27 = v1->m_Components.p[9].m_pComponent;
  }
  else if ( (v26 & 0x8000u) == 0 )
  {
    if ( (v26 >> 13) & 1 )
    {
      v27 = v1->m_Components.p[8].m_pComponent;
    }
    else if ( (v26 >> 12) & 1 )
    {
      v28 = v1->mComponentTableEntryCount;
      v29 = v1->m_Components.size;
      if ( v28 >= v29 )
      {
LABEL_88:
        v27 = 0i64;
      }
      else
      {
        v30 = v1->m_Components.p;
        while ( (v30[v28].m_TypeUID & 0xFE000000) != (UFG::BaseAnimationComponent::_TypeUID & 0xFE000000)
             || UFG::BaseAnimationComponent::_TypeUID & ~v30[v28].m_TypeUID & 0x1FFFFFF )
        {
          if ( ++v28 >= v29 )
            goto LABEL_88;
        }
        v27 = v30[v28].m_pComponent;
      }
    }
    else
    {
      v27 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::BaseAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v27 = v1->m_Components.p[9].m_pComponent;
  }
  if ( v27 )
    ((void (__fastcall *)(UFG::SimComponent *))v27->vfptr[17].__vecDelDtor)(v27);
  v31 = v1->m_Flags;
  if ( !((v31 >> 14) & 1) )
  {
    if ( (v31 & 0x8000u) != 0 )
    {
      v32 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
      if ( v32 && !((UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000) )
      {
        if ( UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
          v32 = 0i64;
        goto LABEL_114;
      }
      goto LABEL_96;
    }
    if ( (v31 >> 13) & 1 )
    {
      v33 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v1);
    }
    else
    {
      if ( (v31 >> 12) & 1 )
      {
        v34 = v1->mComponentTableEntryCount;
        v35 = v1->m_Components.size;
        if ( v34 < v35 )
        {
          v36 = v1->m_Components.p;
          while ( (v36[v34].m_TypeUID & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterAnimationComponent::_TypeUID & ~v36[v34].m_TypeUID & 0x1FFFFFF )
          {
            if ( ++v34 >= v35 )
              goto LABEL_96;
          }
          v32 = (UFG::CharacterAnimationComponent *)v36[v34].m_pComponent;
          goto LABEL_114;
        }
        goto LABEL_96;
      }
      v33 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v1->vfptr,
                                                  UFG::CharacterAnimationComponent::_TypeUID);
    }
    v32 = v33;
    goto LABEL_114;
  }
  v32 = (UFG::CharacterAnimationComponent *)v1->m_Components.p[9].m_pComponent;
  if ( !v32
    || (UFG::CharacterAnimationComponent::_TypeUID ^ v32->m_TypeUID) & 0xFE000000
    || UFG::CharacterAnimationComponent::_TypeUID & ~v32->m_TypeUID & 0x1FFFFFF )
  {
LABEL_96:
    v32 = 0i64;
  }
LABEL_114:
  if ( v32 )
  {
    v37 = v32->mDamageRig;
    if ( v37 )
      CharacterDamageRig::Clone(v37, &source);
  }
LABEL_117:
  if ( v1 == (UFG::SimObjectProp *)LocalPlayer )
    UFG::CustomizeBindings::OnResetLocalPlayer((UFG::SimObject *)&v1->vfptr);
  CharacterDamageRig::~CharacterDamageRig(&source);
}

// File Line: 521
// RVA: 0x547560
char __fastcall UFG::SimObjectUtility::ReinitializeSimObject(UFG::SimObject *pSimObjectToReset, bool bDeleteItems, bool bSoft)
{
  bool v3; // bp
  UFG::SimObjectCharacter *v4; // rdi
  bool v5; // r14
  const char *v6; // rbx
  char *v7; // rax
  unsigned __int16 v8; // cx
  UFG::StreamedResourceComponent *v9; // rax
  unsigned int v10; // er8
  unsigned int v11; // er9
  signed __int64 v12; // rdx
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  unsigned int v15; // er8
  unsigned int v16; // er9
  signed __int64 v17; // rdx
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rax
  unsigned int v20; // er8
  unsigned int v21; // er9
  signed __int64 v22; // rdx
  unsigned int v23; // er8
  unsigned int v24; // er9
  unsigned int v25; // er8
  unsigned int v26; // er9
  unsigned __int16 v27; // cx
  UFG::AttackRightsComponent *v28; // rax
  unsigned int v29; // er8
  unsigned int v30; // er9
  signed __int64 v31; // rdx
  unsigned int v32; // er8
  unsigned int v33; // er9
  unsigned int v34; // er8
  unsigned int v35; // er9
  unsigned __int16 v36; // cx
  UFG::AIScriptInterfaceComponent *v37; // rax
  unsigned int v38; // er8
  unsigned int v39; // er9
  signed __int64 v40; // rdx
  unsigned int v41; // er8
  unsigned int v42; // er9
  unsigned __int16 v43; // cx
  UFG::HealthComponent *v44; // rax
  unsigned int v45; // er8
  unsigned int v46; // er9
  signed __int64 v47; // rdx
  unsigned int v48; // er8
  unsigned int v49; // er9
  unsigned __int16 v50; // cx
  UFG::SimObjectCharacterPropertiesComponent *v51; // rcx
  unsigned int v52; // er8
  unsigned int v53; // er9
  signed __int64 v54; // rdx
  unsigned int v55; // er8
  unsigned int v56; // er9
  unsigned __int16 v57; // cx
  UFG::InventoryComponent *v58; // rax
  unsigned int v59; // er8
  unsigned int v60; // er9
  signed __int64 v61; // rdx
  unsigned int v62; // er8
  unsigned int v63; // er9
  unsigned int v64; // er8
  unsigned int v65; // er9
  UFG::SceneObjectProperties *v66; // r8
  UFG::qPropertySet *v67; // rdx
  unsigned __int16 v68; // cx
  UFG::FaceActionComponent *v69; // rsi
  unsigned int v70; // edx
  unsigned int v71; // er8
  signed __int64 v72; // rsi
  unsigned int v73; // edx
  unsigned int v74; // er8
  unsigned int v75; // edx
  unsigned int v76; // er8
  UFG::SceneObjectProperties *v77; // rbx
  unsigned __int16 v78; // cx
  UFG::PedFormationManagerComponent *v79; // rax
  unsigned int v80; // er8
  unsigned int v81; // er9
  signed __int64 v82; // rdx
  unsigned int v83; // er8
  unsigned int v84; // er9
  unsigned int v85; // er8
  unsigned int v86; // er9
  unsigned __int16 v87; // cx
  UFG::GetInFormationComponent *v88; // rax
  unsigned int v89; // er8
  unsigned int v90; // er9
  signed __int64 v91; // rdx
  unsigned int v92; // er8
  unsigned int v93; // er9
  unsigned int v94; // er8
  unsigned int v95; // er9
  unsigned __int16 v96; // cx
  UFG::ActiveAIEntityComponent *v97; // rbx
  UFG::SimComponent *v98; // rax
  unsigned __int16 v99; // cx
  UFG::InterestPointUserComponent *v100; // rax
  unsigned __int16 v101; // cx
  UFG::InteractableComponent *v102; // rbx
  UFG::SimComponent *v103; // rax
  UFG::qPropertySet *v104; // rax
  unsigned __int16 v105; // cx
  UFG::SimComponent *v106; // rax
  bool v107; // zf
  unsigned __int16 v108; // cx
  UFG::AiDriverComponent *v109; // rcx
  UFG::SimComponent *v110; // rax
  unsigned __int16 v111; // cx
  UFG::HitReactionComponent *v112; // rax
  unsigned __int16 v113; // cx
  UFG::SimComponent *v114; // rcx
  UFG::SimComponent *v115; // rax
  unsigned __int16 v116; // cx
  UFG::ActionTreeComponent *v117; // rax
  unsigned __int16 v118; // cx
  UFG::SimComponent *v119; // rax
  unsigned __int16 v120; // cx
  unsigned __int16 v121; // cx
  UFG::SimComponent *v122; // rcx
  UFG::SimComponent *v123; // rax
  unsigned __int16 v124; // cx
  UFG::FaceMeterComponent *v125; // rax
  unsigned __int16 v126; // cx
  UFG::TSActorComponent *v127; // rbx
  UFG::TSActor *v128; // rax
  UFG::TSActor *v129; // rax
  UFG::TSActor *v130; // rax
  unsigned __int16 v131; // cx
  UFG::CharacterEffectsComponent *v132; // rbx
  UFG::SimComponent *v133; // rax
  UFG::PedSpawnManager *v134; // rax

  v3 = bDeleteItems;
  v4 = (UFG::SimObjectCharacter *)pSimObjectToReset;
  v5 = bSoft;
  if ( UFG::SimObjectUtility::ms_bTraceResetLogging )
  {
    v6 = "False";
    if ( bDeleteItems )
      v6 = "True";
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&pSimObjectToReset->m_Name);
    UFG::qPrintf("ReinitializeSimObject: '%s'(0x%x) Delete Items '%s'\n", v7, v4, v6);
  }
  if ( v4 )
  {
    v8 = v4->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::StreamedResourceComponent *)v4->m_Components.p[10].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::StreamedResourceComponent *)v4->m_Components.p[7].m_pComponent;
      }
      else if ( (v8 >> 12) & 1 )
      {
        v10 = v4->mComponentTableEntryCount;
        v11 = v4->m_Components.size;
        if ( v10 >= v11 )
        {
LABEL_18:
          v9 = 0i64;
        }
        else
        {
          v12 = (signed __int64)&v4->m_Components.p[v10];
          while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
               || UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v12 += 16i64;
            if ( v10 >= v11 )
              goto LABEL_18;
          }
          v9 = *(UFG::StreamedResourceComponent **)v12;
        }
      }
      else
      {
        v9 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v4->vfptr,
                                                 UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v9 = (UFG::StreamedResourceComponent *)v4->m_Components.p[10].m_pComponent;
    }
    if ( v9 )
      UFG::StreamedResourceComponent::ResetPropertyPtr(v9);
    v13 = v4->m_Flags;
    if ( (v13 >> 14) & 1 )
    {
      v14 = v4->m_Components.p[18].m_pComponent;
    }
    else if ( (v13 & 0x8000u) == 0 )
    {
      if ( (v13 >> 13) & 1 )
      {
        v14 = v4->m_Components.p[5].m_pComponent;
      }
      else if ( (v13 >> 12) & 1 )
      {
        v15 = v4->mComponentTableEntryCount;
        v16 = v4->m_Components.size;
        if ( v15 >= v16 )
        {
LABEL_35:
          v14 = 0i64;
        }
        else
        {
          v17 = (signed __int64)&v4->m_Components.p[v15];
          while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::PhantomVolumeComponent::_TypeUID & 0xFE000000)
               || UFG::PhantomVolumeComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
          {
            ++v15;
            v17 += 16i64;
            if ( v15 >= v16 )
              goto LABEL_35;
          }
          v14 = *(UFG::SimComponent **)v17;
        }
      }
      else
      {
        v14 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::PhantomVolumeComponent::_TypeUID);
      }
    }
    else
    {
      v14 = v4->m_Components.p[18].m_pComponent;
    }
    if ( v14 )
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v14);
    v18 = v4->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = v4->m_Components.p[36].m_pComponent;
      goto LABEL_65;
    }
    if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
      {
        v23 = v4->mComponentTableEntryCount;
        v24 = v4->m_Components.size;
        if ( v23 < v24 )
        {
          v22 = (signed __int64)&v4->m_Components.p[v23];
          while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
               || UFG::NavComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
          {
            ++v23;
            v22 += 16i64;
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
        if ( !((v18 >> 12) & 1) )
        {
          v19 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::NavComponent::_TypeUID);
LABEL_65:
          if ( v19 )
            v19->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v19->vfptr, v5);
          v27 = v4->m_Flags;
          if ( (v27 >> 14) & 1 )
          {
            v28 = (UFG::AttackRightsComponent *)v4->m_Components.p[46].m_pComponent;
            goto LABEL_92;
          }
          if ( (v27 & 0x8000u) == 0 )
          {
            if ( (v27 >> 13) & 1 )
            {
              v32 = v4->mComponentTableEntryCount;
              v33 = v4->m_Components.size;
              if ( v32 < v33 )
              {
                v31 = (signed __int64)&v4->m_Components.p[v32];
                while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                     || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
                {
                  ++v32;
                  v31 += 16i64;
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
              if ( !((v27 >> 12) & 1) )
              {
                v28 = (UFG::AttackRightsComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v4->vfptr,
                                                      UFG::AttackRightsComponent::_TypeUID);
LABEL_92:
                if ( v28 )
                  UFG::AttackRightsComponent::Reset(v28);
                goto LABEL_94;
              }
              v34 = v4->mComponentTableEntryCount;
              v35 = v4->m_Components.size;
              if ( v34 < v35 )
              {
                v31 = (signed __int64)&v4->m_Components.p[v34];
                while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                     || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
                {
                  ++v34;
                  v31 += 16i64;
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
            v29 = v4->mComponentTableEntryCount;
            v30 = v4->m_Components.size;
            if ( v29 < v30 )
            {
              v31 = (signed __int64)&v4->m_Components.p[v29];
              while ( (*(_DWORD *)(v31 + 8) & 0xFE000000) != (UFG::AttackRightsComponent::_TypeUID & 0xFE000000)
                   || UFG::AttackRightsComponent::_TypeUID & ~*(_DWORD *)(v31 + 8) & 0x1FFFFFF )
              {
                ++v29;
                v31 += 16i64;
                if ( v29 >= v30 )
                  goto LABEL_75;
              }
LABEL_76:
              v28 = *(UFG::AttackRightsComponent **)v31;
              goto LABEL_92;
            }
          }
LABEL_75:
          v28 = 0i64;
          goto LABEL_92;
        }
        v25 = v4->mComponentTableEntryCount;
        v26 = v4->m_Components.size;
        if ( v25 < v26 )
        {
          v22 = (signed __int64)&v4->m_Components.p[v25];
          while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
               || UFG::NavComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
          {
            ++v25;
            v22 += 16i64;
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
      v20 = v4->mComponentTableEntryCount;
      v21 = v4->m_Components.size;
      if ( v20 < v21 )
      {
        v22 = (signed __int64)&v4->m_Components.p[v20];
        while ( (*(_DWORD *)(v22 + 8) & 0xFE000000) != (UFG::NavComponent::_TypeUID & 0xFE000000)
             || UFG::NavComponent::_TypeUID & ~*(_DWORD *)(v22 + 8) & 0x1FFFFFF )
        {
          ++v20;
          v22 += 16i64;
          if ( v20 >= v21 )
            goto LABEL_48;
        }
LABEL_49:
        v19 = *(UFG::SimComponent **)v22;
        goto LABEL_65;
      }
    }
LABEL_48:
    v19 = 0i64;
    goto LABEL_65;
  }
LABEL_94:
  if ( v5 )
    goto LABEL_140;
  if ( !v4 )
    goto LABEL_318;
  v36 = v4->m_Flags;
  if ( (v36 >> 14) & 1 )
  {
    v37 = (UFG::AIScriptInterfaceComponent *)v4->m_Components.p[5].m_pComponent;
    goto LABEL_116;
  }
  if ( (v36 & 0x8000u) != 0 )
  {
    v37 = (UFG::AIScriptInterfaceComponent *)v4->m_Components.p[5].m_pComponent;
    goto LABEL_116;
  }
  if ( (v36 >> 13) & 1 )
  {
    v38 = v4->mComponentTableEntryCount;
    v39 = v4->m_Components.size;
    if ( v38 < v39 )
    {
      v40 = (signed __int64)&v4->m_Components.p[v38];
      while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::AIScriptInterfaceComponent::_TypeUID & 0xFE000000)
           || UFG::AIScriptInterfaceComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
      {
        ++v38;
        v40 += 16i64;
        if ( v38 >= v39 )
          goto LABEL_106;
      }
LABEL_107:
      v37 = *(UFG::AIScriptInterfaceComponent **)v40;
      goto LABEL_116;
    }
    goto LABEL_106;
  }
  if ( (v36 >> 12) & 1 )
  {
    v41 = v4->mComponentTableEntryCount;
    v42 = v4->m_Components.size;
    if ( v41 < v42 )
    {
      v40 = (signed __int64)&v4->m_Components.p[v41];
      while ( (*(_DWORD *)(v40 + 8) & 0xFE000000) != (UFG::AIScriptInterfaceComponent::_TypeUID & 0xFE000000)
           || UFG::AIScriptInterfaceComponent::_TypeUID & ~*(_DWORD *)(v40 + 8) & 0x1FFFFFF )
      {
        ++v41;
        v40 += 16i64;
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
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::AIScriptInterfaceComponent::_TypeUID);
LABEL_116:
  if ( v37 )
    UFG::AIScriptInterfaceComponent::Reset(v37);
  v43 = v4->m_Flags;
  if ( (v43 >> 14) & 1 )
  {
    v44 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
    goto LABEL_138;
  }
  if ( (v43 & 0x8000u) != 0 )
  {
    v44 = (UFG::HealthComponent *)v4->m_Components.p[6].m_pComponent;
    goto LABEL_138;
  }
  if ( (v43 >> 13) & 1 )
  {
    v45 = v4->mComponentTableEntryCount;
    v46 = v4->m_Components.size;
    if ( v45 < v46 )
    {
      v47 = (signed __int64)&v4->m_Components.p[v45];
      while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF )
      {
        ++v45;
        v47 += 16i64;
        if ( v45 >= v46 )
          goto LABEL_128;
      }
LABEL_129:
      v44 = *(UFG::HealthComponent **)v47;
      goto LABEL_138;
    }
    goto LABEL_128;
  }
  if ( (v43 >> 12) & 1 )
  {
    v48 = v4->mComponentTableEntryCount;
    v49 = v4->m_Components.size;
    if ( v48 < v49 )
    {
      v47 = (signed __int64)&v4->m_Components.p[v48];
      while ( (*(_DWORD *)(v47 + 8) & 0xFE000000) != (UFG::HealthComponent::_TypeUID & 0xFE000000)
           || UFG::HealthComponent::_TypeUID & ~*(_DWORD *)(v47 + 8) & 0x1FFFFFF )
      {
        ++v48;
        v47 += 16i64;
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
  v44 = (UFG::HealthComponent *)UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v4->vfptr,
                                  UFG::HealthComponent::_TypeUID);
LABEL_138:
  if ( v44 )
    UFG::HealthComponent::Reset(v44);
LABEL_140:
  if ( !v4 )
    goto LABEL_318;
  v50 = v4->m_Flags;
  if ( !((v50 >> 14) & 1) )
  {
    if ( (v50 & 0x8000u) != 0 )
    {
      v51 = (UFG::SimObjectCharacterPropertiesComponent *)v4->m_Components.p[3].m_pComponent;
      if ( !v51 || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v51->m_TypeUID) & 0xFE000000 )
        goto LABEL_145;
      if ( UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v51->m_TypeUID & 0x1FFFFFF )
        v51 = 0i64;
      goto LABEL_167;
    }
    if ( (v50 >> 13) & 1 )
    {
      v52 = v4->mComponentTableEntryCount;
      v53 = v4->m_Components.size;
      if ( v52 < v53 )
      {
        v54 = (signed __int64)&v4->m_Components.p[v52];
        while ( (*(_DWORD *)(v54 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v54 + 8) & 0x1FFFFFF )
        {
          ++v52;
          v54 += 16i64;
          if ( v52 >= v53 )
          {
            v51 = 0i64;
            goto LABEL_167;
          }
        }
LABEL_158:
        v51 = *(UFG::SimObjectCharacterPropertiesComponent **)v54;
        goto LABEL_167;
      }
    }
    else
    {
      if ( !((v50 >> 12) & 1) )
      {
        v51 = (UFG::SimObjectCharacterPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v4->vfptr,
                                                              UFG::SimObjectCharacterPropertiesComponent::_TypeUID);
        goto LABEL_167;
      }
      v55 = v4->mComponentTableEntryCount;
      v56 = v4->m_Components.size;
      if ( v55 < v56 )
      {
        v54 = (signed __int64)&v4->m_Components.p[v55];
        while ( (*(_DWORD *)(v54 + 8) & 0xFE000000) != (UFG::SimObjectCharacterPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~*(_DWORD *)(v54 + 8) & 0x1FFFFFF )
        {
          ++v55;
          v54 += 16i64;
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
  v51 = (UFG::SimObjectCharacterPropertiesComponent *)v4->m_Components.p[3].m_pComponent;
  if ( !v51
    || (UFG::SimObjectCharacterPropertiesComponent::_TypeUID ^ v51->m_TypeUID) & 0xFE000000
    || UFG::SimObjectCharacterPropertiesComponent::_TypeUID & ~v51->m_TypeUID & 0x1FFFFFF )
  {
    goto LABEL_145;
  }
LABEL_167:
  if ( v51 )
    UFG::SimObjectCharacterPropertiesComponent::Reset(v51, v5);
  v57 = v4->m_Flags;
  if ( !((v57 >> 14) & 1) )
  {
    if ( (v57 & 0x8000u) == 0 )
    {
      if ( (v57 >> 13) & 1 )
      {
        v62 = v4->mComponentTableEntryCount;
        v63 = v4->m_Components.size;
        if ( v62 < v63 )
        {
          v61 = (signed __int64)&v4->m_Components.p[v62];
          while ( (*(_DWORD *)(v61 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v61 + 8) & 0x1FFFFFF )
          {
            ++v62;
            v61 += 16i64;
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
        if ( !((v57 >> 12) & 1) )
        {
          v58 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::InventoryComponent::_TypeUID);
          goto LABEL_194;
        }
        v64 = v4->mComponentTableEntryCount;
        v65 = v4->m_Components.size;
        if ( v64 < v65 )
        {
          v61 = (signed __int64)&v4->m_Components.p[v64];
          while ( (*(_DWORD *)(v61 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
               || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v61 + 8) & 0x1FFFFFF )
          {
            ++v64;
            v61 += 16i64;
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
      v59 = v4->mComponentTableEntryCount;
      v60 = v4->m_Components.size;
      if ( v59 < v60 )
      {
        v61 = (signed __int64)&v4->m_Components.p[v59];
        while ( (*(_DWORD *)(v61 + 8) & 0xFE000000) != (UFG::InventoryComponent::_TypeUID & 0xFE000000)
             || UFG::InventoryComponent::_TypeUID & ~*(_DWORD *)(v61 + 8) & 0x1FFFFFF )
        {
          ++v59;
          v61 += 16i64;
          if ( v59 >= v60 )
            goto LABEL_177;
        }
LABEL_178:
        v58 = *(UFG::InventoryComponent **)v61;
        goto LABEL_194;
      }
    }
LABEL_177:
    v58 = 0i64;
    goto LABEL_194;
  }
  v58 = (UFG::InventoryComponent *)v4->m_Components.p[39].m_pComponent;
LABEL_194:
  if ( v58 )
  {
    v66 = v58->m_pSimObject->m_pSceneObj;
    v67 = v66->mpWritableProperties;
    if ( v67 || (v67 = v66->mpConstProperties) != 0i64 )
      UFG::InventoryComponent::ResetFromProperties(v58, v67);
  }
  v68 = v4->m_Flags;
  if ( (v68 >> 14) & 1 )
  {
    v69 = (UFG::FaceActionComponent *)v4->m_Components.p[45].m_pComponent;
    goto LABEL_223;
  }
  if ( (v68 & 0x8000u) != 0 )
  {
    v70 = v4->mComponentTableEntryCount;
    v71 = v4->m_Components.size;
    if ( v70 < v71 )
    {
      v72 = (signed __int64)&v4->m_Components.p[v70];
      while ( (*(_DWORD *)(v72 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v72 + 8) & 0x1FFFFFF )
      {
        ++v70;
        v72 += 16i64;
        if ( v70 >= v71 )
          goto LABEL_206;
      }
LABEL_207:
      v69 = *(UFG::FaceActionComponent **)v72;
      goto LABEL_223;
    }
    goto LABEL_206;
  }
  if ( (v68 >> 13) & 1 )
  {
    v73 = v4->mComponentTableEntryCount;
    v74 = v4->m_Components.size;
    if ( v73 < v74 )
    {
      v72 = (signed __int64)&v4->m_Components.p[v73];
      while ( (*(_DWORD *)(v72 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v72 + 8) & 0x1FFFFFF )
      {
        ++v73;
        v72 += 16i64;
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
  if ( (v68 >> 12) & 1 )
  {
    v75 = v4->mComponentTableEntryCount;
    v76 = v4->m_Components.size;
    if ( v75 < v76 )
    {
      v72 = (signed __int64)&v4->m_Components.p[v75];
      while ( (*(_DWORD *)(v72 + 8) & 0xFE000000) != (UFG::FaceActionComponent::_TypeUID & 0xFE000000)
           || UFG::FaceActionComponent::_TypeUID & ~*(_DWORD *)(v72 + 8) & 0x1FFFFFF )
      {
        ++v75;
        v72 += 16i64;
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
                                      (UFG::SimObject *)&v4->vfptr,
                                      UFG::FaceActionComponent::_TypeUID);
LABEL_223:
  if ( v69 )
  {
    v77 = v69->m_pSimObject->m_pSceneObj;
    UFG::FaceActionComponent::ResetState(v69);
    v69->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v69->vfptr, (unsigned int)v77);
  }
  v78 = v4->m_Flags;
  if ( (v78 >> 14) & 1 )
  {
    v79 = (UFG::PedFormationManagerComponent *)v4->m_Components.p[33].m_pComponent;
    goto LABEL_250;
  }
  if ( (v78 & 0x8000u) != 0 )
  {
    v80 = v4->mComponentTableEntryCount;
    v81 = v4->m_Components.size;
    if ( v80 < v81 )
    {
      v82 = (signed __int64)&v4->m_Components.p[v80];
      while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || UFG::PedFormationManagerComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
      {
        ++v80;
        v82 += 16i64;
        if ( v80 >= v81 )
          goto LABEL_233;
      }
LABEL_234:
      v79 = *(UFG::PedFormationManagerComponent **)v82;
      goto LABEL_250;
    }
    goto LABEL_233;
  }
  if ( (v78 >> 13) & 1 )
  {
    v83 = v4->mComponentTableEntryCount;
    v84 = v4->m_Components.size;
    if ( v83 < v84 )
    {
      v82 = (signed __int64)&v4->m_Components.p[v83];
      while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || UFG::PedFormationManagerComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
      {
        ++v83;
        v82 += 16i64;
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
  if ( (v78 >> 12) & 1 )
  {
    v85 = v4->mComponentTableEntryCount;
    v86 = v4->m_Components.size;
    if ( v85 < v86 )
    {
      v82 = (signed __int64)&v4->m_Components.p[v85];
      while ( (*(_DWORD *)(v82 + 8) & 0xFE000000) != (UFG::PedFormationManagerComponent::_TypeUID & 0xFE000000)
           || UFG::PedFormationManagerComponent::_TypeUID & ~*(_DWORD *)(v82 + 8) & 0x1FFFFFF )
      {
        ++v85;
        v82 += 16i64;
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
                                               (UFG::SimObject *)&v4->vfptr,
                                               UFG::PedFormationManagerComponent::_TypeUID);
LABEL_250:
  if ( v79 )
    UFG::PedFormationManagerComponent::Reset(v79);
  v87 = v4->m_Flags;
  if ( (v87 >> 14) & 1 )
  {
    v88 = (UFG::GetInFormationComponent *)v4->m_Components.p[34].m_pComponent;
    goto LABEL_277;
  }
  if ( (v87 & 0x8000u) != 0 )
  {
    v89 = v4->mComponentTableEntryCount;
    v90 = v4->m_Components.size;
    if ( v89 < v90 )
    {
      v91 = (signed __int64)&v4->m_Components.p[v89];
      while ( (*(_DWORD *)(v91 + 8) & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || UFG::GetInPedFormationComponent::_TypeUID & ~*(_DWORD *)(v91 + 8) & 0x1FFFFFF )
      {
        ++v89;
        v91 += 16i64;
        if ( v89 >= v90 )
          goto LABEL_260;
      }
LABEL_261:
      v88 = *(UFG::GetInFormationComponent **)v91;
      goto LABEL_277;
    }
    goto LABEL_260;
  }
  if ( (v87 >> 13) & 1 )
  {
    v92 = v4->mComponentTableEntryCount;
    v93 = v4->m_Components.size;
    if ( v92 < v93 )
    {
      v91 = (signed __int64)&v4->m_Components.p[v92];
      while ( (*(_DWORD *)(v91 + 8) & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || UFG::GetInPedFormationComponent::_TypeUID & ~*(_DWORD *)(v91 + 8) & 0x1FFFFFF )
      {
        ++v92;
        v91 += 16i64;
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
  if ( (v87 >> 12) & 1 )
  {
    v94 = v4->mComponentTableEntryCount;
    v95 = v4->m_Components.size;
    if ( v94 < v95 )
    {
      v91 = (signed __int64)&v4->m_Components.p[v94];
      while ( (*(_DWORD *)(v91 + 8) & 0xFE000000) != (UFG::GetInPedFormationComponent::_TypeUID & 0xFE000000)
           || UFG::GetInPedFormationComponent::_TypeUID & ~*(_DWORD *)(v91 + 8) & 0x1FFFFFF )
      {
        ++v94;
        v91 += 16i64;
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
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::GetInPedFormationComponent::_TypeUID);
LABEL_277:
  if ( v88 )
    UFG::GetInPedFormationComponent::DeleteList(v88);
  v96 = v4->m_Flags;
  if ( (v96 >> 14) & 1 )
  {
    v97 = (UFG::ActiveAIEntityComponent *)v4->m_Components.p[22].m_pComponent;
    if ( !v97
      || (UFG::ActiveAIEntityComponent::_TypeUID ^ v97->m_TypeUID) & 0xFE000000
      || UFG::ActiveAIEntityComponent::_TypeUID & ~v97->m_TypeUID & 0x1FFFFFF )
    {
LABEL_283:
      v97 = 0i64;
      goto LABEL_295;
    }
  }
  else if ( (v96 & 0x8000u) == 0 )
  {
    if ( (v96 >> 13) & 1 )
    {
      v98 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v4->vfptr,
              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else if ( (v96 >> 12) & 1 )
    {
      v98 = UFG::SimObjectGame::GetComponentOfTypeHK(
              (UFG::SimObjectGame *)&v4->vfptr,
              UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      v98 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::ActiveAIEntityComponent::_TypeUID);
    }
    v97 = (UFG::ActiveAIEntityComponent *)v98;
  }
  else
  {
    v97 = (UFG::ActiveAIEntityComponent *)v4->m_Components.p[22].m_pComponent;
    if ( !v97 || (UFG::ActiveAIEntityComponent::_TypeUID ^ v97->m_TypeUID) & 0xFE000000 )
      goto LABEL_283;
    if ( UFG::ActiveAIEntityComponent::_TypeUID & ~v97->m_TypeUID & 0x1FFFFFF )
      v97 = 0i64;
  }
LABEL_295:
  if ( v97 )
  {
    UFG::ActiveAIEntityComponent::ResetAndLoadProperties(v97);
    UFG::AIEntityComponent::OnSiblingsChanged((UFG::AIEntityComponent *)&v97->vfptr);
  }
  v99 = v4->m_Flags;
  if ( (v99 >> 14) & 1 )
  {
    v100 = (UFG::InterestPointUserComponent *)v4->m_Components.p[43].m_pComponent;
    goto LABEL_304;
  }
  if ( (v99 & 0x8000u) == 0 )
  {
    if ( (v99 >> 13) & 1 )
    {
      v100 = (UFG::InterestPointUserComponent *)v4->m_Components.p[12].m_pComponent;
      goto LABEL_304;
    }
    if ( !((v99 >> 12) & 1) )
    {
      v100 = (UFG::InterestPointUserComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v4->vfptr,
                                                  UFG::InterestPointUserComponent::_TypeUID);
LABEL_304:
      if ( v100 )
        UFG::InterestPointUserComponent::Reset(v100);
      goto LABEL_306;
    }
  }
LABEL_306:
  v101 = v4->m_Flags;
  if ( (v101 >> 14) & 1 )
  {
    v102 = (UFG::InteractableComponent *)v4->m_Components.p[12].m_pComponent;
  }
  else if ( (v101 & 0x8000u) == 0 )
  {
    if ( (v101 >> 13) & 1 )
    {
      v103 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::InteractableComponent::_TypeUID);
    }
    else if ( (v101 >> 12) & 1 )
    {
      v103 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::InteractableComponent::_TypeUID);
    }
    else
    {
      v103 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::InteractableComponent::_TypeUID);
    }
    v102 = (UFG::InteractableComponent *)v103;
  }
  else
  {
    v102 = (UFG::InteractableComponent *)v4->m_Components.p[12].m_pComponent;
  }
  if ( v102 )
  {
    UFG::InteractableComponent::DestroyInteractionPoints(v102);
    v104 = UFG::InteractableComponent::GetDataPtr(v102->m_pSimObject->m_pSceneObj);
    UFG::InteractableComponent::InitFromData(v102, (component_Interactable *)v104);
  }
LABEL_318:
  UFG::SimObjectUtility::ResetState((UFG::SimObject *)&v4->vfptr, 0, v3);
  if ( !v4 )
    goto LABEL_360;
  v105 = v4->m_Flags;
  if ( (v105 >> 14) & 1 )
  {
    v106 = v4->m_Components.p[8].m_pComponent;
  }
  else if ( (v105 & 0x8000u) == 0 )
  {
    if ( (v105 >> 13) & 1 )
    {
      v106 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
    }
    else if ( (v105 >> 12) & 1 )
    {
      v106 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
    }
    else
    {
      v106 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v4->vfptr,
               UFG::MissionFailConditionComponent::_TypeUID);
    }
  }
  else
  {
    v106 = v4->m_Components.p[8].m_pComponent;
  }
  if ( v106 )
  {
    v107 = HIBYTE(v106[1].m_BoundComponentHandles.mNode.mPrev) == 0;
    LOBYTE(v106[1].m_Flags) = 0;
    *(_QWORD *)(&v106[1].m_SimObjIndex + 1) = 0i64;
    if ( !v107 )
      UFG::MissionFailConditionComponent::EnableDistanceFailTrigger((UFG::MissionFailConditionComponent *)v106, 1);
  }
  v108 = v4->m_Flags;
  if ( (v108 >> 14) & 1 )
  {
    v109 = (UFG::AiDriverComponent *)v4->m_Components.p[23].m_pComponent;
    if ( v109
      && !((UFG::AiDriverComponent::_TypeUID ^ v109->m_TypeUID) & 0xFE000000)
      && !(UFG::AiDriverComponent::_TypeUID & ~v109->m_TypeUID & 0x1FFFFFF) )
    {
      goto LABEL_347;
    }
  }
  else
  {
    if ( (v108 & 0x8000u) == 0 )
    {
      if ( (v108 >> 13) & 1 )
      {
        v110 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v108 >> 12) & 1 )
      {
        v110 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v110 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::AiDriverComponent::_TypeUID);
      }
      v109 = (UFG::AiDriverComponent *)v110;
      goto LABEL_347;
    }
    v109 = (UFG::AiDriverComponent *)v4->m_Components.p[23].m_pComponent;
    if ( v109 && !((UFG::AiDriverComponent::_TypeUID ^ v109->m_TypeUID) & 0xFE000000) )
    {
      if ( UFG::AiDriverComponent::_TypeUID & ~v109->m_TypeUID & 0x1FFFFFF )
        v109 = 0i64;
      goto LABEL_347;
    }
  }
  v109 = 0i64;
LABEL_347:
  if ( v109 )
    UFG::AiDriverComponent::SetDrivingMode(v109, 0);
  v111 = v4->m_Flags;
  if ( (v111 >> 14) & 1 )
  {
    v112 = (UFG::HitReactionComponent *)v4->m_Components.p[15].m_pComponent;
  }
  else if ( (v111 & 0x8000u) == 0 )
  {
    if ( (v111 >> 13) & 1 )
    {
      v112 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v4->vfptr,
                                            UFG::HitReactionComponent::_TypeUID);
    }
    else if ( (v111 >> 12) & 1 )
    {
      v112 = (UFG::HitReactionComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v4->vfptr,
                                            UFG::HitReactionComponent::_TypeUID);
    }
    else
    {
      v112 = (UFG::HitReactionComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v4->vfptr,
                                            UFG::HitReactionComponent::_TypeUID);
    }
  }
  else
  {
    v112 = (UFG::HitReactionComponent *)v4->m_Components.p[15].m_pComponent;
  }
  if ( v112 )
    UFG::HitReactionComponent::Reset(v112);
LABEL_360:
  if ( !v5 )
  {
    if ( !v4 )
      goto LABEL_457;
    v113 = v4->m_Flags;
    if ( (v113 >> 14) & 1 )
    {
      v114 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v113 & 0x8000u) == 0 )
    {
      if ( (v113 >> 13) & 1 )
      {
        v115 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v113 >> 12) & 1 )
      {
        v115 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v115 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v114 = v115;
    }
    else
    {
      v114 = v4->m_Components.p[20].m_pComponent;
    }
    if ( v114 )
      ((void (*)(void))v114->vfptr[20].__vecDelDtor)();
  }
  if ( v4 )
  {
    v116 = v4->m_Flags;
    if ( (v116 >> 14) & 1 )
    {
      v117 = (UFG::ActionTreeComponent *)v4->m_Components.p[7].m_pComponent;
    }
    else if ( (v116 & 0x8000u) == 0 )
    {
      if ( (v116 >> 13) & 1 )
      {
        v117 = (UFG::ActionTreeComponent *)v4->m_Components.p[6].m_pComponent;
      }
      else if ( (v116 >> 12) & 1 )
      {
        v117 = (UFG::ActionTreeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v4->vfptr,
                                             UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v117 = (UFG::ActionTreeComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v117 = (UFG::ActionTreeComponent *)v4->m_Components.p[7].m_pComponent;
    }
    if ( v117 )
      UFG::ActionTreeComponent::Reset(v117);
    v118 = v4->m_Flags;
    if ( (v118 >> 14) & 1 )
    {
      v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::StimulusEmitterComponent::_TypeUID);
    }
    else if ( (v118 & 0x8000u) == 0 )
    {
      if ( (v118 >> 13) & 1 )
      {
        v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::StimulusEmitterComponent::_TypeUID);
      }
      else if ( (v118 >> 12) & 1 )
      {
        v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::StimulusEmitterComponent::_TypeUID);
      }
      else
      {
        v119 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::StimulusEmitterComponent::_TypeUID);
      }
    }
    else
    {
      v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v4->vfptr,
               UFG::StimulusEmitterComponent::_TypeUID);
    }
    while ( v119 )
    {
      UFG::Simulation::DestroySimComponent(&UFG::gSim, v119);
      v120 = v4->m_Flags;
      if ( (v120 >> 14) & 1 )
      {
        v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::StimulusEmitterComponent::_TypeUID);
      }
      else if ( (v120 & 0x8000u) == 0 )
      {
        if ( (v120 >> 13) & 1 )
        {
          v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v4->vfptr,
                   UFG::StimulusEmitterComponent::_TypeUID);
        }
        else if ( (v120 >> 12) & 1 )
        {
          v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v4->vfptr,
                   UFG::StimulusEmitterComponent::_TypeUID);
        }
        else
        {
          v119 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v4->vfptr,
                   UFG::StimulusEmitterComponent::_TypeUID);
        }
      }
      else
      {
        v119 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::StimulusEmitterComponent::_TypeUID);
      }
    }
    v121 = v4->m_Flags;
    if ( (v121 >> 14) & 1 )
    {
      v122 = v4->m_Components.p[9].m_pComponent;
    }
    else if ( (v121 & 0x8000u) == 0 )
    {
      if ( (v121 >> 13) & 1 )
      {
        v122 = v4->m_Components.p[8].m_pComponent;
      }
      else
      {
        if ( (v121 >> 12) & 1 )
          v123 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v4->vfptr,
                   UFG::BaseAnimationComponent::_TypeUID);
        else
          v123 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        v122 = v123;
      }
    }
    else
    {
      v122 = v4->m_Components.p[9].m_pComponent;
    }
    if ( v122 )
      ((void (*)(void))v122->vfptr[17].__vecDelDtor)();
    v124 = v4->m_Flags;
    if ( (v124 >> 14) & 1 )
    {
      v125 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v4->vfptr,
                                          UFG::FaceMeterComponent::_TypeUID);
    }
    else if ( (v124 & 0x8000u) == 0 )
    {
      if ( (v124 >> 13) & 1 )
      {
        v125 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v4->vfptr,
                                            UFG::FaceMeterComponent::_TypeUID);
      }
      else if ( (v124 >> 12) & 1 )
      {
        v125 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                            (UFG::SimObjectGame *)&v4->vfptr,
                                            UFG::FaceMeterComponent::_TypeUID);
      }
      else
      {
        v125 = (UFG::FaceMeterComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v4->vfptr,
                                            UFG::FaceMeterComponent::_TypeUID);
      }
    }
    else
    {
      v125 = (UFG::FaceMeterComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v4->vfptr,
                                          UFG::FaceMeterComponent::_TypeUID);
    }
    if ( v125 )
      UFG::FaceMeterComponent::Reset(v125);
    v126 = v4->m_Flags;
    if ( (v126 >> 14) & 1 )
    {
      v127 = (UFG::TSActorComponent *)v4->m_Components.p[4].m_pComponent;
    }
    else if ( (v126 & 0x8000u) == 0 )
    {
      if ( (v126 >> 13) & 1 )
      {
        v127 = (UFG::TSActorComponent *)v4->m_Components.p[3].m_pComponent;
      }
      else if ( (v126 >> 12) & 1 )
      {
        v127 = (UFG::TSActorComponent *)v4->m_Components.p[2].m_pComponent;
      }
      else
      {
        v127 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v4->vfptr,
                                          UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v127 = (UFG::TSActorComponent *)v4->m_Components.p[4].m_pComponent;
    }
    if ( v127 )
    {
      v128 = v127->mpActor.i_obj_p;
      if ( v128 )
      {
        if ( v127->mpActor.i_ptr_id == v128->i_ptr_id )
        {
          v129 = UFG::TSActorComponent::GetActor(v127);
          SSActor::clear_coroutines((SSActor *)&v129->vfptr);
          v130 = UFG::TSActorComponent::GetActor(v127);
          SSActor::enable_behavior((SSActor *)&v130->vfptr, 1);
        }
      }
    }
    v131 = v4->m_Flags;
    if ( (v131 >> 14) & 1 )
    {
      v132 = (UFG::CharacterEffectsComponent *)v4->m_Components.p[38].m_pComponent;
    }
    else
    {
      if ( (v131 & 0x8000u) == 0 )
      {
        if ( (v131 >> 13) & 1 )
        {
          v133 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v4->vfptr,
                   UFG::CharacterEffectsComponent::_TypeUID);
        }
        else if ( (v131 >> 12) & 1 )
        {
          v133 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&v4->vfptr,
                   UFG::CharacterEffectsComponent::_TypeUID);
        }
        else
        {
          v133 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v4->vfptr,
                   UFG::CharacterEffectsComponent::_TypeUID);
        }
      }
      else
      {
        v133 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v4->vfptr,
                 UFG::CharacterEffectsComponent::_TypeUID);
      }
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
LABEL_457:
  v134 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetSuspendOption(v134, (UFG::SimObject *)&v4->vfptr, 0);
  if ( v4 == LocalPlayer )
    UFG::CustomizeBindings::OnResetLocalPlayer((UFG::SimObject *)&v4->vfptr);
  return 1;
}131 & 0x8000u) == 0 )
      {
        if ( (v131 >

// File Line: 770
// RVA: 0x5233D0
void __fastcall UFG::SimObjectUtility::ConditionSimObjectForAmbientWorld(UFG::SimObject *pObject)
{
  UFG::SimObject *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::TSActorComponent *v3; // rax
  UFG::TSActor *v4; // rcx
  UFG::TSActor *v5; // rax
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // er8
  unsigned int v9; // er9
  signed __int64 v10; // rdx
  unsigned int v11; // er8
  unsigned int v12; // er9

  if ( pObject )
  {
    v1 = pObject;
    v2 = pObject->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::TSActorComponent *)v1->m_Components.p[3].m_pComponent;
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::TSActorComponent *)v1->m_Components.p[2].m_pComponent;
      }
      else
      {
        v3 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v1, UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    if ( v3 )
    {
      v4 = v3->mpActor.i_obj_p;
      if ( v4 )
      {
        if ( v3->mpActor.i_ptr_id == v4->i_ptr_id )
        {
          v5 = UFG::TSActorComponent::GetActor(v3);
          SSActor::clear_coroutines((SSActor *)&v5->vfptr);
        }
      }
    }
    v6 = v1->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v1->m_Components.p[8].m_pComponent;
      goto LABEL_35;
    }
    if ( (v6 & 0x8000u) != 0 )
    {
      v7 = v1->m_Components.p[8].m_pComponent;
      goto LABEL_35;
    }
    if ( (v6 >> 13) & 1 )
    {
      v8 = (unsigned int)v1[1].vfptr;
      v9 = v1->m_Components.size;
      if ( v8 < v9 )
      {
        v10 = (signed __int64)&v1->m_Components.p[v8];
        while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
             || UFG::MissionFailConditionComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
        {
          ++v8;
          v10 += 16i64;
          if ( v8 >= v9 )
            goto LABEL_25;
        }
LABEL_26:
        v7 = *(UFG::SimComponent **)v10;
        goto LABEL_35;
      }
    }
    else
    {
      if ( !((v6 >> 12) & 1) )
      {
        v7 = UFG::SimObject::GetComponentOfType(v1, UFG::MissionFailConditionComponent::_TypeUID);
LABEL_35:
        if ( v7 )
        {
          UFG::MissionFailConditionComponent::SetFailTrigger(v1, (UFG::qSymbol *)&qSymbol_ArrestFailTrigger.mUID, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(v1, (UFG::qSymbol *)&qSymbol_DeathFailTrigger.mUID, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(v1, (UFG::qSymbol *)&qSymbol_DamageFailTrigger.mUID, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(v1, (UFG::qSymbol *)&qSymbol_DistanceFailTrigger.mUID, 0);
          UFG::MissionFailConditionComponent::SetFailTrigger(
            v1,
            (UFG::qSymbol *)&qSymbol_PanicWeaponFailTrigger.mUID,
            0);
          UFG::MissionFailConditionComponent::SetFailTrigger(
            v1,
            (UFG::qSymbol *)&qSymbol_PanicVehicleFailTrigger.mUID,
            0);
          UFG::MissionFailConditionComponent::SetFailTrigger(
            v1,
            (UFG::qSymbol *)&qSymbol_VehicleFlipFailTrigger.mUID,
            0);
          UFG::MissionFailConditionComponent::SetFailTrigger(v1, (UFG::qSymbol *)&qSymbol_BoatStuckFailTrigger.mUID, 0);
          UFG::MissionFailConditionComponent::SetFailThreshold(
            v1,
            (UFG::qSymbol *)&qSymbol_DamageHealthThreshold.mUID,
            0.0);
        }
        return;
      }
      v11 = (unsigned int)v1[1].vfptr;
      v12 = v1->m_Components.size;
      if ( v11 < v12 )
      {
        v10 = (signed __int64)&v1->m_Components.p[v11];
        while ( (*(_DWORD *)(v10 + 8) & 0xFE000000) != (UFG::MissionFailConditionComponent::_TypeUID & 0xFE000000)
             || UFG::MissionFailConditionComponent::_TypeUID & ~*(_DWORD *)(v10 + 8) & 0x1FFFFFF )
        {
          ++v11;
          v10 += 16i64;
          if ( v11 >= v12 )
          {
            v7 = 0i64;
            goto LABEL_35;
          }
        }
        goto LABEL_26;
      }
    }
LABEL_25:
    v7 = 0i64;
    goto LABEL_35;
  }
}

// File Line: 798
// RVA: 0x5223E0
void __fastcall UFG::SimObjectUtility::AttachHudSymbol(UFG::SimObject *pObject, const char *symbolName, bool useCustomFilterDistance, float customFilterDistance, const char *customWorldMapCaption)
{
  bool v5; // bl
  const char *v6; // rsi
  UFG::SimObject *v7; // rdi
  UFG::qMemoryPool *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rbx
  UFG::SimObjectModifier v12; // [rsp+38h] [rbp-40h]

  v5 = useCustomFilterDistance;
  v6 = symbolName;
  v7 = pObject;
  if ( !(_S12_8 & 1) )
  {
    _S12_8 |= 1u;
    name_uid_2 = UFG::qStringHash32("hud_component", 0xFFFFFFFF);
  }
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x118ui64, "HudComponent", 0i64, 1u);
  if ( v9 )
  {
    UFG::HudComponent::HudComponent(
      (UFG::HudComponent *)v9,
      name_uid_2,
      v6,
      v5,
      customFilterDistance,
      customWorldMapCaption);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v12, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v12, v11, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v12);
  UFG::SimObjectModifier::~SimObjectModifier(&v12);
}

// File Line: 810
// RVA: 0x525C70
void __fastcall UFG::SimObjectUtility::DetachHudSymbol(UFG::SimObject *pObject)
{
  unsigned __int16 v1; // dx
  unsigned int v2; // er8
  unsigned int v3; // er9
  UFG::SimComponentHolder *v4; // rdx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // er8
  unsigned int v7; // er9
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9

  if ( pObject )
  {
    v1 = pObject->m_Flags;
    if ( (v1 >> 14) & 1 )
    {
      v2 = (unsigned int)pObject[1].vfptr;
      v3 = pObject->m_Components.size;
      if ( v2 < v3 )
      {
        v4 = &pObject->m_Components.p[v2];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
             || UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
        {
          ++v2;
          ++v4;
          if ( v2 >= v3 )
            goto LABEL_8;
        }
LABEL_9:
        v5 = v4->m_pComponent;
        goto LABEL_32;
      }
    }
    else if ( (v1 & 0x8000u) == 0 )
    {
      if ( (v1 >> 13) & 1 )
      {
        v8 = (unsigned int)pObject[1].vfptr;
        v9 = pObject->m_Components.size;
        if ( v8 < v9 )
        {
          v4 = &pObject->m_Components.p[v8];
          while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
               || UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
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
        if ( !((v1 >> 12) & 1) )
        {
          v5 = UFG::SimObject::GetComponentOfType(pObject, UFG::HudComponent::_TypeUID);
LABEL_32:
          if ( v5 )
            UFG::Simulation::DestroySimComponent(&UFG::gSim, v5);
          return;
        }
        v10 = (unsigned int)pObject[1].vfptr;
        v11 = pObject->m_Components.size;
        if ( v10 < v11 )
        {
          v4 = &pObject->m_Components.p[v10];
          while ( (v4->m_TypeUID & 0xFE000000) != (UFG::HudComponent::_TypeUID & 0xFE000000)
               || UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
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
             || UFG::HudComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
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
    v5 = 0i64;
    goto LABEL_32;
  }
}

// File Line: 823
// RVA: 0x52A360
UFG::qSymbol *__fastcall UFG::SimObjectUtility::GenerateUniqueActorName(UFG::qSymbol *result, UFG::qSymbol *basename)
{
  UFG::qSymbol *v2; // rsi
  UFG::qSymbol *v3; // rdi
  int v4; // ebx
  char dest; // [rsp+20h] [rbp-28h]
  UFG::qSymbol instance_name; // [rsp+50h] [rbp+8h]
  UFG::qSymbol resulta; // [rsp+60h] [rbp+18h]

  v2 = basename;
  v3 = result;
  v4 = 0;
  instance_name.mUID = -1;
  UFG::qSPrintf(&dest, "_%d", 0i64);
  for ( instance_name.mUID = UFG::qSymbol::create_suffix(&resulta, v2, &dest)->mUID;
        UFG::TSActor::find_instance(&instance_name);
        instance_name.mUID = UFG::qSymbol::create_suffix(&resulta, v2, &dest)->mUID )
  {
    UFG::qSPrintf(&dest, "_%d", (unsigned int)++v4);
  }
  v3->mUID = instance_name.mUID;
  return v3;
}

// File Line: 875
// RVA: 0x556870
void __fastcall UFG::SimObjectUtility::Teleport(UFG::SimObject *pSimObject, UFG::qMatrix44 *xform)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::allocator::free_link *v4; // rax

  v2 = xform;
  v3 = pSimObject;
  v4 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v4 )
    UFG::TeleportEvent::TeleportEvent((UFG::TeleportEvent *)v4, v2, v3->mNode.mUID, 0, UFG::TeleportEvent::m_Name, 0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
}

// File Line: 894
// RVA: 0x53B940
bool __fastcall UFG::SimObjectUtility::IsPositionOnScreen(UFG::qVector3 *position, float radius, bool want_fully_on_screen)
{
  bool v3; // si
  UFG::qVector3 *v4; // r14
  UFG::BaseCameraComponent *v5; // rdx
  UFG::Camera *v6; // rdi
  UFG::qMatrix44 *v7; // rbx
  UFG::qMatrix44 *v8; // rax
  int v9; // xmm6_4
  float v10; // xmm12_4
  float v11; // ST44_4
  float v12; // ST48_4
  float v13; // xmm11_4
  float v14; // xmm10_4
  float v15; // xmm13_4
  float v16; // xmm14_4
  float v17; // ST24_4
  float v18; // xmm15_4
  float v19; // ST2C_4
  float v20; // ST38_4
  float v21; // ST20_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  __m128 v25; // xmm2
  float v26; // xmm0_4
  __m128 v27; // xmm2
  float v28; // xmm0_4
  float v29; // xmm5_4
  __m128 v30; // xmm2
  float v31; // xmm0_4
  int v32; // eax
  bool v33; // al
  UFG::qMatrix44 result; // [rsp+50h] [rbp-88h]
  float v35; // [rsp+90h] [rbp-48h]
  float v36; // [rsp+94h] [rbp-44h]
  float v37; // [rsp+98h] [rbp-40h]
  float v38; // [rsp+9Ch] [rbp-3Ch]
  float v39; // [rsp+A0h] [rbp-38h]
  float v40; // [rsp+A4h] [rbp-34h]
  float v41; // [rsp+A8h] [rbp-30h]
  float v42; // [rsp+ACh] [rbp-2Ch]
  float v43; // [rsp+B0h] [rbp-28h]
  float v44; // [rsp+B4h] [rbp-24h]
  float v45; // [rsp+B8h] [rbp-20h]
  float v46; // [rsp+BCh] [rbp-1Ch]
  float v47; // [rsp+C0h] [rbp-18h]
  float v48; // [rsp+C4h] [rbp-14h]
  float radiusa; // [rsp+1A0h] [rbp+C8h]
  unsigned int v50; // [rsp+1A8h] [rbp+D0h]
  float vars0; // [rsp+1B0h] [rbp+D8h]

  v3 = want_fully_on_screen;
  v4 = position;
  v5 = UFG::Director::Get()->mCurrentCamera;
  if ( v5 )
    v6 = &v5->mCamera;
  else
    v6 = 0i64;
  v7 = UFG::Camera::GetViewProjection(v6);
  v8 = UFG::Camera::GetWorldView(v6);
  UFG::qMatrix44::operator*(v8, &result, v7);
  v9 = LODWORD(result.v1.z) ^ _xmm[0];
  LODWORD(v10) = COERCE_UNSIGNED_INT(result.v0.x + result.v0.w) ^ _xmm[0];
  LODWORD(v11) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.y) ^ _xmm[0];
  LODWORD(v12) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.y) ^ _xmm[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(result.v1.x + result.v1.w) ^ _xmm[0];
  LODWORD(v14) = COERCE_UNSIGNED_INT(result.v2.x + result.v2.w) ^ _xmm[0];
  LODWORD(vars0) = COERCE_UNSIGNED_INT(result.v0.y + result.v0.w) ^ _xmm[0];
  v50 = COERCE_UNSIGNED_INT(result.v1.y + result.v1.w) ^ _xmm[0];
  LODWORD(v15) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.x) ^ _xmm[0];
  LODWORD(v16) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.x) ^ _xmm[0];
  LODWORD(v17) = COERCE_UNSIGNED_INT(result.v2.y + result.v2.w) ^ _xmm[0];
  LODWORD(v18) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.x) ^ _xmm[0];
  LODWORD(v19) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.y) ^ _xmm[0];
  LODWORD(v20) = COERCE_UNSIGNED_INT(result.v1.w - result.v1.z) ^ _xmm[0];
  LODWORD(v21) = COERCE_UNSIGNED_INT(result.v2.w - result.v2.z) ^ _xmm[0];
  v22 = fsqrt(
          (float)((float)(*(float *)&v9 * *(float *)&v9)
                + (float)(COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0])))
        + (float)(COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0])));
  result.v2.y = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v1.x) ^ _xmm[0]);
  result.v1.z = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v0.z) ^ _xmm[0]);
  result.v2.x = (float)(1.0 / v22) * COERCE_FLOAT(LODWORD(result.v2.z) ^ _xmm[0]);
  result.v1.w = (float)(1.0 / v22) * *(float *)&v9;
  v23 = fsqrt((float)((float)(v13 * v13) + (float)(v10 * v10)) + (float)(v14 * v14));
  result.v2.z = (float)(1.0 / v23) * v10;
  result.v2.w = (float)(1.0 / v23) * v13;
  result.v3.y = (float)(1.0 / v23) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.z + result.v1.y) ^ _xmm[0]);
  result.v3.x = (float)(1.0 / v23) * v14;
  v24 = fsqrt((float)((float)(v16 * v16) + (float)(v15 * v15)) + (float)(v18 * v18));
  v36 = (float)(1.0 / v24) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.z) ^ _xmm[0]);
  result.v3.z = (float)(1.0 / v24) * v15;
  v35 = (float)(1.0 / v24) * v18;
  result.v3.w = (float)(1.0 / v24) * v16;
  v25 = (__m128)v50;
  v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(vars0 * vars0)) + (float)(v17 * v17);
  LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v25);
  v37 = (float)(1.0 / v26) * vars0;
  v39 = (float)(1.0 / v26) * v17;
  v38 = (float)(1.0 / v26) * *(float *)&v50;
  v27 = (__m128)LODWORD(v12);
  v40 = (float)(1.0 / v26) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v0.w + result.v1.y) ^ _xmm[0]);
  v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v19 * v19)) + (float)(v11 * v11);
  v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
  v44 = v28 * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v0.w) ^ _xmm[0]);
  v41 = v28 * v19;
  v42 = v28 * v12;
  v43 = v28 * v11;
  LODWORD(v29) = COERCE_UNSIGNED_INT(result.v0.w - result.v0.z) ^ _xmm[0];
  v30 = (__m128)LODWORD(v20);
  v30.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v29 * v29)) + (float)(v21 * v21);
  LODWORD(v31) = (unsigned __int128)_mm_sqrt_ps(v30);
  v48 = (float)(1.0 / v31) * COERCE_FLOAT(COERCE_UNSIGNED_INT(result.v1.y - result.v1.x) ^ _xmm[0]);
  v45 = (float)(1.0 / v31) * v29;
  v46 = (float)(1.0 / v31) * v20;
  v47 = (float)(1.0 / v31) * v21;
  v32 = IntersectSphereFrustum((UFG::qVector4 *)((char *)&result.v1 + 8), v4, radiusa);
  if ( v3 )
    v33 = v32 == 1;
  else
    v33 = v32 != 2;
  return v33;
}

// File Line: 929
// RVA: 0x54FB40
char __fastcall UFG::SimObjectUtility_PlaceOnWater(UFG::qVector3 *out, UFG::qVector3 *position, float height_above_ground, float cast_distance)
{
  float v4; // xmm6_4
  UFG::qVector3 *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  unsigned __int64 v9; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-C8h]
  UFG::qReflectHandleBase v15; // [rsp+40h] [rbp-B8h]
  __int64 v16; // [rsp+68h] [rbp-90h]
  UFG::RayCastData data; // [rsp+70h] [rbp-88h]

  v16 = -2i64;
  v4 = height_above_ground;
  v5 = out;
  if ( cast_distance == 0.0 )
    cast_distance = FLOAT_3_0;
  v6 = position->y;
  v7 = position->z;
  rayStart.x = position->x;
  rayStart.y = v6;
  rayEnd.x = rayStart.x;
  rayEnd.y = v6;
  v8 = cast_distance * 0.5;
  rayStart.z = v8 + v7;
  rayEnd.z = v7 - v8;
  data.mInput.m_to.m_quad.m128_i8[8] = 0;
  data.mInput.m_to.m_quad.m128_i32[3] = 0;
  *(_QWORD *)&data.mInput.m_enableShapeCollectionFilter.m_bool = 0i64;
  data.mOutput.m_normal.m_quad.m128_u64[1] = __PAIR__(-1, (unsigned int)FLOAT_1_0);
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
    v11 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v10);
    v15.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&v15, v15.mTypeUID, v9);
    if ( v15.mData && BYTE4(v15.mData[1].mHandles.mNode.mPrev) )
    {
      v5->x = *((float *)&data.mDebugName + 1);
      LODWORD(v5->y) = data.mCollisionModelName.mUID;
      v5->z = data.point.x + v4;
      UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      return 1;
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
  }
  return 0;
}

// File Line: 988
// RVA: 0x542470
char __fastcall UFG::SimObjectUtility::PlaceOnGround(UFG::qVector3 *out, UFG::qVector3 *position, float height_above_ground, float cast_distance)
{
  float v4; // xmm4_4
  UFG::qVector3 *v5; // rbx
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  char result; // al
  float v11; // xmm0_4
  UFG::qVector3 rayStart; // [rsp+20h] [rbp-118h]
  UFG::qVector3 rayEnd; // [rsp+30h] [rbp-108h]
  UFG::RayCastData data; // [rsp+40h] [rbp-F8h]

  v4 = cast_distance;
  v5 = out;
  if ( cast_distance == 0.0 )
    v4 = FLOAT_3_0;
  v6 = position->y;
  v7 = position->z;
  v8 = position->x;
  data.mInput.m_filterInfo = 0;
  data.mInput.m_userData = 0i64;
  data.mOutput.m_shapeKeyIndex = 0;
  rayStart.y = v6;
  rayEnd.y = v6;
  data.mOutput.m_rootCollidable = 0i64;
  rayStart.x = v8;
  rayEnd.x = v8;
  data.mInput.m_enableShapeCollectionFilter.m_bool = 0;
  data.mOutput.m_hitFraction = 1.0;
  rayEnd.z = v7 - v4;
  data.mOutput.m_extraInfo = -1;
  data.mOutput.m_shapeKeys[0] = -1;
  data.mDebugName = "PlaceOnGround";
  rayStart.z = v7 + (float)(height_above_ground + 1.0);
  data.mCollisionModelName.mUID = -1;
  UFG::RayCastData::Init(&data, &rayStart, &rayEnd, 0x11u);
  if ( !UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
    return 0;
  v9 = data.point.y;
  result = 1;
  v5->x = data.point.x;
  v11 = data.point.z;
  v5->y = v9;
  v5->z = v11 + height_above_ground;
  return result;
}

// File Line: 1036
// RVA: 0x528D90
__int64 __fastcall UFG::SimObjectUtility::FindSpawnCharacterPosition(UFG::qVector3 *origin, float minRange, float maxRange, bool offscreenOnly)
{
  bool v4; // di
  float v5; // xmm6_4
  UFG::qVector3 *v6; // rbx
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  UFG::DaemonManager *v11; // rax
  unsigned __int8 v12; // bl
  __int64 v13; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 out; // [rsp+30h] [rbp-C8h]
  UFG::DaemonQueryOutput output; // [rsp+40h] [rbp-B8h]
  __int64 (__fastcall **v18)(_QWORD); // [rsp+60h] [rbp-98h]
  UFG::qVector3 v19; // [rsp+68h] [rbp-90h]
  __m128 v20; // [rsp+78h] [rbp-80h]
  __int64 v21; // [rsp+88h] [rbp-70h]
  __int64 v22; // [rsp+98h] [rbp-60h]
  __int64 v23; // [rsp+A8h] [rbp-50h]
  UFG::SpawnTraversalImmediateQuery v24; // [rsp+B8h] [rbp-40h]
  float retaddr; // [rsp+178h] [rbp+80h]
  signed int retaddr_4; // [rsp+17Ch] [rbp+84h]
  __int64 v27; // [rsp+198h] [rbp+A0h]

  v23 = -2i64;
  v4 = offscreenOnly;
  v5 = maxRange;
  v6 = origin;
  UFG::SpawnTraversalImmediateQuery::SpawnTraversalImmediateQuery((UFG::SpawnTraversalImmediateQuery *)((char *)&v24 + 8));
  output.m_id = 0;
  *(_QWORD *)&output.m_internalType = 4i64;
  output.vfptr = (UFG::DaemonQueryOutputVtbl *)&UFG::SpawnTraversalOutput::`vftable';
  v19 = UFG::qVector3::msZero;
  v18 = &UFG::HavokNavPosition::`vftable';
  v21 = -1i64;
  v20 = _mm_unpacklo_ps(
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
          _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v22 = 0i64;
  v7 = v6->y;
  v8 = v6->z;
  v24.mSearchOrigin.m_vPosition.x = v6->x;
  v24.mSearchOrigin.m_vPosition.y = v7;
  v24.mSearchOrigin.m_vPosition.z = v8;
  v24.mSearchOrigin.m_bValid = 0;
  UFG::HavokNavPosition::Validate(&v24.mSearchOrigin, 1.0, 1.0, 0.0);
  v24.mSearchRadius = UFG::qRandom(v5 - minRange, &UFG::qDefaultSeed) + minRange;
  v9 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  v10 = cosf(v9);
  v24.mSearchDirection.x = sinf(v9);
  v24.mSearchDirection.y = v10;
  v24.mSearchDirection.z = 0.0;
  v24.mRoadCost = FLOAT_50000_0;
  retaddr_4 = 65280;
  retaddr = FLOAT_0_5;
  v24.mpNavParams = (UFG::NavParams *)&retaddr;
  v11 = UFG::DaemonManager::Instance();
  UFG::DaemonManager::SubmitQuery(v11, (UFG::DaemonQueryInput *)&v24.vfptr, &output);
  if ( output.m_status != 3
    || (position = v19, v4) && UFG::SimObjectUtility::IsPositionOnScreen(&position, 2.0, 0)
    || !UFG::SimObjectUtility::PlaceOnGround(&out, &position, 0.050000001, 5.0) )
  {
    v12 = 0;
  }
  else
  {
    *(_QWORD *)v27 = *(_QWORD *)&out.x;
    *(float *)(v27 + 8) = out.z;
    v12 = 1;
  }
  v13 = v22;
  if ( v22 )
  {
    --*(_DWORD *)(v22 + 40);
    if ( !*(_DWORD *)(v13 + 40) )
      (**(void (__fastcall ***)(__int64, signed __int64))v13)(v13, 1i64);
  }
  return v12;
}

// File Line: 1089
// RVA: 0x528BD0
char __fastcall UFG::SimObjectUtility::FindSpawnBoatPosition(UFG::qVector3 *origin, float minRange, float maxRange, bool offscreenOnly, UFG::qVector3 *pResult)
{
  bool v5; // di
  UFG::qVector3 *v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm8_4
  float v9; // xmm0_4
  float v10; // xmm9_4
  float v11; // xmm8_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // ST28_4
  float v15; // ST20_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v19; // [rsp+40h] [rbp-88h]
  float v20; // [rsp+44h] [rbp-84h]
  float v21; // [rsp+48h] [rbp-80h]
  float v22; // [rsp+50h] [rbp-78h]
  float v23; // [rsp+54h] [rbp-74h]
  float v24; // [rsp+58h] [rbp-70h]
  UFG::qVector3 out; // [rsp+60h] [rbp-68h]
  UFG::qVector3 position; // [rsp+70h] [rbp-58h]

  v5 = offscreenOnly;
  v6 = origin;
  v7 = UFG::qRandom(360.0, &UFG::qDefaultSeed);
  v8 = sinf(v7);
  v9 = cosf(v7);
  v10 = (float)(maxRange - minRange) * 0.5;
  v11 = (float)(v8 * (float)(v10 + minRange)) + v6->x;
  v12 = (float)(v9 * (float)(v10 + minRange)) + v6->y;
  v13 = (float)((float)(v10 + minRange) * 0.0) + v6->z;
  v22 = v11 - v10;
  v23 = v12 - v10;
  v20 = v12 + v10;
  v24 = v13 - v10;
  v21 = v13 + v10;
  v14 = FLOAT_7_0;
  v15 = FLOAT_6_0;
  v19 = v11 + v10;
  if ( !((unsigned __int8 (__fastcall *)(UFG::NavManager *, float *, float *, signed __int64, _DWORD, _DWORD, UFG::qVector3 *))UFG::NavManager::ms_pInstance->vfptr->FindPointOnNavmesh)(
          UFG::NavManager::ms_pInstance,
          &v22,
          &v19,
          64i64,
          LODWORD(v15),
          LODWORD(v14),
          &position)
    || v5 && UFG::SimObjectUtility::IsPositionOnScreen(&position, 2.0, 0)
    || !UFG::SimObjectUtility_PlaceOnWater(&out, &position, 0.050000001, 8.0) )
  {
    return 0;
  }
  v16 = out.y;
  pResult->x = out.x;
  v17 = out.z;
  pResult->y = v16;
  pResult->z = v17;
  return 1;
}

// File Line: 1160
// RVA: 0x529020
__int64 __fastcall UFG::SimObjectUtility::FindSpawnVehicleTransformIterated(UFG::qVector3 *origin, float minRadius, float maxRadius, bool offscreenOnly)
{
  float v4; // xmm9_4
  float v5; // xmm7_4
  UFG::qVector3 *v6; // rbx
  UFG::WheeledVehicleManager *v7; // rsi
  unsigned __int8 v8; // di
  UFG::RoadNetworkResource *v9; // rax
  UFG::RoadNetworkResource *v10; // r14
  UFG::RoadNetworkSegment *v11; // rax
  __int64 v12; // r15
  UFG::RoadNetworkGraph *v13; // rax
  UFG::WayGraph *v14; // rsi
  UFG::WayTraversal *v15; // rax
  UFG::WayTraversal *v16; // rax
  float v17; // xmm10_4
  __int64 v18; // rbx
  float v19; // xmm6_4
  float v20; // xmm11_4
  __int64 v21; // rax
  unsigned __int16 v22; // di
  unsigned __int16 v23; // bx
  UFG::RoadNetworkSegment *v24; // rax
  UFG::RoadNetworkSegment *v25; // rdi
  unsigned int v26; // eax
  bool v27; // zf
  int v28; // eax
  UFG::RoadNetworkIntersection *v29; // rsi
  unsigned int v30; // ebx
  UFG::RoadNetworkConnection *v31; // rax
  UFG::RoadNetworkGate *v32; // r13
  UFG::RoadNetworkIntersection *v33; // rax
  __int64 v34; // rbx
  bool v35; // r14
  unsigned int v36; // er12
  UFG::RoadNetworkConnection *v37; // rax
  UFG::RoadNetworkConnection *v38; // rsi
  __int64 v39; // rax
  UFG::RoadNetworkConnection *v40; // r15
  unsigned int v41; // er14
  unsigned int v42; // edi
  unsigned int v43; // er12
  UFG::RoadNetworkConnection *v44; // rax
  UFG::RoadNetworkConnection *v45; // rsi
  __int64 v46; // rax
  UFG::RoadNetworkConnection *v47; // r15
  unsigned int v48; // er14
  unsigned int v49; // edi
  __int64 *v50; // rdi
  __int64 v51; // rsi
  float v52; // xmm14_4
  UFG::RoadNetworkLane *v53; // rbx
  float v54; // xmm0_4
  float v55; // xmm15_4
  float v56; // xmm8_4
  float v57; // xmm13_4
  int v58; // xmm9_4
  float *v59; // r14
  UFG::WheeledVehicleManager *v60; // rsi
  char v61; // di
  float v62; // xmm6_4
  __m128 v63; // xmm3
  float v64; // xmm5_4
  float v65; // xmm2_4
  __m128 v66; // xmm4
  float v67; // xmm4_4
  float v68; // xmm3_4
  float v69; // xmm5_4
  float v70; // xmm1_4
  float v71; // xmm6_4
  float v72; // xmm3_4
  float v73; // xmm6_4
  UFG::RoadNetworkNode *v74; // rcx
  __m128 v75; // xmm8
  __m128 v76; // xmm3
  float v77; // xmm1_4
  float v78; // xmm5_4
  float v79; // xmm7_4
  float v80; // xmm8_4
  __m128 v81; // xmm3
  float v82; // xmm3_4
  float v83; // xmm1_4
  float v84; // xmm9_4
  float v85; // xmm3_4
  float v86; // xmm10_4
  float v87; // xmm11_4
  float v88; // xmm9_4
  float v89; // xmm3_4
  float v90; // xmm3_4
  unsigned int v91; // xmm4_4
  unsigned int v92; // xmm1_4
  unsigned int v93; // xmm3_4
  float v94; // xmm9_4
  float v95; // xmm3_4
  float v96; // xmm4_4
  float v97; // xmm5_4
  float v98; // xmm2_4
  UFG::qVector4 v99; // xmm1
  UFG::qVector4 v100; // xmm2
  UFG::qVector4 v101; // xmm3
  _OWORD *v102; // rcx
  bool v104; // [rsp+30h] [rbp-90h]
  char v105; // [rsp+31h] [rbp-8Fh]
  float laneT; // [rsp+34h] [rbp-8Ch]
  int v107; // [rsp+38h] [rbp-88h]
  float v108; // [rsp+3Ch] [rbp-84h]
  UFG::qVector4 v109; // [rsp+40h] [rbp-80h]
  UFG::qVector4 v110; // [rsp+50h] [rbp-70h]
  float nearestT[4]; // [rsp+60h] [rbp-60h]
  UFG::qVector4 v112; // [rsp+70h] [rbp-50h]
  __int64 *v113; // [rsp+80h] [rbp-40h]
  __int64 v114; // [rsp+88h] [rbp-38h]
  __int64 v115; // [rsp+90h] [rbp-30h]
  UFG::RoadNetworkResource *v116; // [rsp+98h] [rbp-28h]
  UFG::RoadNetworkSegment *v117; // [rsp+A0h] [rbp-20h]
  UFG::qVector3 v118; // [rsp+A8h] [rbp-18h]
  __int64 v119; // [rsp+B8h] [rbp-8h]
  UFG::qVector3 result; // [rsp+C0h] [rbp+0h]
  UFG::WheeledVehicleManager *v121; // [rsp+D0h] [rbp+10h]
  __int64 v122; // [rsp+D8h] [rbp+18h]
  UFG::qVector3 v123; // [rsp+E0h] [rbp+20h]
  UFG::qVector3 v124; // [rsp+F0h] [rbp+30h]
  __int64 v125[12]; // [rsp+100h] [rbp+40h]
  UFG::VehicleWayFinderClient v126; // [rsp+160h] [rbp+A0h]
  __int16 v127[631]; // [rsp+5AAh] [rbp+4EAh]
  float *v128; // [rsp+AA0h] [rbp+9E0h]
  float v129; // [rsp+AA8h] [rbp+9E8h]
  float v130; // [rsp+AB0h] [rbp+9F0h]
  char v131; // [rsp+AB8h] [rbp+9F8h]
  _OWORD *v132; // [rsp+AC0h] [rbp+A00h]
  char v133; // [rsp+AC8h] [rbp+A08h]

  v122 = -2i64;
  v4 = maxRadius;
  v5 = minRadius;
  v6 = origin;
  *(UFG::qVector4 *)nearestT = UFG::qMatrix44::msIdentity.v0;
  v112 = UFG::qMatrix44::msIdentity.v1;
  v109 = UFG::qMatrix44::msIdentity.v2;
  v110 = UFG::qMatrix44::msIdentity.v3;
  nearestT[3] = UFG::qVector3::msDirFront.x;
  v112.y = UFG::qVector3::msDirFront.y;
  nearestT[0] = UFG::qVector3::msDirFront.z;
  v7 = UFG::WheeledVehicleManager::m_Instance;
  v121 = UFG::WheeledVehicleManager::m_Instance;
  v8 = 0;
  v105 = 0;
  UFG::VehicleWayFinderClient::VehicleWayFinderClient(
    (UFG::VehicleWayFinderClient *)((char *)&v126 + 64),
    0i64,
    0xFFFFFFFF);
  v126.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayTraversalClient::`vftable';
  v9 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(v7->m_NavigationData);
  v10 = v9;
  v116 = v9;
  v11 = UFG::RoadNetworkResource::GetClosestSegment(v9, v6, 0i64, 0);
  v12 = (__int64)v11;
  v117 = v11;
  LODWORD(nearestT[2]) = (_DWORD)FLOAT_1_0;
  UFG::RoadNetworkNode::GetClosestPosition((UFG::RoadNetworkNode *)&v11->mType, &result, v6, &nearestT[2]);
  v13 = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
          UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
          0);
  v14 = (UFG::WayGraph *)&v13->vfptr;
  *(_QWORD *)&v110.z = v13;
  UFG::VehicleWayFinderClient::SetRoadNetworkType(&v126, 0);
  UFG::GetWayTraversal()->pWayGraph = v14;
  v15 = UFG::GetWayTraversal();
  UFG::WayTraversal::FindConnectedEdgesInRange(v15, (UFG::WayTraversalClient *)&v126, v6, &result, minRadius, maxRadius);
  v16 = UFG::GetWayTraversal();
  UFG::WayTraversal::Service(v16, 0.0);
  v17 = v5 * v5;
  v110.x = v5 * v5;
  nearestT[1] = maxRadius * maxRadius;
  v18 = v126.m_NumWayEdges;
  v19 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
  v112.z = sinf(v19);
  v112.x = cosf(v19);
  v20 = FLOAT_N2_0;
  v108 = FLOAT_N2_0;
  v21 = 0i64;
  v114 = 0i64;
  v119 = v18;
  if ( (signed int)v18 > 0 )
  {
    do
    {
      v22 = v126.m_WayEdges[v21];
      v23 = v127[v21];
      if ( !v14->vfptr->IsEdge(v14, v23) )
      {
        v24 = UFG::RoadNetworkResource::GetSegment(v10, v22);
        v25 = v24;
        v26 = v24->mPropertyID1;
        if ( v26 )
        {
          if ( v26 != 10 )
          {
            v27 = v26 == 20 ? v133 == 0 : v26 == 750;
            if ( !v27 )
            {
              if ( v23 )
              {
                v28 = v14->vfptr->GetNumEdges(v14);
                v29 = UFG::RoadNetworkResource::GetIntersection(v10, (unsigned int)v23 - v28);
              }
              else
              {
                v29 = 0i64;
              }
              v30 = 0;
              if ( v25->mNumGates )
              {
                while ( 1 )
                {
                  v31 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v25, v30);
                  v32 = (UFG::RoadNetworkGate *)v31;
                  v33 = (UFG::RoadNetworkIntersection *)v31->mLaneList.mOffset;
                  if ( v33 )
                    v33 = (UFG::RoadNetworkIntersection *)((char *)v33 + (_QWORD)v32 + 8);
                  if ( v33 == v29 )
                    break;
                  if ( ++v30 >= (unsigned __int8)v25->mNumGates )
                    goto LABEL_81;
                }
                if ( v32 )
                {
                  v34 = 0i64;
                  v35 = v25 == (UFG::RoadNetworkSegment *)v12;
                  v104 = v25 == (UFG::RoadNetworkSegment *)v12;
                  v36 = 0;
                  if ( v32->mNumOutgoingConnections )
                  {
                    do
                    {
                      v37 = UFG::RoadNetworkGate::GetOutgoingConnection(v32, v36);
                      v38 = v37;
                      v39 = v37->mConnection.mOffset;
                      if ( v39 )
                      {
                        v40 = (UFG::RoadNetworkConnection *)((char *)v38 + v39 + 16);
                        if ( v40 )
                        {
                          v41 = 0;
                          if ( v40->mNumLanes )
                          {
                            do
                            {
                              UFG::qBezierPathCollectionMemImaged::GetPath(v40, v41);
                              v42 = 0;
                              if ( v38->mNumLanes )
                              {
                                do
                                {
                                  if ( (unsigned int)v34 < 0xC )
                                  {
                                    v125[v34] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v38, v42);
                                    v34 = (unsigned int)(v34 + 1);
                                  }
                                  ++v42;
                                }
                                while ( v42 < v38->mNumLanes );
                              }
                              ++v41;
                            }
                            while ( v41 < v40->mNumLanes );
                          }
                        }
                      }
                      ++v36;
                    }
                    while ( v36 < v32->mNumOutgoingConnections );
                    v35 = v104;
                  }
                  if ( v35 )
                  {
                    v43 = 0;
                    if ( v32->mNumIncomingConnections )
                    {
                      do
                      {
                        v44 = UFG::RoadNetworkGate::GetIncomingConnection(v32, v43);
                        v45 = v44;
                        v46 = v44->mConnection.mOffset;
                        if ( v46 )
                        {
                          v47 = (UFG::RoadNetworkConnection *)((char *)v45 + v46 + 16);
                          if ( v47 )
                          {
                            v48 = 0;
                            if ( v47->mNumLanes )
                            {
                              do
                              {
                                UFG::qBezierPathCollectionMemImaged::GetPath(v47, v48);
                                v49 = 0;
                                if ( v45->mNumLanes )
                                {
                                  do
                                  {
                                    if ( (unsigned int)v34 < 0xC )
                                    {
                                      v125[v34] = (__int64)UFG::qBezierPathCollectionMemImaged::GetPath(v45, v49);
                                      v34 = (unsigned int)(v34 + 1);
                                    }
                                    ++v49;
                                  }
                                  while ( v49 < v45->mNumLanes );
                                }
                                ++v48;
                              }
                              while ( v48 < v47->mNumLanes );
                            }
                          }
                        }
                        ++v43;
                      }
                      while ( v43 < v32->mNumIncomingConnections );
                      v35 = v104;
                    }
                  }
                  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
                  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
                  if ( (_DWORD)v34 )
                  {
                    v50 = v125;
                    v113 = v125;
                    v51 = (unsigned int)v34;
                    v115 = (unsigned int)v34;
                    do
                    {
                      v52 = 0.0;
                      v53 = (UFG::RoadNetworkLane *)*v50;
                      v54 = UFG::RoadNetworkLane::GetLength((UFG::RoadNetworkLane *)*v50);
                      v55 = *(float *)&FLOAT_1_0;
                      v56 = 1.0 / v54;
                      v110.y = 1.0 / v54;
                      if ( v35 )
                      {
                        laneT = 0.0;
                        UFG::RoadNetworkLane::GetNearestPoint(v53, &v123, &result, &laneT);
                        UFG::RoadNetworkLane::GetPos(v53, &v124, laneT);
                        v55 = laneT;
                      }
                      v57 = 0.0;
                      if ( v55 > 0.0 )
                      {
                        *(float *)&v58 = v4 - v5;
                        v107 = v58;
                        v59 = v128;
                        v60 = v121;
                        v61 = v131;
                        do
                        {
                          UFG::RoadNetworkLane::GetPos(v53, (UFG::qVector3 *)&v109, v57);
                          v62 = v109.z - v59[2];
                          v63 = (__m128)LODWORD(v109.y);
                          v63.m128_f32[0] = v109.y - v59[1];
                          v64 = v109.x - *v59;
                          v65 = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v64 * v64))
                              + (float)(v62 * v62);
                          v66 = v63;
                          v66.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v64 * v64))
                                          + (float)(v62 * v62);
                          if ( v66.m128_f32[0] == 0.0 )
                            v67 = 0.0;
                          else
                            v67 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v66));
                          v68 = v63.m128_f32[0] * v67;
                          v69 = v64 * v67;
                          v70 = (float)(v67 * v62) * nearestT[0];
                          v71 = (float)((float)((float)((float)(v69 * v112.x) + (float)(v68 * v112.z)) + v70) + 1.0)
                              * 0.5;
                          v72 = (float)((float)((float)((float)(v68 * v112.y) + (float)(v69 * nearestT[3])) + v70) + 1.5)
                              * 0.40000001;
                          v5 = v129;
                          if ( v65 >= v17
                            && v65 <= (float)((float)((float)(*(float *)&v58 * v72) + v129)
                                            * (float)((float)(*(float *)&v58 * v72) + v129)) )
                          {
                            v73 = (float)(v71 + 100.0) + (float)((float)(v65 - v17) / (float)(nearestT[1] - v17));
                            if ( v73 > v20 )
                            {
                              if ( v53->mNode.mOffset )
                                v74 = (UFG::RoadNetworkNode *)((char *)v53 + v53->mNode.mOffset);
                              else
                                v74 = 0i64;
                              UFG::RoadNetworkNode::GetTangent(v74, &v118, v53->mLaneIndex, v57);
                              v75 = (__m128)LODWORD(v118.x);
                              v76 = v75;
                              v76.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0])
                                                      + (float)(v118.y * v118.y))
                                              + (float)(v118.z * v118.z);
                              if ( v76.m128_f32[0] == 0.0 )
                                v77 = 0.0;
                              else
                                v77 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v76));
                              v78 = v118.z * v77;
                              v79 = v118.y * v77;
                              v80 = v118.x * v77;
                              nearestT[0] = v118.x * v77;
                              nearestT[1] = v118.y * v77;
                              nearestT[2] = v118.z * v77;
                              nearestT[3] = 0.0;
                              v81 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
                              v81.m128_f32[0] = (float)((float)(v81.m128_f32[0] * v81.m128_f32[0])
                                                      + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                                              + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
                              if ( v81.m128_f32[0] == 0.0 )
                                v82 = 0.0;
                              else
                                v82 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v81));
                              v83 = v82 * UFG::qVector3::msDirUp.z;
                              v84 = v82 * UFG::qVector3::msDirUp.y;
                              v85 = v82 * UFG::qVector3::msDirUp.x;
                              v86 = (float)(v85 * v79) - (float)(v80 * v84);
                              v87 = (float)(v80 * v83) - (float)(v85 * v78);
                              v88 = (float)(v84 * v78) - (float)(v83 * v79);
                              v89 = (float)((float)(v88 * v88) + (float)(v87 * v87)) + (float)(v86 * v86);
                              if ( v89 == 0.0 )
                                v90 = 0.0;
                              else
                                v90 = 1.0 / fsqrt(v89);
                              *(float *)&v91 = v90 * v86;
                              *(float *)&v92 = v90 * v87;
                              *(float *)&v93 = v90 * v88;
                              *(_QWORD *)&v112.x = __PAIR__(v92, v93);
                              *(_QWORD *)&v112.z = v91;
                              v94 = (float)(*(float *)&v92 * v80) - (float)(*(float *)&v93 * v79);
                              v95 = (float)(*(float *)&v93 * v78) - (float)(*(float *)&v91 * v80);
                              v96 = (float)(*(float *)&v91 * v79) - (float)(*(float *)&v92 * v78);
                              v97 = (float)((float)(v96 * v96) + (float)(v95 * v95)) + (float)(v94 * v94);
                              if ( v97 == 0.0 )
                                v98 = 0.0;
                              else
                                v98 = 1.0 / fsqrt(v97);
                              v109.x = v96 * v98;
                              v109.y = v98 * v95;
                              v109.z = v98 * v94;
                              v109.w = 0.0;
                              v110.x = v96 * v98;
                              v110.y = v98 * v95;
                              v110.z = v98 * v94;
                              v110.w = 1.0;
                              if ( v61 && UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v109, 2.0, 0)
                                || !UFG::WheeledVehicleManager::CheckSpawnLocationSimple(v60, (UFG::qVector3 *)&v109) )
                              {
                                v73 = 0.0;
                                v20 = v108;
                              }
                              else
                              {
                                v20 = v73;
                                v108 = v73;
                                v105 = 1;
                              }
                              v5 = v129;
                              v17 = v110.x;
                              v58 = v107;
                              v56 = v110.y;
                            }
                            if ( v73 > v52 )
                              v52 = v73;
                          }
                          v57 = v57 + v56;
                        }
                        while ( v57 < v55 );
                        v4 = v130;
                        v50 = v113;
                        v51 = v115;
                        v35 = v104;
                      }
                      ++v50;
                      v113 = v50;
                      v115 = --v51;
                    }
                    while ( v51 );
                  }
                  v12 = (__int64)v117;
                  v10 = v116;
                }
              }
LABEL_81:
              v14 = *(UFG::WayGraph **)&v110.z;
            }
          }
        }
      }
      v21 = v114 + 1;
      v114 = v21;
    }
    while ( v21 < v119 );
    v8 = v105;
    if ( v105 )
    {
      v99 = v112;
      v100 = v109;
      v101 = v110;
      v102 = v132;
      *v132 = *(_OWORD *)nearestT;
      v102[1] = v99;
      v102[2] = v100;
      v102[3] = v101;
    }
  }
  return v8;
}

// File Line: 1590
// RVA: 0x528BC0
UFG::qVector3 *__fastcall UFG::SimObjectUtility::FindRandomSidewalkPosition(UFG::qVector3 *origin, float minRange, float maxRange, bool offscreenOnly, UFG::qVector3 *pResult)
{
  UFG::qVector3 *result; // rax

  result = pResult;
  JUMPOUT(pResult, 0i64, UFG::AISidewalkGraph::FindNodeLocationInRange);
  return result;
}

// File Line: 1600
// RVA: 0x539A90
char __fastcall UFG::SimObjectUtility::IsClassType(UFG::SimObject *pSimObject, UFG::qSymbol *targetClassType)
{
  UFG::qSymbol *v2; // rsi
  UFG::SimObject *v3; // rdi
  UFG::qPropertySet *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  unsigned int v10; // ecx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SceneObjectProperties *v13; // rax

  v2 = targetClassType;
  v3 = pSimObject;
  UFG::qGetTicks();
  v4 = 0i64;
  if ( !v3 )
    return UFG::SimObjectUtility::IsClassType(v4, v2);
  v5 = v3->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v3->m_Components.p[3].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v3->m_Components.p[4].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v3[1].vfptr;
      v8 = v3->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_14:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v3->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_14;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v3, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v3->m_Components.p[3].m_pComponent;
  }
  if ( !v6 )
  {
    v13 = v3->m_pSceneObj;
    if ( v13 )
    {
      v4 = v13->mpWritableProperties;
      if ( !v4 )
        v4 = v13->mpConstProperties;
    }
    return UFG::SimObjectUtility::IsClassType(v4, v2);
  }
  v10 = (unsigned int)v6[2].m_SafePointerList.mNode.mPrev;
  if ( v10 )
  {
    v11 = v6[2].m_SafePointerList.mNode.mNext;
    while ( v2->mUID != LODWORD(v11->mPrev) )
    {
      LODWORD(v4) = (_DWORD)v4 + 1;
      v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)v11 + 4);
      if ( (unsigned int)v4 >= v10 )
        goto LABEL_22;
    }
  }
  else
  {
LABEL_22:
    LODWORD(v4) = -1;
  }
  return (signed int)v4 >= 0;
}

// File Line: 1619
// RVA: 0x52B140
__int64 __fastcall UFG::SimObjectUtility::GetClassTypes(UFG::qPropertySet *pPropertySet, UFG::qSymbol *classTypes, unsigned int maxClassTypes)
{
  UFG::qSymbol *v3; // rbx
  UFG::qPropertySet *v4; // rax
  char *v5; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::qPropertyList *v8; // rcx
  unsigned int v9; // esi
  UFG::qSymbol *v10; // rax
  signed __int64 v11; // rdi
  __int64 v12; // rdx
  unsigned int v13; // ecx

  v3 = classTypes;
  v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pPropertySet,
         (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( !v4 )
    return 0i64;
  v5 = UFG::qPropertySet::GetMemImagePtr(v4);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v7 = *((_QWORD *)v5 + 1);
  if ( !v7 )
    return 0i64;
  v8 = (UFG::qPropertyList *)&v6[v7 + 8];
  if ( !v8 )
    return 0i64;
  v9 = v8->mNumElements;
  if ( v9 )
  {
    v10 = UFG::qPropertyList::Get<UFG::qSymbol>(v8, 0);
    if ( v9 )
    {
      v11 = (char *)v10 - (char *)v3;
      v12 = v9;
      do
      {
        v13 = *(unsigned int *)((char *)&v3->mUID + v11);
        ++v3;
        v3[-1].mUID = v13;
        --v12;
      }
      while ( v12 );
    }
  }
  return v9;
}

// File Line: 1642
// RVA: 0x539C00
char __fastcall UFG::SimObjectUtility::IsClassType(UFG::qPropertySet *pPropertySet, UFG::qSymbol *targetClassType)
{
  UFG::qSymbol *v2; // rsi
  UFG::qPropertySet *v3; // rax
  char *v4; // rax
  char *v5; // rcx
  __int64 v6; // rax
  UFG::qPropertyList *v7; // rcx
  unsigned int v8; // edi
  int v9; // ebx
  UFG::qSymbol *v10; // rcx

  v2 = targetClassType;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         pPropertySet,
         (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( !v3 )
    return 0;
  v4 = UFG::qPropertySet::GetMemImagePtr(v3);
  v5 = v4;
  if ( !v4 )
    return 0;
  v6 = *((_QWORD *)v4 + 1);
  if ( !v6 )
    return 0;
  v7 = (UFG::qPropertyList *)&v5[v6 + 8];
  if ( !v7 )
    return 0;
  v8 = v7->mNumElements;
  v9 = 0;
  v10 = v8 ? UFG::qPropertyList::Get<UFG::qSymbol>(v7, 0) : 0i64;
  if ( !v8 )
    return 0;
  while ( v10[v9].mUID != v2->mUID )
  {
    if ( ++v9 >= v8 )
      return 0;
  }
  return 1;
}

// File Line: 1666
// RVA: 0x539CB0
char __fastcall UFG::SimObjectUtility::IsClassTypeInArray(UFG::SimObject *pSimObject, UFG::qArray<UFG::qSymbol,0> *array)
{
  __int64 v2; // rbx
  UFG::qArray<UFG::qSymbol,0> *v3; // r14
  UFG::SimObject *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // r10
  unsigned int v7; // er8
  unsigned int v8; // er9
  signed __int64 v9; // rdx
  __int64 v10; // r9
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::SceneObjectProperties *v15; // rax
  UFG::qPropertySet *v16; // rcx
  UFG::qPropertySet *v17; // rax
  char *v18; // rax
  char *v19; // rcx
  __int64 v20; // rax
  UFG::qPropertyList *v21; // rbp
  unsigned int v22; // esi
  unsigned int v23; // edi
  UFG::qSymbol *v24; // rax
  __int64 v25; // rcx
  unsigned int v26; // edx
  UFG::qSymbol *v27; // rax

  v2 = array->size;
  v3 = array;
  v4 = pSimObject;
  if ( !(_DWORD)v2 || !pSimObject )
    return 0;
  v5 = pSimObject->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[3].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v6 = v4->m_Components.p[4].m_pComponent;
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = (unsigned int)v4[1].vfptr;
      v8 = v4->m_Components.size;
      if ( v7 >= v8 )
      {
LABEL_15:
        v6 = 0i64;
      }
      else
      {
        v9 = (signed __int64)&v4->m_Components.p[v7];
        while ( (*(_DWORD *)(v9 + 8) & 0xFE000000) != (UFG::SimObjectPropertiesComponent::_TypeUID & 0xFE000000)
             || UFG::SimObjectPropertiesComponent::_TypeUID & ~*(_DWORD *)(v9 + 8) & 0x1FFFFFF )
        {
          ++v7;
          v9 += 16i64;
          if ( v7 >= v8 )
            goto LABEL_15;
        }
        v6 = *(UFG::SimComponent **)v9;
      }
    }
    else
    {
      v6 = UFG::SimObject::GetComponentOfType(v4, UFG::SimObjectPropertiesComponent::_TypeUID);
    }
  }
  else
  {
    v6 = v4->m_Components.p[3].m_pComponent;
  }
  if ( !v6 )
  {
    v15 = v4->m_pSceneObj;
    if ( v15 )
    {
      v16 = v15->mpWritableProperties;
      if ( !v16 )
        v16 = v15->mpConstProperties;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v16,
            (UFG::qSymbol *)&schema_classlist::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v17 )
    {
      v18 = UFG::qPropertySet::GetMemImagePtr(v17);
      v19 = v18;
      if ( v18 )
      {
        v20 = *((_QWORD *)v18 + 1);
        if ( v20 )
        {
          v21 = (UFG::qPropertyList *)&v19[v20 + 8];
          if ( v21 )
          {
            v22 = v21->mNumElements;
            v23 = 0;
            if ( v22 )
            {
              while ( 1 )
              {
                v24 = UFG::qPropertyList::Get<UFG::qSymbol>(v21, v23);
                v25 = 0i64;
                if ( v2 > 0 )
                  break;
LABEL_43:
                if ( ++v23 >= v22 )
                  return 0;
              }
              v26 = v24->mUID;
              v27 = v3->p;
              while ( v27->mUID != v26 )
              {
                ++v25;
                ++v27;
                if ( v25 >= v2 )
                  goto LABEL_43;
              }
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }
  v10 = 0i64;
  if ( v2 <= 0 )
    return 0;
  v11 = (unsigned int)v6[2].m_SafePointerList.mNode.mPrev;
  while ( 1 )
  {
    v12 = 0;
    if ( v11 )
    {
      v13 = v6[2].m_SafePointerList.mNode.mNext;
      while ( v3->p[v10].mUID != LODWORD(v13->mPrev) )
      {
        ++v12;
        v13 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)((char *)v13 + 4);
        if ( v12 >= v11 )
          goto LABEL_27;
      }
      if ( (v12 & 0x80000000) == 0 )
        return 1;
    }
LABEL_27:
    if ( ++v10 >= v2 )
      return 0;
  }
})
          goto LABEL_27;
      }
      if ( (v12 & 0x80000000) == 0 )
        return 1;
    }
LABEL_27:
    if ( ++v10 >= v2 )
      re

// File Line: 1711
// RVA: 0x528680
UFG::qPropertySet *__fastcall UFG::SimObjectUtility::FindDriverProfile(UFG::qPropertySet *vehiclePropertySet)
{
  UFG::qPropertyList *v2; // rax
  UFG::qPropertyList *v3; // rbx
  unsigned int v4; // eax
  UFG::qSymbol *v5; // rax

  if ( !vehiclePropertySet )
    return 0i64;
  v2 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         vehiclePropertySet,
         (UFG::qSymbol *)&qSymbol_DriverProfileList.mUID,
         DEPTH_RECURSE);
  v3 = v2;
  if ( !v2 || !v2->mNumElements )
    return 0i64;
  v4 = UFG::qPropertyList::GetRandomIndex(v2);
  v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v3, v4);
  return UFG::PropertySetManager::FindPropertySet(v5);
}

// File Line: 1741
// RVA: 0x523EE0
void __fastcall UFG::SimObjectUtility::CreateAndAttachProp(UFG::qPropertySet *propertySet, UFG::SimObject *attachTo, bool deletePhysicsFails)
{
  bool v3; // r12
  UFG::SimObjectProp *v4; // rsi
  UFG::qPropertySet *v5; // r14
  UFG::qSymbol *v6; // rax
  Creature *v7; // rdi
  UFG::StreamedResourceComponent *v8; // rbx
  unsigned __int16 v9; // cx
  unsigned int v10; // er8
  unsigned int v11; // er10
  signed __int64 v12; // rdx
  UFG::qSymbol *v13; // rax
  UFG::qPropertySet *v14; // r15
  UFG::SimObjectProp *v15; // rax
  UFG::SimObjectProp *v16; // rbx
  UFG::CharacterAnimationComponent *v17; // r14
  UFG::SimComponent *v18; // rax
  unsigned __int16 v19; // cx
  UFG::CharacterAnimationComponent *v20; // rax
  unsigned int v21; // er8
  unsigned int v22; // er10
  signed __int64 v23; // rdx
  unsigned __int16 v24; // cx
  unsigned int v25; // er8
  unsigned int v26; // er10
  signed __int64 v27; // rdx
  unsigned int v28; // er8
  unsigned int v29; // er10
  unsigned int v30; // er8
  unsigned int v31; // er10
  unsigned int v32; // er8
  unsigned int v33; // er10
  UFG::qResourceData *v34; // rcx
  UFG::qVector3 *v35; // r12
  UFG::qVector3 *v36; // r13
  UFG::qVector3 *v37; // r15
  float v38; // xmm1_4
  float v39; // xmm1_4
  unsigned __int16 v40; // cx
  UFG::CharacterAnimationComponent *v41; // rcx
  UFG::CharacterAnimationComponent *v42; // rax
  unsigned int v43; // er8
  unsigned int v44; // er10
  signed __int64 v45; // rdx
  Creature *v46; // rsi
  int v47; // er14
  int v48; // edi
  float v49; // xmm1_4
  float v50; // xmm0_4
  UFG::qVector3 radians; // [rsp+30h] [rbp-D0h]
  UFG::qMatrix44 rot; // [rsp+40h] [rbp-C0h]
  UFG::qMatrix44 relativeTransform; // [rsp+80h] [rbp-80h]
  char dest; // [rsp+C0h] [rbp-40h]
  UFG::SpawnInfoInterface::SpawnPriority priority; // [rsp+180h] [rbp+80h]
  UFG::qSymbol objName; // [rsp+188h] [rbp+88h]
  UFG::qSymbol result; // [rsp+198h] [rbp+98h]

  v3 = deletePhysicsFails;
  v4 = (UFG::SimObjectProp *)attachTo;
  v5 = propertySet;
  UFG::qSPrintf(&dest, "attachableProp:%x", propertySet->mName.mUID);
  v6 = UFG::qSymbol::create_from_string(&result, &dest);
  UFG::SimObjectUtility::GenerateUniqueActorName(&objName, v6);
  v7 = 0i64;
  if ( !v4 )
    goto LABEL_127;
  v9 = v4->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v8 = (UFG::StreamedResourceComponent *)v4->m_Components.p[10].m_pComponent;
    goto LABEL_18;
  }
  if ( (v9 & 0x8000u) != 0 )
  {
    v8 = (UFG::StreamedResourceComponent *)v4->m_Components.p[10].m_pComponent;
    goto LABEL_18;
  }
  if ( (v9 >> 13) & 1 )
  {
    v8 = (UFG::StreamedResourceComponent *)v4->m_Components.p[7].m_pComponent;
    goto LABEL_18;
  }
  if ( !((v9 >> 12) & 1) )
  {
    v8 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             UFG::StreamedResourceComponent::_TypeUID);
    goto LABEL_18;
  }
  v10 = v4->mComponentTableEntryCount;
  v11 = v4->m_Components.size;
  if ( v10 < v11 )
  {
    v12 = (signed __int64)&v4->m_Components.p[v10];
    while ( (*(_DWORD *)(v12 + 8) & 0xFE000000) != (UFG::StreamedResourceComponent::_TypeUID & 0xFE000000)
         || UFG::StreamedResourceComponent::_TypeUID & ~*(_DWORD *)(v12 + 8) & 0x1FFFFFF )
    {
      ++v10;
      v12 += 16i64;
      if ( v10 >= v11 )
      {
        v8 = 0i64;
        goto LABEL_18;
      }
    }
    v8 = *(UFG::StreamedResourceComponent **)v12;
  }
  else
  {
LABEL_127:
    v8 = 0i64;
  }
LABEL_18:
  priority = 0;
  UFG::StreamedResourceComponent::GetSpawnPriority(v8, &priority);
  v13 = UFG::qPropertySet::Get<UFG::qSymbol>(v5, (UFG::qSymbol *)&qSymbol_AttachOffset.mUID, DEPTH_RECURSE);
  v14 = 0i64;
  if ( v13 )
  {
    v14 = UFG::StreamedResourceComponent::GetAssetPropertySet(v8, v13);
    if ( !v14 )
      return;
  }
  v15 = (UFG::SimObjectProp *)UFG::SpawnInfoInterface::SpawnObject(&objName, v5, priority, 0i64, 0i64, 0i64);
  v16 = v15;
  if ( !v15 )
  {
    v17 = 0i64;
LABEL_22:
    v18 = 0i64;
    goto LABEL_75;
  }
  v19 = v15->m_Flags;
  if ( (v19 >> 14) & 1 )
  {
    v17 = (UFG::CharacterAnimationComponent *)v15->m_Components.p[9].m_pComponent;
    if ( !v17
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_27;
    }
    goto LABEL_45;
  }
  if ( (v19 & 0x8000u) != 0 )
  {
    v17 = (UFG::CharacterAnimationComponent *)v15->m_Components.p[9].m_pComponent;
    if ( !v17 || (UFG::CharacterAnimationComponent::_TypeUID ^ v17->m_TypeUID) & 0xFE000000 )
      goto LABEL_27;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v17->m_TypeUID & 0x1FFFFFF )
      v17 = 0i64;
    goto LABEL_45;
  }
  if ( (v19 >> 13) & 1 )
  {
    v20 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v15);
LABEL_44:
    v17 = v20;
    goto LABEL_45;
  }
  if ( !((v19 >> 12) & 1) )
  {
    v20 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v15->vfptr,
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
  v23 = (signed __int64)&v15->m_Components.p[v21];
  while ( (*(_DWORD *)(v23 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v23 + 8) & 0x1FFFFFF )
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
  if ( (v24 >> 14) & 1 )
  {
    v25 = v16->mComponentTableEntryCount;
    v26 = v16->m_Components.size;
    if ( v25 >= v26 )
      goto LABEL_22;
    v27 = (signed __int64)&v16->m_Components.p[v25];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
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
  if ( (v24 & 0x8000u) != 0 )
  {
    v28 = v16->mComponentTableEntryCount;
    v29 = v16->m_Components.size;
    if ( v28 >= v29 )
      goto LABEL_22;
    v27 = (signed __int64)&v16->m_Components.p[v28];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
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
  if ( (v24 >> 13) & 1 )
  {
    v30 = v16->mComponentTableEntryCount;
    v31 = v16->m_Components.size;
    if ( v30 >= v31 )
      goto LABEL_22;
    v27 = (signed __int64)&v16->m_Components.p[v30];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
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
  if ( (v24 >> 12) & 1 )
  {
    v32 = v16->mComponentTableEntryCount;
    v33 = v16->m_Components.size;
    if ( v32 >= v33 )
      goto LABEL_22;
    v27 = (signed __int64)&v16->m_Components.p[v32];
    while ( (*(_DWORD *)(v27 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
         || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v27 + 8) & 0x1FFFFFF )
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
  v18 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::RigidBodyComponent::_TypeUID);
LABEL_75:
  if ( v3 )
  {
    if ( v17 )
    {
      v34 = v17->mRigHandle.mData;
      if ( v34 )
      {
        if ( *(_DWORD *)&v34[1].mDebugName[4] > 0u && !v18 )
          goto LABEL_128;
      }
    }
  }
  if ( !v16 )
    return;
  if ( !UFG::InventoryComponent::Equip((UFG::SimObject *)&v4->vfptr, (UFG::SimObject *)&v16->vfptr) )
  {
LABEL_128:
    UFG::SimObject::Destroy((UFG::SimObject *)&v16->vfptr);
    return;
  }
  if ( !v14 )
    return;
  relativeTransform = UFG::qMatrix44::msIdentity;
  v35 = UFG::qPropertySet::Get<UFG::qVector3>(v14, (UFG::qSymbol *)&qSymbol_Scale.mUID, DEPTH_RECURSE);
  v36 = UFG::qPropertySet::Get<UFG::qVector3>(v14, (UFG::qSymbol *)&qSymbol_Rotation.mUID, DEPTH_RECURSE);
  v37 = UFG::qPropertySet::Get<UFG::qVector3>(v14, (UFG::qSymbol *)&qSymbol_Translation.mUID, DEPTH_RECURSE);
  if ( v36 )
  {
    v38 = v36->x;
    rot = UFG::qMatrix44::msIdentity;
    radians.z = (float)(v38 * -3.1415927) * 0.0055555557;
    radians.x = (float)(v36->z * 3.1415927) * 0.0055555557;
    radians.y = (float)(v36->y * 3.1415927) * 0.0055555557;
    UFG::qRotationMatrixXYZDepreciated(&rot, &radians);
    UFG::qMatrix44::operator*=(&relativeTransform, &rot);
  }
  if ( v37 )
  {
    v39 = v37->y;
    rot = UFG::qMatrix44::msIdentity;
    radians.y = v39;
    radians.x = v37->z;
    LODWORD(radians.z) = LODWORD(v37->x) ^ _xmm[0];
    UFG::qTranslationMatrix(&rot, &radians);
    UFG::qMatrix44::operator*=(&relativeTransform, &rot);
  }
  if ( !v4 )
    goto LABEL_112;
  v40 = v4->m_Flags;
  if ( (v40 >> 14) & 1 )
  {
    v41 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v41
      || (UFG::CharacterAnimationComponent::_TypeUID ^ v41->m_TypeUID) & 0xFE000000
      || UFG::CharacterAnimationComponent::_TypeUID & ~v41->m_TypeUID & 0x1FFFFFF )
    {
      goto LABEL_92;
    }
    goto LABEL_110;
  }
  if ( (v40 & 0x8000u) != 0 )
  {
    v41 = (UFG::CharacterAnimationComponent *)v4->m_Components.p[9].m_pComponent;
    if ( !v41 || (UFG::CharacterAnimationComponent::_TypeUID ^ v41->m_TypeUID) & 0xFE000000 )
      goto LABEL_92;
    if ( UFG::CharacterAnimationComponent::_TypeUID & ~v41->m_TypeUID & 0x1FFFFFF )
      v41 = 0i64;
    goto LABEL_110;
  }
  if ( (v40 >> 13) & 1 )
  {
    v42 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v4);
LABEL_109:
    v41 = v42;
    goto LABEL_110;
  }
  if ( !((v40 >> 12) & 1) )
  {
    v42 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v4->vfptr,
                                                UFG::CharacterAnimationComponent::_TypeUID);
    goto LABEL_109;
  }
  v43 = v4->mComponentTableEntryCount;
  v44 = v4->m_Components.size;
  if ( v43 >= v44 )
  {
LABEL_92:
    v41 = 0i64;
    goto LABEL_110;
  }
  v45 = (signed __int64)&v4->m_Components.p[v43];
  while ( (*(_DWORD *)(v45 + 8) & 0xFE000000) != (UFG::CharacterAnimationComponent::_TypeUID & 0xFE000000)
       || UFG::CharacterAnimationComponent::_TypeUID & ~*(_DWORD *)(v45 + 8) & 0x1FFFFFF )
  {
    ++v43;
    v45 += 16i64;
    if ( v43 >= v44 )
    {
      v41 = 0i64;
      goto LABEL_110;
    }
  }
  v41 = *(UFG::CharacterAnimationComponent **)v45;
LABEL_110:
  if ( !v41 )
  {
LABEL_112:
    v46 = 0i64;
    goto LABEL_113;
  }
  v46 = v41->mCreature;
LABEL_113:
  if ( v17 )
    v7 = v17->mCreature;
  if ( v46 && v7 )
  {
    *(_QWORD *)&radians.x = -1i64;
    UFG::InventoryComponent::EquipInfo::init(
      (UFG::InventoryComponent::EquipInfo *)&radians,
      (UFG::SimObject *)&v16->vfptr,
      0,
      0);
    v47 = -1;
    if ( v7->mPose.mRigHandle.mData )
      v48 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, LODWORD(radians.x));
    else
      v48 = -1;
    if ( v46->mPose.mRigHandle.mData )
      v47 = Skeleton::GetBoneID(v46->mPose.mRigHandle.mUFGSkeleton, LODWORD(radians.y));
    Creature::AddRelativeTransform(v46, v47, (UFG::SimObject *)&v16->vfptr, v48, &relativeTransform);
    if ( v35 )
    {
      v49 = v35->y;
      radians.x = v35->z;
      v50 = v35->x;
      radians.y = v49;
      radians.z = v50;
      Creature::AddRelativeScale(v46, v47, (UFG::SimObject *)&v16->vfptr, v48, &radians);
    }
  }
}

// File Line: 1865
// RVA: 0x53AC30
char __fastcall UFG::SimObjectUtility::IsInWater(UFG::SimObject *pSimObject)
{
  UFG::SimObject *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::SimObject *v3; // rdi
  UFG::CharacterPhysicsComponent *v4; // rax
  unsigned int v5; // er8
  unsigned int v6; // er9
  signed __int64 v7; // rdx
  unsigned int v8; // er8
  unsigned int v9; // er9
  unsigned int v10; // er8
  unsigned int v11; // er9
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rax
  unsigned int v15; // er8
  unsigned int v16; // er9
  signed __int64 v17; // rdx
  unsigned int v18; // er8
  unsigned int v19; // er9
  unsigned int v20; // er8
  unsigned int v21; // er9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v22; // rcx

  v1 = pSimObject;
  if ( !pSimObject )
    return 0;
  v2 = pSimObject->m_Flags;
  v3 = 0i64;
  if ( !((v2 >> 14) & 1) )
  {
    if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v8 = (unsigned int)v1[1].vfptr;
        v9 = v1->m_Components.size;
        if ( v8 < v9 )
        {
          v7 = (signed __int64)&v1->m_Components.p[v8];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v8;
            v7 += 16i64;
            if ( v8 >= v9 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( !((v2 >> 12) & 1) )
        {
          v4 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                   v1,
                                                   UFG::CharacterPhysicsComponent::_TypeUID);
          goto LABEL_27;
        }
        v10 = (unsigned int)v1[1].vfptr;
        v11 = v1->m_Components.size;
        if ( v10 < v11 )
        {
          v7 = (signed __int64)&v1->m_Components.p[v10];
          while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
          {
            ++v10;
            v7 += 16i64;
            if ( v10 >= v11 )
            {
              v4 = 0i64;
              goto LABEL_27;
            }
          }
          goto LABEL_11;
        }
      }
    }
    else
    {
      v5 = (unsigned int)v1[1].vfptr;
      v6 = v1->m_Components.size;
      if ( v5 < v6 )
      {
        v7 = (signed __int64)&v1->m_Components.p[v5];
        while ( (*(_DWORD *)(v7 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v7 + 8) & 0x1FFFFFF )
        {
          ++v5;
          v7 += 16i64;
          if ( v5 >= v6 )
            goto LABEL_10;
        }
LABEL_11:
        v4 = *(UFG::CharacterPhysicsComponent **)v7;
        goto LABEL_27;
      }
    }
LABEL_10:
    v4 = 0i64;
    goto LABEL_27;
  }
  v4 = (UFG::CharacterPhysicsComponent *)v1->m_Components.p[27].m_pComponent;
LABEL_27:
  if ( v4 && UFG::CharacterPhysicsComponent::IsInWater(v4) )
    return 1;
  v13 = v1->m_Flags;
  if ( (v13 >> 14) & 1 )
  {
    v14 = v1->m_Components.p[44].m_pComponent;
    goto LABEL_55;
  }
  if ( (v13 & 0x8000u) != 0 )
  {
    v15 = (unsigned int)v1[1].vfptr;
    v16 = v1->m_Components.size;
    if ( v15 < v16 )
    {
      v17 = (signed __int64)&v1->m_Components.p[v15];
      while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
      {
        ++v15;
        v17 += 16i64;
        if ( v15 >= v16 )
          goto LABEL_38;
      }
LABEL_39:
      v14 = *(UFG::SimComponent **)v17;
      goto LABEL_55;
    }
    goto LABEL_38;
  }
  if ( (v13 >> 13) & 1 )
  {
    v18 = (unsigned int)v1[1].vfptr;
    v19 = v1->m_Components.size;
    if ( v18 < v19 )
    {
      v17 = (signed __int64)&v1->m_Components.p[v18];
      while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
      {
        ++v18;
        v17 += 16i64;
        if ( v18 >= v19 )
        {
          v14 = 0i64;
          goto LABEL_55;
        }
      }
      goto LABEL_39;
    }
LABEL_38:
    v14 = 0i64;
    goto LABEL_55;
  }
  if ( (v13 >> 12) & 1 )
  {
    v20 = (unsigned int)v1[1].vfptr;
    v21 = v1->m_Components.size;
    if ( v20 < v21 )
    {
      v17 = (signed __int64)&v1->m_Components.p[v20];
      while ( (*(_DWORD *)(v17 + 8) & 0xFE000000) != (UFG::CharacterOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::CharacterOccupantComponent::_TypeUID & ~*(_DWORD *)(v17 + 8) & 0x1FFFFFF )
      {
        ++v20;
        v17 += 16i64;
        if ( v20 >= v21 )
        {
          v14 = 0i64;
          goto LABEL_55;
        }
      }
      goto LABEL_39;
    }
    goto LABEL_38;
  }
  v14 = UFG::SimObject::GetComponentOfType(v1, UFG::CharacterOccupantComponent::_TypeUID);
LABEL_55:
  if ( !v14 )
    return 0;
  v22 = v14[1].m_BoundComponentHandles.mNode.mPrev;
  if ( v22 )
    v3 = (UFG::SimObject *)v22[2].mNext;
  return UFG::SimObjectUtility::IsBoatInWater(v3);
}

// File Line: 1887
// RVA: 0x5397C0
char __fastcall UFG::SimObjectUtility::IsBoat(UFG::SimObject *vehicle)
{
  unsigned __int16 v1; // dx
  UFG::PhysicsMoverInterface *v2; // rax
  unsigned int v3; // er8
  unsigned int v4; // er9
  UFG::SimComponentHolder *v5; // rdx
  UFG::PhysicsBoat *v6; // rcx

  if ( !vehicle )
    return 0;
  v1 = vehicle->m_Flags;
  if ( (v1 >> 14) & 1 )
    return 0;
  if ( (v1 & 0x8000u) == 0 )
  {
    if ( (v1 >> 13) & 1 )
      return 0;
    if ( (v1 >> 12) & 1 )
    {
      v3 = (unsigned int)vehicle[1].vfptr;
      v4 = vehicle->m_Components.size;
      if ( v3 >= v4 )
      {
LABEL_12:
        v2 = 0i64;
      }
      else
      {
        v5 = &vehicle->m_Components.p[v3];
        while ( (v5->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || UFG::PhysicsMoverInterface::_TypeUID & ~v5->m_TypeUID & 0x1FFFFFF )
        {
          ++v3;
          ++v5;
          if ( v3 >= v4 )
            goto LABEL_12;
        }
        v2 = (UFG::PhysicsMoverInterface *)v5->m_pComponent;
      }
    }
    else
    {
      v2 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                           vehicle,
                                           UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    v2 = (UFG::PhysicsMoverInterface *)vehicle->m_Components.p[34].m_pComponent;
  }
  if ( v2 )
  {
    v6 = (UFG::PhysicsBoat *)v2->mPhysicsVehicle;
    if ( v6 )
    {
      if ( !(*((_BYTE *)&v6->0 + 604) & 7) )
        return 1;
    }
  }
  return 0;
}

// File Line: 1903
// RVA: 0x5398B0
char __fastcall UFG::SimObjectUtility::IsBoatInWater(UFG::SimObject *pVehicle)
{
  unsigned __int16 v1; // dx
  signed int v2; // ebx
  UFG::SimComponent *v3; // rax
  unsigned int v4; // er8
  unsigned int v5; // er9
  UFG::SimComponentHolder *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rdi
  float v8; // xmm6_4
  float v9; // xmm0_4

  if ( !pVehicle )
    return 0;
  v1 = pVehicle->m_Flags;
  if ( (v1 >> 14) & 1 )
    return 0;
  v2 = 0;
  if ( (v1 & 0x8000u) == 0 )
  {
    if ( (v1 >> 13) & 1 )
      return 0;
    if ( (v1 >> 12) & 1 )
    {
      v4 = (unsigned int)pVehicle[1].vfptr;
      v5 = pVehicle->m_Components.size;
      if ( v4 >= v5 )
      {
LABEL_12:
        v3 = 0i64;
      }
      else
      {
        v6 = &pVehicle->m_Components.p[v4];
        while ( (v6->m_TypeUID & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
             || UFG::PhysicsMoverInterface::_TypeUID & ~v6->m_TypeUID & 0x1FFFFFF )
        {
          ++v4;
          ++v6;
          if ( v4 >= v5 )
            goto LABEL_12;
        }
        v3 = v6->m_pComponent;
      }
    }
    else
    {
      v3 = UFG::SimObject::GetComponentOfType(pVehicle, UFG::PhysicsMoverInterface::_TypeUID);
    }
  }
  else
  {
    v3 = pVehicle->m_Components.p[34].m_pComponent;
  }
  if ( v3 )
  {
    v7 = v3[10].m_SafePointerList.mNode.mPrev;
    if ( v7 )
    {
      if ( !(BYTE4(v7[37].mNext) & 7) )
      {
        v8 = 0.0;
        do
        {
          v9 = UFG::PhysicsBoat::GetFloatBuoyancy((UFG::PhysicsBoat *)v7, v2++);
          v8 = v8 + v9;
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
  unsigned __int16 v1; // dx
  unsigned int v2; // er8
  unsigned int v3; // er9
  UFG::SimComponentHolder *v4; // rdx
  UFG::SimComponent *v5; // rax
  unsigned int v6; // er8
  unsigned int v7; // er9
  unsigned int v8; // er8
  unsigned int v9; // er9
  UFG::SimObjectCharacter *v10; // rbx

  if ( !pSimObject )
    return 0;
  v1 = pSimObject->m_Flags;
  if ( (v1 >> 14) & 1 )
  {
    v2 = (unsigned int)pSimObject[1].vfptr;
    v3 = pSimObject->m_Components.size;
    if ( v2 < v3 )
    {
      v4 = &pSimObject->m_Components.p[v2];
      while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
           || UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
      {
        ++v2;
        ++v4;
        if ( v2 >= v3 )
          goto LABEL_8;
      }
LABEL_9:
      v5 = v4->m_pComponent;
      goto LABEL_27;
    }
  }
  else
  {
    if ( (v1 & 0x8000u) != 0 )
    {
      v5 = pSimObject->m_Components.p[30].m_pComponent;
      goto LABEL_27;
    }
    if ( (v1 >> 13) & 1 )
    {
      v6 = (unsigned int)pSimObject[1].vfptr;
      v7 = pSimObject->m_Components.size;
      if ( v6 < v7 )
      {
        v4 = &pSimObject->m_Components.p[v6];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
        {
          ++v6;
          ++v4;
          if ( v6 >= v7 )
          {
            v5 = 0i64;
            goto LABEL_27;
          }
        }
        goto LABEL_9;
      }
    }
    else
    {
      if ( !((v1 >> 12) & 1) )
      {
        v5 = UFG::SimObject::GetComponentOfType(pSimObject, UFG::VehicleOccupantComponent::_TypeUID);
        goto LABEL_27;
      }
      v8 = (unsigned int)pSimObject[1].vfptr;
      v9 = pSimObject->m_Components.size;
      if ( v8 < v9 )
      {
        v4 = &pSimObject->m_Components.p[v8];
        while ( (v4->m_TypeUID & 0xFE000000) != (UFG::VehicleOccupantComponent::_TypeUID & 0xFE000000)
             || UFG::VehicleOccupantComponent::_TypeUID & ~v4->m_TypeUID & 0x1FFFFFF )
        {
          ++v8;
          ++v4;
          if ( v8 >= v9 )
          {
            v5 = 0i64;
            goto LABEL_27;
          }
        }
        goto LABEL_9;
      }
    }
  }
LABEL_8:
  v5 = 0i64;
LABEL_27:
  if ( v5 )
  {
    v10 = (UFG::SimObjectCharacter *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v5);
    if ( v10 == UFG::GetLocalPlayer() )
      return 1;
  }
  return 0;
}

// File Line: 1945
// RVA: 0x539A60
bool __fastcall UFG::SimObjectUtility::IsCharacterInVehicle(UFG::SimObject *pSimObject)
{
  bool result; // al

  if ( pSimObject )
    result = UFG::SimObject::GetComponentOfType(pSimObject, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
  else
    result = 0;
  return result;
}

// File Line: 1959
// RVA: 0x52EB50
char __fastcall UFG::SimObjectUtility::GetObjectCapsuleApproximation(UFG::SimObject *pSimObject, UFG::qMatrix44 **pXform, UFG::qVector3 *vSegA, UFG::qVector3 *vSegB, float *fRadius)
{
  UFG::qVector3 *v5; // rsi
  UFG::qVector3 *v6; // r14
  UFG::qMatrix44 **v7; // r15
  UFG::SimObject *v8; // rbx
  UFG::TransformNodeComponent *v9; // rdi
  signed __int64 v10; // rdi
  unsigned __int16 v11; // cx
  UFG::CharacterPhysicsComponent *v12; // rdi
  unsigned int v13; // er8
  unsigned int v14; // er10
  signed __int64 v15; // rdx
  unsigned int v16; // er8
  unsigned int v17; // er10
  unsigned int v18; // er8
  unsigned int v19; // er10
  float v20; // xmm6_4
  float v21; // xmm0_4
  float *v22; // rcx
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  unsigned __int16 v30; // cx
  UFG::PhysicsMoverInterface *v31; // rax
  unsigned int v32; // er8
  unsigned int v33; // er10
  signed __int64 v34; // rdx
  unsigned __int16 v35; // cx
  unsigned int v36; // er8
  unsigned int v37; // er10
  signed __int64 v38; // rdx
  UFG::RigidBody *v39; // rax
  unsigned int v40; // er8
  unsigned int v41; // er10
  unsigned int v42; // er8
  unsigned int v43; // er10
  unsigned int v44; // er8
  unsigned int v45; // er10
  float v46; // xmm2_4
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  float v49; // xmm5_4
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
  float v67; // xmm1_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm1_4
  UFG::qVector3 min; // [rsp+20h] [rbp-78h]
  UFG::qVector3 max; // [rsp+30h] [rbp-68h]

  v5 = vSegB;
  v6 = vSegA;
  v7 = pXform;
  v8 = pSimObject;
  if ( !*pXform )
  {
    if ( pSimObject && (v9 = pSimObject->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pSimObject->m_pTransformNodeComponent);
      v10 = (signed __int64)&v9->mWorldTransform;
    }
    else
    {
      v10 = 0i64;
    }
    *v7 = (UFG::qMatrix44 *)v10;
  }
  if ( *v7 )
  {
    if ( !v8 )
    {
LABEL_94:
      v64 = (*v7)->v3.y;
      v65 = (*v7)->v3.z;
      v66 = (*v7)->v3.x;
      v6->x = v66;
      v6->y = v64;
      v6->z = v65;
      v5->y = v64;
      v5->x = v66;
      v5->z = v65;
      *fRadius = 0.0;
      return 0;
    }
    v11 = v8->m_Flags;
    if ( (v11 >> 14) & 1 )
    {
      v12 = (UFG::CharacterPhysicsComponent *)v8->m_Components.p[27].m_pComponent;
      goto LABEL_34;
    }
    if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v16 = (unsigned int)v8[1].vfptr;
        v17 = v8->m_Components.size;
        if ( v16 < v17 )
        {
          v15 = (signed __int64)&v8->m_Components.p[v16];
          while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
          {
            ++v16;
            v15 += 16i64;
            if ( v16 >= v17 )
            {
              v12 = 0i64;
              goto LABEL_34;
            }
          }
          goto LABEL_18;
        }
      }
      else
      {
        if ( !((v11 >> 12) & 1) )
        {
          v12 = (UFG::CharacterPhysicsComponent *)UFG::SimObject::GetComponentOfType(
                                                    v8,
                                                    UFG::CharacterPhysicsComponent::_TypeUID);
LABEL_34:
          if ( v12 )
          {
            v20 = UFG::CharacterPhysicsComponent::GetHeight(v12, v12->mCollisionModelType);
            v21 = UFG::CharacterPhysicsComponent::GetRadius(v12);
            v22 = (float *)*v7;
            *fRadius = v21;
            v23 = (float)(v21 * v22[8]) + v22[12];
            v24 = (float)(v21 * v22[9]) + v22[13];
            v25 = (float)(v21 * v22[10]) + v22[14];
            v26 = v20 - (float)(v21 * 2.0);
            v6->x = v23;
            v6->y = v24;
            v6->z = v25;
            v27 = (float)(v26 * v22[8]) + v23;
            v28 = (float)(v26 * v22[9]) + v24;
            v29 = (float)(v26 * v22[10]) + v25;
            v5->x = v27;
            v5->y = v28;
            v5->z = v29;
            return 1;
          }
          v30 = v8->m_Flags;
          if ( !((v30 >> 14) & 1) )
          {
            if ( (v30 & 0x8000u) == 0 )
            {
              if ( (v30 >> 13) & 1 )
                goto LABEL_51;
              if ( (v30 >> 12) & 1 )
              {
                v32 = (unsigned int)v8[1].vfptr;
                v33 = v8->m_Components.size;
                if ( v32 >= v33 )
                {
LABEL_46:
                  v31 = 0i64;
                }
                else
                {
                  v34 = (signed __int64)&v8->m_Components.p[v32];
                  while ( (*(_DWORD *)(v34 + 8) & 0xFE000000) != (UFG::PhysicsMoverInterface::_TypeUID & 0xFE000000)
                       || UFG::PhysicsMoverInterface::_TypeUID & ~*(_DWORD *)(v34 + 8) & 0x1FFFFFF )
                  {
                    ++v32;
                    v34 += 16i64;
                    if ( v32 >= v33 )
                      goto LABEL_46;
                  }
                  v31 = *(UFG::PhysicsMoverInterface **)v34;
                }
              }
              else
              {
                v31 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                      v8,
                                                      UFG::PhysicsMoverInterface::_TypeUID);
              }
            }
            else
            {
              v31 = (UFG::PhysicsMoverInterface *)v8->m_Components.p[34].m_pComponent;
            }
            if ( v31 )
            {
              UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(v31, &min, &max);
LABEL_83:
              v47 = (__m128)LODWORD(max.x);
              v48 = (__m128)LODWORD(max.y);
              v46 = (float)(max.z - min.z) * 0.5;
              v47.m128_f32[0] = (float)(max.x - min.x) * 0.5;
              v48.m128_f32[0] = (float)(max.y - min.y) * 0.5;
              if ( v46 <= v47.m128_f32[0] || v46 <= v48.m128_f32[0] )
              {
                if ( v48.m128_f32[0] > v47.m128_f32[0] && v48.m128_f32[0] > v46 )
                {
                  v47.m128_f32[0] = (float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46);
                  v46 = (float)(max.y - min.y) * 0.5;
                  v49 = (*v7)->v1.x;
                  v50 = (*v7)->v1.y;
                  v51 = (*v7)->v1.z;
                  LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v47);
LABEL_91:
                  v53 = (float)(max.x + min.x) * 0.5;
                  v54 = (float)(max.y + min.y) * 0.5;
                  v55 = (float)(max.z + min.z) * 0.5;
                  *fRadius = v52;
                  v56 = v46 - v52;
                  v57 = v53 + (*v7)->v3.x;
                  v58 = v54 + (*v7)->v3.y;
                  v59 = v55 + (*v7)->v3.z;
                  v60 = v51 * v56;
                  v61 = v50 * v56;
                  v62 = v49 * v56;
                  v6->x = v62 + v57;
                  v6->y = v61 + v58;
                  v6->z = v60 + v59;
                  v5->x = v57 - v62;
                  v5->y = v58 - v61;
                  v5->z = v59 - v60;
                  return 1;
                }
                v48.m128_f32[0] = (float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v46 * v46);
                v46 = (float)(max.x - min.x) * 0.5;
                v49 = (*v7)->v0.x;
                v50 = (*v7)->v0.y;
                v51 = (*v7)->v0.z;
              }
              else
              {
                v48.m128_f32[0] = (float)(v48.m128_f32[0] * v48.m128_f32[0])
                                + (float)(v47.m128_f32[0] * v47.m128_f32[0]);
                v49 = (*v7)->v2.x;
                v50 = (*v7)->v2.y;
                v51 = (*v7)->v2.z;
              }
              LODWORD(v52) = (unsigned __int128)_mm_sqrt_ps(v48);
              goto LABEL_91;
            }
          }
LABEL_51:
          v35 = v8->m_Flags;
          if ( (v35 >> 14) & 1 )
          {
            v36 = (unsigned int)v8[1].vfptr;
            v37 = v8->m_Components.size;
            if ( v36 < v37 )
            {
              v38 = (signed __int64)&v8->m_Components.p[v36];
              while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                   || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
              {
                ++v36;
                v38 += 16i64;
                if ( v36 >= v37 )
                  goto LABEL_57;
              }
LABEL_58:
              v39 = *(UFG::RigidBody **)v38;
              goto LABEL_81;
            }
          }
          else if ( (v35 & 0x8000u) == 0 )
          {
            if ( (v35 >> 13) & 1 )
            {
              v42 = (unsigned int)v8[1].vfptr;
              v43 = v8->m_Components.size;
              if ( v42 < v43 )
              {
                v38 = (signed __int64)&v8->m_Components.p[v42];
                while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                     || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                {
                  ++v42;
                  v38 += 16i64;
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
              if ( !((v35 >> 12) & 1) )
              {
                v39 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v8, UFG::RigidBodyComponent::_TypeUID);
LABEL_81:
                if ( v39 )
                {
                  UFG::RigidBody::GetAabb(v39, &min, &max, WORLD_AABB);
                  goto LABEL_83;
                }
                goto LABEL_94;
              }
              v44 = (unsigned int)v8[1].vfptr;
              v45 = v8->m_Components.size;
              if ( v44 < v45 )
              {
                v38 = (signed __int64)&v8->m_Components.p[v44];
                while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                     || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
                {
                  ++v44;
                  v38 += 16i64;
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
            v40 = (unsigned int)v8[1].vfptr;
            v41 = v8->m_Components.size;
            if ( v40 < v41 )
            {
              v38 = (signed __int64)&v8->m_Components.p[v40];
              while ( (*(_DWORD *)(v38 + 8) & 0xFE000000) != (UFG::RigidBodyComponent::_TypeUID & 0xFE000000)
                   || UFG::RigidBodyComponent::_TypeUID & ~*(_DWORD *)(v38 + 8) & 0x1FFFFFF )
              {
                ++v40;
                v38 += 16i64;
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
        v18 = (unsigned int)v8[1].vfptr;
        v19 = v8->m_Components.size;
        if ( v18 < v19 )
        {
          v15 = (signed __int64)&v8->m_Components.p[v18];
          while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
               || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
          {
            ++v18;
            v15 += 16i64;
            if ( v18 >= v19 )
            {
              v12 = 0i64;
              goto LABEL_34;
            }
          }
          goto LABEL_18;
        }
      }
    }
    else
    {
      v13 = (unsigned int)v8[1].vfptr;
      v14 = v8->m_Components.size;
      if ( v13 < v14 )
      {
        v15 = (signed __int64)&v8->m_Components.p[v13];
        while ( (*(_DWORD *)(v15 + 8) & 0xFE000000) != (UFG::CharacterPhysicsComponent::_TypeUID & 0xFE000000)
             || UFG::CharacterPhysicsComponent::_TypeUID & ~*(_DWORD *)(v15 + 8) & 0x1FFFFFF )
        {
          ++v13;
          v15 += 16i64;
          if ( v13 >= v14 )
            goto LABEL_17;
        }
LABEL_18:
        v12 = *(UFG::CharacterPhysicsComponent **)v15;
        goto LABEL_34;
      }
    }
LABEL_17:
    v12 = 0i64;
    goto LABEL_34;
  }
  v67 = UFG::qVector3::msZero.y;
  v68 = UFG::qVector3::msZero.z;
  v6->x = UFG::qVector3::msZero.x;
  v6->y = v67;
  v6->z = v68;
  v69 = UFG::qVector3::msZero.y;
  v70 = UFG::qVector3::msZero.z;
  v5->x = UFG::qVector3::msZero.x;
  v5->y = v69;
  v5->z = v70;
  *fRadius = 0.0;
  return 0;
}

// File Line: 2061
// RVA: 0x534640
char __fastcall UFG::SimObjectUtility::HandleSimObjectLeavingWorld(UFG::SimObject *pSimObject)
{
  UFG::SimObject *v1; // rdi
  UFG::GameStatTracker *v2; // rbx
  UFG::qVector4 v3; // xmm3
  UFG::allocator::free_link *v4; // rax
  unsigned __int16 v5; // cx
  UFG::TSActorComponent *v6; // rax
  UFG::TSCharacter *v7; // rax
  UFG::qMatrix44 worldXform; // [rsp+40h] [rbp-68h]

  v1 = pSimObject;
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
      v1->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      0);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v4);
  if ( v1 )
  {
    v5 = v1->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = (UFG::TSActorComponent *)v1->m_Components.p[3].m_pComponent;
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::TSActorComponent *)v1->m_Components.p[2].m_pComponent;
      }
      else
      {
        v6 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v1, UFG::TSActorComponent::_TypeUID);
      }
    }
    else
    {
      v6 = (UFG::TSActorComponent *)v1->m_Components.p[4].m_pComponent;
    }
    if ( v6 )
    {
      v7 = (UFG::TSCharacter *)UFG::TSActorComponent::GetActor(v6);
      ((void (__fastcall *)(UFG::TSCharacter *))v7->vfptr[2].get_data_by_name)(v7);
    }
  }
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 1);
  UFG::UIHK_NISOverlay::HideCurtains(5.0, 0);
  return 1;
}

