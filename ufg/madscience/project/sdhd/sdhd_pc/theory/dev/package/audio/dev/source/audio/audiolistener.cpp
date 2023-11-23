// File Line: 44
// RVA: 0x140620
void __fastcall UFG::AudioListener::AudioListener(UFG::AudioListener *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  this->vfptr = (UFG::AudioListenerVtbl *)&UFG::AudioListener::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_position.x = UFG::qVector3::msZero.x;
  this->m_position.y = y;
  this->m_position.z = z;
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
  *(_DWORD *)&this->m_displayListenerInfo = 256;
  *(_WORD *)&this->m_highSpeedMode = 0;
  this->m_highSpeedModeThreshhold_kmPhr = 1000.0;
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
  v2->vfptr->Add(v2);
}

// File Line: 78
// RVA: 0x142740
void __fastcall UFG::AudioListener::Add(UFG::AudioListener *this)
{
  unsigned int v2; // ebx
  UFG::qArray<unsigned long,0> *p_m_myIds; // rax

  v2 = 0;
  p_m_myIds = &gAudioListener[0].m_myIds;
  while ( (int)p_m_myIds->size > 0 && *p_m_myIds->p != -1 )
  {
    p_m_myIds += 7;
    ++v2;
    if ( (__int64)p_m_myIds >= (__int64)&UFG::gAudioEventCallbackObjectPool.mMostSlotsAllocated )
    {
      this->m_listenerId = -1;
      return;
    }
  }
  UFG::Audio3D::SetId(&gAudioListener[v2], v2);
  this->m_listenerId = v2;
}

// File Line: 92
// RVA: 0x14B3B0
void __fastcall UFG::AudioListener::Remove(UFG::AudioListener *this)
{
  unsigned int m_listenerId; // eax
  UFG::qArray<unsigned long,0> *v2; // rbx
  unsigned int *p; // rcx

  m_listenerId = this->m_listenerId;
  if ( m_listenerId < 8 )
  {
    v2 = &gAudioListener[0].m_myIds + 7 * m_listenerId;
    p = v2->p;
    if ( p )
      operator delete[](p);
    v2->p = 0i64;
    *(_QWORD *)&v2->size = 0i64;
  }
}

