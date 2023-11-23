// File Line: 28
// RVA: 0x598620
void __fastcall UFG::AudioEntityRegionDataGame::CheckTriggerRegions(UFG::AudioEntityRegionDataGame *this)
{
  UFG::AudioTriggerRegion::CheckEntity(this->m_parent);
}

// File Line: 61
// RVA: 0x59C700
__int64 __fastcall UFG::AudioEntityRegionDataGame::FindObsOccValues(
        UFG::AudioEntityRegionDataGame *this,
        float *obs,
        float *occ)
{
  unsigned int mUID; // ebx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float *v8; // rbp
  UFG::RegionContainmentInfo *ContainmentInfo; // rax
  UFG::AudioListener *v10; // r15
  UFG::RegionContainmentInfo *v11; // r13
  unsigned int size; // r8d
  __int64 v13; // rdi
  __int64 v14; // rbp
  unsigned int *p_mUID; // rsi
  UFG::qBaseTreeRB *v16; // rax
  float *mChild; // rcx
  UFG::qSymbol *v18; // rax
  unsigned int v19; // eax
  __int64 v20; // rdi
  __int64 v21; // rsi
  UFG::qSymbol *p; // rbx
  unsigned int v23; // edx
  UFG::qBaseTreeRB *v24; // rax
  float *v25; // r9
  unsigned int v26; // edx
  unsigned int v27; // eax
  UFG::qSymbol *v28; // rcx
  float v29; // xmm1_4

  mUID = UFG::gNullQSymbol.mUID;
  v5 = 0.0;
  v6 = 0.0;
  v8 = obs;
  ContainmentInfo = UFG::AudioEntity::GetContainmentInfo(this->m_parent);
  v10 = UFG::AudioListener::sm_pInstance;
  v11 = ContainmentInfo;
  size = UFG::AudioListener::sm_pInstance->m_containmentInfo.m_regionsContainedIn.size;
  if ( size )
  {
    v13 = 0i64;
    v14 = size;
    do
    {
      p_mUID = &v10->m_containmentInfo.m_regionsContainedIn.p[v13].mUID;
      if ( *p_mUID )
      {
        v16 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, *p_mUID);
        if ( v16 )
        {
          mChild = (float *)v16[-9].mNULL.mChild;
          if ( v16 != (UFG::qBaseTreeRB *)608 )
          {
            if ( mUID == UFG::gNullQSymbol.mUID )
            {
              v18 = &UFG::gNullQSymbol;
              if ( ((_BYTE)mChild[184] & 0x20) != 0 )
                v18 = (UFG::qSymbol *)p_mUID;
              mUID = v18->mUID;
            }
            v5 = v5 + mChild[182];
            v6 = v6 + mChild[183];
          }
        }
      }
      ++v13;
      --v14;
    }
    while ( v14 );
    v8 = obs;
  }
  if ( this->m_parent->m_inDoorRegion && mUID != UFG::gNullQSymbol.mUID && UFG::DoorStateManager::sm_open )
  {
    *v8 = 0.0;
    *occ = 0.0;
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
        p = v11->m_regionsContainedIn.p;
        v23 = p[v20].mUID;
        if ( v23 )
        {
          v24 = UFG::qBaseTreeRB::Get(&UFG::AudioTriggerRegion::msAudioTriggerRegions.mTree, v23);
          if ( v24 )
          {
            v25 = (float *)v24[-9].mNULL.mChild;
            if ( v24 != (UFG::qBaseTreeRB *)608 && ((_BYTE)v25[184] & 2) != 0 )
            {
              v26 = v10->m_containmentInfo.m_regionsContainedIn.size;
              v27 = 0;
              if ( !v26 )
                goto LABEL_27;
              v28 = v10->m_containmentInfo.m_regionsContainedIn.p;
              while ( p[v20].mUID != v28->mUID )
              {
                ++v27;
                ++v28;
                if ( v27 >= v26 )
                  goto LABEL_27;
              }
              if ( v27 == -1 )
LABEL_27:
                v29 = *(float *)&FLOAT_1_0;
              else
                v29 = FLOAT_N1_0;
              v6 = v6 + (float)(v29 * v25[183]);
              v5 = v5 + (float)(v29 * v25[182]);
            }
          }
        }
        ++v20;
        --v21;
      }
      while ( v21 );
    }
    *v8 = v5;
    *occ = v6;
  }
  return 0i64;
}

