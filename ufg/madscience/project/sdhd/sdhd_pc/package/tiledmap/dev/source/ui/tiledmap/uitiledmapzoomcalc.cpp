// File Line: 68
// RVA: 0xCECA0
float __fastcall UFG::UITiledMapZoomCalc::ZoomHistoryAverage(UFG::UITiledMapZoomCalc *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float *v3; // rcx
  signed __int64 v4; // rax
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm3_4

  v1 = this->mZoomHistory[0];
  v2 = 0.0;
  v3 = &this->mZoomHistory[1];
  v4 = 2i64;
  v5 = v1;
  do
  {
    v6 = *(v3 - 1);
    if ( v6 < v1 )
      v1 = *(v3 - 1);
    if ( v6 > v5 )
      v5 = *(v3 - 1);
    v7 = *v3;
    v8 = v2 + v6;
    if ( *v3 < v1 )
      v1 = *v3;
    if ( v7 > v5 )
      v5 = *v3;
    v9 = v3[1];
    v10 = v8 + v7;
    if ( v9 < v1 )
      v1 = v3[1];
    if ( v9 > v5 )
      v5 = v3[1];
    v11 = v3[2];
    v12 = v10 + v9;
    if ( v11 < v1 )
      v1 = v3[2];
    if ( v11 > v5 )
      v5 = v3[2];
    v13 = v3[3];
    v14 = v12 + v11;
    if ( v13 < v1 )
      v1 = v3[3];
    if ( v13 > v5 )
      v5 = v3[3];
    v15 = v14 + v13;
    v16 = v3[4];
    if ( v16 < v1 )
      v1 = v3[4];
    if ( v16 > v5 )
      v5 = v3[4];
    v3 += 6;
    v2 = v15 + v16;
    --v4;
  }
  while ( v4 );
  return (float)(v2 - (float)(v5 + v1)) * 0.099998996;
}