// File Line: 106
// RVA: 0x14D410
void __fastcall UFG::AudioListener::Update(UFG::AudioListener *this, float delta_sec)
{
  UFG::qNode<UFG::Editor::View,UFG::Editor::View> *v3; // rsi
  UFG::Audio3DListener *v4; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float *p_mFOVOffset; // rax
  float v7; // xmm8_4
  float y; // xmm9_4
  float z; // xmm10_4
  UFG::BaseCameraComponent *v10; // rax
  float *v11; // rax
  float x; // xmm15_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  UFG::BaseCameraComponent *v15; // rax
  float *v16; // rax
  float v17; // xmm6_4
  UFG::qVector3 *DirForward; // rax
  int v19; // xmm7_4
  int x_low; // xmm11_4
  int y_low; // xmm12_4
  int z_low; // xmm13_4
  UFG::BaseCameraComponent *v23; // rax
  UFG::Camera *p_mCamera; // rax
  int v25; // xmm13_4
  int v26; // xmm12_4
  int v27; // xmm11_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v29; // xmm0_4
  float v30; // xmm14_4
  float v31; // xmm15_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm4_4
  float v36; // xmm6_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm3_4
  unsigned int v43; // xmm13_4
  int v44; // xmm15_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm7_4
  float v48; // xmm0_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm2_4
  float v52; // xmm0_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  unsigned int m_listenerId; // eax
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // [rsp+20h] [rbp-118h]
  float v59; // [rsp+24h] [rbp-114h]
  float v60; // [rsp+28h] [rbp-110h]
  float v61; // [rsp+2Ch] [rbp-10Ch]
  UFG::qVector4 v62; // [rsp+30h] [rbp-108h]
  UFG::qVector4 v63; // [rsp+40h] [rbp-F8h]
  UFG::qVector4 v64; // [rsp+50h] [rbp-E8h]
  UFG::qVector4 v65; // [rsp+60h] [rbp-D8h]
  UFG::qVector3 result; // [rsp+70h] [rbp-C8h] BYREF
  float v67; // [rsp+140h] [rbp+8h]
  float v69; // [rsp+150h] [rbp+18h]
  float v70; // [rsp+158h] [rbp+20h]

  if ( UFG::Editor::GetActiveView() && UFG::Editor::IsActive() )
  {
    v3 = UFG::Editor::GetActiveView()[10];
    v4 = 0i64;
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        p_mFOVOffset = &mCurrentCamera->mCamera.mFOVOffset;
      else
        p_mFOVOffset = 0i64;
      v7 = p_mFOVOffset[44];
      y = p_mFOVOffset[45];
      z = p_mFOVOffset[46];
    }
    else
    {
      v7 = *(float *)&v3[11].mPrev;
      y = *((float *)&v3[11].mPrev + 1);
      z = *(float *)&v3[11].mNext;
    }
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      v10 = UFG::Director::Get()->mCurrentCamera;
      if ( v10 )
        v11 = &v10->mCamera.mFOVOffset;
      else
        v11 = 0i64;
      x = v11[32];
      v13 = v11[33];
      v14 = v11[34];
    }
    else
    {
      x = *(float *)&v3[8].mPrev;
      v13 = *((float *)&v3[8].mPrev + 1);
      v14 = *(float *)&v3[8].mNext;
    }
    v58 = v14;
    v59 = v13;
    v67 = x;
    if ( UFG::Editor::Camera::UsingGameCamera((UFG::Editor::Camera *)v3) )
    {
      v15 = UFG::Director::Get()->mCurrentCamera;
      if ( v15 )
        v16 = &v15->mCamera.mFOVOffset;
      else
        v16 = 0i64;
      v17 = v16[36];
      v70 = v16[37];
      v60 = v16[38];
    }
    else
    {
      v17 = *(float *)&v3[9].mPrev;
      v70 = *((float *)&v3[9].mPrev + 1);
      v60 = *(float *)&v3[9].mNext;
    }
    v69 = v17;
    DirForward = UFG::Editor::Camera::GetDirForward((UFG::Editor::Camera *)v3, &result);
    v19 = _xmm[0];
    x_low = LODWORD(DirForward->x);
    y_low = LODWORD(DirForward->y);
    z_low = LODWORD(DirForward->z);
  }
  else
  {
    v4 = 0i64;
    v23 = UFG::Director::Get()->mCurrentCamera;
    if ( v23 )
      p_mCamera = &v23->mCamera;
    else
      p_mCamera = 0i64;
    v19 = _xmm[0];
    x = p_mCamera->mTransformation.v0.x;
    v17 = p_mCamera->mTransformation.v1.x;
    x_low = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
    v7 = p_mCamera->mTransformation.v3.x;
    y_low = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
    z_low = LODWORD(p_mCamera->mTransformation.v2.z) ^ _xmm[0];
    y = p_mCamera->mTransformation.v3.y;
    z = p_mCamera->mTransformation.v3.z;
    v59 = p_mCamera->mTransformation.v0.y;
    v67 = x;
    v58 = p_mCamera->mTransformation.v0.z;
    v70 = p_mCamera->mTransformation.v1.y;
    v69 = v17;
    v60 = p_mCamera->mTransformation.v1.z;
  }
  v25 = z_low ^ v19;
  v26 = y_low ^ v19;
  v27 = x_low ^ v19;
  if ( this->m_lockListenerPosition )
    goto LABEL_46;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  v29 = z;
  v30 = v7;
  v31 = y;
  v61 = z;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v29 = m_pTransformNodeComponent->mWorldTransform.v3.z;
    v30 = m_pTransformNodeComponent->mWorldTransform.v3.x;
    v31 = m_pTransformNodeComponent->mWorldTransform.v3.y;
    v61 = v29;
  }
  if ( this->m_positionListenerAtCamera )
  {
    if ( v7 == UFG::qVector3::msZero.x && y == UFG::qVector3::msZero.y && z == UFG::qVector3::msZero.z )
      goto LABEL_39;
    v32 = this->m_position.z;
    v33 = this->m_position.y + (float)((float)(y - this->m_position.y) * 0.2);
    this->m_position.x = this->m_position.x + (float)((float)(v7 - this->m_position.x) * 0.2);
    this->m_position.y = v33;
    this->m_position.z = v32 + (float)((float)(z - v32) * 0.2);
  }
  else
  {
    v34 = (float)((float)(v29 - this->m_position.z) * 0.2) + this->m_position.z;
    v35 = (float)((float)(v31 - this->m_position.y) * 0.2) + this->m_position.y;
    this->m_position.x = (float)((float)(v30 - this->m_position.x) * 0.2) + this->m_position.x;
    this->m_position.z = v34;
    this->m_position.y = v35;
  }
  v17 = v69;
LABEL_39:
  if ( this->m_triggerPositionAtCamera )
  {
    if ( v7 != UFG::qVector3::msZero.x || y != UFG::qVector3::msZero.y || z != UFG::qVector3::msZero.z )
    {
      this->m_triggerPosition.x = v7;
      this->m_triggerPosition.y = y;
      this->m_triggerPosition.z = z;
    }
  }
  else
  {
    this->m_triggerPosition.x = v30;
    this->m_triggerPosition.y = v31;
    this->m_triggerPosition.z = v61;
  }
  x = v67;
