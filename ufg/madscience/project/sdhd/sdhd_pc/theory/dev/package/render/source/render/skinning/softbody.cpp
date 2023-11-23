// File Line: 56
// RVA: 0x1453A40
__int64 dynamic_initializer_for__Render::Softbody::s_List__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::Softbody::s_List__);
}

// File Line: 57
// RVA: 0x1453A30
__int64 dynamic_initializer_for__Render::ISoftbody::s_DeletionQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::ISoftbody::s_DeletionQueue__);
}

// File Line: 77
// RVA: 0x20C00
void __fastcall Render::VerletCloth::VerletCloth(
        Render::VerletCloth *this,
        Illusion::SoftbodyData *softbodyData,
        Illusion::Mesh *src_mesh)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
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

  this->mPrev = this;
  this->mNext = this;
  this->mPrevSoftVertPosUnconstrained = 0i64;
  this->mPrevSoftVertPosConstrained = 0i64;
  this->mNeedsReset = 2;
  y = UFG::qMatrix44::msIdentity.v0.y;
  z = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->mPrevWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mPrevWorld.v0.y = y;
  this->mPrevWorld.v0.z = z;
  this->mPrevWorld.v0.w = w;
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
  this->mPrevSoftVertPositionsSize = v16;
  this->mPrevSoftVertPosConstrained = (Render::PackedPosition *)UFG::qMalloc(
                                                                  v16,
                                                                  "VerletCloth::mPrevSoftVertPosConstrained",
                                                                  0x8000ui64);
  this->mPrevSoftVertPosUnconstrained = (Render::PackedPosition *)UFG::qMalloc(
                                                                    this->mPrevSoftVertPositionsSize,
                                                                    "VerletCloth::mPrevSoftVertPosUnconstrained",
                                                                    0x8000ui64);
}

