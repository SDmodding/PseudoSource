// File Line: 86
// RVA: 0x2376E0
void __fastcall UFG::RegionPolygon::RegionPolygon(UFG::RegionPolygon *this, UFG::RegionPolygon *rgnPoly)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionBase::`vftable;
  this->mRefCount = 0;
  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionPolygon::`vftable;
  this->mpVerts = 0i64;
  this->mVertCount = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCenter.x = UFG::qVector3::msZero.x;
  this->mCenter.y = y;
  this->mCenter.z = z;
  v4 = UFG::qVector3::msDirUp.y;
  v5 = UFG::qVector3::msDirUp.z;
  this->mNormal.x = UFG::qVector3::msDirUp.x;
  this->mNormal.y = v4;
  this->mNormal.z = v5;
  *(_QWORD *)&this->mOrigDist = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMin.y = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMax.x = 0i64;
  this->mBoundingBox.mMax.z = 0.0;
  UFG::RegionPolygon::SetShape(this, rgnPoly);
}

// File Line: 114
// RVA: 0x237790
void __fastcall UFG::RegionPolygon::RegionPolygon(UFG::RegionPolygon *this, UFG::qPropertySet *props)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionBase::`vftable;
  this->mRefCount = 0;
  this->vfptr = (UFG::RegionBaseVtbl *)&UFG::RegionPolygon::`vftable;
  this->mpVerts = 0i64;
  *(_QWORD *)&this->mVertCount = 0i64;
  this->mExtentBelow = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mCenter.x = UFG::qVector3::msZero.x;
  this->mCenter.y = y;
  this->mCenter.z = z;
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
  UFG::allocator::free_link *v2; // rax

  v2 = UFG::qMalloc(0x58ui64, UFG::gGlobalNewName, 0i64);
  if ( v2 )
    UFG::RegionPolygon::RegionPolygon((UFG::RegionPolygon *)v2, this);
}

// File Line: 145
// RVA: 0x23D350
void __fastcall UFG::RegionPolygon::GetCenter(UFG::RegionPolygon *this, UFG::qVector3 *pPos)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = this->mCenter.y;
  z = this->mCenter.z;
  pPos->x = this->mCenter.x;
  pPos->y = y;
  pPos->z = z;
}

// File Line: 155
// RVA: 0x23DD60
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetRandomPosition(UFG::RegionPolygon *this, UFG::qVector3 *result)
{
  UFG::qVector3 *RandomPosition; // rax
  float y; // xmm7_4
  float z; // xmm8_4
  float x; // xmm4_4
  float v8; // xmm2_4
  float v9; // xmm7_4
  float v10; // xmm8_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-48h] BYREF

  do
  {
    RandomPosition = UFG::qBox::GetRandomPosition(&this->mBoundingBox, &resulta);
    y = RandomPosition->y;
    z = RandomPosition->z;
    result->x = RandomPosition->x;
    x = result->x;
    result->y = y;
    result->z = z;
    v8 = (float)((float)((float)(this->mNormal.x * x) + (float)(this->mNormal.y * y)) + (float)(this->mNormal.z * z))
       - this->mOrigDist;
    v9 = y - (float)(this->mNormal.y * v8);
    v10 = z - (float)(this->mNormal.z * v8);
    result->x = x - (float)(this->mNormal.x * v8);
    result->y = v9;
    result->z = v10;
  }
  while ( !UFG::qIsBoundPointPolyXY(result, this->mpVerts, this->mVertCount) );
  return result;
}

// File Line: 184
// RVA: 0x245F10
void __fastcall UFG::RegionPolygon::Translate(UFG::RegionPolygon *this, UFG::qVector3 *offset)
{
  UFG::qVector3 *mpVerts; // rcx
  __int64 mVertCount; // rax
  unsigned __int64 v5; // r11
  float y; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
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
  float *p_z; // rcx
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm2_4

  mpVerts = this->mpVerts;
  mVertCount = this->mVertCount;
  v5 = (unsigned __int64)&mpVerts[mVertCount];
  if ( (unsigned __int64)mpVerts < v5 )
  {
    if ( (12 * mVertCount + 11) / 12 >= 4 )
    {
      do
      {
        y = mpVerts->y;
        z = mpVerts->z;
        x = mpVerts->x;
        mpVerts += 4;
        v9 = y + offset->y;
        v10 = z + offset->z;
        mpVerts[-4].x = x + offset->x;
        v11 = mpVerts[-3].x;
        mpVerts[-4].y = v9;
        v12 = mpVerts[-3].y;
        mpVerts[-4].z = v10;
        v13 = v12 + offset->y;
        v14 = mpVerts[-3].z + offset->z;
        mpVerts[-3].x = v11 + offset->x;
        v15 = mpVerts[-2].x;
        mpVerts[-3].y = v13;
        v16 = mpVerts[-2].y;
        mpVerts[-3].z = v14;
        v17 = v16 + offset->y;
        v18 = mpVerts[-2].z + offset->z;
        mpVerts[-2].x = v15 + offset->x;
        v19 = mpVerts[-1].x;
        mpVerts[-2].y = v17;
        v20 = mpVerts[-1].y;
        mpVerts[-2].z = v18;
        v21 = v20 + offset->y;
        v22 = mpVerts[-1].z + offset->z;
        mpVerts[-1].x = v19 + offset->x;
        mpVerts[-1].y = v21;
        mpVerts[-1].z = v22;
      }
      while ( (__int64)mpVerts < (__int64)(v5 - 36) );
    }
    if ( (unsigned __int64)mpVerts < v5 )
    {
      p_z = &mpVerts->z;
      do
      {
        v24 = *p_z;
        v25 = *(p_z - 2);
        p_z += 3;
        v26 = v24 + offset->z;
        v27 = offset->y + *(p_z - 4);
        *(p_z - 5) = v25 + offset->x;
        *(p_z - 4) = v27;
        *(p_z - 3) = v26;
      }
      while ( (unsigned __int64)(p_z - 2) < v5 );
    }
  }
  v28 = this->mBoundingBox.mMin.y + offset->y;
  v29 = this->mBoundingBox.mMin.z + offset->z;
  this->mBoundingBox.mMin.x = this->mBoundingBox.mMin.x + offset->x;
  this->mBoundingBox.mMin.y = v28;
  this->mBoundingBox.mMin.z = v29;
  v30 = this->mBoundingBox.mMax.z + offset->z;
  v31 = offset->y + this->mBoundingBox.mMax.y;
  this->mBoundingBox.mMax.x = offset->x + this->mBoundingBox.mMax.x;
  this->mBoundingBox.mMax.y = v31;
  this->mBoundingBox.mMax.z = v30;
  UFG::RegionPolygon::RecalcCachedValues(this, 0);
}

// File Line: 205
// RVA: 0x243CE0
void __fastcall UFG::RegionPolygon::PropertiesLoad(UFG::RegionPolygon *this, UFG::qPropertySet *props)
{
  unsigned int v4; // edi
  UFG::qPropertyList *v5; // r14
  unsigned __int64 mNumElements; // rbp
  unsigned __int64 v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rbx
  UFG::qVector3 *v10; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  v4 = 0;
  if ( this->mVertCount )
  {
    this->mVertCount = 0;
    operator delete[](this->mpVerts);
    this->mpVerts = 0i64;
    UFG::RegionPolygon::RecalcCachedValues(this, 1);
  }
  this->mExtentAbove = *UFG::qPropertySet::Get<float>(
                          props,
                          (UFG::qArray<unsigned long,0> *)&SimSym_ExtentAbove,
                          DEPTH_RECURSE);
  this->mExtentBelow = *UFG::qPropertySet::Get<float>(
                          props,
                          (UFG::qArray<unsigned long,0> *)&SimSym_ExtentBelow,
                          DEPTH_RECURSE);
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         props,
         (UFG::qArray<unsigned long,0> *)&SimSym_Vertexes,
         DEPTH_RECURSE);
  mNumElements = v5->mNumElements;
  if ( (_DWORD)mNumElements )
  {
    this->mVertCount = mNumElements;
    v7 = 12 * mNumElements;
    if ( !is_mul_ok(mNumElements, 0xCui64) )
      v7 = -1i64;
    v8 = UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
    this->mpVerts = (UFG::qVector3 *)v8;
    v9 = v8 + 1;
    do
    {
      v10 = UFG::qPropertyList::Get<UFG::qVector3>(v5, v4);
      y = v10->y;
      z = v10->z;
      *(float *)&v9[-1].mNext = v10->x;
      *((float *)&v9[-1].mNext + 1) = y;
      *(float *)&v9->mNext = z;
      ++v4;
      v9 = (UFG::allocator::free_link *)((char *)v9 + 12);
    }
    while ( v4 < (unsigned int)mNumElements );
  }
  UFG::RegionPolygon::RecalcCachedValues(this, 1);
}

