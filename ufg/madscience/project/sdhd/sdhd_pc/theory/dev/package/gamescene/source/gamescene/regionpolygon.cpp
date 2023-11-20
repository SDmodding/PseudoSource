// File Line: 86
// RVA: 0x2376E0
void __fastcall UFG::RegionPolygon::RegionPolygon(UFG::RegionPolygon *this, UFG::RegionPolygon *rgnPoly)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionBase::`vftable';
  this->mRefCount = 0;
  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionPolygon::`vftable';
  this->mpVerts = 0i64;
  this->mVertCount = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mCenter.x = UFG::qVector3::msZero.x;
  this->mCenter.y = v2;
  this->mCenter.z = v3;
  v4 = UFG::qVector3::msDirUp.y;
  v5 = UFG::qVector3::msDirUp.z;
  this->mNormal.x = UFG::qVector3::msDirUp.x;
  this->mNormal.y = v4;
  this->mNormal.z = v5;
  *(_QWORD *)&this->mOrigDist = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMin.y = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMax.x = 0i64;
  this->mBoundingBox.mMax.z = 0.0;
  UFG::RegionPolygon::SetShape(this, (UFG::RegionBase *)&rgnPoly->vfptr);
}

// File Line: 114
// RVA: 0x237790
void __fastcall UFG::RegionPolygon::RegionPolygon(UFG::RegionPolygon *this, UFG::qPropertySet *props)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionBase::`vftable';
  this->mRefCount = 0;
  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionPolygon::`vftable';
  this->mpVerts = 0i64;
  *(_QWORD *)&this->mVertCount = 0i64;
  this->mExtentBelow = 0.0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  this->mCenter.x = UFG::qVector3::msZero.x;
  this->mCenter.y = v2;
  this->mCenter.z = v3;
  v4 = UFG::qVector3::msDirUp.y;
  v5 = UFG::qVector3::msDirUp.z;
  this->mNormal.x = UFG::qVector3::msDirUp.x;
  this->mNormal.y = v4;
  this->mNormal.z = v5;
  *(_QWORD *)&this->mOrigDist = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMin.y = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMax.x = 0i64;
  this->mBoundingBox.mMax.z = 0.0;
  UFG::RegionPolygon::PropertiesLoad(this, props);
}

// File Line: 136
// RVA: 0x23A370
void __fastcall UFG::RegionPolygon::Clone(UFG::RegionPolygon *this)
{
  UFG::RegionPolygon *v1; // rbx
  UFG::allocator::free_link *v2; // rax

  v1 = this;
  v2 = UFG::qMalloc(0x58ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
    UFG::RegionPolygon::RegionPolygon((UFG::RegionPolygon *)v2, v1);
}

// File Line: 145
// RVA: 0x23D350
void __fastcall UFG::RegionPolygon::GetCenter(UFG::RegionPolygon *this, UFG::qVector3 *pPos)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = this->mCenter.y;
  v3 = this->mCenter.z;
  pPos->x = this->mCenter.x;
  pPos->y = v2;
  pPos->z = v3;
}

// File Line: 155
// RVA: 0x23DD60
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetRandomPosition(UFG::RegionPolygon *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rbx
  UFG::RegionPolygon *v3; // rdi
  UFG::qVector3 *v4; // rax
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-48h]

  v2 = result;
  v3 = this;
  do
  {
    v4 = UFG::qBox::GetRandomPosition(&v3->mBoundingBox, &resulta);
    v5 = v4->y;
    v6 = v4->z;
    v2->x = v4->x;
    v7 = v2->x;
    v2->y = v5;
    v2->z = v6;
    v8 = (float)((float)((float)(v3->mNormal.x * v7) + (float)(v3->mNormal.y * v5)) + (float)(v3->mNormal.z * v6))
       - v3->mOrigDist;
    v9 = v5 - (float)(v3->mNormal.y * v8);
    v10 = v6 - (float)(v3->mNormal.z * v8);
    v2->x = v7 - (float)(v3->mNormal.x * v8);
    v2->y = v9;
    v2->z = v10;
  }
  while ( !(unsigned __int8)UFG::qIsBoundPointPolyXY(v2, v3->mpVerts, v3->mVertCount) );
  return v2;
}

// File Line: 184
// RVA: 0x245F10
void __fastcall UFG::RegionPolygon::Translate(UFG::RegionPolygon *this, UFG::qVector3 *offset)
{
  UFG::RegionPolygon *v2; // r10
  UFG::qVector3 *v3; // rcx
  __int64 v4; // rax
  unsigned __int64 v5; // r11
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float *v23; // rcx
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm2_4

  v2 = this;
  v3 = this->mpVerts;
  v4 = v2->mVertCount;
  v5 = (unsigned __int64)&v3[v4];
  if ( (unsigned __int64)v3 < v5 )
  {
    if ( (signed __int64)(((unsigned __int64)((unsigned __int128)((12 * v4 + 11)
                                                                * (signed __int128)3074457345618258603i64) >> 64) >> 63)
                        + ((signed __int64)((unsigned __int128)((12 * v4 + 11) * (signed __int128)3074457345618258603i64) >> 64) >> 1)) >= 4 )
    {
      do
      {
        v6 = v3->y;
        v7 = v3->z;
        v8 = v3->x;
        v3 += 4;
        v9 = v6 + offset->y;
        v10 = v7 + offset->z;
        v3[-4].x = v8 + offset->x;
        v11 = v3[-3].x;
        v3[-4].y = v9;
        v12 = v3[-3].y;
        v3[-4].z = v10;
        v13 = v12 + offset->y;
        v14 = v3[-3].z + offset->z;
        v3[-3].x = v11 + offset->x;
        v15 = v3[-2].x;
        v3[-3].y = v13;
        v16 = v3[-2].y;
        v3[-3].z = v14;
        v17 = v16 + offset->y;
        v18 = v3[-2].z + offset->z;
        v3[-2].x = v15 + offset->x;
        v19 = v3[-1].x;
        v3[-2].y = v17;
        v20 = v3[-1].y;
        v3[-2].z = v18;
        v21 = v20 + offset->y;
        v22 = v3[-1].z + offset->z;
        v3[-1].x = v19 + offset->x;
        v3[-1].y = v21;
        v3[-1].z = v22;
      }
      while ( (signed __int64)v3 < (signed __int64)(v5 - 36) );
    }
    if ( (unsigned __int64)v3 < v5 )
    {
      v23 = &v3->z;
      do
      {
        v24 = *v23;
        v25 = *(v23 - 2);
        v23 += 3;
        v26 = v24 + offset->z;
        v27 = offset->y + *(v23 - 4);
        *(v23 - 5) = v25 + offset->x;
        *(v23 - 4) = v27;
        *(v23 - 3) = v26;
      }
      while ( (unsigned __int64)(v23 - 2) < v5 );
    }
  }
  v28 = v2->mBoundingBox.mMin.y + offset->y;
  v29 = v2->mBoundingBox.mMin.z + offset->z;
  v2->mBoundingBox.mMin.x = v2->mBoundingBox.mMin.x + offset->x;
  v2->mBoundingBox.mMin.y = v28;
  v2->mBoundingBox.mMin.z = v29;
  v30 = v2->mBoundingBox.mMax.z + offset->z;
  v31 = offset->y + v2->mBoundingBox.mMax.y;
  v2->mBoundingBox.mMax.x = offset->x + v2->mBoundingBox.mMax.x;
  v2->mBoundingBox.mMax.y = v31;
  v2->mBoundingBox.mMax.z = v30;
  UFG::RegionPolygon::RecalcCachedValues(v2, 0);
}