// File Line: 104
// RVA: 0x214B0
void __fastcall Render::VerletCloth::FillTaskParameters(
        Render::VerletCloth *this,
        Render::sSoftbodyParams *output,
        Illusion::Model *source_model,
        UFG::qMatrix44 *worldMat,
        UFG::qMatrix44 *invWorldMat,
        Render::Softbody *context)
{
  float mPendingTimeStep; // xmm6_4
  __m128 y_low; // xmm2
  float v12; // xmm1_4
  float v13; // xmm0_4
  float mDrag; // eax
  __int64 mOffset; // rax
  _QWORD *v16; // rax
  char *v17; // rcx
  __int64 v18; // rax
  char *v19; // rax
  __int64 v20; // rax
  char *v21; // rax
  char *v22; // rax
  __int64 v23; // rax
  char *v24; // rdx
  UFG::qVector4 v25; // xmm0
  UFG::qVector4 v26; // xmm1
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **p_mNext; // r14
  UFG::qVector4 v28; // xmm3
  UFG::qVector4 v29; // xmm2
  UFG::qVector4 v30; // xmm1
  Render::Softbody *v31; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **v32; // rsi
  Render::Softbody *v33; // rbx
  Render::Softbody *i; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **j; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **k; // rbx
  UFG::qVector4 v37; // xmm3
  UFG::qVector4 v38; // xmm2
  UFG::qVector4 v39; // xmm1
  unsigned int mNeedsReset; // eax
  UFG::qMatrix44 result; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qMatrix44 v42; // [rsp+60h] [rbp-78h] BYREF

  UFG::qMatrix44::operator*(&this->mPrevWorld, &result, invWorldMat);
  mPendingTimeStep = this->mPendingTimeStep;
  if ( mPendingTimeStep <= 0.00000011920929
    || mPendingTimeStep > 0.30000001
    || UFG::qMatrix44::operator==(&this->mPrevWorld, &UFG::qMatrix44::msIdentity) )
  {
    this->mPendingTimeStep = 0.0;
  }
  else
  {
    y_low = (__m128)LODWORD(result.v3.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(result.v3.x * result.v3.x))
                      + (float)(result.v3.z * result.v3.z);
    v12 = _mm_sqrt_ps(y_low).m128_f32[0] / mPendingTimeStep;
    if ( v12 > Render::VERLET_maxTranslationSpeed )
    {
      LODWORD(result.v3.w) = (_DWORD)FLOAT_1_0;
      result.v3.x = result.v3.x * (float)(Render::VERLET_maxTranslationSpeed / v12);
      result.v3.y = result.v3.y * (float)(Render::VERLET_maxTranslationSpeed / v12);
      result.v3.z = result.v3.z * (float)(Render::VERLET_maxTranslationSpeed / v12);
    }
  }
  v13 = this->mPendingTimeStep;
  if ( v13 >= 0.1 )
    v13 = FLOAT_0_1;
  output->timestep = v13;
  output->friction = context->mFriction;
  mDrag = context->mDrag;
  output->noisetime = 0.0;
  output->drag = mDrag;
  mOffset = source_model->mModelUser.mOffset;
  if ( mOffset )
    v16 = (__int64 *)((char *)&source_model->mModelUser.mOffset + mOffset);
  else
    v16 = 0i64;
  if ( *v16 )
    v17 = (char *)v16 + *v16;
  else
    v17 = 0i64;
  output->spring_size = 4 * *((_DWORD *)v17 + 10);
  v18 = *((_QWORD *)v17 + 2);
  if ( v18 )
    v19 = &v17[v18 + 16];
  else
    v19 = 0i64;
  output->spring_data = v19;
  output->remapper_size = 2 * *((_DWORD *)v17 + 11);
  v20 = *((_QWORD *)v17 + 3);
  if ( v20 )
    v21 = &v17[v20 + 24];
  else
    v21 = 0i64;
  output->remapper_data = v21;
  output->soft_indices_count = *((_DWORD *)v17 + 8);
  output->hard_indices_count = *((_DWORD *)v17 + 9) - *((_DWORD *)v17 + 8);
  if ( *(_QWORD *)v17 )
    v22 = &v17[*(_QWORD *)v17];
  else
    v22 = 0i64;
  output->verlet_indices_data = v22;
  v23 = *((_QWORD *)v17 + 1);
  if ( v23 )
    v24 = &v17[v23 + 8];
  else
    v24 = 0i64;
  output->render_indices_data = v24;
  v25 = result.v0;
  output->prev_soft_positions_unconstrained_data = this->mPrevSoftVertPosUnconstrained;
  v26 = result.v2;
  output->prev_soft_positions_constrained_data = this->mPrevSoftVertPosConstrained;
  p_mNext = &context->mSoftbodySpaceShapes.mShapes.mNode.mNext;
  output->delta_world_transform.v0 = v25;
  output->delta_world_transform.v1 = result.v1;
  output->delta_world_transform.v2 = v26;
  output->delta_world_transform.v3 = result.v3;
  v28 = invWorldMat->v1;
  v29 = invWorldMat->v2;
  v30 = invWorldMat->v3;
  output->inverse_world_transform.v0 = invWorldMat->v0;
  output->inverse_world_transform.v1 = v28;
  output->inverse_world_transform.v2 = v29;
  output->inverse_world_transform.v3 = v30;
  v25.x = context->mAccel.x;
  v30.x = context->mAccel.y;
  v29.x = context->mAccel.z;
  output->accel.w = 1.0;
  output->accel.x = v25.x;
  output->accel.y = v30.x;
  output->accel.z = v29.x;
  v29.x = UFG::qVector4::msZero.z;
  v28.x = UFG::qVector4::msZero.w;
  v25.x = UFG::qVector4::msZero.x;
  output->winddir.y = UFG::qVector4::msZero.y;
  output->winddir.z = v29.x;
  output->winddir.x = v25.x;
  output->winddir.w = v28.x;
  v30.x = UFG::qVector4::msZero.y;
  v29.x = UFG::qVector4::msZero.z;
  v28.x = UFG::qVector4::msZero.w;
  output->ground_plane.x = UFG::qVector4::msZero.x;
  output->ground_plane.y = v30.x;
  output->ground_plane.z = v29.x;
  output->ground_plane.w = v28.x;
  output->windspeed = 0.0;
  output->need_reset = this->mNeedsReset != 0;
  v31 = (Render::Softbody *)&context->mWorldSpaceShapes.mShapes.mNode.mNext[-1].mNext;
  if ( v31 != (Render::Softbody *)&context->mSoftbodySpaceShapes.mShapes.mNode.mNext )
  {
    do
    {
      ((void (__fastcall *)(Render::Softbody *, UFG::qMatrix44 *, UFG::qMatrix44 *))v31->mPrev->mPrev)(
        v31,
        invWorldMat,
        worldMat);
      v31 = (Render::Softbody *)&v31->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext;
    }
    while ( v31 != (Render::Softbody *)p_mNext );
  }
  UFG::qMatrix44::operator*(&context->mWorld, &v42, invWorldMat);
  UFG::qMatrix44::operator*(worldMat, &result, &context->mInvWorld);
  v32 = &context->mModelSpaceShapes.mShapes.mNode.mNext;
  v33 = (Render::Softbody *)&(*p_mNext)[-1].mNext;
  if ( v33 != (Render::Softbody *)&context->mModelSpaceShapes.mShapes.mNode.mNext )
  {
    do
    {
      ((void (__fastcall *)(Render::Softbody *, UFG::qMatrix44 *, UFG::qMatrix44 *))v33->mPrev->mPrev)(
        v33,
        &v42,
        &result);
      v33 = (Render::Softbody *)&v33->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext;
    }
    while ( v33 != (Render::Softbody *)v32 );
  }
  *(_QWORD *)&output->collision_plane_count = 0i64;
  for ( i = (Render::Softbody *)&(*v32)[-1].mNext;
        i != (Render::Softbody *)&context->mNext;
        i = (Render::Softbody *)&i->mModelSpaceShapes.mShapes.mNode.mPrev[-1].mNext )
  {
    ((void (__fastcall *)(Render::Softbody *, Render::sSoftbodyParams *))i->mPrev->mNext)(i, output);
  }
  for ( j = &(*p_mNext)[-1].mNext; j != v32; j = &j[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **, Render::sSoftbodyParams *))(*j)->mNext)(
      j,
      output);
  for ( k = &context->mWorldSpaceShapes.mShapes.mNode.mNext[-1].mNext; k != p_mNext; k = &k[2][-1].mNext )
    ((void (__fastcall *)(UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> **, Render::sSoftbodyParams *))(*k)->mNext)(
      k,
      output);
  v37 = worldMat->v1;
  v38 = worldMat->v2;
  v39 = worldMat->v3;
  this->mPrevWorld.v0 = worldMat->v0;
  this->mPrevWorld.v1 = v37;
  this->mPrevWorld.v2 = v38;
  this->mPrevWorld.v3 = v39;
  mNeedsReset = this->mNeedsReset;
  this->mPendingTimeStep = 0.0;
  if ( mNeedsReset )
    this->mNeedsReset = mNeedsReset - 1;
}