// File Line: 238
// RVA: 0x244460
void __fastcall UFG::RegionPolygon::PropertiesSave(UFG::RegionPolygon *this, UFG::qPropertySet *pProps)
{
  UFG::qPropertyList *v4; // rax
  UFG::qPropertyList *v5; // rdi
  UFG::qVector3 *mpVerts; // rbx
  UFG::qVector3 *i; // rsi

  UFG::qPropertySet::Set<float>(pProps, (UFG::qArray<unsigned long,0> *)&SimSym_ExtentAbove, this->mExtentAbove);
  UFG::qPropertySet::Set<float>(pProps, (UFG::qArray<unsigned long,0> *)&SimSym_ExtentBelow, this->mExtentBelow);
  v4 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         pProps,
         (UFG::qArray<unsigned long,0> *)&SimSym_Vertexes,
         DEPTH_RECURSE);
  v5 = v4;
  if ( v4 )
  {
    UFG::qPropertyList::RemoveAll(v4);
  }
  else
  {
    v5 = UFG::qPropertyList::Create("pVertList");
    UFG::qPropertySet::Set<UFG::qPropertyList>(pProps, (UFG::qArray<unsigned long,0> *)&SimSym_Vertexes, v5);
  }
  mpVerts = this->mpVerts;
  for ( i = &mpVerts[this->mVertCount]; mpVerts < i; ++mpVerts )
    UFG::qPropertyList::Add<UFG::qVector3>(v5, mpVerts);
}

// File Line: 304
// RVA: 0x23E8A0
void __fastcall UFG::RegionPolygon::InsertVert(UFG::RegionPolygon *this, UFG::qVector3 *vert, unsigned int vertIdx)
{
  __int64 v3; // rsi
  unsigned int mVertCount; // edi
  unsigned __int64 v7; // rax
  __int64 v8; // rcx
  float y; // xmm1_4
  float z; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float x; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  UFG::qVector3 *v21; // [rsp+50h] [rbp+8h]

  v3 = vertIdx;
  mVertCount = this->mVertCount;
  v7 = 12i64 * (mVertCount + 1);
  if ( !is_mul_ok(mVertCount + 1, 0xCui64) )
    v7 = -1i64;
  v21 = (UFG::qVector3 *)UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
  UFG::qMemCopy(v21, this->mpVerts, 12 * v3);
  v8 = v3;
  y = vert->y;
  z = vert->z;
  v21[v8].x = vert->x;
  v21[v8].y = y;
  v21[v8].z = z;
  UFG::qMemCopy(&v21[v3 + 1], &this->mpVerts[v3], 12 * (mVertCount - v3));
  operator delete[](this->mpVerts);
  this->mpVerts = v21;
  if ( ++this->mVertCount <= 3 )
  {
    UFG::RegionPolygon::RecalcCachedValues(this, 1);
  }
  else
  {
    v11 = (float)(this->mExtentAbove * this->mNormal.y) + vert->y;
    v12 = (float)(this->mExtentAbove * this->mNormal.z) + vert->z;
    x = this->mBoundingBox.mMax.x;
    if ( x <= (float)((float)(this->mExtentAbove * this->mNormal.x) + vert->x) )
      x = (float)(this->mExtentAbove * this->mNormal.x) + vert->x;
    this->mBoundingBox.mMax.x = x;
    v14 = this->mBoundingBox.mMax.y;
    if ( v14 <= v11 )
      v14 = v11;
    this->mBoundingBox.mMax.y = v14;
    v15 = this->mBoundingBox.mMax.z;
    if ( v15 <= v12 )
      v15 = v12;
    this->mBoundingBox.mMax.z = v15;
    v16 = (float)(this->mExtentBelow * this->mNormal.y) + vert->y;
    v17 = (float)(this->mExtentBelow * this->mNormal.z) + vert->z;
    v18 = this->mBoundingBox.mMin.x;
    if ( v18 >= (float)((float)(this->mExtentBelow * this->mNormal.x) + vert->x) )
      v18 = (float)(this->mExtentBelow * this->mNormal.x) + vert->x;
    this->mBoundingBox.mMin.x = v18;
    v19 = this->mBoundingBox.mMin.y;
    if ( v19 >= v16 )
      v19 = v16;
    this->mBoundingBox.mMin.y = v19;
    v20 = this->mBoundingBox.mMin.z;
    if ( v20 >= v17 )
      v20 = v17;
    this->mBoundingBox.mMin.z = v20;
  }
}

// File Line: 380
// RVA: 0x2457E0
void __fastcall UFG::RegionPolygon::SetShape(
        UFG::RegionPolygon *this,
        UFG::RegionPolygon::eShape shape,
        float extentAbove,
        float extentBelow)
{
  int v6; // edi
  unsigned __int64 v7; // rax
  UFG::qVector3 *mpVerts; // rax
  UFG::qVector3 *v9; // rax
  UFG::qVector3 *v10; // rax
  unsigned __int64 v11; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::allocator::free_link *v14; // [rsp+60h] [rbp+8h]
  UFG::allocator::free_link *v15; // [rsp+60h] [rbp+8h]

  if ( this->mVertCount )
  {
    this->mVertCount = 0;
    operator delete[](this->mpVerts);
    this->mpVerts = 0i64;
    UFG::RegionPolygon::RecalcCachedValues(this, 1);
  }
  this->mExtentAbove = extentAbove;
  this->mExtentBelow = extentBelow;
  v6 = shape - 1;
  if ( v6 )
  {
    if ( v6 != 1 )
      return;
    this->mVertCount = 4;
    v7 = 48i64;
    if ( !is_mul_ok(4ui64, 0xCui64) )
      v7 = -1i64;
    v14 = UFG::qMalloc(v7, "RegionPolygon.mpVerts", 0i64);
    this->mpVerts = (UFG::qVector3 *)v14;
    LODWORD(v14->mNext) = 1065353216;
    *(UFG::allocator::free_link **)((char *)&v14->mNext + 4) = (UFG::allocator::free_link *)1065353216;
    mpVerts = this->mpVerts;
    mpVerts[1].x = 1.0;
    mpVerts[1].y = -1.0;
    mpVerts[1].z = 0.0;
    v9 = this->mpVerts;
    v9[2].x = -1.0;
    v9[2].y = -1.0;
    v9[2].z = 0.0;
    v10 = this->mpVerts;
    v10[3].x = -1.0;
    *(_QWORD *)&v10[3].y = 1065353216i64;
  }
  else
  {
    this->mVertCount = 1;
    v11 = 12i64;
    if ( !is_mul_ok(1ui64, 0xCui64) )
      v11 = -1i64;
    v15 = UFG::qMalloc(v11, "RegionPolygon.mpVerts", 0i64);
    this->mpVerts = (UFG::qVector3 *)v15;
    v15->mNext = 0i64;
    LODWORD(v15[1].mNext) = 0;
  }
  y = UFG::qVector3::msDirUp.y;
  z = UFG::qVector3::msDirUp.z;
  this->mNormal.x = UFG::qVector3::msDirUp.x;
  this->mNormal.y = y;
  this->mNormal.z = z;
  UFG::RegionPolygon::RecalcCachedValues(this, 0);
}

// File Line: 418
// RVA: 0x245660
void __fastcall UFG::RegionPolygon::SetShape(UFG::RegionPolygon *this, UFG::RegionBase *region)
{
  int mRefCount; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  int v7; // xmm2_4
  float v8; // xmm1_4
  int v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  unsigned __int64 v12; // rax
  __int64 v13; // [rsp+28h] [rbp-20h] BYREF
  float extentBelow[2]; // [rsp+30h] [rbp-18h]
  float extentAbove[2]; // [rsp+38h] [rbp-10h]
  UFG::allocator::free_link *v16; // [rsp+58h] [rbp+10h]

  if ( region->vfptr->GetType(region) == RegionType_polygon )
  {
    if ( this->mVertCount )
    {
      this->mVertCount = 0;
      operator delete[](this->mpVerts);
      this->mpVerts = 0i64;
      UFG::RegionPolygon::RecalcCachedValues(this, 1);
    }
    this->mVertCount = region[1].mRefCount;
    this->mExtentAbove = *((float *)&region[1].mRefCount + 1);
    this->mExtentBelow = *(float *)&region[2].vfptr;
    mRefCount = region[2].mRefCount;
    v5 = *((float *)&region[2].mRefCount + 1);
    this->mCenter.x = *((float *)&region[2].vfptr + 1);
    LODWORD(this->mCenter.y) = mRefCount;
    this->mCenter.z = v5;
    v6 = *((float *)&region[3].vfptr + 1);
    v7 = region[3].mRefCount;
    this->mNormal.x = *(float *)&region[3].vfptr;
    this->mNormal.y = v6;
    LODWORD(this->mNormal.z) = v7;
    this->mOrigDist = *((float *)&region[3].mRefCount + 1);
    v8 = *((float *)&region[4].vfptr + 1);
    v9 = region[4].mRefCount;
    this->mBoundingBox.mMin.x = *(float *)&region[4].vfptr;
    this->mBoundingBox.mMin.y = v8;
    LODWORD(this->mBoundingBox.mMin.z) = v9;
    v10 = *(float *)&region[5].vfptr;
    v11 = *((float *)&region[5].vfptr + 1);
    this->mBoundingBox.mMax.x = *((float *)&region[4].mRefCount + 1);
    this->mBoundingBox.mMax.y = v10;
    this->mBoundingBox.mMax.z = v11;
    v12 = 12i64 * (unsigned int)region[1].mRefCount;
    if ( !is_mul_ok((unsigned int)region[1].mRefCount, 0xCui64) )
      v12 = -1i64;
    v16 = UFG::qMalloc(v12, "RegionPolygon.mpVerts", 0i64);
    this->mpVerts = (UFG::qVector3 *)v16;
    UFG::qMemCopy(v16, region[1].vfptr, 12 * region[1].mRefCount);
  }
  v13 = 0i64;
  *(_QWORD *)extentBelow = 0i64;
  *(_QWORD *)extentAbove = 0i64;
  region->vfptr->GetBoundingBox(region, (UFG::qBox *)&v13);
  UFG::RegionPolygon::SetShape(this, Shape_quad, extentAbove[1], extentBelow[0]);
}

