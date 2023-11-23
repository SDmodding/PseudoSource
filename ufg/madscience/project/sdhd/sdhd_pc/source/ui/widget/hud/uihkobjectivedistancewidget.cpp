// File Line: 59
// RVA: 0x5C4580
void __fastcall UFG::UIHKObjectiveDistanceWidget::UIHKObjectiveDistanceWidget(UFG::UIHKObjectiveDistanceWidget *this)
{
  *(_DWORD *)&this->mVisibleSynced = 0x1000000;
  *(_WORD *)&this->mIsOnScreen = 0;
  this->mDistance = 0.0;
  UFG::qString::qString(&this->mCaption);
  this->mArrowDirection = ARROW_DOWN;
  this->mTargetSimObject_AcquireCounter = 2.0;
  this->mOldDistance = -1.0;
  this->mOldAlpha = -1.0;
  this->mCoronaType = 0;
  this->mColorChanged = 0;
  this->mAssociatedIcon.mUID = -1;
  this->mAssociatedIconIndex = TPCharacterPlayer;
  this->mObjective = 0i64;
  this->mTargetSimObj.mPrev = &this->mTargetSimObj;
  this->mTargetSimObj.mNext = &this->mTargetSimObj;
  this->mTargetSimObj.m_pPointer = 0i64;
  this->mSimObjectID.mUID = -1;
  this->mColor = UFG::qColour::White;
}