// File Line: 188
// RVA: 0x21D60
void __fastcall Render::SoftbodyCollisionSphere::UpdateTransform(
        Render::SoftbodyCollisionSphere *this,
        UFG::qMatrix44 *initial2local,
        UFG::qMatrix44 *local2initial)
{
  float y; // xmm5_4
  float v4; // xmm6_4
  float x; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  __m128 x_low; // xmm3

  y = this->mCentre_initial.y;
  v4 = y * initial2local->v1.z;
  x = this->mCentre_initial.x;
  v6 = (float)((float)((float)(y * initial2local->v1.x) + (float)(x * initial2local->v0.x))
             + (float)(this->mCentre_initial.z * initial2local->v2.x))
     + initial2local->v3.x;
  v7 = (float)((float)(v4 + (float)(x * initial2local->v0.z)) + (float)(this->mCentre_initial.z * initial2local->v2.z))
     + initial2local->v3.z;
  this->mCentre_local.y = (float)((float)((float)(this->mCentre_initial.y * initial2local->v1.y)
                                        + (float)(x * initial2local->v0.y))
                                + (float)(this->mCentre_initial.z * initial2local->v2.y))
                        + initial2local->v3.y;
  this->mCentre_local.x = v6;
  this->mCentre_local.z = v7;
  x_low = (__m128)LODWORD(initial2local->v0.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                    + (float)(initial2local->v0.y * initial2local->v0.y))
                            + (float)(initial2local->v0.z * initial2local->v0.z))
                    + (float)(initial2local->v0.w * initial2local->v0.w);
  this->mRadius_local = this->mRadius_initial / _mm_sqrt_ps(x_low).m128_f32[0];
}

// File Line: 218
// RVA: 0x21460
void __fastcall Render::SoftbodyCollisionSphere::FillTaskParameters(
        Render::SoftbodyCollisionSphere *this,
        Render::sSoftbodyParams *output)
{
  __int64 collision_sphere_count; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector4 *v5; // rax
  float mRadius_local; // xmm3_4

  collision_sphere_count = output->collision_sphere_count;
  if ( (unsigned int)collision_sphere_count < 4 )
  {
    y = this->mCentre_local.y;
    z = this->mCentre_local.z;
    v5 = &output->collision_sphere_data[collision_sphere_count];
    mRadius_local = this->mRadius_local;
    v5->x = this->mCentre_local.x;
    v5->y = y;
    v5->z = z;
    v5->w = mRadius_local;
    ++output->collision_sphere_count;
  }
}

