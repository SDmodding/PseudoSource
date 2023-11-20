// File Line: 40
// RVA: 0x3C5A20
void __fastcall UFG::PhotoTarget::Init(UFG::PhotoTarget *this, UFG::SimObject *object, UFG::qVector3 *position, bool frontOnly, bool upload, float delay)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  UFG::PhotoTarget *v10; // rbx
  UFG::SimObject *v11; // rdi
  int v12; // eax

  this->vMin.x = -0.60000002;
  this->vMin.y = -0.60000002;
  this->vMin.z = 0.1;
  this->vMin.w = -3.1415927;
  this->vMax.x = 0.60000002;
  this->vMax.y = 0.60000002;
  this->vMax.z = 0.80000001;
  this->vMax.w = 3.1415927;
  v6 = position->y;
  v7 = position->z;
  this->vPosition.x = position->x;
  this->vPosition.y = v6;
  this->vPosition.z = v7;
  v8 = UFG::qVector3::msAxisX.y;
  v9 = UFG::qVector3::msAxisX.z;
  v10 = this;
  v11 = object;
  this->vForward.x = UFG::qVector3::msAxisX.x;
  this->vForward.y = v8;
  this->vForward.z = v9;
  this->bFrontOnly = frontOnly;
  this->bUpload = upload;
  if ( object )
    v12 = object->mNode.mUID;
  else
    v12 = 0;
  this->nUID = v12;
  *(_WORD *)&this->bValid = 0;
  this->bClearLOS = 0;
  *(_QWORD *)&this->fTimer = 0i64;
  this->fDelay = delay;
  if ( object )
  {
    UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&this->mTargetTransform, object);
    UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Bind<UFG::SimObject>(&v10->mTargetSubject, v11);
  }
}

// File Line: 85
// RVA: 0x3C5F80
void __fastcall UFG::PhotoTarget::LineOfSightCallback(UFG::RayCastData *raycastData, UFG::SimComponent *simComponent, void *callbackUserData)
{
  int v3; // edx
  unsigned __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rcx

  if ( raycastData->hit )
  {
    v3 = *((_DWORD *)callbackUserData + 15);
    if ( v3
      && (v4 = raycastData->mHavokRigidBody->m_userData) != 0
      && (v5 = *(_QWORD *)(v4 + 24)) != 0
      && (v6 = *(_QWORD *)(v5 + 40)) != 0 )
    {
      *((_BYTE *)callbackUserData + 70) = v3 == *(_DWORD *)(v6 + 64);
    }
    else
    {
      *((_BYTE *)callbackUserData + 70) = 0;
    }
  }
  else
  {
    *((_BYTE *)callbackUserData + 70) = 1;
  }
}

