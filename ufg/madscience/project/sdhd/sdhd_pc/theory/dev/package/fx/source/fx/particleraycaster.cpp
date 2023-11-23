// File Line: 39
// RVA: 0x1D0610
void Render::ParticleRaycaster::InitRaycastDirections(void)
{
  Render::ParticleRaycaster::sRaycastDirections[0] = UFG::qVector3::msAxisX;
  dword_1423661F4 = LODWORD(UFG::qVector3::msAxisX.z) ^ _xmm[0];
  dword_1423661F0 = LODWORD(UFG::qVector3::msAxisX.y) ^ _xmm[0];
  *(UFG::qVector3 *)byte_1423661F8 = UFG::qVector3::msAxisY;
  dword_14236620C = LODWORD(UFG::qVector3::msAxisY.z) ^ _xmm[0];
  *(UFG::qVector3 *)byte_142366210 = UFG::qVector3::msAxisZ;
  dword_142366208 = LODWORD(UFG::qVector3::msAxisY.y) ^ _xmm[0];
  dword_142366224 = LODWORD(UFG::qVector3::msAxisZ.z) ^ _xmm[0];
  dword_1423661EC = LODWORD(UFG::qVector3::msAxisX.x) ^ _xmm[0];
  dword_142366220 = LODWORD(UFG::qVector3::msAxisZ.y) ^ _xmm[0];
  dword_142366204 = LODWORD(UFG::qVector3::msAxisY.x) ^ _xmm[0];
  *(float *)&dword_142366228 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(FLOAT_2_0)).m128_f32[0];
  dword_14236622C = dword_142366228;
  dword_14236621C = LODWORD(UFG::qVector3::msAxisZ.x) ^ _xmm[0];
  *(float *)&dword_142366230 = *(float *)&dword_142366228 * 0.0;
  *(float *)&dword_142366234 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(FLOAT_3_0)).m128_f32[0];
  dword_14236623C = dword_142366234;
  dword_142366240 = dword_142366234;
  dword_142366250 = dword_142366234;
  dword_142366254 = dword_142366234;
  *(float *)&dword_142366238 = *(float *)&dword_142366234 * -1.0;
  dword_14236625C = dword_142366234;
  *(float *)&dword_142366244 = *(float *)&dword_142366234 * -1.0;
  *(float *)&dword_142366248 = *(float *)&dword_142366234 * -1.0;
  *(float *)&dword_14236624C = *(float *)&dword_142366234 * -1.0;
  *(float *)&dword_14236626C = *(float *)&dword_142366228 * 0.0;
  *(float *)&dword_142366264 = *(float *)&dword_142366228 * -1.0;
  *(float *)&dword_142366268 = *(float *)&dword_142366228 * -1.0;
  *(float *)&dword_142366258 = *(float *)&dword_142366234 * -1.0;
  *(float *)&dword_142366260 = *(float *)&dword_142366234 * -1.0;
}

// File Line: 59
// RVA: 0x1C1D90
void __fastcall Render::ParticleRaycaster::ParticleRaycaster(Render::ParticleRaycaster *this)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // [rsp+40h] [rbp+8h]

  v2 = 0;
  *(_QWORD *)&this->mMode = 0i64;
  this->mRaycastResultListLength = 12;
  v3 = 384i64;
  if ( !is_mul_ok(0xCui64, 0x20ui64) )
    v3 = -1i64;
  v4 = UFG::qMalloc(v3, "ParticleRaycaster::mraycastresultlist", 0i64);
  this->mRaycastResultList = (Render::ParticleRaycaster::RaycastResult *)v4;
  UFG::qMemSet(v4, 0, 32 * this->mRaycastResultListLength);
  if ( this->mRaycastResultListLength )
  {
    do
    {
      this->mRaycastResultList[v2].index = v2;
      ++v2;
    }
    while ( v2 < this->mRaycastResultListLength );
  }
  Render::ParticleRaycaster::InitRaycastDirections();
}

