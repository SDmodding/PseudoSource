// File Line: 56
// RVA: 0x1453A40
__int64 dynamic_initializer_for__Render::Softbody::s_List__()
{
  return atexit(dynamic_atexit_destructor_for__Render::Softbody::s_List__);
}

// File Line: 57
// RVA: 0x1453A30
__int64 dynamic_initializer_for__Render::ISoftbody::s_DeletionQueue__()
{
  return atexit(dynamic_atexit_destructor_for__Render::ISoftbody::s_DeletionQueue__);
}

// File Line: 77
// RVA: 0x20C00
void __fastcall Render::VerletCloth::VerletCloth(Render::VerletCloth *this, Illusion::SoftbodyData *softbodyData, Illusion::Mesh *src_mesh)
{
  Render::VerletCloth *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  unsigned __int64 v16; // rcx

  v3 = this;
  this->mPrev = (UFG::qNode<Render::VerletCloth,Render::VerletCloth> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::VerletCloth,Render::VerletCloth> *)&this->mPrev;
  this->mPrevSoftVertPosUnconstrained = 0i64;
  this->mPrevSoftVertPosConstrained = 0i64;
  this->mNeedsReset = 2;
  v4 = UFG::qMatrix44::msIdentity.v0.y;
  v5 = UFG::qMatrix44::msIdentity.v0.z;
  v6 = UFG::qMatrix44::msIdentity.v0.w;
  this->mPrevWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mPrevWorld.v0.y = v4;
  this->mPrevWorld.v0.z = v5;
  this->mPrevWorld.v0.w = v6;
  v7 = UFG::qMatrix44::msIdentity.v1.y;
  v8 = UFG::qMatrix44::msIdentity.v1.z;
  v9 = UFG::qMatrix44::msIdentity.v1.w;
  this->mPrevWorld.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mPrevWorld.v1.y = v7;
  this->mPrevWorld.v1.z = v8;
  this->mPrevWorld.v1.w = v9;
  v10 = UFG::qMatrix44::msIdentity.v2.y;
  v11 = UFG::qMatrix44::msIdentity.v2.z;
  v12 = UFG::qMatrix44::msIdentity.v2.w;
  this->mPrevWorld.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mPrevWorld.v2.y = v10;
  this->mPrevWorld.v2.z = v11;
  this->mPrevWorld.v2.w = v12;
  v13 = UFG::qMatrix44::msIdentity.v3.y;
  v14 = UFG::qMatrix44::msIdentity.v3.z;
  v15 = UFG::qMatrix44::msIdentity.v3.w;
  this->mPrevWorld.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mPrevWorld.v3.y = v13;
  this->mPrevWorld.v3.z = v14;
  this->mPrevWorld.v3.w = v15;
  this->mPendingTimeStep = 0.0;
  v16 = (6 * softbodyData->mNumSoftVertIndices + 15) & 0xFFFFFFF0;
  v3->mPrevSoftVertPositionsSize = v16;
  v3->mPrevSoftVertPosConstrained = (Render::PackedPosition *)UFG::qMalloc(
                                                                v16,
                                                                "VerletCloth::mPrevSoftVertPosConstrained",
                                                                0x8000ui64);
  v3->mPrevSoftVertPosUnconstrained = (Render::PackedPosition *)UFG::qMalloc(
                                                                  v3->mPrevSoftVertPositionsSize,
                                                                  "VerletCloth::mPrevSoftVertPosUnconstrained",
                                                                  0x8000ui64);
}