// File Line: 205
// RVA: 0x243CE0
void __fastcall UFG::RegionPolygon::PropertiesLoad(UFG::RegionPolygon *this, UFG::qPropertySet *props)
{
  UFG::qPropertySet *v2; // rbx
  UFG::RegionPolygon *v3; // rsi
  unsigned int v4; // edi
  UFG::qPropertyList *v5; // r14
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::qVector3 *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm1_4

  v2 = props;
  v3 = this;
  v4 = 0;
  if ( this->mVertCount )
  {
    this->mVertCount = 0;
    operator delete[](this->mpVerts);
    v3->mpVerts = 0i64;
    UFG::RegionPolygon::RecalcCachedValues(v3, 1);
  }
  v3->mExtentAbove = *UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&SimSym_ExtentAbove.mUID, DEPTH_RECURSE);
  v3->mExtentBelow = *UFG::qPropertySet::Get<float>(v2, (UFG::qSymbol *)&SimSym_ExtentBelow.mUID, DEPTH_RECURSE);
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&SimSym_Vertexes.mUID, DEPTH_RECURSE);
  v6 = v5->mNumElements;
  if ( (_DWORD)v6 )
  {
    v3->mVertCount = v6;
    v7 = 12 * v6;
    if ( !is_mul_ok(v6, 0xCui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
    v3->mpVerts = (UFG::qVector3 *)v8;
    if ( (_DWORD)v6 )
    {
      v9 = v8 + 1;
      do
      {
        v10 = UFG::qPropertyList::Get<UFG::qVector3>(v5, v4);
        v11 = v10->y;
        v12 = v10->z;
        *(float *)&v9[-1].mNext = v10->x;
        *((float *)&v9[-1].mNext + 1) = v11;
        *(float *)&v9->mNext = v12;
        ++v4;
        v9 = (UFG::allocator::free_link *)((char *)v9 + 12);
      }
      while ( v4 < (unsigned int)v6 );
    }
  }
  UFG::RegionPolygon::RecalcCachedValues(v3, 1);
}

// File Line: 238
// RVA: 0x244460
void __fastcall UFG::RegionPolygon::PropertiesSave(UFG::RegionPolygon *this, UFG::qPropertySet *pProps)
{
  UFG::qPropertySet *v2; // rbx
  UFG::RegionPolygon *v3; // rsi
  UFG::qPropertyList *v4; // rax
  UFG::allocator::free_link *v5; // rdi
  UFG::qVector3 *v6; // rbx
  unsigned __int64 i; // rsi

  v2 = pProps;
  v3 = this;
  UFG::qPropertySet::Set<float>(pProps, (UFG::qSymbol *)&SimSym_ExtentAbove.mUID, this->mExtentAbove);
  UFG::qPropertySet::Set<float>(v2, (UFG::qSymbol *)&SimSym_ExtentBelow.mUID, v3->mExtentBelow);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(v2, (UFG::qSymbol *)&SimSym_Vertexes.mUID, DEPTH_RECURSE);
  v5 = (UFG::allocator::free_link *)v4;
  if ( v4 )
  {
    UFG::qPropertyList::RemoveAll(v4);
  }
  else
  {
    v5 = UFG::qPropertyList::Create("pVertList");
    UFG::qPropertySet::Set<UFG::qPropertyList>(v2, (UFG::qSymbol *)&SimSym_Vertexes.mUID, (UFG::qPropertyList *)v5);
  }
  v6 = v3->mpVerts;
  for ( i = (unsigned __int64)&v6[v3->mVertCount]; (unsigned __int64)v6 < i; ++v6 )
    UFG::qPropertyList::Add<UFG::qVector3>((UFG::qPropertyList *)v5, v6);
}

// File Line: 304
// RVA: 0x23E8A0
void __fastcall UFG::RegionPolygon::InsertVert(UFG::RegionPolygon *this, UFG::qVector3 *vert, unsigned int vertIdx)
{
  __int64 v3; // rsi
  UFG::qVector3 *v4; // r14
  UFG::RegionPolygon *v5; // rbp
  unsigned int v6; // edi
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  UFG::allocator::free_link *v21; // [rsp+50h] [rbp+8h]

  v3 = vertIdx;
  v4 = vert;
  v5 = this;
  v6 = this->mVertCount;
  v7 = 12i64 * (v6 + 1);
  if ( !is_mul_ok(v6 + 1, 0xCui64) )
    v7 = -1i64;
  v21 = UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
  UFG::qMemCopy(v21, v5->mpVerts, 12 * v3);
  v8 = 3 * v3;
  v9 = v4->y;
  v10 = v4->z;
  *((_DWORD *)&v21->mNext + v8) = LODWORD(v4->x);
  *((float *)&v21->mNext + v8 + 1) = v9;
  *((float *)&v21[1].mNext + v8) = v10;
  UFG::qMemCopy((char *)v21 + 4 * (3 * v3 + 3), &v5->mpVerts[v3], 12 * (v6 - v3));
  operator delete[](v5->mpVerts);
  v5->mpVerts = (UFG::qVector3 *)v21;
  if ( ++v5->mVertCount <= 3 )
  {
    UFG::RegionPolygon::RecalcCachedValues(v5, 1);
  }
  else
  {
    v11 = (float)(v5->mExtentAbove * v5->mNormal.y) + v4->y;
    v12 = (float)(v5->mExtentAbove * v5->mNormal.z) + v4->z;
    v13 = v5->mBoundingBox.mMax.x;
    if ( v13 <= (float)((float)(v5->mExtentAbove * v5->mNormal.x) + v4->x) )
      v13 = (float)(v5->mExtentAbove * v5->mNormal.x) + v4->x;
    v5->mBoundingBox.mMax.x = v13;
    v14 = v5->mBoundingBox.mMax.y;
    if ( v14 <= v11 )
      v14 = v11;
    v5->mBoundingBox.mMax.y = v14;
    v15 = v5->mBoundingBox.mMax.z;
    if ( v15 <= v12 )
      v15 = v12;
    v5->mBoundingBox.mMax.z = v15;
    v16 = (float)(v5->mExtentBelow * v5->mNormal.y) + v4->y;
    v17 = (float)(v5->mExtentBelow * v5->mNormal.z) + v4->z;
    v18 = v5->mBoundingBox.mMin.x;
    if ( v18 >= (float)((float)(v5->mExtentBelow * v5->mNormal.x) + v4->x) )
      v18 = (float)(v5->mExtentBelow * v5->mNormal.x) + v4->x;
    v5->mBoundingBox.mMin.x = v18;
    v19 = v5->mBoundingBox.mMin.y;
    if ( v19 >= v16 )
      v19 = v16;
    v5->mBoundingBox.mMin.y = v19;
    v20 = v5->mBoundingBox.mMin.z;
    if ( v20 >= v17 )
      v20 = v17;
    v5->mBoundingBox.mMin.z = v20;
  }
}

// File Line: 380
// RVA: 0x2457E0
void __fastcall UFG::RegionPolygon::SetShape(UFG::RegionPolygon *this, UFG::RegionPolygon::eShape shape, float extentAbove, float extentBelow)
{
  UFG::RegionPolygon::eShape v4; // edi
  UFG::RegionPolygon *v5; // rbx
  int v6; // edi
  unsigned __int64 v7; // rax
  _DWORD *v8; // rax
  _DWORD *v9; // rax
  UFG::qVector3 *v10; // rax
  unsigned __int64 v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::allocator::free_link *v14; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v15; // [rsp+60h] [rbp+8h]

  v4 = shape;
  v5 = this;
  if ( this->mVertCount )
  {
    this->mVertCount = 0;
    operator delete[](this->mpVerts);
    v5->mpVerts = 0i64;
    UFG::RegionPolygon::RecalcCachedValues(v5, 1);
  }
  v5->mExtentAbove = extentAbove;
  v5->mExtentBelow = extentBelow;
  v6 = v4 - 1;
  if ( v6 )
  {
    if ( v6 != 1 )
      return;
    v5->mVertCount = 4;
    v7 = 48i64;
    if ( !is_mul_ok(4ui64, 0xCui64) )
      v7 = -1i64;
    v14 = UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
    v5->mpVerts = (UFG::qVector3 *)v14;
    LODWORD(v14->mNext) = 1065353216;
    *(UFG::allocator::free_link **)((char *)&v14->mNext + 4) = (UFG::allocator::free_link *)1065353216;
    v8 = (_DWORD *)&v5->mpVerts->x;
    v8[3] = 1065353216;
    v8[4] = -1082130432;
    v8[5] = 0;
    v9 = (_DWORD *)&v5->mpVerts->x;
    v9[6] = -1082130432;
    v9[7] = -1082130432;
    v9[8] = 0;
    v10 = v5->mpVerts;
    v10[3].x = -1.0;
    *(_QWORD *)&v10[3].y = 1065353216i64;
  }
  else
  {
    v5->mVertCount = 1;
    v11 = 12i64;
    if ( !is_mul_ok(1ui64, 0xCui64) )
      v11 = -1i64;
    v15 = UFG::qMalloc(v11, "RegionPolygon.mpVerts", 0i64);
    v5->mpVerts = (UFG::qVector3 *)v15;
    v15->mNext = 0i64;
    LODWORD(v15[1].mNext) = 0;
  }
  v12 = UFG::qVector3::msDirUp.y;
  v13 = UFG::qVector3::msDirUp.z;
  v5->mNormal.x = UFG::qVector3::msDirUp.x;
  v5->mNormal.y = v12;
  v5->mNormal.z = v13;
  UFG::RegionPolygon::RecalcCachedValues(v5, 0);
}

// File Line: 418
// RVA: 0x245660
void __fastcall UFG::RegionPolygon::SetShape(UFG::RegionPolygon *this, UFG::RegionBase *region)
{
  UFG::RegionBase *v2; // rdi
  UFG::RegionPolygon *v3; // rbx
  int v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  int v7; // xmm2_4
  float v8; // xmm1_4
  int v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned __int64 v12; // rax
  __int64 v13; // [rsp+28h] [rbp-20h]
  float extentBelow[2]; // [rsp+30h] [rbp-18h]
  float extentAbove[2]; // [rsp+38h] [rbp-10h]
  UFG::allocator::free_link *v16; // [rsp+58h] [rbp+10h]

  v2 = region;
  v3 = this;
  if ( region->vfptr->GetType(region) == 8 )
  {
    if ( v3->mVertCount )
    {
      v3->mVertCount = 0;
      operator delete[](v3->mpVerts);
      v3->mpVerts = 0i64;
      UFG::RegionPolygon::RecalcCachedValues(v3, 1);
    }
    v3->mVertCount = v2[1].mRefCount;
    v3->mExtentAbove = *((float *)&v2[1].mRefCount + 1);
    v3->mExtentBelow = *(float *)&v2[2].vfptr;
    v4 = v2[2].mRefCount;
    v5 = *((float *)&v2[2].mRefCount + 1);
    v3->mCenter.x = *((float *)&v2[2].vfptr + 1);
    LODWORD(v3->mCenter.y) = v4;
    v3->mCenter.z = v5;
    v6 = *((float *)&v2[3].vfptr + 1);
    v7 = v2[3].mRefCount;
    v3->mNormal.x = *(float *)&v2[3].vfptr;
    v3->mNormal.y = v6;
    LODWORD(v3->mNormal.z) = v7;
    v3->mOrigDist = *((float *)&v2[3].mRefCount + 1);
    v8 = *((float *)&v2[4].vfptr + 1);
    v9 = v2[4].mRefCount;
    v3->mBoundingBox.mMin.x = *(float *)&v2[4].vfptr;
    v3->mBoundingBox.mMin.y = v8;
    LODWORD(v3->mBoundingBox.mMin.z) = v9;
    v10 = *(float *)&v2[5].vfptr;
    v11 = *((float *)&v2[5].vfptr + 1);
    v3->mBoundingBox.mMax.x = *((float *)&v2[4].mRefCount + 1);
    v3->mBoundingBox.mMax.y = v10;
    v3->mBoundingBox.mMax.z = v11;
    v12 = 12i64 * (unsigned int)v2[1].mRefCount;
    if ( !is_mul_ok((unsigned int)v2[1].mRefCount, 0xCui64) )
      v12 = -1i64;
    v16 = UFG::qMalloc(v12, "RegionPolygon.mpVerts", 0i64);
    v3->mpVerts = (UFG::qVector3 *)v16;
    UFG::qMemCopy(v16, v2[1].vfptr, 12 * v2[1].mRefCount);
  }
  v13 = 0i64;
  *(_QWORD *)extentBelow = 0i64;
  *(_QWORD *)extentAbove = 0i64;
  v2->vfptr->GetBoundingBox(v2, (UFG::qBox *)&v13);
  UFG::RegionPolygon::SetShape(v3, Shape_quad, extentAbove[1], extentBelow[0]);
}

// File Line: 454
// RVA: 0x23D400
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetClosestPointOutside(UFG::RegionPolygon *this, UFG::qVector3 *result, UFG::qVector3 *pos)
{
  UFG::qVector3 *v3; // r14
  UFG::qVector3 *v4; // rdi
  UFG::RegionPolygon *v5; // r12
  UFG::qVector3 *v6; // rax
  int v7; // ebp
  int v8; // ebx
  signed int v9; // er15
  float v10; // xmm6_4
  UFG::qVector3 *v11; // rsi
  float v12; // xmm7_4
  float v13; // xmm9_4
  float v14; // xmm8_4
  UFG::qVector3 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 *v20; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h]

  v3 = result;
  v4 = pos;
  v5 = this;
  if ( this->vfptr->IsHitPoint((UFG::RegionBase *)this, pos) )
  {
    v7 = v5->mVertCount - 1;
    v8 = 0;
    v9 = -1;
    v10 = FLOAT_9_9999996e24;
    if ( v7 > 0 )
    {
      v11 = v5->mpVerts;
      v12 = v4->x;
      v13 = v4->z;
      v14 = v4->y;
      do
      {
        v15 = UFG::qNearestSegPoint(&resulta, v11, v11 + 1, v4);
        v16 = fsqrt(
                (float)((float)((float)(v12 - v15->x) * (float)(v12 - v15->x))
                      + (float)((float)(v14 - v15->y) * (float)(v14 - v15->y)))
              + (float)((float)(v13 - v15->z) * (float)(v13 - v15->z)));
        if ( v16 < v10 )
        {
          v10 = v16;
          v9 = v8;
        }
        ++v8;
        ++v11;
      }
      while ( v8 < v7 );
    }
    v17 = v4->x;
    v18 = v4->y;
    v19 = v4->z;
    if ( v9 != -1 )
    {
      v20 = UFG::qNearestSegPoint(&resulta, &v5->mpVerts[v9], &v5->mpVerts[v9 + 1], v4);
      v17 = v20->x;
      v18 = v20->y;
      v19 = v20->z;
    }
    v3->x = v17;
    v3->y = v18;
    v6 = v3;
    v3->z = v19;
  }
  else
  {
    v3->x = v4->x;
    v3->y = v4->y;
    v3->z = v4->z;
    v6 = v3;
  }
  return v6;
}

