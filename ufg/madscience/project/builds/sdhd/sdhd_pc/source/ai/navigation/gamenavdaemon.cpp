// File Line: 17
// RVA: 0x356050
UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *__fastcall UFG::GameNavDaemon::FindClosestDoorFromFace(UFG::GameNavDaemon *this, hkaiStreamingCollection *collection, unsigned int faceKey)
{
  float v3; // xmm8_4
  float v4; // xmm9_4
  float v5; // xmm10_4
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v6; // rdi
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v7; // rbp
  float v8; // xmm6_4
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v9; // rax
  UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *v10; // rbx
  UFG::TransformNodeComponent *v11; // rsi
  float v12; // xmm2_4
  float v14; // [rsp+20h] [rbp-68h]
  float v15; // [rsp+24h] [rbp-64h]
  float v16; // [rsp+28h] [rbp-60h]

  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)collection->m_instances.m_data[faceKey >> 22].m_instancePtr,
    (hkaiNavMeshInstance *)(faceKey & 0x3FFFFF),
    (unsigned __int64)&v14,
    (hkVector4f *)(6i64 * (faceKey >> 22)));
  v3 = v14;
  v4 = v15;
  v5 = v16;
  v6 = UFG::DoorComponent::s_DoorComponentList.mNode.mNext - 4;
  v7 = 0i64;
  v8 = FLOAT_3_4028235e38;
  if ( (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&UFG::DoorComponent::s_DoorComponentList.mNode.mNext[-4] != &UFG::DoorComponent::s_DoorComponentList - 4 )
  {
    do
    {
      v9 = v6[2].mNext;
      v10 = (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&v6[4].mNext[-4];
      if ( v9 )
        v11 = (UFG::TransformNodeComponent *)v9[5].mNext;
      else
        v11 = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform(v11);
      v12 = (float)((float)((float)(v4 - v11->mWorldTransform.v3.y) * (float)(v4 - v11->mWorldTransform.v3.y))
                  + (float)((float)(v3 - v11->mWorldTransform.v3.x) * (float)(v3 - v11->mWorldTransform.v3.x)))
          + (float)((float)(v5 - v11->mWorldTransform.v3.z) * (float)(v5 - v11->mWorldTransform.v3.z));
      if ( v12 < 4.0 && v12 < v8 )
      {
        v8 = (float)((float)((float)(v4 - v11->mWorldTransform.v3.y) * (float)(v4 - v11->mWorldTransform.v3.y))
                   + (float)((float)(v3 - v11->mWorldTransform.v3.x) * (float)(v3 - v11->mWorldTransform.v3.x)))
           + (float)((float)(v5 - v11->mWorldTransform.v3.z) * (float)(v5 - v11->mWorldTransform.v3.z));
        v7 = v6;
      }
      v6 = &v10->mNode;
    }
    while ( v10 != &UFG::DoorComponent::s_DoorComponentList - 4 );
  }
  return v7;
}

// File Line: 48
// RVA: 0x358C00
void __fastcall UFG::GameNavDaemon::GatherResourcesForPath(UFG::GameNavDaemon *this, UFG::NavPath *navPath, hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathOut, hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // r13
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v5; // r14
  UFG::NavPath *v6; // rsi
  UFG::GameNavDaemon *v7; // rdi
  UFG::NavManagerVtbl *v8; // r10
  hkaiStreamingCollection *v9; // rbx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v10; // rbp
  int v11; // er12
  __int64 v12; // r15
  float v13; // xmm6_4
  unsigned int v14; // er9
  int v15; // edx
  hkaiStreamingCollection::InstanceInfo *v16; // r11
  hkaiNavMeshInstance *v17; // r8
  int v18; // eax
  signed __int64 v19; // rcx
  hkaiNavMesh::Edge *v20; // rax
  int v21; // er10
  signed __int64 v22; // rdx
  int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // er9
  int v26; // edx
  hkaiNavMeshInstance *v27; // r8
  int v28; // er11
  int v29; // eax
  __int64 v30; // rcx
  _DWORD *v31; // rax
  int v32; // er10
  int v33; // eax
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v34; // rax
  UFG::SimObjectGame *v35; // rcx
  UFG::PowerManagementComponent *v36; // rdi
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // rax
  UFG::SimObjectGame *v39; // rbx
  signed __int64 v40; // r8
  char v41; // dl
  __int64 v42; // rax
  char v43; // cl
  UFG::allocator::free_link *v44; // rax
  hkJobType v45; // edx
  unsigned int v46; // eax
  UFG::SimComponent *v47; // rax
  unsigned __int16 v48; // cx
  Creature *v49; // rbx
  int v50; // edi
  unsigned int v51; // edx
  int v52; // esi
  __m128 v53; // xmm8
  __m128 v54; // xmm9
  __m128 v55; // xmm10
  __m128 v56; // xmm11
  __m128 v57; // xmm12
  __m128 v58; // xmm13
  float v59; // xmm15_4
  float v60; // xmm2_4
  float v61; // xmm14_4
  __m128 v62; // xmm0
  float v63; // xmm3_4
  float v64; // xmm1_4
  float v65; // xmm3_4
  int v66; // er8
  __int64 v67; // rax
  hkaiPath::PathPoint *v68; // rcx
  char v69; // dl
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm7_4
  __m128 v73; // xmm0
  __m128 v74; // xmm2
  __m128 v75; // xmm3
  void (__fastcall *v76)(UFG::NavManager *); // [rsp+20h] [rbp-178h]
  float v77; // [rsp+28h] [rbp-170h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-158h]
  UFG::qMatrix44 v79; // [rsp+80h] [rbp-118h]
  UFG::GameNavDaemon *v80; // [rsp+1A0h] [rbp+8h]
  UFG::NavPath *v81; // [rsp+1A8h] [rbp+10h]
  float v82; // [rsp+1B8h] [rbp+20h]

  v81 = navPath;
  v80 = this;
  v4 = visitedEdges;
  v5 = pathOut;
  v6 = navPath;
  v7 = this;
  v8 = UFG::NavManager::ms_pInstance[3].vfptr;
  v9 = (hkaiStreamingCollection *)v8->LowHealthDefrag;
  v76 = v8->LowHealthDefrag;
  v10 = 0i64;
  v11 = 0;
  v12 = 0i64;
  if ( visitedEdges->m_size > 0 )
  {
    v13 = FLOAT_0_5;
    while ( 1 )
    {
      v14 = v4->m_data[v12];
      if ( v14 == -1 )
        return;
      v15 = v14 & 0x3FFFFF;
      v16 = v9->m_instances.m_data;
      v17 = v16[v14 >> 22].m_instancePtr;
      v18 = v17->m_numOriginalEdges;
      if ( (signed int)(v14 & 0x3FFFFF) < v18 )
      {
        v21 = v17->m_edgeMap.m_size ? v17->m_edgeMap.m_data[v15] : v14 & 0x3FFFFF;
        if ( v21 == -1 )
        {
          v19 = v15;
          v20 = v17->m_originalEdges;
        }
        else
        {
          v19 = v21;
          v20 = v17->m_instancedEdges.m_data;
        }
      }
      else
      {
        v19 = v15 - v18;
        v20 = v17->m_ownedEdges.m_data;
      }
      v22 = (signed __int64)&v20[v19];
      if ( *(_DWORD *)(v22 + 8) != -1 )
        break;
LABEL_104:
      ++v11;
      ++v12;
      if ( v11 >= v4->m_size )
        return;
    }
    v23 = *(_DWORD *)(v22 + 12);
    if ( *(_BYTE *)(v22 + 16) & 0x40 )
      v24 = v23 & 0xFFC00000;
    else
      v24 = v16[v14 >> 22].m_instancePtr->m_runtimeId << 22;
    v25 = v24 | v23 & 0x3FFFFF;
    if ( v23 == -1 )
      v25 = -1;
    v26 = v25 & 0x3FFFFF;
    v27 = v16[v25 >> 22].m_instancePtr;
    v28 = v27->m_faceDataStriding;
    if ( v28 )
    {
      v29 = v27->m_numOriginalFaces;
      if ( v26 < v29 )
      {
        if ( v27->m_faceMap.m_size )
          v32 = v27->m_faceMap.m_data[v26];
        else
          v32 = v25 & 0x3FFFFF;
        if ( v32 == -1 )
        {
          v30 = v26 * v28;
          v31 = v27->m_originalFaceData;
        }
        else
        {
          v30 = v28 * v32;
          v31 = v27->m_instancedFaceData.m_data;
        }
      }
      else
      {
        v30 = v28 * (v26 - v29);
        v31 = v27->m_ownedFaceData.m_data;
      }
      v33 = v31[v30];
    }
    else
    {
      LOBYTE(v33) = 0;
    }
    if ( (v33 & 0x80u) == 0 )
    {
      v10 = 0i64;
      goto LABEL_104;
    }
    if ( v10 )
      goto LABEL_104;
    v34 = UFG::GameNavDaemon::FindClosestDoorFromFace(v7, v9, v25);
    v10 = v34;
    if ( !v34 )
      goto LABEL_104;
    v35 = (UFG::SimObjectGame *)v34[2].mNext;
    if ( v35 )
    {
      v37 = v35->m_Flags;
      if ( (v37 >> 14) & 1 )
      {
        v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::PowerManagementComponent::_TypeUID);
      }
      else if ( (v37 & 0x8000u) == 0 )
      {
        if ( (v37 >> 13) & 1 )
        {
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::PowerManagementComponent::_TypeUID);
        }
        else if ( (v37 >> 12) & 1 )
        {
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::PowerManagementComponent::_TypeUID);
        }
        else
        {
          v38 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v35->vfptr,
                  UFG::PowerManagementComponent::_TypeUID);
        }
      }
      else
      {
        v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v35, UFG::PowerManagementComponent::_TypeUID);
      }
      v36 = (UFG::PowerManagementComponent *)v38;
    }
    else
    {
      v36 = 0i64;
    }
    v39 = (UFG::SimObjectGame *)v10[2].mNext;
    if ( v36 && v39 )
    {
      v40 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v41 = ++*(_BYTE *)(v40 + 80);
      v42 = v41;
      *(_DWORD *)(v40 + 4 * v42) = 1;
      *(_QWORD *)(v40 + 8 * v42 + 16) = "AI::GameNavDaemon::GatherResourcesForPath";
      *(_QWORD *)(v40 + 8 * v42 + 48) = 0i64;
      v43 = *(_BYTE *)(v40 + 81);
      if ( v41 > v43 )
        v43 = v41;
      *(_BYTE *)(v40 + 81) = v43;
      v44 = UFG::qMalloc(0x28ui64, "AI::GetPathFromHavok:NavResourceDoor", 0i64);
      if ( v44 )
        UFG::GameNavResourcePowerManagement::GameNavResourcePowerManagement(
          (UFG::GameNavResourcePowerManagement *)v44,
          &v39->m_Name,
          v36);
      UFG::NavPath::AddResource(v6, (UFG::NavResource *)v44);
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v45);
    }
    v46 = _S69;
    if ( !(_S69 & 1) )
    {
      _S69 |= 1u;
      UFG::qSymbolUC::create_from_string(&symSyncSingle01, "C_FeetSync01");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncSingle01__);
      v46 = _S69;
    }
    if ( !(v46 & 2) )
    {
      _S69 = v46 | 2;
      UFG::qSymbolUC::create_from_string(&symSyncSingle02, "C_FeetSync02");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncSingle02__);
      v46 = _S69;
    }
    if ( !(v46 & 4) )
    {
      _S69 = v46 | 4;
      UFG::qSymbolUC::create_from_string(&symSyncDouble01, "C_FreemanSync_Back");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncDouble01__);
      v46 = _S69;
    }
    if ( !(v46 & 8) )
    {
      _S69 = v46 | 8;
      UFG::qSymbolUC::create_from_string(&symSyncDouble02, "C_FreemanSync_Front");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncDouble02__);
    }
    if ( v39 )
    {
      v48 = v39->m_Flags;
      if ( (v48 >> 14) & 1 )
      {
        v47 = v39->m_Components.p[9].m_pComponent;
      }
      else if ( (v48 & 0x8000u) == 0 )
      {
        if ( (v48 >> 13) & 1 )
        {
          v47 = v39->m_Components.p[8].m_pComponent;
        }
        else if ( (v48 >> 12) & 1 )
        {
          v47 = UFG::SimObjectGame::GetComponentOfTypeHK(v39, UFG::BaseAnimationComponent::_TypeUID);
        }
        else
        {
          v47 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v39->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v47 = v39->m_Components.p[9].m_pComponent;
      }
    }
    else
    {
      v47 = 0i64;
    }
    v49 = *(Creature **)&v47[2].m_TypeUID;
    if ( !v49 )
    {
LABEL_102:
      v9 = (hkaiStreamingCollection *)v76;
      v7 = v80;
      goto LABEL_104;
    }
    if ( v49->mPose.mRigHandle.mData )
      v50 = Skeleton::GetBoneID(v49->mPose.mRigHandle.mUFGSkeleton, symSyncSingle01.mUID);
    else
      v50 = -1;
    if ( v50 == -1 )
    {
      if ( v49->mPose.mRigHandle.mData )
        v50 = Skeleton::GetBoneID(v49->mPose.mRigHandle.mUFGSkeleton, symSyncDouble01.mUID);
      else
        v50 = -1;
      if ( v49->mPose.mRigHandle.mData )
      {
        v51 = symSyncDouble02.mUID;
LABEL_82:
        v52 = Skeleton::GetBoneID(v49->mPose.mRigHandle.mUFGSkeleton, v51);
        goto LABEL_84;
      }
    }
    else if ( v49->mPose.mRigHandle.mData )
    {
      v51 = symSyncSingle02.mUID;
      goto LABEL_82;
    }
    v52 = -1;
LABEL_84:
    if ( v50 != -1 && v52 != -1 )
    {
      Creature::GetTransform(v49, v50, &transform);
      Creature::GetTransform(v49, v52, &v79);
      v53 = (__m128)LODWORD(transform.v3.x);
      v54 = (__m128)LODWORD(transform.v3.y);
      v55 = (__m128)LODWORD(transform.v3.z);
      v56 = (__m128)LODWORD(v79.v3.x);
      v57 = (__m128)LODWORD(v79.v3.y);
      v58 = (__m128)LODWORD(v79.v3.z);
      v59 = (float)(v79.v3.x + transform.v3.x) * v13;
      v60 = (float)(v79.v3.y + transform.v3.y) * v13;
      v82 = v60;
      v61 = (float)(v79.v3.z + transform.v3.z) * v13;
      v62 = (__m128)LODWORD(transform.v3.y);
      v62.m128_f32[0] = (float)((float)(transform.v3.y - v60) * (float)(transform.v3.y - v60))
                      + (float)((float)(transform.v3.x - v59) * (float)(transform.v3.x - v59));
      LODWORD(v63) = (unsigned __int128)_mm_sqrt_ps(v62);
      v64 = *(float *)&FLOAT_1_0;
      v65 = (float)(v63 + 1.0) * (float)(v63 + 1.0);
      v77 = v65;
      v66 = 0;
      if ( v5->m_size > 0 )
      {
        v67 = 0i64;
        do
        {
          v68 = v5->m_data;
          if ( !v5->m_data[v67].m_flags.m_storage && v68[v67].m_userEdgeData == 0x80000000 )
            break;
          v69 = v68[v67].m_flags.m_storage;
          if ( !(v69 & 1) && !(v69 & 2) )
          {
            v70 = v68[v67].m_position.m_quad.m128_f32[0];
            v71 = v68[v67].m_position.m_quad.m128_f32[1];
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v68[v67].m_position.m_quad.m128_f32[2] - v61) & _xmm) < v64 )
            {
              if ( (float)((float)((float)(v71 - v60) * (float)(v71 - v60))
                         + (float)((float)(v70 - v59) * (float)(v70 - v59))) < v65 )
              {
                v72 = v68[v67].m_position.m_quad.m128_f32[2];
                if ( (float)((float)((float)((float)(v57.m128_f32[0] - v71) * (float)(v57.m128_f32[0] - v71))
                                   + (float)((float)(v56.m128_f32[0] - v70) * (float)(v56.m128_f32[0] - v70)))
                           + (float)((float)(v58.m128_f32[0] - v72) * (float)(v58.m128_f32[0] - v72))) >= (float)((float)((float)((float)(v54.m128_f32[0] - v71) * (float)(v54.m128_f32[0] - v71)) + (float)((float)(v53.m128_f32[0] - v70) * (float)(v53.m128_f32[0] - v70))) + (float)((float)(v55.m128_f32[0] - v72) * (float)(v55.m128_f32[0] - v72))) )
                {
                  v73 = v55;
                  v74 = v54;
                  v75 = v53;
                }
                else
                {
                  v73 = v58;
                  v74 = v57;
                  v75 = v56;
                }
                v68[v67].m_position.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps(v75, v73),
                                               _mm_unpacklo_ps(v74, (__m128)LODWORD(FLOAT_1000_0)));
                v65 = v77;
                v60 = v82;
              }
              v64 = *(float *)&FLOAT_1_0;
            }
          }
          ++v66;
          ++v67;
        }
        while ( v66 < v5->m_size );
        v13 = FLOAT_0_5;
      }
    }
    v6 = v81;
    goto LABEL_102;
  }
}

