// File Line: 40
// RVA: 0x3C5A20
void __fastcall UFG::PhotoTarget::Init(
        UFG::PhotoTarget *this,
        UFG::SimObject *object,
        UFG::qVector3 *position,
        bool frontOnly,
        bool upload,
        float delay)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  int mUID; // eax

  this->vMin.x = -0.60000002;
  this->vMin.y = -0.60000002;
  this->vMin.z = 0.1;
  this->vMin.w = -3.1415927;
  this->vMax.x = 0.60000002;
  this->vMax.y = 0.60000002;
  this->vMax.z = 0.80000001;
  this->vMax.w = 3.1415927;
  y = position->y;
  z = position->z;
  this->vPosition.x = position->x;
  this->vPosition.y = y;
  this->vPosition.z = z;
  v8 = UFG::qVector3::msAxisX.y;
  v9 = UFG::qVector3::msAxisX.z;
  this->vForward.x = UFG::qVector3::msAxisX.x;
  this->vForward.y = v8;
  this->vForward.z = v9;
  this->bFrontOnly = frontOnly;
  this->bUpload = upload;
  if ( object )
    mUID = object->mNode.mUID;
  else
    mUID = 0;
  this->nUID = mUID;
  *(_WORD *)&this->bValid = 0;
  this->bClearLOS = 0;
  *(_QWORD *)&this->fTimer = 0i64;
  this->fDelay = delay;
  if ( object )
  {
    UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&this->mTargetTransform, object);
    UFG::RebindingComponentHandle<UFG::CameraSubject,0>::Bind<UFG::SimObject>(&this->mTargetSubject, object);
  }
}

// File Line: 85
// RVA: 0x3C5F80
void __fastcall UFG::PhotoTarget::LineOfSightCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *simComponent,
        _DWORD *callbackUserData)
{
  int v3; // edx
  unsigned __int64 m_userData; // rax
  __int64 v5; // rax
  __int64 v6; // rcx

  if ( raycastData->hit )
  {
    v3 = callbackUserData[15];
    *((_BYTE *)callbackUserData + 70) = v3
                                     && (m_userData = raycastData->mHavokRigidBody->m_userData) != 0
                                     && (v5 = *(_QWORD *)(m_userData + 24)) != 0
                                     && (v6 = *(_QWORD *)(v5 + 40)) != 0
                                     && v3 == *(_DWORD *)(v6 + 64);
  }
  else
  {
    *((_BYTE *)callbackUserData + 70) = 1;
  }
}

