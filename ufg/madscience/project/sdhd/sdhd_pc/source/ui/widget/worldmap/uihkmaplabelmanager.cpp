// File Line: 44
// RVA: 0x5EB9E0
void __fastcall UFG::UIHKMapLabelManager::HandleScreenInit(UFG::UIHKMapLabelManager *this, UFG::UIScreen *pScreen)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qArray<unsigned long,0> *v5; // rax
  UFG::qPropertyList *v6; // r13
  unsigned int mNumElements; // r12d
  unsigned int size; // edx
  unsigned int v9; // ebx
  unsigned int capacity; // edx
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int v13; // esi
  __int64 v14; // r14
  __int64 v15; // r15
  char *ValuePtr; // rax
  UFG::qPropertySet *v17; // rbx
  UFG::qArray<unsigned long,0> *v18; // rax
  char *v19; // rax
  UFG::qArray<unsigned long,0> *v20; // rax
  float *v21; // rax
  float v22; // xmm9_4
  UFG::qArray<unsigned long,0> *v23; // rax
  float *v24; // rax
  float v25; // xmm8_4
  UFG::qArray<unsigned long,0> *v26; // rax
  float *v27; // rax
  float v28; // xmm7_4
  UFG::qArray<unsigned long,0> *v29; // rax
  float *v30; // rax
  float v31; // xmm6_4
  UFG::qArray<unsigned long,0> *v32; // rax
  char *v33; // rax
  const char *v34; // rbx
  char *mData; // rbx
  Scaleform::GFx::Movie *pObject; // [rsp+30h] [rbp-D0h]
  UFG::qSymbol v37; // [rsp+38h] [rbp-C8h] BYREF
  UFG::qSymbol v38; // [rsp+3Ch] [rbp-C4h] BYREF
  UFG::qSymbol v39; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qSymbol v40; // [rsp+44h] [rbp-BCh] BYREF
  Scaleform::GFx::Value ptr; // [rsp+50h] [rbp-B0h] BYREF
  char v42[16]; // [rsp+80h] [rbp-80h] BYREF
  __int64 v43; // [rsp+90h] [rbp-70h]
  int v44; // [rsp+98h] [rbp-68h]
  char *v45; // [rsp+A0h] [rbp-60h]
  __int64 v46; // [rsp+B0h] [rbp-50h]
  UFG::qString v47; // [rsp+B8h] [rbp-48h] BYREF
  UFG::qString v48; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qSymbol result; // [rsp+198h] [rbp+98h] BYREF
  UFG::qSymbol v50; // [rsp+1A0h] [rbp+A0h] BYREF
  UFG::qSymbol v51; // [rsp+1A8h] [rbp+A8h] BYREF

  if ( pScreen )
  {
    v46 = -2i64;
    pObject = pScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v3 = UFG::qSymbol::create_from_string(&result, "UI-MapLabels");
      PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
      this->mPSSetData = PropertySet;
      if ( PropertySet )
      {
        v5 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&result, "mapLabels");
        v6 = PropertyUtils::Get<UFG::qPropertyList>(this->mPSSetData, v5, DEPTH_RECURSE);
        if ( v6 )
        {
          UFG::qArray<UFG::UIHKMapLabelData,0>::~qArray<UFG::UIHKMapLabelData,0>(&this->mData);
          this->mNumLabels = 0;
          mNumElements = v6->mNumElements;
          size = this->mData.size;
          if ( (int)(mNumElements - this->mData.size) <= 0 )
          {
            v12 = this->mData.size - v6->mNumElements;
            if ( v12 )
            {
              if ( v12 < size )
                this->mData.size = size - v12;
              else
                this->mData.size = 0;
            }
          }
          else
          {
            v9 = v6->mNumElements;
            capacity = this->mData.capacity;
            if ( v9 > capacity )
            {
              if ( capacity )
                v11 = 2 * capacity;
              else
                v11 = 1;
              for ( ; v11 < v9; v11 *= 2 )
                ;
              if ( v11 - v9 > 0x10000 )
                v11 = v9 + 0x10000;
              UFG::qArray<UFG::UIHKMapLabelData,0>::Reallocate(&this->mData, v11, "mData");
            }
            this->mData.size = v9;
          }
          this->mNumLabels = mNumElements;
          v13 = 0;
          if ( mNumElements )
          {
            v14 = 0i64;
            v15 = 0i64;
            do
            {
              ValuePtr = UFG::qPropertyList::GetValuePtr(v6, 0x1Au, v13);
              if ( ValuePtr && *(_QWORD *)ValuePtr )
                v17 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
              else
                v17 = 0i64;
              v18 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v50, "text");
              v19 = PropertyUtils::Get<char const *>(v17, v18, DEPTH_RECURSE);
              UFG::qString::qString(&v47, v19);
              v20 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v51, "pos_x");
              v21 = UFG::qPropertySet::Get<float>(v17, v20, DEPTH_RECURSE);
              if ( v21 )
                v22 = *v21;
              else
                v22 = 0.0;
              v23 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v37, "pos_y");
              v24 = UFG::qPropertySet::Get<float>(v17, v23, DEPTH_RECURSE);
              if ( v24 )
                v25 = *v24;
              else
                v25 = 0.0;
              v26 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v39, "min_zoom");
              v27 = UFG::qPropertySet::Get<float>(v17, v26, DEPTH_RECURSE);
              if ( v27 )
                v28 = *v27;
              else
                v28 = 0.0;
              v29 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v40, "max_zoom");
              v30 = UFG::qPropertySet::Get<float>(v17, v29, DEPTH_RECURSE);
              if ( v30 )
                v31 = *v30;
              else
                v31 = 0.0;
              v32 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v38, "c_image");
              v33 = PropertyUtils::Get<char const *>(v17, v32, DEPTH_RECURSE);
              UFG::qString::qString(&v48, v33);
              this->mData.p[v14].mId = v13;
              UFG::qString::Set(&this->mData.p[v15].mText, v47.mData, v47.mLength, 0i64, 0);
              this->mData.p[v14].mPosition.x = v22;
              this->mData.p[v14].mPosition.y = v25;
              this->mData.p[v14].mMinZoom = v28;
              this->mData.p[v14].mMaxZoom = v31;
              this->mData.p[v14].mIsVisible = 0;
              v34 = UFG::UI::LocalizeText(v47.mData);
              `eh vector constructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
              if ( (ptr.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                  ptr.pObjectInterface,
                  &ptr,
                  ptr.mValue);
                ptr.pObjectInterface = 0i64;
              }
              ptr.Type = VT_String;
              ptr.mValue.pString = v34;
              mData = v48.mData;
              if ( (v44 & 0x40) != 0 )
              {
                (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v43 + 16i64))(v43, v42, v45);
                v43 = 0i64;
              }
              v44 = 6;
              v45 = mData;
              Scaleform::GFx::Movie::Invoke(pObject, "MapLabels_CreateLabel", 0i64, &ptr, 2u);
              `eh vector destructor iterator(
                &ptr,
                0x30ui64,
                2,
                (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
              UFG::qString::~qString(&v48);
              UFG::qString::~qString(&v47);
              ++v13;
              ++v15;
              ++v14;
            }
            while ( v13 < mNumElements );
          }
          this->mInitialized = 1;
        }
      }
    }
  }
}

