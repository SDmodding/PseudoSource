// File Line: 44
// RVA: 0x5EB9E0
void __fastcall UFG::UIHKMapLabelManager::HandleScreenInit(UFG::UIHKMapLabelManager *this, UFG::UIScreen *pScreen)
{
  UFG::UIHKMapLabelManager *v2; // rdi
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int v7; // er12
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // esi
  __int64 v14; // r14
  __int64 v15; // r15
  char *v16; // rax
  UFG::qPropertySet *v17; // rbx
  UFG::qSymbol *v18; // rax
  char *v19; // rax
  UFG::qSymbol *v20; // rax
  float *v21; // rax
  float v22; // xmm9_4
  UFG::qSymbol *v23; // rax
  float *v24; // rax
  float v25; // xmm8_4
  UFG::qSymbol *v26; // rax
  float *v27; // rax
  float v28; // xmm7_4
  UFG::qSymbol *v29; // rax
  float *v30; // rax
  float v31; // xmm6_4
  UFG::qSymbol *v32; // rax
  char *v33; // rax
  const char *v34; // rbx
  char *v35; // rbx
  Scaleform::GFx::Movie *v36; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol v37; // [rsp+38h] [rbp-C8h]
  UFG::qSymbol v38; // [rsp+3Ch] [rbp-C4h]
  UFG::qSymbol v39; // [rsp+40h] [rbp-C0h]
  UFG::qSymbol v40; // [rsp+44h] [rbp-BCh]
  char ptr; // [rsp+50h] [rbp-B0h]
  __int64 v42; // [rsp+60h] [rbp-A0h]
  unsigned int v43; // [rsp+68h] [rbp-98h]
  const char *v44; // [rsp+70h] [rbp-90h]
  char v45; // [rsp+80h] [rbp-80h]
  __int64 v46; // [rsp+90h] [rbp-70h]
  unsigned int v47; // [rsp+98h] [rbp-68h]
  char *v48; // [rsp+A0h] [rbp-60h]
  __int64 v49; // [rsp+B0h] [rbp-50h]
  UFG::qString v50; // [rsp+B8h] [rbp-48h]
  UFG::qString v51; // [rsp+E0h] [rbp-20h]
  UFG::qSymbol result; // [rsp+198h] [rbp+98h]
  UFG::qSymbol v53; // [rsp+1A0h] [rbp+A0h]
  UFG::qSymbol v54; // [rsp+1A8h] [rbp+A8h]

  if ( pScreen )
  {
    v49 = -2i64;
    v2 = this;
    v36 = pScreen->mRenderable->m_movie.pObject;
    if ( v36 )
    {
      v3 = UFG::qSymbol::create_from_string(&result, "UI-MapLabels");
      v4 = UFG::PropertySetManager::GetPropertySet(v3);
      v2->mPSSetData = v4;
      if ( v4 )
      {
        v5 = UFG::qSymbol::create_from_string(&result, "mapLabels");
        v6 = PropertyUtils::Get<UFG::qPropertyList>(v2->mPSSetData, v5, DEPTH_RECURSE);
        if ( v6 )
        {
          UFG::qArray<UFG::UIHKMapLabelData,0>::~qArray<UFG::UIHKMapLabelData,0>(&v2->mData);
          v2->mNumLabels = 0;
          v7 = v6->mNumElements;
          v8 = v2->mData.size;
          if ( (signed int)(v6->mNumElements - v2->mData.size) <= 0 )
          {
            v12 = v2->mData.size - v6->mNumElements;
            if ( v2->mData.size != v6->mNumElements )
            {
              if ( v12 < v8 )
                v2->mData.size = v8 - v12;
              else
                v2->mData.size = 0;
            }
          }
          else
          {
            v9 = v6->mNumElements;
            v10 = v2->mData.capacity;
            if ( v9 > v10 )
            {
              if ( v10 )
                v11 = 2 * v10;
              else
                v11 = 1;
              for ( ; v11 < v9; v11 *= 2 )
                ;
              if ( v11 - v9 > 0x10000 )
                v11 = v9 + 0x10000;
              UFG::qArray<UFG::UIHKMapLabelData,0>::Reallocate(&v2->mData, v11, "mData");
            }
            v2->mData.size = v9;
          }
          v2->mNumLabels = v7;
          v13 = 0;
          if ( v7 )
          {
            v14 = 0i64;
            v15 = 0i64;
            do
            {
              v16 = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v13);
              if ( v16 && *(_QWORD *)v16 )
                v17 = (UFG::qPropertySet *)&v16[*(_QWORD *)v16];
              else
                v17 = 0i64;
              v18 = UFG::qSymbol::create_from_string(&v53, "text");
              v19 = PropertyUtils::Get<char const *>(v17, v18, DEPTH_RECURSE);
              UFG::qString::qString(&v50, v19);
              v20 = UFG::qSymbol::create_from_string(&v54, "pos_x");
              v21 = UFG::qPropertySet::Get<float>(v17, v20, DEPTH_RECURSE);
              if ( v21 )
                v22 = *v21;
              else
                v22 = 0.0;
              v23 = UFG::qSymbol::create_from_string(&v37, "pos_y");
              v24 = UFG::qPropertySet::Get<float>(v17, v23, DEPTH_RECURSE);
              if ( v24 )
                v25 = *v24;
              else
                v25 = 0.0;
              v26 = UFG::qSymbol::create_from_string(&v39, "min_zoom");
              v27 = UFG::qPropertySet::Get<float>(v17, v26, DEPTH_RECURSE);
              if ( v27 )
                v28 = *v27;
              else
                v28 = 0.0;
              v29 = UFG::qSymbol::create_from_string(&v40, "max_zoom");
              v30 = UFG::qPropertySet::Get<float>(v17, v29, DEPTH_RECURSE);
              if ( v30 )
                v31 = *v30;
              else
                v31 = 0.0;
              v32 = UFG::qSymbol::create_from_string(&v38, "c_image");
              v33 = PropertyUtils::Get<char const *>(v17, v32, DEPTH_RECURSE);
              UFG::qString::qString(&v51, v33);
              v2->mData.p[v14].mId = v13;
              UFG::qString::Set(&v2->mData.p[v15].mText, v50.mData, v50.mLength, 0i64, 0);
              v2->mData.p[v14].mPosition.x = v22;
              v2->mData.p[v14].mPosition.y = v25;
              v2->mData.p[v14].mMinZoom = v28;
              v2->mData.p[v14].mMaxZoom = v31;
              v2->mData.p[v14].mIsVisible = 0;
              v34 = UFG::UI::LocalizeText(v50.mData);
              `eh vector constructor iterator'(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              if ( (v43 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v42 + 16i64))(v42, &ptr, v44);
                v42 = 0i64;
              }
              v43 = 6;
              v44 = v34;
              v35 = v51.mData;
              if ( (v47 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v46 + 16i64))(v46, &v45, v48);
                v46 = 0i64;
              }
              v47 = 6;
              v48 = v35;
              Scaleform::GFx::Movie::Invoke(v36, "MapLabels_CreateLabel", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
              `eh vector destructor iterator'(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
              UFG::qString::~qString(&v51);
              UFG::qString::~qString(&v50);
              ++v13;
              ++v15;
              ++v14;
            }
            while ( v13 < v7 );
          }
          v2->mInitialized = 1;
        }
      }
    }
  }
}