// File Line: 454
// RVA: 0x23D400
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetClosestPointOutside(
        UFG::RegionPolygon *this,
        UFG::qVector3 *result,
        UFG::qVector3 *pos)
{
  UFG::qVector3 *v6; // rax
  signed int v7; // ebp
  int v8; // ebx
  int v9; // r15d
  float v10; // xmm6_4
  UFG::qVector3 *mpVerts; // rsi
  float x; // xmm7_4
  float z; // xmm9_4
  float y; // xmm8_4
  UFG::qVector3 *v15; // rax
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qVector3 *v20; // rax
  UFG::qVector3 resulta; // [rsp+20h] [rbp-68h] BYREF

  if ( this->vfptr->IsHitPoint(this, pos) )
  {
    v7 = this->mVertCount - 1;
    v8 = 0;
    v9 = -1;
    v10 = FLOAT_9_9999996e24;
    if ( v7 > 0 )
    {
      mpVerts = this->mpVerts;
      x = pos->x;
      z = pos->z;
      y = pos->y;
      do
      {
        v15 = UFG::qNearestSegPoint(&resulta, mpVerts, mpVerts + 1, pos);
        v16 = fsqrt(
                (float)((float)((float)(x - v15->x) * (float)(x - v15->x))
                      + (float)((float)(y - v15->y) * (float)(y - v15->y)))
              + (float)((float)(z - v15->z) * (float)(z - v15->z)));
        if ( v16 < v10 )
        {
          v10 = v16;
          v9 = v8;
        }
        ++v8;
        ++mpVerts;
      }
      while ( v8 < v7 );
    }
    v17 = pos->x;
    v18 = pos->y;
    v19 = pos->z;
    if ( v9 != -1 )
    {
      v20 = UFG::qNearestSegPoint(&resulta, &this->mpVerts[v9], &this->mpVerts[v9 + 1], pos);
      v17 = v20->x;
      v18 = v20->y;
      v19 = v20->z;
    }
    result->x = v17;
    result->y = v18;
    v6 = result;
    result->z = v19;
  }
  else
  {
    result->x = pos->x;
    result->y = pos->y;
    result->z = pos->z;
    return result;
  }
  return v6;
}

// File Line: 493
// RVA: 0x2405B0
bool __fastcall UFG::RegionPolygon::IsHitPoint(UFG::RegionPolygon *this, UFG::qVector3 *pos)
{
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v5; // xmm0_4

  x = pos->x;
  if ( pos->x < this->mBoundingBox.mMin.x )
    return 0;
  if ( x > this->mBoundingBox.mMax.x )
    return 0;
  y = pos->y;
  if ( y < this->mBoundingBox.mMin.y )
    return 0;
  if ( y > this->mBoundingBox.mMax.y )
    return 0;
  z = pos->z;
  if ( z < this->mBoundingBox.mMin.z )
    return 0;
  if ( z > this->mBoundingBox.mMax.z )
    return 0;
  v5 = (float)((float)((float)(y * this->mNormal.y) + (float)(x * this->mNormal.x)) + (float)(z * this->mNormal.z))
     - this->mOrigDist;
  return v5 >= this->mExtentBelow
      && v5 <= this->mExtentAbove
      && UFG::qIsBoundPointPolyXY(pos, this->mpVerts, this->mVertCount);
}

// File Line: 518
// RVA: 0x240920
bool __fastcall UFG::RegionPolygon::IsHitPointWS(
        UFG::RegionPolygon *this,
        UFG::qVector3 *pos,
        UFG::qMatrix44 *localWorld)
{
  float z; // xmm3_4
  float x; // xmm8_4
  float y; // xmm0_4
  float v8; // xmm7_4
  float v9; // xmm4_4
  __m128 y_low; // xmm2
  float v11; // xmm8_4
  float v12; // xmm0_4
  float v13; // xmm8_4
  float v14; // xmm4_4
  float mExtentAbove; // xmm5_4
  __m128 v16; // xmm2
  float v17; // xmm0_4
  __m128 v18; // xmm4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm2_4
  unsigned int mVertCount; // r8d
  UFG::qVector3 *mpVerts; // rdx
  UFG::qVector3 posXY; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 d; // [rsp+30h] [rbp-78h] BYREF

  z = this->mCenter.z;
  x = this->mCenter.x;
  y = this->mCenter.y;
  v9 = (float)(x * localWorld->v0.z) + (float)(y * localWorld->v1.z);
  y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  v11 = (float)(x * localWorld->v0.y) + (float)(y * localWorld->v1.y);
  v12 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v13 = (float)(v11 + (float)(z * localWorld->v2.y)) + localWorld->v3.y;
  v14 = (float)(v9 + (float)(z * localWorld->v2.z)) + localWorld->v3.z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y)
                                    * (float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y))
                            + (float)((float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
                                    * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)))
                    + (float)(v12 * v12);
  mExtentAbove = _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
  if ( mExtentAbove <= this->mExtentAbove )
    mExtentAbove = this->mExtentAbove;
  if ( mExtentAbove <= this->mExtentBelow )
    mExtentAbove = this->mExtentBelow;
  v16 = (__m128)LODWORD(pos->y);
  v17 = pos->z - v14;
  v18 = (__m128)LODWORD(localWorld->v2.y);
  v18.m128_f32[0] = (float)((float)(v18.m128_f32[0] * v18.m128_f32[0]) + (float)(localWorld->v2.x * localWorld->v2.x))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v8 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
             + (float)(localWorld->v2.x * z))
     + localWorld->v3.x;
  v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] - v13) * (float)(v16.m128_f32[0] - v13))
                          + (float)((float)(pos->x - v8) * (float)(pos->x - v8)))
                  + (float)(v17 * v17);
  if ( _mm_sqrt_ps(v16).m128_f32[0] > (float)(_mm_sqrt_ps(v18).m128_f32[0] * mExtentAbove) )
    return 0;
  UFG::qInverse(&d, localWorld);
  v19 = pos->y;
  v20 = pos->z;
  v21 = (float)((float)((float)(d.v1.x * v19) + (float)(d.v0.x * pos->x)) + (float)(d.v2.x * v20)) + d.v3.x;
  v22 = (float)((float)((float)(d.v1.y * v19) + (float)(d.v0.y * pos->x)) + (float)(d.v2.y * v20)) + d.v3.y;
  v23 = (float)((float)((float)(d.v1.z * v19) + (float)(d.v0.z * pos->x)) + (float)(d.v2.z * v20)) + d.v3.z;
  v24 = (float)((float)((float)(v22 * this->mNormal.y) + (float)(v21 * this->mNormal.x)) + (float)(v23 * this->mNormal.z))
      - this->mOrigDist;
  if ( v24 < this->mExtentBelow || v24 > this->mExtentAbove )
    return 0;
  mVertCount = this->mVertCount;
  mpVerts = this->mpVerts;
  posXY.x = v21;
  posXY.y = v22;
  posXY.z = v23;
  return UFG::qIsBoundPointPolyXY(&posXY, mpVerts, mVertCount);
}