// File Line: 288
// RVA: 0x20920
void __fastcall Render::Softbody::Softbody(
        Render::Softbody *this,
        UFG::CompositeDrawableComponent *src_composite_drawable)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float w; // xmm3_4
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
  UFG::qNode<Render::Softbody,Render::Softbody> *mPrev; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mModelSpaceShapes.mShapes.mNode.mPrev = &this->mModelSpaceShapes.mShapes.mNode;
  this->mModelSpaceShapes.mShapes.mNode.mNext = &this->mModelSpaceShapes.mShapes.mNode;
  this->mSoftbodySpaceShapes.mShapes.mNode.mPrev = &this->mSoftbodySpaceShapes.mShapes.mNode;
  this->mSoftbodySpaceShapes.mShapes.mNode.mNext = &this->mSoftbodySpaceShapes.mShapes.mNode;
  this->mWorldSpaceShapes.mShapes.mNode.mPrev = &this->mWorldSpaceShapes.mShapes.mNode;
  this->mWorldSpaceShapes.mShapes.mNode.mNext = &this->mWorldSpaceShapes.mShapes.mNode;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mModelGuidToClothMap.mTree.mTree);
  this->mCompDrawComp = src_composite_drawable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mSystemVelocity.x = UFG::qVector3::msZero.x;
  this->mSystemVelocity.y = y;
  this->mSystemVelocity.z = z;
  this->mSystemVelocityOnceOnly = 1;
  v6 = UFG::qMatrix44::msIdentity.v0.y;
  v7 = UFG::qMatrix44::msIdentity.v0.z;
  w = UFG::qMatrix44::msIdentity.v0.w;
  this->mWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mWorld.v0.y = v6;
  this->mWorld.v0.z = v7;
  this->mWorld.v0.w = w;
  v9 = UFG::qMatrix44::msIdentity.v1.y;
  v10 = UFG::qMatrix44::msIdentity.v1.z;
  v11 = UFG::qMatrix44::msIdentity.v1.w;
  this->mWorld.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mWorld.v1.y = v9;
  this->mWorld.v1.z = v10;
  this->mWorld.v1.w = v11;
  v12 = UFG::qMatrix44::msIdentity.v2.y;
  v13 = UFG::qMatrix44::msIdentity.v2.z;
  v14 = UFG::qMatrix44::msIdentity.v2.w;
  this->mWorld.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mWorld.v2.y = v12;
  this->mWorld.v2.z = v13;
  this->mWorld.v2.w = v14;
  v15 = UFG::qMatrix44::msIdentity.v3.y;
  v16 = UFG::qMatrix44::msIdentity.v3.z;
  v17 = UFG::qMatrix44::msIdentity.v3.w;
  this->mWorld.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mWorld.v3.y = v15;
  this->mWorld.v3.z = v16;
  this->mWorld.v3.w = v17;
  v18 = UFG::qMatrix44::msIdentity.v0.y;
  v19 = UFG::qMatrix44::msIdentity.v0.z;
  v20 = UFG::qMatrix44::msIdentity.v0.w;
  this->mInvWorld.v0.x = UFG::qMatrix44::msIdentity.v0.x;
  this->mInvWorld.v0.y = v18;
  this->mInvWorld.v0.z = v19;
  this->mInvWorld.v0.w = v20;
  v21 = UFG::qMatrix44::msIdentity.v1.y;
  v22 = UFG::qMatrix44::msIdentity.v1.z;
  v23 = UFG::qMatrix44::msIdentity.v1.w;
  this->mInvWorld.v1.x = UFG::qMatrix44::msIdentity.v1.x;
  this->mInvWorld.v1.y = v21;
  this->mInvWorld.v1.z = v22;
  this->mInvWorld.v1.w = v23;
  v24 = UFG::qMatrix44::msIdentity.v2.y;
  v25 = UFG::qMatrix44::msIdentity.v2.z;
  v26 = UFG::qMatrix44::msIdentity.v2.w;
  this->mInvWorld.v2.x = UFG::qMatrix44::msIdentity.v2.x;
  this->mInvWorld.v2.y = v24;
  this->mInvWorld.v2.z = v25;
  this->mInvWorld.v2.w = v26;
  v27 = UFG::qMatrix44::msIdentity.v3.y;
  v28 = UFG::qMatrix44::msIdentity.v3.z;
  v29 = UFG::qMatrix44::msIdentity.v3.w;
  this->mInvWorld.v3.x = UFG::qMatrix44::msIdentity.v3.x;
  this->mInvWorld.v3.y = v27;
  this->mInvWorld.v3.z = v28;
  this->mInvWorld.v3.w = v29;
  mPrev = Render::Softbody::s_List.mNode.mPrev;
  Render::Softbody::s_List.mNode.mPrev->mNext = this;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<Render::Softbody,Render::Softbody> *)&Render::Softbody::s_List;
  Render::Softbody::s_List.mNode.mPrev = this;
}r::So