// File Line: 493
// RVA: 0x2405B0
bool __fastcall UFG::RegionPolygon::IsHitPoint(UFG::RegionPolygon *this, UFG::qVector3 *pos)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  bool result; // al

  v2 = pos->x;
  if ( pos->x < this->mBoundingBox.mMin.x
    || v2 > this->mBoundingBox.mMax.x
    || (v3 = pos->y, v3 < this->mBoundingBox.mMin.y)
    || v3 > this->mBoundingBox.mMax.y
    || (v4 = pos->z, v4 < this->mBoundingBox.mMin.z)
    || v4 > this->mBoundingBox.mMax.z
    || (v5 = (float)((float)((float)(v3 * this->mNormal.y) + (float)(v2 * this->mNormal.x))
                   + (float)(v4 * this->mNormal.z))
           - this->mOrigDist,
        v5 < this->mExtentBelow)
    || v5 > this->mExtentAbove )
  {
    result = 0;
  }
  else
  {
    result = UFG::qIsBoundPointPolyXY(pos, this->mpVerts, this->mVertCount);
  }
  return result;
}

// File Line: 518
// RVA: 0x240920
bool __fastcall UFG::RegionPolygon::IsHitPointWS(UFG::RegionPolygon *this, UFG::qVector3 *pos, UFG::qMatrix44 *localWorld)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  UFG::qVector3 *v5; // rdi
  UFG::RegionPolygon *v6; // rbx
  float v7; // xmm8_4
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm4_4
  __m128 v11; // xmm2
  float v12; // xmm8_4
  float v13; // xmm0_4
  float v14; // xmm8_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  __m128 v17; // xmm2
  float v18; // xmm0_4
  __m128 v19; // xmm4
  float v20; // xmm2_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm2_4
  unsigned int v26; // er8
  UFG::qVector3 *v27; // rdx
  UFG::qVector3 posXY; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 d; // [rsp+30h] [rbp-78h]

  v3 = this->mCenter.x;
  v4 = this->mCenter.z;
  v5 = pos;
  v6 = this;
  v7 = v3;
  v8 = this->mCenter.y;
  v10 = (float)(v3 * localWorld->v0.z) + (float)(v8 * localWorld->v1.z);
  v11 = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v12 = (float)(v7 * localWorld->v0.y) + (float)(v8 * localWorld->v1.y);
  v13 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v14 = (float)(v12 + (float)(this->mCenter.z * localWorld->v2.y)) + localWorld->v3.y;
  v15 = (float)(v10 + (float)(v4 * localWorld->v2.z)) + localWorld->v3.z;
  v11.m128_f32[0] = (float)((float)((float)(v11.m128_f32[0] - this->mBoundingBox.mMin.y)
                                  * (float)(v11.m128_f32[0] - this->mBoundingBox.mMin.y))
                          + (float)((float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
                                  * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)))
                  + (float)(v13 * v13);
  v16 = COERCE_FLOAT(_mm_sqrt_ps(v11)) * 0.5;
  if ( v16 <= this->mExtentAbove )
    v16 = this->mExtentAbove;
  if ( v16 <= this->mExtentBelow )
    v16 = this->mExtentBelow;
  v17 = (__m128)LODWORD(pos->y);
  v18 = pos->z - v15;
  v19 = (__m128)LODWORD(localWorld->v2.y);
  v19.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(localWorld->v2.x * localWorld->v2.x))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v9 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
             + (float)(localWorld->v2.x * v4))
     + localWorld->v3.x;
  v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v14) * (float)(v17.m128_f32[0] - v14))
                          + (float)((float)(pos->x - v9) * (float)(pos->x - v9)))
                  + (float)(v18 * v18);
  if ( COERCE_FLOAT(_mm_sqrt_ps(v17)) > (float)(COERCE_FLOAT(_mm_sqrt_ps(v19)) * v16) )
    return 0;
  UFG::qInverse(&d, localWorld);
  v20 = v5->y;
  v21 = v5->z;
  v22 = (float)((float)((float)(d.v1.x * v20) + (float)(d.v0.x * v5->x)) + (float)(d.v2.x * v21)) + d.v3.x;
  v23 = (float)((float)((float)(d.v1.y * v20) + (float)(d.v0.y * v5->x)) + (float)(d.v2.y * v21)) + d.v3.y;
  v24 = (float)((float)((float)(d.v1.z * v20) + (float)(d.v0.z * v5->x)) + (float)(d.v2.z * v21)) + d.v3.z;
  v25 = (float)((float)((float)(v23 * v6->mNormal.y) + (float)(v22 * v6->mNormal.x)) + (float)(v24 * v6->mNormal.z))
      - v6->mOrigDist;
  if ( v25 < v6->mExtentBelow || v25 > v6->mExtentAbove )
    return 0;
  v26 = v6->mVertCount;
  v27 = v6->mpVerts;
  posXY.x = v22;
  posXY.y = v23;
  posXY.z = v24;
  return UFG::qIsBoundPointPolyXY(&posXY, v27, v26);
}