LABEL_46:
  v65.w = 1.0;
  v65.x = this->m_position.x;
  *(_QWORD *)&v64.x = __PAIR64__(LODWORD(v70), LODWORD(v17));
  *(_QWORD *)&v64.z = LODWORD(v60);
  v65.y = this->m_position.y;
  v37 = v65.y - this->m_prevPosition.y;
  v65.z = this->m_position.z;
  v38 = (float)(1.0 / delta_sec) * (float)(v65.x - this->m_prevPosition.x);
  v39 = (float)(1.0 / delta_sec) * (float)(v65.z - this->m_prevPosition.z);
  this->m_velocity.x = v38;
  this->m_velocity.z = v39;
  this->m_velocity.y = (float)(1.0 / delta_sec) * v37;
  v40 = FLOAT_27_777779;
  if ( v38 <= -27.777779 )
  {
    v38 = FLOAT_N27_777779;
  }
  else if ( v38 >= 27.777779 )
  {
    v38 = FLOAT_27_777779;
  }
  this->m_velocity.x = v38;
  v41 = this->m_velocity.y;
  if ( v41 <= -27.777779 )
  {
    v41 = FLOAT_N27_777779;
  }
  else if ( v41 >= 27.777779 )
  {
    v41 = FLOAT_27_777779;
  }
  this->m_velocity.y = v41;
  v42 = this->m_velocity.z;
  if ( v42 <= -27.777779 )
  {
    v42 = FLOAT_N27_777779;
    goto LABEL_58;
  }
  if ( v42 < 27.777779 )
LABEL_58:
    v40 = v42;
  this->m_velocity.z = v40;
  v43 = v25 ^ v19;
  v63.w = -0.0;
  LODWORD(v62.x) = v27 ^ v19;
  v44 = LODWORD(x) ^ v19;
  v45 = this->m_triggerPosition.x - this->m_prevTriggerPosition.x;
  LODWORD(v63.z) = LODWORD(v58) ^ v19;
  LODWORD(v63.y) = LODWORD(v59) ^ v19;
  LODWORD(v62.y) = v26 ^ v19;
  v46 = this->m_triggerPosition.y - this->m_prevTriggerPosition.y;
  v47 = (float)((float)((float)(this->m_velocity.y - this->m_prevVelocity.y)
                      * (float)(this->m_velocity.y - this->m_prevVelocity.y))
              + (float)((float)(v38 - this->m_prevVelocity.x) * (float)(v38 - this->m_prevVelocity.x)))
      + (float)((float)(this->m_velocity.z - this->m_prevVelocity.z)
              * (float)(this->m_velocity.z - this->m_prevVelocity.z));
  v48 = this->m_triggerPosition.z - this->m_prevTriggerPosition.z;
  LODWORD(v63.x) = v44;
  v36 = 1.0 / delta_sec;
  this->m_highSpeedMode = (float)((float)((float)((float)(v36 * v46) * (float)(v36 * v46))
                                        + (float)((float)(v36 * v45) * (float)(v36 * v45)))
                                + (float)((float)(v36 * v48) * (float)(v36 * v48))) > (float)((float)(this->m_highSpeedModeThreshhold_kmPhr * 0.27777779)
                                                                                            * (float)(this->m_highSpeedModeThreshhold_kmPhr * 0.27777779));
  UFG::TiDo::m_pInstance->vfptr->UpdateListenerTriggerRegions(UFG::TiDo::m_pInstance, this);
  v49 = this->m_position.y;
  v50 = this->m_position.z;
  this->m_prevPosition.x = this->m_position.x;
  this->m_prevPosition.y = v49;
  this->m_prevPosition.z = v50;
  v51 = this->m_velocity.y;
  v52 = this->m_velocity.z;
  this->m_prevVelocity.x = this->m_velocity.x;
  this->m_prevVelocity.y = v51;
  this->m_prevVelocity.z = v52;
  v53 = this->m_triggerPosition.y;
  v54 = this->m_triggerPosition.z;
  this->m_prevTriggerPosition.x = this->m_triggerPosition.x;
  this->m_prevTriggerPosition.y = v53;
  this->m_prevTriggerPosition.z = v54;
  m_listenerId = this->m_listenerId;
  if ( m_listenerId < 8 )
    v4 = &gAudioListener[m_listenerId];
  *(_QWORD *)&v62.z = v43 | 0x8000000000000000ui64;
  v4->m_matrix.v0 = v62;
  v4->m_matrix.v1 = v63;
  v4->m_matrix.v2 = v64;
  v4->m_matrix.v3 = v65;
  if ( v47 > 1.0 || v47 < 18225.0 )
  {
    v56 = this->m_velocity.y;
    v57 = this->m_velocity.z;
    v4->m_velocity.x = this->m_velocity.x;
    v4->m_velocity.y = v56;
    v4->m_velocity.z = v57;
  }
  v4->vfptr->Update(v4);
}

// File Line: 230
// RVA: 0x145D00
float __fastcall UFG::AudioListener::GetDistance2From(UFG::AudioListener *this, UFG::qVector3 *pos)
{
  return (float)((float)((float)(pos->y - this->m_position.y) * (float)(pos->y - this->m_position.y))
               + (float)((float)(pos->x - this->m_position.x) * (float)(pos->x - this->m_position.x)))
       + (float)((float)(pos->z - this->m_position.z) * (float)(pos->z - this->m_position.z));
}