// File Line: 65
// RVA: 0x615440
void __fastcall UFG::UIHKObjectiveDistanceWidget::Update(
        UFG::UIHKObjectiveDistanceWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // r15
  float v6; // xmm0_4
  bool v7; // si
  float v8; // xmm6_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *m_pPointer; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float v13; // xmm1_4
  __m128 pNext_low; // xmm7
  __m128 v15; // xmm2
  float v16; // xmm3_4
  float v17; // xmm6_4
  UFG::BaseCameraComponent *CurrentBaseCamera; // rax
  double v19; // xmm0_8
  float v20; // xmm8_4
  float mWidth; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  UFG::BaseCameraComponent *mCurrentCamera; // rcx
  UFG::Camera *p_mCamera; // rcx
  float v27; // xmm7_4
  UFG::BaseCameraComponent *v28; // rcx
  UFG::Camera *v29; // rcx
  float FarPlane; // xmm0_4
  UFG::BaseCameraComponent *v31; // rcx
  UFG::Camera *v32; // rcx
  UFG::qMatrix44 *WorldView; // rax
  Illusion::Target *BackBufferTarget; // rax
  float mHeight; // xmm1_4
  UFG::qVector3 *v36; // rax
  float x; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  char v40; // al
  bool mVisible; // al
  float v42; // xmm15_4
  float v43; // xmm13_4
  float v44; // xmm10_4
  float v45; // xmm11_4
  UFG::BaseCameraComponent *v46; // rax
  _DWORD *p_mFOVOffset; // rax
  int v48; // xmm1_4
  float v49; // xmm4_4
  float v50; // xmm0_4
  float v51; // xmm6_4
  float v52; // xmm0_4
  float v53; // xmm6_4
  float v54; // xmm0_4
  float v55; // xmm0_4
  float v56; // xmm8_4
  bool v57; // r14
  int v58; // edi
  float v59; // xmm7_4
  float v60; // xmm9_4
  int v61; // esi
  float v62; // xmm0_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm8_4
  UFG::UIHKObjectiveDistanceWidget::eArrowDirection v66; // r8d
  float v67; // xmm15_4
  float v68; // xmm8_4
  float mDistance; // xmm0_4
  int far_plane; // [rsp+20h] [rbp-B8h]
  int far_planea; // [rsp+20h] [rbp-B8h]
  float v72; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 world_pos; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qVector3 a; // [rsp+48h] [rbp-90h] BYREF
  void *v75; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::Value pval; // [rsp+60h] [rbp-78h] BYREF
  float v77; // [rsp+90h] [rbp-48h]
  UFG::qVector2 viewport_scale; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::GFx::Value value; // [rsp+A0h] [rbp-38h] BYREF
  UFG::qVector3 v1; // [rsp+D0h] [rbp-8h] BYREF
  UFG::qVector3 dir; // [rsp+E0h] [rbp+8h] BYREF
  char v82[16]; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v83; // [rsp+108h] [rbp+30h]
  int v84; // [rsp+110h] [rbp+38h]
  __int64 v85; // [rsp+118h] [rbp+40h]
  __int64 v86[26]; // [rsp+128h] [rbp+50h] BYREF
  __int16 v87; // [rsp+1FCh] [rbp+124h]
  bool v88; // [rsp+1FEh] [rbp+126h]
  __int64 v89; // [rsp+208h] [rbp+130h]
  UFG::qMatrix44 dest; // [rsp+218h] [rbp+140h] BYREF
  UFG::qMatrix44 result; // [rsp+258h] [rbp+180h] BYREF
  UFG::SimObject *simObj; // [rsp+370h] [rbp+298h] BYREF
  float vars0; // [rsp+380h] [rbp+2A8h]

  v89 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "mc_ObjectiveDist");
    memset(&v86[12], 0, 112);
    LODWORD(v86[12]) = 1065353216;
    HIDWORD(v86[14]) = 1065353216;
    LODWORD(v86[17]) = 1065353216;
    LODWORD(v86[18]) = 1065353216;
    HIDWORD(v86[20]) = 1065353216;
    LODWORD(v86[23]) = 1065353216;
    HIDWORD(v86[25]) = 1065353216;
    v87 = 0;
    if ( (pval.Type & 0x8F) != 10 )
      goto LABEL_122;
    pval.pObjectInterface->vfptr->GetDisplayInfo(pval.pObjectInterface, v75, (Scaleform::GFx::Value::DisplayInfo *)v86);
    if ( !this->mEnabled )
    {
      if ( !this->mChanged )
        goto LABEL_122;
      this->mChanged = 0;
      v87 |= 0x40u;
      v88 = 0;
LABEL_6:
      pval.pObjectInterface->vfptr->SetDisplayInfo(
        pval.pObjectInterface,
        v75,
        (Scaleform::GFx::Value::DisplayInfo *)v86);
LABEL_122:
      if ( (pval.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, void *))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          v75);
      return;
    }
    if ( !this->mTargetSimObj.m_pPointer && this->mSimObjectID.mUID != UFG::gNullQSymbol.mUID )
    {
      v6 = this->mTargetSimObject_AcquireCounter - elapsed;
      this->mTargetSimObject_AcquireCounter = v6;
      if ( v6 <= 0.0 )
      {
        this->mTargetSimObject_AcquireCounter = 2.0;
        if ( UFG::FindTargetBySymbol(&this->mSimObjectID, &simObj) )
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mTargetSimObj,
            (UFG::SimComponent *)simObj);
      }
    }
    v7 = this->mVisible && (this->mPosSet || this->mTargetSimObj.m_pPointer);
    v8 = FLOAT_100_0;
    y = this->mWorldPos.y;
    z = this->mWorldPos.z;
    world_pos.x = this->mWorldPos.x;
    world_pos.y = y;
    world_pos.z = z;
    m_pPointer = this->mTargetSimObj.m_pPointer;
    if ( m_pPointer )
    {
      m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v13 = m_pTransformNodeComponent->mWorldTransform.v3.y;
        z = m_pTransformNodeComponent->mWorldTransform.v3.z;
        world_pos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
        world_pos.y = v13;
      }
    }
    world_pos.z = z + UFG::UIHKTweakables::ObjectiveDistanceWidget_Altitude;
    if ( !UFG::UI::GetPlayerWorldPosition((UFG::qVector3 *)&pval.8, &dir) )
      goto LABEL_126;
    pNext_low = (__m128)LODWORD(pval.pNext);
    pNext_low.m128_f32[0] = *(float *)&pval.pNext - world_pos.x;
    v15 = pNext_low;
    v15.m128_f32[0] = (float)((float)(pNext_low.m128_f32[0] * pNext_low.m128_f32[0])
                            + (float)((float)(*((float *)&pval.pVoidNext + 1) - world_pos.y)
                                    * (float)(*((float *)&pval.pVoidNext + 1) - world_pos.y)))
                    + (float)((float)(*(float *)&pval.pObjectInterface - world_pos.z)
                            * (float)(*(float *)&pval.pObjectInterface - world_pos.z));
    v16 = _mm_sqrt_ps(v15).m128_f32[0];
    this->mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(this->mDistance - v16) & _xmm) > 0.1;
    this->mDistance = v16;
    if ( v15.m128_f32[0] < 9.0 )
      goto LABEL_126;
    if ( v15.m128_f32[0] < 64.0 )
    {
      v17 = (float)(v15.m128_f32[0] - 9.0) * 0.018181818;
      if ( v17 < 0.0 )
        v17 = 0.0;
      v8 = v17 * 100.0;
    }
    if ( !v7 )
    {
LABEL_126:
      if ( !this->mVisibleSynced )
      {
        v87 |= 0x40u;
        v88 = 0;
        pval.pObjectInterface->vfptr->SetDisplayInfo(
          pval.pObjectInterface,
          v75,
          (Scaleform::GFx::Value::DisplayInfo *)v86);
        this->mVisibleSynced = 1;
      }
      goto LABEL_122;
    }
    this->mVisibleSynced = 0;
    if ( v8 != this->mOldAlpha )
    {
      this->mOldAlpha = v8;
      v87 |= 0x20u;
      *(double *)&v86[5] = v8;
    }
    CurrentBaseCamera = UFG::GetCurrentBaseCamera();
    if ( CurrentBaseCamera )
    {
      v19 = ((double (__fastcall *)(UFG::BaseCameraComponent *))CurrentBaseCamera->vfptr[19].__vecDelDtor)(CurrentBaseCamera);
      v20 = *(float *)&v19;
    }
    else
    {
      v20 = FLOAT_1_5707964;
    }
    mWidth = (float)Render::GetBackBufferTarget()->mWidth;
    v22 = Render::gScreenViewportScaleH * mWidth;
    v23 = tanf(v20 * 0.5);
    v24 = atan2f((float)(v23 * v22) / mWidth, 1.0) * 2.0;
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mCamera = &mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    v27 = UFG::Camera::GetNearPlane(p_mCamera);
    v28 = UFG::Director::Get()->mCurrentCamera;
    if ( v28 )
      v29 = &v28->mCamera;
    else
      v29 = 0i64;
    FarPlane = UFG::Camera::GetFarPlane(v29);
    UFG::qPerspectiveMatrix(&dest, v24, 1.7777778, v27, FarPlane);
    v31 = UFG::Director::Get()->mCurrentCamera;
    if ( v31 )
      v32 = &v31->mCamera;
    else
      v32 = 0i64;
    WorldView = UFG::Camera::GetWorldView(v32);
    UFG::qMatrix44::operator*(WorldView, &result, &dest);
    BackBufferTarget = Render::GetBackBufferTarget();
    mHeight = (float)BackBufferTarget->mHeight;
    viewport_scale.x = (float)BackBufferTarget->mWidth;
    viewport_scale.y = mHeight;
    UFG::qGetScreenCoord(&a, &world_pos, &result, &viewport_scale, &this->mIsOnScreen);
    UFG::UI::ScaleViewCoordsToUIScreen(screen, &a.x, &a.y);
    v36 = UFG::qFloor(&dir, &a);
    x = v36->x;
    v38 = v36->y;
    v39 = v36->z;
    a.x = x;
    a.y = v38;
    a.z = v39;
    if ( x != this->mScreenPos.x || v38 != this->mScreenPos.y || (v40 = 0, v39 != this->mScreenPos.z) )
      v40 = 1;
    this->mChanged |= v40;
    this->mScreenPos.x = x;
    this->mScreenPos.y = v38;
    this->mScreenPos.z = v39;
    if ( !this->mChanged )
      goto LABEL_6;
    this->mChanged = 0;
    mVisible = this->mVisible;
    v87 |= 0x40u;
    v88 = mVisible;
    if ( !mVisible )
      goto LABEL_6;
    v42 = (float)(int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)(screen->mRenderable->m_movieDef.pObject);
    v43 = (float)(int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)(screen->mRenderable->m_movieDef.pObject);
    *(float *)&simObj = v43;
    v44 = v42 * 0.5;
    v45 = v43 * 0.5;
    HIDWORD(v75) = atan2f(v42 * 0.5, v43 * 0.5);
    vars0 = 3.1415927 - *((float *)&v75 + 1);
    *(float *)&v75 = 6.2831855 - *((float *)&v75 + 1);
    v72 = *((float *)&v75 + 1) + 3.1415927;
    *(float *)&pval.Type = world_pos.x - *(float *)&pval.pNext;
    *((float *)&pval.Type + 1) = world_pos.y - *((float *)&pval.pVoidNext + 1);
    *(float *)&pval.mValue.IValue = world_pos.z - *(float *)&pval.pObjectInterface;
    v46 = UFG::Director::Get()->mCurrentCamera;
    if ( v46 )
      p_mFOVOffset = (_DWORD *)&v46->mCamera.mFOVOffset;
    else
      p_mFOVOffset = 0i64;
    v48 = p_mFOVOffset[42] ^ _xmm[0];
    LODWORD(v49) = p_mFOVOffset[41] ^ _xmm[0];
    LODWORD(v1.x) = p_mFOVOffset[40] ^ _xmm[0];
    v1.y = v49;
    LODWORD(v1.z) = v48;
    *(float *)&pval.DataAux = a.x - v44;
    *((float *)&pval.DataAux + 1) = a.y - v45;
    v77 = a.z;
    if ( (float)((float)(v1.x * v1.x) + (float)(v49 * v49)) < 0.0000010000001
      || (float)((float)(*((float *)&pval.Type + 1) * *((float *)&pval.Type + 1))
               + (float)(*(float *)&pval.Type * *(float *)&pval.Type)) < 0.0000010000001 )
    {
      goto LABEL_122;
    }
    v50 = UFG::qHeading2D(&v1);
    v51 = v50 - UFG::qHeading2D((UFG::qVector3 *)&pval.Type);
    v52 = fmodf(v51, 6.2831855);
    v53 = v52;
    if ( v52 < 0.0 )
      v53 = v52 + 6.2831855;
    if ( (float)((float)(*((float *)&pval.DataAux + 1) * *((float *)&pval.DataAux + 1))
               + (float)(*(float *)&pval.DataAux * *(float *)&pval.DataAux)) < 0.0000010000001 )
      goto LABEL_122;
    v54 = UFG::qHeading2D((UFG::qVector3 *)&pval.DataAux);
    v55 = fmodf(v54 + 1.5707964, 6.2831855);
    v56 = v55;
    if ( v55 < 0.0 )
      v56 = v55 + 6.2831855;
    v57 = v53 < 1.5707964 || v53 > 4.712389;
    v58 = 4;
    v59 = *(float *)&v75;
    if ( v53 <= *(float *)&v75 && v53 >= v72 )
    {
      v60 = 0.0;
      v43 = v45 - (float)(v44 / tanf(6.2831855 - v53));
      v61 = 0;
      goto LABEL_76;
    }
    if ( v53 < *((float *)&v75 + 1) )
    {
      if ( v53 < vars0 )
        goto LABEL_70;
    }
    else if ( v53 <= vars0 )
    {
      v60 = v42;
      v43 = v45 - (float)(v44 / tanf(v53));
      v61 = 1;
      goto LABEL_76;
    }
    if ( v53 <= v72 )
    {
      v62 = tanf(3.1415927 - v53);
      v61 = 3;
LABEL_75:
      v60 = (float)(v62 * v45) + v44;
LABEL_76:
      if ( v57 )
      {
        v63 = a.x;
        if ( a.x >= 0.0 && a.x <= v42 )
        {
          v64 = a.y;
          if ( a.y >= 0.0 && a.y <= *(float *)&simObj )
            goto LABEL_95;
          v59 = *(float *)&v75;
        }
        if ( v56 >= *((float *)&v75 + 1) && v56 <= vars0 )
        {
          v63 = v42;
          v64 = v45 - (float)(v44 / tanf(v56));
          v58 = 1;
LABEL_95:
          v65 = *(float *)&simObj;
          goto LABEL_96;
        }
        if ( v56 <= v59 && v56 >= v72 )
        {
          v63 = 0.0;
          v64 = v45 - (float)(v44 / tanf(6.2831855 - v56));
          v58 = 0;
          goto LABEL_95;
        }
        if ( v56 >= vars0 && v56 <= v72 )
        {
          v63 = (float)(tanf(3.1415927 - v56) * v45) + v44;
          v65 = *(float *)&simObj;
          v64 = *(float *)&simObj;
          v58 = 3;
LABEL_96:
          value.pObjectInterface = 0i64;
          value.Type = VT_Undefined;
          if ( v57 )
          {
            v66 = v58;
          }
          else
          {
            v63 = v60;
            v64 = v43;
            v66 = v61;
          }
          UFG::UIHKObjectiveDistanceWidget::SetArrowDirection(this, pObject, v66);
          LOBYTE(far_plane) = (pval.Type & 0x8F) == 10;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *, Scaleform::GFx::Value *, int))&pval.pObjectInterface->vfptr->gap8[24])(
            pval.pObjectInterface,
            v75,
            "_width",
            &value,
            far_plane);
          LOBYTE(far_planea) = (pval.Type & 0x8F) == 10;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *, Scaleform::GFx::Value *, int))&pval.pObjectInterface->vfptr->gap8[24])(
            pval.pObjectInterface,
            v75,
            "_height",
            &value,
            far_planea);
          v67 = v42 - 70.0;
          v68 = v65 - 70.0;
          if ( v63 <= 70.0 )
            v63 = FLOAT_70_0;
          if ( v63 >= v67 )
            v63 = v67;
          if ( v64 <= 100.0 )
            v64 = FLOAT_100_0;
          if ( v64 >= v68 )
            v64 = v68;
          *(double *)v86 = v63;
          v87 |= 3u;
          *(double *)&v86[1] = v64;
          pval.pObjectInterface->vfptr->SetDisplayInfo(
            pval.pObjectInterface,
            v75,
            (Scaleform::GFx::Value::DisplayInfo *)v86);
          v83 = 0i64;
          v84 = 0;
          mDistance = this->mDistance;
          if ( mDistance != this->mOldDistance )
          {
            this->mOldDistance = mDistance;
            UFG::qSPrintf((char *)&dir, 20, "%.0f m", mDistance);
            if ( (value.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                value.mValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = VT_String;
            value.mValue.pString = (const char *)&dir;
            Scaleform::GFx::Movie::SetVariable(pObject, "mc_ObjectiveDist.tf_distance.text", &value, 1i64);
          }
          if ( this->mColorChanged )
          {
            this->mColorChanged = 0;
            UFG::UIHKObjectiveDistanceWidget::Flash_SetColor(this, pObject, &this->mColor);
          }
          if ( (pval.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, void *))&pval.pObjectInterface->vfptr->gap8[8])(
              pval.pObjectInterface,
              &pval,
              v75);
            pval.pObjectInterface = 0i64;
          }
          pval.Type = VT_Null;
          if ( (v84 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v83 + 16i64))(v83, v82, v85);
            v83 = 0i64;
          }
          v84 = 0;
          if ( (value.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              value.mValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = VT_Undefined;
          goto LABEL_122;
        }
        if ( v56 >= v59 || v56 <= *((float *)&v75 + 1) )
        {
          v63 = (float)(tanf(v56) * v45) + v44;
          v64 = 0.0;
          v58 = 2;
          goto LABEL_95;
        }
      }
      v64 = v45;
      v63 = v42 * 0.5;
      goto LABEL_95;
    }