// File Line: 104
// RVA: 0x214B0
void __fastcall Render::VerletCloth::FillTaskParameters(Render::VerletCloth *this, Render::sSoftbodyParams *output, Illusion::Model *source_model, UFG::qMatrix44 *worldMat, UFG::qMatrix44 *invWorldMat, Render::Softbody *context)
{
  Render::sSoftbodyParams *v6; // rdi
  Illusion::Model *v7; // r14
  Render::VerletCloth *v8; // r13
  UFG::qMatrix44 *v9; // rbp
  float v10; // xmm6_4
  __m128 v11; // xmm4
  __m128 v12; // xmm2
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // eax
  __int64 v16; // rax
  _QWORD *v17; // rax
  char *v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rax
  __int64 v21; // rax
  signed __int64 v22; // rax
  char *v23; // rax
  __int64 v24; // rax
  signed __int64 v25; // rdx
  UFG::qVector4 v26; // xmm0
  UFG::qVector4 v27; // xmm1
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **v28; // r14
  UFG::qVector4 v29; // xmm3
  UFG::qVector4 v30; // xmm2
  UFG::qVector4 v31; // xmm1
  Render::Softbody *v32; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **v33; // rsi
  Render::Softbody *v34; // rbx
  Render::Softbody *i; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **j; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **k; // rbx
  UFG::qVector4 v38; // xmm3
  UFG::qVector4 v39; // xmm2
  UFG::qVector4 v40; // xmm1
  unsigned int v41; // eax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-B8h]
  UFG::qMatrix44 v43; // [rsp+60h] [rbp-78h]

  v6 = output;
  v7 = source_model;
  v8 = this;
  v9 = worldMat;
  UFG::qMatrix44::operator*(&this->mPrevWorld, &result, invWorldMat);
  v10 = v8->mPendingTimeStep;
  if ( v10 <= 0.00000011920929
    || v10 > 0.30000001
    || UFG::qMatrix44::operator==(&v8->mPrevWorld, &UFG::qMatrix44::msIdentity) )
  {
    v8->mPendingTimeStep = 0.0;
  }
  else
  {
    v11 = (__m128)LODWORD(result.v3.y);
    v12 = v11;
    v12.m128_f32[0] = (float)((float)(v11.m128_f32[0] * v11.m128_f32[0]) + (float)(result.v3.x * result.v3.x))
                    + (float)(result.v3.z * result.v3.z);
    v13 = COERCE_FLOAT(_mm_sqrt_ps(v12)) / v10;
    if ( v13 > Render::VERLET_maxTranslationSpeed )
    {
      LODWORD(result.v3.w) = (_DWORD)FLOAT_1_0;
      result.v3.x = result.v3.x * (float)(Render::VERLET_maxTranslationSpeed / v13);
      result.v3.y = result.v3.y * (float)(Render::VERLET_maxTranslationSpeed / v13);
      result.v3.z = result.v3.z * (float)(Render::VERLET_maxTranslationSpeed / v13);
    }
  }
  v14 = v8->mPendingTimeStep;
  if ( v14 >= 0.1 )
    v14 = FLOAT_0_1;
  v6->timestep = v14;
  v6->friction = context->mFriction;
  v15 = context->mDrag;
  v6->noisetime = 0.0;
  v6->drag = v15;
  v16 = v7->mModelUser.mOffset;
  if ( v16 )
    v17 = (__int64 *)((char *)&v7->mModelUser.mOffset + v16);
  else
    v17 = 0i64;
  if ( *v17 )
    v18 = (char *)v17 + *v17;
  else
    v18 = 0i64;
  v6->spring_size = 4 * *((_DWORD *)v18 + 10);
  v19 = *((_QWORD *)v18 + 2);
  if ( v19 )
    v20 = (signed __int64)&v18[v19 + 16];
  else
    v20 = 0i64;
  v6->spring_data = (void *)v20;
  v6->remapper_size = 2 * *((_DWORD *)v18 + 11);
  v21 = *((_QWORD *)v18 + 3);
  if ( v21 )
    v22 = (signed __int64)&v18[v21 + 24];
  else
    v22 = 0i64;
  v6->remapper_data = (void *)v22;
  v6->soft_indices_count = *((_DWORD *)v18 + 8);
  v6->hard_indices_count = *((_DWORD *)v18 + 9) - *((_DWORD *)v18 + 8);
  if ( *(_QWORD *)v18 )
    v23 = &v18[*(_QWORD *)v18];
  else
    v23 = 0i64;
  v6->verlet_indices_data = v23;
  v24 = *((_QWORD *)v18 + 1);
  if ( v24 )
    v25 = (signed __int64)&v18[v24 + 8];
  else
    v25 = 0i64;
  v6->render_indices_data = (void *)v25;
  v26 = result.v0;
  v6->prev_soft_positions_unconstrained_data = v8->mPrevSoftVertPosUnconstrained;
  v27 = result.v2;
  v6->prev_soft_positions_constrained_data = v8->mPrevSoftVertPosConstrained;
  v28 = &context->mSoftbodySpaceShapes.mShapes.mNode.mNext;
  v6->delta_world_transform.v0 = v26;
  v6->delta_world_transform.v1 = result.v1;
  v6->delta_world_transform.v2 = v27;
  v6->delta_world_transform.v3 = result.v3;
  v29 = invWorldMat->v1;
  v30 = invWorldMat->v2;
  v31 = invWorldMat->v3;
  v6->inverse_world_transform.v0 = invWorldMat->v0;
  v6->inverse_world_transform.v1 = v29;
  v6->inverse_world_transform.v2 = v30;
  v6->inverse_world_transform.v3 = v31;
  v26.x = context->mAccel.x;
  v31.x = context->mAccel.y;
  v30.x = context->mAccel.z;
  v6->accel.w = 1.0;
  v6->accel.x = v26.x;
  v6->accel.y = v31.x;
  v6->accel.z = v30.x;
  v30.x = UFG::qVector4::msZero.z;
  v29.x = UFG::qVector4::msZero.w;
  v26.x = UFG::qVector4::msZero.x;
  v6->winddir.y = UFG::qVector4::msZero.y;
  v6->winddir.z = v30.x;
  v6->winddir.x = v26.x;
  v6->winddir.w = v29.x;
  v31.x = UFG::qVector4::msZero.y;
  v30.x = UFG::qVector4::msZero.z;
  v29.x = UFG::qVector4::msZero.w;
  v6->ground_plane.x = UFG::qVector4::msZero.x;
  v6->ground_plane.y = v31.x;
  v6->ground_plane.z = v30.x;
  v6->ground_plane.w = v29.x;
  v6->windspeed = 0.0;
  v6->need_reset = v8->mNeedsReset > 0;
  v32 = (Render::Softbody *)&context->mWorldSpaceShapes.mShapes.mNode.mNext[-1].mNext;
  if ( v32 != (Render::Softbody *)&context->mSoftbodySpaceShapes.mShapes.mNode.mNext )
  {
    do
    {
      ((void (__fastcall *)(Render::Softbody *, UFG::qMatrix44 *, UFG::qMatrix44 *))v32->mPrev->mPrev)(
        v32,
        invWorldMat,
        v9);
      v32 = (Render::Softbody *)&v32->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext;
    }
    while ( v32 != (Render::Softbody *)v28 );
  }
  UFG::qMatrix44::operator*(&context->mWorld, &v43, invWorldMat);
  UFG::qMatrix44::operator*(v9, &result, &context->mInvWorld);
  v33 = &context->mModelSpaceShapes.mShapes.mNode.mNext;
  v34 = (Render::Softbody *)&(*v28)[-1].mNext;
  if ( v34 != (Render::Softbody *)&context->mModelSpaceShapes.mShapes.mNode.mNext )
  {
    do
    {
      ((void (__fastcall *)(Render::Softbody *, UFG::qMatrix44 *, UFG::qMatrix44 *))v34->mPrev->mPrev)(
        v34,
        &v43,
        &result);
      v34 = (Render::Softbody *)&v34->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext;
    }
    while ( v34 != (Render::Softbody *)v33 );
  }
  *(_QWORD *)&v6->collision_plane_count = 0i64;
  for ( i = (Render::Softbody *)&(*v33)[-1].mNext;
        i != (Render::Softbody *)&context->mNext;
        i = (Render::Softbody *)&i->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext )
  {
    ((void (__fastcall *)(Render::Softbody *, Render::sSoftbodyParams *))i->mPrev->mNext)(i, v6);
  }
  for ( j = &(*v28)[-1].mNext; j != v33; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **, Render::sSoftbodyParams *))(*j)->mNext)(
      j,
      v6);
  for ( k = &context->mWorldSpaceShapes.mShapes.mNode.mNext[-1].mNext; k != v28; k = &k[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **, Render::sSoftbodyParams *))(*k)->mNext)(
      k,
      v6);
  v38 = v9->v1;
  v39 = v9->v2;
  v40 = v9->v3;
  v8->mPrevWorld.v0 = v9->v0;
  v8->mPrevWorld.v1 = v38;
  v8->mPrevWorld.v2 = v39;
  v8->mPrevWorld.v3 = v40;
  v41 = v8->mNeedsReset;
  v8->mPendingTimeStep = 0.0;
  if ( v41 )
    v8->mNeedsReset = v41 - 1;
}