// File Line: 118
// RVA: 0x3D6650
void __fastcall UFG::PhotoTarget::Update(UFG::PhotoTarget *this, float delta_seconds, UFG::Camera *camera, float tan_half_fov, UFG::LinearGraph<float> *focus_graph)
{
  bool v5; // zf
  float v6; // xmm4_4
  float v7; // xmm10_4
  UFG::Camera *v8; // rsi
  UFG::PhotoTarget *v9; // rdi
  float v10; // xmm5_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float *v14; // rbx
  float *v15; // rax
  float v16; // xmm9_4
  float v17; // xmm1_4
  float v18; // xmm8_4
  float v19; // xmm7_4
  float v20; // xmm9_4
  float *v21; // rax
  UFG::SimComponent *v22; // rcx
  float v23; // xmm4_4
  float v24; // xmm6_4
  __int64 v25; // rax
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  UFG::SimComponent *v29; // rbx
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float *v33; // rbx
  UFG::TransformNodeComponent *v34; // rcx
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  UFG::Camera *v39; // rcx
  char v40; // cl
  char v41; // al
  UFG::BasePhysicsSystemVtbl *v42; // rax
  UFG::qVector3 world_pos; // [rsp+28h] [rbp-41h]
  UFG::qVector3 v1; // [rsp+38h] [rbp-31h]
  UFG::qVector3 v2; // [rsp+48h] [rbp-21h]
  UFG::qVector2 viewport_scale; // [rsp+C8h] [rbp+5Fh]
  bool is_on_screen; // [rsp+D0h] [rbp+67h]

  v5 = this->mTargetSubject.m_pSimComponent == 0i64;
  v6 = this->vPosition.x;
  v7 = delta_seconds;
  v8 = camera;
  v9 = this;
  v10 = this->vPosition.y;
  v11 = this->vForward.x;
  v12 = this->vForward.z;
  world_pos.z = this->vPosition.z;
  v13 = this->vForward.y;
  world_pos.x = v6;
  v1.y = v13;
  world_pos.y = v10;
  v1.x = v11;
  v1.z = v12;
  if ( v5 )
  {
    if ( !this->mTargetTransform.m_pSimComponent )
      goto LABEL_6;
    v29 = this->mTargetTransform.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mTargetTransform.m_pSimComponent);
    v30 = *((float *)&v29[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v31 = *(float *)&v29[2].m_BoundComponentHandles.mNode.mNext;
    v32 = *(float *)&v29[2].m_BoundComponentHandles.mNode.mPrev;
    v33 = (float *)v9->mTargetTransform.m_pSimComponent;
    v34 = (UFG::TransformNodeComponent *)v9->mTargetTransform.m_pSimComponent;
    world_pos.x = v32;
    world_pos.y = v30;
    world_pos.z = v31;
    UFG::TransformNodeComponent::UpdateWorldTransform(v34);
    v26 = v33[33];
    v27 = v33[34];
    v28 = v33[32];
  }
  else
  {
    v14 = (float *)((__int64 (*)(void))this->mTargetSubject.m_pSimComponent->vfptr[18].__vecDelDtor)();
    v15 = (float *)((__int64 (*)(void))v9->mTargetSubject.m_pSimComponent->vfptr[23].__vecDelDtor)();
    v16 = v15[1];
    v17 = v15[2];
    v18 = (float)((float)((float)(*v15 * *v14) + (float)(v16 * v14[4])) + (float)(v17 * v14[8])) + v14[12];
    v19 = (float)((float)((float)(v16 * v14[5]) + (float)(*v15 * v14[1])) + (float)(v17 * v14[9])) + v14[13];
    v20 = (float)((float)((float)(v16 * v14[6]) + (float)(*v15 * v14[2])) + (float)(v17 * v14[10])) + v14[14];
    v21 = (float *)((__int64 (*)(void))v9->mTargetSubject.m_pSimComponent->vfptr[24].__vecDelDtor)();
    v22 = v9->mTargetSubject.m_pSimComponent;
    v23 = (float)((float)((float)(v21[1] * v14[5]) + (float)(*v21 * v14[1])) + (float)(v21[2] * v14[9])) + v14[13];
    v24 = (float)((float)((float)(v21[1] * v14[6]) + (float)(*v21 * v14[2])) + (float)(v21[2] * v14[10])) + v14[14];
    world_pos.x = (float)((float)((float)((float)((float)(*v21 * *v14) + (float)(v21[1] * v14[4]))
                                        + (float)(v21[2] * v14[8]))
                                + v14[12])
                        + v18)
                * 0.5;
    world_pos.z = (float)(v24 * 0.80000001) + (float)(v20 * 0.2);
    world_pos.y = (float)(v23 + v19) * 0.5;
    v25 = ((__int64 (*)(void))v22->vfptr[16].__vecDelDtor)();
    v26 = *(float *)(v25 + 4);
    v27 = *(float *)(v25 + 8);
    v28 = *(float *)v25;
  }
  v6 = world_pos.x;
  v10 = world_pos.y;
  v35 = world_pos.z;
  v9->vPosition.x = world_pos.x;
  v9->vPosition.y = v10;
  v9->vPosition.z = v35;
  v9->vForward.z = v27;
  v9->vForward.y = v26;
  v1.z = v27;
  v9->vForward.x = v28;
  v1.y = v26;
  v1.x = v28;
LABEL_6:
  v36 = 0.0;
  if ( v9->bFrontOnly )
  {
    v37 = v8->mTransformation.v3.x;
    v38 = v8->mTransformation.v3.y;
    v2.z = 0.0;
    v2.x = v37 - v6;
    v2.y = v38 - v10;
    v36 = UFG::qAngleBetween(&v1, &v2);
  }
  v9->bFramed = 0;
  if ( v36 < 1.5707964 )
  {
    is_on_screen = 0;
    viewport_scale.x = 1.0;
    viewport_scale.y = 1.0;
    v39 = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
    if ( v39 )
      v39 = (UFG::Camera *)((char *)v39 + 80);
    UFG::Camera::GetScreenCoord(v39, &v2, &world_pos, &viewport_scale, &is_on_screen);
    if ( is_on_screen )
    {
      v40 = v2.x <= 0.1 || v2.x >= 0.89999998 ? 0 : 1;
      v41 = v2.y <= 0.1 || v2.y >= 0.89999998 ? 0 : 1;
      if ( v40 && v41 )
        v9->bFramed = 1;
    }
  }
  if ( !v9->bFramed
    || (*(_QWORD *)&world_pos.z = v9,
        v42 = UFG::BasePhysicsSystem::mInstance->vfptr,
        *(_QWORD *)&world_pos.x = 0i64,
        !((unsigned __int8 (__fastcall *)(UFG::BasePhysicsSystem *, UFG::qVector4 *, UFG::qVector3 *, signed __int64, void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, void *), _QWORD, UFG::PhotoTarget *, _QWORD, _QWORD))v42->CastAsyncRay)(
           UFG::BasePhysicsSystem::mInstance,
           &v8->mTransformation.v3,
           &world_pos,
           13i64,
           UFG::PhotoTarget::LineOfSightCallback,
           0i64,
           v9,
           *(_QWORD *)&v1.x,
           *(_QWORD *)&v1.z)) )
  {
    v9->bClearLOS = 0;
  }
  v9->fTimer = v7 + v9->fTimer;
}