// File Line: 563
// RVA: 0x241FE0
char __fastcall UFG::RegionPolygon::IsHitSegment(UFG::RegionPolygon *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rdi
  UFG::RegionPolygon *v5; // rbx
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // r14
  float v8; // xmm3_4
  UFG::qVector3 *v9; // kr00_8
  unsigned int v10; // er9
  UFG::qVector3 *v11; // r8
  float v12; // xmm9_4
  float v13; // xmm8_4
  float v14; // xmm10_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  char result; // al
  float v24; // xmm5_4
  float v25; // xmm4_4
  UFG::qVector3 v26; // [rsp+18h] [rbp-49h]
  UFG::qVector3 *hit_enter_p; // [rsp+28h] [rbp-39h]
  UFG::qVector3 *hit_exit_p; // [rsp+30h] [rbp-31h]
  UFG::qVector3 endXY; // [rsp+38h] [rbp-29h]
  UFG::qVector3 startXY; // [rsp+48h] [rbp-19h]
  float pPDist; // [rsp+C8h] [rbp+67h]

  v4 = pHitPos;
  v5 = this;
  v6 = end;
  v7 = start;
  if ( !UFG::qBox::IsHitSeg(&this->mBoundingBox, start, end, 0i64, 0i64) )
    return 0;
  v8 = v5->mOrigDist;
  hit_exit_p = &v26;
  if ( !(unsigned int)UFG::qIntersectSegSlab(
                        v7,
                        v6,
                        &v5->mNormal,
                        v8 + v5->mExtentBelow,
                        v8 + v5->mExtentAbove,
                        (UFG::qVector3 *)&hit_enter_p,
                        &v26) )
    return 0;
  v9 = hit_enter_p;
  v10 = v5->mVertCount;
  v11 = v5->mpVerts;
  hit_enter_p = 0i64;
  v12 = v5->mNormal.y;
  v13 = v5->mNormal.x;
  v14 = v5->mNormal.z;
  v15 = (float)((float)((float)(v5->mNormal.x * *(float *)&v9) + (float)(v5->mNormal.y * *((float *)&v9 + 1)))
              + (float)(v5->mNormal.z * *(float *)&hit_exit_p))
      - v5->mOrigDist;
  v16 = v5->mNormal.x * v15;
  v17 = v5->mNormal.z * v15;
  v18 = v5->mNormal.y * v15;
  v19 = v5->mNormal.x;
  v20 = *(float *)&v9 - v16;
  v21 = v5->mNormal.y;
  startXY.x = v20;
  startXY.z = *(float *)&hit_exit_p - v17;
  startXY.y = *((float *)&v9 + 1) - v18;
  v22 = (float)((float)((float)(v19 * v26.x) + (float)(v21 * v26.y)) + (float)(v14 * v26.z)) - v5->mOrigDist;
  endXY.x = v26.x - (float)(v13 * v22);
  endXY.y = v26.y - (float)(v12 * v22);
  endXY.z = v26.z - (float)(v14 * v22);
  if ( !v4 )
    return UFG::qIntersectSegPolyXY(&startXY, &endXY, v11, v10, 0i64, hit_enter_p);
  if ( !UFG::qIntersectSegPolyXY(&startXY, &endXY, v11, v10, &pPDist, hit_enter_p) )
    return 0;
  result = 1;
  v24 = (float)((float)(v26.y - *((float *)&hit_enter_p + 1)) * pPDist) + *((float *)&hit_enter_p + 1);
  v25 = (float)((float)(v26.z - *(float *)&hit_exit_p) * pPDist) + *(float *)&hit_exit_p;
  v4->x = (float)((float)(v26.x - *(float *)&hit_enter_p) * pPDist) + *(float *)&hit_enter_p;
  v4->y = v24;
  v4->z = v25;
  return result;
}

// File Line: 617
// RVA: 0x2428F0
bool __fastcall UFG::RegionPolygon::IsHitSegmentWS(UFG::RegionPolygon *this, UFG::qVector3 *start, UFG::qVector3 *end, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm3_4
  float v6; // xmm4_4
  UFG::qMatrix44 *v7; // rbx
  UFG::qVector3 *v8; // rsi
  UFG::qVector3 *v9; // r14
  UFG::RegionPolygon *v10; // rdi
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  __m128 v14; // xmm2
  float v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm8_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  __m128 v22; // xmm1
  float v23; // xmm6_4
  UFG::qVector3 *v24; // rax
  bool v25; // al
  UFG::RegionBaseVtbl *v26; // rax
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm13_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm13_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h]
  float v39; // [rsp+2Ch] [rbp-6Dh]
  UFG::qVector3 result; // [rsp+30h] [rbp-69h]
  float v41; // [rsp+3Ch] [rbp-5Dh]
  float v42; // [rsp+40h] [rbp-59h]
  float v43; // [rsp+48h] [rbp-51h]
  float v44; // [rsp+4Ch] [rbp-4Dh]
  float v45; // [rsp+50h] [rbp-49h]
  float v46; // [rsp+58h] [rbp-41h]
  float v47; // [rsp+5Ch] [rbp-3Dh]
  float v48; // [rsp+60h] [rbp-39h]
  float v49; // [rsp+F8h] [rbp+5Fh]
  float *v50; // [rsp+118h] [rbp+7Fh]

  v5 = this->mCenter.z;
  v6 = localWorld->v2.x;
  v7 = localWorld;
  v8 = end;
  v9 = start;
  v10 = this;
  v11 = this->mCenter.x;
  v12 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
              + (float)(localWorld->v2.x * v5))
      + localWorld->v3.x;
  v13 = (float)(this->mCenter.y * localWorld->v1.z) + (float)(v11 * localWorld->v0.z);
  v14 = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v14.m128_f32[0] = (float)(v14.m128_f32[0] - this->mBoundingBox.mMin.y)
                  * (float)(v14.m128_f32[0] - this->mBoundingBox.mMin.y);
  v15 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v16 = (float)((float)((float)(v11 * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y))
              + (float)(this->mCenter.z * localWorld->v2.y))
      + localWorld->v3.y;
  v17 = this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x;
  v18 = v13 + (float)(v5 * localWorld->v2.z);
  pos.x = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
                + (float)(localWorld->v2.x * v5))
        + localWorld->v3.x;
  v19 = v18 + localWorld->v3.z;
  pos.y = v16;
  v14.m128_f32[0] = (float)(v14.m128_f32[0] + (float)(v17 * v17)) + (float)(v15 * v15);
  v20 = this->mExtentAbove;
  pos.z = v19;
  v21 = COERCE_FLOAT(_mm_sqrt_ps(v14)) * 0.5;
  if ( v21 <= v20 )
    v21 = v20;
  if ( v21 <= this->mExtentBelow )
    v21 = this->mExtentBelow;
  v22 = (__m128)LODWORD(localWorld->v2.y);
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v6 * v6))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v23 = COERCE_FLOAT(_mm_sqrt_ps(v22)) * v21;
  v24 = UFG::qNearestSegPoint(&result, start, end, &pos);
  if ( (float)((float)((float)((float)(v16 - v24->y) * (float)(v16 - v24->y))
                     + (float)((float)(v12 - v24->x) * (float)(v12 - v24->x)))
             + (float)((float)(v19 - v24->z) * (float)(v19 - v24->z))) > (float)(v23 * v23) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, v7);
  v26 = v10->vfptr;
  v27 = v9->x;
  v28 = v9->y;
  v29 = v9->z;
  v30 = v42 * v28;
  v49 = (float)((float)((float)(result.z * v28) + (float)(pos.z * v9->x)) + (float)(v43 * v29)) + v46;
  v31 = v8->z;
  v32 = result.x;
  v33 = v30 + (float)(result.x * v27);
  v34 = v8->y;
  v35 = v8->x;
  result.x = v49;
  pos.y = (float)((float)((float)(v41 * v34) + (float)(v39 * v35)) + (float)(v44 * v31)) + v47;
  pos.z = (float)((float)((float)(v42 * v34) + (float)(v32 * v35)) + (float)(v45 * v31)) + v48;
  pos.x = (float)(v33 + (float)(v45 * v29)) + v48;
  v25 = v26->IsHitSegment((UFG::RegionBase *)&v10->vfptr, &result, &pos, (UFG::qVector3 *)v50);
  if ( v50 )
  {
    v36 = (float)((float)((float)(v50[1] * v7->v1.y) + (float)(*v50 * v7->v0.y)) + (float)(v50[2] * v7->v2.y))
        + v7->v3.y;
    v37 = (float)((float)((float)(v50[1] * v7->v1.z) + (float)(*v50 * v7->v0.z)) + (float)(v50[2] * v7->v2.z))
        + v7->v3.z;
    *v50 = (float)((float)((float)(v50[1] * v7->v1.x) + (float)(*v50 * v7->v0.x)) + (float)(v50[2] * v7->v2.x))
         + v7->v3.x;
    v50[1] = v36;
    v50[2] = v37;
  }
  return v25;
}

// File Line: 664
// RVA: 0x23F8B0
char __fastcall UFG::RegionPolygon::IsHitPlaneRay(UFG::RegionPolygon *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::RegionPolygon *v4; // rbx
  UFG::qVector3 *v5; // rdi
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector3 posXY; // [rsp+30h] [rbp-18h]

  v4 = this;
  v5 = pHitPos;
  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &this->mNormal, this->mOrigDist, &posXY)
    || posXY.x < v4->mBoundingBox.mMin.x
    || posXY.x > v4->mBoundingBox.mMax.x
    || posXY.y < v4->mBoundingBox.mMin.y
    || posXY.y > v4->mBoundingBox.mMax.y
    || posXY.z < v4->mBoundingBox.mMin.z
    || posXY.z > v4->mBoundingBox.mMax.z
    || !(unsigned __int8)UFG::qIsBoundPointPolyXY(&posXY, v4->mpVerts, v4->mVertCount) )
  {
    return 0;
  }
  if ( v5 )
  {
    v6 = posXY.y;
    v5->x = posXY.x;
    v7 = posXY.z;
    v5->y = v6;
    v5->z = v7;
  }
  return 1;
}