// File Line: 102
// RVA: 0x612040
void __fastcall UFG::UIHKMapLabelManager::StartOutro(UFG::UIHKMapLabelManager *this, UFG::UIScreen *pScreen)
{
  UFG::UIHKMapLabelManager *v2; // rdi
  Scaleform::GFx::Movie *v3; // rsi
  unsigned int v4; // ebx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( pScreen )
  {
    v2 = this;
    v3 = pScreen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v4 = 0;
      if ( this->mNumLabels > 0 )
      {
        do
        {
          if ( v2->mData.p[(unsigned __int64)v4].mIsVisible )
          {
            if ( ((unsigned int)pargs.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
                pargs.pObjectInterface,
                &pargs,
                *(_QWORD *)&pargs.mValue.NValue);
              pargs.pObjectInterface = 0i64;
            }
            pargs.Type = 5;
            pargs.mValue.NValue = (double)(signed int)v4;
            Scaleform::GFx::Movie::Invoke(v3, "MapLabels_Outro", 0i64, &pargs, 1u);
          }
          ++v4;
        }
        while ( v4 < v2->mNumLabels );
      }
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
    }
  }
}

// File Line: 124
// RVA: 0x63B920
void __fastcall UFG::UIHKMapLabelManager::update(UFG::UIHKMapLabelManager *this, UFG::UIScreen *pScreen, UFG::UITiledMapMath *mapGeo)
{
  UFG::UITiledMapMath *v3; // r13
  UFG::UIHKMapLabelManager *v4; // r14
  Scaleform::GFx::Movie *v5; // r12
  unsigned int v6; // edi
  unsigned __int64 v7; // rbx
  UFG::UIHKMapLabelData *v8; // rax
  float v9; // xmm1_4
  float v10; // xmm0_4
  UFG::UIHKMapLabelData *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  char v14; // si
  char v15; // r15
  double v16; // xmm6_8
  double v17; // xmm6_8
  UFG::MinimapTilePoint2f iconPos; // [rsp+30h] [rbp-D0h]
  UFG::MinimapPoint2f v19; // [rsp+38h] [rbp-C8h]
  char ptr; // [rsp+40h] [rbp-C0h]
  __int64 v21; // [rsp+50h] [rbp-B0h]
  unsigned int v22; // [rsp+58h] [rbp-A8h]
  double v23; // [rsp+60h] [rbp-A0h]
  char v24; // [rsp+70h] [rbp-90h]
  __int64 v25; // [rsp+80h] [rbp-80h]
  unsigned int v26; // [rsp+88h] [rbp-78h]
  double v27; // [rsp+90h] [rbp-70h]
  char v28; // [rsp+A0h] [rbp-60h]
  __int64 v29; // [rsp+B0h] [rbp-50h]
  unsigned int v30; // [rsp+B8h] [rbp-48h]
  double v31; // [rsp+C0h] [rbp-40h]
  char v32; // [rsp+D0h] [rbp-30h]
  __int64 v33; // [rsp+E0h] [rbp-20h]
  unsigned int v34; // [rsp+E8h] [rbp-18h]
  __int64 v35; // [rsp+F0h] [rbp-10h]
  char v36; // [rsp+100h] [rbp+0h]
  __int64 v37; // [rsp+110h] [rbp+10h]
  unsigned int v38; // [rsp+118h] [rbp+18h]
  __int64 v39; // [rsp+120h] [rbp+20h]
  __int64 v40; // [rsp+130h] [rbp+30h]
  UFG::ScreenPoint2f v41; // [rsp+190h] [rbp+90h]
  UFG::WorldPoint2f point; // [rsp+1A8h] [rbp+A8h]

  v40 = -2i64;
  v3 = mapGeo;
  v4 = this;
  if ( this->mInitialized )
  {
    if ( pScreen )
    {
      v5 = pScreen->mRenderable->m_movie.pObject;
      if ( v5 )
      {
        `eh vector constructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v6 = 0;
        if ( v4->mNumLabels )
        {
          do
          {
            v7 = (unsigned __int64)v6 << 6;
            v8 = v4->mData.p;
            v9 = *(float *)((char *)&v8->mPosition.y + v7);
            point.x = *(float *)((char *)&v8->mPosition.x + v7);
            point.y = v9;
            UFG::MinimapPoint2f::MinimapPoint2f(&v19, &point);
            UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v19, v3);
            v41 = 0i64;
            UFG::ScreenPoint2f::InitFromIconPos(&v41, &iconPos, v3);
            v10 = v3->scale;
            v11 = v4->mData.p;
            v12 = *(float *)((char *)&v11->mMaxZoom + v7);
            v13 = *(float *)((char *)&v11->mMinZoom + v7);
            v14 = 0;
            v15 = 0;
            if ( *(&v11->mIsVisible + v7) )
            {
              if ( v10 > v12 || v10 < v13 )
              {
                *(&v11->mIsVisible + v7) = 0;
                v15 = 1;
              }
            }
            else if ( v10 <= v12 && v10 >= v13 )
            {
              *(&v11->mIsVisible + v7) = 1;
              v14 = 1;
            }
            if ( (v22 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v21 + 16i64))(
                v21,
                &ptr,
                COERCE_DOUBLE(*(_QWORD *)&v23));
              v21 = 0i64;
            }
            v22 = 5;
            v23 = (double)(signed int)v6;
            v16 = v41.x;
            if ( (v26 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v25 + 16i64))(
                v25,
                &v24,
                COERCE_DOUBLE(*(_QWORD *)&v27));
              v25 = 0i64;
            }
            v26 = 5;
            v27 = v16;
            v17 = v41.y;
            if ( (v30 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
                v29,
                &v28,
                COERCE_DOUBLE(*(_QWORD *)&v31));
              v29 = 0i64;
            }
            v30 = 5;
            v31 = v17;
            if ( (v34 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v33 + 16i64))(v33, &v32, v35);
              v33 = 0i64;
            }
            v34 = 2;
            LOBYTE(v35) = v14;
            if ( (v38 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v37 + 16i64))(v37, &v36, v39);
              v37 = 0i64;
            }
            v38 = 2;
            LOBYTE(v39) = v15;
            Scaleform::GFx::Movie::Invoke(v5, "MapLabels_SetPosition", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
            ++v6;
          }
          while ( v6 < v4->mNumLabels );
        }
        `eh vector destructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

