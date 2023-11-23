// File Line: 12
// RVA: 0x3C3E50
const char *__fastcall UFG::CameraSubject::GetTypeName(UFG::CameraSubject *this)
{
  return "CameraSubject";
}

// File Line: 16
// RVA: 0x3BA9E0
void __fastcall UFG::CameraSubject::CameraSubject(UFG::CameraSubject *this, unsigned int name_uid)
{
  UFG::SimComponent::SimComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->pTransformNodeComponent);
  UFG::SimComponent::AddType(this, UFG::CameraSubject::_CameraSubjectTypeUID, "CameraSubject");
  UFG::CameraSubject::Init(this);
}

// File Line: 24
// RVA: 0x3BDC30
void __fastcall UFG::CameraSubject::~CameraSubject(UFG::CameraSubject *this)
{
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->pTransformNodeComponent);
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 30
// RVA: 0x3C5860
void __fastcall UFG::CameraSubject::Init(UFG::CameraSubject *this)
{
  __m128 v1; // xmm2
  float w; // xmm3_4
  float x; // xmm0_4
  float v4; // xmm3_4
  float v5; // xmm0_4

  v1 = 0i64;
  v1.m128_f32[0] = (float)1;
  this->mLocalWorld.v0 = (UFG::qVector4)v1;
  this->mLocalWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 81);
  this->mLocalWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 69);
  this->mLocalWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 21);
  this->mWorldLocal.v0 = (UFG::qVector4)v1;
  this->mWorldLocal.v1 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 81);
  this->mWorldLocal.v2 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 69);
  this->mWorldLocal.v3 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 21);
  this->bPinnedPosition = 0;
  this->mPinPosParam = 0.0;
  v1.m128_i32[0] = LODWORD(UFG::qVector4::msZero.z);
  w = UFG::qVector4::msZero.w;
  x = UFG::qVector4::msZero.x;
  this->mPinPos.y = UFG::qVector4::msZero.y;
  LODWORD(this->mPinPos.z) = v1.m128_i32[0];
  this->mPinPos.x = x;
  this->mPinPos.w = w;
  this->bPinnedOrientation = 0;
  this->mPinOrientParam = 0.0;
  v1.m128_i32[0] = LODWORD(UFG::qQuaternion::msUnity.z);
  v4 = UFG::qQuaternion::msUnity.w;
  v5 = UFG::qQuaternion::msUnity.x;
  this->mPinOrient.y = UFG::qQuaternion::msUnity.y;
  LODWORD(this->mPinOrient.z) = v1.m128_i32[0];
  this->mPinOrient.x = v5;
  this->mPinOrient.w = v4;
}

// File Line: 45
// RVA: 0x3C7940
void __fastcall UFG::CameraSubject::OnAttach(UFG::CameraSubject *this, UFG::SimObject *object)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1

  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->pTransformNodeComponent,
    object);
  m_pSimComponent = this->pTransformNodeComponent.m_pSimComponent;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent);
    v4 = *(UFG::qVector4 *)&m_pSimComponent[2].m_SafePointerList.mNode.mNext;
    v5 = *(UFG::qVector4 *)&m_pSimComponent[2].m_Flags;
    m_BoundComponentHandles = (UFG::qVector4)m_pSimComponent[2].m_BoundComponentHandles;
    this->mLocalWorld.v0 = *(UFG::qVector4 *)&m_pSimComponent[2].vfptr;
    this->mLocalWorld.v1 = v4;
    this->mLocalWorld.v2 = v5;
    this->mLocalWorld.v3 = m_BoundComponentHandles;
  }
}

// File Line: 52
// RVA: 0x3C7B10
void __fastcall UFG::CameraSubject::OnDetach(UFG::CameraSubject *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_pTransformNodeComponent = &this->pTransformNodeComponent;
  if ( this->pTransformNodeComponent.m_pSimComponent )
  {
    mNext = this->pTransformNodeComponent.mNext;
    mPrev = p_pTransformNodeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_pTransformNodeComponent->mNext = p_pTransformNodeComponent;
    p_pTransformNodeComponent->mPrev = p_pTransformNodeComponent;
    p_pTransformNodeComponent->m_Changed = 1;
    p_pTransformNodeComponent->m_pSimComponent = 0i64;
    p_pTransformNodeComponent->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->pTransformNodeComponent.m_pSimObject
      && (p_pTransformNodeComponent->mPrev != p_pTransformNodeComponent
       || this->pTransformNodeComponent.mNext != &this->pTransformNodeComponent) )
    {
      v4 = this->pTransformNodeComponent.mNext;
      v5 = p_pTransformNodeComponent->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_pTransformNodeComponent->mNext = p_pTransformNodeComponent;
      p_pTransformNodeComponent->mPrev = p_pTransformNodeComponent;
      p_pTransformNodeComponent->m_pSimObject = 0i64;
    }
    p_pTransformNodeComponent->m_Changed = 1;
  }
}