// File Line: 710
// RVA: 0x23FEA0
bool __fastcall UFG::RegionPolygon::IsHitPlaneRayWS(UFG::RegionPolygon *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm5_4
  UFG::qMatrix44 *v6; // rbx
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // r14
  UFG::RegionPolygon *v9; // rdi
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  __m128 v15; // xmm2
  float v16; // xmm3_4
  __m128 v17; // xmm1
  float v18; // xmm6_4
  bool result; // al
  float v20; // xmm3_4
  float v21; // xmm2_4
  UFG::RegionBaseVtbl *v22; // rax
  float v23; // xmm4_4
  float v24; // xmm13_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm13_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h]
  float v33; // [rsp+2Ch] [rbp-6Dh]
  float v34; // [rsp+30h] [rbp-69h]
  float v35; // [rsp+38h] [rbp-61h]
  float v36; // [rsp+3Ch] [rbp-5Dh]
  float v37; // [rsp+40h] [rbp-59h]
  float v38; // [rsp+48h] [rbp-51h]
  float v39; // [rsp+4Ch] [rbp-4Dh]
  float v40; // [rsp+50h] [rbp-49h]
  float v41; // [rsp+58h] [rbp-41h]
  float v42; // [rsp+5Ch] [rbp-3Dh]
  float v43; // [rsp+60h] [rbp-39h]
  float v44; // [rsp+F8h] [rbp+5Fh]
  float *v45; // [rsp+118h] [rbp+7Fh]

  v5 = this->mCenter.z;
  v6 = localWorld;
  v7 = rayDir;
  v8 = rayPos;
  v9 = this;
  v10 = localWorld->v2.x;
  v11 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
              + (float)(localWorld->v2.x * v5))
      + localWorld->v3.x;
  v12 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v13 = (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
      * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x);
  v14 = (float)((float)((float)(this->mCenter.y * localWorld->v1.z) + (float)(this->mCenter.x * localWorld->v0.z))
              + (float)(v5 * localWorld->v2.z))
      + localWorld->v3.z;
  pos.y = (float)((float)((float)(this->mCenter.x * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y))
                + (float)(this->mCenter.z * localWorld->v2.y))
        + localWorld->v3.y;
  v15 = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v15.m128_f32[0] = v15.m128_f32[0] - this->mBoundingBox.mMin.y;
  pos.x = v11;
  pos.z = v14;
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + v13) + (float)(v12 * v12);
  v16 = COERCE_FLOAT(_mm_sqrt_ps(v15)) * 0.5;
  if ( v16 <= this->mExtentAbove )
    v16 = this->mExtentAbove;
  if ( v16 <= this->mExtentBelow )
    v16 = this->mExtentBelow;
  v17 = (__m128)LODWORD(localWorld->v2.y);
  v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v10 * v10))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v18 = COERCE_FLOAT(_mm_sqrt_ps(v17)) * v16;
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, &pos) > (float)(v18 * v18) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, v6);
  v20 = v8->x;
  v21 = v8->y;
  v22 = v9->vfptr;
  v23 = v8->z;
  v24 = v37 * v21;
  v44 = (float)((float)((float)(v35 * v21) + (float)(pos.z * v8->x)) + (float)(v38 * v23)) + v41;
  v25 = v7->z;
  v26 = v34;
  v27 = v24 + (float)(v34 * v20);
  v28 = v7->y;
  v29 = v7->x;
  v34 = v44;
  pos.y = (float)((float)((float)(v36 * v28) + (float)(v33 * v29)) + (float)(v39 * v25)) + v42;
  pos.z = (float)((float)((float)(v37 * v28) + (float)(v26 * v29)) + (float)(v40 * v25)) + v43;
  pos.x = (float)(v27 + (float)(v40 * v23)) + v43;
  result = v22->IsHitPlaneRay((UFG::RegionBase *)&v9->vfptr, (UFG::qVector3 *)&v34, &pos, (UFG::qVector3 *)v45);
  if ( v45 )
  {
    v30 = (float)((float)((float)(v45[1] * v6->v1.y) + (float)(*v45 * v6->v0.y)) + (float)(v45[2] * v6->v2.y))
        + v6->v3.y;
    v31 = (float)((float)((float)(v45[1] * v6->v1.z) + (float)(*v45 * v6->v0.z)) + (float)(v45[2] * v6->v2.z))
        + v6->v3.z;
    *v45 = (float)((float)((float)(v45[1] * v6->v1.x) + (float)(*v45 * v6->v0.x)) + (float)(v45[2] * v6->v2.x))
         + v6->v3.x;
    v45[1] = v30;
    v45[2] = v31;
  }
  return result;
}

// File Line: 756
// RVA: 0x240D10
char __fastcall UFG::RegionPolygon::IsHitRay(UFG::RegionPolygon *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qVector3 *pHitPos)
{
  UFG::qVector3 *v4; // rdi
  UFG::RegionPolygon *v5; // rbx
  UFG::qVector3 *v6; // rsi
  UFG::qVector3 *v7; // r14
  float v8; // xmm3_4
  UFG::qVector3 *v9; // kr00_8
  unsigned int v10; // er9
  UFG::qVector3 *v11; // r8
  float v12; // xmm9_4
  float v13; // xmm8_4
  float v14; // xmm10_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  char result; // al
  float v24; // xmm5_4
  float v25; // xmm4_4
  UFG::qVector3 v26; // [rsp+18h] [rbp-49h]
  UFG::qVector3 *hit_enter_p; // [rsp+28h] [rbp-39h]
  UFG::qVector3 *hit_exit_p; // [rsp+30h] [rbp-31h]
  UFG::qVector3 endXY; // [rsp+38h] [rbp-29h]
  UFG::qVector3 startXY; // [rsp+48h] [rbp-19h]
  float pPDist; // [rsp+C8h] [rbp+67h]

  v4 = pHitPos;
  v5 = this;
  v6 = rayDir;
  v7 = rayPos;
  if ( !UFG::qBox::IsHitRay(&this->mBoundingBox, rayPos, rayDir, 0i64, 0i64) )
    return 0;
  v8 = v5->mOrigDist;
  hit_exit_p = &v26;
  if ( !(unsigned int)UFG::qIntersectRaySlab(
                        v7,
                        v6,
                        &v5->mNormal,
                        v8 + v5->mExtentBelow,
                        v8 + v5->mExtentAbove,
                        (UFG::qVector3 *)&hit_enter_p,
                        &v26) )
    return 0;
  v9 = hit_enter_p;
  v10 = v5->mVertCount;
  v11 = v5->mpVerts;
  hit_enter_p = 0i64;
  v12 = v5->mNormal.y;
  v13 = v5->mNormal.x;
  v14 = v5->mNormal.z;
  v15 = (float)((float)((float)(v5->mNormal.x * *(float *)&v9) + (float)(v5->mNormal.y * *((float *)&v9 + 1)))
              + (float)(v5->mNormal.z * *(float *)&hit_exit_p))
      - v5->mOrigDist;
  v16 = v5->mNormal.x * v15;
  v17 = v5->mNormal.z * v15;
  v18 = v5->mNormal.y * v15;
  v19 = v5->mNormal.x;
  v20 = *(float *)&v9 - v16;
  v21 = v5->mNormal.y;
  startXY.x = v20;
  startXY.z = *(float *)&hit_exit_p - v17;
  startXY.y = *((float *)&v9 + 1) - v18;
  v22 = (float)((float)((float)(v19 * v26.x) + (float)(v21 * v26.y)) + (float)(v14 * v26.z)) - v5->mOrigDist;
  endXY.x = v26.x - (float)(v13 * v22);
  endXY.y = v26.y - (float)(v12 * v22);
  endXY.z = v26.z - (float)(v14 * v22);
  if ( !v4 )
    return UFG::qIntersectSegPolyXY(&startXY, &endXY, v11, v10, 0i64, hit_enter_p);
  if ( !UFG::qIntersectSegPolyXY(&startXY, &endXY, v11, v10, &pPDist, hit_enter_p) )
    return 0;
  result = 1;
  v24 = (float)((float)(v26.y - *((float *)&hit_enter_p + 1)) * pPDist) + *((float *)&hit_enter_p + 1);
  v25 = (float)((float)(v26.z - *(float *)&hit_exit_p) * pPDist) + *(float *)&hit_exit_p;
  v4->x = (float)((float)(v26.x - *(float *)&hit_enter_p) * pPDist) + *(float *)&hit_enter_p;
  v4->y = v24;
  v4->z = v25;
  return result;
}