// File Line: 102
// RVA: 0x612040
void __fastcall UFG::UIHKMapLabelManager::StartOutro(UFG::UIHKMapLabelManager *this, UFG::UIScreen *pScreen)
{
  Scaleform::GFx::Movie *pObject; // rsi
  unsigned int i; // ebx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( pScreen )
  {
    pObject = pScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Undefined;
      for ( i = 0; i < this->mNumLabels; ++i )
      {
        if ( this->mData.p[(unsigned __int64)i].mIsVisible )
        {
          if ( (pargs.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              pargs.mValue);
            pargs.pObjectInterface = 0i64;
          }
          pargs.Type = VT_Number;
          pargs.mValue.NValue = (double)(int)i;
          Scaleform::GFx::Movie::Invoke(pObject, "MapLabels_Outro", 0i64, &pargs, 1u);
        }
      }
      if ( (pargs.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
    }
  }
}

// File Line: 124
// RVA: 0x63B920
void __fastcall UFG::UIHKMapLabelManager::update(
        UFG::UIHKMapLabelManager *this,
        UFG::UIScreen *pScreen,
        UFG::UITiledMapMath *mapGeo)
{
  Scaleform::GFx::Movie *pObject; // r12
  unsigned int i; // edi
  unsigned __int64 v7; // rbx
  UFG::UIHKMapLabelData *p; // rax
  float v9; // xmm1_4
  float scale; // xmm0_4
  UFG::UIHKMapLabelData *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  char v14; // si
  char v15; // r15
  double x; // xmm6_8
  double y; // xmm6_8
  UFG::MinimapTilePoint2f iconPos; // [rsp+30h] [rbp-D0h] BYREF
  UFG::MinimapPoint2f v19; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-C0h] BYREF
  char v21[16]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v22; // [rsp+80h] [rbp-80h]
  int v23; // [rsp+88h] [rbp-78h]
  double v24; // [rsp+90h] [rbp-70h]
  char v25[16]; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v26; // [rsp+B0h] [rbp-50h]
  int v27; // [rsp+B8h] [rbp-48h]
  double v28; // [rsp+C0h] [rbp-40h]
  char v29[16]; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v30; // [rsp+E0h] [rbp-20h]
  int v31; // [rsp+E8h] [rbp-18h]
  __int64 v32; // [rsp+F0h] [rbp-10h]
  char v33[16]; // [rsp+100h] [rbp+0h] BYREF
  __int64 v34; // [rsp+110h] [rbp+10h]
  int v35; // [rsp+118h] [rbp+18h]
  __int64 v36; // [rsp+120h] [rbp+20h]
  __int64 v37; // [rsp+130h] [rbp+30h]
  UFG::ScreenPoint2f v38; // [rsp+190h] [rbp+90h] BYREF
  UFG::WorldPoint2f point; // [rsp+1A8h] [rbp+A8h] BYREF

  v37 = -2i64;
  if ( this->mInitialized )
  {
    if ( pScreen )
    {
      pObject = pScreen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        for ( i = 0; i < this->mNumLabels; ++i )
        {
          v7 = (unsigned __int64)i << 6;
          p = this->mData.p;
          v9 = *(float *)((char *)&p->mPosition.y + v7);
          point.x = *(float *)((char *)&p->mPosition.x + v7);
          point.y = v9;
          UFG::MinimapPoint2f::MinimapPoint2f(&v19, &point);
          UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v19, mapGeo);
          v38 = 0i64;
          UFG::ScreenPoint2f::InitFromIconPos(&v38, &iconPos, mapGeo);
          scale = mapGeo->scale;
          v11 = this->mData.p;
          v12 = *(float *)((char *)&v11->mMaxZoom + v7);
          v13 = *(float *)((char *)&v11->mMinZoom + v7);
          v14 = 0;
          v15 = 0;
          if ( *(&v11->mIsVisible + v7) )
          {
            if ( scale > v12 || scale < v13 )
            {
              *(&v11->mIsVisible + v7) = 0;
              v15 = 1;
            }
          }
          else if ( scale <= v12 && scale >= v13 )
          {
            *(&v11->mIsVisible + v7) = 1;
            v14 = 1;
          }
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_Number;
          ptr.mValue.NValue = (double)(int)i;
          x = v38.x;
          if ( (v23 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
              v22,
              v21,
              COERCE_DOUBLE(*(_QWORD *)&v24));
            v22 = 0i64;
          }
          v23 = 5;
          v24 = x;
          y = v38.y;
          if ( (v27 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
              v26,
              v25,
              COERCE_DOUBLE(*(_QWORD *)&v28));
            v26 = 0i64;
          }
          v27 = 5;
          v28 = y;
          if ( (v31 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v30 + 16i64))(v30, v29, v32);
            v30 = 0i64;
          }
          v31 = 2;
          LOBYTE(v32) = v14;
          if ( (v35 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v34 + 16i64))(v34, v33, v36);
            v34 = 0i64;
          }
          v35 = 2;
          LOBYTE(v36) = v15;
          Scaleform::GFx::Movie::Invoke(pObject, "MapLabels_SetPosition", 0i64, &ptr, 5u);
        }
        `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

