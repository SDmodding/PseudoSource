// File Line: 40
// RVA: 0x5EBEC0
void __fastcall UFG::UIHKReticleWidget::HandleScreenInit(UFG::UIHKReticleWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // r14
  EnumList<unsigned long> **p; // rcx
  signed int size; // edx
  signed int v6; // r8d
  __int64 v7; // rsi
  __int64 v8; // r12
  UFG::qVector2 *v9; // r15
  const char *v10; // rbx
  char *mData; // rbx
  unsigned int v12; // edi
  float *v13; // rbx
  bool Variable; // al
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-78h] BYREF
  UFG::qString v17; // [rsp+90h] [rbp-48h] BYREF
  __int64 v18; // [rsp+B8h] [rbp-20h]
  UFG::qString v19; // [rsp+C0h] [rbp-18h] BYREF

  if ( screen )
  {
    v18 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "mc_Reticle._visible");
      this->mVisible = pval.mValue.BValue;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "mc_Reticle._x");
      this->mScreenX = pval.mValue.NValue;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "mc_Reticle._y");
      this->mScreenY = pval.mValue.NValue;
      UFG::qString::qString(&v19);
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      p = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p;
      size = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size;
      if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
        v6 = 0;
      else
        v6 = (*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.size;
      v7 = 1i64;
      v8 = v6;
      if ( v6 > 1i64 )
      {
        v9 = this->mDefaultReticleOffset[1];
        while ( 1 )
        {
          if ( size < 0 )
            v10 = 0i64;
          else
            v10 = (*p)->m_enumName.p[v7];
          UFG::qString::Set(&v19, v10);
          UFG::qString::qString(&v17, v10);
          UFG::qString::MakeLower(&v17);
          mData = v19.mData;
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              pval.DataAux);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_String;
          pval.DataAux = (unsigned __int64)mData;
          Scaleform::GFx::Movie::Invoke(pObject, "setReticleType", 0i64, &ptr, 1u);
          UFG::qString::qString((UFG::qString *)&ptr.8);
          v12 = 1;
          v13 = (float *)v9;
          do
          {
            UFG::qString::Format(
              (UFG::qString *)&ptr.8,
              "mc_Reticle.mc_outer.mc_ReticleType.mc_%s_%d._x",
              v17.mData,
              v12);
            Scaleform::GFx::Movie::GetVariable(pObject, &pval, ptr.mValue.pString);
            *v13 = pval.mValue.NValue;
            UFG::qString::Format(
              (UFG::qString *)&ptr.8,
              "mc_Reticle.mc_outer.mc_ReticleType.mc_%s_%d._y",
              v17.mData,
              v12);
            Variable = Scaleform::GFx::Movie::GetVariable(pObject, &pval, ptr.mValue.pString);
            if ( Variable )
              v13[1] = pval.mValue.NValue;
            ++v12;
            v13 += 2;
          }
          while ( Variable );
          UFG::qString::~qString((UFG::qString *)&ptr.8);
          UFG::qString::~qString(&v17);
          ++v7;
          v9 += 4;
          if ( v7 >= v8 )
            break;
          p = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p;
          size = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size;
        }
      }
      `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v19);
      if ( (pval.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
    }
  }
}

// File Line: 107
// RVA: 0x616AC0
void __fastcall UFG::UIHKReticleWidget::Update(UFG::UIHKReticleWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreenRenderable *mRenderable; // rsi
  Scaleform::GFx::Movie *pObject; // rsi
  bool mVisible; // bl
  const char *v7; // rdx
  const char *v8; // rax
  char *v9; // rbx
  UFG::eFactionStandingEnum mTargetFaction; // ecx
  __int32 v11; // ecx
  const char *v12; // rdx
  char *v13; // rbx
  Scaleform::GFx::Value *v14; // rbx
  float mScreenX; // xmm6_4
  float mScreenY; // xmm7_4
  Illusion::Target *BackBufferTarget; // rbx
  float v18; // xmm6_4
  float v19; // xmm7_4
  Scaleform::GFx::Value::ValueUnion v20; // xmm6_8
  float mfSizeMax; // xmm3_4
  float v22; // xmm1_4
  float mfSizeCurrent; // xmm2_4
  Scaleform::GFx::Value::ValueUnion v24; // xmm0_8
  int v25; // ebx
  __int64 v26; // r14
  int v27; // r15d
  float x; // xmm0_4
  float v29; // xmm0_4
  int v30; // ebx
  __int64 v31; // r14
  __int64 v32; // rcx
  float v33; // xmm6_4
  float y; // xmm7_4
  int v35; // r15d
  int v36; // ebx
  int v37; // ebx
  float v38; // xmm7_4
  float v39; // xmm6_4
  Scaleform::GFx::Value::ValueUnion v40; // xmm6_8
  char *mData; // rdx
  float mRadius; // xmm9_4
  int v43; // ebx
  __int64 v44; // r14
  __int64 v45; // rcx
  float v46; // xmm6_4
  float v47; // xmm7_4
  int v48; // r15d
  int v49; // ebx
  int v50; // ebx
  float v51; // xmm6_4
  Scaleform::GFx::Value::ValueUnion v52; // xmm6_8
  float v53; // xmm7_4
  float v54; // xmm6_4
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v57; // [rsp+90h] [rbp-58h]
  double v58; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::Value v59; // [rsp+A8h] [rbp-40h] BYREF
  UFG::qString v60; // [rsp+D8h] [rbp-10h] BYREF
  UFG::qString result; // [rsp+100h] [rbp+18h] BYREF
  __int64 v62; // [rsp+128h] [rbp+40h]
  UFG::qString v63; // [rsp+130h] [rbp+48h] BYREF

  v62 = -2i64;
  if ( this->mChanged )
  {
    mRenderable = screen->mRenderable;
    if ( mRenderable->m_shouldRender )
    {
      pObject = mRenderable->m_movie.pObject;
      if ( pObject )
      {
        this->mChanged = 0;
        value.pObjectInterface = 0i64;
        value.Type = VT_Undefined;
        mVisible = this->mVisible;
        value.Type = VT_Boolean;
        value.mValue.BValue = mVisible;
        Scaleform::GFx::Movie::SetVariable(pObject, "mc_Reticle._visible", &value, 1i64);
        if ( !this->mVisible )
          goto LABEL_109;
        if ( !this->mStateChanged )
        {
LABEL_16:
          if ( !this->mFactionChanged )
          {
LABEL_29:
            if ( !this->mTypeChanged )
            {
LABEL_37:
              mScreenX = this->mScreenX;
              mScreenY = this->mScreenY;
              BackBufferTarget = Render::GetBackBufferTarget();
              v18 = mScreenX
                  * (float)((float)(int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)(screen->mRenderable->m_movieDef.pObject)
                          / (float)BackBufferTarget->mWidth);
              v19 = mScreenY
                  * (float)((float)(int)((float (__fastcall *)(Scaleform::GFx::MovieDef *))screen->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)(screen->mRenderable->m_movieDef.pObject)
                          / (float)BackBufferTarget->mHeight);
              v20.NValue = v18;
              if ( (value.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                  value.pObjectInterface,
                  &value,
                  value.mValue);
                value.pObjectInterface = 0i64;
              }
              value.Type = VT_Number;
              value.mValue = v20;
              Scaleform::GFx::Movie::SetVariable(pObject, "mc_Reticle._x", &value, 1i64);
              if ( (value.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                  value.pObjectInterface,
                  &value,
                  value.mValue);
                value.pObjectInterface = 0i64;
              }
              value.Type = VT_Number;
              value.mValue.NValue = v19;
              Scaleform::GFx::Movie::SetVariable(pObject, "mc_Reticle._y", &value, 1i64);
              if ( this->mHasAmmo
                && (mfSizeMax = this->mfSizeMax,
                    v22 = (float)((float)(mfSizeMax - this->mfSizeMin) * 0.69999999) + this->mfSizeMin,
                    mfSizeCurrent = this->mfSizeCurrent,
                    mfSizeCurrent > v22) )
              {
                if ( (value.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    value.mValue);
                  value.pObjectInterface = 0i64;
                }
                v24.NValue = (float)(100.0
                                   - (float)((float)((float)(mfSizeCurrent - v22) / (float)(mfSizeMax - v22)) * 100.0));
              }
              else
              {
                if ( (value.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    value.mValue);
                  value.pObjectInterface = 0i64;
                }
                v24.NValue = DOUBLE_100_0;
              }
              value.Type = VT_Number;
              value.mValue = v24;
              Scaleform::GFx::Movie::SetVariable(pObject, "mc_Reticle._alpha", &value, 1i64);
              if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
                UFG::qString::qString(&v63, 0i64);
              else
                UFG::qString::qString(
                  &v63,
                  (*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.p[this->mType]);
              UFG::qString::MakeLower(&v63);
              UFG::qString::FormatEx(&result, "mc_Reticle.mc_outer.mc_ReticleType.mc_%s", v63.mData);
              v59.pObjectInterface = 0i64;
              v59.Type = VT_Undefined;
              ptr.DataAux = 0i64;
              v57 = 0;
              if ( this->mType != 1 )
              {
                if ( this->mType != 2 )
                {
                  if ( this->mType == 3 )
                  {
                    v25 = 0;
                    v26 = 0i64;
                    while ( 1 )
                    {
                      v27 = v25 + 1;
                      UFG::qString::FormatEx(&v60, "%s_%d._x", result.mData, (unsigned int)(v25 + 1));
                      UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._y", result.mData, (unsigned int)(v25 + 1));
                      x = this->mDefaultReticleOffset[this->mType][v26].x;
                      if ( !v25 )
                        break;
                      if ( v25 == 1 )
                      {
                        v29 = (float)(x - 9.0) + this->mRadius;
LABEL_60:
                        if ( (value.Type & 0x40) != 0 )
                        {
                          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                            value.pObjectInterface,
                            &value,
                            value.mValue);
                          value.pObjectInterface = 0i64;
                        }
                        value.Type = VT_Number;
                        value.mValue.NValue = v29;
                        Scaleform::GFx::Movie::SetVariable(pObject, v60.mData, &value, 1i64);
                      }
                      UFG::qString::~qString((UFG::qString *)&ptr);
                      UFG::qString::~qString(&v60);
                      ++v25;
                      ++v26;
                      if ( v27 >= 2 )
                        goto LABEL_104;
                    }
                    v29 = (float)(x + 9.0) - this->mRadius;
                    goto LABEL_60;
                  }
LABEL_104:
                  if ( (v57 & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, double))(*(_QWORD *)ptr.DataAux + 16i64))(
                      ptr.DataAux,
                      &ptr.Type,
                      COERCE_DOUBLE(*(_QWORD *)&v58));
                    ptr.DataAux = 0i64;
                  }
                  v57 = 0;
                  if ( (v59.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v59.pObjectInterface->vfptr->gap8[8])(
                      v59.pObjectInterface,
                      &v59,
                      v59.mValue);
                    v59.pObjectInterface = 0i64;
                  }
                  v59.Type = VT_Undefined;
                  UFG::qString::~qString(&result);
                  UFG::qString::~qString(&v63);
                  goto LABEL_109;
                }
                v30 = 0;
                v31 = 0i64;
                while ( 1 )
                {
                  v32 = v31 + 4i64 * this->mType;
                  v33 = this->mDefaultReticleOffset[0][v32].x;
                  y = this->mDefaultReticleOffset[0][v32].y;
                  v35 = v30 + 1;
                  UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._x", result.mData, (unsigned int)(v30 + 1));
                  UFG::qString::FormatEx(&v60, "%s_%d._y", result.mData, (unsigned int)(v30 + 1));
                  if ( !v30 )
                    break;
                  v36 = v30 - 1;
                  if ( !v36 )
                  {
                    v39 = v33 - this->mRadius;
LABEL_72:
                    v40.NValue = v39;
                    if ( (value.Type & 0x40) != 0 )
                    {
                      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                        value.pObjectInterface,
                        &value,
                        value.mValue);
                      value.pObjectInterface = 0i64;
                    }
                    mData = *(char **)&ptr.Type;
LABEL_80:
                    value.Type = VT_Number;
                    value.mValue = v40;
                    Scaleform::GFx::Movie::SetVariable(pObject, mData, &value, 1i64);
                    goto LABEL_81;
                  }
                  v37 = v36 - 1;
                  if ( !v37 )
                  {
                    v39 = v33 + this->mRadius;
                    goto LABEL_72;
                  }
                  if ( v37 == 1 )
                  {
                    v38 = y + this->mRadius;
                    goto LABEL_77;
                  }
LABEL_81:
                  UFG::qString::~qString(&v60);
                  UFG::qString::~qString((UFG::qString *)&ptr);
                  v30 = v35;
                  ++v31;
                  if ( v35 >= 4 )
                    goto LABEL_104;
                }
                v38 = y - this->mRadius;
LABEL_77:
                v40.NValue = v38;
                if ( (value.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    value.mValue);
                  value.pObjectInterface = 0i64;
                }
                mData = v60.mData;
                goto LABEL_80;
              }
              mRadius = this->mRadius;
              if ( mRadius <= 7.0 )
                mRadius = FLOAT_7_0;
              v43 = 0;
              v44 = 0i64;
              while ( 1 )
              {
                v45 = v44 + 4i64 * this->mType;
                v46 = this->mDefaultReticleOffset[0][v45].x;
                v47 = this->mDefaultReticleOffset[0][v45].y;
                v48 = v43 + 1;
                UFG::qString::FormatEx(&v60, "%s_%d._x", result.mData, (unsigned int)(v43 + 1));
                UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._y", result.mData, (unsigned int)(v43 + 1));
                if ( !v43 )
                  break;
                v49 = v43 - 1;
                if ( !v49 )
                {
                  v54 = (float)(v46 - 7.0) + mRadius;
LABEL_97:
                  v52.NValue = v54;
                  if ( (v59.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v59.pObjectInterface->vfptr->gap8[8])(
                      v59.pObjectInterface,
                      &v59,
                      v59.mValue);
                    v59.pObjectInterface = 0i64;
                  }
                  v53 = (float)(v47 + 7.0) - mRadius;
                  goto LABEL_100;
                }
                v50 = v49 - 1;
                if ( !v50 )
                {
                  v51 = (float)(v46 + 7.0) - mRadius;
LABEL_91:
                  v52.NValue = v51;
                  if ( (v59.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v59.pObjectInterface->vfptr->gap8[8])(
                      v59.pObjectInterface,
                      &v59,
                      v59.mValue);
                    v59.pObjectInterface = 0i64;
                  }
                  v53 = (float)(v47 - 7.0) + mRadius;
LABEL_100:
                  v59.mValue = v52;
                  v59.Type = VT_Number;
                  if ( (v57 & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, double))(*(_QWORD *)ptr.DataAux + 16i64))(
                      ptr.DataAux,
                      &ptr.Type,
                      COERCE_DOUBLE(*(_QWORD *)&v58));
                    ptr.DataAux = 0i64;
                  }
                  v58 = v53;
                  v57 = 5;
                  goto LABEL_103;
                }
                if ( v50 == 1 )
                {
                  v51 = (float)(v46 - 7.0) + mRadius;
                  goto LABEL_91;
                }
LABEL_103:
                Scaleform::GFx::Movie::SetVariable(pObject, v60.mData, &v59, 1i64);
                Scaleform::GFx::Movie::SetVariable(
                  pObject,
                  *(const char **)&ptr.Type,
                  (Scaleform::GFx::Value *)&ptr.Type,
                  1i64);
                UFG::qString::~qString((UFG::qString *)&ptr);
                UFG::qString::~qString(&v60);
                v43 = v48;
                ++v44;
                if ( v48 >= 4 )
                  goto LABEL_104;
              }
              v54 = (float)(v46 + 7.0) - mRadius;
              goto LABEL_97;
            }
            this->mTypeChanged = 0;
            if ( this->mType )
            {
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
                v14 = 0i64;
              else
                v14 = (Scaleform::GFx::Value *)(*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.p[this->mType];
              if ( (ptr.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
                  ptr.pObjectInterface,
                  &ptr,
                  ptr.pNext);
                ptr.pObjectInterface = 0i64;
              }
              ptr.Type = VT_String;
              ptr.pNext = v14;
              Scaleform::GFx::Movie::Invoke(pObject, "setReticleType", 0i64, &ptr, 1u);
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
              goto LABEL_37;
            }
LABEL_109:
            if ( (value.Type & 0x40) != 0 )
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                value.mValue);
            return;
          }
          this->mFactionChanged = 0;
          UFG::qString::qString(&v60);
          `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          mTargetFaction = this->mTargetFaction;
          if ( mTargetFaction )
          {
            v11 = mTargetFaction - 1;
            if ( v11 )
            {
              if ( v11 != 1 )
              {
LABEL_24:
                if ( this->mHighlightMode == eHIGHLIGHT_MODE_EXPLODABLE )
                  UFG::qString::Set(&v60, "enemy");
                v13 = v60.mData;
                if ( (ptr.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
                    ptr.pObjectInterface,
                    &ptr,
                    ptr.pNext);
                  ptr.pObjectInterface = 0i64;
                }
                ptr.Type = VT_String;
                ptr.pNext = (Scaleform::GFx::Value *)v13;
                Scaleform::GFx::Movie::Invoke(pObject, "setReticleFaction", 0i64, &ptr, 1u);
                `eh vector destructor iterator(
                  &ptr,
                  0x30ui64,
                  1,
                  (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
                UFG::qString::~qString(&v60);
                goto LABEL_29;
              }
              v12 = "enemy";
            }
            else
            {
              v12 = "normal";
            }
          }
          else
          {
            v12 = "ped";
          }
          UFG::qString::Set(&v60, v12);
          goto LABEL_24;
        }
        *(_WORD *)&this->mStateChanged = 256;
        UFG::qString::qString(&v60, &customCaption);
        UFG::GameStatTracker::Instance();
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( this->mState == STATE_DANGER )
        {
          v8 = "free_aim";
        }
        else
        {
          if ( this->mState != STATE_COMPLETE )
          {
            v7 = "hide";
LABEL_13:
            UFG::qString::Set(&v60, v7);
            v9 = v60.mData;
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.pNext);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_String;
            ptr.pNext = (Scaleform::GFx::Value *)v9;
            Scaleform::GFx::Movie::Invoke(pObject, "setReticleState", 0i64, &ptr, 1u);
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v60);
            goto LABEL_16;
          }
          v8 = "locked_aim";
        }
        v7 = "empty_clip";
        if ( this->mHasAmmo )
          v7 = v8;
        goto LABEL_13;
      }
    }
  }
}

