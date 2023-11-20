// File Line: 39
// RVA: 0x1D0610
void Render::ParticleRaycaster::InitRaycastDirections(void)
{
  float v0; // xmm0_4
  float v1; // xmm4_4
  float v2; // xmm0_4

  dword_1423661F4 = LODWORD(UFG::qVector3::msAxisX.z) ^ _xmm[0];
  dword_1423661F0 = LODWORD(UFG::qVector3::msAxisX.y) ^ _xmm[0];
  Render::ParticleRaycaster::sRaycastDirections[0] = UFG::qVector3::msAxisX;
  dword_14236620C = LODWORD(UFG::qVector3::msAxisY.z) ^ _xmm[0];
  dword_142366208 = LODWORD(UFG::qVector3::msAxisY.y) ^ _xmm[0];
  dword_142366224 = LODWORD(UFG::qVector3::msAxisZ.z) ^ _xmm[0];
  LODWORD(v0) = (unsigned __int128)_mm_sqrt_ps((__m128)LODWORD(FLOAT_2_0));
  dword_1423661EC = LODWORD(UFG::qVector3::msAxisX.x) ^ _xmm[0];
  dword_142366220 = LODWORD(UFG::qVector3::msAxisZ.y) ^ _xmm[0];
  *(UFG::qVector3 *)byte_1423661F8 = UFG::qVector3::msAxisY;
  v1 = 1.0 / v0;
  dword_142366204 = LODWORD(UFG::qVector3::msAxisY.x) ^ _xmm[0];
  *(UFG::qVector3 *)byte_142366210 = UFG::qVector3::msAxisZ;
  *(float *)&dword_142366228 = 1.0 / v0;
  *(float *)&dword_14236622C = 1.0 / v0;
  dword_14236621C = LODWORD(UFG::qVector3::msAxisZ.x) ^ _xmm[0];
  *(float *)&dword_142366230 = (float)(1.0 / v0) * 0.0;
  LODWORD(v2) = (unsigned __int128)_mm_sqrt_ps((__m128)LODWORD(FLOAT_3_0));
  *(float *)&dword_142366234 = 1.0 / v2;
  *(float *)&dword_14236623C = 1.0 / v2;
  *(float *)&dword_142366240 = 1.0 / v2;
  *(float *)&dword_142366250 = 1.0 / v2;
  *(float *)&dword_142366254 = 1.0 / v2;
  *(float *)&dword_142366238 = (float)(1.0 / v2) * -1.0;
  *(float *)&dword_14236625C = 1.0 / v2;
  *(float *)&dword_142366244 = (float)(1.0 / v2) * -1.0;
  *(float *)&dword_142366248 = (float)(1.0 / v2) * -1.0;
  *(float *)&dword_14236624C = (float)(1.0 / v2) * -1.0;
  *(float *)&dword_14236626C = v1 * 0.0;
  *(float *)&dword_142366264 = v1 * -1.0;
  *(float *)&dword_142366268 = v1 * -1.0;
  *(float *)&dword_142366258 = (float)(1.0 / v2) * -1.0;
  *(float *)&dword_142366260 = (float)(1.0 / v2) * -1.0;
}

// File Line: 59
// RVA: 0x1C1D90
void __fastcall Render::ParticleRaycaster::ParticleRaycaster(Render::ParticleRaycaster *this)
{
  Render::ParticleRaycaster *v1; // rdi
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = 0;
  *(_QWORD *)&this->mMode = 0i64;
  this->mRaycastResultListLength = 12;
  v3 = 384i64;
  if ( !is_mul_ok(0xCui64, 0x20ui64) )
    v3 = -1i64;
  v4 = UFG::qMalloc(v3, "ParticleRaycaster::mraycastresultlist", 0i64);
  v1->mRaycastResultList = (Render::ParticleRaycaster::RaycastResult *)v4;
  UFG::qMemSet(v4, 0, 32 * v1->mRaycastResultListLength);
  if ( v1->mRaycastResultListLength > 0 )
  {
    do
    {
      v1->mRaycastResultList[v2].index = v2;
      ++v2;
    }
    while ( v2 < v1->mRaycastResultListLength );
  }
  Render::ParticleRaycaster::InitRaycastDirections();
}