// File Line: 188
// RVA: 0x21D60
void __fastcall Render::SoftbodyCollisionSphere::UpdateTransform(Render::SoftbodyCollisionSphere *this, UFG::qMatrix44 *initial2local, UFG::qMatrix44 *local2initial)
{
  float v3; // xmm3_4
  float v4; // xmm5_4
  float v5; // xmm6_4
  __m128 v6; // xmm3

  v3 = this->mCentre_initial.x;
  v4 = (float)((float)((float)(this->mCentre_initial.y * initial2local->v1.x)
                     + (float)(this->mCentre_initial.x * initial2local->v0.x))
             + (float)(this->mCentre_initial.z * initial2local->v2.x))
     + initial2local->v3.x;
  v5 = (float)((float)((float)(this->mCentre_initial.y * initial2local->v1.z) + (float)(v3 * initial2local->v0.z))
             + (float)(this->mCentre_initial.z * initial2local->v2.z))
     + initial2local->v3.z;
  this->mCentre_local.y = (float)((float)((float)(this->mCentre_initial.y * initial2local->v1.y)
                                        + (float)(v3 * initial2local->v0.y))
                                + (float)(this->mCentre_initial.z * initial2local->v2.y))
                        + initial2local->v3.y;
  this->mCentre_local.x = v4;
  this->mCentre_local.z = v5;
  v6 = (__m128)LODWORD(initial2local->v0.x);
  v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] * v6.m128_f32[0])
                                 + (float)(initial2local->v0.y * initial2local->v0.y))
                         + (float)(initial2local->v0.z * initial2local->v0.z))
                 + (float)(initial2local->v0.w * initial2local->v0.w);
  this->mRadius_local = this->mRadius_initial / COERCE_FLOAT(_mm_sqrt_ps(v6));
}

// File Line: 218
// RVA: 0x21460
void __fastcall Render::SoftbodyCollisionSphere::FillTaskParameters(Render::SoftbodyCollisionSphere *this, Render::sSoftbodyParams *output)
{
  __int64 v2; // rax
  float v3; // xmm1_4
  float v4; // xmm2_4
  float *v5; // rax
  float v6; // xmm3_4

  v2 = output->collision_sphere_count;
  if ( (unsigned int)v2 < 4 )
  {
    v3 = this->mCentre_local.y;
    v4 = this->mCentre_local.z;
    v5 = &output->timestep + 4 * (v2 + 18);
    v6 = this->mRadius_local;
    *v5 = this->mCentre_local.x;
    v5[1] = v3;
    v5[2] = v4;
    v5[3] = v6;
    ++output->collision_sphere_count;
  }
}