// File Line: 563
// RVA: 0x241FE0
char __fastcall UFG::RegionPolygon::IsHitSegment(
        UFG::RegionPolygon *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qVector3 *pHitPos)
{
  float mOrigDist; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  unsigned int mVertCount; // r9d
  UFG::qVector2 *mpVerts; // r8
  float y; // xmm9_4
  float x; // xmm8_4
  float z; // xmm10_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  char result; // al
  float v19; // xmm5_4
  float v20; // xmm4_4
  UFG::qVector3 v21; // [rsp+18h] [rbp-49h] BYREF
  UFG::qVector3 *hit_enter_p; // [rsp+28h] [rbp-39h] BYREF
  UFG::qVector3 *hit_exit_p; // [rsp+30h] [rbp-31h]
  UFG::qVector3 endXY; // [rsp+38h] [rbp-29h] BYREF
  UFG::qVector3 startXY; // [rsp+48h] [rbp-19h] BYREF
  float pPDist[6]; // [rsp+C8h] [rbp+67h] BYREF

  if ( !UFG::qBox::IsHitSeg(&this->mBoundingBox, start, end, 0i64, 0i64) )
    return 0;
  mOrigDist = this->mOrigDist;
  hit_exit_p = &v21;
  if ( !(unsigned int)UFG::qIntersectSegSlab(
                        start,
                        end,
                        &this->mNormal,
                        mOrigDist + this->mExtentBelow,
                        mOrigDist + this->mExtentAbove,
                        (UFG::qVector3 *)&hit_enter_p,
                        &v21) )
    return 0;
  v9 = *(float *)&hit_enter_p;
  v10 = *((float *)&hit_enter_p + 1);
  mVertCount = this->mVertCount;
  mpVerts = (UFG::qVector2 *)this->mpVerts;
  hit_enter_p = 0i64;
  y = this->mNormal.y;
  x = this->mNormal.x;
  z = this->mNormal.z;
  v16 = (float)((float)((float)(x * v9) + (float)(y * v10)) + (float)(z * *(float *)&hit_exit_p)) - this->mOrigDist;
  startXY.x = v9 - (float)(x * v16);
  startXY.z = *(float *)&hit_exit_p - (float)(z * v16);
  startXY.y = v10 - (float)(y * v16);
  v17 = (float)((float)((float)(x * v21.x) + (float)(y * v21.y)) + (float)(z * v21.z)) - this->mOrigDist;
  endXY.x = v21.x - (float)(x * v17);
  endXY.y = v21.y - (float)(y * v17);
  endXY.z = v21.z - (float)(z * v17);
  if ( !pHitPos )
    return UFG::qIntersectSegPolyXY(
             (UFG::qVector2 *)&startXY,
             (UFG::qVector2 *)&endXY,
             mpVerts,
             mVertCount,
             0i64,
             hit_enter_p);
  if ( !UFG::qIntersectSegPolyXY(
          (UFG::qVector2 *)&startXY,
          (UFG::qVector2 *)&endXY,
          mpVerts,
          mVertCount,
          pPDist,
          hit_enter_p) )
    return 0;
  result = 1;
  v19 = (float)((float)(v21.y - *((float *)&hit_enter_p + 1)) * pPDist[0]) + *((float *)&hit_enter_p + 1);
  v20 = (float)((float)(v21.z - *(float *)&hit_exit_p) * pPDist[0]) + *(float *)&hit_exit_p;
  pHitPos->x = (float)((float)(v21.x - *(float *)&hit_enter_p) * pPDist[0]) + *(float *)&hit_enter_p;
  pHitPos->y = v19;
  pHitPos->z = v20;
  return result;
}

// File Line: 617
// RVA: 0x2428F0
bool __fastcall UFG::RegionPolygon::IsHitSegmentWS(
        UFG::RegionPolygon *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float z; // xmm3_4
  float x; // xmm4_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm8_4
  __m128 y_low; // xmm2
  float v15; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm8_4
  float v19; // xmm8_4
  float mExtentAbove; // xmm0_4
  float mExtentBelow; // xmm3_4
  __m128 v22; // xmm1
  float v23; // xmm6_4
  UFG::qVector3 *v24; // rax
  bool v25; // al
  UFG::RegionBaseVtbl *vfptr; // rax
  float v27; // xmm3_4
  float y; // xmm2_4
  float v29; // xmm4_4
  float v30; // xmm13_4
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm13_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h] BYREF
  float v39; // [rsp+2Ch] [rbp-6Dh]
  UFG::qVector3 result; // [rsp+30h] [rbp-69h] BYREF
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

  z = this->mCenter.z;
  x = localWorld->v2.x;
  v11 = this->mCenter.x;
  v12 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(v11 * localWorld->v0.x)) + (float)(x * z))
      + localWorld->v3.x;
  v13 = (float)(this->mCenter.y * localWorld->v1.z) + (float)(v11 * localWorld->v0.z);
  y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y)
                    * (float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y);
  v15 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v16 = (float)((float)((float)(v11 * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y))
              + (float)(z * localWorld->v2.y))
      + localWorld->v3.y;
  v17 = this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x;
  v18 = v13 + (float)(z * localWorld->v2.z);
  pos.x = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(this->mCenter.x * localWorld->v0.x))
                + (float)(x * z))
        + localWorld->v3.x;
  v19 = v18 + localWorld->v3.z;
  pos.y = v16;
  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] + (float)(v17 * v17)) + (float)(v15 * v15);
  mExtentAbove = this->mExtentAbove;
  pos.z = v19;
  mExtentBelow = _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
  if ( mExtentBelow <= mExtentAbove )
    mExtentBelow = mExtentAbove;
  if ( mExtentBelow <= this->mExtentBelow )
    mExtentBelow = this->mExtentBelow;
  v22 = (__m128)LODWORD(localWorld->v2.y);
  v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(x * x))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v23 = _mm_sqrt_ps(v22).m128_f32[0] * mExtentBelow;
  v24 = UFG::qNearestSegPoint(&result, start, end, &pos);
  if ( (float)((float)((float)((float)(v16 - v24->y) * (float)(v16 - v24->y))
                     + (float)((float)(v12 - v24->x) * (float)(v12 - v24->x)))
             + (float)((float)(v19 - v24->z) * (float)(v19 - v24->z))) > (float)(v23 * v23) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, localWorld);
  vfptr = this->vfptr;
  v27 = start->x;
  y = start->y;
  v29 = start->z;
  v30 = v42 * y;
  v49 = (float)((float)((float)(result.z * y) + (float)(pos.z * start->x)) + (float)(v43 * v29)) + v46;
  v31 = end->z;
  v32 = result.x;
  v33 = v30 + (float)(result.x * v27);
  v34 = end->y;
  v35 = end->x;
  result.x = v49;
  pos.y = (float)((float)((float)(v41 * v34) + (float)(v39 * v35)) + (float)(v44 * v31)) + v47;
  pos.z = (float)((float)((float)(v42 * v34) + (float)(v32 * v35)) + (float)(v45 * v31)) + v48;
  pos.x = (float)(v33 + (float)(v45 * v29)) + v48;
  v25 = vfptr->IsHitSegment(this, &result, &pos, (UFG::qVector3 *)v50);
  if ( v50 )
  {
    v36 = (float)((float)((float)(v50[1] * localWorld->v1.y) + (float)(*v50 * localWorld->v0.y))
                + (float)(v50[2] * localWorld->v2.y))
        + localWorld->v3.y;
    v37 = (float)((float)((float)(v50[1] * localWorld->v1.z) + (float)(*v50 * localWorld->v0.z))
                + (float)(v50[2] * localWorld->v2.z))
        + localWorld->v3.z;
    *v50 = (float)((float)((float)(v50[1] * localWorld->v1.x) + (float)(*v50 * localWorld->v0.x))
                 + (float)(v50[2] * localWorld->v2.x))
         + localWorld->v3.x;
    v50[1] = v36;
    v50[2] = v37;
  }
  return v25;
}

// File Line: 664
// RVA: 0x23F8B0
char __fastcall UFG::RegionPolygon::IsHitPlaneRay(
        UFG::RegionPolygon *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 posXY; // [rsp+30h] [rbp-18h] BYREF

  if ( !UFG::qIntersectRayPlane(rayPos, rayDir, &this->mNormal, this->mOrigDist, &posXY)
    || posXY.x < this->mBoundingBox.mMin.x
    || posXY.x > this->mBoundingBox.mMax.x
    || posXY.y < this->mBoundingBox.mMin.y
    || posXY.y > this->mBoundingBox.mMax.y
    || posXY.z < this->mBoundingBox.mMin.z
    || posXY.z > this->mBoundingBox.mMax.z
    || !UFG::qIsBoundPointPolyXY(&posXY, this->mpVerts, this->mVertCount) )
  {
    return 0;
  }
  if ( pHitPos )
  {
    y = posXY.y;
    pHitPos->x = posXY.x;
    z = posXY.z;
    pHitPos->y = y;
    pHitPos->z = z;
  }
  return 1;
}