// File Line: 294
// RVA: 0x20D90
void __fastcall Render::Softbody::~Softbody(Render::Softbody *this)
{
  UFG::qNode<Render::Softbody,Render::Softbody> *mPrev; // rdx
  UFG::qNode<Render::Softbody,Render::Softbody> *mNext; // rax
  Render::Skinning *p_mModelGuidToClothMap; // rdi
  UFG::qBaseTreeRB *i; // rsi
  UFG::qBaseNodeRB *mParent; // rbx
  Render::PackedPosition *v7; // rdx
  Render::PackedPosition *v8; // rdx
  UFG::qBaseNodeRB *v9; // rdx
  UFG::qBaseNodeRB *v10; // rax
  Render::SkinningCacheNode *Head; // rbx
  Render::Softbody::CollisionShapeCollection *p_mModelSpaceShapes; // rbp
  Render::Softbody::CollisionShapeCollection *p_mSoftbodySpaceShapes; // r15
  Render::Softbody::CollisionShapeCollection *p_mWorldSpaceShapes; // rsi
  Render::SkinningCacheNode *v15; // rbx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v16; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v17; // rax
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v18; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v19; // rax
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v20; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v21; // rax
  UFG::qNode<Render::Softbody,Render::Softbody> *v22; // rcx
  UFG::qNode<Render::Softbody,Render::Softbody> *v23; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
  p_mModelGuidToClothMap = (Render::Skinning *)&this->mModelGuidToClothMap;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)p_mModelGuidToClothMap, &i->mRoot) )
  {
    mParent = i->mNULL.mParent;
    if ( mParent )
    {
      v7 = (Render::PackedPosition *)mParent[1].mParent;
      if ( v7 )
      {
        Render::ISoftbody::AddBufferForDeletion(&Render::gSoftbody, v7);
        mParent[1].mParent = 0i64;
      }
      v8 = *(Render::PackedPosition **)&mParent->mUID;
      if ( v8 )
      {
        Render::ISoftbody::AddBufferForDeletion(&Render::gSoftbody, v8);
        *(_QWORD *)&mParent->mUID = 0i64;
      }
      v9 = mParent->mParent;
      v10 = mParent->mChild[0];
      v9->mChild[0] = v10;
      v10->mParent = v9;
      mParent->mParent = mParent;
      mParent->mChild[0] = mParent;
      operator delete[](mParent);
    }
  }
  while ( p_mModelGuidToClothMap->mSkinnedVertexBuffers.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mModelGuidToClothMap->mSkinnedVertexBuffers);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      &p_mModelGuidToClothMap->mSkinnedVertexBuffers.mTree,
      &Head->mNode);
    operator delete[](Head);
  }
  p_mModelSpaceShapes = &this->mModelSpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mModelSpaceShapes.mShapes);
  p_mSoftbodySpaceShapes = &this->mSoftbodySpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mSoftbodySpaceShapes.mShapes);
  p_mWorldSpaceShapes = &this->mWorldSpaceShapes;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mWorldSpaceShapes.mShapes);
  while ( p_mModelGuidToClothMap->mSkinnedVertexBuffers.mTree.mCount )
  {
    v15 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mModelGuidToClothMap->mSkinnedVertexBuffers);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      &p_mModelGuidToClothMap->mSkinnedVertexBuffers.mTree,
      &v15->mNode);
    operator delete[](v15);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mModelGuidToClothMap);
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mWorldSpaceShapes.mShapes);
  v16 = p_mWorldSpaceShapes->mShapes.mNode.mPrev;
  v17 = this->mWorldSpaceShapes.mShapes.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  p_mWorldSpaceShapes->mShapes.mNode.mPrev = &p_mWorldSpaceShapes->mShapes.mNode;
  this->mWorldSpaceShapes.mShapes.mNode.mNext = &this->mWorldSpaceShapes.mShapes.mNode;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mSoftbodySpaceShapes.mShapes);
  v18 = p_mSoftbodySpaceShapes->mShapes.mNode.mPrev;
  v19 = this->mSoftbodySpaceShapes.mShapes.mNode.mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  p_mSoftbodySpaceShapes->mShapes.mNode.mPrev = &p_mSoftbodySpaceShapes->mShapes.mNode;
  this->mSoftbodySpaceShapes.mShapes.mNode.mNext = &this->mSoftbodySpaceShapes.mShapes.mNode;
  UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mModelSpaceShapes.mShapes);
  v20 = p_mModelSpaceShapes->mShapes.mNode.mPrev;
  v21 = this->mModelSpaceShapes.mShapes.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  p_mModelSpaceShapes->mShapes.mNode.mPrev = &p_mModelSpaceShapes->mShapes.mNode;
  this->mModelSpaceShapes.mShapes.mNode.mNext = &this->mModelSpaceShapes.mShapes.mNode;
  v22 = this->mPrev;
  v23 = this->mNext;
  v22->mNext = v23;
  v23->mPrev = v22;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 313
// RVA: 0x21A70
void __fastcall Render::Softbody::SimUpdate(Render::Softbody *this, float timeStep)
{
  float v2; // xmm6_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::qMap<Render::VerletCloth *> *p_mModelGuidToClothMap; // rbx
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseNodeRB *mParent; // rcx
  float v10; // xmm0_4

  v2 = timeStep * Render::VERLET_timescale;
  if ( this->mSystemVelocityOnceOnly )
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    this->mSystemVelocity.x = UFG::qVector3::msZero.x;
    this->mSystemVelocity.y = y;
    this->mSystemVelocity.z = z;
  }
  v5 = Render::VERLET_gravity.y;
  v6 = Render::VERLET_gravity.z;
  p_mModelGuidToClothMap = &this->mModelGuidToClothMap;
  this->mAccel.x = Render::VERLET_gravity.x;
  this->mAccel.y = v5;
  this->mAccel.z = v6;
  this->mDrag = Render::VERLET_drag;
  this->mFriction = Render::VERLET_friction;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(&p_mModelGuidToClothMap->mTree.mTree, &i->mRoot) )
  {
    mParent = i->mNULL.mParent;
    v10 = *(float *)&mParent->mChild[1];
    if ( v10 > 0.0 )
      *(float *)&mParent->mChild[1] = v10 + v2;
    else
      *(float *)&mParent->mChild[1] = v2;
  }
}

// File Line: 360
// RVA: 0x21960
void __fastcall Render::Softbody::ForceReset(Render::Softbody *this)
{
  UFG::qMap<Render::VerletCloth *> *p_mModelGuidToClothMap; // rbx
  UFG::qBaseTreeRB *i; // rax

  p_mModelGuidToClothMap = &this->mModelGuidToClothMap;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mModelGuidToClothMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(&p_mModelGuidToClothMap->mTree.mTree, &i->mRoot) )
  {
    HIDWORD(i->mNULL.mParent[1].mChild[0]) = 1;
  }
}

