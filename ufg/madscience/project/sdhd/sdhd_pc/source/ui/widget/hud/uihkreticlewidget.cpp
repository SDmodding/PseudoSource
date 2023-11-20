// File Line: 40
// RVA: 0x5EBEC0
void __fastcall UFG::UIHKReticleWidget::HandleScreenInit(UFG::UIHKReticleWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKReticleWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // r14
  EnumList<unsigned long> **v4; // rcx
  signed int v5; // edx
  signed int v6; // er8
  signed __int64 v7; // rsi
  signed __int64 v8; // r12
  signed __int64 v9; // r15
  const char *v10; // rbx
  char *v11; // rbx
  unsigned int v12; // edi
  float *v13; // rbx
  bool v14; // al
  Scaleform::GFx::Value pval; // [rsp+30h] [rbp-A8h]
  char ptr; // [rsp+60h] [rbp-78h]
  UFG::qString v17; // [rsp+68h] [rbp-70h]
  UFG::qString v18; // [rsp+90h] [rbp-48h]
  __int64 v19; // [rsp+B8h] [rbp-20h]
  UFG::qString v20; // [rsp+C0h] [rbp-18h]

  if ( screen )
  {
    v19 = -2i64;
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pval.pObjectInterface = 0i64;
      pval.Type = 0;
      Scaleform::GFx::Movie::GetVariable(v3, &pval, "mc_Reticle._visible");
      v2->mVisible = pval.mValue.BValue;
      Scaleform::GFx::Movie::GetVariable(v3, &pval, "mc_Reticle._x");
      v2->mScreenX = pval.mValue.NValue;
      Scaleform::GFx::Movie::GetVariable(v3, &pval, "mc_Reticle._y");
      v2->mScreenY = pval.mValue.NValue;
      UFG::qString::qString(&v20);
      `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v4 = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p;
      v5 = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size;
      if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
        v6 = 0;
      else
        v6 = (*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.size;
      v7 = 1i64;
      v8 = v6;
      if ( v6 > 1i64 )
      {
        v9 = (signed __int64)v2->mDefaultReticleOffset[1];
        while ( 1 )
        {
          if ( v5 < 0 )
            v10 = 0i64;
          else
            v10 = (*v4)->m_enumName.p[v7];
          UFG::qString::Set(&v20, v10);
          UFG::qString::qString(&v18, v10);
          UFG::qString::MakeLower(&v18);
          v11 = v20.mData;
          if ( (v17.mMagic >> 6) & 1 )
          {
            ((void (__fastcall *)(UFG::qNode<UFG::qString,UFG::qString> *, char *, unsigned __int64))v17.mNext->mPrev[1].mPrev)(
              v17.mNext,
              &ptr,
              pval.DataAux);
            v17.mNext = 0i64;
          }
          v17.mMagic = 6;
          pval.DataAux = (unsigned __int64)v11;
          Scaleform::GFx::Movie::Invoke(v3, "setReticleType", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
          UFG::qString::qString(&v17);
          v12 = 1;
          v13 = (float *)v9;
          do
          {
            UFG::qString::Format(&v17, "mc_Reticle.mc_outer.mc_ReticleType.mc_%s_%d._x", v18.mData, v12);
            Scaleform::GFx::Movie::GetVariable(v3, &pval, v17.mData);
            *v13 = pval.mValue.NValue;
            UFG::qString::Format(&v17, "mc_Reticle.mc_outer.mc_ReticleType.mc_%s_%d._y", v18.mData, v12);
            v14 = Scaleform::GFx::Movie::GetVariable(v3, &pval, v17.mData);
            if ( v14 )
              v13[1] = pval.mValue.NValue;
            ++v12;
            v13 += 2;
          }
          while ( v14 );
          UFG::qString::~qString(&v17);
          UFG::qString::~qString(&v18);
          ++v7;
          v9 += 32i64;
          if ( v7 >= v8 )
            break;
          v4 = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p;
          v5 = UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size;
        }
      }
      `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v20);
      if ( ((unsigned int)pval.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          *(_QWORD *)&pval.mValue.NValue);
    }
  }
}       pval.pObjectInterface,
          &pval,
     