// File Line: 710
// RVA: 0x23FEA0
bool __fastcall UFG::RegionPolygon::IsHitPlaneRayWS(
        UFG::RegionPolygon *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float z; // xmm5_4
  float x; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  __m128 y_low; // xmm2
  float mExtentAbove; // xmm3_4
  __m128 v20; // xmm1
  float v21; // xmm6_4
  bool result; // al
  float v23; // xmm3_4
  float y; // xmm2_4
  UFG::RegionBaseVtbl *vfptr; // rax
  float v26; // xmm4_4
  float v27; // xmm13_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm13_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h] BYREF
  float v36; // [rsp+2Ch] [rbp-6Dh]
  int v37[4]; // [rsp+30h] [rbp-69h] BYREF
  float v38; // [rsp+40h] [rbp-59h]
  float v39; // [rsp+48h] [rbp-51h]
  float v40; // [rsp+4Ch] [rbp-4Dh]
  float v41; // [rsp+50h] [rbp-49h]
  float v42; // [rsp+58h] [rbp-41h]
  float v43; // [rsp+5Ch] [rbp-3Dh]
  float v44; // [rsp+60h] [rbp-39h]
  float v45; // [rsp+F8h] [rbp+5Fh]
  float *v46; // [rsp+118h] [rbp+7Fh]

  z = this->mCenter.z;
  x = this->mCenter.x;
  v11 = localWorld->v2.x;
  v12 = x * localWorld->v0.z;
  v13 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(x * localWorld->v0.x)) + (float)(v11 * z))
      + localWorld->v3.x;
  v14 = (float)(x * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y);
  v15 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v16 = (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
      * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x);
  v17 = (float)((float)((float)(this->mCenter.y * localWorld->v1.z) + v12) + (float)(z * localWorld->v2.z))
      + localWorld->v3.z;
  pos.y = (float)(v14 + (float)(z * localWorld->v2.y)) + localWorld->v3.y;
  y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mBoundingBox.mMin.y;
  pos.x = v13;
  pos.z = v17;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + v16) + (float)(v15 * v15);
  mExtentAbove = _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
  if ( mExtentAbove <= this->mExtentAbove )
    mExtentAbove = this->mExtentAbove;
  if ( mExtentAbove <= this->mExtentBelow )
    mExtentAbove = this->mExtentBelow;
  v20 = (__m128)LODWORD(localWorld->v2.y);
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v11 * v11))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v21 = _mm_sqrt_ps(v20).m128_f32[0] * mExtentAbove;
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, &pos) > (float)(v21 * v21) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, localWorld);
  v23 = rayPos->x;
  y = rayPos->y;
  vfptr = this->vfptr;
  v26 = rayPos->z;
  v27 = v38 * y;
  v45 = (float)((float)((float)(*(float *)&v37[2] * y) + (float)(pos.z * rayPos->x)) + (float)(v39 * v26)) + v42;
  v28 = rayDir->z;
  v29 = *(float *)v37;
  v30 = v27 + (float)(*(float *)v37 * v23);
  v31 = rayDir->y;
  v32 = rayDir->x;
  *(float *)v37 = v45;
  pos.y = (float)((float)((float)(*(float *)&v37[3] * v31) + (float)(v36 * v32)) + (float)(v40 * v28)) + v43;
  pos.z = (float)((float)((float)(v38 * v31) + (float)(v29 * v32)) + (float)(v41 * v28)) + v44;
  pos.x = (float)(v30 + (float)(v41 * v26)) + v44;
  result = vfptr->IsHitPlaneRay(this, (UFG::qVector3 *)v37, &pos, (UFG::qVector3 *)v46);
  if ( v46 )
  {
    v33 = (float)((float)((float)(v46[1] * localWorld->v1.y) + (float)(*v46 * localWorld->v0.y))
                + (float)(v46[2] * localWorld->v2.y))
        + localWorld->v3.y;
    v34 = (float)((float)((float)(v46[1] * localWorld->v1.z) + (float)(*v46 * localWorld->v0.z))
                + (float)(v46[2] * localWorld->v2.z))
        + localWorld->v3.z;
    *v46 = (float)((float)((float)(v46[1] * localWorld->v1.x) + (float)(*v46 * localWorld->v0.x))
                 + (float)(v46[2] * localWorld->v2.x))
         + localWorld->v3.x;
    v46[1] = v33;
    v46[2] = v34;
  }
  return result;
}

// File Line: 756
// RVA: 0x240D10
char __fastcall UFG::RegionPolygon::IsHitRay(
        UFG::RegionPolygon *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qVector3 *pHitPos)
{
  float mOrigDist; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  unsigned int mVertCount; // r9d
  UFG::qVector2 *mpVerts; // r8
  float y; // xmm9_4
  float x; // xmm8_4
  float z; // xmm10_4
  float v16; // xmm3_4
  float v17; // xmm3_4
  char result; // al
  float v19; // xmm5_4
  float v20; // xmm4_4
  UFG::qVector3 v21; // [rsp+18h] [rbp-49h] BYREF
  UFG::qVector3 *hit_enter_p; // [rsp+28h] [rbp-39h] BYREF
  UFG::qVector3 *hit_exit_p; // [rsp+30h] [rbp-31h]
  UFG::qVector3 endXY; // [rsp+38h] [rbp-29h] BYREF
  UFG::qVector3 startXY; // [rsp+48h] [rbp-19h] BYREF
  float pPDist[6]; // [rsp+C8h] [rbp+67h] BYREF

  if ( !UFG::qBox::IsHitRay(&this->mBoundingBox, rayPos, rayDir, 0i64, 0i64) )
    return 0;
  mOrigDist = this->mOrigDist;
  hit_exit_p = &v21;
  if ( !(unsigned int)UFG::qIntersectRaySlab(
                        rayPos,
                        rayDir,
                        &this->mNormal,
                        mOrigDist + this->mExtentBelow,
                        mOrigDist + this->mExtentAbove,
                        (UFG::qVector3 *)&hit_enter_p,
                        &v21) )
    return 0;
  v9 = *(float *)&hit_enter_p;
  v10 = *((float *)&hit_enter_p + 1);
  mVertCount = this->mVertCount;
  mpVerts = (UFG::qVector2 *)this->mpVerts;
  hit_enter_p = 0i64;
  y = this->mNormal.y;
  x = this->mNormal.x;
  z = this->mNormal.z;
  v16 = (float)((float)((float)(x * v9) + (float)(y * v10)) + (float)(z * *(float *)&hit_exit_p)) - this->mOrigDist;
  startXY.x = v9 - (float)(x * v16);
  startXY.z = *(float *)&hit_exit_p - (float)(z * v16);
  startXY.y = v10 - (float)(y * v16);
  v17 = (float)((float)((float)(x * v21.x) + (float)(y * v21.y)) + (float)(z * v21.z)) - this->mOrigDist;
  endXY.x = v21.x - (float)(x * v17);
  endXY.y = v21.y - (float)(y * v17);
  endXY.z = v21.z - (float)(z * v17);
  if ( !pHitPos )
    return UFG::qIntersectSegPolyXY(
             (UFG::qVector2 *)&startXY,
             (UFG::qVector2 *)&endXY,
             mpVerts,
             mVertCount,
             0i64,
             hit_enter_p);
  if ( !UFG::qIntersectSegPolyXY(
          (UFG::qVector2 *)&startXY,
          (UFG::qVector2 *)&endXY,
          mpVerts,
          mVertCount,
          pPDist,
          hit_enter_p) )
    return 0;
  result = 1;
  v19 = (float)((float)(v21.y - *((float *)&hit_enter_p + 1)) * pPDist[0]) + *((float *)&hit_enter_p + 1);
  v20 = (float)((float)(v21.z - *(float *)&hit_exit_p) * pPDist[0]) + *(float *)&hit_exit_p;
  pHitPos->x = (float)((float)(v21.x - *(float *)&hit_enter_p) * pPDist[0]) + *(float *)&hit_enter_p;
  pHitPos->y = v19;
  pHitPos->z = v20;
  return result;
}