LABEL_70:
    if ( v53 >= *(float *)&v75 || v53 <= *((float *)&v75 + 1) )
    {
      v62 = tanf(v53);
      v61 = 2;
    }
    else
    {
      v62 = tanf(v53);
      v61 = 4;
    }
    v43 = 0.0;
    goto LABEL_75;
  }
}

// File Line: 486
// RVA: 0x605850
void __fastcall UFG::UIHKObjectiveDistanceWidget::SetEnabled(UFG::UIHKObjectiveDistanceWidget *this, bool enabled)
{
  bool v2; // zf

  v2 = this->mEnabled == enabled;
  this->mEnabled = enabled;
  this->mChanged |= !v2;
}

// File Line: 508
// RVA: 0x5D51E0
void __fastcall UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKObjectiveDistanceWidget *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mTargetSimObj; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mPosSet = 0;
  UFG::qString::Set(&this->mCaption, &customCaption);
  p_mTargetSimObj = &this->mTargetSimObj;
  this->mObjective = 0i64;
  if ( this->mTargetSimObj.m_pPointer )
  {
    mPrev = p_mTargetSimObj->mPrev;
    mNext = this->mTargetSimObj.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetSimObj->mPrev = p_mTargetSimObj;
    this->mTargetSimObj.mNext = &this->mTargetSimObj;
  }
  this->mTargetSimObj.m_pPointer = 0i64;
  this->mSimObjectID = UFG::gNullQSymbol;
  this->mColor = UFG::qColour::White;
}

