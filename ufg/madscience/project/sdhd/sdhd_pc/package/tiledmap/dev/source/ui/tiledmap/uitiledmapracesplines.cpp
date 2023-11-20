// File Line: 34
// RVA: 0xBCFB0
void __fastcall UFG::UITiledMapRaceSplines::UITiledMapRaceSplines(UFG::UITiledMapRaceSplines *this)
{
  UFG::UITiledMapRaceSplines *v1; // rbx

  v1 = this;
  UFG::qString::qString(&this->m_CurrentLayerName);
  v1->m_MarkerPositions.p = 0i64;
  *(_QWORD *)&v1->m_MarkerPositions.size = 0i64;
  v1->m_SplinePoints.p = 0i64;
  *(_QWORD *)&v1->m_SplinePoints.size = 0i64;
  v1->m_NumSplinePoints = 0;
}

// File Line: 41
// RVA: 0xCAC40
void __fastcall UFG::UITiledMapRaceSplines::SetLayerName(UFG::UITiledMapRaceSplines *this, const char *layerName)
{
  const char *v2; // rdi
  UFG::UITiledMapRaceSplines *v3; // rbx

  v2 = layerName;
  v3 = this;
  if ( (unsigned int)UFG::qStringCompare(layerName, this->m_CurrentLayerName.mData, -1) )
  {
    if ( UFG::UITiledMapRaceSplines::GetMarkerPositions(v3, v2) )
    {
      UFG::UITiledMapRaceSplines::GenerateSpline(v3);
      UFG::qString::Set(&v3->m_CurrentLayerName, v2);
    }
  }
}

// File Line: 57
// RVA: 0xBE980
void __fastcall UFG::UITiledMapRaceSplines::Clear(UFG::UITiledMapRaceSplines *this)
{
  UFG::UITiledMapRaceSplines *v1; // rbx
  UFG::qVector3 *v2; // rcx
  UFG::qVector3 *v3; // rcx

  v1 = this;
  UFG::qString::Set(&this->m_CurrentLayerName, &customWorldMapCaption);
  v2 = v1->m_MarkerPositions.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_MarkerPositions.p = 0i64;
  *(_QWORD *)&v1->m_MarkerPositions.size = 0i64;
  v3 = v1->m_SplinePoints.p;
  if ( v3 )
    operator delete[](v3);
  v1->m_SplinePoints.p = 0i64;
  *(_QWORD *)&v1->m_SplinePoints.size = 0i64;
  v1->m_NumSplinePoints = 0;
}