// File Line: 811
// RVA: 0x2414A0
bool __fastcall UFG::RegionPolygon::IsHitRayWS(
        UFG::RegionPolygon *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        UFG::qMatrix44 *localWorld,
        UFG::qVector3 *pHitPos)
{
  float z; // xmm5_4
  float x; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  __m128 y_low; // xmm2
  float mExtentAbove; // xmm3_4
  __m128 v20; // xmm1
  float v21; // xmm6_4
  bool result; // al
  float v23; // xmm3_4
  float y; // xmm2_4
  UFG::RegionBaseVtbl *vfptr; // rax
  float v26; // xmm4_4
  float v27; // xmm13_4
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm13_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm6_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-79h] BYREF
  float v36; // [rsp+2Ch] [rbp-6Dh]
  int v37[4]; // [rsp+30h] [rbp-69h] BYREF
  float v38; // [rsp+40h] [rbp-59h]
  float v39; // [rsp+48h] [rbp-51h]
  float v40; // [rsp+4Ch] [rbp-4Dh]
  float v41; // [rsp+50h] [rbp-49h]
  float v42; // [rsp+58h] [rbp-41h]
  float v43; // [rsp+5Ch] [rbp-3Dh]
  float v44; // [rsp+60h] [rbp-39h]
  float v45; // [rsp+F8h] [rbp+5Fh]
  float *v46; // [rsp+118h] [rbp+7Fh]

  z = this->mCenter.z;
  x = this->mCenter.x;
  v11 = localWorld->v2.x;
  v12 = x * localWorld->v0.z;
  v13 = (float)((float)((float)(this->mCenter.y * localWorld->v1.x) + (float)(x * localWorld->v0.x)) + (float)(v11 * z))
      + localWorld->v3.x;
  v14 = (float)(x * localWorld->v0.y) + (float)(this->mCenter.y * localWorld->v1.y);
  v15 = this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z;
  v16 = (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x)
      * (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x);
  v17 = (float)((float)((float)(this->mCenter.y * localWorld->v1.z) + v12) + (float)(z * localWorld->v2.z))
      + localWorld->v3.z;
  pos.y = (float)(v14 + (float)(z * localWorld->v2.y)) + localWorld->v3.y;
  y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mBoundingBox.mMin.y;
  pos.x = v13;
  pos.z = v17;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + v16) + (float)(v15 * v15);
  mExtentAbove = _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
  if ( mExtentAbove <= this->mExtentAbove )
    mExtentAbove = this->mExtentAbove;
  if ( mExtentAbove <= this->mExtentBelow )
    mExtentAbove = this->mExtentBelow;
  v20 = (__m128)LODWORD(localWorld->v2.y);
  v20.m128_f32[0] = (float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v11 * v11))
                  + (float)(localWorld->v2.z * localWorld->v2.z);
  v21 = _mm_sqrt_ps(v20).m128_f32[0] * mExtentAbove;
  if ( UFG::qDistanceSqrRayPoint(rayPos, rayDir, &pos) > (float)(v21 * v21) )
    return 0;
  UFG::qInverse((UFG::qMatrix44 *)&pos.z, localWorld);
  v23 = rayPos->x;
  y = rayPos->y;
  vfptr = this->vfptr;
  v26 = rayPos->z;
  v27 = v38 * y;
  v45 = (float)((float)((float)(*(float *)&v37[2] * y) + (float)(pos.z * rayPos->x)) + (float)(v39 * v26)) + v42;
  v28 = rayDir->z;
  v29 = *(float *)v37;
  v30 = v27 + (float)(*(float *)v37 * v23);
  v31 = rayDir->y;
  v32 = rayDir->x;
  *(float *)v37 = v45;
  pos.y = (float)((float)((float)(*(float *)&v37[3] * v31) + (float)(v36 * v32)) + (float)(v40 * v28)) + v43;
  pos.z = (float)((float)((float)(v38 * v31) + (float)(v29 * v32)) + (float)(v41 * v28)) + v44;
  pos.x = (float)(v30 + (float)(v41 * v26)) + v44;
  result = vfptr->IsHitRay(this, (UFG::qVector3 *)v37, &pos, (UFG::qVector3 *)v46);
  if ( v46 )
  {
    v33 = (float)((float)((float)(v46[1] * localWorld->v1.y) + (float)(*v46 * localWorld->v0.y))
                + (float)(v46[2] * localWorld->v2.y))
        + localWorld->v3.y;
    v34 = (float)((float)((float)(v46[1] * localWorld->v1.z) + (float)(*v46 * localWorld->v0.z))
                + (float)(v46[2] * localWorld->v2.z))
        + localWorld->v3.z;
    *v46 = (float)((float)((float)(v46[1] * localWorld->v1.x) + (float)(*v46 * localWorld->v0.x))
                 + (float)(v46[2] * localWorld->v2.x))
         + localWorld->v3.x;
    v46[1] = v33;
    v46[2] = v34;
  }
  return result;
}

// File Line: 851
// RVA: 0x23A7D0
__int64 __fastcall UFG::RegionPolygon::CycleAspect(UFG::RegionPolygon *this, unsigned int aspect, bool forward)
{
  unsigned int v3; // edx

  if ( forward )
  {
    v3 = aspect + 1;
    if ( v3 == this->mVertCount )
    {
      return 4294967195i64;
    }
    else
    {
      if ( v3 > 0xFFFFFF9C )
        return 0;
      return v3;
    }
  }
  else if ( aspect )
  {
    if ( aspect == -101 )
      return this->mVertCount - 1;
    else
      return aspect - 1;
  }
  else
  {
    return 4294967196i64;
  }
}

// File Line: 898
// RVA: 0x23C380
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetAspectCenter(
        UFG::RegionPolygon *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  UFG::qVector3 *v3; // rax
  float mExtentAbove; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  if ( aspect < this->mVertCount )
  {
    *result = this->mpVerts[aspect];
    return result;
  }
  if ( aspect == -101 )
  {
    mExtentAbove = this->mExtentAbove;
  }
  else
  {
    if ( aspect != -100 )
    {
      *result = this->mCenter;
      return result;
    }
    mExtentAbove = this->mExtentBelow;
  }
  v3 = result;
  v5 = (float)(mExtentAbove * this->mNormal.y) + this->mCenter.y;
  v6 = (float)(mExtentAbove * this->mNormal.x) + this->mCenter.x;
  result->z = (float)(mExtentAbove * this->mNormal.z) + this->mCenter.z;
  result->y = v5;
  result->x = v6;
  return v3;
}

// File Line: 922
// RVA: 0x23C6B0
UFG::qVector3 *__fastcall UFG::RegionPolygon::GetAspectNormal(
        UFG::RegionPolygon *this,
        UFG::qVector3 *result,
        unsigned int aspect)
{
  unsigned int mVertCount; // r11d
  __int64 v5; // rax
  float v6; // xmm2_4
  __m128 z_low; // xmm5
  float x; // xmm6_4
  __int64 v9; // rcx
  UFG::qVector3 *mpVerts; // r8
  __int64 v11; // rcx
  float v12; // xmm3_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  __m128 v18; // xmm3
  UFG::qVector3 *v19; // rax
  int v20; // xmm1_4
  float y; // xmm0_4

  mVertCount = this->mVertCount;
  if ( aspect >= mVertCount )
  {
    if ( aspect == -100 )
    {
      v19 = result;
      v20 = LODWORD(this->mNormal.z) ^ _xmm[0];
      LODWORD(result->x) = LODWORD(this->mNormal.x) ^ _xmm[0];
      y = this->mNormal.y;
      LODWORD(result->z) = v20;
      LODWORD(result->y) = LODWORD(y) ^ _xmm[0];
    }
    else
    {
      *result = this->mNormal;
      return result;
    }
  }
  else
  {
    v5 = mVertCount - 1;
    if ( aspect )
      v5 = aspect - 1;
    v6 = this->mNormal.y;
    z_low = (__m128)LODWORD(this->mNormal.z);
    x = this->mNormal.x;
    v9 = aspect + 1;
    mpVerts = this->mpVerts;
    if ( (_DWORD)v9 == mVertCount )
      v9 = 0i64;
    v11 = v9;
    v12 = mpVerts[v11].y - mpVerts[v5].y;
    v13 = mpVerts[v11].z - mpVerts[v5].z;
    v14 = mpVerts[v11].x - mpVerts[v5].x;
    v15 = (float)(this->mNormal.y * v13) - (float)(this->mNormal.z * v12);
    z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v14) - (float)(x * v13);
    v16 = (float)(x * v12) - (float)(v6 * v14);
    v17 = 0.0;
    v18 = z_low;
    v18.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v15 * v15)) + (float)(v16 * v16);
    if ( v18.m128_f32[0] != 0.0 )
      v17 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
    v19 = result;
    result->x = v15 * v17;
    result->z = v16 * v17;
    result->y = z_low.m128_f32[0] * v17;
  }
  return v19;
}

// File Line: 945
// RVA: 0x23E7F0
__int64 __fastcall UFG::RegionPolygon::InsertAspect(UFG::RegionPolygon *this, unsigned int aspect)
{
  unsigned int mVertCount; // eax
  UFG::qVector3 *mpVerts; // r8
  __int64 v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm1_4
  UFG::qVector3 vert; // [rsp+20h] [rbp-18h] BYREF

  mVertCount = this->mVertCount;
  if ( aspect >= mVertCount )
    return aspect;
  mpVerts = this->mpVerts;
  v4 = aspect + 1;
  if ( (unsigned int)v4 >= mVertCount )
    v4 = 0i64;
  v5 = mpVerts[v4].y + mpVerts[aspect].y;
  v6 = mpVerts[v4].z + mpVerts[aspect].z;
  vert.x = (float)(mpVerts[v4].x + mpVerts[aspect].x) * 0.5;
  vert.y = v5 * 0.5;
  vert.z = v6 * 0.5;
  UFG::RegionPolygon::InsertVert(this, &vert, v4);
  return (unsigned int)v4;
}