// File Line: 288
// RVA: 0x20920
void __fastcall Render::Softbody::Softbody(Render::Softbody *this, UFG::CompositeDrawableComponent *src_composite_drawable)
{
  UFG::CompositeDrawableComponent *v2; // rbx
  Render::Softbody *v3; // rdi
  Render::Softbody::CollisionShapeCollection *v4; // rax
  Render::Softbody::CollisionShapeCollection *v5; // rax
  Render::Softbody::CollisionShapeCollection *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm3_4
  UFG::qNode<Render::Softbody,Render::Softbody> *v33; // rax

  v2 = src_composite_drawable;
  v3 = this;
  this->mPrev = (UFG::qNode<Render::Softbody,Render::Softbody> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&this->mPrev;
  v4 = &this->mModelSpaceShapes;
  v4->mShapes.mNode.mPrev = &v4->mShapes.mNode;
  v4->mShapes.mNode.mNext = &v4->mShapes.mNode;
  v5 = &this->mSoftbodySpaceShapes;
  v5->mShapes.mNode.mPrev = &v5->mShapes.mNode;
  v5->mShapes.mNode.mNext = &v5->mShapes.mNode;
  v6 = &this->mWorldSpaceShapes;
  v6->mShapes.mNode.mPrev = &v6->mShapes.mNode;
  v6->mShapes.mNode.mNext = &v6->mShapes.mNode;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mModelGuidToClothMap.mTree.mTree);
  v3->mCompDrawComp = v2;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v3->mSystemVelocity.x = UFG::qVector3::msZero.x;
  v3->mSystemVelocity.y = v7;
  v3->mSystemVelocity.z = v8;
  v3->mSystemVelocityOnceOnly = 1;
  v9 = UFG::qMatrix44::msIdentity.v0.y;
  v10 = UFG::qMatrix44::msIdentity.v0.z;
  v11 = UFG::qMatrix44::msIdentity.v0.w;
  v3->mWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v3->mWorld.v0.y = v9;
  v3->mWorld.v0.z = v10;
  v3->mWorld.v0.w = v11;
  v12 = UFG::qMatrix44::msIdentity.v1.y;
  v13 = UFG::qMatrix44::msIdentity.v1.z;
  v14 = UFG::qMatrix44::msIdentity.v1.w;
  v3->mWorld.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v3->mWorld.v1.y = v12;
  v3->mWorld.v1.z = v13;
  v3->mWorld.v1.w = v14;
  v15 = UFG::qMatrix44::msIdentity.v2.y;
  v16 = UFG::qMatrix44::msIdentity.v2.z;
  v17 = UFG::qMatrix44::msIdentity.v2.w;
  v3->mWorld.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v3->mWorld.v2.y = v15;
  v3->mWorld.v2.z = v16;
  v3->mWorld.v2.w = v17;
  v18 = UFG::qMatrix44::msIdentity.v3.y;
  v19 = UFG::qMatrix44::msIdentity.v3.z;
  v20 = UFG::qMatrix44::msIdentity.v3.w;
  v3->mWorld.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v3->mWorld.v3.y = v18;
  v3->mWorld.v3.z = v19;
  v3->mWorld.v3.w = v20;
  v21 = UFG::qMatrix44::msIdentity.v0.y;
  v22 = UFG::qMatrix44::msIdentity.v0.z;
  v23 = UFG::qMatrix44::msIdentity.v0.w;
  v3->mInvWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  v3->mInvWorld.v0.y = v21;
  v3->mInvWorld.v0.z = v22;
  v3->mInvWorld.v0.w = v23;
  v24 = UFG::qMatrix44::msIdentity.v1.y;
  v25 = UFG::qMatrix44::msIdentity.v1.z;
  v26 = UFG::qMatrix44::msIdentity.v1.w;
  v3->mInvWorld.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  v3->mInvWorld.v1.y = v24;
  v3->mInvWorld.v1.z = v25;
  v3->mInvWorld.v1.w = v26;
  v27 = UFG::qMatrix44::msIdentity.v2.y;
  v28 = UFG::qMatrix44::msIdentity.v2.z;
  v29 = UFG::qMatrix44::msIdentity.v2.w;
  v3->mInvWorld.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  v3->mInvWorld.v2.y = v27;
  v3->mInvWorld.v2.z = v28;
  v3->mInvWorld.v2.w = v29;
  v30 = UFG::qMatrix44::msIdentity.v3.y;
  v31 = UFG::qMatrix44::msIdentity.v3.z;
  v32 = UFG::qMatrix44::msIdentity.v3.w;
  v3->mInvWorld.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  v3->mInvWorld.v3.y = v30;
  v3->mInvWorld.v3.z = v31;
  v3->mInvWorld.v3.w = v32;
  v33 = Render::Softbody::s_List.mNode.mPrev;
  Render::Softbody::s_List.mNode.mPrev->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&v3->mPrev;
  v3->mPrev = v33;
  v3->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&Render::Softbody::s_List;
  Render::Softbody::s_List.mNode.mPrev = (UFG::qNode<Render::Softbody,Render::Softbody> *)&v3->mPrev;
}