// File Line: 369
// RVA: 0x21330
Render::sSoftbodyParams *__fastcall Render::Softbody::CreateTaskParameters(
        Render::Softbody *this,
        Illusion::Model *source_model,
        UFG::qMatrix44 *local2world)
{
  unsigned int mUID; // edx
  UFG::qBaseTreeRB *v7; // rax
  Render::VerletCloth **p_mNULL; // rax
  Render::VerletCloth *v9; // rdi
  Render::sSoftbodyParams *result; // rax
  Render::sSoftbodyParams *v11; // rbx
  UFG::qMatrix44 d; // [rsp+30h] [rbp-58h] BYREF
  __int64 v13; // [rsp+98h] [rbp+10h] BYREF

  mUID = source_model->mNode.mUID;
  v13 = 0i64;
  if ( mUID && (v7 = UFG::qBaseTreeRB::Get(&this->mModelGuidToClothMap.mTree.mTree, mUID)) != 0i64 )
    p_mNULL = (Render::VerletCloth **)&v7->mNULL;
  else
    p_mNULL = (Render::VerletCloth **)&v13;
  v9 = *p_mNULL;
  if ( !*p_mNULL )
    return 0i64;
  result = (Render::sSoftbodyParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x1A0u, 0x10u);
  v11 = result;
  if ( result )
  {
    UFG::qInverse(&d, local2world);
    Render::VerletCloth::FillTaskParameters(v9, v11, source_model, local2world, &d, this);
    return v11;
  }
  return result;
}

// File Line: 413
// RVA: 0x1453C50
__int64 Render::_dynamic_initializer_for__s_uDirectionUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Direction", -1);
  s_uDirectionUID = result;
  return result;
}

// File Line: 414
// RVA: 0x1453C70
__int64 Render::_dynamic_initializer_for__s_uSync01UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Sync01", -1);
  s_uSync01UID = result;
  return result;
}

// File Line: 415
// RVA: 0x1453B70
__int64 Render::_dynamic_initializer_for__s_uBalanceUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Balance", -1);
  s_uBalanceUID = result;
  return result;
}

// File Line: 417
// RVA: 0x1453BF0
__int64 Render::_dynamic_initializer_for__s_uBip01_R_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Clavicle", -1);
  s_uBip01_R_ClavicleUID = result;
  return result;
}

// File Line: 418
// RVA: 0x1453C10
__int64 Render::_dynamic_initializer_for__s_uBip01_R_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R UpperArm", -1);
  s_uBip01_R_UpperArmUID = result;
  return result;
}

// File Line: 419
// RVA: 0x1453CF0
__int64 Render::_dynamic_initializer_for__s_ur_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_upperarm_twist", -1);
  s_ur_upperarm_twistUID = result;
  return result;
}

// File Line: 420
// RVA: 0x1453CD0
__int64 Render::_dynamic_initializer_for__s_ur_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("r_shoulder_joint", -1);
  s_ur_shoulder_jointUID = result;
  return result;
}

// File Line: 422
// RVA: 0x1453B90
__int64 Render::_dynamic_initializer_for__s_uBip01_L_ClavicleUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Clavicle", -1);
  s_uBip01_L_ClavicleUID = result;
  return result;
}

// File Line: 423
// RVA: 0x1453BB0
__int64 Render::_dynamic_initializer_for__s_uBip01_L_UpperArmUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L UpperArm", -1);
  s_uBip01_L_UpperArmUID = result;
  return result;
}

// File Line: 424
// RVA: 0x1453CB0
__int64 Render::_dynamic_initializer_for__s_ul_upperarm_twistUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_upperarm_twist", -1);
  s_ul_upperarm_twistUID = result;
  return result;
}

// File Line: 425
// RVA: 0x1453C90
__int64 Render::_dynamic_initializer_for__s_ul_shoulder_jointUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("l_shoulder_joint", -1);
  s_ul_shoulder_jointUID = result;
  return result;
}

// File Line: 427
// RVA: 0x1453B30
__int64 Render::_dynamic_initializer_for__s_R_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Forearm", -1);
  s_R_Forearm_UID = result;
  return result;
}

// File Line: 428
// RVA: 0x1453B50
__int64 Render::_dynamic_initializer_for__s_R_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R Hand", -1);
  s_R_Hand_UID = result;
  return result;
}

// File Line: 429
// RVA: 0x1453B10
__int64 Render::_dynamic_initializer_for__s_R_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 R ForeTwist", -1);
  s_R_ForeTwist_UID = result;
  return result;
}

// File Line: 431
// RVA: 0x1453AD0
__int64 Render::_dynamic_initializer_for__s_L_Forearm_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Forearm", -1);
  s_L_Forearm_UID = result;
  return result;
}

// File Line: 432
// RVA: 0x1453AF0
__int64 Render::_dynamic_initializer_for__s_L_Hand_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L Hand", -1);
  s_L_Hand_UID = result;
  return result;
}