// File Line: 811
// RVA: 0x2414A0
bool __fastcall UFG::RegionPolygon::IsHitRayWS(UFG::RegionPolygon *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, UFG::qMatrix44 *localWorld, UFG::qVector3 *pHitPos)
{
  float v5; // xmm5_4
  UFG::qMatrix44 *v6; // rbx
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // r14
  UFG::RegionPolygon *v9; // rdi
  float v10; // xmm7_4
  float v11; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  __m128 v15; // xmm2
  float v16; // xmm3_4
  __m128 v17; // xmm1
  float v18; // xmm6_4
  bool result; // al
  float v20; // xmm3_4
  float v21; // xmm2_4
  UFG::RegionBaseVtbl *v22; // rax
  float v23; // xmm4_4
  float v24; // xmm13_4
  float v25; // xmm2_4
  float v26; // xmm5_4
  float v27; // xmm13_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h]
  float v33; // [rsp+2Ch] [rbp-6Dh]
  float v34; // [rsp+30h] [rbp-69h]
  float v35; // [rsp+38h] [rbp-61h]
  float v36; // [rsp+3Ch] [rbp-5Dh]
  float v37; // [rsp+40h] [rbp-59h]
  float v38; // [rsp+48h] [rbp-51h]
  float v39; // [rsp+4Ch] [rbp-4Dh]
  float v40; // [rsp+50h] [rbp-49h]
  float v41; // [rsp+58h] [rbp-41h]
  float v42; // [rsp+5Ch] [rbp-3Dh]
  float v43; // [rsp+60h] [rbp-39h]
  float v44; // [rsp+F8h] [rbp+5Fh]
  float *v45; // [rsp+118h] [rbp+7Fh]

  v5 = this->mCenter.z;
  v6 = localWorld;
  v7 = rayDir;
  v8 = rayPos;
  v9 = this;
  v10 = localWorld->v2.x;
  v11 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
              + (float)(localWorld->v2.x * v5))
      + localWorld->v3.x;
  v12 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v13 = (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
      * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x);
  v14 = (float)((float)((float)(this->mCenter.y * localWorld->v1.z) + (float)(this->mCenter.x * localWorld->v0.z))
              + (float)(v5 * localWorld->v2.z))
      + localWorld->v3.z;
  pos.y = (float)((float)((float)(this->mCenter.x * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y))
                + (float)(this->mCenter.z * localWorld->v2.y))
        + localWorld->v3.y;
  v15 = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v15.m128_f32[0] = v15.m128_f32[0] - this->mBoundingBox.mMin.y;
  pos.x = v11;
  pos.z = v14;
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + v13) + (float)(v12 * v12);
  v16 = COERCE_FLOAT(_mm_sqrt_ps(v15)) * 0.5;
  if ( v16 <= this->mExtentAbove )
    v16 = this->mExtentAbove;
  if ( v16 <= this->mExtentBelow )
    v16 = this->mExtentBelow;
  v17 = (__m128)LODWORD(localWorld->v2.y);
  v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v10 * v10))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v18 = COERCE_FLOAT(_mm_sqrt_ps(v17)) * v16;
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, &pos) > (float)(v18 * v18) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, v6);
  v20 = v8->x;
  v21 = v8->y;
  v22 = v9->vfptr;
  v23 = v8->z;
  v24 = v37 * v21;
  v44 = (float)((float)((float)(v35 * v21) + (float)(pos.z * v8->x)) + (float)(v38 * v23)) + v41;
  v25 = v7->z;
  v26 = v34;
  v27 = v24 + (float)(v34 * v20);
  v28 = v7->y;
  v29 = v7->x;
  v34 = v44;
  pos.y = (float)((float)((float)(v36 * v28) + (float)(v33 * v29)) + (float)(v39 * v25)) + v42;
  pos.z = (float)((float)((float)(v37 * v28) + (float)(v26 * v29)) + (float)(v40 * v25)) + v43;
  pos.x = (float)(v27 + (float)(v40 * v23)) + v43;
  result = v22->IsHitRay((UFG::RegionBase *)&v9->vfptr, (UFG::qVector3 *)&v34, &pos, (UFG::qVector3 *)v45);
  if ( v45 )
  {
    v30 = (float)((float)((float)(v45[1] * v6->v1.y) + (float)(*v45 * v6->v0.y)) + (float)(v45[2] * v6->v2.y))
        + v6->v3.y;
    v31 = (float)((float)((float)(v45[1] * v6->v1.z) + (float)(*v45 * v6->v0.z)) + (float)(v45[2] * v6->v2.z))
        + v6->v3.z;
    *v45 = (float)((float)((float)(v45[1] * v6->v1.x) + (float)(*v45 * v6->v0.x)) + (float)(v45[2] * v6->v2.x))
         + v6->v3.x;
    v45[1] = v30;
    v45[2] = v31;
  }
  return result;
}

// File Line: 851
// RVA: 0x23A7D0
signed __int64 __fastcall UFG::RegionPolygon::CycleAspect(UFG::RegionPolygon *this, unsigned int aspect, bool forward)
{
  unsigned int v3; // edx
  signed __int64 result; // rax

  if ( forward )
  {
    v3 = aspect + 1;
    if ( v3 == this->mVertCount )
    {
      result = 4294967195i64;
    }
    else
    {
      if ( v3 > 0xFFFFFF9C )
        v3 = 0;
      result = v3;
    }
  }
  else if ( aspect )
  {
    if ( aspect == -101 )
      result = this->mVertCount - 1;
    else
      result = aspect - 1;
  }
  else
  {
    result = 4294967196i64;
  }
  return result;
}

// File Line: 898
// RVA: 0x23C380
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetAspectCenter(UFG::RegionPolygon *this, UFG::qVector3 *result, unsigned int aspect)
{
  UFG::qVector3 *v3; // rcx
  signed __int64 v4; // r8
  UFG::qVector3 *v5; // rax
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4

  if ( aspect < this->mVertCount )
  {
    v3 = this->mpVerts;
    v4 = aspect;
    result->x = v3[v4].x;
    result->y = v3[v4].y;
    result->z = v3[v4].z;
    return result;
  }
  if ( aspect == -101 )
  {
    v6 = this->mExtentAbove;
  }
  else
  {
    if ( aspect != -100 )
    {
      result->x = this->mCenter.x;
      result->y = this->mCenter.y;
      result->z = this->mCenter.z;
      return result;
    }
    v6 = this->mExtentBelow;
  }
  v5 = result;
  v7 = (float)(v6 * this->mNormal.y) + this->mCenter.y;
  v8 = (float)(v6 * this->mNormal.x) + this->mCenter.x;
  result->z = (float)(v6 * this->mNormal.z) + this->mCenter.z;
  result->y = v7;
  result->x = v8;
  return v5;
}

// File Line: 922
// RVA: 0x23C6B0
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetAspectNormal(UFG::RegionPolygon *this, UFG::qVector3 *result, unsigned int aspect)
{
  unsigned int v3; // er11
  UFG::RegionPolygon *v4; // r10
  __int64 v5; // rax
  float v6; // xmm2_4
  __m128 v7; // xmm5
  float v8; // xmm6_4
  signed __int64 v9; // rcx
  UFG::qVector3 *v10; // r8
  signed __int64 v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  __m128 v18; // xmm3
  UFG::qVector3 *v19; // rax
  int v20; // xmm1_4
  float v21; // xmm0_4

  v3 = this->mVertCount;
  v4 = this;
  if ( aspect >= v3 )
  {
    if ( aspect == -100 )
    {
      v19 = result;
      v20 = LODWORD(this->mNormal.z) ^ _xmm[0];
      LODWORD(result->x) = LODWORD(this->mNormal.x) ^ _xmm[0];
      v21 = this->mNormal.y;
      LODWORD(result->z) = v20;
      LODWORD(result->y) = LODWORD(v21) ^ _xmm[0];
    }
    else
    {
      result->x = this->mNormal.x;
      result->y = this->mNormal.y;
      result->z = this->mNormal.z;
      v19 = result;
    }
  }
  else
  {
    v5 = v3 - 1;
    if ( aspect )
      v5 = aspect - 1;
    v6 = this->mNormal.y;
    v7 = (__m128)LODWORD(this->mNormal.z);
    v8 = this->mNormal.x;
    v9 = aspect + 1;
    v10 = v4->mpVerts;
    if ( (_DWORD)v9 == v3 )
      v9 = 0i64;
    v11 = v9;
    v12 = v10[v11].y - v10[v5].y;
    v13 = v10[v11].z - v10[v5].z;
    v14 = v10[v11].x - v10[v5].x;
    v15 = (float)(v4->mNormal.y * v13) - (float)(v4->mNormal.z * v12);
    v7.m128_f32[0] = (float)(v7.m128_f32[0] * v14) - (float)(v8 * v13);
    v16 = (float)(v8 * v12) - (float)(v6 * v14);
    v17 = 0.0;
    v18 = v7;
    v18.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v15 * v15)) + (float)(v16 * v16);
    if ( v18.m128_f32[0] != 0.0 )
      v17 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
    v19 = result;
    result->x = v15 * v17;
    result->z = v16 * v17;
    result->y = v7.m128_f32[0] * v17;
  }
  return v19;
}

// File Line: 945
// RVA: 0x23E7F0
__int64 __fastcall UFG::RegionPolygon::InsertAspect(UFG::RegionPolygon *this, unsigned int aspect)
{
  unsigned int v2; // eax
  UFG::qVector3 *v3; // r8
  __int64 v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm1_4
  UFG::qVector3 vert; // [rsp+20h] [rbp-18h]

  v2 = this->mVertCount;
  if ( aspect >= v2 )
    return aspect;
  v3 = this->mpVerts;
  v4 = aspect + 1;
  if ( (unsigned int)v4 >= v2 )
    v4 = 0i64;
  v5 = v3[v4].y + v3[aspect].y;
  v6 = v3[v4].z + v3[aspect].z;
  vert.x = (float)(v3[v4].x + v3[aspect].x) * 0.5;
  vert.y = v5 * 0.5;
  vert.z = v6 * 0.5;
  UFG::RegionPolygon::InsertVert(this, &vert, v4);
  return (unsigned int)v4;
}

