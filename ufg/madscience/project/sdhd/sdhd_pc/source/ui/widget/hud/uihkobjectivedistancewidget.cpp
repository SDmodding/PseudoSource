// File Line: 59
// RVA: 0x5C4580
void __fastcall UFG::UIHKObjectiveDistanceWidget::UIHKObjectiveDistanceWidget(UFG::UIHKObjectiveDistanceWidget *this)
{
  UFG::UIHKObjectiveDistanceWidget *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  *(_DWORD *)&this->mVisibleSynced = 0x1000000;
  *(_WORD *)&this->mIsOnScreen = 0;
  this->mDistance = 0.0;
  UFG::qString::qString(&this->mCaption);
  v1->mArrowDirection = 3;
  v1->mTargetSimObject_AcquireCounter = 2.0;
  v1->mOldDistance = -1.0;
  v1->mOldAlpha = -1.0;
  v1->mCoronaType = 0;
  v1->mColorChanged = 0;
  v1->mAssociatedIcon.mUID = -1;
  v1->mAssociatedIconIndex = 0;
  v1->mObjective = 0i64;
  v2 = &v1->mTargetSimObj;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mTargetSimObj.m_pPointer = 0i64;
  v1->mSimObjectID.mUID = -1;
  v1->mColor.r = UFG::qColour::White.r;
  v1->mColor.g = UFG::qColour::White.g;
  v1->mColor.b = UFG::qColour::White.b;
  v1->mColor.a = UFG::qColour::White.a;
}