// File Line: 433
// RVA: 0x1453AB0
__int64 Render::_dynamic_initializer_for__s_L_ForeTwist_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 L ForeTwist", -1);
  s_L_ForeTwist_UID = result;
  return result;
}

// File Line: 435
// RVA: 0x1453BD0
__int64 Render::_dynamic_initializer_for__s_uBip01_Neck_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 Neck", -1);
  s_uBip01_Neck_UID = result;
  return result;
}

// File Line: 436
// RVA: 0x1453C30
__int64 Render::_dynamic_initializer_for__s_uBip01_Spine_UID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Bip01 Spine", -1);
  s_uBip01_Spine_UID = result;
  return result;
}

// File Line: 440
// RVA: 0x21B70
void __fastcall Render::Softbody::UpdateTransform(Render::Softbody *this)
{
  UFG::CompositeDrawableComponent *mCompDrawComp; // rbx
  SkeletalPose *mPose; // rbx
  int BoneID; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm0
  UFG::qVector3 centre; // [rsp+18h] [rbp-39h] BYREF
  UFG::qMatrix44 v11; // [rsp+28h] [rbp-29h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+68h] [rbp+17h] BYREF

  mCompDrawComp = this->mCompDrawComp;
  if ( mCompDrawComp )
  {
    mPose = mCompDrawComp->mPose;
    if ( mPose )
    {
      BoneID = Skeleton::GetBoneID(mPose->mRigHandle.mUFGSkeleton, s_uBip01_Spine_UID);
      if ( BoneID >= 0 )
        SkeletalPose::GetPositionWS(mPose, BoneID, &matrixWS);
      UFG::qList<UFG::EngineModelBlendMode,UFG::EngineModelBlendMode,1,0>::DeleteNodes(&this->mWorldSpaceShapes.mShapes);
      v5 = Skeleton::GetBoneID(mPose->mRigHandle.mUFGSkeleton, s_uBip01_R_ClavicleUID);
      if ( v5 >= 0 )
      {
        SkeletalPose::GetPositionWS(mPose, v5, &v11);
        centre.z = v11.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&this->mWorldSpaceShapes, &centre, 0.1);
      }
      v6 = Skeleton::GetBoneID(mPose->mRigHandle.mUFGSkeleton, s_uBip01_L_ClavicleUID);
      if ( v6 >= 0 )
      {
        SkeletalPose::GetPositionWS(mPose, v6, &v11);
        centre.z = v11.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&this->mWorldSpaceShapes, &centre, 0.1);
      }
      v7 = Skeleton::GetBoneID(mPose->mRigHandle.mUFGSkeleton, s_uBip01_Neck_UID);
      if ( v7 >= 0 )
      {
        SkeletalPose::GetPositionWS(mPose, v7, &v11);
        centre.z = v11.v3.z;
        Render::Softbody::CollisionShapeCollection::AddSphere(&this->mWorldSpaceShapes, &centre, 0.1);
      }
    }
    else
    {
      matrixWS = UFG::qMatrix44::msIdentity;
    }
    v8 = matrixWS.v2;
    this->mWorld.v0 = matrixWS.v0;
    this->mWorld.v1 = matrixWS.v1;
    v9 = matrixWS.v3;
    this->mWorld.v2 = v8;
    this->mWorld.v3 = v9;
    UFG::qInverse(&this->mInvWorld, &this->mWorld);
  }
}

// File Line: 505
// RVA: 0x21170
Render::VerletCloth *__fastcall Render::Softbody::AddModel(Render::Softbody *this, Illusion::Model *src_model)
{
  Render::VerletCloth *v4; // rbx
  __int64 mOffset; // rax
  char *v6; // rax
  Illusion::SoftbodyData *v7; // rdi
  __int64 v8; // rax
  _QWORD *v9; // rax
  Illusion::Mesh *v10; // rsi
  char *v12; // rax
  Render::VerletCloth *v13; // rax
  Render::VerletCloth *value; // [rsp+58h] [rbp+10h] BYREF

  v4 = 0i64;
  mOffset = src_model->mModelUser.mOffset;
  if ( mOffset )
  {
    v6 = (char *)&src_model->mModelUser + mOffset;
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
          UFG::qMap<Render::VerletCloth *>::Set(&this->mModelGuidToClothMap, src_model->mNode.mUID, &value);
        }
      }
    }
  }
  return v4;
}