// File Line: 975
// RVA: 0x23F6B0
char __fastcall UFG::RegionPolygon::IsHitAspect(
        UFG::RegionPolygon *this,
        UFG::qVector3 *rayPos,
        UFG::qVector3 *rayDir,
        unsigned int *pHitAspect)
{
  unsigned int mVertCount; // r14d
  int v5; // r13d
  UFG::qVector3 *mpVerts; // rcx
  float v10; // xmm6_4
  unsigned int v12; // ebp
  unsigned int v13; // ebx
  float v14; // xmm0_4
  char result; // al
  UFG::RegionBaseVtbl *vfptr; // rax
  int v17[4]; // [rsp+20h] [rbp-58h] BYREF

  mVertCount = this->mVertCount;
  v5 = 0;
  mpVerts = this->mpVerts;
  v10 = FLOAT_0_0099999998;
  v12 = -99;
  v13 = 0;
  while ( 1 )
  {
    v14 = UFG::qDistanceSqrRayPoint(rayPos, rayDir, &mpVerts[v13]);
    if ( v14 < v10 )
    {
      if ( !pHitAspect )
        return 1;
      v12 = v13;
      v10 = v14;
    }
    if ( ++v13 > mVertCount )
      break;
    mpVerts = this->mpVerts;
  }
  if ( v10 != 0.0099999998 )
  {
    *pHitAspect = v12;
    return 1;
  }
  vfptr = this->vfptr;
  if ( !pHitAspect )
    return vfptr->IsHitRay(this, rayPos, rayDir, 0i64);
  if ( !vfptr->IsHitRay(this, rayPos, rayDir, (UFG::qVector3 *)v17) )
    return 0;
  result = 1;
  LOBYTE(v5) = (float)((float)((float)((float)(*(float *)&v17[1] * this->mNormal.y)
                                     + (float)(*(float *)v17 * this->mNormal.x))
                             + (float)(*(float *)&v17[2] * this->mNormal.z))
                     - this->mOrigDist) < 0.0;
  *pHitAspect = v5 - 101;
  return result;
}

// File Line: 1050
// RVA: 0x245080
__int64 __fastcall UFG::RegionPolygon::RemoveAspect(UFG::RegionPolygon *this, unsigned int aspect)
{
  unsigned int mVertCount; // r8d
  unsigned int v3; // ebx
  UFG::qVector3 *mpVerts; // rax
  unsigned int v6; // r8d

  mVertCount = this->mVertCount;
  v3 = aspect;
  if ( aspect < mVertCount && mVertCount > 1 )
  {
    mpVerts = this->mpVerts;
    v6 = mVertCount - 1;
    this->mVertCount = v6;
    UFG::qMemMove(&mpVerts[aspect], (char *)&mpVerts[aspect + 1], 12 * (v6 - aspect));
    UFG::RegionPolygon::RecalcCachedValues(this, 1);
    if ( v3 == this->mVertCount )
      return 0;
  }
  return v3;
}