// File Line: 58
// RVA: 0x3C4380
UFG::qVector3 *__fastcall UFG::CameraSubject::GetVelocity(UFG::CameraSubject *this)
{
  UFG::SimComponent *m_pSimComponent; // rbx

  m_pSimComponent = this->pTransformNodeComponent.m_pSimComponent;
  if ( !m_pSimComponent )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent);
  return (UFG::qVector3 *)&m_pSimComponent[4];
}

// File Line: 111
// RVA: 0x3C7DA0
void __fastcall UFG::CameraSubject::PinOrientationSmooth(
        UFG::CameraSubject *this,
        UFG::CameraSubject::PinOrientMode mode)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float x; // xmm4_4
  float y; // xmm5_4
  __m128 y_low; // xmm1
  float v8; // xmm3_4
  UFG::qMatrix44 *p_mWorldTransform; // rdx
  UFG::TransformNodeComponent *v10; // rbx
  float v11[2]; // [rsp+20h] [rbp-48h] BYREF
  __int64 v12; // [rsp+28h] [rbp-40h]
  unsigned int v13; // [rsp+30h] [rbp-38h]
  float v14; // [rsp+34h] [rbp-34h]
  __int64 v15; // [rsp+38h] [rbp-30h]
  UFG::qVector4 v16; // [rsp+40h] [rbp-28h]
  UFG::qVector4 v17; // [rsp+50h] [rbp-18h]

  m_pSimComponent = (UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent;
  this->bPinnedOrientation = 1;
  if ( m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    x = m_pSimComponent->mWorldVelocity.x;
    y = m_pSimComponent->mWorldVelocity.y;
    if ( mode == PinOrientMode_Velocity
      && (y_low = (__m128)LODWORD(m_pSimComponent->mWorldVelocity.y),
          y_low.m128_f32[0] = (float)(y * y) + (float)(x * x),
          y_low.m128_f32[0] > 1.0) )
    {
      if ( y_low.m128_f32[0] == 0.0 )
        v8 = 0.0;
      else
        v8 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
      p_mWorldTransform = (UFG::qMatrix44 *)v11;
      v12 = *(_QWORD *)&UFG::qMatrix44::msIdentity.v0.z;
      v15 = *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.z;
      v11[1] = v8 * y;
      v11[0] = v8 * x;
      v14 = v8 * x;
      v16 = UFG::qMatrix44::msIdentity.v2;
      v17 = UFG::qMatrix44::msIdentity.v3;
      v13 = COERCE_UNSIGNED_INT(v8 * y) ^ _xmm[0];
    }
    else
    {
      v10 = (UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v10);
      p_mWorldTransform = &v10->mWorldTransform;
    }
    UFG::qQuaternion::Set(&this->mPinOrient, p_mWorldTransform);
  }
}