// File Line: 214
// RVA: 0x3BCCE0
void __fastcall UFG::PhotoManager::PhotoManager(UFG::PhotoManager *this)
{
  UFG::PhotoManager *v1; // rbx

  v1 = this;
  UFG::TSActor::TSActor((UFG::TSActor *)&this->vfptr, &UFG::PhotoManager::mClass->i_name, UFG::PhotoManager::mClass);
  v1->vfptr = (SSObjectBaseVtbl *)&UFG::PhotoManager::`vftable';
  UFG::PhotoManager::nGoodPhotos = 0;
  memset(UFG::PhotoManager::aPhotoTargets, 0, sizeof(UFG::PhotoManager::aPhotoTargets));
}

// File Line: 239
// RVA: 0x3C8430
void UFG::PhotoManager::Release(void)
{
  UFG::PhotoTarget **v0; // rbx
  UFG::PhotoTarget *v1; // rdi

  v0 = UFG::PhotoManager::aPhotoTargets;
  do
  {
    v1 = *v0;
    if ( *v0 )
    {
      UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&v1->mTargetTransform);
      UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->mTargetSubject);
      operator delete[](v1);
      *v0 = 0i64;
    }
    ++v0;
  }
  while ( (signed __int64)v0 < (signed __int64)&UFG::bCameraDebugDrawAvoidance );
}

// File Line: 253
// RVA: 0x3C1690
void UFG::PhotoManager::Create(void)
{
  UFG::PhotoManager *v0; // rax

  v0 = (UFG::PhotoManager *)AMemory::c_malloc_func(0xD8ui64, "PhotoManager");
  if ( v0 )
    UFG::PhotoManager::PhotoManager(v0);
  UFG::PhotoManager::mInstance = v0;
  ++v0->i_ref_count;
}

// File Line: 266
// RVA: 0x3BFB80
void UFG::PhotoManager::BindAtomics(void)
{
  UFG::PhotoManager::mClass = (SSActorClass *)SSBrain::get_class("PhotoManager");
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "photo_init",
    UFG::PhotoManager::MthdC_photo_init,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "photo_release",
    UFG::PhotoManager::MthdC_photo_init,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "add_photo_target_xform",
    UFG::PhotoManager::MthdC_add_photo_target_xform,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "add_photo_target_subject",
    UFG::PhotoManager::MthdC_add_photo_target_subject,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "add_photo_target_position",
    UFG::PhotoManager::MthdC_add_photo_target_position,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_valid",
    UFG::PhotoManager::MthdC_set_photo_target_valid,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_forward",
    UFG::PhotoManager::MthdC_set_photo_target_forward,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_fov_range",
    UFG::PhotoManager::MthdC_set_photo_target_fov_range,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_facing_range",
    UFG::PhotoManager::MthdC_set_photo_target_facing_range,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_screen_range_x",
    UFG::PhotoManager::MthdC_set_photo_target_screen_range_x,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "set_photo_target_screen_range_y",
    UFG::PhotoManager::MthdC_set_photo_target_screen_range_y,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::PhotoManager::mClass->vfptr,
    "get_photo_target_num_good_photos",
    UFG::PhotoManager::MthdC_get_photo_target_num_good_photos,
    1,
    0);
}

// File Line: 288
// RVA: 0x3D64E0
void __fastcall UFG::PhotoManager::Update(float delta_seconds)
{
  float v1; // xmm7_4
  UFG::BaseCameraComponent *v2; // rsi
  signed __int64 v3; // rsi
  float v4; // xmm3_4
  __int64 v5; // ST30_8
  int v6; // ST3C_4
  float v7; // xmm2_4
  float v8; // ST44_4
  float v9; // ST48_4
  float v10; // ST4C_4
  float v11; // ST40_4
  float v12; // xmm1_4
  signed int v13; // ebx
  UFG::PhotoTarget **v14; // rdi
  float v15; // xmm6_4
  signed int v16; // eax
  UFG::LinearGraph<float> focus_graph; // [rsp+50h] [rbp-48h]

  v1 = delta_seconds;
  v2 = UFG::Director::Get()->mCurrentCamera;
  if ( v2 )
  {
    v3 = (signed __int64)&v2->mCamera;
    if ( v3 )
    {
      v4 = 0.0;
      v5 = *(unsigned int *)(v3 + 40);
      v6 = *(_DWORD *)(v3 + 48);
      v7 = *(float *)(v3 + 32) * 0.5;
      v8 = *(float *)(v3 + 28) - v7;
      v9 = v7 + *(float *)(v3 + 28);
      v10 = (float)(v7 + *(float *)(v3 + 28)) + *(float *)(v3 + 44);
      v11 = v8 - *(float *)(v3 + 36);
      v12 = *(float *)(v3 + 192);
      if ( v12 != 0.0 )
        v4 = atan2f(1.0, v12) * 2.0;
      v13 = 0;
      v14 = UFG::PhotoManager::aPhotoTargets;
      v15 = tanf(v4 * 0.5);
      do
      {
        if ( v13 <= 0 )
        {
          v16 = 0;
        }
        else
        {
          v16 = v13;
          if ( v13 >= 15 )
            v16 = 15;
        }
        if ( v13 == v16 )
        {
          if ( *v14 )
            UFG::PhotoTarget::Update(*v14, v1, (UFG::Camera *)v3, v15, &focus_graph);
        }
        ++v13;
        ++v14;
      }
      while ( v13 < 16 );
    }
  }
}

// File Line: 332
// RVA: 0x3BF2D0
char __fastcall UFG::PhotoManager::AnyValidTargetsFramed()
{
  signed int v0; // eax
  UFG::PhotoTarget **v1; // rdx
  signed int v2; // ecx
  UFG::PhotoTarget *v3; // rcx

  v0 = 0;
  v1 = UFG::PhotoManager::aPhotoTargets;
  while ( 1 )
  {
    if ( v0 <= 0 )
    {
      v2 = 0;
    }
    else
    {
      v2 = v0;
      if ( v0 >= 15 )
        v2 = 15;
    }
    if ( v0 == v2 )
    {
      v3 = *v1;
      if ( *v1 )
      {
        if ( v3->bValid && v3->bFramed && v3->bClearLOS && v3->fDelay < v3->fTimer )
          break;
      }
    }
    ++v0;
    ++v1;
    if ( v0 >= 16 )
      return 0;
  }
  return 1;
}

// File Line: 343
// RVA: 0x3C3F50
UFG::PhotoTarget *__fastcall UFG::PhotoManager::GetValidOnScreenTarget()
{
  signed int v0; // ecx
  UFG::PhotoTarget **v1; // rdx
  signed int v2; // eax
  UFG::PhotoTarget *result; // rax

  v0 = 0;
  v1 = UFG::PhotoManager::aPhotoTargets;
  while ( 1 )
  {
    if ( v0 <= 0 )
    {
      v2 = 0;
    }
    else
    {
      v2 = v0;
      if ( v0 >= 15 )
        v2 = 15;
    }
    if ( v0 == v2 )
    {
      result = *v1;
      if ( *v1 )
      {
        if ( result->bValid && result->bFramed && result->bClearLOS && result->fDelay < result->fTimer )
          break;
      }
    }
    ++v0;
    ++v1;
    if ( v0 >= 16 )
      return 0i64;
  }
  return result;
}

// File Line: 357
// RVA: 0x3C5580
char __fastcall UFG::PhotoManager::HasPhotoTarget()
{
  signed int v0; // eax
  UFG::PhotoTarget **v1; // rdx
  signed int v2; // ecx

  v0 = 0;
  v1 = UFG::PhotoManager::aPhotoTargets;
  while ( 1 )
  {
    if ( v0 <= 0 )
    {
      v2 = 0;
    }
    else
    {
      v2 = v0;
      if ( v0 >= 15 )
        v2 = 15;
    }
    if ( v0 == v2 && *v1 )
      break;
    ++v0;
    ++v1;
    if ( v0 >= 16 )
      return 0;
  }
  return 1;
}

// File Line: 370
// RVA: 0x3C83E0
void UFG::PhotoManager::RecordPhoto(void)
{
  char v0; // r8
  UFG::PhotoTarget **v1; // rdx
  signed int v2; // eax
  signed int v3; // ecx

  v0 = 0;
  v1 = UFG::PhotoManager::aPhotoTargets;
  v2 = 0;
  do
  {
    if ( v2 <= 0 )
    {
      v3 = 0;
    }
    else
    {
      v3 = v2;
      if ( v2 >= 15 )
        v3 = 15;
    }
    if ( v2 == v3 && *v1 )
    {
      ++(*v1)->nGoodPhotos;
      v0 |= 1u;
    }
    ++v2;
    ++v1;
  }
  while ( v2 < 16 );
  if ( v0 )
    ++UFG::PhotoManager::nGoodPhotos;
}

// File Line: 383
// RVA: 0x3C70F0
void __fastcall UFG::PhotoManager::MthdC_photo_init(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhotoManager::Release();
}

// File Line: 406
// RVA: 0x3C6E60
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_subject(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **v6; // rdx
  SSInstance *v7; // rbp
  bool v8; // r14
  bool v9; // r15
  float delay; // xmm6_4
  UFG::allocator::free_link *v11; // rax
  UFG::PhotoTarget *v12; // rax

  v2 = ppResult;
  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    ++v5;
    if ( (signed __int64)v5 >= (signed __int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    v6 = pScope->i_data.i_array_p;
    v7 = (*v6)->i_data_p;
    v8 = v6[1]->i_data_p->i_user_data > 0;
    v9 = v6[2]->i_data_p->i_user_data > 0;
    delay = *(float *)&v6[3]->i_data_p->i_user_data;
    v11 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v11 )
    {
      UFG::PhotoTarget::PhotoTarget((UFG::PhotoTarget *)v11, *(UFG::SimObject **)&v7[4].i_ref_count, v8, v9, delay);
      v3 = v12;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 422
// RVA: 0x3C6D70
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **v6; // rdx
  UFG::qVector3 *v7; // rbp
  bool v8; // r14
  float v9; // xmm6_4
  UFG::allocator::free_link *v10; // rax
  UFG::PhotoTarget *v11; // rax

  v2 = ppResult;
  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    ++v5;
    if ( (signed __int64)v5 >= (signed __int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    v6 = pScope->i_data.i_array_p;
    v7 = (UFG::qVector3 *)(*v6)->i_data_p->i_user_data;
    v8 = v6[1]->i_data_p->i_user_data > 0;
    v9 = *(float *)&v6[2]->i_data_p->i_user_data;
    v10 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v10 )
    {
      UFG::PhotoTarget::PhotoTarget((UFG::PhotoTarget *)v10, v7, v8, v9);
      v3 = v11;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 437
// RVA: 0x3C6F70
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **v6; // rdx
  UFG::TransformNodeComponent *v7; // rbp
  bool v8; // r14
  bool v9; // r15
  float delay; // xmm6_4
  UFG::allocator::free_link *v11; // rax
  UFG::PhotoTarget *v12; // rax

  v2 = ppResult;
  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    ++v5;
    if ( (signed __int64)v5 >= (signed __int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    v6 = pScope->i_data.i_array_p;
    v7 = (UFG::TransformNodeComponent *)(*v6)->i_data_p->i_user_data;
    v8 = v6[1]->i_data_p->i_user_data > 0;
    v9 = v6[2]->i_data_p->i_user_data > 0;
    delay = *(float *)&v6[3]->i_data_p->i_user_data;
    v11 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v11 )
    {
      UFG::PhotoTarget::PhotoTarget((UFG::PhotoTarget *)v11, v7, v8, v9, delay);
      v3 = v12;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 453
// RVA: 0x3C72F0
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_valid(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
      v5->bValid = v2[1]->i_data_p->i_user_data != 0;
  }
}

// File Line: 461
// RVA: 0x3C7170
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_forward(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx
  float *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
    {
      v6 = (float *)v2[1]->i_data_p->i_user_data;
      v7 = v6[1];
      v8 = v6[2];
      v5->vForward.x = *v6;
      v5->vForward.y = v7;
      v5->vForward.z = v8;
    }
  }
}

// File Line: 473
// RVA: 0x3C71D0
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_fov_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
    {
      v6 = *(float *)&v2[1]->i_data_p->i_user_data;
      v5->vMax.z = *(float *)&v2[2]->i_data_p->i_user_data;
      v5->vMin.z = v6;
    }
  }
}

// File Line: 486
// RVA: 0x3C7100
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_facing_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // xmm1_4

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
    {
      v6 = (float)(*(float *)&v2[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
      v5->vMax.w = v6;
      LODWORD(v5->vMin.w) = LODWORD(v6) ^ _xmm[0];
    }
  }
}

// File Line: 498
// RVA: 0x3C7230
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_screen_range_x(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
    {
      v6 = *(float *)&v2[1]->i_data_p->i_user_data;
      v5->vMax.x = *(float *)&v2[2]->i_data_p->i_user_data;
      v5->vMin.x = v6;
    }
  }
}

// File Line: 511
// RVA: 0x3C7290
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_screen_range_y(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  __int64 v3; // rax
  signed int v4; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = SLODWORD((*v2)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
    {
      v6 = *(float *)&v2[1]->i_data_p->i_user_data;
      v5->vMax.y = *(float *)&v2[2]->i_data_p->i_user_data;
      v5->vMin.y = v6;
    }
  }
}

// File Line: 525
// RVA: 0x3C7080
void __fastcall UFG::PhotoManager::MthdC_get_photo_target_num_good_photos(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // er8
  __int64 v3; // rcx
  signed int v4; // eax
  UFG::PhotoTarget *v5; // rcx

  v2 = 0;
  v3 = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (signed int)v3 <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = v3;
    if ( (signed int)v3 >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)v3 == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[v3];
    if ( v5 )
      v2 = v5->nGoodPhotos;
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v2);
}