// File Line: 528
// RVA: 0x605220
void __fastcall UFG::UIHKObjectiveDistanceWidget::SetArrowDirection(
        UFG::UIHKObjectiveDistanceWidget *this,
        Scaleform::GFx::Movie *movie,
        UFG::UIHKObjectiveDistanceWidget::eArrowDirection dir)
{
  int v3; // r8d
  int v4; // r8d
  const char *v5; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-38h] BYREF

  if ( movie && this->mArrowDirection != dir )
  {
    this->mArrowDirection = dir;
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_Undefined;
    if ( dir )
    {
      v3 = dir - 1;
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          if ( v4 == 1 )
            v5 = "down";
          else
            v5 = "hidden";
        }
        else
        {
          v5 = aU_2;
        }
      }
      else
      {
        v5 = "right";
      }
    }
    else
    {
      v5 = "left";
    }
    pargs.Type = VT_String;
    pargs.mValue.pString = v5;
    Scaleform::GFx::Movie::Invoke(movie, "ObjectiveDist_SetArrowDirection", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 572
// RVA: 0x606630
void __fastcall UFG::UIHKObjectiveDistanceWidget::SetObjective(
        UFG::UIHKObjectiveDistanceWidget *this,
        UFG::UIHKPlayerObjective *objective)
{
  UFG::UIHKPlayerObjectiveManager *v4; // rbp
  UFG::Objective *mObjective; // rcx
  char *v6; // rsi
  const char *mText; // rcx
  bool v8; // cc
  UFG::Objective *v9; // rax
  char *mData; // rdx
  UFG::Objective *v11; // rcx
  UFG::qSymbol *v12; // rax
  Render::SkinningCacheNode *FirstIndicator; // rax
  UFG::SimComponent *SimObject; // rax
  UFG::eIconTexturePageIndex v15; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::HudComponent *m_pPointer; // rcx
  char WorldPosition; // al
  bool mVisible; // zf
  UFG::qBaseTreeRB *CollisionModel; // rax
  CAkSrcPhysModel *v23; // rdi
  UFG::qColour *Color; // rax
  unsigned int vfptr_high; // ecx
  UFG::qVector3 v26; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-18h] BYREF
  UFG::HudComponent *target; // [rsp+68h] [rbp+10h] BYREF

  UFG::UIHKObjectiveDistanceWidget::Clear(this);
  if ( !objective )
    return;
  if ( objective->minimapBlips.size > 1 )
    return;
  this->mObjective = objective->mObjective;
  v4 = UFG::UIHKPlayerObjectiveManager::mInstance;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return;
  UFG::UI::GetPlayerWorldPosition(&pos, &dir);
  mObjective = objective->mObjective;
  v6 = &customCaption;
  if ( mObjective )
    mText = mObjective->mLocationCaption.mText;
  else
    mText = &customCaption;
  v8 = (int)UFG::qStringLength(mText) <= 0;
  v9 = objective->mObjective;
  if ( v8 )
  {
    if ( v9 )
      mData = v9->mCaption.mData;
    else
      mData = objective->alternateCaption.mData;
  }
  else
  {
    if ( v9 )
      v6 = v9->mLocationCaption.mText;
    mData = v6;
  }
  this->mChanged = 1;
  UFG::qString::Set(&this->mCaption, mData);
  v11 = objective->mObjective;
  if ( v11 )
  {
    FirstIndicator = UFG::Objective::GetFirstIndicator(v11);
    if ( FirstIndicator )
      v12 = (UFG::qSymbol *)&FirstIndicator[1];
    else
      v12 = &UFG::gNullQSymbol;
  }
  else
  {
    v12 = &UFG::gNullQSymbol;
  }
  this->mSimObjectID = (UFG::qSymbol)v12->mUID;
  SimObject = (UFG::SimComponent *)UFG::UIHKPlayerObjective::GetSimObject(objective);
  if ( SimObject )
  {
    UFG::qSafePointer<Creature,Creature>::operator=(
      (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mTargetSimObj,
      SimObject);
    mVisible = this->mVisible;
    this->mVisible = 1;
    this->mChanged |= !mVisible;
  }
  v15 = TPCharacterPlayer;
  target = 0i64;
  if ( objective->useFixedPos )
  {
    x = objective->fixedPos.x;
    y = objective->fixedPos.y;
    z = objective->fixedPos.z;
    v26.x = x;
    v26.y = y;
    v26.z = z;
LABEL_28:
    this->mChanged = 1;
    this->mPosSet = 1;
    this->mWorldPos.x = x;
    this->mWorldPos.y = y;
    this->mWorldPos.z = z;
    mVisible = this->mVisible;
    this->mVisible = 1;
LABEL_31:
    this->mChanged |= !mVisible;
    goto LABEL_32;
  }
  m_pPointer = (UFG::HudComponent *)objective->gpsTarget.m_pPointer;
  if ( m_pPointer )
    WorldPosition = UFG::HudComponent::GetWorldPosition(m_pPointer, &v26);
  else
    WorldPosition = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(v4, objective, &v26, &target);
  if ( WorldPosition )
  {
    z = v26.z;
    y = v26.y;
    x = v26.x;
    goto LABEL_28;
  }
  if ( !this->mTargetSimObj.m_pPointer )
  {
    mVisible = !this->mVisible;
    this->mVisible = 0;
    goto LABEL_31;
  }
LABEL_32:
  if ( UFG::UIHKScreenHud::mIconManager
    && objective->minimapBlips.size
    && (CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                           (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
                           *objective->minimapBlips.p),
        (v23 = (CAkSrcPhysModel *)CollisionModel) != 0i64) )
  {
    Color = UFG::UIMapBlip::GetColor((UFG::UIMapBlip *)CollisionModel);
    this->mChanged = 1;
    this->mColorChanged = 1;
    this->mColor = *Color;
    vfptr_high = HIDWORD(UFG::UIMapBlip::GetType(v23)->vfptr);
    this->mAssociatedIcon.mUID = vfptr_high;
    if ( vfptr_high == UIBlipIcon_Waypoint_14.mUID )
      goto LABEL_39;
    if ( vfptr_high == UIBlipIcon_Mission_Start_14.mUID )
    {
      this->mAssociatedIconIndex = TPObjectiveCircleStart;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Mission_Objective_14.mUID )
    {
LABEL_39:
      this->mAssociatedIconIndex = TPObjectiveCircle;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Case_Start_14.mUID || vfptr_high == UIBlipIcon_Case_Objective_14.mUID )
    {
      this->mAssociatedIconIndex = TPTPoliceCase;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Social_14.mUID )
      goto LABEL_56;
    if ( vfptr_high == UIBlipIcon_Cop_Event_Start_14.mUID )
    {
      this->mAssociatedIconIndex = TPTJob;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Event_Start_14.mUID || vfptr_high == UIBlipIcon_Event_Objective_14.mUID )
    {
      this->mAssociatedIconIndex = TPTEvent;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Race_Start_14.mUID || vfptr_high == UIBlipIcon_Race_Start_Flag_14.mUID )
    {
      this->mAssociatedIconIndex = TPObjectiveRaceFlag;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Triad_Wars_14.mUID )
    {
      this->mAssociatedIconIndex = TPObjectiveTriadWars;
      return;
    }
    if ( vfptr_high == UIBlipIcon_Trapped_Ped_14.mUID || vfptr_high == UIBlipIcon_Face_Character_14.mUID )
    {
LABEL_56:
      this->mAssociatedIconIndex = TPCharacterSocial;
    }
    else if ( vfptr_high == UIBlipIcon_Massage_Parlors_14.mUID )
    {
      this->mAssociatedIconIndex = TPAmbientMassage;
    }
    else if ( vfptr_high == UIBlipIcon_Fight_Club_14.mUID )
    {
      this->mAssociatedIconIndex = TPAmbientFightClub;
    }
    else
    {
      if ( vfptr_high == UIBlipIcon_Race_Objective_14.mUID )
        v15 = TPAmbientVehicleStore;
      this->mAssociatedIconIndex = v15;
    }
  }
  else
  {
    this->mAssociatedIconIndex = TPCharacterPlayer;
    this->mChanged = 1;
    this->mColorChanged = 1;
    this->mColor = UFG::qColour::White;
  }
}

// File Line: 656
// RVA: 0x5DFB10
void __fastcall UFG::UIHKObjectiveDistanceWidget::Flash_SetColor(
        UFG::UIHKObjectiveDistanceWidget *this,
        Scaleform::GFx::Movie *movie,
        UFG::qColour *color)
{
  int v5; // edi
  int v6; // esi
  int v7; // r15d
  Scaleform::GFx::Value::ValueUnion v8; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+8h] [rbp-79h] BYREF
  char v10[16]; // [rsp+38h] [rbp-49h] BYREF
  __int64 v11; // [rsp+48h] [rbp-39h]
  int v12; // [rsp+50h] [rbp-31h]
  double v13; // [rsp+58h] [rbp-29h]
  char v14[16]; // [rsp+68h] [rbp-19h] BYREF
  __int64 v15; // [rsp+78h] [rbp-9h]
  int v16; // [rsp+80h] [rbp-1h]
  double v17; // [rsp+88h] [rbp+7h]
  __int64 v18; // [rsp+98h] [rbp+17h]

  v18 = -2i64;
  v5 = (int)(float)(color->r * 255.0);
  v6 = (int)(float)(color->g * 255.0);
  v7 = (int)(float)(color->b * 255.0);
  *(_QWORD *)&ptr.Type = Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator(&ptr.DataAux, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)Scaleform::GFx::Value::~Value & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.NValue = (double)(unsigned __int8)v5;
  if ( (v12 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(v11, v10, COERCE_DOUBLE(*(_QWORD *)&v13));
    v11 = 0i64;
  }
  v12 = 5;
  v13 = (double)(unsigned __int8)v6;
  if ( (v16 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(v15, v14, COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = (double)(unsigned __int8)v7;
  Scaleform::GFx::Movie::Invoke(movie, "ObjectiveDist_SetColor", 0i64, &ptr, 3u);
  v8.NValue = (double)(int)this->mAssociatedIconIndex;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.mValue = v8;
  Scaleform::GFx::Movie::Invoke(movie, "ObjectiveDist_SetType", 0i64, &ptr, 1u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