// File Line: 68
// RVA: 0xC0FB0
bool __fastcall UFG::UITiledMapRaceSplines::GetMarkerPositions(UFG::UITiledMapRaceSplines *this, const char *layerName)
{
  const char *v2; // rbx
  signed int v3; // edi
  UFG::qArray<UFG::qVector3,0> *v4; // rsi
  UFG::qVector3 *v5; // rcx
  UFG::qSymbol *v6; // rax
  UFG::qBaseTreeRB *v7; // rbx
  bool v8; // al
  UFG::SceneLayerResource *v9; // r14
  UFG::qPropertySet *v10; // rax
  UFG::qPropertySet *v11; // rbx
  UFG::qMatrix44 *v12; // rax
  __int128 v13; // xmm0
  UFG::qPropertyList *v14; // r15
  unsigned int v15; // er12
  unsigned int v16; // edi
  char *v17; // rax
  UFG::qPropertySet *v18; // rcx
  UFG::qMatrix44 *v19; // rax
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  signed __int64 v24; // r13
  unsigned int v25; // ebx
  unsigned int v26; // edx
  unsigned int v27; // edx
  signed __int64 v28; // rcx
  UFG::qVector3 *v29; // rax
  __m128 v30; // [rsp+20h] [rbp-A8h]
  __m128 v31; // [rsp+30h] [rbp-98h]
  _BYTE v32[48]; // [rsp+40h] [rbp-88h]
  UFG::qString v33; // [rsp+70h] [rbp-58h]
  __int64 v34; // [rsp+A0h] [rbp-28h]
  __m128 v35; // [rsp+A8h] [rbp-20h]
  __m128 v36; // [rsp+B8h] [rbp-10h]
  __m128 v37; // [rsp+C8h] [rbp+0h]
  __m128 v38; // [rsp+D8h] [rbp+10h]
  UFG::qString v39; // [rsp+E8h] [rbp+20h]
  UFG::qSymbol result; // [rsp+1F8h] [rbp+130h]
  UFG::qSymbol name; // [rsp+208h] [rbp+140h]
  UFG::qSymbol v42; // [rsp+210h] [rbp+148h]

  v34 = -2i64;
  v2 = layerName;
  v3 = 0;
  v4 = &this->m_MarkerPositions;
  v5 = this->m_MarkerPositions.p;
  if ( v5 )
    operator delete[](v5);
  v4->p = 0i64;
  *(_QWORD *)&v4->size = 0i64;
  UFG::qString::qString((UFG::qString *)((char *)&v33 + 8), v2);
  UFG::qString::ReplaceString((UFG::qString *)((char *)&v33 + 8), "_Slice", &customWorldMapCaption, 1);
  v6 = UFG::qSymbol::create_from_string(&result, *(const char **)&v33.mStringHash32);
  v7 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v6);
  if ( v7 )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&v33, "XformLocal");
    UFG::qString::qString(&v39, *(const char **)&v33.mStringHash32);
    UFG::qString::operator+=(&v39, "-Race_MainPathObject");
    UFG::qSymbol::create_from_string(&name, v39.mData);
    UFG::qSymbol::create_from_string(&v42, "SimObjChildren");
    v9 = (UFG::SceneLayerResource *)(*(_QWORD *)&v7->mCount - 88i64);
    *(_QWORD *)&v32[40] = (char *)v7 - 32;
    if ( v9 != (UFG::SceneLayerResource *)v7[-1].mNULL.mChild )
    {
      do
      {
        v10 = UFG::SceneLayerResource::GetNamedPropertySet(v9, &name);
        v11 = v10;
        if ( v10 )
        {
          result.mUID = v3 + 1;
          v12 = PropertyUtils::Get<UFG::qMatrix44>(v10, (UFG::qSymbol *)&SimSym_XformLocal.mUID, DEPTH_RECURSE);
          v30 = (__m128)v12->v0;
          v31 = (__m128)v12->v1;
          *(_QWORD *)v32 = *(_QWORD *)&v12->v2.x;
          *(float *)&v32[8] = v12->v2.z;
          *(float *)&v32[12] = v12->v2.w;
          v13 = LODWORD(v12->v3.x);
          *(float *)&v32[20] = v12->v3.y;
          *(float *)&v32[24] = v12->v3.z;
          *(float *)&v32[28] = v12->v3.w;
          v14 = UFG::qPropertySet::Get<UFG::qPropertyList>(v11, &v42, DEPTH_RECURSE);
          v15 = v14->mNumElements;
          v16 = 0;
          if ( v15 )
          {
            do
            {
              v17 = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
              if ( v17 && *(_QWORD *)v17 )
                v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17];
              else
                v18 = 0i64;
              v19 = UFG::qPropertySet::Get<UFG::qMatrix44>(v18, (UFG::qSymbol *)&SimSym_XformLocal.mUID, DEPTH_RECURSE);
              v20 = v19->v0.y;
              *(float *)&v32[32] = v19->v0.x;
              *(float *)&v32[40] = v19->v0.z;
              *(float *)&v32[44] = v19->v0.w;
              v21 = v19->v1.y;
              v22 = v19->v1.z;
              v23 = v19->v1.w;
              *(float *)&v33.mPrev = v19->v1.x;
              *((float *)&v33.mPrev + 1) = v21;
              v33.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)__PAIR__(LODWORD(v23), LODWORD(v22));
              *(_QWORD *)&v32[8] = *(_QWORD *)&v19->v2.x;
              *(_QWORD *)&v32[16] = *(_QWORD *)&v19->v2.z;
              *(_QWORD *)&v32[24] = *(_QWORD *)&v19->v3.x;
              *(_QWORD *)&v32[32] = *(_QWORD *)&v19->v3.z;
              v35 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[32], *(__m128 *)&v32[32], 0), v30), _xmm),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[32], *(__m128 *)&v32[32], 85), v31)),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[32], *(__m128 *)&v32[32], 170), *(__m128 *)v32)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[32], *(__m128 *)&v32[32], 255), *(__m128 *)&v32[16]));
              v36 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)v33.0, (__m128)v33.0, 0), v30), (__m128)0i64),
                          _mm_mul_ps(_mm_shuffle_ps((__m128)v33.0, (__m128)v33.0, 85), v31)),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)v33.0, (__m128)v33.0, 170), *(__m128 *)v32)),
                      _mm_mul_ps(_mm_shuffle_ps((__m128)v33.0, (__m128)v33.0, 255), *(__m128 *)&v32[16]));
              v37 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[8], *(__m128 *)&v32[8], 0), v30),
                            (__m128)0i64),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[8], *(__m128 *)&v32[8], 85), v31)),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[8], *(__m128 *)&v32[8], 170), *(__m128 *)v32)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[8], *(__m128 *)&v32[8], 255), *(__m128 *)&v32[16]));
              v38 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[24], *(__m128 *)&v32[24], 0), v30),
                            (__m128)0i64),
                          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[24], *(__m128 *)&v32[24], 85), v31)),
                        _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[24], *(__m128 *)&v32[24], 170), *(__m128 *)v32)),
                      _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v32[24], *(__m128 *)&v32[24], 255), *(__m128 *)&v32[16]));
              v24 = v4->size;
              v25 = v24 + 1;
              v26 = v4->capacity;
              if ( (signed int)v24 + 1 > v26 )
              {
                if ( v26 )
                  v27 = 2 * v26;
                else
                  v27 = 1;
                for ( ; v27 < v25; v27 *= 2 )
                  ;
                if ( v27 - v25 > 0x10000 )
                  v27 = v24 + 65537;
                UFG::qArray<UFG::qVector3,0>::Reallocate(v4, v27, "qArray.Add");
              }
              v4->size = v25;
              v28 = v24;
              v29 = v4->p;
              *(_QWORD *)&v29[v28].x = v38.m128_u64[0];
              v29[v28].z = v38.m128_f32[2];
              ++v16;
            }
            while ( v16 < v15 );
          }
          v3 = result.mUID;
        }
        v9 = (UFG::SceneLayerResource *)&v9->mNext[-6].mNext;
      }
      while ( v9 != *(UFG::SceneLayerResource **)&v32[40] );
    }
    UFG::qString::~qString(&v39);
    UFG::qString::~qString((UFG::qString *)((char *)&v33 + 8));
    v8 = v3 > 0;
  }
  else
  {
    UFG::qString::~qString((UFG::qString *)((char *)&v33 + 8));
    v8 = 0;
  }
  return v8;
}