// File Line: 118
// RVA: 0x3D6650
void __fastcall UFG::PhotoTarget::Update(
        UFG::PhotoTarget *this,
        float delta_seconds,
        UFG::Camera *camera,
        float tan_half_fov,
        UFG::LinearGraph<float> *focus_graph)
{
  bool v5; // zf
  float x; // xmm4_4
  float y; // xmm5_4
  float v11; // xmm2_4
  float z; // xmm1_4
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
  UFG::SimComponent *m_pSimComponent; // rbx
  unsigned int mPrev_high; // xmm1_4
  int mNext; // xmm2_4
  unsigned int mPrev; // xmm0_4
  UFG::SimComponent *v33; // rbx
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  UFG::Camera *mCurrentCamera; // rcx
  bool v39; // cl
  bool v40; // al
  UFG::BasePhysicsSystemVtbl *vfptr; // rax
  unsigned __int64 world_pos; // [rsp+28h] [rbp-41h] BYREF
  UFG::PhotoTarget *world_pos_8; // [rsp+30h] [rbp-39h]
  UFG::qVector3 v1; // [rsp+38h] [rbp-31h] BYREF
  UFG::qVector3 v2; // [rsp+48h] [rbp-21h] BYREF
  UFG::qVector2 viewport_scale; // [rsp+C8h] [rbp+5Fh] BYREF
  bool is_on_screen; // [rsp+D0h] [rbp+67h] BYREF

  v5 = this->mTargetSubject.m_pSimComponent == 0i64;
  x = this->vPosition.x;
  y = this->vPosition.y;
  v11 = this->vForward.x;
  z = this->vForward.z;
  *(float *)&world_pos_8 = this->vPosition.z;
  v13 = this->vForward.y;
  world_pos = __PAIR64__(LODWORD(y), LODWORD(x));
  v1.y = v13;
  v1.x = v11;
  v1.z = z;
  if ( v5 )
  {
    if ( !this->mTargetTransform.m_pSimComponent )
      goto LABEL_6;
    m_pSimComponent = this->mTargetTransform.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    mPrev_high = HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
    mNext = (int)m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    mPrev = (unsigned int)m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v33 = this->mTargetTransform.m_pSimComponent;
    world_pos = __PAIR64__(mPrev_high, mPrev);
    LODWORD(world_pos_8) = mNext;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v33);
    v26 = *((float *)&v33[2].vfptr + 1);
    v27 = *(float *)&v33[2].m_SafePointerList.mNode.mPrev;
    v28 = *(float *)&v33[2].vfptr;
  }
  else
  {
    v14 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTargetSubject.m_pSimComponent->vfptr[18].__vecDelDtor)(this->mTargetSubject.m_pSimComponent);
    v15 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTargetSubject.m_pSimComponent->vfptr[23].__vecDelDtor)(this->mTargetSubject.m_pSimComponent);
    v16 = v15[1];
    v17 = v15[2];
    v18 = (float)((float)((float)(*v15 * *v14) + (float)(v16 * v14[4])) + (float)(v17 * v14[8])) + v14[12];
    v19 = (float)((float)((float)(v16 * v14[5]) + (float)(*v15 * v14[1])) + (float)(v17 * v14[9])) + v14[13];
    v20 = (float)((float)((float)(v16 * v14[6]) + (float)(*v15 * v14[2])) + (float)(v17 * v14[10])) + v14[14];
    v21 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))this->mTargetSubject.m_pSimComponent->vfptr[24].__vecDelDtor)(this->mTargetSubject.m_pSimComponent);
    v22 = this->mTargetSubject.m_pSimComponent;
    v23 = (float)((float)((float)(v21[1] * v14[5]) + (float)(*v21 * v14[1])) + (float)(v21[2] * v14[9])) + v14[13];
    v24 = (float)((float)((float)(v21[1] * v14[6]) + (float)(*v21 * v14[2])) + (float)(v21[2] * v14[10])) + v14[14];
    *(float *)&world_pos = (float)((float)((float)((float)((float)(*v21 * *v14) + (float)(v21[1] * v14[4]))
                                                 + (float)(v21[2] * v14[8]))
                                         + v14[12])
                                 + v18)
                         * 0.5;
    *(float *)&world_pos_8 = (float)(v24 * 0.80000001) + (float)(v20 * 0.2);
    *((float *)&world_pos + 1) = (float)(v23 + v19) * 0.5;
    v25 = ((__int64 (__fastcall *)(UFG::SimComponent *))v22->vfptr[16].__vecDelDtor)(v22);
    v26 = *(float *)(v25 + 4);
    v27 = *(float *)(v25 + 8);
    v28 = *(float *)v25;
  }
  LODWORD(x) = world_pos;
  y = *((float *)&world_pos + 1);
  v34 = *(float *)&world_pos_8;
  LODWORD(this->vPosition.x) = world_pos;
  this->vPosition.y = y;
  this->vPosition.z = v34;
  this->vForward.z = v27;
  this->vForward.y = v26;
  v1.z = v27;
  this->vForward.x = v28;
  v1.y = v26;
  v1.x = v28;
LABEL_6:
  v35 = 0.0;
  if ( this->bFrontOnly )
  {
    v36 = camera->mTransformation.v3.x;
    v37 = camera->mTransformation.v3.y;
    v2.z = 0.0;
    v2.x = v36 - x;
    v2.y = v37 - y;
    v35 = UFG::qAngleBetween(&v1, &v2);
  }
  this->bFramed = 0;
  if ( v35 < 1.5707964 )
  {
    is_on_screen = 0;
    viewport_scale.x = 1.0;
    viewport_scale.y = 1.0;
    mCurrentCamera = (UFG::Camera *)UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::Camera *)((char *)mCurrentCamera + 80);
    UFG::Camera::GetScreenCoord(mCurrentCamera, &v2, (UFG::qVector3 *)&world_pos, &viewport_scale, &is_on_screen);
    if ( is_on_screen )
    {
      v39 = v2.x > 0.1 && v2.x < 0.89999998;
      v40 = v2.y > 0.1 && v2.y < 0.89999998;
      if ( v39 && v40 )
        this->bFramed = 1;
    }
  }
  if ( !this->bFramed
    || (world_pos_8 = this,
        vfptr = UFG::BasePhysicsSystem::mInstance->vfptr,
        world_pos = 0i64,
        !((unsigned __int8 (__fastcall *)(UFG::BasePhysicsSystem *, UFG::qVector4 *, unsigned __int64 *, __int64, void (__fastcall *)(UFG::RayCastData *, UFG::SimComponent *, _DWORD *)))vfptr->CastAsyncRay)(
           UFG::BasePhysicsSystem::mInstance,
           &camera->mTransformation.v3,
           &world_pos,
           13i64,
           UFG::PhotoTarget::LineOfSightCallback)) )
  {
    this->bClearLOS = 0;
  }
  this->fTimer = delta_seconds + this->fTimer;
}