// File Line: 65
// RVA: 0x615440
void __fastcall UFG::UIHKObjectiveDistanceWidget::Update(UFG::UIHKObjectiveDistanceWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // r14
  UFG::UIHKObjectiveDistanceWidget *v4; // rbx
  Scaleform::GFx::Movie *v5; // r15
  float v6; // xmm0_4
  bool v7; // si
  float v8; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::SimObject *v11; // rdi
  UFG::TransformNodeComponent *v12; // rdi
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  __m128 v16; // xmm7
  __m128 v17; // xmm2
  float v18; // xmm3_4
  float v19; // xmm7_4
  double v20; // xmm0_8
  float v21; // xmm6_4
  UFG::BaseCameraComponent *v22; // rax
  float v23; // xmm8_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm6_4
  UFG::BaseCameraComponent *v28; // rcx
  UFG::Camera *v29; // rcx
  float v30; // xmm7_4
  UFG::BaseCameraComponent *v31; // rcx
  UFG::Camera *v32; // rcx
  float v33; // xmm0_4
  UFG::BaseCameraComponent *v34; // rcx
  UFG::Camera *v35; // rcx
  UFG::qMatrix44 *v36; // rax
  Illusion::Target *v37; // rax
  float v38; // xmm1_4
  float v39; // xmm0_4
  UFG::qVector3 *v40; // rax
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  char v44; // al
  char v45; // al
  float v46; // xmm15_4
  float v47; // xmm13_4
  float v48; // xmm10_4
  float v49; // xmm11_4
  UFG::BaseCameraComponent *v50; // rax
  _DWORD *v51; // rax
  int v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm0_4
  float v55; // xmm6_4
  float v56; // xmm0_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm0_4
  float v60; // xmm8_4
  bool v61; // r14
  signed int v62; // edi
  float v63; // xmm7_4
  float v64; // xmm9_4
  signed int v65; // esi
  float v66; // xmm0_4
  float v67; // xmm6_4
  float v68; // xmm7_4
  float v69; // xmm8_4
  UFG::UIHKObjectiveDistanceWidget::eArrowDirection v70; // er8
  __int64 v71; // ST20_8
  float v72; // xmm15_4
  float v73; // xmm8_4
  float v74; // xmm0_4
  __int64 far_plane; // [rsp+20h] [rbp-B8h]
  float v76; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 world_pos; // [rsp+38h] [rbp-A0h]
  UFG::qVector3 a; // [rsp+48h] [rbp-90h]
  void *v79; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::Value pval; // [rsp+60h] [rbp-78h]
  float v81; // [rsp+90h] [rbp-48h]
  UFG::qVector2 viewport_scale; // [rsp+98h] [rbp-40h]
  Scaleform::GFx::Value value; // [rsp+A0h] [rbp-38h]
  UFG::qVector3 v1; // [rsp+D0h] [rbp-8h]
  UFG::qVector3 dir; // [rsp+E0h] [rbp+8h]
  char v86; // [rsp+F8h] [rbp+20h]
  __int64 v87; // [rsp+108h] [rbp+30h]
  unsigned int v88; // [rsp+110h] [rbp+38h]
  __int64 v89; // [rsp+118h] [rbp+40h]
  double v90; // [rsp+128h] [rbp+50h]
  double v91; // [rsp+130h] [rbp+58h]
  double v92; // [rsp+150h] [rbp+78h]
  int Dst; // [rsp+188h] [rbp+B0h]
  int v94; // [rsp+19Ch] [rbp+C4h]
  int v95; // [rsp+1B0h] [rbp+D8h]
  int v96; // [rsp+1B8h] [rbp+E0h]
  int v97; // [rsp+1CCh] [rbp+F4h]
  int v98; // [rsp+1E0h] [rbp+108h]
  int v99; // [rsp+1F4h] [rbp+11Ch]
  __int16 v100; // [rsp+1FCh] [rbp+124h]
  char v101; // [rsp+1FEh] [rbp+126h]
  __int64 v102; // [rsp+208h] [rbp+130h]
  UFG::qMatrix44 dest; // [rsp+218h] [rbp+140h]
  UFG::qMatrix44 result; // [rsp+258h] [rbp+180h]
  UFG::SimObject *simObj; // [rsp+370h] [rbp+298h]
  float vars0; // [rsp+380h] [rbp+2A8h]

  v102 = -2i64;
  v3 = screen;
  v4 = this;
  v5 = screen->mRenderable->m_movie.pObject;
  if ( v5 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v5, &pval, "mc_ObjectiveDist");
    memset(&Dst, 0, 0x30ui64);
    Dst = 1065353216;
    v94 = 1065353216;
    v95 = 1065353216;
    memset(&v96, 0, 0x40ui64);
    v96 = 1065353216;
    v97 = 1065353216;
    v98 = 1065353216;
    v99 = 1065353216;
    v100 = 0;
    if ( (pval.Type & 0x8F) != 10 )
      goto LABEL_122;
    pval.pObjectInterface->vfptr->GetDisplayInfo(pval.pObjectInterface, v79, (Scaleform::GFx::Value::DisplayInfo *)&v90);
    if ( !v4->mEnabled )
    {
      if ( !v4->mChanged )
        goto LABEL_122;
      v4->mChanged = 0;
      v100 |= 0x40u;
      v101 = 0;
LABEL_6:
      pval.pObjectInterface->vfptr->SetDisplayInfo(
        pval.pObjectInterface,
        v79,
        (Scaleform::GFx::Value::DisplayInfo *)&v90);
LABEL_122:
      if ( ((unsigned int)pval.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, void *))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          v79);
      return;
    }
    if ( !v4->mTargetSimObj.m_pPointer && v4->mSimObjectID.mUID != UFG::gNullQSymbol.mUID )
    {
      v6 = v4->mTargetSimObject_AcquireCounter - elapsed;
      v4->mTargetSimObject_AcquireCounter = v6;
      if ( v6 <= 0.0 )
      {
        v4->mTargetSimObject_AcquireCounter = 2.0;
        if ( UFG::FindTargetBySymbol(&v4->mSimObjectID, &simObj) )
          UFG::qSafePointer<Creature,Creature>::operator=(
            (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v4->mTargetSimObj,
            (UFG::SimComponent *)simObj);
      }
    }
    v7 = v4->mVisible && (v4->mPosSet || v4->mTargetSimObj.m_pPointer);
    v8 = FLOAT_100_0;
    v9 = v4->mWorldPos.y;
    v10 = v4->mWorldPos.z;
    world_pos.x = v4->mWorldPos.x;
    world_pos.y = v9;
    world_pos.z = v10;
    v11 = v4->mTargetSimObj.m_pPointer;
    if ( v11 )
    {
      v12 = v11->m_pTransformNodeComponent;
      if ( v12 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform(v12);
        v13 = v12->mWorldTransform.v3.y;
        v10 = v12->mWorldTransform.v3.z;
        world_pos.x = v12->mWorldTransform.v3.x;
        world_pos.y = v13;
      }
    }
    world_pos.z = v10 + UFG::UIHKTweakables::ObjectiveDistanceWidget_Altitude;
    if ( !UFG::UI::GetPlayerWorldPosition((UFG::qVector3 *)&pval.8, &dir) )
      goto LABEL_126;
    v14 = *(float *)&pval.pObjectInterface - world_pos.z;
    v15 = *((float *)&pval.pVoidNext + 1) - world_pos.y;
    v16 = (__m128)LODWORD(pval.pNext);
    v16.m128_f32[0] = *(float *)&pval.pNext - world_pos.x;
    v17 = v16;
    v17.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15)) + (float)(v14 * v14);
    LODWORD(v18) = (unsigned __int128)_mm_sqrt_ps(v17);
    v4->mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v4->mDistance - v18) & _xmm) > 0.1;
    v4->mDistance = v18;
    v19 = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v15 * v15)) + (float)(v14 * v14);
    *(float *)&v20 = FLOAT_9_0;
    if ( v19 < 9.0 )
      goto LABEL_126;
    if ( v19 < 64.0 )
    {
      v21 = (float)(v19 - 9.0) * 0.018181818;
      if ( v21 < 0.0 )
        v21 = 0.0;
      v8 = v21 * 100.0;
    }
    if ( !v7 )
    {
LABEL_126:
      if ( !v4->mVisibleSynced )
      {
        v100 |= 0x40u;
        v101 = 0;
        pval.pObjectInterface->vfptr->SetDisplayInfo(
          pval.pObjectInterface,
          v79,
          (Scaleform::GFx::Value::DisplayInfo *)&v90);
        v4->mVisibleSynced = 1;
      }
      goto LABEL_122;
    }
    v4->mVisibleSynced = 0;
    if ( v8 != v4->mOldAlpha )
    {
      v4->mOldAlpha = v8;
      v100 |= 0x20u;
      v20 = v8;
      v92 = v8;
    }
    v22 = UFG::GetCurrentBaseCamera();
    if ( v22 )
    {
      ((void (__fastcall *)(UFG::BaseCameraComponent *))v22->vfptr[19].__vecDelDtor)(v22);
      v23 = *(float *)&v20;
    }
    else
    {
      v23 = FLOAT_1_5707964;
    }
    v24 = (float)Render::GetBackBufferTarget()->mWidth;
    v25 = Render::gScreenViewportScaleH * v24;
    v26 = tanf(v23 * 0.5);
    v27 = atan2f((float)(v26 * v25) / v24, 1.0) * 2.0;
    v28 = UFG::Director::Get()->mCurrentCamera;
    if ( v28 )
      v29 = &v28->mCamera;
    else
      v29 = 0i64;
    v30 = UFG::Camera::GetNearPlane(v29);
    v31 = UFG::Director::Get()->mCurrentCamera;
    if ( v31 )
      v32 = &v31->mCamera;
    else
      v32 = 0i64;
    v33 = UFG::Camera::GetFarPlane(v32);
    UFG::qPerspectiveMatrix(&dest, v27, 1.7777778, v30, v33);
    v34 = UFG::Director::Get()->mCurrentCamera;
    if ( v34 )
      v35 = &v34->mCamera;
    else
      v35 = 0i64;
    v36 = UFG::Camera::GetWorldView(v35);
    UFG::qMatrix44::operator*(v36, &result, &dest);
    v37 = Render::GetBackBufferTarget();
    v38 = (float)v37->mHeight;
    v39 = (float)v37->mWidth;
    viewport_scale.x = (float)v37->mWidth;
    viewport_scale.y = v38;
    UFG::qGetScreenCoord(&a, &world_pos, &result, &viewport_scale, &v4->mIsOnScreen);
    UFG::UI::ScaleViewCoordsToUIScreen(v3, &a.x, &a.y, v39);
    v40 = UFG::qFloor(&dir, &a);
    v41 = v40->x;
    v42 = v40->y;
    v43 = v40->z;
    a.x = v41;
    a.y = v42;
    a.z = v43;
    if ( v41 != v4->mScreenPos.x || v42 != v4->mScreenPos.y || (v44 = 0, v43 != v4->mScreenPos.z) )
      v44 = 1;
    v4->mChanged |= v44;
    v4->mScreenPos.x = v41;
    v4->mScreenPos.y = v42;
    v4->mScreenPos.z = v43;
    if ( !v4->mChanged )
      goto LABEL_6;
    v4->mChanged = 0;
    v45 = v4->mVisible;
    v100 |= 0x40u;
    v101 = v45;
    if ( !v45 )
      goto LABEL_6;
    ((void (*)(void))v3->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)();
    v46 = (float)(signed int)v42;
    ((void (*)(void))v3->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)();
    v47 = (float)(signed int)v42;
    *(float *)&simObj = (float)(signed int)v42;
    v48 = v46 * 0.5;
    v49 = v47 * 0.5;
    HIDWORD(v79) = atan2f(v46 * 0.5, v47 * 0.5);
    vars0 = 3.1415927 - *((float *)&v79 + 1);
    *(float *)&v79 = 6.2831855 - *((float *)&v79 + 1);
    v76 = *((float *)&v79 + 1) + 3.1415927;
    *(float *)&pval.Type = world_pos.x - *(float *)&pval.pNext;
    *((float *)&pval.Type + 1) = world_pos.y - *((float *)&pval.pVoidNext + 1);
    *(float *)&pval.mValue.IValue = world_pos.z - *(float *)&pval.pObjectInterface;
    v50 = UFG::Director::Get()->mCurrentCamera;
    if ( v50 )
      v51 = (_DWORD *)&v50->mCamera.mFOVOffset;
    else
      v51 = 0i64;
    v52 = v51[42] ^ _xmm[0];
    LODWORD(v53) = v51[41] ^ _xmm[0];
    LODWORD(v1.x) = v51[40] ^ _xmm[0];
    v1.y = v53;
    LODWORD(v1.z) = v52;
    *(float *)&pval.DataAux = a.x - v48;
    *((float *)&pval.DataAux + 1) = a.y - v49;
    v81 = a.z;
    if ( (float)((float)(v1.x * v1.x) + (float)(v53 * v53)) < 0.0000010000001
      || (float)((float)(*((float *)&pval.Type + 1) * *((float *)&pval.Type + 1))
               + (float)(*(float *)&pval.Type * *(float *)&pval.Type)) < 0.0000010000001 )
    {
      goto LABEL_122;
    }
    v54 = UFG::qHeading2D(&v1);
    v55 = v54 - UFG::qHeading2D((UFG::qVector3 *)&pval.Type);
    v56 = fmodf(v55, 6.2831855);
    v57 = v56;
    if ( v56 < 0.0 )
      v57 = v56 + 6.2831855;
    if ( (float)((float)(*((float *)&pval.DataAux + 1) * *((float *)&pval.DataAux + 1))
               + (float)(*(float *)&pval.DataAux * *(float *)&pval.DataAux)) < 0.0000010000001 )
      goto LABEL_122;
    v58 = UFG::qHeading2D((UFG::qVector3 *)&pval.DataAux);
    v59 = fmodf(v58 + 1.5707964, 6.2831855);
    v60 = v59;
    if ( v59 < 0.0 )
      v60 = v59 + 6.2831855;
    v61 = v57 < 1.5707964 || v57 > 4.712389;
    v62 = 4;
    v63 = *(float *)&v79;
    if ( v57 <= *(float *)&v79 && v57 >= v76 )
    {
      v64 = 0.0;
      v47 = v49 - (float)(v48 / tanf(6.2831855 - v57));
      v65 = 0;
      goto LABEL_76;
    }
    if ( v57 < *((float *)&v79 + 1) )
    {
      if ( v57 < vars0 )
        goto LABEL_70;
    }
    else if ( v57 <= vars0 )
    {
      v64 = v46;
      v47 = v49 - (float)(v48 / tanf(v57));
      v65 = 1;
      goto LABEL_76;
    }
    if ( v57 <= v76 )
    {
      v66 = tanf(3.1415927 - v57);
      v65 = 3;
LABEL_75:
      v64 = (float)(v66 * v49) + v48;
LABEL_76:
      if ( v61 )
      {
        v67 = a.x;
        if ( a.x >= 0.0 && a.x <= v46 )
        {
          v68 = a.y;
          if ( a.y >= 0.0 && a.y <= *(float *)&simObj )
            goto LABEL_95;
          v63 = *(float *)&v79;
        }
        if ( v60 >= *((float *)&v79 + 1) && v60 <= vars0 )
        {
          v67 = v46;
          v68 = v49 - (float)(v48 / tanf(v60));
          v62 = 1;
LABEL_95:
          v69 = *(float *)&simObj;
          goto LABEL_96;
        }
        if ( v60 <= v63 && v60 >= v76 )
        {
          v67 = 0.0;
          v68 = v49 - (float)(v48 / tanf(6.2831855 - v60));
          v62 = 0;
          goto LABEL_95;
        }
        if ( v60 >= vars0 && v60 <= v76 )
        {
          v67 = (float)(tanf(3.1415927 - v60) * v49) + v48;
          v69 = *(float *)&simObj;
          v68 = *(float *)&simObj;
          v62 = 3;
LABEL_96:
          value.pObjectInterface = 0i64;
          value.Type = 0;
          if ( v61 )
          {
            v70 = v62;
          }
          else
          {
            v67 = v64;
            v68 = v47;
            v70 = v65;
          }
          UFG::UIHKObjectiveDistanceWidget::SetArrowDirection(v4, v5, v70);
          LOBYTE(far_plane) = (pval.Type & 0x8F) == 10;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *, Scaleform::GFx::Value *, __int64))&pval.pObjectInterface->vfptr->gap8[24])(
            pval.pObjectInterface,
            v79,
            "_width",
            &value,
            far_plane);
          LOBYTE(v71) = (pval.Type & 0x8F) == 10;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, void *, const char *, Scaleform::GFx::Value *, __int64))&pval.pObjectInterface->vfptr->gap8[24])(
            pval.pObjectInterface,
            v79,
            "_height",
            &value,
            v71);
          v72 = v46 - 70.0;
          v73 = v69 - 70.0;
          if ( v67 <= 70.0 )
            v67 = FLOAT_70_0;
          if ( v67 >= v72 )
            v67 = v72;
          if ( v68 <= 100.0 )
            v68 = FLOAT_100_0;
          if ( v68 >= v73 )
            v68 = v73;
          v90 = v67;
          v100 |= 3u;
          v91 = v68;
          pval.pObjectInterface->vfptr->SetDisplayInfo(
            pval.pObjectInterface,
            v79,
            (Scaleform::GFx::Value::DisplayInfo *)&v90);
          v87 = 0i64;
          v88 = 0;
          v74 = v4->mDistance;
          if ( v74 != v4->mOldDistance )
          {
            v4->mOldDistance = v74;
            UFG::qSPrintf((char *)&dir, 20, "%.0f m", v74);
            if ( ((unsigned int)value.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                *(_QWORD *)&value.mValue.NValue);
              value.pObjectInterface = 0i64;
            }
            value.Type = 6;
            *(_QWORD *)&value.mValue.NValue = &dir;
            Scaleform::GFx::Movie::SetVariable(v5, "mc_ObjectiveDist.tf_distance.text", &value, 1i64);
          }
          if ( v4->mColorChanged )
          {
            v4->mColorChanged = 0;
            UFG::UIHKObjectiveDistanceWidget::Flash_SetColor(v4, v5, &v4->mColor);
          }
          if ( ((unsigned int)pval.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, void *))&pval.pObjectInterface->vfptr->gap8[8])(
              pval.pObjectInterface,
              &pval,
              v79);
            pval.pObjectInterface = 0i64;
          }
          pval.Type = 1;
          if ( (v88 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v87 + 16i64))(v87, &v86, v89);
            v87 = 0i64;
          }
          v88 = 0;
          if ( ((unsigned int)value.Type >> 6) & 1 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
              value.pObjectInterface,
              &value,
              *(_QWORD *)&value.mValue.NValue);
            value.pObjectInterface = 0i64;
          }
          value.Type = 0;
          goto LABEL_122;
        }
        if ( v60 >= v63 || v60 <= *((float *)&v79 + 1) )
        {
          v67 = (float)(tanf(v60) * v49) + v48;
          v68 = 0.0;
          v62 = 2;
          goto LABEL_95;
        }
      }
      v68 = v49;
      v67 = v46 * 0.5;
      goto LABEL_95;
    }