// File Line: 294
// RVA: 0x20D90
void __fastcall Render::Softbody::~Softbody(Render::Softbody *this)
{
  Render::Softbody *v1; // r14
  UFG::qNode<Render::Softbody,Render::Softbody> *v2; // rdx
  UFG::qNode<Render::Softbody,Render::Softbody> *v3; // rax
  UFG::qBaseTreeRB *v4; // rdi
  UFG::qBaseTreeRB *i; // rsi
  UFG::qBaseNodeRB *v6; // rbx
  Render::PackedPosition *v7; // rdx
  Render::PackedPosition *v8; // rdx
  UFG::qBaseNodeRB *v9; // rdx
  UFG::qBaseNodeRB *v10; // rax
  Render::SkinningCacheNode *v11; // rbx
  Render::Softbody::CollisionShapeCollection *v12; // rbp
  Render::Softbody::CollisionShapeCollection *v13; // r15
  Render::Softbody::CollisionShapeCollection *v14; // rsi
  Render::SkinningCacheNode *v15; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v16; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v17; // rax
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v18; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v19; // rax
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v20; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v21; // rax
  UFG::qNode<Render::Softbody,Render::Softbody> *v22; // rcx
  UFG::qNode<Render::Softbody,Render::Softbody> *v23; // rax

  v1 = this;
  v2 = this->mPrev;
  v3 = this->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  this->mPrev = (UFG::qNode<Render::Softbody,Render::Softbody> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&this->mPrev;
  v4 = &this->mModelGuidToClothMap.mTree.mTree;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(v4, &i->mRoot) )
  {
    v6 = i->mNULL.mParent;
    if ( v6 )
    {
      v7 = (Render::PackedPosition *)v6[1].mParent;
      if ( v7 )
      {
        Render::ISoftbody::AddBufferForDeletion(&Render::gSoftbody, v7);
        v6[1].mParent = 0i64;
      }
      v8 = *(Render::PackedPosition **)&v6->mUID;
      if ( v8 )
      {
        Render::ISoftbody::AddBufferForDeletion(&Render::gSoftbody, v8);
        *(_QWORD *)&v6->mUID = 0i64;
      }
      v9 = v6->mParent;
      v10 = v6->mChild[0];
      v9->mChild[0] = v10;
      v10->mParent = v9;
      v6->mParent = v6;
      v6->mChild[0] = v6;
      operator delete[](v6);
    }
  }
  while ( v4->mCount )
  {
    v11 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v4);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v4, &v11->mNode);
    operator delete[](v11);
  }
  v12 = &v1->mModelSpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mModelSpaceShapes.mShapes);
  v13 = &v1->mSoftbodySpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mSoftbodySpaceShapes.mShapes);
  v14 = &v1->mWorldSpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mWorldSpaceShapes.mShapes);
  while ( v4->mCount )
  {
    v15 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)v4);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)v4, &v15->mNode);
    operator delete[](v15);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v4);
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mWorldSpaceShapes.mShapes);
  v16 = v14->mShapes.mNode.mPrev;
  v17 = v1->mWorldSpaceShapes.mShapes.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v14->mShapes.mNode.mPrev = &v14->mShapes.mNode;
  v1->mWorldSpaceShapes.mShapes.mNode.mNext = &v1->mWorldSpaceShapes.mShapes.mNode;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mSoftbodySpaceShapes.mShapes);
  v18 = v13->mShapes.mNode.mPrev;
  v19 = v1->mSoftbodySpaceShapes.mShapes.mNode.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v13->mShapes.mNode.mPrev = &v13->mShapes.mNode;
  v1->mSoftbodySpaceShapes.mShapes.mNode.mNext = &v1->mSoftbodySpaceShapes.mShapes.mNode;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v1->mModelSpaceShapes.mShapes);
  v20 = v12->mShapes.mNode.mPrev;
  v21 = v1->mModelSpaceShapes.mShapes.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v12->mShapes.mNode.mPrev = &v12->mShapes.mNode;
  v1->mModelSpaceShapes.mShapes.mNode.mNext = &v1->mModelSpaceShapes.mShapes.mNode;
  v22 = v1->mPrev;
  v23 = v1->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  v1->mPrev = (UFG::qNode<Render::Softbody,Render::Softbody> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&v1->mPrev;
}

// File Line: 313
// RVA: 0x21A70
void __fastcall Render::Softbody::SimUpdate(Render::Softbody *this, float timeStep)
{
  float v2; // xmm6_4
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qBaseTreeRB *v7; // rbx
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseNodeRB *v9; // rcx
  float v10; // xmm0_4

  v2 = timeStep * Render::VERLET_timescale;
  if ( this->mSystemVelocityOnceOnly )
  {
    v3 = UFG::qVector3::msZero.y;
    v4 = UFG::qVector3::msZero.z;
    this->mSystemVelocity.x = UFG::qVector3::msZero.x;
    this->mSystemVelocity.y = v3;
    this->mSystemVelocity.z = v4;
  }
  v5 = Render::VERLET_gravity.y;
  v6 = Render::VERLET_gravity.z;
  v7 = &this->mModelGuidToClothMap.mTree.mTree;
  this->mAccel.x = Render::VERLET_gravity.x;
  this->mAccel.y = v5;
  this->mAccel.z = v6;
  this->mDrag = Render::VERLET_drag;
  this->mFriction = Render::VERLET_friction;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(v7, &i->mRoot) )
  {
    v9 = i->mNULL.mParent;
    v10 = *(float *)&v9->mChild[1];
    if ( v10 > 0.0 )
      *(float *)&v9->mChild[1] = v10 + v2;
    else
      *(float *)&v9->mChild[1] = v2;
  }
}

// File Line: 360
// RVA: 0x21960
void __fastcall Render::Softbody::ForceReset(Render::Softbody *this)
{
  UFG::qBaseTreeRB *v1; // rbx
  UFG::qBaseTreeRB *i; // rax

  v1 = &this->mModelGuidToClothMap.mTree.mTree;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(v1, &i->mRoot) )
  {
    HIDWORD(i->mNULL.mParent[1].mChild[0]) = 1;
  }
}