// File Line: 93
// RVA: 0xCCE90
void __fastcall UFG::UITiledMapZoomCalc::Update(UFG::UITiledMapZoomCalc *this, float elapsedTime, UFG::qVector3 *playerVelocity, bool playerOnFoot, UFG::UIMapInteriorManager *interiorManager)
{
  bool v5; // si
  UFG::UITiledMapZoomCalc *v6; // rbx
  float v7; // xmm1_4
  __m128 v8; // xmm1
  float v9; // xmm1_4
  int v10; // ecx
  float v11; // xmm0_4
  signed __int64 v12; // rax
  signed __int64 v13; // rcx
  float v14; // xmm7_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  UFG::eInteriors v19; // edx
  unsigned int v20; // er8
  __int64 v21; // rax
  UFG::UITiledMapInteriorData *v22; // rcx
  float v23; // xmm0_4
  float v24; // xmm6_4
  float *v25; // rcx
  UFG::CopSystem *v26; // rax
  float v27; // xmm6_4
  float v28; // xmm1_4
  int v29; // xmm1_4

  v5 = playerOnFoot;
  v6 = this;
  v7 = 0.0;
  if ( !playerOnFoot )
  {
    v8 = (__m128)LODWORD(playerVelocity->x);
    v8.m128_f32[0] = (float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(playerVelocity->y * playerVelocity->y);
    if ( v8.m128_f32[0] > 0.0 )
      v8.m128_i32[0] = (unsigned __int128)_mm_sqrt_ps(v8);
    if ( v8.m128_f32[0] >= UFG::gMinimapZoomMaxSpeed )
      v8.m128_f32[0] = UFG::gMinimapZoomMaxSpeed;
    v9 = v8.m128_f32[0] - UFG::gMinimapZoomMinSpeed;
    if ( v9 <= 0.0 )
      v9 = 0.0;
    v7 = v9 / (float)(UFG::gMinimapZoomMaxSpeed - UFG::gMinimapZoomMinSpeed);
  }
  v10 = (this->mZoomHistoryIndex + 1) % 12;
  v6->mZoomHistoryIndex = v10;
  v6->mZoomHistory[v10] = v7;
  v11 = UFG::UITiledMapZoomCalc::ZoomHistoryAverage(v6);
  v12 = (signed __int64)&v6->mZoomHistory[1];
  v13 = 2i64;
  v14 = v11;
  do
  {
    v12 += 24i64;
    v15 = (float)(v14 + *(float *)(v12 - 20)) * 0.5;
    v16 = (float)(v14 + *(float *)(v12 - 24)) * 0.5;
    *(float *)(v12 - 28) = (float)(v14 + *(float *)(v12 - 28)) * 0.5;
    *(float *)(v12 - 20) = v15;
    *(float *)(v12 - 24) = v16;
    v17 = (float)(v14 + *(float *)(v12 - 12)) * 0.5;
    *(float *)(v12 - 16) = (float)(v14 + *(float *)(v12 - 16)) * 0.5;
    *(float *)(v12 - 12) = v17;
    *(float *)(v12 - 8) = (float)(v14 + *(float *)(v12 - 8)) * 0.5;
    --v13;
  }
  while ( v13 );
  if ( UFG::UITiledMapTweakables::UseDebugZoomLevel )
  {
    v18 = UFG::UITiledMapTweakables::DebugZoomLevel;
    v6->mScale = UFG::UITiledMapTweakables::DebugZoomLevel;
  }
  else if ( UFG::UITiledMapZoomCalc::gScaleIsLocked )
  {
    v18 = UFG::UITiledMapZoomCalc::gLockedScale;
    if ( interiorManager->mActive )
    {
      v18 = UFG::UITiledMapZoomCalc::gLockedScale * UFG::UITiledMapZoomCalc::gInteriorMapZoom;
      v6->mInteriorActiveLastFrame = 1;
    }
    v6->mScale = v18;
  }
  else if ( interiorManager->mActive )
  {
    v19 = interiorManager->mActiveInterior;
    if ( v19 == INTERIOR_NONE )
      goto LABEL_23;
    v20 = interiorManager->mNumInteriors;
    v21 = 0i64;
    if ( !v20 )
      goto LABEL_23;
    v22 = interiorManager->mData;
    while ( v22->InteriorId != v19 )
    {
      v21 = (unsigned int)(v21 + 1);
      ++v22;
      if ( (unsigned int)v21 >= v20 )
        goto LABEL_23;
    }
    v25 = (float *)&interiorManager->mData[v21].InteriorId;
    if ( v25 )
      v23 = v25[14];
    else
LABEL_23:
      v23 = *(float *)&FLOAT_1_0;
    v24 = UFG::UITiledMapZoomCalc::gInteriorMapZoom;
    v6->mInteriorActiveLastFrame = 1;
    v18 = v24 * v23;
    v6->mScale = v18;
  }
  else if ( v5 )
  {
    v18 = UFG::gMinimapZoomOnFoot;
    if ( UFG::UI::IsPlayerInCombat() )
      v18 = v18 * UFG::gMinimapZoomCombatMultiplier;
  }
  else
  {
    v26 = UFG::CopSystem::Instance();
    if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v26->vfptr[6].__vecDelDtor)(v26) )
      v18 = UFG::gMinimapZoomDuringPoliceChase;
    else
      v18 = UFG::gMinimapZoomAtMinSpeed
          - (float)((float)(UFG::gMinimapZoomAtMinSpeed - UFG::gMinimapZoomAtMaxSpeed) * v14);
  }
  if ( !interiorManager->mActive && v6->mInteriorActiveLastFrame )
  {
    v6->mScale = v18;
    v6->mInteriorActiveLastFrame = 0;
  }
  v27 = v18 - v6->mScale;
  v28 = v6->mScale * 0.1;
  if ( COERCE_FLOAT(LODWORD(v27) & _xmm) < 0.0020000001 )
    v27 = 0.0;
  if ( v27 > v28 )
    v27 = v6->mScale * 0.1;
  v29 = LODWORD(v28) ^ _xmm[0];
  if ( v27 < *(float *)&v29 )
    v27 = *(float *)&v29;
  v6->mScale = v6->mScale + v27;
}

// File Line: 185
// RVA: 0xC6120
void __fastcall UFG::UITiledMapZoomCalc::LockScale(float scale)
{
  UFG::UITiledMapZoomCalc::gLockedScale = scale;
  UFG::UITiledMapZoomCalc::gScaleIsLocked = 1;
}

// File Line: 192
// RVA: 0xCBDA0
void UFG::UITiledMapZoomCalc::UnlockScale(void)
{
  UFG::UITiledMapZoomCalc::gScaleIsLocked = 0;
}