// File Line: 137
// RVA: 0xC0910
void __fastcall UFG::UITiledMapRaceSplines::GenerateSpline(UFG::UITiledMapRaceSplines *this)
{
  UFG::UITiledMapRaceSplines *v1; // rbx
  UFG::qVector3 *v2; // rcx
  unsigned int v3; // edi
  unsigned int v4; // er15
  unsigned int v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // edx
  UFG::qVector3 *v9; // r10
  __int64 v10; // r9
  unsigned int v11; // er8
  signed __int64 v12; // r12
  _DWORD *v13; // rcx
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
  signed __int64 v27; // rcx
  signed __int64 v28; // rax
  int v29; // xmm0_4
  int v30; // xmm1_4

  v1 = this;
  v2 = this->m_SplinePoints.p;
  if ( v2 )
    operator delete[](v2);
  v3 = 0;
  v1->m_SplinePoints.p = 0i64;
  *(_QWORD *)&v1->m_SplinePoints.size = 0i64;
  v1->m_NumSplinePoints = 0;
  UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v4 = v1->m_MarkerPositions.size;
  v5 = v4 * UFG::UIHKTweakables::WorldMap_RaceLineRes;
  v6 = v1->m_SplinePoints.size;
  if ( v6 != v4 * UFG::UIHKTweakables::WorldMap_RaceLineRes )
  {
    if ( (signed int)(v5 - v6) <= 0 )
    {
      if ( v6 != v5 )
      {
        if ( v6 - v5 < v6 )
          v1->m_SplinePoints.size = v5;
        else
          v1->m_SplinePoints.size = 0;
      }
    }
    else
    {
      v7 = v1->m_SplinePoints.capacity;
      if ( v5 > v7 )
      {
        if ( v7 )
          v8 = 2 * v7;
        else
          v8 = 1;
        for ( ; v8 < v5; v8 *= 2 )
          ;
        if ( v8 - v5 > 0x10000 )
          v8 = v5 + 0x10000;
        UFG::qArray<UFG::qVector3,0>::Reallocate(&v1->m_SplinePoints, v8, "UITiledMapRaceSplines");
      }
      v1->m_SplinePoints.size = v5;
    }
  }
  if ( v4 >= 2 )
  {
    v9 = v1->m_SplinePoints.p;
    v10 = 0i64;
    if ( (signed int)v4 < 4 )
    {
LABEL_27:
      if ( v3 < v4 )
      {
        v27 = (signed __int64)v9 + 4 * (v10 + 2 * (v10 + 1));
        do
        {
          if ( v3 >= v5 )
            break;
          ++v3;
          v27 += 12i64;
          v28 = (signed __int64)((char *)v1->m_MarkerPositions.p - 8i64 - (_QWORD)v9);
          v29 = *(_DWORD *)(v28 + v27 - 8);
          v30 = *(_DWORD *)(v28 + v27 - 4);
          *(_DWORD *)(v27 - 20) = *(_DWORD *)(v28 + v27 - 12);
          *(_DWORD *)(v27 - 16) = v29;
          *(_DWORD *)(v27 - 12) = v30;
          ++v1->m_NumSplinePoints;
        }
        while ( v3 < v4 );
      }
    }
    else
    {
      v11 = 2;
      v12 = -20i64 - (_QWORD)v9;
      v13 = (_DWORD *)&v9[1].z;
      while ( v3 < v5 )
      {
        v14 = v1->m_MarkerPositions.p;
        v15 = (char *)v13 + v12;
        v16 = *(_DWORD *)((char *)&v14->y + (_QWORD)v13 + v12);
        v17 = *(_DWORD *)((char *)&v14->z + (_QWORD)v13 + v12);
        *(v13 - 5) = *(_DWORD *)((char *)&v14->x + (_QWORD)v13 + v12);
        *(v13 - 4) = v16;
        *(v13 - 3) = v17;
        ++v1->m_NumSplinePoints;
        if ( v11 - 1 >= v5 )
          break;
        v18 = v1->m_MarkerPositions.p;
        v19 = *(_DWORD *)((char *)&v18[1].y + (_QWORD)v15);
        v20 = *(_DWORD *)((char *)&v18[1].z + (_QWORD)v15);
        *(v13 - 2) = *(_DWORD *)((char *)&v18[1].x + (_QWORD)v15);
        *(v13 - 1) = v19;
        *v13 = v20;
        ++v1->m_NumSplinePoints;
        if ( v11 >= v5 )
          break;
        v21 = (_DWORD *)((char *)&v1->m_MarkerPositions.p->x + (unsigned __int64)v13 + 4i64 - (_QWORD)v9);
        v22 = v21[1];
        v23 = v21[2];
        v13[1] = *v21;
        v13[2] = v22;
        v13[3] = v23;
        ++v1->m_NumSplinePoints;
        if ( v11 + 1 >= v5 )
          break;
        v3 += 4;
        v10 += 4i64;
        v24 = (_DWORD *)((char *)&v1->m_MarkerPositions.p->x + (unsigned __int64)v13 + 16i64 - (_QWORD)v9);
        v13 += 12;
        v11 += 4;
        v25 = v24[1];
        v26 = v24[2];
        *(v13 - 8) = *v24;
        *(v13 - 7) = v25;
        *(v13 - 6) = v26;
        ++v1->m_NumSplinePoints;
        if ( v3 >= v4 - 3 )
          goto LABEL_27;
      }
    }
  }
}