// File Line: 369
// RVA: 0x21330
Render::sSoftbodyParams *__fastcall Render::Softbody::CreateTaskParameters(Render::Softbody *this, Illusion::Model *source_model, UFG::qMatrix44 *local2world)
{
  Illusion::Model *v3; // rbp
  unsigned int v4; // edx
  UFG::qMatrix44 *v5; // r14
  Render::Softbody *context; // rsi
  UFG::qBaseTreeRB *v7; // rax
  Render::VerletCloth **v8; // rax
  Render::VerletCloth *v9; // rdi
  Render::sSoftbodyParams *result; // rax
  Render::sSoftbodyParams *v11; // rbx
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h]
  __int64 v13; // [rsp+98h] [rbp+10h]

  v3 = source_model;
  v4 = source_model->mNode.mUID;
  v5 = local2world;
  context = this;
  v13 = 0i64;
  if ( v4 && (v7 = UFG::qBaseTreeRB::Get(&this->mModelGuidToClothMap.mTree.mTree, v4)) != 0i64 )
    v8 = (Render::VerletCloth **)&v7->mNULL;
  else
    v8 = (Render::VerletCloth **)&v13;
  v9 = *v8;
  if ( !*v8 )
    return 0i64;
  result = (Render::sSoftbodyParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1A0u, 0x10u);
  v11 = result;
  if ( result )
  {
    UFG::qInverse(&d, v5);
    Render::VerletCloth::FillTaskParameters(v9, v11, v3, v5, &d, context);
    result = v11;
  }
  return result;
}

// File Line: 413
// RVA: 0x1453C50
__int64 Render::_dynamic_initializer_for__s_uDirectionUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Direction", 0xFFFFFFFF);
  s_uDirectionUID = result;
  return result;
}

// File Line: 414
// RVA: 0x1453C70
__int64 Render::_dynamic_initializer_for__s_uSync01UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Sync01", 0xFFFFFFFF);
  s_uSync01UID = result;
  return result;
}

// File Line: 415
// RVA: 0x1453B70
__int64 Render::_dynamic_initializer_for__s_uBalanceUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Balance", 0xFFFFFFFF);
  s_uBalanceUID = result;
  return result;
}

// File Line: 417
// RVA: 0x1453BF0
__int64 Render::_dynamic_initializer_for__s_uBip01_R_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Clavicle", 0xFFFFFFFF);
  s_uBip01_R_ClavicleUID = result;
  return result;
}

// File Line: 418
// RVA: 0x1453C10
__int64 Render::_dynamic_initializer_for__s_uBip01_R_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R UpperArm", 0xFFFFFFFF);
  s_uBip01_R_UpperArmUID = result;
  return result;
}

// File Line: 419
// RVA: 0x1453CF0
__int64 Render::_dynamic_initializer_for__s_ur_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_upperarm_twist", 0xFFFFFFFF);
  s_ur_upperarm_twistUID = result;
  return result;
}

// File Line: 420
// RVA: 0x1453CD0
__int64 Render::_dynamic_initializer_for__s_ur_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_shoulder_joint", 0xFFFFFFFF);
  s_ur_shoulder_jointUID = result;
  return result;
}

// File Line: 422
// RVA: 0x1453B90
__int64 Render::_dynamic_initializer_for__s_uBip01_L_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Clavicle", 0xFFFFFFFF);
  s_uBip01_L_ClavicleUID = result;
  return result;
}

// File Line: 423
// RVA: 0x1453BB0
__int64 Render::_dynamic_initializer_for__s_uBip01_L_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L UpperArm", 0xFFFFFFFF);
  s_uBip01_L_UpperArmUID = result;
  return result;
}

// File Line: 424
// RVA: 0x1453CB0
__int64 Render::_dynamic_initializer_for__s_ul_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_upperarm_twist", 0xFFFFFFFF);
  s_ul_upperarm_twistUID = result;
  return result;
}

// File Line: 425
// RVA: 0x1453C90
__int64 Render::_dynamic_initializer_for__s_ul_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_shoulder_joint", 0xFFFFFFFF);
  s_ul_shoulder_jointUID = result;
  return result;
}

// File Line: 427
// RVA: 0x1453B30
__int64 Render::_dynamic_initializer_for__s_R_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Forearm", 0xFFFFFFFF);
  s_R_Forearm_UID = result;
  return result;
}

// File Line: 428
// RVA: 0x1453B50
__int64 Render::_dynamic_initializer_for__s_R_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Hand", 0xFFFFFFFF);
  s_R_Hand_UID = result;
  return result;
}

// File Line: 429
// RVA: 0x1453B10
__int64 Render::_dynamic_initializer_for__s_R_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R ForeTwist", 0xFFFFFFFF);
  s_R_ForeTwist_UID = result;
  return result;
}

// File Line: 431
// RVA: 0x1453AD0
__int64 Render::_dynamic_initializer_for__s_L_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Forearm", 0xFFFFFFFF);
  s_L_Forearm_UID = result;
  return result;
}

// File Line: 432
// RVA: 0x1453AF0
__int64 Render::_dynamic_initializer_for__s_L_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Hand", 0xFFFFFFFF);
  s_L_Hand_UID = result;
  return result;
}

// File Line: 433
// RVA: 0x1453AB0
__int64 Render::_dynamic_initializer_for__s_L_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L ForeTwist", 0xFFFFFFFF);
  s_L_ForeTwist_UID = result;
  return result;
}

// File Line: 435
// RVA: 0x1453BD0
__int64 Render::_dynamic_initializer_for__s_uBip01_Neck_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 Neck", 0xFFFFFFFF);
  s_uBip01_Neck_UID = result;
  return result;
}

// File Line: 436
// RVA: 0x1453C30
__int64 Render::_dynamic_initializer_for__s_uBip01_Spine_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 Spine", 0xFFFFFFFF);
  s_uBip01_Spine_UID = result;
  return result;
}