// File Line: 89
// RVA: 0x1CC390
__int64 __fastcall Render::ParticleRaycaster::GetHitPlanes(
        Render::ParticleRaycaster *this,
        unsigned int sizeOfOutPlaneArray,
        Render::ParticleRaycaster::Plane *outPlanes)
{
  __int64 v6; // rbx
  unsigned int i; // r9d
  Render::ParticleRaycaster::RaycastResult *mRaycastResultList; // rcx
  __int64 v9; // r8
  float y; // xmm0_4
  float z; // xmm1_4
  __int64 v12; // rdx
  float v13; // xmm0_4
  float v14; // xmm1_4

  if ( this->mMode == Mode_Immediate )
    return 0i64;
  v6 = 0i64;
  for ( i = 0; i < this->mRaycastResultListLength; ++i )
  {
    mRaycastResultList = this->mRaycastResultList;
    v9 = i;
    if ( this->mRaycastResultList[v9].valid && mRaycastResultList[v9].hit )
    {
      y = mRaycastResultList[v9].point.y;
      z = mRaycastResultList[v9].point.z;
      v12 = v6;
      v6 = (unsigned int)(v6 + 1);
      outPlanes[v12].position.x = mRaycastResultList[v9].point.x;
      outPlanes[v12].position.y = y;
      outPlanes[v12].position.z = z;
      v13 = this->mRaycastResultList[v9].normal.y;
      v14 = this->mRaycastResultList[v9].normal.z;
      outPlanes[v12].normal.x = this->mRaycastResultList[v9].normal.x;
      outPlanes[v12].normal.y = v13;
      outPlanes[v12].normal.z = v14;
    }
  }
  return (unsigned int)v6;
}

// File Line: 111
// RVA: 0x1C75D0
void __fastcall Render::ParticleRaycaster::AsyncRayCallback(
        UFG::RayCastData *rayCastData,
        UFG::SimComponent *sim_component,
        float *user_data)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  *((_BYTE *)user_data + 24) = 1;
  *((_BYTE *)user_data + 25) = rayCastData->hit;
  y = rayCastData->point.y;
  z = rayCastData->point.z;
  *user_data = rayCastData->point.x;
  user_data[1] = y;
  user_data[2] = z;
  v5 = rayCastData->normal.y;
  v6 = rayCastData->normal.z;
  user_data[3] = rayCastData->normal.x;
  user_data[4] = v5;
  user_data[5] = v6;
}

// File Line: 127
// RVA: 0x1D0FA0
__int64 __fastcall Render::ParticleRaycaster::IssueQueries(
        Render::ParticleRaycaster *this,
        unsigned int maxNumRaycasts)
{
  unsigned int v4; // ebx
  unsigned int i; // r14d
  unsigned int mRaycastComboIndex; // eax
  float y; // xmm5_4
  float z; // xmm6_4
  __int64 v9; // rax
  int v10; // xmm5_4
  int v11; // xmm6_4
  Render::ParticleRaycaster::RaycastResult *v13; // [rsp+30h] [rbp-58h]
  int v14[4]; // [rsp+40h] [rbp-48h] BYREF
  int v15[4]; // [rsp+50h] [rbp-38h] BYREF

  v4 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( v4 == maxNumRaycasts )
      break;
    mRaycastComboIndex = this->mRaycastComboIndex;
    y = this->mPosition.y;
    z = this->mPosition.z;
    v15[0] = LODWORD(this->mPosition.x);
    *(float *)&v15[1] = y;
    *(float *)&v15[2] = z;
    v9 = i + 6 * mRaycastComboIndex;
    v13 = &this->mRaycastResultList[i];
    *(float *)&v10 = y + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].y * 5.0);
    *(float *)&v11 = z + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].z * 5.0);
    *(float *)v14 = *(float *)v15 + (float)(Render::ParticleRaycaster::sRaycastDirections[v9].x * 5.0);
    v14[1] = v10;
    v14[2] = v11;
    v4 += UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
            UFG::BasePhysicsSystem::mInstance,
            (UFG::qVector3 *)v15,
            (UFG::qVector3 *)v14,
            14u,
            (void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *))Render::ParticleRaycaster::AsyncRayCallback,
            0i64,
            v13);
  }
  return v4;
}