LABEL_70:
    if ( v57 >= *(float *)&v79 || v57 <= *((float *)&v79 + 1) )
    {
      v66 = tanf(v57);
      v65 = 2;
    }
    else
    {
      v66 = tanf(v57);
      v65 = 4;
    }
    v47 = 0.0;
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
  UFG::UIHKObjectiveDistanceWidget *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = this;
  this->mPosSet = 0;
  UFG::qString::Set(&this->mCaption, &customWorldMapCaption);
  v2 = &v1->mTargetSimObj;
  v1->mObjective = 0i64;
  if ( v1->mTargetSimObj.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mTargetSimObj.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mTargetSimObj.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mTargetSimObj.mPrev;
  }
  v1->mTargetSimObj.m_pPointer = 0i64;
  v1->mSimObjectID = UFG::gNullQSymbol;
  v1->mColor.r = UFG::qColour::White.r;
  v1->mColor.g = UFG::qColour::White.g;
  v1->mColor.b = UFG::qColour::White.b;
  v1->mColor.a = UFG::qColour::White.a;
}

// File Line: 528
// RVA: 0x605220
void __fastcall UFG::UIHKObjectiveDistanceWidget::SetArrowDirection(UFG::UIHKObjectiveDistanceWidget *this, Scaleform::GFx::Movie *movie, UFG::UIHKObjectiveDistanceWidget::eArrowDirection dir)
{
  __int32 v3; // er8
  int v4; // er8
  const char *v5; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-38h]

  if ( movie && this->mArrowDirection != dir )
  {
    this->mArrowDirection = dir;
    pargs.pObjectInterface = 0i64;
    pargs.Type = 0;
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
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v5;
    Scaleform::GFx::Movie::Invoke(movie, "ObjectiveDist_SetArrowDirection", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 572
// RVA: 0x606630
void __fastcall UFG::UIHKObjectiveDistanceWidget::SetObjective(UFG::UIHKObjectiveDistanceWidget *this, UFG::UIHKPlayerObjective *objective)
{
  UFG::UIHKPlayerObjective *v2; // rdi
  UFG::UIHKObjectiveDistanceWidget *v3; // rbx
  UFG::UIHKPlayerObjectiveManager *v4; // rbp
  UFG::Objective *v5; // rcx
  char *v6; // rsi
  const char *v7; // rcx
  int v8; // eax
  bool v9; // sf
  UFG::Objective *v10; // rax
  const char *v11; // rdx
  UFG::Objective *v12; // rcx
  UFG::qSymbol *v13; // rax
  Render::SkinningCacheNode *v14; // rax
  UFG::SimComponent *v15; // rax
  signed int v16; // esi
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::HudComponent *v20; // rcx
  char v21; // al
  bool v22; // zf
  UFG::qBaseTreeRB *v23; // rax
  CAkSrcPhysModel *v24; // rdi
  UFG::qColour *v25; // rax
  unsigned int v26; // ecx
  UFG::qVector3 v27; // [rsp+20h] [rbp-38h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-28h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-18h]
  UFG::HudComponent *target; // [rsp+68h] [rbp+10h]

  v2 = objective;
  v3 = this;
  UFG::UIHKObjectiveDistanceWidget::Clear(this);
  if ( !v2 )
    return;
  if ( v2->minimapBlips.size > 1 )
    return;
  v3->mObjective = v2->mObjective;
  v4 = UFG::UIHKPlayerObjectiveManager::mInstance;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    return;
  UFG::UI::GetPlayerWorldPosition(&pos, &dir);
  v5 = v2->mObjective;
  v6 = &customWorldMapCaption;
  if ( v5 )
    v7 = v5->mLocationCaption.mText;
  else
    v7 = &customWorldMapCaption;
  v8 = UFG::qStringLength(v7);
  v22 = v8 == 0;
  v9 = v8 < 0;
  v10 = v2->mObjective;
  if ( v9 || v22 )
  {
    if ( v10 )
      v11 = v10->mCaption.mData;
    else
      v11 = v2->alternateCaption.mData;
  }
  else
  {
    if ( v10 )
      v6 = v10->mLocationCaption.mText;
    v11 = v6;
  }
  v3->mChanged = 1;
  UFG::qString::Set(&v3->mCaption, v11);
  v12 = v2->mObjective;
  if ( v12 )
  {
    v14 = UFG::Objective::GetFirstIndicator(v12);
    if ( v14 )
      v13 = (UFG::qSymbol *)&v14[1];
    else
      v13 = &UFG::gNullQSymbol;
  }
  else
  {
    v13 = &UFG::gNullQSymbol;
  }
  v3->mSimObjectID = (UFG::qSymbol)v13->mUID;
  v15 = (UFG::SimComponent *)UFG::UIHKPlayerObjective::GetSimObject(v2);
  if ( v15 )
  {
    UFG::qSafePointer<Creature,Creature>::operator=(
      (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v3->mTargetSimObj,
      v15);
    v22 = v3->mVisible == 1;
    v3->mVisible = 1;
    v3->mChanged |= !v22;
  }
  v16 = 0;
  target = 0i64;
  if ( v2->useFixedPos )
  {
    v17 = v2->fixedPos.x;
    v18 = v2->fixedPos.y;
    v19 = v2->fixedPos.z;
    v27.x = v2->fixedPos.x;
    v27.y = v18;
    v27.z = v19;
LABEL_28:
    v3->mChanged = 1;
    v3->mPosSet = 1;
    v3->mWorldPos.x = v17;
    v3->mWorldPos.y = v18;
    v3->mWorldPos.z = v19;
    v22 = v3->mVisible == 1;
    v3->mVisible = 1;
LABEL_31:
    v3->mChanged |= !v22;
    goto LABEL_32;
  }
  v20 = (UFG::HudComponent *)v2->gpsTarget.m_pPointer;
  if ( v20 )
    v21 = UFG::HudComponent::GetWorldPosition(v20, &v27);
  else
    v21 = UFG::UIHKPlayerObjectiveManager::GetObjectivePos(v4, v2, &v27, &target);
  if ( v21 )
  {
    v19 = v27.z;
    v18 = v27.y;
    v17 = v27.x;
    goto LABEL_28;
  }
  if ( !v3->mTargetSimObj.m_pPointer )
  {
    v22 = v3->mVisible == 0;
    v3->mVisible = 0;
    goto LABEL_31;
  }
LABEL_32:
  if ( UFG::UIHKScreenHud::mIconManager
    && v2->minimapBlips.size > 0
    && (v23 = UFG::BasePhysicsSystem::GetCollisionModel(
                (UFG::BasePhysicsSystem *)UFG::UIHKScreenHud::mIconManager,
                *v2->minimapBlips.p),
        (v24 = (CAkSrcPhysModel *)v23) != 0i64) )
  {
    v25 = UFG::UIMapBlip::GetColor((UFG::UIMapBlip *)v23);
    v3->mChanged = 1;
    v3->mColorChanged = 1;
    v3->mColor.r = v25->r;
    v3->mColor.g = v25->g;
    v3->mColor.b = v25->b;
    v3->mColor.a = v25->a;
    v26 = HIDWORD(UFG::UIMapBlip::GetType(v24)->vfptr);
    v3->mAssociatedIcon.mUID = v26;
    if ( v26 == UIBlipIcon_Waypoint_14.mUID )
      goto LABEL_67;
    if ( v26 == UIBlipIcon_Mission_Start_14.mUID )
    {
      v3->mAssociatedIconIndex = 4;
      return;
    }
    if ( v26 == UIBlipIcon_Mission_Objective_14.mUID )
    {
LABEL_67:
      v3->mAssociatedIconIndex = 3;
      return;
    }
    if ( v26 == UIBlipIcon_Case_Start_14.mUID || v26 == UIBlipIcon_Case_Objective_14.mUID )
    {
      v3->mAssociatedIconIndex = 35;
      return;
    }
    if ( v26 == UIBlipIcon_Social_14.mUID )
      goto LABEL_68;
    if ( v26 == UIBlipIcon_Cop_Event_Start_14.mUID )
    {
      v3->mAssociatedIconIndex = 37;
      return;
    }
    if ( v26 == UIBlipIcon_Event_Start_14.mUID || v26 == UIBlipIcon_Event_Objective_14.mUID )
    {
      v3->mAssociatedIconIndex = 36;
      return;
    }
    if ( v26 == UIBlipIcon_Race_Start_14.mUID || v26 == UIBlipIcon_Race_Start_Flag_14.mUID )
    {
      v3->mAssociatedIconIndex = 22;
      return;
    }
    if ( v26 == UIBlipIcon_Triad_Wars_14.mUID )
    {
      v3->mAssociatedIconIndex = 27;
      return;
    }
    if ( v26 != UIBlipIcon_Trapped_Ped_14.mUID && v26 != UIBlipIcon_Face_Character_14.mUID )
    {
      if ( v26 == UIBlipIcon_Massage_Parlors_14.mUID )
      {
        v3->mAssociatedIconIndex = 16;
      }
      else if ( v26 == UIBlipIcon_Fight_Club_14.mUID )
      {
        v3->mAssociatedIconIndex = 20;
      }
      else
      {
        if ( v26 == UIBlipIcon_Race_Objective_14.mUID )
          v16 = 14;
        v3->mAssociatedIconIndex = v16;
      }
    }
    else
    {
LABEL_68:
      v3->mAssociatedIconIndex = 30;
    }
  }
  else
  {
    v3->mAssociatedIconIndex = 0;
    v3->mChanged = 1;
    v3->mColorChanged = 1;
    v3->mColor.r = UFG::qColour::White.r;
    v3->mColor.g = UFG::qColour::White.g;
    v3->mColor.b = UFG::qColour::White.b;
    v3->mColor.a = UFG::qColour::White.a;
  }
}

// File Line: 656
// RVA: 0x5DFB10
void __fastcall UFG::UIHKObjectiveDistanceWidget::Flash_SetColor(UFG::UIHKObjectiveDistanceWidget *this, Scaleform::GFx::Movie *movie, UFG::qColour *color)
{
  Scaleform::GFx::Movie *v3; // rbx
  UFG::UIHKObjectiveDistanceWidget *v4; // r14
  signed int v5; // edi
  signed int v6; // esi
  signed int v7; // er15
  double v8; // xmm6_8
  char ptr; // [rsp+8h] [rbp-79h]
  __int64 v10; // [rsp+18h] [rbp-69h]
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-61h]
  double v12; // [rsp+28h] [rbp-59h]
  __int64 v13; // [rsp+30h] [rbp-51h]
  char v14; // [rsp+38h] [rbp-49h]
  __int64 v15; // [rsp+48h] [rbp-39h]
  unsigned int v16; // [rsp+50h] [rbp-31h]
  double v17; // [rsp+58h] [rbp-29h]
  char v18; // [rsp+68h] [rbp-19h]
  __int64 v19; // [rsp+78h] [rbp-9h]
  unsigned int v20; // [rsp+80h] [rbp-1h]
  double v21; // [rsp+88h] [rbp+7h]
  __int64 v22; // [rsp+98h] [rbp+17h]

  v22 = -2i64;
  v3 = movie;
  v4 = this;
  v5 = (signed int)(float)(color->r * 255.0);
  v6 = (signed int)(float)(color->g * 255.0);
  v7 = (signed int)(float)(color->b * 255.0);
  pDtor = (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value;
  `eh vector constructor iterator'(&v13, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)Scaleform::GFx::Value::~Value >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
      v10,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  LODWORD(pDtor) = 5;
  v12 = (double)(unsigned __int8)v5;
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
      v15,
      &v14,
      COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = (double)(unsigned __int8)v6;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
      v19,
      &v18,
      COERCE_DOUBLE(*(_QWORD *)&v21));
    v19 = 0i64;
  }
  v20 = 5;
  v21 = (double)(unsigned __int8)v7;
  Scaleform::GFx::Movie::Invoke(v3, "ObjectiveDist_SetColor", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  v8 = (double)(signed int)v4->mAssociatedIconIndex;
  if ( ((unsigned int)pDtor >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(
      v10,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v12 = v8;
  Scaleform::GFx::Movie::Invoke(v3, "ObjectiveDist_SetType", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