// File Line: 440
// RVA: 0x21B70
void __fastcall Render::Softbody::UpdateTransform(Render::Softbody *this)
{
  UFG::CompositeDrawableComponent *v1; // rbx
  Render::Softbody *v2; // rdi
  SkeletalPose *v3; // rbx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  UFG::qVector4 v8; // xmm1
  signed __int64 v9; // rdx
  UFG::qVector4 v10; // xmm0
  UFG::qVector3 centre; // [rsp+18h] [rbp-39h]
  UFG::qMatrix44 v12; // [rsp+28h] [rbp-29h]
  UFG::qMatrix44 matrixWS; // [rsp+68h] [rbp+17h]

  v1 = this->mCompDrawComp;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->mPose;
    if ( v3 )
    {
      v4 = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, s_uBip01_Spine_UID);
      if ( v4 >= 0 )
        SkeletalPose::GetPositionWS(v3, v4, &matrixWS);
      UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&v2->mWorldSpaceShapes.mShapes);
      v5 = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, s_uBip01_R_ClavicleUID);
      if ( v5 >= 0 )
      {
        SkeletalPose::GetPositionWS(v3, v5, &v12);
        centre.z = v12.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&v2->mWorldSpaceShapes, &centre, 0.1);
      }
      v6 = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, s_uBip01_L_ClavicleUID);
      if ( v6 >= 0 )
      {
        SkeletalPose::GetPositionWS(v3, v6, &v12);
        centre.z = v12.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&v2->mWorldSpaceShapes, &centre, 0.1);
      }
      v7 = Skeleton::GetBoneID(v3->mRigHandle.mUFGSkeleton, s_uBip01_Neck_UID);
      if ( v7 >= 0 )
      {
        SkeletalPose::GetPositionWS(v3, v7, &v12);
        centre.z = v12.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&v2->mWorldSpaceShapes, &centre, 0.1);
      }
    }
    else
    {
      matrixWS = UFG::qMatrix44::msIdentity;
    }
    v8 = matrixWS.v2;
    v9 = (signed __int64)&v2->mWorld;
    *(UFG::qVector4 *)v9 = matrixWS.v0;
    *(UFG::qVector4 *)(v9 + 16) = matrixWS.v1;
    v10 = matrixWS.v3;
    *(UFG::qVector4 *)(v9 + 32) = v8;
    *(UFG::qVector4 *)(v9 + 48) = v10;
    UFG::qInverse(&v2->mInvWorld, &v2->mWorld);
  }
}

// File Line: 505
// RVA: 0x21170
Render::VerletCloth *__fastcall Render::Softbody::AddModel(Render::Softbody *this, Illusion::Model *src_model)
{
  Illusion::Model *v2; // rbp
  Render::Softbody *v3; // r14
  Render::VerletCloth *v4; // rbx
  __int64 v5; // rax
  char *v6; // rax
  Illusion::SoftbodyData *v7; // rdi
  __int64 v8; // rax
  _QWORD *v9; // rax
  Illusion::Mesh *v10; // rsi
  char *v12; // rax
  Render::VerletCloth *v13; // rax
  Render::VerletCloth *value; // [rsp+58h] [rbp+10h]

  v2 = src_model;
  v3 = this;
  v4 = 0i64;
  v5 = src_model->mModelUser.mOffset;
  if ( v5 )
  {
    v6 = (char *)&src_model->mModelUser + v5;
    if ( v6 )
    {
      if ( *((_DWORD *)v6 + 2) )
      {
        v7 = (Illusion::SoftbodyData *)&v6[*(_QWORD *)v6];
        if ( !*(_QWORD *)v6 )
          v7 = 0i64;
        v8 = src_model->mMeshOffsetTable.mOffset;
        if ( v8 )
          v9 = (__int64 *)((char *)&src_model->mMeshOffsetTable.mOffset + v8);
        else
          v9 = 0i64;
        v10 = (Illusion::Mesh *)((char *)v9 + *v9);
        if ( !*v9 )
          v10 = 0i64;
        if ( !v7->mNumSoftVertIndices )
          return 0i64;
        v12 = UFG::qMalloc(0x70ui64, "VerletCloth", 0i64);
        value = (Render::VerletCloth *)v12;
        if ( v12 )
        {
          Render::VerletCloth::VerletCloth((Render::VerletCloth *)v12, v7, v10);
          v4 = v13;
        }
        if ( v4 )
        {
          value = v4;
          UFG::qMap<Render::VerletCloth *>::Set(&v3->mModelGuidToClothMap, v2->mNode.mUID, &value);
        }
      }
    }
  }
  return v4;
}

// File Line: 545
// RVA: 0x21260
void __fastcall Render::Softbody::CollisionShapeCollection::AddSphere(Render::Softbody::CollisionShapeCollection *this, UFG::qVector3 *centre, float radius)
{
  float v3; // xmm6_4
  UFG::qVector3 *v4; // rdi
  Render::Softbody::CollisionShapeCollection *v5; // rbx
  char *v6; // rax
  _QWORD *v7; // r8
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v12; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v13; // rax

  v3 = radius;
  v4 = centre;
  v5 = this;
  v6 = UFG::qMalloc(0x38ui64, "SoftbodyCollisionSphere", 0i64);
  if ( v6 )
  {
    v7 = v6 + 8;
    *v7 = v7;
    v7[1] = v7;
    *(_QWORD *)v6 = &Render::SoftbodyCollisionShape::`vftable;
    *(_QWORD *)v6 = &Render::SoftbodyCollisionSphere::`vftable;
    v8 = v4->y;
    v9 = v4->z;
    *((_DWORD *)v6 + 6) = LODWORD(v4->x);
    *((float *)v6 + 7) = v8;
    *((float *)v6 + 8) = v9;
    *((float *)v6 + 9) = radius;
    v10 = v4->y;
    v11 = v4->z;
    *((_DWORD *)v6 + 10) = LODWORD(v4->x);
    *((float *)v6 + 11) = v10;
    *((float *)v6 + 12) = v11;
    *((float *)v6 + 13) = v3;
  }
  v12 = (UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *)(v6 + 8);
  v13 = v5->mShapes.mNode.mPrev;
  v13->mNext = v12;
  v12->mPrev = v13;
  v12->mNext = &v5->mShapes.mNode;
  v5->mShapes.mNode.mPrev = v12;
}

