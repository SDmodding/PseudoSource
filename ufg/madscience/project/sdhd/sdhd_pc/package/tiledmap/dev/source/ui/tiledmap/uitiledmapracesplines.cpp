// File Line: 34
// RVA: 0xBCFB0
void __fastcall UFG::UITiledMapRaceSplines::UITiledMapRaceSplines(UFG::UITiledMapRaceSplines *this)
{
  UFG::qString::qString(&this->m_CurrentLayerName);
  this->m_MarkerPositions.p = 0i64;
  *(_QWORD *)&this->m_MarkerPositions.size = 0i64;
  this->m_SplinePoints.p = 0i64;
  *(_QWORD *)&this->m_SplinePoints.size = 0i64;
  this->m_NumSplinePoints = 0;
}

// File Line: 41
// RVA: 0xCAC40
void __fastcall UFG::UITiledMapRaceSplines::SetLayerName(UFG::UITiledMapRaceSplines *this, const char *layerName)
{
  if ( (unsigned int)UFG::qStringCompare(layerName, this->m_CurrentLayerName.mData, -1) )
  {
    if ( UFG::UITiledMapRaceSplines::GetMarkerPositions(this, layerName) )
    {
      UFG::UITiledMapRaceSplines::GenerateSpline(this);
      UFG::qString::Set(&this->m_CurrentLayerName, layerName);
    }
  }
}

// File Line: 57
// RVA: 0xBE980
void __fastcall UFG::UITiledMapRaceSplines::Clear(UFG::UITiledMapRaceSplines *this)
{
  UFG::qVector3 *p; // rcx
  UFG::qVector3 *v3; // rcx

  UFG::qString::Set(&this->m_CurrentLayerName, &customCaption);
  p = this->m_MarkerPositions.p;
  if ( p )
    operator delete[](p);
  this->m_MarkerPositions.p = 0i64;
  *(_QWORD *)&this->m_MarkerPositions.size = 0i64;
  v3 = this->m_SplinePoints.p;
  if ( v3 )
    operator delete[](v3);
  this->m_SplinePoints.p = 0i64;
  *(_QWORD *)&this->m_SplinePoints.size = 0i64;
  this->m_NumSplinePoints = 0;
}

