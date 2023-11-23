// File Line: 17
// RVA: 0x356050
UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *__fastcall UFG::GameNavDaemon::FindClosestDoorFromFace(
        UFG::GameNavDaemon *this,
        hkaiStreamingCollection *collection,
        unsigned int faceKey)
{
  float v3; // xmm8_4
  float v4; // xmm9_4
  float v5; // xmm10_4
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *p_mNode; // rdi
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v7; // rbp
  float v8; // xmm6_4
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *mNext; // rax
  UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *v10; // rbx
  UFG::TransformNodeComponent *v11; // rsi
  float v12; // xmm2_4
  int v14[16]; // [rsp+20h] [rbp-68h] BYREF

  hkaiNavMeshUtils::calcFaceCentroid<hkaiNavMeshInstance>(
    (hkaiNavMeshUtils *)collection->m_instances.m_data[faceKey >> 22].m_instancePtr,
    (hkaiNavMeshInstance *)(faceKey & 0x3FFFFF),
    (int)v14,
    (hkVector4f *)(6i64 * (faceKey >> 22)));
  v3 = *(float *)v14;
  v4 = *(float *)&v14[1];
  v5 = *(float *)&v14[2];
  p_mNode = UFG::DoorComponent::s_DoorComponentList.mNode.mNext - 4;
  v7 = 0i64;
  v8 = FLOAT_3_4028235e38;
  if ( (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&UFG::DoorComponent::s_DoorComponentList.mNode.mNext[-4] != &UFG::DoorComponent::s_DoorComponentList - 4 )
  {
    do
    {
      mNext = p_mNode[2].mNext;
      v10 = (UFG::qList<UFG::DoorComponent,UFG::DoorComponent,1,0> *)&p_mNode[4].mNext[-4];
      if ( mNext )
        v11 = (UFG::TransformNodeComponent *)mNext[5].mNext;
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
        v7 = p_mNode;
      }
      p_mNode = &v10->mNode;
    }
    while ( v10 != &UFG::DoorComponent::s_DoorComponentList - 4 );
  }
  return v7;
}