// File Line: 563
// RVA: 0x219B0
Render::Softbody *__fastcall Render::ISoftbody::GenerateSoftbody(Render::ISoftbody *this, UFG::CompositeDrawableComponent *src_composite_drawable, ModelType::ModelBindingSkin *binding)
{
  ModelType::ModelBindingSkin *v3; // rdi
  UFG::CompositeDrawableComponent *v4; // rsi
  Render::Softbody *v5; // rbx
  char *v7; // rax
  Render::Softbody *v8; // rax
  Render::Softbody *v9; // rbx

  v3 = binding;
  v4 = src_composite_drawable;
  v5 = binding->mSoftbody;
  if ( v5 )
  {
    Render::Softbody::~Softbody(binding->mSoftbody);
    operator delete[](v5);
    v3->mSoftbody = 0i64;
  }
  if ( !v3->mModelProxy.mModelHandle.mData )
    return 0i64;
  v7 = UFG::qMalloc(0x138ui64, "Softbody", 0i64);
  if ( v7 )
  {
    Render::Softbody::Softbody((Render::Softbody *)v7, v4);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  if ( Render::Softbody::AddModel(v9, (Illusion::Model *)v3->mModelProxy.mModelHandle.mData) )
  {
    v3->mSoftbody = v9;
  }
  else
  {
    if ( v9 )
    {
      Render::Softbody::~Softbody(v9);
      operator delete[](v9);
    }
    v9 = 0i64;
  }
  return v9;
}

// File Line: 612
// RVA: 0x21050
void __fastcall Render::ISoftbody::AddBufferForDeletion(Render::ISoftbody *this, Render::PackedPosition *packedPositions)
{
  __int64 v2; // rbp
  Render::PackedPosition *v3; // r14
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char *v7; // rax
  Render::PackedPosition **v8; // r9
  Render::PackedPosition **v9; // rsi
  signed __int64 v10; // r8
  signed __int64 v11; // rdx

  v2 = Render::ISoftbody::s_DeletionQueue.size;
  v3 = packedPositions;
  v4 = Render::ISoftbody::s_DeletionQueue.size + 1;
  if ( Render::ISoftbody::s_DeletionQueue.size + 1 <= Render::ISoftbody::s_DeletionQueue.capacity )
    goto LABEL_23;
  if ( Render::ISoftbody::s_DeletionQueue.capacity )
    v5 = 2 * Render::ISoftbody::s_DeletionQueue.capacity;
  else
    v5 = 1;
  for ( ; v5 < v4; v5 *= 2 )
    ;
  if ( v5 <= 2 )
    v5 = 2;
  if ( v5 - v4 > 0x10000 )
    v5 = Render::ISoftbody::s_DeletionQueue.size + 65537;
  if ( v5 == (_DWORD)v2 )
  {
LABEL_23:
    v9 = Render::ISoftbody::s_DeletionQueue.p;
  }
  else
  {
    v6 = 8i64 * v5;
    if ( !is_mul_ok(v5, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "qArray.Add", 0i64);
    v8 = Render::ISoftbody::s_DeletionQueue.p;
    v9 = (Render::PackedPosition **)v7;
    if ( Render::ISoftbody::s_DeletionQueue.p )
    {
      v10 = 0i64;
      if ( Render::ISoftbody::s_DeletionQueue.size )
      {
        do
        {
          v11 = v10;
          v10 = (unsigned int)(v10 + 1);
          *(_QWORD *)&v7[v11 * 8] = v8[v11];
          v8 = Render::ISoftbody::s_DeletionQueue.p;
        }
        while ( (unsigned int)v10 < Render::ISoftbody::s_DeletionQueue.size );
      }
      operator delete[](v8);
    }
    Render::ISoftbody::s_DeletionQueue.p = v9;
    Render::ISoftbody::s_DeletionQueue.capacity = v5;
  }
  Render::ISoftbody::s_DeletionQueue.size = v4;
  v9[v2] = v3;
}

// File Line: 617
// RVA: 0x21400
void __fastcall Render::ISoftbody::DeleteQueuedBuffers(Render::ISoftbody *this)
{
  unsigned int v1; // eax

  if ( Render::ISoftbody::s_DeletionQueue.size )
  {
    while ( 1 )
    {
      operator delete[](*(void **)Render::ISoftbody::s_DeletionQueue.p);
      *Render::ISoftbody::s_DeletionQueue.p = Render::ISoftbody::s_DeletionQueue.p[Render::ISoftbody::s_DeletionQueue.size
                                                                                 - 1];
      v1 = Render::ISoftbody::s_DeletionQueue.size;
      if ( Render::ISoftbody::s_DeletionQueue.size <= 1 )
        break;
      --Render::ISoftbody::s_DeletionQueue.size;
      if ( v1 == 1 )
        return;
    }
    Render::ISoftbody::s_DeletionQueue.size = 0;
  }
}