// File Line: 68
// RVA: 0xC0FB0
bool __fastcall UFG::UITiledMapRaceSplines::GetMarkerPositions(UFG::UITiledMapRaceSplines *this, const char *layerName)
{
  signed int mUID; // edi
  UFG::qArray<UFG::qVector3,0> *p_m_MarkerPositions; // rsi
  UFG::qVector3 *p; // rcx
  UFG::qSymbol *v6; // rax
  UFG::qBaseTreeRB *Layer; // rbx
  UFG::SceneLayerResource *p_mNext; // r14
  UFG::qPropertySet *NamedPropertySet; // rax
  UFG::qPropertySet *v11; // rbx
  UFG::qMatrix44 *v12; // rax
  UFG::qPropertyList *v13; // r15
  unsigned int mNumElements; // r12d
  unsigned int i; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v17; // rcx
  UFG::qMatrix44 *v18; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
  __int64 size; // r13
  unsigned int v23; // ebx
  unsigned int capacity; // edx
  unsigned int v25; // edx
  __int64 v26; // rcx
  UFG::qVector3 *v27; // rax
  __m128 v28; // [rsp+20h] [rbp-A8h]
  __m128 v29; // [rsp+30h] [rbp-98h]
  _BYTE v30[48]; // [rsp+40h] [rbp-88h]
  UFG::qString v31; // [rsp+70h] [rbp-58h] BYREF
  __int64 v32; // [rsp+A0h] [rbp-28h]
  __m128 v33; // [rsp+A8h] [rbp-20h]
  __m128 v34; // [rsp+B8h] [rbp-10h]
  __m128 v35; // [rsp+C8h] [rbp+0h]
  __m128 v36; // [rsp+D8h] [rbp+10h]
  UFG::qString v37; // [rsp+E8h] [rbp+20h] BYREF
  UFG::qSymbol result; // [rsp+1F8h] [rbp+130h] BYREF
  UFG::qSymbol name; // [rsp+208h] [rbp+140h] BYREF
  UFG::qSymbol v40; // [rsp+210h] [rbp+148h] BYREF

  v32 = -2i64;
  mUID = 0;
  p_m_MarkerPositions = &this->m_MarkerPositions;
  p = this->m_MarkerPositions.p;
  if ( p )
    operator delete[](p);
  p_m_MarkerPositions->p = 0i64;
  *(_QWORD *)&p_m_MarkerPositions->size = 0i64;
  UFG::qString::qString((UFG::qString *)&v31.mNext, layerName);
  UFG::qString::ReplaceString((UFG::qString *)&v31.mNext, "_Slice", &customCaption, 1);
  v6 = UFG::qSymbol::create_from_string(&result, *(const char **)&v31.mStringHash32);
  Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v6);
  if ( Layer )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v31, "XformLocal");
    UFG::qString::qString(&v37, *(const char **)&v31.mStringHash32);
    UFG::qString::operator+=(&v37, "-Race_MainPathObject");
    UFG::qSymbol::create_from_string(&name, v37.mData);
    UFG::qSymbol::create_from_string(&v40, "SimObjChildren");
    p_mNext = (UFG::SceneLayerResource *)(*(_QWORD *)&Layer->mCount - 88i64);
    *(_QWORD *)&v30[40] = (char *)Layer - 32;
    if ( p_mNext != (UFG::SceneLayerResource *)Layer[-1].mNULL.mChild )
    {
      do
      {
        NamedPropertySet = UFG::SceneLayerResource::GetNamedPropertySet(p_mNext, &name);
        v11 = NamedPropertySet;
        if ( NamedPropertySet )
        {
          result.mUID = mUID + 1;
          v12 = PropertyUtils::Get<UFG::qMatrix44>(NamedPropertySet, &SimSym_XformLocal, DEPTH_RECURSE);
          v28 = (__m128)v12->v0;
          v29 = (__m128)v12->v1;
          *(_QWORD *)v30 = *(_QWORD *)&v12->v2.x;
          v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(v11, &v40, DEPTH_RECURSE);
          mNumElements = v13->mNumElements;
          for ( i = 0; i < mNumElements; ++i )
          {
            ValuePtr = UFG::qPropertyList::GetValuePtr(v13, 0x1Au, i);
            if ( ValuePtr && *(_QWORD *)ValuePtr )
              v17 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
            else
              v17 = 0i64;
            v18 = UFG::qPropertySet::Get<UFG::qMatrix44>(v17, &SimSym_XformLocal, DEPTH_RECURSE);
            *(_QWORD *)&v30[40] = *(_QWORD *)&v18->v0.z;
            y = v18->v1.y;
            z = v18->v1.z;
            w = v18->v1.w;
            *(float *)&v31.mPrev = v18->v1.x;
            *((float *)&v31.mPrev + 1) = y;
            v31.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)__PAIR64__(LODWORD(w), LODWORD(z));
            *(UFG::qVector4 *)&v30[8] = v18->v2;
            *(UFG::qVector4 *)&v30[24] = v18->v3;
            v33 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[32], *(__m128 *)&v30[32], 0), v28), _xmm),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[32], *(__m128 *)&v30[32], 85), v29)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[32], *(__m128 *)&v30[32], 170), *(__m128 *)v30)),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[32], *(__m128 *)&v30[32], 255), *(__m128 *)&v30[16]));
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_shuffle_ps(
                              (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                              (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                              0),
                            v28),
                          (__m128)0i64),
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                            (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                            85),
                          v29)),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                          (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                          170),
                        *(__m128 *)v30)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(
                        (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                        (__m128)v31.UFG::qNode<UFG::qString,UFG::qString>,
                        255),
                      *(__m128 *)&v30[16]));
            v35 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[8], *(__m128 *)&v30[8], 0), v28),
                          (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[8], *(__m128 *)&v30[8], 85), v29)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[8], *(__m128 *)&v30[8], 170), *(__m128 *)v30)),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[8], *(__m128 *)&v30[8], 255), *(__m128 *)&v30[16]));
            v36 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[24], *(__m128 *)&v30[24], 0), v28),
                          (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[24], *(__m128 *)&v30[24], 85), v29)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[24], *(__m128 *)&v30[24], 170), *(__m128 *)v30)),
                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v30[24], *(__m128 *)&v30[24], 255), *(__m128 *)&v30[16]));
            size = p_m_MarkerPositions->size;
            v23 = size + 1;
            capacity = p_m_MarkerPositions->capacity;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v25 = 2 * capacity;
              else
                v25 = 1;
              for ( ; v25 < v23; v25 *= 2 )
                ;
              if ( v25 - v23 > 0x10000 )
                v25 = size + 65537;
              UFG::qArray<UFG::qVector3,0>::Reallocate(p_m_MarkerPositions, v25, "qArray.Add");
            }
            p_m_MarkerPositions->size = v23;
            v26 = size;
            v27 = p_m_MarkerPositions->p;
            *(_QWORD *)&v27[v26].x = v36.m128_u64[0];
            LODWORD(v27[v26].z) = v36.m128_i32[2];
          }
          mUID = result.mUID;
        }
        p_mNext = (UFG::SceneLayerResource *)&p_mNext->mNext[-6].mNext;
      }
      while ( p_mNext != *(UFG::SceneLayerResource **)&v30[40] );
    }
    UFG::qString::~qString(&v37);
    UFG::qString::~qString((UFG::qString *)&v31.mNext);
    return mUID > 0;
  }
  else
  {
    UFG::qString::~qString((UFG::qString *)&v31.mNext);
    return 0;
  }
}&v37);