// File Line: 545
// RVA: 0x21260
void __fastcall Render::Softbody::CollisionShapeCollection::AddSphere(
        Render::Softbody::CollisionShapeCollection *this,
        UFG::qVector3 *centre,
        float radius)
{
  char *v6; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *v11; // rcx
  UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *mPrev; // rax

  v6 = UFG::qMalloc(0x38ui64, "SoftbodyCollisionSphere", 0i64);
  if ( v6 )
  {
    *((_QWORD *)v6 + 1) = v6 + 8;
    *((_QWORD *)v6 + 2) = v6 + 8;
    *(_QWORD *)v6 = &Render::SoftbodyCollisionShape::`vftable;
    *(_QWORD *)v6 = &Render::SoftbodyCollisionSphere::`vftable;
    y = centre->y;
    z = centre->z;
    *((_DWORD *)v6 + 6) = LODWORD(centre->x);
    *((float *)v6 + 7) = y;
    *((float *)v6 + 8) = z;
    *((float *)v6 + 9) = radius;
    v9 = centre->y;
    v10 = centre->z;
    *((_DWORD *)v6 + 10) = LODWORD(centre->x);
    *((float *)v6 + 11) = v9;
    *((float *)v6 + 12) = v10;
    *((float *)v6 + 13) = radius;
  }
  v11 = (UFG::qNode<Render::SoftbodyCollisionShape,Render::SoftbodyCollisionShape> *)(v6 + 8);
  mPrev = this->mShapes.mNode.mPrev;
  mPrev->mNext = v11;
  v11->mPrev = mPrev;
  v11->mNext = &this->mShapes.mNode;
  this->mShapes.mNode.mPrev = v11;
}

// File Line: 563
// RVA: 0x219B0
Render::Softbody *__fastcall Render::ISoftbody::GenerateSoftbody(
        Render::ISoftbody *this,
        UFG::CompositeDrawableComponent *src_composite_drawable,
        ModelType::ModelBindingSkin *binding)
{
  Render::Softbody *mSoftbody; // rbx
  char *v7; // rax
  Render::Softbody *v8; // rax
  Render::Softbody *v9; // rbx

  mSoftbody = binding->mSoftbody;
  if ( mSoftbody )
  {
    Render::Softbody::~Softbody(binding->mSoftbody);
    operator delete[](mSoftbody);
    binding->mSoftbody = 0i64;
  }
  if ( !binding->mModelProxy.mModelHandle.mData )
    return 0i64;
  v7 = UFG::qMalloc(0x138ui64, "Softbody", 0i64);
  if ( v7 )
  {
    Render::Softbody::Softbody((Render::Softbody *)v7, src_composite_drawable);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  if ( Render::Softbody::AddModel(v9, (Illusion::Model *)binding->mModelProxy.mModelHandle.mData) )
  {
    binding->mSoftbody = v9;
  }
  else
  {
    if ( v9 )
    {
      Render::Softbody::~Softbody(v9);
      operator delete[](v9);
    }
    return 0i64;
  }
  return v9;
}

// File Line: 612
// RVA: 0x21050
void __fastcall Render::ISoftbody::AddBufferForDeletion(
        Render::ISoftbody *this,
        Render::PackedPosition *packedPositions)
{
  __int64 size; // rbp
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char *v7; // rax
  Render::PackedPosition **v8; // r9
  Render::PackedPosition **p; // rsi
  __int64 i; // r8
  __int64 v11; // rdx

  size = Render::ISoftbody::s_DeletionQueue.size;
  v4 = Render::ISoftbody::s_DeletionQueue.size + 1;
  if ( Render::ISoftbody::s_DeletionQueue.size + 1 <= Render::ISoftbody::s_DeletionQueue.capacity )
    goto LABEL_19;
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
  if ( v5 == Render::ISoftbody::s_DeletionQueue.size )
  {
LABEL_19:
    p = Render::ISoftbody::s_DeletionQueue.p;
  }
  else
  {
    v6 = 8i64 * v5;
    if ( !is_mul_ok(v5, 8ui64) )
      v6 = -1i64;
    v7 = UFG::qMalloc(v6, "qArray.Add", 0i64);
    v8 = Render::ISoftbody::s_DeletionQueue.p;
    p = (Render::PackedPosition **)v7;
    if ( Render::ISoftbody::s_DeletionQueue.p )
    {
      for ( i = 0i64; (unsigned int)i < Render::ISoftbody::s_DeletionQueue.size; v8 = Render::ISoftbody::s_DeletionQueue.p )
      {
        v11 = i;
        i = (unsigned int)(i + 1);
        *(_QWORD *)&v7[v11 * 8] = v8[v11];
      }
      operator delete[](v8);
    }
    Render::ISoftbody::s_DeletionQueue.p = p;
    Render::ISoftbody::s_DeletionQueue.capacity = v5;
  }
  Render::ISoftbody::s_DeletionQueue.size = v4;
  p[size] = packedPositions;
}

// File Line: 617
// RVA: 0x21400
void __fastcall Render::ISoftbody::DeleteQueuedBuffers(Render::ISoftbody *this)
{
  unsigned int size; // eax

  if ( Render::ISoftbody::s_DeletionQueue.size )
  {
    while ( 1 )
    {
      operator delete[](*(void **)Render::ISoftbody::s_DeletionQueue.p);
      *Render::ISoftbody::s_DeletionQueue.p = Render::ISoftbody::s_DeletionQueue.p[Render::ISoftbody::s_DeletionQueue.size
                                                                                 - 1];
      size = Render::ISoftbody::s_DeletionQueue.size;
      if ( Render::ISoftbody::s_DeletionQueue.size <= 1 )
        break;
      --Render::ISoftbody::s_DeletionQueue.size;
      if ( size == 1 )
        return;
    }
    Render::ISoftbody::s_DeletionQueue.size = 0;
  }
}