// File Line: 107
// RVA: 0x616AC0
void __usercall UFG::UIHKReticleWidget::Update(UFG::UIHKReticleWidget *this@<rcx>, UFG::UIScreen *screen@<rdx>, float a3@<xmm0>)
{
  UFG::UIScreen *v3; // r14
  UFG::UIHKReticleWidget *v4; // rdi
  UFG::UIScreenRenderable *v5; // rsi
  Scaleform::GFx::Movie *v6; // rsi
  bool v7; // bl
  const char *v8; // rdx
  const char *v9; // rax
  char *v10; // rbx
  UFG::eFactionStandingEnum v11; // ecx
  int v12; // ecx
  const char *v13; // rdx
  char *v14; // rbx
  char *v15; // rbx
  float v16; // xmm6_4
  float v17; // xmm7_4
  Illusion::Target *v18; // rbx
  float v19; // xmm6_4
  float v20; // xmm7_4
  double v21; // xmm6_8
  double v22; // xmm6_8
  unsigned int v23; // eax
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  double v27; // xmm0_8
  const char *v28; // rdx
  int v29; // ebx
  __int64 v30; // r14
  int v31; // er15
  float v32; // xmm0_4
  float v33; // xmm0_4
  int v34; // ebx
  __int64 v35; // r14
  signed __int64 v36; // rcx
  float v37; // xmm6_4
  float v38; // xmm7_4
  int v39; // er15
  int v40; // ebx
  int v41; // ebx
  float v42; // xmm7_4
  float v43; // xmm6_4
  double v44; // xmm6_8
  char *v45; // rdx
  float v46; // xmm9_4
  int v47; // ebx
  __int64 v48; // r14
  signed __int64 v49; // rcx
  float v50; // xmm6_4
  float v51; // xmm7_4
  int v52; // er15
  int v53; // ebx
  int v54; // ebx
  float v55; // xmm6_4
  double v56; // xmm6_8
  float v57; // xmm7_4
  float v58; // xmm6_4
  double v59; // xmm6_8
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  char *v62; // [rsp+68h] [rbp-80h]
  __int64 v63; // [rsp+70h] [rbp-78h]
  char *ppathToVar; // [rsp+78h] [rbp-70h]
  __int64 v65; // [rsp+88h] [rbp-60h]
  unsigned int v66; // [rsp+90h] [rbp-58h]
  __int64 v67; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::Value v68; // [rsp+A8h] [rbp-40h]
  UFG::qString v69; // [rsp+D8h] [rbp-10h]
  UFG::qString result; // [rsp+100h] [rbp+18h]
  __int64 v71; // [rsp+128h] [rbp+40h]
  UFG::qString v72; // [rsp+130h] [rbp+48h]

  v71 = -2i64;
  v3 = screen;
  v4 = this;
  if ( this->mChanged )
  {
    v5 = screen->mRenderable;
    if ( v5->m_shouldRender )
    {
      v6 = v5->m_movie.pObject;
      if ( v6 )
      {
        this->mChanged = 0;
        value.pObjectInterface = 0i64;
        value.Type = 0;
        v7 = this->mVisible;
        value.Type = 2;
        value.mValue.BValue = v7;
        Scaleform::GFx::Movie::SetVariable(v6, "mc_Reticle._visible", &value, 1i64);
        if ( !v4->mVisible )
          goto LABEL_109;
        if ( !v4->mStateChanged )
        {
LABEL_16:
          if ( !v4->mFactionChanged )
          {
LABEL_29:
            if ( !v4->mTypeChanged )
            {
LABEL_37:
              v16 = v4->mScreenX;
              v17 = v4->mScreenY;
              v18 = Render::GetBackBufferTarget();
              ((void (*)(void))v3->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceTypeCode)();
              v19 = v16 * (float)((float)(signed int)a3 / (float)v18->mWidth);
              ((void (*)(void))v3->mRenderable->m_movieDef.pObject->vfptr[1].GetResourceReport)();
              v20 = v17 * (float)((float)(signed int)a3 / (float)v18->mHeight);
              v21 = v19;
              if ( ((unsigned int)value.Type >> 6) & 1 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                  value.pObjectInterface,
                  &value,
                  *(_QWORD *)&value.mValue.NValue);
                value.pObjectInterface = 0i64;
              }
              value.Type = 5;
              value.mValue.NValue = v21;
              Scaleform::GFx::Movie::SetVariable(v6, "mc_Reticle._x", &value, 1i64);
              v22 = v20;
              if ( ((unsigned int)value.Type >> 6) & 1 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                  value.pObjectInterface,
                  &value,
                  *(_QWORD *)&value.mValue.NValue);
                value.pObjectInterface = 0i64;
              }
              value.Type = 5;
              value.mValue.NValue = v22;
              Scaleform::GFx::Movie::SetVariable(v6, "mc_Reticle._y", &value, 1i64);
              v23 = (unsigned int)value.Type >> 6;
              if ( v4->mHasAmmo
                && (v24 = v4->mfSizeMax,
                    v25 = (float)((float)(v4->mfSizeMax - v4->mfSizeMin) * 0.69999999) + v4->mfSizeMin,
                    v26 = v4->mfSizeCurrent,
                    v26 > v25) )
              {
                if ( v23 & 1 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    *(_QWORD *)&value.mValue.NValue);
                  value.pObjectInterface = 0i64;
                }
                v27 = (float)(100.0 - (float)((float)((float)(v26 - v25) / (float)(v24 - v25)) * 100.0));
              }
              else
              {
                if ( v23 & 1 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    *(_QWORD *)&value.mValue.NValue);
                  value.pObjectInterface = 0i64;
                }
                v27 = DOUBLE_100_0;
              }
              value.Type = 5;
              value.mValue.NValue = v27;
              Scaleform::GFx::Movie::SetVariable(v6, "mc_Reticle._alpha", &value, 1i64);
              if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
                v28 = 0i64;
              else
                v28 = (*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.p[v4->mType];
              UFG::qString::qString(&v72, v28);
              UFG::qString::MakeLower(&v72);
              UFG::qString::FormatEx(&result, "mc_Reticle.mc_outer.mc_ReticleType.mc_%s", v72.mData);
              v68.pObjectInterface = 0i64;
              v68.Type = 0;
              v65 = 0i64;
              v66 = 0;
              if ( v4->mType != 1 )
              {
                if ( v4->mType != 2 )
                {
                  if ( v4->mType == 3 )
                  {
                    v29 = 0;
                    v30 = 0i64;
                    while ( 1 )
                    {
                      v31 = v29 + 1;
                      UFG::qString::FormatEx(&v69, "%s_%d._x", result.mData, (unsigned int)(v29 + 1));
                      UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._y", result.mData, (unsigned int)(v29 + 1));
                      v32 = v4->mDefaultReticleOffset[0][v30 + 4i64 * v4->mType].x;
                      if ( !v29 )
                        break;
                      if ( v29 == 1 )
                      {
                        v33 = (float)(v32 - 9.0) + v4->mRadius;
LABEL_60:
                        if ( ((unsigned int)value.Type >> 6) & 1 )
                        {
                          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                            value.pObjectInterface,
                            &value,
                            *(_QWORD *)&value.mValue.NValue);
                          value.pObjectInterface = 0i64;
                        }
                        value.Type = 5;
                        value.mValue.NValue = v33;
                        Scaleform::GFx::Movie::SetVariable(v6, v69.mData, &value, 1i64);
                      }
                      UFG::qString::~qString((UFG::qString *)&ptr);
                      UFG::qString::~qString(&v69);
                      ++v29;
                      ++v30;
                      if ( v31 >= 2 )
                        goto LABEL_104;
                    }
                    v33 = (float)(v32 + 9.0) - v4->mRadius;
                    goto LABEL_60;
                  }
LABEL_104:
                  if ( (v66 >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(__int64, char **, __int64))(*(_QWORD *)v65 + 16i64))(v65, &ppathToVar, v67);
                    v65 = 0i64;
                  }
                  v66 = 0;
                  if ( ((unsigned int)v68.Type >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v68.pObjectInterface->vfptr->gap8[8])(
                      v68.pObjectInterface,
                      &v68,
                      *(_QWORD *)&v68.mValue.NValue);
                    v68.pObjectInterface = 0i64;
                  }
                  v68.Type = 0;
                  UFG::qString::~qString(&result);
                  UFG::qString::~qString(&v72);
                  goto LABEL_109;
                }
                v34 = 0;
                v35 = 0i64;
                while ( 1 )
                {
                  v36 = v35 + 4i64 * v4->mType;
                  v37 = v4->mDefaultReticleOffset[0][v36].x;
                  v38 = v4->mDefaultReticleOffset[0][v36].y;
                  v39 = v34 + 1;
                  UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._x", result.mData, (unsigned int)(v34 + 1));
                  UFG::qString::FormatEx(&v69, "%s_%d._y", result.mData, (unsigned int)(v34 + 1));
                  if ( !v34 )
                    break;
                  v40 = v34 - 1;
                  if ( !v40 )
                  {
                    v43 = v37 - v4->mRadius;
LABEL_72:
                    v44 = v43;
                    if ( ((unsigned int)value.Type >> 6) & 1 )
                    {
                      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                        value.pObjectInterface,
                        &value,
                        *(_QWORD *)&value.mValue.NValue);
                      value.pObjectInterface = 0i64;
                    }
                    v45 = ppathToVar;
LABEL_80:
                    value.Type = 5;
                    value.mValue.NValue = v44;
                    Scaleform::GFx::Movie::SetVariable(v6, v45, &value, 1i64);
                    goto LABEL_81;
                  }
                  v41 = v40 - 1;
                  if ( !v41 )
                  {
                    v43 = v37 + v4->mRadius;
                    goto LABEL_72;
                  }
                  if ( v41 == 1 )
                  {
                    v42 = v38 + v4->mRadius;
                    goto LABEL_77;
                  }
LABEL_81:
                  UFG::qString::~qString(&v69);
                  UFG::qString::~qString((UFG::qString *)&ptr);
                  v34 = v39;
                  ++v35;
                  if ( v39 >= 4 )
                    goto LABEL_104;
                }
                v42 = v38 - v4->mRadius;
LABEL_77:
                v44 = v42;
                if ( ((unsigned int)value.Type >> 6) & 1 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                    value.pObjectInterface,
                    &value,
                    *(_QWORD *)&value.mValue.NValue);
                  value.pObjectInterface = 0i64;
                }
                v45 = v69.mData;
                goto LABEL_80;
              }
              v46 = v4->mRadius;
              if ( v46 <= 7.0 )
                v46 = FLOAT_7_0;
              v47 = 0;
              v48 = 0i64;
              while ( 1 )
              {
                v49 = v48 + 4i64 * v4->mType;
                v50 = v4->mDefaultReticleOffset[0][v49].x;
                v51 = v4->mDefaultReticleOffset[0][v49].y;
                v52 = v47 + 1;
                UFG::qString::FormatEx(&v69, "%s_%d._x", result.mData, (unsigned int)(v47 + 1));
                UFG::qString::FormatEx((UFG::qString *)&ptr, "%s_%d._y", result.mData, (unsigned int)(v47 + 1));
                if ( !v47 )
                  break;
                v53 = v47 - 1;
                if ( !v53 )
                {
                  v58 = (float)(v50 - 7.0) + v46;
LABEL_97:
                  v56 = v58;
                  if ( ((unsigned int)v68.Type >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v68.pObjectInterface->vfptr->gap8[8])(
                      v68.pObjectInterface,
                      &v68,
                      *(_QWORD *)&v68.mValue.NValue);
                    v68.pObjectInterface = 0i64;
                  }
                  v57 = (float)(v51 + 7.0) - v46;
                  goto LABEL_100;
                }
                v54 = v53 - 1;
                if ( !v54 )
                {
                  v55 = (float)(v50 + 7.0) - v46;
LABEL_91:
                  v56 = v55;
                  if ( ((unsigned int)v68.Type >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v68.pObjectInterface->vfptr->gap8[8])(
                      v68.pObjectInterface,
                      &v68,
                      *(_QWORD *)&v68.mValue.NValue);
                    v68.pObjectInterface = 0i64;
                  }
                  v57 = (float)(v51 - 7.0) + v46;
LABEL_100:
                  v68.mValue.NValue = v56;
                  v59 = v57;
                  v68.Type = 5;
                  if ( (v66 >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(__int64, char **, __int64))(*(_QWORD *)v65 + 16i64))(v65, &ppathToVar, v67);
                    v65 = 0i64;
                  }
                  v67 = *(_QWORD *)&v59;
                  v66 = 5;
                  goto LABEL_103;
                }
                if ( v54 == 1 )
                {
                  v55 = (float)(v50 - 7.0) + v46;
                  goto LABEL_91;
                }