// File Line: 144
// RVA: 0x3D85E0
void __fastcall UFG::CameraSubject::UpdateBase(
        UFG::CameraSubject *this,
        float delta_sec,
        bool debug_draw,
        UFG::CameraSubject::UpdateParams *update_params)
{
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  UFG::qMatrix44 *Matrix; // rax
  float v9; // xmm9_4
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1
  bool bPinnedOrientation; // al
  float v14; // xmm1_4
  float mPinRotRate; // xmm2_4
  float mPinPosParam; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float mPinPosRate; // xmm2_4
  UFG::qQuaternion a; // [rsp+30h] [rbp-98h] BYREF
  UFG::qQuaternion result; // [rsp+40h] [rbp-88h] BYREF
  UFG::qMatrix44 v23; // [rsp+50h] [rbp-78h] BYREF

  if ( this->pTransformNodeComponent.m_pSimComponent )
  {
    m_pSimComponent = (UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    UFG::qQuaternion::Set(&a, &m_pSimComponent->mWorldTransform);
    UFG::qNlerp(&result, &a, &this->mPinOrient, this->mPinOrientParam, qAngularPath_Shortest);
    Matrix = UFG::qQuaternion::GetMatrix(&result, &v23, &UFG::qVector3::msZero);
    v9 = *(float *)&FLOAT_1_0;
    v10 = Matrix->v1;
    v11 = Matrix->v2;
    v12 = Matrix->v3;
    this->mLocalWorld.v0 = Matrix->v0;
    this->mLocalWorld.v1 = v10;
    this->mLocalWorld.v2 = v11;
    this->mLocalWorld.v3 = v12;
    bPinnedOrientation = this->bPinnedOrientation;
    if ( bPinnedOrientation )
      v14 = *(float *)&FLOAT_1_0;
    else
      v14 = 0.0;
    if ( bPinnedOrientation )
      mPinRotRate = update_params->mPinRotRate;
    else
      mPinRotRate = update_params->mUnpinRotRate;
    UFG::qApproach(&this->mPinOrientParam, v14, mPinRotRate, delta_sec);
    mPinPosParam = this->mPinPosParam;
    v17 = (float)((float)(this->mPinPos.y - m_pSimComponent->mWorldTransform.v3.y) * mPinPosParam)
        + m_pSimComponent->mWorldTransform.v3.y;
    v18 = (float)((float)(this->mPinPos.z - m_pSimComponent->mWorldTransform.v3.z) * mPinPosParam)
        + m_pSimComponent->mWorldTransform.v3.z;
    v19 = (float)((float)(this->mPinPos.w - m_pSimComponent->mWorldTransform.v3.w) * mPinPosParam)
        + m_pSimComponent->mWorldTransform.v3.w;
    this->mLocalWorld.v3.x = (float)((float)(this->mPinPos.x - m_pSimComponent->mWorldTransform.v3.x) * mPinPosParam)
                           + m_pSimComponent->mWorldTransform.v3.x;
    this->mLocalWorld.v3.y = v17;
    this->mLocalWorld.v3.z = v18;
    this->mLocalWorld.v3.w = v19;
    if ( this->bPinnedPosition )
    {
      mPinPosRate = update_params->mPinPosRate;
    }
    else
    {
      mPinPosRate = update_params->mUnpinPosRate;
      v9 = 0.0;
    }
    UFG::qApproach(&this->mPinPosParam, v9, mPinPosRate, delta_sec);
    UFG::qInverseAffine(&this->mWorldLocal, &this->mLocalWorld);
  }
}

// File Line: 207
// RVA: 0x3C28C0
void __fastcall UFG::CameraSubject::GetBoxVerts(UFG::CameraSubject *this, UFG::qVector3 *verts, float margin)
{
  __int64 v5; // rax
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  __int64 v9; // rax
  float v10; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v5 = ((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[23].__vecDelDtor)(this);
  v6 = *(float *)(v5 + 8);
  v7 = *(float *)v5 - margin;
  v8 = *(float *)(v5 + 4) - margin;
  v9 = ((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[24].__vecDelDtor)(this);
  v10 = margin + *(float *)(v9 + 4);
  v11 = margin + *(float *)v9;
  v12 = *(float *)(v9 + 8);
  verts->x = v7;
  verts->y = v8;
  verts->z = v6;
  verts[1].x = v7;
  verts[1].y = v8;
  verts[1].z = v12;
  verts[2].y = v10;
  verts[2].x = v7;
  verts[2].z = v6;
  verts[3].x = v7;
  verts[3].y = v10;
  verts[3].z = v12;
  verts[4].y = v8;
  verts[4].z = v6;
  verts[4].x = v11;
  verts[5].y = v8;
  verts[5].x = v11;
  verts[5].z = v12;
  verts[6].y = v10;
  verts[6].z = v6;
  verts[6].x = v11;
  verts[7].y = v10;
  verts[7].x = v11;
  verts[7].z = v12;
}

// File Line: 223
// RVA: 0x3C2D70
UFG::qVector3 *__fastcall UFG::CameraSubject::GetExtentInDirection(
        UFG::CameraSubject *this,
        UFG::qVector3 *result,
        UFG::qVector3 *world_direction,
        UFG::qVector3 *local_corners)
{
  int v4; // eax
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  __int64 v10; // rcx
  UFG::qVector3 *v11; // rax
  float x; // xmm0_4
  float z; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm2_4
  float v16; // xmm2_4

  v4 = 0;
  v6 = (float)((float)((float)(world_direction->y * this->mWorldLocal.v1.x)
                     + (float)(world_direction->x * this->mWorldLocal.v0.x))
             + (float)(world_direction->z * this->mWorldLocal.v2.x))
     + (float)(this->mWorldLocal.v3.x * 0.0);
  v7 = (float)((float)((float)(world_direction->x * this->mWorldLocal.v0.y)
                     + (float)(world_direction->y * this->mWorldLocal.v1.y))
             + (float)(world_direction->z * this->mWorldLocal.v2.y))
     + (float)(this->mWorldLocal.v3.y * 0.0);
  v8 = (float)((float)((float)(world_direction->x * this->mWorldLocal.v0.z)
                     + (float)(world_direction->y * this->mWorldLocal.v1.z))
             + (float)(world_direction->z * this->mWorldLocal.v2.z))
     + (float)(this->mWorldLocal.v3.z * 0.0);
  v9 = (float)((float)(v7 * local_corners->y) + (float)(v6 * local_corners->x)) + (float)(v8 * local_corners->z);
  if ( (float)((float)((float)(v7 * local_corners[1].y) + (float)(v6 * local_corners[1].x))
             + (float)(v8 * local_corners[1].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[1].y) + (float)(v6 * local_corners[1].x)) + (float)(v8 * local_corners[1].z);
    v4 = 1;
  }
  if ( (float)((float)((float)(v7 * local_corners[2].y) + (float)(v6 * local_corners[2].x))
             + (float)(v8 * local_corners[2].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[2].y) + (float)(v6 * local_corners[2].x)) + (float)(v8 * local_corners[2].z);
    v4 = 2;
  }
  if ( (float)((float)((float)(v7 * local_corners[3].y) + (float)(v6 * local_corners[3].x))
             + (float)(v8 * local_corners[3].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[3].y) + (float)(v6 * local_corners[3].x)) + (float)(v8 * local_corners[3].z);
    v4 = 3;
  }
  if ( (float)((float)((float)(v7 * local_corners[4].y) + (float)(v6 * local_corners[4].x))
             + (float)(v8 * local_corners[4].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[4].y) + (float)(v6 * local_corners[4].x)) + (float)(v8 * local_corners[4].z);
    v4 = 4;
  }
  if ( (float)((float)((float)(v7 * local_corners[5].y) + (float)(v6 * local_corners[5].x))
             + (float)(v8 * local_corners[5].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[5].y) + (float)(v6 * local_corners[5].x)) + (float)(v8 * local_corners[5].z);
    v4 = 5;
  }
  if ( (float)((float)((float)(v7 * local_corners[6].y) + (float)(v6 * local_corners[6].x))
             + (float)(v8 * local_corners[6].z)) > v9 )
  {
    v9 = (float)((float)(v7 * local_corners[6].y) + (float)(v6 * local_corners[6].x)) + (float)(v8 * local_corners[6].z);
    v4 = 6;
  }
  if ( (float)((float)((float)(v7 * local_corners[7].y) + (float)(v6 * local_corners[7].x))
             + (float)(v8 * local_corners[7].z)) > v9 )
    v4 = 7;
  v10 = v4;
  v11 = result;
  x = local_corners[v10].x;
  z = local_corners[v10].z;
  v14 = (float)(local_corners[v10].y * this->mLocalWorld.v1.z) + (float)(x * this->mLocalWorld.v0.z);
  v15 = (float)(local_corners[v10].y * this->mLocalWorld.v1.y) + (float)(x * this->mLocalWorld.v0.y);
  result->x = (float)((float)((float)(local_corners[v10].y * this->mLocalWorld.v1.x)
                            + (float)(x * this->mLocalWorld.v0.x))
                    + (float)(z * this->mLocalWorld.v2.x))
            + this->mLocalWorld.v3.x;
  v16 = (float)(v15 + (float)(z * this->mLocalWorld.v2.y)) + this->mLocalWorld.v3.y;
  result->z = (float)(v14 + (float)(z * this->mLocalWorld.v2.z)) + this->mLocalWorld.v3.z;
  result->y = v16;
  return v11;
}is->mLocalWorld.v2.z)) + this->mLocalWor

