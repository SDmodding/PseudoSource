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
UFG::qVector4 *__fastcall UFG::qHalfVector4::operator UFG::qVector4 const(UFG::qHalfVector4 *this, UFG::qVector4 *result)
{
  unsigned int v2; // er8
  UFG::qVector4 *v3; // r11
  UFG::qHalfVector4 *v4; // r10
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  UFG::qVector4 *v10; // rax

  v2 = this->x.mRep;
  v3 = result;
  v4 = this;
  v5 = this->y.mRep;
  LODWORD(result->x) = ((((v2 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v2 & 0x3FF | 8 * (v2 & 0xFFFF8000)) << 13);
  v6 = ((((v5 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v5 & 0x3FF | 8 * (v5 & 0xFFFF8000)) << 13);
  v7 = v4->z.mRep;
  LODWORD(v3->y) = v6;
  v8 = ((((v7 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v7 & 0x3FF | 8 * (v7 & 0xFFFF8000)) << 13);
  v9 = v4->w.mRep;
  LODWORD(v3->z) = v8;
  v10 = v3;
  LODWORD(v3->w) = ((((v9 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v9 & 0x3FF | 8 * (v9 & 0xFFFF8000)) << 13);
  return v10;
}

// File Line: 246
// RVA: 0x1E4B20
UFG::qHalfVector3 *__fastcall UFG::qHalfVector3::operator=(UFG::qHalfVector3 *this, UFG::qVector3 *t)
{
  UFG::qVector3 *v2; // rbx
  unsigned int v3; // er8
  int v4; // er10
  unsigned __int16 v5; // r10
  unsigned int v6; // er8
  unsigned int v7; // edx
  int v8; // er8
  unsigned __int16 v9; // r8
  unsigned int v10; // edx
  unsigned int v11; // edx
  int v12; // er8
  UFG::qHalfVector3 *result; // rax
  unsigned int v14; // edx
  float v15; // [rsp+8h] [rbp+8h]
  float v16; // [rsp+8h] [rbp+8h]
  float v17; // [rsp+8h] [rbp+8h]

  v2 = t;
  v15 = t->x;
  v3 = LODWORD(t->x) & 0x7FFFFFFF;
  v4 = (LODWORD(t->x) >> 16) & 0x8000;
  if ( v3 <= 0x47FFEFFF )
  {
    if ( v3 >= 0x38800000 )
      v6 = v3 - 939524096;
    else
      v6 = (LODWORD(v15) & 0x7FFFFF | 0x800000u) >> (113 - (v3 >> 23));
    v5 = ((((v6 >> 13) & 1) + v6 + 4095) >> 13) | v4;
  }
  else
  {
    v5 = v4 | 0x7FFF;
  }
  this->x.mRep = v5;
  v16 = t->y;
  v7 = LODWORD(v16) & 0x7FFFFFFF;
  v8 = (LODWORD(v16) >> 16) & 0x8000;
  if ( (LODWORD(v16) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v7 >= 0x38800000 )
      v10 = v7 - 939524096;
    else
      v10 = (LODWORD(v16) & 0x7FFFFF | 0x800000u) >> (113 - (v7 >> 23));
    v9 = ((((v10 >> 13) & 1) + v10 + 4095) >> 13) | v8;
  }
  else
  {
    v9 = v8 | 0x7FFF;
  }
  this->y.mRep = v9;
  v17 = v2->z;
  v11 = LODWORD(v17) & 0x7FFFFFFF;
  v12 = (LODWORD(v17) >> 16) & 0x8000;
  if ( (LODWORD(v17) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v11 >= 0x38800000 )
      v14 = v11 - 939524096;
    else
      v14 = (LODWORD(v17) & 0x7FFFFF | 0x800000u) >> (113 - (v11 >> 23));
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