LABEL_103:
                Scaleform::GFx::Movie::SetVariable(v6, v69.mData, &v68, 1i64);
                Scaleform::GFx::Movie::SetVariable(v6, ppathToVar, (Scaleform::GFx::Value *)&ppathToVar, 1i64);
                UFG::qString::~qString((UFG::qString *)&ptr);
                UFG::qString::~qString(&v69);
                v47 = v52;
                ++v48;
                if ( v52 >= 4 )
                  goto LABEL_104;
              }
              v58 = (float)(v50 + 7.0) - v46;
              goto LABEL_97;
            }
            v4->mTypeChanged = 0;
            if ( v4->mType )
            {
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              if ( (UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.size & 0x80000000) != 0 )
                v15 = 0i64;
              else
                v15 = (*UFG::gSimObjectWeaponReticleTracksEnum.m_enumLists.p)->m_enumName.p[v4->mType];
              if ( ((unsigned int)ppathToVar >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v63 + 16i64))(v63, &ptr, v62);
                v63 = 0i64;
              }
              LODWORD(ppathToVar) = 6;
              v62 = v15;
              Scaleform::GFx::Movie::Invoke(v6, "setReticleType", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                1,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
              goto LABEL_37;
            }
LABEL_109:
            if ( ((unsigned int)value.Type >> 6) & 1 )
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
                value.pObjectInterface,
                &value,
                *(_QWORD *)&value.mValue.NValue);
            return;
          }
          v4->mFactionChanged = 0;
          UFG::qString::qString(&v69);
          `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          v11 = v4->mTargetFaction;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( v12 )
            {
              if ( v12 != 1 )
              {
LABEL_24:
                if ( v4->mHighlightMode == 1 )
                  UFG::qString::Set(&v69, "enemy");
                v14 = v69.mData;
                if ( ((unsigned int)ppathToVar >> 6) & 1 )
                {
                  (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v63 + 16i64))(v63, &ptr, v62);
                  v63 = 0i64;
                }
                LODWORD(ppathToVar) = 6;
                v62 = v14;
                Scaleform::GFx::Movie::Invoke(v6, "setReticleFaction", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
                `eh vector destructor iterator(
                  &ptr,
                  0x30ui64,
                  1,
                  (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
                UFG::qString::~qString(&v69);
                goto LABEL_29;
              }
              v13 = "enemy";
            }
            else
            {
              v13 = "normal";
            }
          }
          else
          {
            v13 = "ped";
          }
          UFG::qString::Set(&v69, v13);
          goto LABEL_24;
        }
        *(_WORD *)&v4->mStateChanged = 256;
        UFG::qString::qString(&v69, &customWorldMapCaption);
        UFG::GameStatTracker::Instance();
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        if ( v4->mState == 2 )
        {
          v9 = "free_aim";
        }
        else
        {
          if ( v4->mState != 3 )
          {
            v8 = "hide";
LABEL_13:
            UFG::qString::Set(&v69, v8);
            v10 = v69.mData;
            if ( ((unsigned int)ppathToVar >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v63 + 16i64))(v63, &ptr, v62);
              v63 = 0i64;
            }
            LODWORD(ppathToVar) = 6;
            v62 = v10;
            Scaleform::GFx::Movie::Invoke(v6, "setReticleState", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              1,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v69);
            goto LABEL_16;
          }
          v9 = "locked_aim";
        }
        v8 = "empty_clip";
        if ( v4->mHasAmmo )
          v8 = v9;
        goto LABEL_13;
      }
    }
  }
}

