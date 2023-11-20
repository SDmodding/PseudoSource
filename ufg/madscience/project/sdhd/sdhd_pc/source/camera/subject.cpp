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
  UFG::CameraSubject *v2; // rbx

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->pTransformNodeComponent);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CameraSubject::_CameraSubjectTypeUID,
    "CameraSubject");
  UFG::CameraSubject::Init(v2);
}

// File Line: 24
// RVA: 0x3BDC30
void __fastcall UFG::CameraSubject::~CameraSubject(UFG::CameraSubject *this)
{
  UFG::CameraSubject *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CameraSubject::`vftable;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->pTransformNodeComponent);
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 30
// RVA: 0x3C5860
void __fastcall UFG::CameraSubject::Init(UFG::CameraSubject *this)
{
  __m128 v1; // xmm2
  float v2; // xmm3_4
  float v3; // xmm0_4
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
  v2 = UFG::qVector4::msZero.w;
  v3 = UFG::qVector4::msZero.x;
  this->mPinPos.y = UFG::qVector4::msZero.y;
  LODWORD(this->mPinPos.z) = v1.m128_i32[0];
  this->mPinPos.x = v3;
  this->mPinPos.w = v2;
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
  UFG::CameraSubject *v2; // rbx
  UFG::SimComponent *v3; // rdi
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  v2 = this;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->pTransformNodeComponent,
    object);
  v3 = v2->pTransformNodeComponent.m_pSimComponent;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->pTransformNodeComponent.m_pSimComponent);
    v4 = *(UFG::qVector4 *)&v3[2].m_SafePointerList.mNode.mNext;
    v5 = *(UFG::qVector4 *)&v3[2].m_Flags;
    v6 = (UFG::qVector4)v3[2].m_BoundComponentHandles;
    v2->mLocalWorld.v0 = *(UFG::qVector4 *)&v3[2].vfptr;
    v2->mLocalWorld.v1 = v4;
    v2->mLocalWorld.v2 = v5;
    v2->mLocalWorld.v3 = v6;
  }
}

// File Line: 52
// RVA: 0x3C7B10
void __fastcall UFG::CameraSubject::OnDetach(UFG::CameraSubject *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->pTransformNodeComponent;
  if ( this->pTransformNodeComponent.m_pSimComponent )
  {
    v2 = this->pTransformNodeComponent.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->pTransformNodeComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->pTransformNodeComponent.mNext != &this->pTransformNodeComponent) )
    {
      v4 = this->pTransformNodeComponent.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 58
// RVA: 0x3C4380
UFG::qVector3 *__fastcall UFG::CameraSubject::GetVelocity(UFG::CameraSubject *this)
{
  UFG::SimComponent *v1; // rbx

  v1 = this->pTransformNodeComponent.m_pSimComponent;
  if ( !v1 )
    return &UFG::qVector3::msZero;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent);
  return (UFG::qVector3 *)&v1[4];
}

// File Line: 111
// RVA: 0x3C7DA0
void __fastcall UFG::CameraSubject::PinOrientationSmooth(UFG::CameraSubject *this, UFG::CameraSubject::PinOrientMode mode)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::CameraSubject::PinOrientMode v3; // esi
  UFG::CameraSubject *v4; // rdi
  float v5; // xmm4_4
  float v6; // xmm5_4
  __m128 v7; // xmm1
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  UFG::qMatrix44 *v11; // rdx
  UFG::SimComponent *v12; // rbx
  UFG::qVector4 v13; // [rsp+20h] [rbp-48h]
  UFG::qVector4 v14; // [rsp+30h] [rbp-38h]
  UFG::qVector4 v15; // [rsp+40h] [rbp-28h]
  UFG::qVector4 v16; // [rsp+50h] [rbp-18h]

  v2 = (UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent;
  v3 = mode;
  v4 = this;
  this->bPinnedOrientation = 1;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v5 = v2->mWorldVelocity.x;
    v6 = v2->mWorldVelocity.y;
    if ( v3 != 1
      || (v7 = (__m128)LODWORD(v2->mWorldVelocity.y),
          v7.m128_f32[0] = (float)(v6 * v6) + (float)(v5 * v5),
          v7.m128_f32[0] <= 1.0) )
    {
      v12 = v4->pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v4->pTransformNodeComponent.m_pSimComponent);
      v11 = (UFG::qMatrix44 *)&v12[2];
    }
    else
    {
      if ( v7.m128_f32[0] == 0.0 )
        v8 = 0.0;
      else
        v8 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
      v9 = v8;
      v10 = v8 * v6;
      v11 = (UFG::qMatrix44 *)&v13;
      v13 = UFG::qMatrix44::msIdentity.v0;
      v14 = UFG::qMatrix44::msIdentity.v1;
      v13.y = v10;
      v13.x = v9 * v5;
      v14.y = v9 * v5;
      v15 = UFG::qMatrix44::msIdentity.v2;
      v16 = UFG::qMatrix44::msIdentity.v3;
      LODWORD(v14.x) = LODWORD(v10) ^ _xmm[0];
    }
    UFG::qQuaternion::Set(&v4->mPinOrient, v11);
  }
}

// File Line: 144
// RVA: 0x3D85E0
void __fastcall UFG::CameraSubject::UpdateBase(UFG::CameraSubject *this, float delta_sec, bool debug_draw, UFG::CameraSubject::UpdateParams *update_params)
{
  UFG::CameraSubject::UpdateParams *v4; // rsi
  float v5; // xmm10_4
  UFG::CameraSubject *v6; // rdi
  UFG::TransformNodeComponent *v7; // rbx
  UFG::qMatrix44 *v8; // rax
  float v9; // xmm9_4
  UFG::qVector4 v10; // xmm3
  UFG::qVector4 v11; // xmm2
  UFG::qVector4 v12; // xmm1
  bool v13; // al
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  UFG::qQuaternion a; // [rsp+30h] [rbp-98h]
  UFG::qQuaternion result; // [rsp+40h] [rbp-88h]
  UFG::qMatrix44 v23; // [rsp+50h] [rbp-78h]

  v4 = update_params;
  v5 = delta_sec;
  v6 = this;
  if ( this->pTransformNodeComponent.m_pSimComponent )
  {
    v7 = (UFG::TransformNodeComponent *)this->pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v7);
    UFG::qQuaternion::Set(&a, &v7->mWorldTransform);
    UFG::qNlerp(&result, &a, &v6->mPinOrient, v6->mPinOrientParam, 0);
    v8 = UFG::qQuaternion::GetMatrix(&result, &v23, &UFG::qVector3::msZero);
    v9 = *(float *)&FLOAT_1_0;
    v10 = v8->v1;
    v11 = v8->v2;
    v12 = v8->v3;
    v6->mLocalWorld.v0 = v8->v0;
    v6->mLocalWorld.v1 = v10;
    v6->mLocalWorld.v2 = v11;
    v6->mLocalWorld.v3 = v12;
    v13 = v6->bPinnedOrientation;
    if ( v13 )
      v14 = *(float *)&FLOAT_1_0;
    else
      v14 = 0.0;
    if ( v13 )
      v15 = v4->mPinRotRate;
    else
      v15 = v4->mUnpinRotRate;
    UFG::qApproach(&v6->mPinOrientParam, v14, v15, v5);
    v16 = v6->mPinPosParam;
    v17 = (float)((float)(v6->mPinPos.y - v7->mWorldTransform.v3.y) * v16) + v7->mWorldTransform.v3.y;
    v18 = (float)((float)(v6->mPinPos.z - v7->mWorldTransform.v3.z) * v16) + v7->mWorldTransform.v3.z;
    v19 = (float)((float)(v6->mPinPos.w - v7->mWorldTransform.v3.w) * v16) + v7->mWorldTransform.v3.w;
    v6->mLocalWorld.v3.x = (float)((float)(v6->mPinPos.x - v7->mWorldTransform.v3.x) * v16) + v7->mWorldTransform.v3.x;
    v6->mLocalWorld.v3.y = v17;
    v6->mLocalWorld.v3.z = v18;
    v6->mLocalWorld.v3.w = v19;
    if ( v6->bPinnedPosition )
    {
      v20 = v4->mPinPosRate;
    }
    else
    {
      v20 = v4->mUnpinPosRate;
      v9 = 0.0;
    }
    UFG::qApproach(&v6->mPinPosParam, v9, v20, v5);
    UFG::qInverseAffine(&v6->mWorldLocal, &v6->mLocalWorld);
  }
}

// File Line: 207
// RVA: 0x3C28C0
void __fastcall UFG::CameraSubject::GetBoxVerts(UFG::CameraSubject *this, UFG::qVector3 *verts, float margin)
{
  UFG::qVector3 *v3; // rdi
  UFG::CameraSubject *v4; // rbx
  __int64 v5; // rax
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  __int64 v9; // rax
  float v10; // xmm9_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v3 = verts;
  v4 = this;
  v5 = ((__int64 (*)(void))this->vfptr[23].__vecDelDtor)();
  v6 = *(float *)(v5 + 8);
  v7 = *(float *)v5 - margin;
  v8 = *(float *)(v5 + 4) - margin;
  v9 = ((__int64 (__fastcall *)(UFG::CameraSubject *))v4->vfptr[24].__vecDelDtor)(v4);
  v10 = margin + *(float *)(v9 + 4);
  v11 = margin + *(float *)v9;
  v12 = *(float *)(v9 + 8);
  v3->x = v7;
  v3->y = v8;
  v3->z = v6;
  v3[1].x = v7;
  v3[1].y = v8;
  v3[1].z = v12;
  v3[2].y = v10;
  v3[2].x = v7;
  v3[2].z = v6;
  v3[3].x = v7;
  v3[3].y = v10;
  v3[3].z = v12;
  v3[4].y = v8;
  v3[4].z = v6;
  v3[4].x = v11;
  v3[5].y = v8;
  v3[5].x = v11;
  v3[5].z = v12;
  v3[6].y = v10;
  v3[6].z = v6;
  v3[6].x = v11;
  v3[7].y = v10;
  v3[7].x = v11;
  v3[7].z = v12;
}

// File Line: 223
// RVA: 0x3C2D70
UFG::qVector3 *__fastcall UFG::CameraSubject::GetExtentInDirection(UFG::CameraSubject *this, UFG::qVector3 *result, UFG::qVector3 *world_direction, UFG::qVector3 *local_corners)
{
  signed int v4; // eax
  UFG::CameraSubject *v5; // r10
  float v6; // xmm7_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  __int64 v10; // rcx
  UFG::qVector3 *v11; // rax
  float v12; // xmm4_4
  float v13; // xmm6_4
  float v14; // xmm2_4
  float v15; // xmm2_4

  v4 = 0;
  v5 = this;
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
  v12 = local_corners[v10].z;
  v13 = (float)(local_corners[v10].y * v5->mLocalWorld.v1.z) + (float)(local_corners[v10].x * v5->mLocalWorld.v0.z);
  v14 = (float)(local_corners[v10].y * v5->mLocalWorld.v1.y) + (float)(local_corners[v10].x * v5->mLocalWorld.v0.y);
  result->x = (float)((float)((float)(local_corners[v10].y * v5->mLocalWorld.v1.x)
                            + (float)(local_corners[v10].x * v5->mLocalWorld.v0.x))
                    + (float)(local_corners[v10].z * v5->mLocalWorld.v2.x))
            + v5->mLocalWorld.v3.x;
  v15 = (float)(v14 + (float)(v12 * v5->mLocalWorld.v2.y)) + v5->mLocalWorld.v3.y;
  result->z = (float)(v13 + (float)(v12 * v5->mLocalWorld.v2.z)) + v5->mLocalWorld.v3.z;
  result->y = v15;
  return v11;
}->mLocalW

