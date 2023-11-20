// File Line: 28
// RVA: 0x598620
void __fastcall UFG::AudioEntityRegionDataGame::CheckTriggerRegions(UFG::AudioEntityRegionDataGame *this)
{
  UFG::AudioTriggerRegion::CheckEntity(this->m_parent);
}

// File Line: 61
// RVA: 0x59C700
__int64 __fastcall UFG::AudioEntityRegionDataGame::FindObsOccValues(UFG::AudioEntityRegionDataGame *this, float *obs, float *occ)
{
  unsigned int v3; // ebx
  UFG::AudioEntityRegionDataGame *v4; // r14
  float v5; // xmm6_4
  float v6; // xmm7_4
  float *v7; // r12
  float *v8; // rbp
  UFG::RegionContainmentInfo *v9; // rax
  UFG::AudioListener *v10; // r15
  UFG::RegionContainmentInfo *v11; // r13
  unsigned int v12; // er8
  __int64 v13; // rdi
  __int64 v14; // rbp
  unsigned int *v15; // rsi
  UFG::qBaseTreeRB *v16; // rax
  signed __int64 v17; // rcx
  UFG::qSymbol *v18; // rax
  unsigned int v19; // eax
  __int64 v20; // rdi
  __int64 v21; // rsi
  UFG::qSymbol *v22; // rbx
  unsigned int v23; // edx
  UFG::qBaseTreeRB *v24; // rax
  signed __int64 v25; // r9
  unsigned int v26; // edx
  unsigned int v27; // eax
  UFG::qSymbol *v28; // rcx
  float v29; // xmm1_4
  float *v31; // [rsp+98h] [rbp+10h]

  v31 = obs;
  v3 = UFG::gNullQSymbol.mUID;
  v4 = this;
  v5 = 0.0;
  v6 = 0.0;
  v7 = occ;
  v8 = obs;
  v9 = UFG::AudioEntity::GetContainmentInfo(this->m_parent);
  v10 = UFG::AudioListener::sm_pInstance;
  v11 = v9;
  v12 = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.size;
  if ( v12 )
  {
    v13 = 0i64;
    v14 = v12;
    do
    {
      v15 = &v10->m_containmentInfo.m_regionsContainedIn.p[v13].mUID;
      if ( *v15 )
      {
        v16 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *v15);
        if ( v16 )
        {
          v17 = (signed __int64)v16[-9].mNULL.mChild;
          if ( v16 != (UFG::qBaseTreeRB *)608 )
          {
            if ( v3 == UFG::gNullQSymbol.mUID )
            {
              v18 = &UFG::gNullQSymbol;
              if ( *(_BYTE *)(v17 + 736) & 0x20 )
                v18 = (UFG::qSymbol *)v15;
              v3 = v18->mUID;
            }
            v5 = v5 + *(float *)(v17 + 728);
            v6 = v6 + *(float *)(v17 + 732);
          }
        }
      }
      ++v13;
      --v14;
    }
    while ( v14 );
    v8 = v31;
  }
  if ( v4->m_parent->m_inDoorRegion && v3 != UFG::gNullQSymbol.mUID && UFG::DoorStateManager::sm_open )
  {
    *v8 = 0.0;
    *v7 = 0.0;
  }
  else
  {
    v19 = v11->m_regionsContainedIn.size;
    if ( v19 )
    {
      v20 = 0i64;
      v21 = v19;
      do
      {
        v22 = v11->m_regionsContainedIn.p;
        v23 = v22[v20].mUID;
        if ( v23 )
        {
          v24 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v23);
          if ( v24 )
          {
            v25 = (signed __int64)v24[-9].mNULL.mChild;
            if ( v24 != (UFG::qBaseTreeRB *)608 )
            {
              if ( *(_BYTE *)(v25 + 736) & 2 )
              {
                v26 = v10->m_containmentInfo.m_regionsContainedIn.size;
                v27 = 0;
                if ( !v26 )
                  goto LABEL_27;
                v28 = v10->m_containmentInfo.m_regionsContainedIn.p;
                while ( v22[v20].mUID != v28->mUID )
                {
                  ++v27;
                  ++v28;
                  if ( v27 >= v26 )
                    goto LABEL_27;
                }
                if ( v27 != -1 )
                  v29 = FLOAT_N1_0;
                else
LABEL_27:
                  v29 = *(float *)&FLOAT_1_0;
                v6 = v6 + (float)(v29 * *(float *)(v25 + 732));
                v5 = v5 + (float)(v29 * *(float *)(v25 + 728));
              }
            }
          }
        }
        ++v20;
        --v21;
      }
      while ( v21 );
    }
    *v8 = v5;
    *v7 = v6;
  }
  return 0i64;
}