// File Line: 1073
// RVA: 0x2462C0
void __fastcall UFG::RegionPolygon::TranslateAspect(
        UFG::RegionPolygon *this,
        unsigned int aspect,
        UFG::qVector3 *delta)
{
  __int64 v3; // rdx
  UFG::qVector3 *mpVerts; // rax
  float v5; // xmm2_4
  float v6; // xmm1_4
  UFG::qVector3 *v7; // rax
  float x; // xmm3_4
  float z; // xmm5_4
  float y; // xmm8_4
  float v11; // xmm6_4
  float v12; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm2_4

  if ( aspect < this->mVertCount )
  {
    v3 = aspect;
    mpVerts = this->mpVerts;
    v5 = delta->y + mpVerts[v3].y;
    v6 = delta->z + mpVerts[v3].z;
    mpVerts[v3].x = delta->x + mpVerts[v3].x;
    mpVerts[v3].y = v5;
    mpVerts[v3].z = v6;
    if ( this->mVertCount >= 4 )
    {
      v7 = this->mpVerts;
      x = this->mNormal.x;
      z = this->mNormal.z;
      y = v7[v3].y;
      v11 = v7[v3].z;
      v12 = v7[v3].x;
      v13 = (float)((float)((float)(x * v12) + (float)(this->mNormal.y * y)) + (float)(z * v11)) - this->mOrigDist;
      v7[v3].y = y - (float)(this->mNormal.y * v13);
      v7[v3].z = v11 - (float)(z * v13);
      v7[v3].x = v12 - (float)(x * v13);
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
  unsigned int mVertCount; // eax
  bool v4; // zf
  UFG::qVector3 *mpVerts; // rax
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm5_4
  __m128 z_low; // xmm7
  float v11; // xmm6_4
  float v12; // xmm3_4
  __m128 v13; // xmm2
  float v14; // xmm3_4
  float x; // xmm4_4
  float v16; // xmm5_4
  float z; // xmm3_4
  float y; // xmm5_4
  float v19; // xmm8_4
  __m128 y_low; // xmm9
  float v21; // xmm10_4
  float v22; // xmm3_4
  __m128 v23; // xmm4
  float v24; // xmm1_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  float v28; // xmm11_4
  __m128 v29; // xmm12
  __m128 v30; // xmm13
  __m128 v31; // xmm4
  float v32; // xmm1_4
  float v33; // xmm11_4
  float v34; // xmm12_4
  __m128 x_low; // xmm14
  __m128 v36; // xmm7
  float v37; // xmm15_4
  __m128 v38; // xmm4
  float v39; // xmm1_4
  float v40; // xmm7_4
  float v41; // xmm15_4
  float v42; // xmm4_4
  __m128 v43; // xmm5
  float v44; // xmm6_4
  __m128 v45; // xmm0
  float v46; // xmm1_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm6_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  __m128 v52; // xmm13
  float v53; // xmm0_4
  float v54; // xmm12_4
  __m128 v55; // xmm11
  float v56; // xmm11_4
  float v57; // xmm0_4
  float v58; // xmm1_4
  float v59; // xmm11_4
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm0_4
  float v63; // xmm4_4
  __m128 v64; // xmm12
  float v65; // xmm7_4
  float v66; // xmm11_4
  __m128 v67; // xmm8
  float v68; // xmm1_4
  float v69; // xmm6_4
  float v70; // xmm4_4
  __m128 v71; // xmm2
  float v72; // xmm3_4
  UFG::qVector3 *v73; // rdx
  __int64 v74; // rax
  float mExtentBelow; // xmm6_4
  float mExtentAbove; // xmm7_4
  float v77; // xmm8_4
  float v78; // xmm5_4
  unsigned __int64 v79; // r9
  float *p_z; // rcx
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

  if ( recalcNormal )
  {
    mVertCount = this->mVertCount;
    if ( mVertCount <= 1 )
    {
      x = UFG::qVector3::msDirUp.x;
      y = UFG::qVector3::msDirUp.y;
      z = UFG::qVector3::msDirUp.z;
    }
    else
    {
      v4 = mVertCount == 2;
      mpVerts = this->mpVerts;
      if ( v4 )
      {
        z_low = (__m128)LODWORD(mpVerts[1].z);
        v6 = mpVerts[1].x - mpVerts->x;
        v7 = mpVerts[1].y - mpVerts->y;
        v8 = z_low.m128_f32[0] - mpVerts->z;
        v9 = (float)(v7 * UFG::qVector3::msDirFront.z) - (float)(v8 * UFG::qVector3::msDirFront.y);
        z_low.m128_f32[0] = (float)(v8 * UFG::qVector3::msDirFront.x) - (float)(v6 * UFG::qVector3::msDirFront.z);
        v11 = (float)(v6 * UFG::qVector3::msDirFront.y) - (float)(v7 * UFG::qVector3::msDirFront.x);
        if ( v11 >= 0.0 )
          v12 = *(float *)&FLOAT_1_0;
        else
          v12 = FLOAT_N1_0;
        v13 = z_low;
        v13.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v9 * v9))
                        + (float)(v11 * v11);
        v14 = v12 / _mm_sqrt_ps(v13).m128_f32[0];
        x = v14 * v9;
        v16 = v14;
        z = v14 * v11;
        y = v16 * z_low.m128_f32[0];
      }
      else
      {
        y_low = (__m128)LODWORD(mpVerts[1].y);
        v19 = mpVerts[1].x - mpVerts->x;
        y_low.m128_f32[0] = y_low.m128_f32[0] - mpVerts->y;
        v21 = mpVerts[1].z - mpVerts->z;
        v23 = y_low;
        v22 = *(float *)&FLOAT_1_0;
        v23.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v19 * v19))
                        + (float)(v21 * v21);
        if ( v23.m128_f32[0] == 0.0 )
          v24 = 0.0;
        else
          v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
        v29 = (__m128)LODWORD(mpVerts[2].y);
        v30 = (__m128)LODWORD(mpVerts[2].z);
        v25 = v19 * v24;
        v26 = y_low.m128_f32[0] * v24;
        v27 = v21 * v24;
        v28 = mpVerts[2].x - mpVerts[1].x;
        v29.m128_f32[0] = v29.m128_f32[0] - mpVerts[1].y;
        v30.m128_f32[0] = v30.m128_f32[0] - mpVerts[1].z;
        v31 = v29;
        v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28))
                        + (float)(v30.m128_f32[0] * v30.m128_f32[0]);
        if ( v31.m128_f32[0] == 0.0 )
          v32 = 0.0;
        else
          v32 = 1.0 / _mm_sqrt_ps(v31).m128_f32[0];
        x_low = (__m128)LODWORD(mpVerts->x);
        v36 = (__m128)LODWORD(mpVerts->y);
        v33 = v28 * v32;
        v34 = v29.m128_f32[0] * v32;
        v30.m128_f32[0] = v30.m128_f32[0] * v32;
        x_low.m128_f32[0] = x_low.m128_f32[0] - mpVerts[2].x;
        v36.m128_f32[0] = v36.m128_f32[0] - mpVerts[2].y;
        v37 = mpVerts->z - mpVerts[2].z;
        v38 = v36;
        v38.m128_f32[0] = (float)((float)(v36.m128_f32[0] * v36.m128_f32[0])
                                + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]))
                        + (float)(v37 * v37);
        if ( v38.m128_f32[0] == 0.0 )
          v39 = 0.0;
        else
          v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
        x_low.m128_f32[0] = x_low.m128_f32[0] * v39;
        v40 = v36.m128_f32[0] * v39;
        v41 = v37 * v39;
        v43 = v30;
        v42 = (float)(v34 * v27) - (float)(v30.m128_f32[0] * v26);
        v43.m128_f32[0] = (float)(v30.m128_f32[0] * v25) - (float)(v33 * v27);
        v44 = (float)(v33 * v26) - (float)(v34 * v25);
        *(float *)&v116 = (float)(v43.m128_f32[0] * v43.m128_f32[0]) + (float)(v42 * v42);
        v45 = (__m128)v116;
        v45.m128_f32[0] = *(float *)&v116 + (float)(v44 * v44);
        if ( v45.m128_f32[0] == 0.0 )
          v46 = 0.0;
        else
          v46 = 1.0 / _mm_sqrt_ps(v45).m128_f32[0];
        v47 = v42 * v46;
        v48 = v43.m128_f32[0] * v46;
        v49 = v44 * v46;
        v50 = (float)(v40 * v30.m128_f32[0]) - (float)(v41 * v34);
        v115 = v50;
        v51 = x_low.m128_f32[0] * v30.m128_f32[0];
        v52 = (__m128)COERCE_UNSIGNED_INT(v41 * v33);
        v52.m128_f32[0] = v52.m128_f32[0] - v51;
        v53 = v40 * v33;
        v55 = v52;
        v54 = (float)(x_low.m128_f32[0] * v34) - v53;
        v55.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v50 * v50)) + (float)(v54 * v54);
        if ( v55.m128_f32[0] == 0.0 )
          v56 = 0.0;
        else
          v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
        v57 = v56;
        v58 = v56;
        v59 = v56 * v54;
        v64 = x_low;
        v60 = v49 + v59;
        v61 = v48 + (float)(v57 * v52.m128_f32[0]);
        v62 = v40;
        v63 = v47 + (float)(v58 * v115);
        v64.m128_f32[0] = (float)(x_low.m128_f32[0] * v27) - (float)(v41 * v25);
        v65 = (float)(v40 * v25) - (float)(x_low.m128_f32[0] * v26);
        v67 = v64;
        v66 = (float)(v41 * v26) - (float)(v62 * v27);
        v67.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)(v66 * v66)) + (float)(v65 * v65);
        if ( v67.m128_f32[0] == 0.0 )
          v68 = 0.0;
        else
          v68 = 1.0 / _mm_sqrt_ps(v67).m128_f32[0];
        v69 = v60 + (float)(v65 * v68);
        v70 = v63 + (float)(v66 * v68);
        v43.m128_f32[0] = v61 + (float)(v64.m128_f32[0] * v68);
        if ( v69 < 0.0 )
          v22 = FLOAT_N1_0;
        v71 = v43;
        v71.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v43.m128_f32[0]) + (float)(v70 * v70)) + (float)(v69 * v69);
        v72 = v22 / _mm_sqrt_ps(v71).m128_f32[0];
        x = v70 * v72;
        y = v43.m128_f32[0] * v72;
        z = v72 * v69;
      }
    }
    this->mNormal.x = x;
    this->mNormal.y = y;
    this->mNormal.z = z;
  }
  v73 = this->mpVerts;
  v74 = this->mVertCount;
  this->mOrigDist = (float)((float)(v73->y * this->mNormal.y) + (float)(v73->x * this->mNormal.x))
                  + (float)(v73->z * this->mNormal.z);
  if ( (_DWORD)v74 )
  {
    mExtentBelow = this->mExtentBelow;
    mExtentAbove = this->mExtentAbove;
    v77 = mExtentAbove;
    v78 = mExtentAbove * this->mNormal.z;
    v79 = (unsigned __int64)&v73[v74];
    p_z = &v73->z;
    v81 = mExtentBelow;
    v82 = mExtentAbove * this->mNormal.x;
    v83 = v77 * this->mNormal.y;
    v84 = mExtentBelow * this->mNormal.z;
    v85 = v78 + v73->z;
    v86 = v83 + v73->y;
    v87 = v81 * this->mNormal.x;
    v88 = this->mExtentBelow * this->mNormal.y;
    this->mBoundingBox.mMax.x = v82 + v73->x;
    this->mBoundingBox.mMax.y = v86;
    this->mBoundingBox.mMax.z = v85;
    v89 = v88 + v73->y;
    v90 = v84 + v73->z;
    this->mBoundingBox.mMin.x = v87 + v73->x;
    this->mBoundingBox.mMin.y = v89;
    this->mBoundingBox.mMin.z = v90;
    if ( (unsigned __int64)v73 < v79 )
    {
      do
      {
        v91 = this->mBoundingBox.mMax.x;
        v92 = v83 + *(p_z - 1);
        v93 = v78 + *p_z;
        if ( v91 <= (float)(v82 + *(p_z - 2)) )
          v91 = v82 + *(p_z - 2);
        this->mBoundingBox.mMax.x = v91;
        v94 = this->mBoundingBox.mMax.y;
        if ( v94 <= v92 )
          v94 = v92;
        this->mBoundingBox.mMax.y = v94;
        v95 = this->mBoundingBox.mMax.z;
        if ( v95 <= v93 )
          v95 = v93;
        this->mBoundingBox.mMax.z = v95;
        v96 = this->mBoundingBox.mMin.x;
        v97 = v88 + *(p_z - 1);
        v98 = v84 + *p_z;
        if ( v96 >= (float)(v87 + *(p_z - 2)) )
          v96 = v87 + *(p_z - 2);
        this->mBoundingBox.mMin.x = v96;
        v99 = this->mBoundingBox.mMin.y;
        if ( v99 >= v97 )
          v99 = v97;
        this->mBoundingBox.mMin.y = v99;
        v100 = this->mBoundingBox.mMin.z;
        if ( v100 >= v98 )
          v100 = v98;
        p_z += 3;
        this->mBoundingBox.mMin.z = v100;
      }
      while ( (unsigned __int64)(p_z - 2) < v79 );
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
  v104 = this->mBoundingBox.mMin.y;
  v105 = this->mBoundingBox.mMin.z;
  this->mCenter.x = this->mBoundingBox.mMin.x;
  this->mCenter.y = v104;
  this->mCenter.z = v105;
  v106 = (float)(v104 + this->mBoundingBox.mMax.y) * 0.5;
  v107 = v105 + this->mBoundingBox.mMax.z;
  v108 = this->mBoundingBox.mMax.x;
  this->mCenter.y = v106;
  v109 = v107 * 0.5;
  v110 = v108 + this->mCenter.x;
  this->mCenter.z = v109;
  v111 = v110 * 0.5;
  this->mCenter.x = v111;
  v112 = (float)((float)((float)(v111 * this->mNormal.x) + (float)(v106 * this->mNormal.y))
               + (float)(v109 * this->mNormal.z))
       - this->mOrigDist;
  v113 = v112 * this->mNormal.x;
  v114 = v112 * this->mNormal.y;
  this->mCenter.z = v109 - (float)(v112 * this->mNormal.z);
  this->mCenter.x = v111 - v113;
  this->mCenter.y = v106 - v114;
}r.z = v109 - (float)(v112 * this->mNormal.z);
  this->mCenter.x = v111 - v113;
  this->mCenter.y = v106 - v114;
}