// File Line: 975
// RVA: 0x23F6B0
char __fastcall UFG::RegionPolygon::IsHitAspect(UFG::RegionPolygon *this, UFG::qVector3 *rayPos, UFG::qVector3 *rayDir, unsigned int *pHitAspect)
{
  unsigned int v4; // er14
  int v5; // er13
  UFG::RegionPolygon *v6; // rsi
  UFG::qVector3 *v7; // rcx
  unsigned int *v8; // rdi
  UFG::qVector3 *v9; // r15
  float v10; // xmm6_4
  UFG::qVector3 *v11; // r12
  signed int v12; // ebp
  signed int v13; // ebx
  float v14; // xmm0_4
  char result; // al
  UFG::RegionBaseVtbl *v16; // rax
  float v17; // [rsp+20h] [rbp-58h]
  float v18; // [rsp+24h] [rbp-54h]
  float v19; // [rsp+28h] [rbp-50h]

  v4 = this->mVertCount;
  v5 = 0;
  v6 = this;
  v7 = this->mpVerts;
  v8 = pHitAspect;
  v9 = rayDir;
  v10 = FLOAT_0_0099999998;
  v11 = rayPos;
  v12 = -99;
  v13 = 0;
  while ( 1 )
  {
    v14 = UFG::qDistanceSqrRayPoint(v11, v9, &v7[v13]);
    if ( v14 < v10 )
    {
      if ( !v8 )
        return 1;
      v12 = v13;
      v10 = v14;
    }
    if ( ++v13 > v4 )
      break;
    v7 = v6->mpVerts;
  }
  if ( v10 != 0.0099999998 )
  {
    *v8 = v12;
    return 1;
  }
  v16 = v6->vfptr;
  if ( !v8 )
    return v16->IsHitRay((UFG::RegionBase *)&v6->vfptr, v11, v9, 0i64);
  if ( !v16->IsHitRay((UFG::RegionBase *)&v6->vfptr, v11, v9, (UFG::qVector3 *)&v17) )
    return 0;
  result = 1;
  LOBYTE(v5) = (float)((float)((float)((float)(v18 * v6->mNormal.y) + (float)(v17 * v6->mNormal.x))
                             + (float)(v19 * v6->mNormal.z))
                     - v6->mOrigDist) < 0.0;
  *v8 = v5 - 101;
  return result;
}

// File Line: 1050
// RVA: 0x245080
__int64 __fastcall UFG::RegionPolygon::RemoveAspect(UFG::RegionPolygon *this, unsigned int aspect)
{
  unsigned int v2; // er8
  unsigned int v3; // ebx
  UFG::RegionPolygon *v4; // rdi
  UFG::qVector3 *v5; // rax
  unsigned int v6; // er8

  v2 = this->mVertCount;
  v3 = aspect;
  v4 = this;
  if ( aspect < v2 && v2 > 1 )
  {
    v5 = this->mpVerts;
    v6 = v2 - 1;
    this->mVertCount = v6;
    UFG::qMemMove(&v5[aspect], &v5[aspect + 1], 12 * (v6 - aspect));
    UFG::RegionPolygon::RecalcCachedValues(v4, 1);
    if ( v3 == v4->mVertCount )
      v3 = 0;
  }
  return v3;
}

// File Line: 1073
// RVA: 0x2462C0
void __fastcall UFG::RegionPolygon::TranslateAspect(UFG::RegionPolygon *this, unsigned int aspect, UFG::qVector3 *delta)
{
  signed __int64 v3; // rdx
  UFG::qVector3 *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4
  UFG::qVector3 *v7; // rax
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm2_4

  if ( aspect < this->mVertCount )
  {
    v3 = aspect;
    v4 = this->mpVerts;
    v5 = delta->y + v4[v3].y;
    v6 = delta->z + v4[v3].z;
    v4[v3].x = delta->x + v4[v3].x;
    v4[v3].y = v5;
    v4[v3].z = v6;
    if ( this->mVertCount >= 4 )
    {
      v7 = this->mpVerts;
      v8 = this->mNormal.x;
      v9 = this->mNormal.z;
      v10 = v7[v3].y;
      v11 = v7[v3].z;
      v12 = v7[v3].x;
      v13 = (float)((float)((float)(v8 * v12) + (float)(this->mNormal.y * v10)) + (float)(v9 * v11)) - this->mOrigDist;
      v7[v3].y = v10 - (float)(this->mNormal.y * v13);
      v7[v3].z = v11 - (float)(v9 * v13);
      v7[v3].x = v12 - (float)(v8 * v13);
    }
    UFG::RegionPolygon::RecalcCachedValues(this, 1);
    return;
  }
  v14 = (float)((float)(this->mNormal.y * delta->y) + (float)(this->mNormal.x * delta->x))
      + (float)(this->mNormal.z * delta->z);
  if ( aspect == -101 )
  {
    v16 = v14 + this->mExtentAbove;
    if ( v16 <= 0.0 )
      v16 = 0.0;
    this->mExtentAbove = v16;
    goto LABEL_13;
  }
  if ( aspect != -100 )
  {
LABEL_13:
    UFG::RegionPolygon::RecalcCachedValues(this, 0);
    return;
  }
  v15 = v14 + this->mExtentBelow;
  if ( v15 >= 0.0 )
    v15 = 0.0;
  this->mExtentBelow = v15;
  UFG::RegionPolygon::RecalcCachedValues(this, 0);
}