// File Line: 48
// RVA: 0x358C00
void __fastcall UFG::GameNavDaemon::GatherResourcesForPath(
        UFG::GameNavDaemon *this,
        UFG::NavPath *navPath,
        hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *pathOut,
        hkArray<unsigned int,hkContainerHeapAllocator> *visitedEdges)
{
  UFG::NavPath *v6; // rsi
  UFG::GameNavDaemon *v7; // rdi
  hkaiStreamingCollection *LowHealthDefrag; // rbx
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *v9; // rbp
  int v10; // r12d
  __int64 v11; // r15
  float v12; // xmm6_4
  unsigned int v13; // r9d
  int v14; // edx
  hkaiStreamingCollection::InstanceInfo *m_data; // r11
  hkaiNavMeshInstance *m_instancePtr; // r8
  int m_numOriginalEdges; // eax
  __int64 v18; // rcx
  hkaiNavMesh::Edge *m_originalEdges; // rax
  unsigned int v20; // r10d
  hkaiNavMesh::Edge *v21; // rdx
  unsigned int m_oppositeFace; // eax
  unsigned int v23; // ecx
  unsigned int v24; // r9d
  int v25; // edx
  hkaiNavMeshInstance *v26; // r8
  int m_faceDataStriding; // r11d
  int m_numOriginalFaces; // eax
  __int64 v29; // rcx
  _DWORD *m_originalFaceData; // rax
  int v31; // r10d
  int v32; // eax
  UFG::qNode<UFG::DoorComponent,UFG::DoorComponent> *ClosestDoorFromFace; // rax
  UFG::SimObjectGame *mNext; // rcx
  UFG::PowerManagementComponent *v35; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v38; // rbx
  __int64 v39; // r8
  char v40; // dl
  char v41; // cl
  UFG::allocator::free_link *v42; // rax
  hkJobType v43; // edx
  unsigned int v44; // eax
  UFG::SimComponent *m_pComponent; // rax
  __int16 v46; // cx
  Creature *v47; // rbx
  int BoneID; // edi
  unsigned int mUID; // edx
  int v50; // esi
  __m128 x_low; // xmm8
  __m128 y_low; // xmm9
  __m128 z_low; // xmm10
  __m128 v54; // xmm11
  __m128 v55; // xmm12
  __m128 v56; // xmm13
  float v57; // xmm15_4
  float v58; // xmm2_4
  float v59; // xmm14_4
  __m128 v60; // xmm0
  float v61; // xmm3_4
  float v62; // xmm1_4
  float v63; // xmm3_4
  int v64; // r8d
  __int64 v65; // rax
  hkaiPath::PathPoint *v66; // rcx
  char m_storage; // dl
  float v68; // xmm4_4
  float v69; // xmm6_4
  float v70; // xmm7_4
  __m128 v71; // xmm0
  __m128 v72; // xmm2
  __m128 v73; // xmm3
  hkaiStreamingCollection *v74; // [rsp+20h] [rbp-178h]
  float v75; // [rsp+28h] [rbp-170h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-158h] BYREF
  UFG::qMatrix44 v77; // [rsp+80h] [rbp-118h] BYREF
  float v80; // [rsp+1B8h] [rbp+20h]

  v6 = navPath;
  v7 = this;
  LowHealthDefrag = (hkaiStreamingCollection *)UFG::NavManager::ms_pInstance[3].vfptr->LowHealthDefrag;
  v74 = LowHealthDefrag;
  v9 = 0i64;
  v10 = 0;
  v11 = 0i64;
  if ( visitedEdges->m_size > 0 )
  {
    v12 = FLOAT_0_5;
    while ( 1 )
    {
      v13 = visitedEdges->m_data[v11];
      if ( v13 == -1 )
        return;
      v14 = v13 & 0x3FFFFF;
      m_data = LowHealthDefrag->m_instances.m_data;
      m_instancePtr = m_data[v13 >> 22].m_instancePtr;
      m_numOriginalEdges = m_instancePtr->m_numOriginalEdges;
      if ( (int)(v13 & 0x3FFFFF) < m_numOriginalEdges )
      {
        v20 = m_instancePtr->m_edgeMap.m_size ? m_instancePtr->m_edgeMap.m_data[v14] : v13 & 0x3FFFFF;
        if ( v20 == -1 )
        {
          v18 = v14;
          m_originalEdges = m_instancePtr->m_originalEdges;
        }
        else
        {
          v18 = (int)v20;
          m_originalEdges = m_instancePtr->m_instancedEdges.m_data;
        }
      }
      else
      {
        v18 = v14 - m_numOriginalEdges;
        m_originalEdges = m_instancePtr->m_ownedEdges.m_data;
      }
      v21 = &m_originalEdges[v18];
      if ( v21->m_oppositeEdge != -1 )
        break;
LABEL_102:
      ++v10;
      ++v11;
      if ( v10 >= visitedEdges->m_size )
        return;
    }
    m_oppositeFace = v21->m_oppositeFace;
    if ( (v21->m_flags.m_storage & 0x40) != 0 )
      v23 = m_oppositeFace & 0xFFC00000;
    else
      v23 = m_data[v13 >> 22].m_instancePtr->m_runtimeId << 22;
    v24 = v23 | m_oppositeFace & 0x3FFFFF;
    if ( m_oppositeFace == -1 )
      v24 = -1;
    v25 = v24 & 0x3FFFFF;
    v26 = m_data[v24 >> 22].m_instancePtr;
    m_faceDataStriding = v26->m_faceDataStriding;
    if ( m_faceDataStriding )
    {
      m_numOriginalFaces = v26->m_numOriginalFaces;
      if ( v25 < m_numOriginalFaces )
      {
        if ( v26->m_faceMap.m_size )
          v31 = v26->m_faceMap.m_data[v25];
        else
          v31 = v24 & 0x3FFFFF;
        if ( v31 == -1 )
        {
          v29 = v25 * m_faceDataStriding;
          m_originalFaceData = v26->m_originalFaceData;
        }
        else
        {
          v29 = m_faceDataStriding * v31;
          m_originalFaceData = v26->m_instancedFaceData.m_data;
        }
      }
      else
      {
        v29 = m_faceDataStriding * (v25 - m_numOriginalFaces);
        m_originalFaceData = v26->m_ownedFaceData.m_data;
      }
      v32 = m_originalFaceData[v29];
    }
    else
    {
      LOBYTE(v32) = 0;
    }
    if ( (v32 & 0x80u) == 0 )
    {
      v9 = 0i64;
      goto LABEL_102;
    }
    if ( v9 )
      goto LABEL_102;
    ClosestDoorFromFace = UFG::GameNavDaemon::FindClosestDoorFromFace(v7, LowHealthDefrag, v24);
    v9 = ClosestDoorFromFace;
    if ( !ClosestDoorFromFace )
      goto LABEL_102;
    mNext = (UFG::SimObjectGame *)ClosestDoorFromFace[2].mNext;
    if ( mNext )
    {
      m_Flags = mNext->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(mNext, UFG::PowerManagementComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(mNext, UFG::PowerManagementComponent::_TypeUID);
      v35 = (UFG::PowerManagementComponent *)ComponentOfTypeHK;
    }
    else
    {
      v35 = 0i64;
    }
    v38 = (UFG::SimObjectGame *)v9[2].mNext;
    if ( v35 && v38 )
    {
      v39 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
      v40 = ++*(_BYTE *)(v39 + 80);
      *(_DWORD *)(v39 + 4i64 * v40) = 1;
      *(_QWORD *)(v39 + 8i64 * v40 + 16) = "AI::GameNavDaemon::GatherResourcesForPath";
      *(_QWORD *)(v39 + 8i64 * v40 + 48) = 0i64;
      v41 = *(_BYTE *)(v39 + 81);
      if ( v40 > v41 )
        v41 = v40;
      *(_BYTE *)(v39 + 81) = v41;
      v42 = UFG::qMalloc(0x28ui64, "AI::GetPathFromHavok:NavResourceDoor", 0i64);
      if ( v42 )
        UFG::GameNavResourcePowerManagement::GameNavResourcePowerManagement(
          (UFG::GameNavResourcePowerManagement *)v42,
          &v38->m_Name,
          v35);
      UFG::NavPath::AddResource(v6, (UFG::qReflectInventoryBase *)v42);
      HavokJobMemoryPoolTagger::onEndJob((HavokJobMemoryPoolTagger *)CustomHavokMemorySystem::mInstance, v43);
    }
    v44 = _S69;
    if ( (_S69 & 1) == 0 )
    {
      _S69 |= 1u;
      UFG::qSymbolUC::create_from_string(&symSyncSingle01, "C_FeetSync01");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncSingle01__);
      v44 = _S69;
    }
    if ( (v44 & 2) == 0 )
    {
      _S69 = v44 | 2;
      UFG::qSymbolUC::create_from_string(&symSyncSingle02, "C_FeetSync02");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncSingle02__);
      v44 = _S69;
    }
    if ( (v44 & 4) == 0 )
    {
      _S69 = v44 | 4;
      UFG::qSymbolUC::create_from_string(&symSyncDouble01, "C_FreemanSync_Back");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncDouble01__);
      v44 = _S69;
    }
    if ( (v44 & 8) == 0 )
    {
      _S69 = v44 | 8;
      UFG::qSymbolUC::create_from_string(&symSyncDouble02, "C_FreemanSync_Front");
      atexit(UFG::GameNavDaemon::GatherResourcesForPath_::_19_::_dynamic_atexit_destructor_for__symSyncDouble02__);
    }
    if ( v38 )
    {
      v46 = v38->m_Flags;
      if ( (v46 & 0x4000) != 0 )
      {
        m_pComponent = v38->m_Components.p[9].m_pComponent;
      }
      else if ( v46 >= 0 )
      {
        if ( (v46 & 0x2000) != 0 )
        {
          m_pComponent = v38->m_Components.p[8].m_pComponent;
        }
        else if ( (v46 & 0x1000) != 0 )
        {
          m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(v38, UFG::BaseAnimationComponent::_TypeUID);
        }
        else
        {
          m_pComponent = UFG::SimObject::GetComponentOfType(v38, UFG::BaseAnimationComponent::_TypeUID);
        }
      }
      else
      {
        m_pComponent = v38->m_Components.p[9].m_pComponent;
      }
    }
    else
    {
      m_pComponent = 0i64;
    }
    v47 = *(Creature **)&m_pComponent[2].m_TypeUID;
    if ( !v47 )
    {
LABEL_100:
      LowHealthDefrag = v74;
      v7 = this;
      goto LABEL_102;
    }
    if ( v47->mPose.mRigHandle.mData )
      BoneID = Skeleton::GetBoneID(v47->mPose.mRigHandle.mUFGSkeleton, symSyncSingle01.mUID);
    else
      BoneID = -1;
    if ( BoneID == -1 )
    {
      if ( v47->mPose.mRigHandle.mData )
        BoneID = Skeleton::GetBoneID(v47->mPose.mRigHandle.mUFGSkeleton, symSyncDouble01.mUID);
      else
        BoneID = -1;
      if ( v47->mPose.mRigHandle.mData )
      {
        mUID = symSyncDouble02.mUID;
LABEL_80:
        v50 = Skeleton::GetBoneID(v47->mPose.mRigHandle.mUFGSkeleton, mUID);
        goto LABEL_82;
      }
    }
    else if ( v47->mPose.mRigHandle.mData )
    {
      mUID = symSyncSingle02.mUID;
      goto LABEL_80;
    }
    v50 = -1;
