// File Line: 44
// RVA: 0x140620
void __fastcall UFG::AudioListener::AudioListener(UFG::AudioListener *this)
{
  UFG::AudioListener *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  v1 = this;
  this->vfptr = (UFG::AudioListenerVtbl *)&UFG::AudioListener::`vftable;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->m_position.x = UFG::qVector3::msZero.x;
  this->m_position.y = v2;
  this->m_position.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->m_velocity.x = UFG::qVector3::msZero.x;
  this->m_velocity.y = v4;
  this->m_velocity.z = v5;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->m_prevPosition.x = UFG::qVector3::msZero.x;
  this->m_prevPosition.y = v6;
  this->m_prevPosition.z = v7;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  this->m_prevVelocity.x = UFG::qVector3::msZero.x;
  this->m_prevVelocity.y = v8;
  this->m_prevVelocity.z = v9;
  this->m_listenerId = 0;
  UFG::RegionContainmentInfo::RegionContainmentInfo(&this->m_containmentInfo);
  *(_DWORD *)&v1->m_displayListenerInfo = 256;
  *(_WORD *)&v1->m_highSpeedMode = 0;
  v1->m_highSpeedModeThreshhold_kmPhr = 1000.0;
}

// File Line: 65
// RVA: 0x143EE0
void UFG::AudioListener::Create(void)
{
  char *v0; // rax
  UFG::AudioListener *v1; // rax
  UFG::AudioListener *v2; // rcx

  v0 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x88ui64, "AudioListener", 0i64, 1u);
  if ( v0 )
  {
    UFG::AudioListener::AudioListener((UFG::AudioListener *)v0);
    v2 = v1;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::AudioListener::sm_pInstance = v2;
  ((void (*)(void))v2->vfptr->Add)();
}

// File Line: 78
// RVA: 0x142740
void __fastcall UFG::AudioListener::Add(UFG::AudioListener *this)
{
  UFG::AudioListener *v1; // rdi
  unsigned int v2; // ebx
  UFG::qArray<unsigned long,0> *v3; // rax

  v1 = this;
  v2 = 0;
  v3 = &gAudioListener[0].m_myIds;
  while ( (signed int)v3->size > 0 && *v3->p != -1 )
  {
    v3 += 7;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated )
    {
      this->m_listenerId = -1;
      return;
    }
  }
  UFG::Audio3D::SetId((UFG::Audio3D *)&gAudioListener[v2].vfptr, v2);
  v1->m_listenerId = v2;
}

// File Line: 92
// RVA: 0x14B3B0
void __fastcall UFG::AudioListener::Remove(UFG::AudioListener *this)
{
  unsigned int v1; // eax
  UFG::qArray<unsigned long,0> *v2; // rbx
  unsigned int *v3; // rcx

  v1 = this->m_listenerId;
  if ( v1 < 8 )
  {
    v2 = &gAudioListener[0].m_myIds + 7 * v1;
    v3 = v2->p;
    if ( v3 )
      operator delete[](v3);
    v2->p = 0i64;
    *(_QWORD *)&v2->size = 0i64;
  }
}

// File Line: 106
// RVA: 0x14D410
void __fastcall UFG::AudioListener::Update(UFG::AudioListener *this, float delta_sec)
{
  UFG::AudioListener *v2; // rbx
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> *v3; // rsi
  UFG::Audio3DListener *v4; // rdi
  UFG::BaseCameraComponent *v5; // rax
  float *v6; // rax
  float v7; // xmm8_4
  float v8; // xmm9_4
  float v9; // xmm10_4
  UFG::BaseCameraComponent *v10; // rax
  _DWORD *v11; // rax
  int v12; // xmm15_4
  int v13; // xmm0_4
  int v14; // xmm1_4
  UFG::BaseCameraComponent *v15; // rax
  _DWORD *v16; // rax
  unsigned int v17; // xmm6_4
  UFG::qVector3 *v18; // rax
  int v19; // xmm7_4
  int v20; // xmm11_4
  int v21; // xmm12_4
  int v22; // xmm13_4
  UFG::BaseCameraComponent *v23; // rax
  signed __int64 v24; // rax
  int v25; // xmm13_4
  int v26; // xmm12_4
  int v27; // xmm11_4
  UFG::TransformNodeComponent *v28; // rsi
  float v29; // xmm0_4
  float v30; // xmm14_4
  float v31; // xmm15_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm6_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm3_4
  int v45; // xmm13_4
  int v46; // xmm15_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm7_4
  float v50; // xmm0_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  unsigned int v57; // eax
  float v58; // xmm0_4
  float v59; // xmm1_4
  int v60; // [rsp+20h] [rbp-118h]
  int v61; // [rsp+24h] [rbp-114h]
  unsigned int v62; // [rsp+28h] [rbp-110h]
  float v63; // [rsp+2Ch] [rbp-10Ch]
  UFG::qVector4 v64; // [rsp+30h] [rbp-108h]
  UFG::qVector4 v65; // [rsp+40h] [rbp-F8h]
  UFG::qVector4 v66; // [rsp+50h] [rbp-E8h]
  UFG::qVector4 v67; // [rsp+60h] [rbp-D8h]
  UFG::qVector3 result; // [rsp+70h] [rbp-C8h]
  int v69; // [rsp+140h] [rbp+8h]
  float v70; // [rsp+148h] [rbp+10h]
  unsigned int v71; // [rsp+150h] [rbp+18h]
  unsigned int v72; // [rsp+158h] [rbp+20h]

  v70 = delta_sec;
  v2 = this;
  if ( UFG::Editor::GetActiveView() && (unsigned __int8)UFG::Editor::IsActive() )
  {
    v3 = UFG::Editor::GetActiveView()[10];
    v4 = 0i64;
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      v5 = UFG::Director::Get()->mCurrentCamera;
      if ( v5 )
        v6 = &v5->mCamera.mFOVOffset;
      else
        v6 = 0i64;
      v7 = v6[44];
      v8 = v6[45];
      v9 = v6[46];
    }
    else
    {
      v7 = *(float *)&v3[11].mPrev;
      v8 = *((float *)&v3[11].mPrev + 1);
      v9 = *(float *)&v3[11].mNext;
    }
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      v10 = UFG::Director::Get()->mCurrentCamera;
      if ( v10 )
        v11 = (_DWORD *)&v10->mCamera.mFOVOffset;
      else
        v11 = 0i64;
      v12 = v11[32];
      v13 = v11[33];
      v14 = v11[34];
    }
    else
    {
      v12 = (int)v3[8].mPrev;
      v13 = HIDWORD(v3[8].mPrev);
      v14 = (int)v3[8].mNext;
    }
    v60 = v14;
    v61 = v13;
    v69 = v12;
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      v15 = UFG::Director::Get()->mCurrentCamera;
      if ( v15 )
        v16 = (_DWORD *)&v15->mCamera.mFOVOffset;
      else
        v16 = 0i64;
      v17 = v16[36];
      v72 = v16[37];
      v62 = v16[38];
    }
    else
    {
      v17 = (unsigned int)v3[9].mPrev;
      v72 = HIDWORD(v3[9].mPrev);
      v62 = (unsigned int)v3[9].mNext;
    }
    v71 = v17;
    v18 = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)v3, &result);
    v19 = _xmm[0];
    v20 = LODWORD(v18->x);
    v21 = LODWORD(v18->y);
    v22 = LODWORD(v18->z);
  }
  else
  {
    v4 = 0i64;
    v23 = UFG::Director::Get()->mCurrentCamera;
    if ( v23 )
      v24 = (signed __int64)&v23->mCamera;
    else
      v24 = 0i64;
    v19 = _xmm[0];
    v12 = *(_DWORD *)(v24 + 128);
    v17 = *(_DWORD *)(v24 + 144);
    v20 = *(_DWORD *)(v24 + 160) ^ _xmm[0];
    v7 = *(float *)(v24 + 176);
    v21 = *(_DWORD *)(v24 + 164) ^ _xmm[0];
    v22 = *(_DWORD *)(v24 + 168) ^ _xmm[0];
    v8 = *(float *)(v24 + 180);
    v9 = *(float *)(v24 + 184);
    v61 = *(_DWORD *)(v24 + 132);
    v69 = *(_DWORD *)(v24 + 128);
    v60 = *(_DWORD *)(v24 + 136);
    v72 = *(_DWORD *)(v24 + 148);
    v71 = *(_DWORD *)(v24 + 144);
    v62 = *(_DWORD *)(v24 + 152);
  }
  v25 = v22 ^ v19;
  v26 = v21 ^ v19;
  v27 = v20 ^ v19;
  if ( v2->m_lockListenerPosition )
    goto LABEL_46;
  if ( LocalPlayer )
    v28 = LocalPlayer->m_pTransformNodeComponent;
  else
    v28 = 0i64;
  v29 = v9;
  v30 = v7;
  v31 = v8;
  v63 = v9;
  if ( v28 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v28);
    v29 = v28->mWorldTransform.v3.z;
    v30 = v28->mWorldTransform.v3.x;
    v31 = v28->mWorldTransform.v3.y;
    v63 = v28->mWorldTransform.v3.z;
  }
  if ( v2->m_positionListenerAtCamera )
  {
    if ( v7 == UFG::qVector3::msZero.x && v8 == UFG::qVector3::msZero.y && v9 == UFG::qVector3::msZero.z )
      goto LABEL_39;
    v32 = v2->m_position.z;
    v33 = v2->m_position.y + (float)((float)(v8 - v2->m_position.y) * 0.2);
    v2->m_position.x = v2->m_position.x + (float)((float)(v7 - v2->m_position.x) * 0.2);
    v2->m_position.y = v33;
    v2->m_position.z = v32 + (float)((float)(v9 - v32) * 0.2);
  }
  else
  {
    v34 = (float)((float)(v29 - v2->m_position.z) * 0.2) + v2->m_position.z;
    v35 = (float)((float)(v31 - v2->m_position.y) * 0.2) + v2->m_position.y;
    v2->m_position.x = (float)((float)(v30 - v2->m_position.x) * 0.2) + v2->m_position.x;
    v2->m_position.z = v34;
    v2->m_position.y = v35;
  }
  v17 = v71;
LABEL_39:
  if ( v2->m_triggerPositionAtCamera )
  {
    if ( v7 != UFG::qVector3::msZero.x || v8 != UFG::qVector3::msZero.y || v9 != UFG::qVector3::msZero.z )
    {
      v2->m_triggerPosition.x = v7;
      v2->m_triggerPosition.y = v8;
      v2->m_triggerPosition.z = v9;
    }
  }
  else
  {
    v2->m_triggerPosition.x = v30;
    v2->m_triggerPosition.y = v31;
    v2->m_triggerPosition.z = v63;
  }
  v12 = v69;
LABEL_46:
  v36 = v2->m_position.x;
  v37 = v2->m_position.y;
  v67.w = 1.0;
  *(_QWORD *)&v67.x = __PAIR__(LODWORD(v37), LODWORD(v36));
  *(_QWORD *)&v66.x = __PAIR__(v72, v17);
  *(_QWORD *)&v66.z = v62;
  v39 = v37 - v2->m_prevPosition.y;
  v67.z = v2->m_position.z;
  v40 = (float)(1.0 / v70) * (float)(v36 - v2->m_prevPosition.x);
  v41 = (float)(1.0 / v70) * (float)(v67.z - v2->m_prevPosition.z);
  v2->m_velocity.x = v40;
  v2->m_velocity.z = v41;
  v2->m_velocity.y = (float)(1.0 / v70) * v39;
  v42 = FLOAT_27_777779;
  if ( v40 <= -27.777779 )
  {
    v40 = FLOAT_N27_777779;
  }
  else if ( v40 >= 27.777779 )
  {
    v40 = FLOAT_27_777779;
  }
  v2->m_velocity.x = v40;
  v43 = v2->m_velocity.y;
  if ( v43 <= -27.777779 )
  {
    v43 = FLOAT_N27_777779;
  }
  else if ( v43 >= 27.777779 )
  {
    v43 = FLOAT_27_777779;
  }
  v2->m_velocity.y = v43;
  v44 = v2->m_velocity.z;
  if ( v44 <= -27.777779 )
  {
    v44 = FLOAT_N27_777779;
    goto LABEL_58;
  }
  if ( v44 < 27.777779 )
LABEL_58:
    v42 = v44;
  v2->m_velocity.z = v42;
  v45 = v25 ^ v19;
  v65.w = -0.0;
  LODWORD(v64.x) = v27 ^ v19;
  v46 = v12 ^ v19;
  v47 = v2->m_triggerPosition.x - v2->m_prevTriggerPosition.x;
  LODWORD(v65.z) = v60 ^ v19;
  LODWORD(v65.y) = v61 ^ v19;
  LODWORD(v64.y) = v26 ^ v19;
  v48 = v2->m_triggerPosition.y - v2->m_prevTriggerPosition.y;
  v49 = (float)((float)((float)(v2->m_velocity.y - v2->m_prevVelocity.y)
                      * (float)(v2->m_velocity.y - v2->m_prevVelocity.y))
              + (float)((float)(v40 - v2->m_prevVelocity.x) * (float)(v40 - v2->m_prevVelocity.x)))
      + (float)((float)(v2->m_velocity.z - v2->m_prevVelocity.z) * (float)(v2->m_velocity.z - v2->m_prevVelocity.z));
  v50 = v2->m_triggerPosition.z - v2->m_prevTriggerPosition.z;
  *(_QWORD *)&v64.z = __PAIR__(2147483648, v45);
  LODWORD(v65.x) = v46;
  v38 = 1.0 / v70;
  v2->m_highSpeedMode = (float)((float)((float)((float)(v38 * v48) * (float)(v38 * v48))
                                      + (float)((float)(v38 * v47) * (float)(v38 * v47)))
                              + (float)((float)(v38 * v50) * (float)(v38 * v50))) > (float)((float)(v2->m_highSpeedModeThreshhold_kmPhr
                                                                                                  * 0.27777779)
                                                                                          * (float)(v2->m_highSpeedModeThreshhold_kmPhr
                                                                                                  * 0.27777779));
  UFG::TiDo::m_pInstance->vfptr->UpdateListenerTriggerRegions(UFG::TiDo::m_pInstance, v2);
  v51 = v2->m_position.y;
  v52 = v2->m_position.z;
  v2->m_prevPosition.x = v2->m_position.x;
  v2->m_prevPosition.y = v51;
  v2->m_prevPosition.z = v52;
  v53 = v2->m_velocity.y;
  v54 = v2->m_velocity.z;
  v2->m_prevVelocity.x = v2->m_velocity.x;
  v2->m_prevVelocity.y = v53;
  v2->m_prevVelocity.z = v54;
  v55 = v2->m_triggerPosition.y;
  v56 = v2->m_triggerPosition.z;
  v2->m_prevTriggerPosition.x = v2->m_triggerPosition.x;
  v2->m_prevTriggerPosition.y = v55;
  v2->m_prevTriggerPosition.z = v56;
  v57 = v2->m_listenerId;
  if ( v57 < 8 )
    v4 = &gAudioListener[v57];
  v4->m_matrix.v0 = v64;
  v4->m_matrix.v1 = v65;
  v4->m_matrix.v2 = v66;
  v4->m_matrix.v3 = v67;
  if ( v49 > 1.0 || v49 < 18225.0 )
  {
    v58 = v2->m_velocity.y;
    v59 = v2->m_velocity.z;
    v4->m_velocity.x = v2->m_velocity.x;
    v4->m_velocity.y = v58;
    v4->m_velocity.z = v59;
  }
  v4->vfptr->Update((UFG::Audio3D *)&v4->vfptr);
}

// File Line: 230
// RVA: 0x145D00
float __fastcall UFG::AudioListener::GetDistance2From(UFG::AudioListener *this, UFG::qVector3 *pos)
{
  return (float)((float)((float)(pos->y - this->m_position.y) * (float)(pos->y - this->m_position.y))
               + (float)((float)(pos->x - this->m_position.x) * (float)(pos->x - this->m_position.x)))
       + (float)((float)(pos->z - this->m_position.z) * (float)(pos->z - this->m_position.z));
}

