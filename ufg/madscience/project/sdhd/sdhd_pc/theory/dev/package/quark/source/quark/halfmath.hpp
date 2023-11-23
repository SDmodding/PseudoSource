// File Line: 17
// RVA: 0x1C0E0
void __fastcall UFG::qHalfFloat::qHalfFloat(UFG::qHalfFloat *this)
{
  this->mRep = 0;
}

// File Line: 113
// RVA: 0x1C2020
void __fastcall UFG::qHalfVector3::qHalfVector3(UFG::qHalfVector3 *this)
{
  *(_DWORD *)&this->x.mRep = 0;
  this->z.mRep = 0;
  this->x.mRep = 0;
  this->y.mRep = 0;
  this->z.mRep = 0;
}

// File Line: 162
// RVA: 0x1C2190
void __fastcall UFG::qHalfVector4::qHalfVector4(UFG::qHalfVector4 *this)
{
  *this = 0i64;
  this->x.mRep = 0;
  this->y.mRep = 0;
  this->z.mRep = 0;
  this->w.mRep = 0;
}

// File Line: 169
// RVA: 0x1C4E40
UFG::qVector4 *__fastcall UFG::qHalfVector4::operator UFG::qVector4(
        UFG::qHalfVector4 *this,
        UFG::qVector4 *result) const
{
  unsigned int mRep; // r8d
  unsigned int v5; // ecx
  float v6; // edx
  unsigned int v7; // ecx
  float v8; // edx
  unsigned int v9; // ecx
  UFG::qVector4 *v10; // rax

  mRep = this->x.mRep;
  v5 = this->y.mRep;
  LODWORD(result->x) = ((((mRep >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((mRep & 0x3FF | (8 * (mRep & 0xFFFF8000))) << 13);
  LODWORD(v6) = ((((v5 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v5 & 0x3FF | (8 * (v5 & 0xFFFF8000))) << 13);
  v7 = this->z.mRep;
  result->y = v6;
  LODWORD(v8) = ((((v7 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v7 & 0x3FF | (8 * (v7 & 0xFFFF8000))) << 13);
  v9 = this->w.mRep;
  result->z = v8;
  v10 = result;
  LODWORD(result->w) = ((((v9 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v9 & 0x3FF | (8 * (v9 & 0xFFFF8000))) << 13);
  return v10;
}

// File Line: 246
// RVA: 0x1E4B20
UFG::qHalfVector3 *__fastcall UFG::qHalfVector3::operator=(UFG::qHalfVector3 *this, UFG::qVector3 *t)
{
  unsigned int v3; // r8d
  int v4; // r10d
  unsigned __int16 v5; // r10
  unsigned int v6; // r8d
  unsigned int v7; // edx
  int v8; // r8d
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // r8d
  UFG::qHalfVector3 *result; // rax
  unsigned int v14; // edx
  float y; // [rsp+8h] [rbp+8h]
  float z; // [rsp+8h] [rbp+8h]

  v3 = LODWORD(t->x) & 0x7FFFFFFF;
  v4 = HIWORD(LODWORD(t->x)) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(t->x) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->x.mRep = v5;
  y = t->y;
  v7 = LODWORD(y) & 0x7FFFFFFF;
  v8 = HIWORD(LODWORD(y)) & 0x8000;
  if ( (LODWORD(y) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(y) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->y.mRep = v9;
  z = t->z;
  v11 = LODWORD(z) & 0x7FFFFFFF;
  v12 = HIWORD(LODWORD(z)) & 0x8000;
  if ( (LODWORD(z) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v14 = v11 - 939524096;
    else
      v14 = (LODWORD(z) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
    result = this;
    this->z.mRep = v12 | ((v14 + ((v14 >> 13) & 1) + 4095) >> 13);
  }
  else
  {
    result = this;
    this->z.mRep = v12 | 0x7FFF;
  }
  return result;
}