LABEL_82:
    if ( BoneID != -1 && v50 != -1 )
    {
      Creature::GetTransform(v47, BoneID, &transform);
      Creature::GetTransform(v47, v50, &v77);
      x_low = (__m128)LODWORD(transform.v3.x);
      y_low = (__m128)LODWORD(transform.v3.y);
      z_low = (__m128)LODWORD(transform.v3.z);
      v54 = (__m128)LODWORD(v77.v3.x);
      v55 = (__m128)LODWORD(v77.v3.y);
      v56 = (__m128)LODWORD(v77.v3.z);
      v57 = (float)(v77.v3.x + transform.v3.x) * v12;
      v58 = (float)(v77.v3.y + transform.v3.y) * v12;
      v80 = v58;
      v59 = (float)(v77.v3.z + transform.v3.z) * v12;
      v60 = (__m128)LODWORD(transform.v3.y);
      v60.m128_f32[0] = (float)((float)(transform.v3.y - v58) * (float)(transform.v3.y - v58))
                      + (float)((float)(transform.v3.x - v57) * (float)(transform.v3.x - v57));
      v61 = _mm_sqrt_ps(v60).m128_f32[0];
      v62 = *(float *)&FLOAT_1_0;
      v63 = (float)(v61 + 1.0) * (float)(v61 + 1.0);
      v75 = v63;
      v64 = 0;
      if ( pathOut->m_size > 0 )
      {
        v65 = 0i64;
        do
        {
          v66 = pathOut->m_data;
          if ( !pathOut->m_data[v65].m_flags.m_storage && v66[v65].m_userEdgeData == 0x80000000 )
            break;
          m_storage = v66[v65].m_flags.m_storage;
          if ( (m_storage & 1) == 0 && (m_storage & 2) == 0 )
          {
            v68 = v66[v65].m_position.m_quad.m128_f32[0];
            v69 = v66[v65].m_position.m_quad.m128_f32[1];
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v66[v65].m_position.m_quad.m128_f32[2] - v59) & _xmm) < v62 )
            {
              if ( (float)((float)((float)(v69 - v58) * (float)(v69 - v58))
                         + (float)((float)(v68 - v57) * (float)(v68 - v57))) < v63 )
              {
                v70 = v66[v65].m_position.m_quad.m128_f32[2];
                if ( (float)((float)((float)((float)(v55.m128_f32[0] - v69) * (float)(v55.m128_f32[0] - v69))
                                   + (float)((float)(v54.m128_f32[0] - v68) * (float)(v54.m128_f32[0] - v68)))
                           + (float)((float)(v56.m128_f32[0] - v70) * (float)(v56.m128_f32[0] - v70))) >= (float)((float)((float)((float)(y_low.m128_f32[0] - v69) * (float)(y_low.m128_f32[0] - v69)) + (float)((float)(x_low.m128_f32[0] - v68) * (float)(x_low.m128_f32[0] - v68))) + (float)((float)(z_low.m128_f32[0] - v70) * (float)(z_low.m128_f32[0] - v70))) )
                {
                  v71 = z_low;
                  v72 = y_low;
                  v73 = x_low;
                }
                else
                {
                  v71 = v56;
                  v72 = v55;
                  v73 = v54;
                }
                v66[v65].m_position.m_quad = _mm_unpacklo_ps(
                                               _mm_unpacklo_ps(v73, v71),
                                               _mm_unpacklo_ps(v72, (__m128)LODWORD(FLOAT_1000_0)));
                v63 = v75;
                v58 = v80;
              }
              v62 = *(float *)&FLOAT_1_0;
            }
          }
          ++v64;
          ++v65;
        }
        while ( v64 < pathOut->m_size );
        v12 = FLOAT_0_5;
      }
    }
    v6 = navPath;
    goto LABEL_100;
  }
}