// File Line: 137
// RVA: 0xC0910
void __fastcall UFG::UITiledMapRaceSplines::GenerateSpline(UFG::UITiledMapRaceSplines *this)
{
  UFG::qVector3 *p; // rcx
  unsigned int v3; // edi
  unsigned int size; // r15d
  unsigned int v5; // esi
  unsigned int v6; // ecx
  unsigned int capacity; // edx
  unsigned int v8; // edx
  UFG::qVector3 *v9; // r10
  __int64 v10; // r9
  unsigned int v11; // r8d
  __int64 v12; // r12
  _DWORD *p_z; // rcx
  UFG::qVector3 *v14; // rax
  char *v15; // rdx
  int v16; // xmm0_4
  int v17; // xmm1_4
  UFG::qVector3 *v18; // rax
  int v19; // xmm0_4
  int v20; // xmm1_4
  _DWORD *v21; // rax
  int v22; // xmm0_4
  int v23; // xmm1_4
  _DWORD *v24; // rax
  int v25; // xmm0_4
  int v26; // xmm1_4
  float *v27; // rcx
  char *v28; // rax
  int v29; // xmm0_4
  int v30; // xmm1_4

  p = this->m_SplinePoints.p;
  if ( p )
    operator delete[](p);
  v3 = 0;
  this->m_SplinePoints.p = 0i64;
  *(_QWORD *)&this->m_SplinePoints.size = 0i64;
  this->m_NumSplinePoints = 0;
  UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  size = this->m_MarkerPositions.size;
  v5 = size * UFG::UIHKTweakables::WorldMap_RaceLineRes;
  v6 = this->m_SplinePoints.size;
  if ( v6 != size * UFG::UIHKTweakables::WorldMap_RaceLineRes )
  {
    if ( (int)(v5 - v6) <= 0 )
    {
      if ( v6 != v5 )
      {
        if ( v6 - v5 < v6 )
          this->m_SplinePoints.size = v5;
        else
          this->m_SplinePoints.size = 0;
      }
    }
    else
    {
      capacity = this->m_SplinePoints.capacity;
      if ( v5 > capacity )
      {
        if ( capacity )
          v8 = 2 * capacity;
        else
          v8 = 1;
        for ( ; v8 < v5; v8 *= 2 )
          ;
        if ( v8 - v5 > 0x10000 )
          v8 = v5 + 0x10000;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&this->m_SplinePoints, v8, "UITiledMapRaceSplines");
      }
      this->m_SplinePoints.size = v5;
    }
  }
  if ( size >= 2 )
  {
    v9 = this->m_SplinePoints.p;
    v10 = 0i64;
    if ( (int)size < 4 )
    {
LABEL_27:
      if ( v3 < size )
      {
        v27 = &v9->z + 2 * v10 + v10;
        do
        {
          if ( v3 >= v5 )
            break;
          ++v3;
          v27 += 3;
          v28 = (char *)this->m_MarkerPositions.p - 8i64 - (_QWORD)v9;
          v29 = *(_DWORD *)((char *)v27 + (_QWORD)v28 - 8);
          v30 = *(_DWORD *)((char *)v27 + (_QWORD)v28 - 4);
          *(v27 - 5) = *(float *)((char *)v27 + (_QWORD)v28 - 12);
          *((_DWORD *)v27 - 4) = v29;
          *((_DWORD *)v27 - 3) = v30;
          ++this->m_NumSplinePoints;
        }
        while ( v3 < size );
      }
    }
    else
    {
      v11 = 2;
      v12 = -20i64 - (_QWORD)v9;
      p_z = (_DWORD *)&v9[1].z;
      while ( v3 < v5 )
      {
        v14 = this->m_MarkerPositions.p;
        v15 = (char *)p_z + v12;
        v16 = *(_DWORD *)((char *)&v14->y + (_QWORD)p_z + v12);
        v17 = *(_DWORD *)((char *)&v14->z + (_QWORD)p_z + v12);
        *(p_z - 5) = *(_DWORD *)((char *)&v14->x + (_QWORD)p_z + v12);
        *(p_z - 4) = v16;
        *(p_z - 3) = v17;
        ++this->m_NumSplinePoints;
        if ( v11 - 1 >= v5 )
          break;
        v18 = this->m_MarkerPositions.p;
        v19 = *(_DWORD *)((char *)&v18[1].y + (_QWORD)v15);
        v20 = *(_DWORD *)((char *)&v18[1].z + (_QWORD)v15);
        *(p_z - 2) = *(_DWORD *)((char *)&v18[1].x + (_QWORD)v15);
        *(p_z - 1) = v19;
        *p_z = v20;
        ++this->m_NumSplinePoints;
        if ( v11 >= v5 )
          break;
        v21 = (_DWORD *)((char *)&this->m_MarkerPositions.p->x + (unsigned __int64)p_z + 4i64 - (_QWORD)v9);
        v22 = v21[1];
        v23 = v21[2];
        p_z[1] = *v21;
        p_z[2] = v22;
        p_z[3] = v23;
        ++this->m_NumSplinePoints;
        if ( v11 + 1 >= v5 )
          break;
        v3 += 4;
        v10 += 4i64;
        v24 = (_DWORD *)((char *)&this->m_MarkerPositions.p->x + (unsigned __int64)p_z + 16i64 - (_QWORD)v9);
        p_z += 12;
        v11 += 4;
        v25 = v24[1];
        v26 = v24[2];
        *(p_z - 8) = *v24;
        *(p_z - 7) = v25;
        *(p_z - 6) = v26;
        ++this->m_NumSplinePoints;
        if ( v3 >= size - 3 )
          goto LABEL_27;
      }
    }
  }
}