// File Line: 89
// RVA: 0x1CC390
__int64 __fastcall Render::ParticleRaycaster::GetHitPlanes(Render::ParticleRaycaster *this, unsigned int sizeOfOutPlaneArray, Render::ParticleRaycaster::Plane *outPlanes)
{
  Render::ParticleRaycaster::Plane *v3; // r11
  Render::ParticleRaycaster *v4; // r10
  signed __int64 v6; // rbx
  unsigned int v7; // er9
  Render::ParticleRaycaster::RaycastResult *v8; // rcx
  signed __int64 v9; // r8
  float v10; // xmm0_4
  float v11; // xmm1_4
  signed __int64 v12; // rdx
  float v13; // xmm0_4
  float v14; // xmm1_4

  v3 = outPlanes;
  v4 = this;
  if ( this->mMode == Mode_Immediate )
    return 0i64;
  v6 = 0i64;
  v7 = 0;
  if ( this->mRaycastResultListLength )
  {
    do
    {
      v8 = v4->mRaycastResultList;
      v9 = v7;
      if ( v4->mRaycastResultList[v9].valid )
      {
        if ( v8[v9].hit )
        {
          v10 = v8[v9].point.y;
          v11 = v8[v9].point.z;
          v12 = v6;
          v6 = (unsigned int)(v6 + 1);
          v3[v12].position.x = v8[v9].point.x;
          v3[v12].position.y = v10;
          v3[v12].position.z = v11;
          v13 = v4->mRaycastResultList[v9].normal.y;
          v14 = v4->mRaycastResultList[v9].normal.z;
          v3[v12].normal.x = v4->mRaycastResultList[v9].normal.x;
          v3[v12].normal.y = v13;
          v3[v12].normal.z = v14;
        }
      }
      ++v7;
    }
    while ( v7 < v4->mRaycastResultListLength );
  }
  return (unsigned int)v6;
}

// File Line: 111
// RVA: 0x1C75D0
void __fastcall Render::ParticleRaycaster::AsyncRayCallback(UFG::RayCastData *rayCastData, UFG::SimComponent *sim_component, void *user_data)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  *((_BYTE *)user_data + 24) = 1;
  *((_BYTE *)user_data + 25) = rayCastData->hit;
  v3 = rayCastData->point.y;
  v4 = rayCastData->point.z;
  *(float *)user_data = rayCastData->point.x;
  *((float *)user_data + 1) = v3;
  *((float *)user_data + 2) = v4;
  v5 = rayCastData->normal.y;
  v6 = rayCastData->normal.z;
  *((_DWORD *)user_data + 3) = LODWORD(rayCastData->normal.x);
  *((float *)user_data + 4) = v5;
  *((float *)user_data + 5) = v6;
}

// File Line: 127
// RVA: 0x1D0FA0
__int64 __fastcall Render::ParticleRaycaster::IssueQueries(Render::ParticleRaycaster *this, unsigned int maxNumRaycasts)
{
  unsigned int v2; // edi
  Render::ParticleRaycaster *v3; // rsi
  unsigned int v4; // ebx
  unsigned int v5; // er14
  unsigned int v6; // eax
  float v7; // xmm5_4
  float v8; // xmm6_4
  __int64 v9; // rax
  Render::ParticleRaycaster::RaycastResult *v10; // ST30_8
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v14; // [rsp+40h] [rbp-48h]
  float v15; // [rsp+44h] [rbp-44h]
  float v16; // [rsp+48h] [rbp-40h]
  float v17; // [rsp+50h] [rbp-38h]
  float v18; // [rsp+54h] [rbp-34h]
  float v19; // [rsp+58h] [rbp-30h]

  v2 = maxNumRaycasts;
  v3 = this;
  v4 = 0;
  v5 = 0;
  do
  {
    if ( v4 == v2 )
      break;
    v6 = v3->mRaycastComboIndex;
    v7 = v3->mPosition.y;
    v8 = v3->mPosition.z;
    v17 = v3->mPosition.x;
    v18 = v7;
    v19 = v8;
    v9 = v5 + 6 * v6;
    v10 = &v3->mRaycastResultList[v5];
    v11 = v7 + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].y * 5.0);
    v12 = v8 + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].z * 5.0);
    v14 = v17 + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].x * 5.0);
    v15 = v11;
    v16 = v12;
    ++v5;
    v4 += UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
            UFG::BasePhysicsSystem::mInstance,
            (UFG::qVector3 *)&v17,
            (UFG::qVector3 *)&v14,
            14u,
            Render::ParticleRaycaster::AsyncRayCallback,
            0i64,
            v10) != 0;
  }
  while ( v5 < 6 );
  return v4;
}