// File Line: 214
// RVA: 0x3BCCE0
void __fastcall UFG::PhotoManager::PhotoManager(UFG::PhotoManager *this)
{
  UFG::TSActor::TSActor(this, &UFG::PhotoManager::mClass->i_name, UFG::PhotoManager::mClass);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::PhotoManager::`vftable;
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
  while ( (__int64)v0 < (__int64)&UFG::bCameraDebugDrawAvoidance );
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
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  UFG::PhotoManager::mClass = (SSActorClass *)SSBrain::get_class("PhotoManager");
  SSClass::register_method_func(UFG::PhotoManager::mClass, "photo_init", UFG::PhotoManager::MthdC_photo_init, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "photo_release",
    UFG::PhotoManager::MthdC_photo_init,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "add_photo_target_xform",
    UFG::PhotoManager::MthdC_add_photo_target_xform,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "add_photo_target_subject",
    UFG::PhotoManager::MthdC_add_photo_target_subject,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "add_photo_target_position",
    UFG::PhotoManager::MthdC_add_photo_target_position,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_valid",
    UFG::PhotoManager::MthdC_set_photo_target_valid,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_forward",
    UFG::PhotoManager::MthdC_set_photo_target_forward,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_fov_range",
    UFG::PhotoManager::MthdC_set_photo_target_fov_range,
    1,
    rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_facing_range",
    UFG::PhotoManager::MthdC_set_photo_target_facing_range,
    1,
    rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_screen_range_x",
    UFG::PhotoManager::MthdC_set_photo_target_screen_range_x,
    1,
    rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "set_photo_target_screen_range_y",
    UFG::PhotoManager::MthdC_set_photo_target_screen_range_y,
    1,
    rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(
    UFG::PhotoManager::mClass,
    "get_photo_target_num_good_photos",
    UFG::PhotoManager::MthdC_get_photo_target_num_good_photos,
    1,
    rebindk);
}

// File Line: 288
// RVA: 0x3D64E0
void __fastcall UFG::PhotoManager::Update(float delta_seconds)
{
  UFG::BaseCameraComponent *mCurrentCamera; // rsi
  UFG::Camera *p_mCamera; // rsi
  float v4; // xmm3_4
  float x; // xmm1_4
  int v6; // ebx
  UFG::PhotoTarget **v7; // rdi
  float v8; // xmm6_4
  int v9; // eax
  UFG::LinearGraph<float> focus_graph; // [rsp+50h] [rbp-48h] BYREF

  mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
  if ( mCurrentCamera )
  {
    p_mCamera = &mCurrentCamera->mCamera;
    if ( p_mCamera )
    {
      v4 = 0.0;
      x = p_mCamera->mProjection.v0.x;
      if ( x != 0.0 )
        v4 = atan2f(1.0, x) * 2.0;
      v6 = 0;
      v7 = UFG::PhotoManager::aPhotoTargets;
      v8 = tanf(v4 * 0.5);
      do
      {
        if ( v6 <= 0 )
        {
          v9 = 0;
        }
        else
        {
          v9 = v6;
          if ( v6 >= 15 )
            v9 = 15;
        }
        if ( v6 == v9 )
        {
          if ( *v7 )
            UFG::PhotoTarget::Update(*v7, delta_seconds, p_mCamera, v8, &focus_graph);
        }
        ++v6;
        ++v7;
      }
      while ( v6 < 16 );
    }
  }
}

// File Line: 332
// RVA: 0x3BF2D0
char __fastcall UFG::PhotoManager::AnyValidTargetsFramed()
{
  int v0; // eax
  UFG::PhotoTarget **i; // rdx
  int v2; // ecx
  UFG::PhotoTarget *v3; // rcx

  v0 = 0;
  for ( i = UFG::PhotoManager::aPhotoTargets; ; ++i )
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
      v3 = *i;
      if ( *i )
      {
        if ( v3->bValid && v3->bFramed && v3->bClearLOS && v3->fDelay < v3->fTimer )
          break;
      }
    }
    if ( ++v0 >= 16 )
      return 0;
  }
  return 1;
}

// File Line: 343
// RVA: 0x3C3F50
UFG::PhotoTarget *__fastcall UFG::PhotoManager::GetValidOnScreenTarget()
{
  int v0; // ecx
  UFG::PhotoTarget **i; // rdx
  int v2; // eax
  UFG::PhotoTarget *result; // rax

  v0 = 0;
  for ( i = UFG::PhotoManager::aPhotoTargets; ; ++i )
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
      result = *i;
      if ( *i )
      {
        if ( result->bValid && result->bFramed && result->bClearLOS && result->fDelay < result->fTimer )
          break;
      }
    }
    if ( ++v0 >= 16 )
      return 0i64;
  }
  return result;
}

// File Line: 357
// RVA: 0x3C5580
char __fastcall UFG::PhotoManager::HasPhotoTarget()
{
  int v0; // eax
  UFG::PhotoTarget **i; // rdx
  int v2; // ecx

  v0 = 0;
  for ( i = UFG::PhotoManager::aPhotoTargets; ; ++i )
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
    if ( v0 == v2 && *i )
      break;
    if ( ++v0 >= 16 )
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
  int i; // eax
  int v3; // ecx

  v0 = 0;
  v1 = UFG::PhotoManager::aPhotoTargets;
  for ( i = 0; i < 16; ++i )
  {
    if ( i <= 0 )
    {
      v3 = 0;
    }
    else
    {
      v3 = i;
      if ( i >= 15 )
        v3 = 15;
    }
    if ( i == v3 && *v1 )
    {
      ++(*v1)->nGoodPhotos;
      v0 |= 1u;
    }
    ++v1;
  }
  if ( v0 )
    ++UFG::PhotoManager::nGoodPhotos;
}

// File Line: 383
// RVA: 0x3C70F0
// attributes: thunk
void __fastcall UFG::PhotoManager::MthdC_photo_init(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhotoManager::Release();
}

// File Line: 406
// RVA: 0x3C6E60
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_subject(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbp
  bool v8; // r14
  bool v9; // r15
  float delay; // xmm6_4
  UFG::allocator::free_link *v11; // rax
  UFG::PhotoTarget *v12; // rax

  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    if ( (__int64)++v5 >= (__int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v8 = i_array_p[1]->i_data_p->i_user_data != 0;
    v9 = i_array_p[2]->i_data_p->i_user_data != 0;
    delay = *(float *)&i_array_p[3]->i_data_p->i_user_data;
    v11 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v11 )
    {
      UFG::PhotoTarget::PhotoTarget(
        (UFG::PhotoTarget *)v11,
        *(UFG::SimObject **)&i_data_p[4].i_ref_count,
        v8,
        v9,
        delay);
      v3 = v12;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 422
// RVA: 0x3C6D70
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **i_array_p; // rdx
  UFG::qVector3 *i_user_data; // rbp
  bool v8; // r14
  float v9; // xmm6_4
  UFG::allocator::free_link *v10; // rax
  UFG::PhotoTarget *v11; // rax

  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    if ( (__int64)++v5 >= (__int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (UFG::qVector3 *)(*i_array_p)->i_data_p->i_user_data;
    v8 = i_array_p[1]->i_data_p->i_user_data != 0;
    v9 = *(float *)&i_array_p[2]->i_data_p->i_user_data;
    v10 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v10 )
    {
      UFG::PhotoTarget::PhotoTarget((UFG::PhotoTarget *)v10, i_user_data, v8, v9);
      v3 = v11;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 437
// RVA: 0x3C6F70
void __fastcall UFG::PhotoManager::MthdC_add_photo_target_xform(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::PhotoTarget *v3; // rdi
  unsigned int v4; // ebx
  UFG::PhotoTarget **v5; // rax
  SSData **i_array_p; // rdx
  UFG::TransformNodeComponent *i_user_data; // rbp
  bool v8; // r14
  bool v9; // r15
  float delay; // xmm6_4
  UFG::allocator::free_link *v11; // rax
  UFG::PhotoTarget *v12; // rax

  v3 = 0i64;
  v4 = 0;
  v5 = UFG::PhotoManager::aPhotoTargets;
  while ( *v5 )
  {
    ++v4;
    if ( (__int64)++v5 >= (__int64)&UFG::bCameraDebugDrawAvoidance )
    {
      v4 = -1;
      goto LABEL_9;
    }
  }
  if ( v4 != -1 )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (UFG::TransformNodeComponent *)(*i_array_p)->i_data_p->i_user_data;
    v8 = i_array_p[1]->i_data_p->i_user_data != 0;
    v9 = i_array_p[2]->i_data_p->i_user_data != 0;
    delay = *(float *)&i_array_p[3]->i_data_p->i_user_data;
    v11 = UFG::qMalloc(0xB0ui64, "PhotoTarget", 0i64);
    if ( v11 )
    {
      UFG::PhotoTarget::PhotoTarget((UFG::PhotoTarget *)v11, i_user_data, v8, v9, delay);
      v3 = v12;
    }
    UFG::PhotoManager::aPhotoTargets[v4] = v3;
  }
LABEL_9:
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v4);
}

// File Line: 453
// RVA: 0x3C72F0
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_valid(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
      v5->bValid = i_array_p[1]->i_data_p->i_user_data != 0;
  }
}

// File Line: 461
// RVA: 0x3C7170
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_forward(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx
  float *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
    {
      v6 = (float *)i_array_p[1]->i_data_p->i_user_data;
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
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
    {
      v6 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      v5->vMax.z = *(float *)&i_array_p[2]->i_data_p->i_user_data;
      v5->vMin.z = v6;
    }
  }
}

// File Line: 486
// RVA: 0x3C7100
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_facing_range(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // xmm1_4

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
    {
      v6 = (float)(*(float *)&i_array_p[1]->i_data_p->i_user_data * 3.1415927) * 0.0055555557;
      v5->vMax.w = v6;
      LODWORD(v5->vMin.w) = LODWORD(v6) ^ _xmm[0];
    }
  }
}

// File Line: 498
// RVA: 0x3C7230
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_screen_range_x(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
    {
      v6 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      v5->vMax.x = *(float *)&i_array_p[2]->i_data_p->i_user_data;
      v5->vMin.x = v6;
    }
  }
}

// File Line: 511
// RVA: 0x3C7290
void __fastcall UFG::PhotoManager::MthdC_set_photo_target_screen_range_y(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  __int64 i_user_data_low; // rax
  int i_user_data; // ecx
  UFG::PhotoTarget *v5; // rdx
  float v6; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data_low = SLODWORD((*i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    i_user_data = 0;
  }
  else
  {
    i_user_data = (*i_array_p)->i_data_p->i_user_data;
    if ( (int)i_user_data_low >= 15 )
      i_user_data = 15;
  }
  if ( (_DWORD)i_user_data_low == i_user_data )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
    {
      v6 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
      v5->vMax.y = *(float *)&i_array_p[2]->i_data_p->i_user_data;
      v5->vMin.y = v6;
    }
  }
}

// File Line: 525
// RVA: 0x3C7080
void __fastcall UFG::PhotoManager::MthdC_get_photo_target_num_good_photos(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  unsigned int nGoodPhotos; // r8d
  __int64 i_user_data_low; // rcx
  int v4; // eax
  UFG::PhotoTarget *v5; // rcx

  nGoodPhotos = 0;
  i_user_data_low = SLODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( (int)i_user_data_low <= 0 )
  {
    v4 = 0;
  }
  else
  {
    v4 = i_user_data_low;
    if ( (int)i_user_data_low >= 15 )
      v4 = 15;
  }
  if ( (_DWORD)i_user_data_low == v4 )
  {
    v5 = UFG::PhotoManager::aPhotoTargets[i_user_data_low];
    if ( v5 )
      nGoodPhotos = v5->nGoodPhotos;
  }
  *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, nGoodPhotos);
}