// File Line: 1221
// RVA: 0x244660
void __fastcall UFG::RegionPolygon::RecalcCachedValues(UFG::RegionPolygon *this, bool recalcNormal)
{
  UFG::RegionPolygon *v2; // r8
  unsigned int v3; // eax
  bool v4; // zf
  UFG::qVector3 *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  __m128 v9; // xmm7
  float v10; // xmm6_4
  float v11; // xmm3_4
  __m128 v12; // xmm2
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm8_4
  __m128 v19; // xmm9
  float v20; // xmm10_4
  float v21; // xmm3_4
  __m128 v22; // xmm4
  float v23; // xmm1_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  __m128 v28; // xmm12
  __m128 v29; // xmm13
  __m128 v30; // xmm4
  float v31; // xmm1_4
  float v32; // xmm11_4
  float v33; // xmm12_4
  __m128 v34; // xmm14
  __m128 v35; // xmm7
  float v36; // xmm15_4
  __m128 v37; // xmm4
  float v38; // xmm1_4
  float v39; // xmm7_4
  float v40; // xmm15_4
  float v41; // xmm4_4
  __m128 v42; // xmm5
  float v43; // xmm6_4
  __m128 v44; // xmm0
  float v45; // xmm1_4
  float v46; // xmm4_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  __m128 v51; // xmm13
  float v52; // xmm0_4
  float v53; // xmm12_4
  __m128 v54; // xmm11
  float v55; // xmm11_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm11_4
  float v59; // xmm6_4
  float v60; // xmm5_4
  float v61; // xmm0_4
  float v62; // xmm4_4
  __m128 v63; // xmm12
  float v64; // xmm7_4
  float v65; // xmm11_4
  __m128 v66; // xmm8
  float v67; // xmm1_4
  float v68; // xmm6_4
  float v69; // xmm4_4
  __m128 v70; // xmm2
  float v71; // xmm3_4
  UFG::qVector3 *v72; // rdx
  __int64 v73; // rax
  float v74; // xmm5_4
  float v75; // xmm6_4
  float v76; // xmm7_4
  float v77; // xmm8_4
  float v78; // xmm5_4
  unsigned __int64 v79; // r9
  float *v80; // rcx
  float v81; // xmm9_4
  float v82; // xmm7_4
  float v83; // xmm8_4
  float v84; // xmm6_4
  float v85; // xmm0_4
  float v86; // xmm1_4
  float v87; // xmm9_4
  float v88; // xmm10_4
  float v89; // xmm1_4
  float v90; // xmm0_4
  float v91; // xmm3_4
  float v92; // xmm1_4
  float v93; // xmm2_4
  float v94; // xmm0_4
  float v95; // xmm1_4
  float v96; // xmm3_4
  float v97; // xmm0_4
  float v98; // xmm2_4
  float v99; // xmm1_4
  float v100; // xmm0_4
  float v101; // xmm0_4
  float v102; // xmm2_4
  float v103; // xmm1_4
  float v104; // xmm7_4
  float v105; // xmm8_4
  float v106; // xmm7_4
  float v107; // xmm8_4
  float v108; // xmm6_4
  float v109; // xmm8_4
  float v110; // xmm6_4
  float v111; // xmm6_4
  float v112; // xmm5_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // [rsp+B0h] [rbp+8h]
  unsigned int v116; // [rsp+B8h] [rbp+10h]

  v2 = this;
  if ( recalcNormal )
  {
    v3 = this->mVertCount;
    if ( v3 <= 1 )
    {
      v14 = UFG::qVector3::msDirUp.x;
      v17 = UFG::qVector3::msDirUp.y;
      v16 = UFG::qVector3::msDirUp.z;
    }
    else
    {
      v4 = v3 == 2;
      v5 = this->mpVerts;
      if ( v4 )
      {
        v9 = (__m128)LODWORD(v5[1].z);
        v9.m128_f32[0] = v9.m128_f32[0] - v5->z;
        v6 = v5[1].x - v5->x;
        v7 = v5[1].y - v5->y;
        v8 = (float)(v7 * UFG::qVector3::msDirFront.z) - (float)(v9.m128_f32[0] * UFG::qVector3::msDirFront.y);
        v9.m128_f32[0] = (float)(v9.m128_f32[0] * UFG::qVector3::msDirFront.x)
                       - (float)(v6 * UFG::qVector3::msDirFront.z);
        v10 = (float)(v6 * UFG::qVector3::msDirFront.y) - (float)(v7 * UFG::qVector3::msDirFront.x);
        if ( v10 >= 0.0 )
          v11 = *(float *)&FLOAT_1_0;
        else
          v11 = FLOAT_N1_0;
        v12 = v9;
        v12.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
        v13 = v11 / COERCE_FLOAT(_mm_sqrt_ps(v12));
        v14 = v13 * v8;
        v15 = v13;
        v16 = v13 * v10;
        v17 = v15 * v9.m128_f32[0];
      }
      else
      {
        v19 = (__m128)LODWORD(v5[1].y);
        v18 = v5[1].x - v5->x;
        v19.m128_f32[0] = v19.m128_f32[0] - v5->y;
        v20 = v5[1].z - v5->z;
        v22 = v19;
        v21 = *(float *)&FLOAT_1_0;
        v22.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18)) + (float)(v20 * v20);
        if ( v22.m128_f32[0] == 0.0 )
          v23 = 0.0;
        else
          v23 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v22));
        v28 = (__m128)LODWORD(v5[2].y);
        v29 = (__m128)LODWORD(v5[2].z);
        v24 = v18 * v23;
        v25 = v19.m128_f32[0] * v23;
        v26 = v20 * v23;
        v27 = v5[2].x - v5[1].x;
        v28.m128_f32[0] = v28.m128_f32[0] - v5[1].y;
        v29.m128_f32[0] = v29.m128_f32[0] - v5[1].z;
        v30 = v28;
        v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27))
                        + (float)(v29.m128_f32[0] * v29.m128_f32[0]);
        if ( v30.m128_f32[0] == 0.0 )
          v31 = 0.0;
        else
          v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
        v34 = (__m128)LODWORD(v5->x);
        v35 = (__m128)LODWORD(v5->y);
        v32 = v27 * v31;
        v33 = v28.m128_f32[0] * v31;
        v29.m128_f32[0] = v29.m128_f32[0] * v31;
        v34.m128_f32[0] = v34.m128_f32[0] - v5[2].x;
        v35.m128_f32[0] = v35.m128_f32[0] - v5[2].y;
        v36 = v5->z - v5[2].z;
        v37 = v35;
        v37.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(v34.m128_f32[0] * v34.m128_f32[0]))
                        + (float)(v36 * v36);
        if ( v37.m128_f32[0] == 0.0 )
          v38 = 0.0;
        else
          v38 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v37));
        v34.m128_f32[0] = v34.m128_f32[0] * v38;
        v39 = v35.m128_f32[0] * v38;
        v40 = v36 * v38;
        v42 = v29;
        v41 = (float)(v33 * v26) - (float)(v29.m128_f32[0] * v25);
        v42.m128_f32[0] = (float)(v29.m128_f32[0] * v24) - (float)(v32 * v26);
        v43 = (float)(v32 * v25) - (float)(v33 * v24);
        *(float *)&v116 = (float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v41 * v41);
        v44 = (__m128)v116;
        v44.m128_f32[0] = *(float *)&v116 + (float)(v43 * v43);
        if ( v44.m128_f32[0] == 0.0 )
          v45 = 0.0;
        else
          v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
        v46 = v41 * v45;
        v47 = v42.m128_f32[0] * v45;
        v48 = v43 * v45;
        v49 = (float)(v39 * v29.m128_f32[0]) - (float)(v40 * v33);
        v115 = (float)(v39 * v29.m128_f32[0]) - (float)(v40 * v33);
        v50 = v34.m128_f32[0] * v29.m128_f32[0];
        v51 = (__m128)COERCE_UNSIGNED_INT(v40 * v32);
        v51.m128_f32[0] = v51.m128_f32[0] - v50;
        v52 = v39 * v32;
        v54 = v51;
        v53 = (float)(v34.m128_f32[0] * v33) - v52;
        v54.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v49 * v49)) + (float)(v53 * v53);
        if ( v54.m128_f32[0] == 0.0 )
          v55 = 0.0;
        else
          v55 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v54));
        v56 = v55;
        v57 = v55;
        v58 = v55 * v53;
        v63 = v34;
        v59 = v48 + v58;
        v60 = v47 + (float)(v56 * v51.m128_f32[0]);
        v61 = v39;
        v62 = v46 + (float)(v57 * v115);
        v63.m128_f32[0] = (float)(v34.m128_f32[0] * v26) - (float)(v40 * v24);
        v64 = (float)(v39 * v24) - (float)(v34.m128_f32[0] * v25);
        v66 = v63;
        v65 = (float)(v40 * v25) - (float)(v61 * v26);
        v66.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v65 * v65)) + (float)(v64 * v64);
        if ( v66.m128_f32[0] == 0.0 )
          v67 = 0.0;
        else
          v67 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v66));
        v68 = v59 + (float)(v64 * v67);
        v69 = v62 + (float)(v65 * v67);
        v42.m128_f32[0] = v60 + (float)(v63.m128_f32[0] * v67);
        if ( v68 < 0.0 )
          v21 = FLOAT_N1_0;
        v70 = v42;
        v70.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v69 * v69)) + (float)(v68 * v68);
        v71 = v21 / COERCE_FLOAT(_mm_sqrt_ps(v70));
        v14 = v69 * v71;
        v17 = v42.m128_f32[0] * v71;
        v16 = v71 * v68;
      }
    }
    this->mNormal.x = v14;
    this->mNormal.y = v17;
    this->mNormal.z = v16;
  }
  v72 = this->mpVerts;
  v73 = this->mVertCount;
  this->mOrigDist = (float)((float)(v72->y * this->mNormal.y) + (float)(v72->x * this->mNormal.x))
                  + (float)(v72->z * this->mNormal.z);
  if ( (_DWORD)v73 )
  {
    v74 = this->mExtentAbove;
    v75 = this->mExtentBelow;
    v76 = v74;
    v77 = this->mExtentAbove;
    v78 = v74 * this->mNormal.z;
    v79 = (unsigned __int64)&v72[v73];
    v80 = &v72->z;
    v81 = v75;
    v82 = v76 * v2->mNormal.x;
    v83 = v77 * v2->mNormal.y;
    v84 = v75 * v2->mNormal.z;
    v85 = v78 + v72->z;
    v86 = v83 + v72->y;
    v87 = v81 * v2->mNormal.x;
    v88 = v2->mExtentBelow * v2->mNormal.y;
    v2->mBoundingBox.mMax.x = v82 + v72->x;
    v2->mBoundingBox.mMax.y = v86;
    v2->mBoundingBox.mMax.z = v85;
    v89 = v88 + v72->y;
    v90 = v84 + v72->z;
    v2->mBoundingBox.mMin.x = v87 + v72->x;
    v2->mBoundingBox.mMin.y = v89;
    v2->mBoundingBox.mMin.z = v90;
    if ( (unsigned __int64)v72 < v79 )
    {
      do
      {
        v91 = v2->mBoundingBox.mMax.x;
        v92 = v83 + *(v80 - 1);
        v93 = v78 + *v80;
        if ( v91 <= (float)(v82 + *(v80 - 2)) )
          v91 = v82 + *(v80 - 2);
        v2->mBoundingBox.mMax.x = v91;
        v94 = v2->mBoundingBox.mMax.y;
        if ( v94 <= v92 )
          v94 = v92;
        v2->mBoundingBox.mMax.y = v94;
        v95 = v2->mBoundingBox.mMax.z;
        if ( v95 <= v93 )
          v95 = v93;
        v2->mBoundingBox.mMax.z = v95;
        v96 = v2->mBoundingBox.mMin.x;
        v97 = v88 + *(v80 - 1);
        v98 = v84 + *v80;
        if ( v96 >= (float)(v87 + *(v80 - 2)) )
          v96 = v87 + *(v80 - 2);
        v2->mBoundingBox.mMin.x = v96;
        v99 = v2->mBoundingBox.mMin.y;
        if ( v99 >= v97 )
          v99 = v97;
        v2->mBoundingBox.mMin.y = v99;
        v100 = v2->mBoundingBox.mMin.z;
        if ( v100 >= v98 )
          v100 = v98;
        v80 += 3;
        v2->mBoundingBox.mMin.z = v100;
      }
      while ( (unsigned __int64)(v80 - 2) < v79 );
    }
  }
  else
  {
    v101 = (float)(this->mBoundingBox.mMax.x + this->mBoundingBox.mMin.x) * 0.5;
    v102 = (float)(this->mBoundingBox.mMax.y + this->mBoundingBox.mMin.y) * 0.5;
    v103 = (float)(this->mBoundingBox.mMin.z + this->mBoundingBox.mMax.z) * 0.5;
    this->mBoundingBox.mMin.x = v101;
    this->mBoundingBox.mMin.y = v102;
    this->mBoundingBox.mMin.z = v103;
    this->mBoundingBox.mMax.x = v101;
    this->mBoundingBox.mMax.y = v102;
    this->mBoundingBox.mMax.z = v103;
  }
  v104 = v2->mBoundingBox.mMin.y;
  v105 = v2->mBoundingBox.mMin.z;
  v2->mCenter.x = v2->mBoundingBox.mMin.x;
  v2->mCenter.y = v104;
  v2->mCenter.z = v105;
  v106 = (float)(v104 + v2->mBoundingBox.mMax.y) * 0.5;
  v107 = v105 + v2->mBoundingBox.mMax.z;
  v108 = v2->mBoundingBox.mMax.x;
  v2->mCenter.y = v106;
  v109 = v107 * 0.5;
  v110 = v108 + v2->mCenter.x;
  v2->mCenter.z = v109;
  v111 = v110 * 0.5;
  v2->mCenter.x = v111;
  v112 = (float)((float)((float)(v111 * v2->mNormal.x) + (float)(v106 * v2->mNormal.y)) + (float)(v109 * v2->mNormal.z))
       - v2->mOrigDist;
  v113 = v112 * v2->mNormal.x;
  v114 = v112 * v2->mNormal.y;
  v2->mCenter.z = v109 - (float)(v112 * v2->mNormal.z);
  v2->mCenter.x = v111 - v113;
  v2->mCenter.y = v106 - v114;
}

