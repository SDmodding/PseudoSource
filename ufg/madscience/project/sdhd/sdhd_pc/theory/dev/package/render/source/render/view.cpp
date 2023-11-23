// File Line: 65
// RVA: 0x159E0
Render::vDynamic *__fastcall `anonymous namespace::GetVertsCircle(int segCount, UFG::qColour *colour)
{
  __int64 v3; // r15
  unsigned int v4; // eax
  Render::vDynamic *v5; // rbx
  unsigned int v6; // eax
  float v7; // xmm6_4
  float v8; // xmm7_4
  float *p_z; // rdi
  unsigned __int64 v10; // rbp
  float z; // xmm1_4
  __int64 v12; // rax
  int v13; // ecx
  Render::vDynamic *v14; // rdx

  v3 = (unsigned int)segCount;
  v4 = _S1_0;
  if ( (_S1_0 & 1) == 0 )
  {
    v4 = _S1_0 | 1;
    _S1_0 |= 1u;
  }
  if ( (v4 & 2) == 0 )
    _S1_0 = v4 | 2;
  v5 = &spVerts[1];
  v6 = sSegCountLast;
  if ( segCount != sSegCountLast )
  {
    v7 = 0.0;
    v8 = 6.2831855 / (float)segCount;
    if ( &spVerts[1] < &spVerts[(unsigned int)segCount + 1] )
    {
      p_z = &spVerts[1].mPosition.z;
      v10 = (48 * (unsigned __int64)(unsigned int)segCount - 1) / 0x30 + 1;
      do
      {
        *(p_z - 1) = sinf(v7) * -0.5;
        *p_z = cosf(v7) * 0.5;
        v7 = v7 + v8;
        p_z += 12;
        --v10;
      }
      while ( v10 );
    }
    z = spVerts[1].mPosition.z;
    v12 = (unsigned int)(v3 + 1);
    spVerts[v12].mPosition.y = spVerts[1].mPosition.y;
    spVerts[v12].mPosition.z = z;
    v6 = v3;
    sSegCountLast = v3;
  }
  if ( colour->r != sColourLast.r
    || sColourLast.g != colour->g
    || sColourLast.b != colour->b
    || sColourLast.a != colour->a
    || (unsigned int)v3 > v6 )
  {
    v13 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    v14 = &spVerts[v3 + 2];
    if ( &spVerts[1] < v14 )
    {
      do
      {
        v5->mColour = v13;
        ++v5;
      }
      while ( v5 < v14 );
    }
    sColourLast = *colour;
  }
  return spVerts;
}

// File Line: 249
// RVA: 0xD230
__int64 __fastcall `anonymous namespace::AngleToSegment(float angle, int segCount)
{
  __m128 v2; // xmm1
  int v3; // ecx
  int v5; // ecx

  v2 = 0i64;
  v2.m128_f32[0] = (float)((float)segCount * angle) * 0.15915494;
  if ( v2.m128_f32[0] >= 0.0 )
  {
    v2.m128_f32[0] = v2.m128_f32[0] + 0.5;
    v5 = (int)v2.m128_f32[0];
    if ( (int)v2.m128_f32[0] != 0x80000000 && (float)v5 != v2.m128_f32[0] )
      v2.m128_f32[0] = (float)(v5 - (_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1));
  }
  else
  {
    v2.m128_f32[0] = v2.m128_f32[0] - 0.5;
    v3 = (int)v2.m128_f32[0];
    if ( (int)v2.m128_f32[0] != 0x80000000 && (float)v3 != v2.m128_f32[0] )
      return (unsigned int)(int)(float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1) + v3);
  }
  return (unsigned int)(int)v2.m128_f32[0];
}

// File Line: 282
// RVA: 0x155F0
Render::vDynamic *__fastcall `anonymous namespace::GetVertsAxes()
{
  if ( (_S3 & 1) == 0 )
    _S3 |= 1u;
  if ( !sAxesInit )
  {
    UFG::qMemSet(spAxesVerts, 0, 0x420u);
    *(_QWORD *)&spAxesVerts[0].mPosition.x = 1065353216i64;
    dword_14212B448 = 0;
    dword_14212B46C = (int)(float)(UFG::qColour::Red.r * 255.0) | (((int)(float)(UFG::qColour::Red.g * 255.0) | (((int)(float)(UFG::qColour::Red.b * 255.0) | ((int)(float)(UFG::qColour::Red.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B470 = 0i64;
    dword_14212B478 = 0;
    dword_14212B49C = dword_14212B46C;
    dword_14212B4A0 = 0;
    qword_14212B4A4 = 1065353216i64;
    dword_14212B4CC = (int)(float)(UFG::qColour::Green.r * 255.0) | (((int)(float)(UFG::qColour::Green.g * 255.0) | (((int)(float)(UFG::qColour::Green.b * 255.0) | ((int)(float)(UFG::qColour::Green.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B4D0 = 0i64;
    dword_14212B4D8 = 0;
    dword_14212B4FC = dword_14212B4CC;
    qword_14212B500 = 0i64;
    dword_14212B508 = 1065353216;
    dword_14212B52C = (int)(float)(UFG::qColour::Blue.r * 255.0) | (((int)(float)(UFG::qColour::Blue.g * 255.0) | (((int)(float)(UFG::qColour::Blue.b * 255.0) | ((int)(float)(UFG::qColour::Blue.a * 255.0) << 8)) << 8)) << 8);
    qword_14212B530 = 0i64;
    dword_14212B538 = 0;
    dword_14212B55C = dword_14212B52C;
    dword_14212B560 = 1040187392;
    qword_14212B564 = 1048576000i64;
    dword_14212B58C = dword_14212B46C;
    dword_14212B590 = -1107296256;
    dword_14212B594 = -1098907648;
    dword_14212B598 = 0;
    dword_14212B5BC = dword_14212B46C;
    dword_14212B5C0 = 1040187392;
    dword_14212B5C4 = -1098907648;
    dword_14212B5C8 = 0;
    dword_14212B5EC = dword_14212B46C;
    dword_14212B5F0 = -1107296256;
    qword_14212B5F4 = 1048576000i64;
    dword_14212B61C = dword_14212B46C;
    dword_14212B620 = 1040187392;
    qword_14212B624 = 1048576000i64;
    dword_14212B64C = dword_14212B4CC;
    qword_14212B650 = 0i64;
    dword_14212B658 = 0;
    dword_14212B67C = dword_14212B4CC;
    dword_14212B680 = -1107296256;
    qword_14212B684 = 1048576000i64;
    dword_14212B6AC = dword_14212B4CC;
    qword_14212B6B0 = 0i64;
    dword_14212B6B8 = 0;
    dword_14212B6DC = dword_14212B4CC;
    qword_14212B6E0 = 0i64;
    dword_14212B6E8 = 0;
    dword_14212B70C = dword_14212B4CC;
    dword_14212B710 = 0;
    dword_14212B714 = -1098907648;
    dword_14212B718 = 0;
    dword_14212B73C = dword_14212B4CC;
    dword_14212B740 = 1040187392;
    qword_14212B744 = 1048576000i64;
    dword_14212B76C = dword_14212B52C;
    dword_14212B770 = -1107296256;
    qword_14212B774 = 1048576000i64;
    dword_14212B79C = dword_14212B52C;
    dword_14212B7A0 = 1040187392;
    qword_14212B7A4 = 1048576000i64;
    dword_14212B7CC = dword_14212B52C;
    dword_14212B7D0 = -1107296256;
    dword_14212B7D4 = -1098907648;
    dword_14212B7D8 = 0;
    dword_14212B7FC = dword_14212B52C;
    dword_14212B800 = 1040187392;
    dword_14212B804 = -1098907648;
    dword_14212B808 = 0;
    dword_14212B82C = dword_14212B52C;
    dword_14212B830 = -1107296256;
    dword_14212B834 = -1098907648;
    dword_14212B838 = 0;
    dword_14212B85C = dword_14212B52C;
  }
  return spAxesVerts;
}

// File Line: 346
// RVA: 0x1453260
__int64 dynamic_initializer_for__Render::Poly::sModelHandle__()
{
  UFG::qResourceHandle::qResourceHandle(&Render::Poly::sModelHandle);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::Poly::sModelHandle__);
}

// File Line: 350
// RVA: 0xD740
void Render::Poly::DefaultModelInit(void)
{
  unsigned int mStringHashUpper32; // eax
  UFG::qResourceData *v1; // rax
  UFG::qResourceData *v2; // r14
  UFG::qBaseNodeRB *v3; // rcx
  _QWORD *v4; // rcx
  char *v5; // r15
  unsigned int mStringHash32; // ebp
  Illusion::Buffer *v7; // rdi
  __int64 mOffset; // rax
  char *v9; // r8
  float y; // xmm1_4
  float z; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  UFG::qResourceWarehouse *v26; // rax
  unsigned int v27; // edi
  Illusion::Buffer *v28; // rbx
  __int64 v29; // rax
  _DWORD *v30; // rcx
  UFG::qResourceWarehouse *v31; // rax
  UFG::qResourceWarehouse *v32; // rax
  unsigned int v33; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v35; // rax
  UFG::qString result; // [rsp+48h] [rbp-80h] BYREF
  UFG::qString v37; // [rsp+70h] [rbp-58h] BYREF

  UFG::qString::FormatEx(&v37, "DX10_PolyDefaultModel");
  mStringHashUpper32 = v37.mStringHashUpper32;
  if ( v37.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(v37.mData, 0xFFFFFFFF);
    v37.mStringHashUpper32 = mStringHashUpper32;
  }
  Render::Poly::sModelUID = mStringHashUpper32;
  v1 = Illusion::Factory::NewModel(v37.mData, mStringHashUpper32, 1u, 0i64, 0i64, 0i64);
  v2 = v1;
  v3 = v1[2].mNode.mChild[0];
  if ( v3 )
    v4 = (UFG::qBaseNodeRB **)((char *)&v3[5].mChild[2] + (_QWORD)v1);
  else
    v4 = 0i64;
  v5 = (char *)v4 + *v4;
  if ( !*v4 )
    v5 = 0i64;
  UFG::qString::FormatEx(&result, "PolyDefaultModel.VertexBuffer");
  mStringHash32 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    mStringHash32 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
    result.mStringHash32 = mStringHash32;
  }
  v7 = Illusion::Factory::NewBuffer(result.mData, mStringHash32, 0xC0u, 0i64, result.mData, 0i64, 0i64);
  v7->mBufferType = 0;
  v7->mElementByteSize = 48;
  v7->mNumElements = 4;
  mOffset = v7->mData.mOffset;
  if ( mOffset )
    v9 = (char *)&v7->mData + mOffset;
  else
    v9 = 0i64;
  *((_QWORD *)v9 + 6) = 0i64;
  *((_DWORD *)v9 + 14) = 0;
  *(_QWORD *)v9 = 1065353216i64;
  *((_DWORD *)v9 + 2) = 0;
  *((_DWORD *)v9 + 24) = 1065353216;
  *(_QWORD *)(v9 + 100) = 1065353216i64;
  *((_DWORD *)v9 + 36) = 0;
  *(_QWORD *)(v9 + 148) = 1065353216i64;
  *((_WORD *)v9 + 30) = 0;
  *((_WORD *)v9 + 31) = 0;
  *((_WORD *)v9 + 6) = 15360;
  *((_WORD *)v9 + 7) = 0;
  *((_WORD *)v9 + 54) = 15360;
  *((_WORD *)v9 + 55) = 15360;
  *((_WORD *)v9 + 78) = 0;
  *((_WORD *)v9 + 79) = 15360;
  *((_WORD *)v9 + 32) = 0;
  *((_WORD *)v9 + 33) = 0;
  *((_WORD *)v9 + 8) = 15360;
  *((_WORD *)v9 + 9) = 0;
  *((_WORD *)v9 + 56) = 15360;
  *((_WORD *)v9 + 57) = 15360;
  *((_WORD *)v9 + 80) = 0;
  *((_WORD *)v9 + 81) = 15360;
  *((_DWORD *)v9 + 11) = -1;
  *((_DWORD *)v9 + 23) = -1;
  *((_DWORD *)v9 + 35) = -1;
  *((_DWORD *)v9 + 47) = -1;
  y = UFG::qVector3::msAxisZ.y;
  z = UFG::qVector3::msAxisZ.z;
  *((_DWORD *)v9 + 5) = LODWORD(UFG::qVector3::msAxisZ.x);
  *((float *)v9 + 6) = y;
  *((float *)v9 + 7) = z;
  v12 = UFG::qVector3::msAxisZ.y;
  v13 = UFG::qVector3::msAxisZ.z;
  *((_DWORD *)v9 + 17) = LODWORD(UFG::qVector3::msAxisZ.x);
  *((float *)v9 + 18) = v12;
  *((float *)v9 + 19) = v13;
  v14 = UFG::qVector3::msAxisZ.y;
  v15 = UFG::qVector3::msAxisZ.z;
  *((_DWORD *)v9 + 29) = LODWORD(UFG::qVector3::msAxisZ.x);
  *((float *)v9 + 30) = v14;
  *((float *)v9 + 31) = v15;
  v16 = UFG::qVector3::msAxisZ.y;
  v17 = UFG::qVector3::msAxisZ.z;
  *((_DWORD *)v9 + 41) = LODWORD(UFG::qVector3::msAxisZ.x);
  *((float *)v9 + 42) = v16;
  *((float *)v9 + 43) = v17;
  v18 = UFG::qVector3::msAxisX.y;
  v19 = UFG::qVector3::msAxisX.z;
  *((_DWORD *)v9 + 8) = LODWORD(UFG::qVector3::msAxisX.x);
  *((float *)v9 + 9) = v18;
  *((float *)v9 + 10) = v19;
  v20 = UFG::qVector3::msAxisX.y;
  v21 = UFG::qVector3::msAxisX.z;
  *((_DWORD *)v9 + 20) = LODWORD(UFG::qVector3::msAxisX.x);
  *((float *)v9 + 21) = v20;
  *((float *)v9 + 22) = v21;
  v22 = UFG::qVector3::msAxisX.y;
  v23 = UFG::qVector3::msAxisX.z;
  *((_DWORD *)v9 + 32) = LODWORD(UFG::qVector3::msAxisX.x);
  *((float *)v9 + 33) = v22;
  *((float *)v9 + 34) = v23;
  v24 = UFG::qVector3::msAxisX.y;
  v25 = UFG::qVector3::msAxisX.z;
  *((_DWORD *)v9 + 44) = LODWORD(UFG::qVector3::msAxisX.x);
  *((float *)v9 + 45) = v24;
  *((float *)v9 + 46) = v25;
  v26 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v26, &v7->UFG::qResourceData);
  *((_QWORD *)v5 + 28) = 3i64;
  *((_DWORD *)v5 + 58) = 2;
  *((_QWORD *)v5 + 30) = "DX10PolyDefaultModel";
  *((_DWORD *)v5 + 30) = mStringHash32;
  *((_DWORD *)v5 + 14) = Scaleform::Render::ShapeMeshProvider::GetLayerCount((hkDataClassDict *)&Render::gDynamicDescriptor);
  UFG::qString::~qString(&result);
  UFG::qString::FormatEx(&result, "DX10PolyDefaultModel.IndexBuffer");
  v27 = result.mStringHash32;
  if ( result.mStringHash32 == -1 )
  {
    v27 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
    result.mStringHash32 = v27;
  }
  v28 = Illusion::Factory::NewBuffer(result.mData, v27, 0xCu, 0i64, result.mData, 0i64, 0i64);
  v28->mBufferType = 1;
  v28->mElementByteSize = 2;
  v28->mNumElements = 6;
  v29 = v28->mData.mOffset;
  if ( v29 )
    v30 = (_DWORD *)((char *)&v28->mData + v29);
  else
    v30 = 0i64;
  *v30 = 0x10000;
  v30[1] = 131074;
  v30[2] = 196609;
  v31 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v31, &v28->UFG::qResourceData);
  *((_DWORD *)v5 + 22) = v27;
  UFG::qString::~qString(&result);
  v32 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v32, v2);
  v33 = Render::Poly::sModelUID;
  Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v35 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v35, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&Render::Poly::sModelHandle, 0xA2ADCD77, v33, Inventory);
  UFG::qString::~qString(&v37);
}

// File Line: 483
// RVA: 0xC810
void __fastcall Render::Poly::Poly(Render::Poly *this, float x, float y, float w, float h, float z)
{
  this->mVertices = 0i64;
  Render::Poly::Init(this, x, y, w, h, z);
}

// File Line: 489
// RVA: 0x15C30
void __fastcall Render::Poly::Init(Render::Poly *this, float x, float y, float w, float h, float z)
{
  if ( !this->mVertices )
    this->mVertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xC0u, 0x10u);
  Render::Poly::SetScreenPos(this, x, y, w, h, z);
  Render::Poly::SetUVs(this, 0.0, 0.0, 1.0, 1.0);
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  this->mVertices[1].mColour = -1;
  this->mVertices->mColour = -1;
  this->mVertices[2].mColour = -1;
  this->mVertices[3].mColour = -1;
}

// File Line: 506
// RVA: 0x161F0
void __fastcall Render::Poly::SetColour(Render::Poly *this, UFG::qColour *colour)
{
  int v4; // ecx

  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v4 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
  this->mVertices[1].mColour = v4;
  this->mVertices->mColour = v4;
  this->mVertices[2].mColour = v4;
  this->mVertices[3].mColour = v4;
}

// File Line: 535
// RVA: 0x162A0
void __fastcall Render::Poly::SetColours(
        Render::Poly *this,
        UFG::qColour *colour0,
        UFG::qColour *colour1,
        UFG::qColour *colour2,
        UFG::qColour *colour3)
{
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  this->mVertices[1].mColour = (int)(float)(colour0->r * 255.0) | (((int)(float)(colour0->g * 255.0) | (((int)(float)(colour0->b * 255.0) | ((int)(float)(colour0->a * 255.0) << 8)) << 8)) << 8);
  this->mVertices->mColour = (int)(float)(colour1->r * 255.0) | (((int)(float)(colour1->g * 255.0) | (((int)(float)(colour1->b * 255.0) | ((int)(float)(colour1->a * 255.0) << 8)) << 8)) << 8);
  this->mVertices[2].mColour = (int)(float)(colour2->r * 255.0) | (((int)(float)(colour2->g * 255.0) | (((int)(float)(colour2->b * 255.0) | ((int)(float)(colour2->a * 255.0) << 8)) << 8)) << 8);
  this->mVertices[3].mColour = (int)(float)(colour3->r * 255.0) | (((int)(float)(colour3->g * 255.0) | (((int)(float)(colour3->b * 255.0) | ((int)(float)(colour3->a * 255.0) << 8)) << 8)) << 8);
}

// File Line: 549
// RVA: 0x16440
void __fastcall Render::Poly::SetScreenPos(
        Render::Poly *this,
        UFG::qVector2 *p0,
        UFG::qVector2 *p1,
        UFG::qVector2 *p2,
        UFG::qVector2 *p3,
        float z)
{
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  this->mVertices[1].mPosition.x = p0->x;
  this->mVertices[1].mPosition.y = p0->y;
  this->mVertices[1].mPosition.z = z;
  this->mVertices->mPosition.x = p1->x;
  this->mVertices->mPosition.y = p1->y;
  this->mVertices->mPosition.z = z;
  this->mVertices[2].mPosition.x = p2->x;
  this->mVertices[2].mPosition.y = p2->y;
  this->mVertices[2].mPosition.z = z;
  *(UFG::qVector2 *)&this->mVertices[3].mPosition.x = *p3;
  this->mVertices[3].mPosition.z = z;
}

// File Line: 568
// RVA: 0x16520
void __fastcall Render::Poly::SetScreenPos(Render::Poly *this, float x, float y, float w, float h, float z)
{
  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  this->mVertices[1].mPosition.x = x;
  this->mVertices[1].mPosition.y = y;
  this->mVertices[1].mPosition.z = z;
  this->mVertices->mPosition.x = x + w;
  this->mVertices->mPosition.y = y;
  this->mVertices->mPosition.z = z;
  this->mVertices[2].mPosition.x = x + w;
  this->mVertices[2].mPosition.y = y + h;
  this->mVertices[2].mPosition.z = z;
  this->mVertices[3].mPosition.x = x;
  this->mVertices[3].mPosition.y = y + h;
  this->mVertices[3].mPosition.z = z;
}

// File Line: 582
// RVA: 0x16960
void __fastcall Render::Poly::SetUVs(Render::Poly *this, float u, float v, float u_width, float v_width)
{
  float v7; // xmm1_4
  unsigned int v8; // edx
  int v9; // r11d
  float v10; // xmm0_4
  unsigned __int16 v11; // r11
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // r10d
  unsigned __int16 v15; // r10
  unsigned int v16; // edx
  unsigned int v17; // edx
  int v18; // r9d
  unsigned __int16 v19; // r9
  unsigned int v20; // edx
  unsigned int v21; // edx
  int v22; // r8d
  unsigned __int16 v23; // r8
  unsigned int v24; // edx

  if ( !this->mVertices )
    Render::Poly::Init(this, 0.0, 0.0, 1.0, 1.0, 0.0);
  v7 = v + v_width;
  v8 = LODWORD(u) & 0x7FFFFFFF;
  v9 = HIWORD(LODWORD(u)) & 0x8000;
  v10 = u + u_width;
  if ( (LODWORD(u) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v8 >= 0x38800000 )
      v12 = v8 - 939524096;
    else
      v12 = (LODWORD(u) & 0x7FFFFF | 0x800000u) >> (113 - (v8 >> 23));
    v11 = ((((v12 >> 13) & 1) + v12 + 4095) >> 13) | v9;
  }
  else
  {
    v11 = v9 | 0x7FFF;
  }
  v13 = fabs(u + u_width);
  v14 = HIWORD(LODWORD(v10)) & 0x8000;
  if ( v13 <= 0x47FFEFFF )
  {
    if ( v13 >= 0x38800000 )
      v16 = v13 - 939524096;
    else
      v16 = (LODWORD(v10) & 0x7FFFFF | 0x800000u) >> (113 - (v13 >> 23));
    v15 = ((((v16 >> 13) & 1) + v16 + 4095) >> 13) | v14;
  }
  else
  {
    v15 = v14 | 0x7FFF;
  }
  v17 = LODWORD(v) & 0x7FFFFFFF;
  v18 = HIWORD(LODWORD(v)) & 0x8000;
  if ( (LODWORD(v) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v17 >= 0x38800000 )
      v20 = v17 - 939524096;
    else
      v20 = (LODWORD(v) & 0x7FFFFF | 0x800000u) >> (113 - (v17 >> 23));
    v19 = ((((v20 >> 13) & 1) + v20 + 4095) >> 13) | v18;
  }
  else
  {
    v19 = v18 | 0x7FFF;
  }
  v21 = fabs(v + v_width);
  v22 = HIWORD(LODWORD(v7)) & 0x8000;
  if ( v21 <= 0x47FFEFFF )
  {
    if ( v21 >= 0x38800000 )
      v24 = v21 - 939524096;
    else
      v24 = (LODWORD(v7) & 0x7FFFFF | 0x800000u) >> (113 - (v21 >> 23));
    v23 = ((((v24 >> 13) & 1) + v24 + 4095) >> 13) | v22;
  }
  else
  {
    v23 = v22 | 0x7FFF;
  }
  this->mVertices[1].mTexCoord0[0] = v11;
  this->mVertices[1].mTexCoord0[1] = v19;
  this->mVertices->mTexCoord0[0] = v15;
  this->mVertices->mTexCoord0[1] = v19;
  this->mVertices[2].mTexCoord0[0] = v15;
  this->mVertices[2].mTexCoord0[1] = v23;
  this->mVertices[3].mTexCoord0[0] = v11;
  this->mVertices[3].mTexCoord0[1] = v23;
}

// File Line: 606
// RVA: 0x15540
Render::ViewSettings *__fastcall Render::ViewSettings::GetIdentity()
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    Render::ViewSettings::ViewSettings(
      &settings,
      &UFG::qMatrix44::msIdentity,
      &UFG::qMatrix44::msIdentity,
      -1,
      0.0,
      0.0);
  }
  return &settings;
}

// File Line: 618
// RVA: 0x15D30
void Render::View::InitShared(void)
{
  unsigned int v0; // eax
  int v1; // eax
  Illusion::Material *v2; // rbx
  int v3; // edi
  int v4; // eax
  Illusion::Material *v5; // rbx
  int v6; // eax
  Illusion::Material *v7; // rbx
  unsigned int v8; // eax
  Illusion::Material *v9; // rbx
  int v10; // eax
  Illusion::Material *v11; // rbx
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax
  Render::vDynamic *VertsCircle; // rax
  float *p_x; // rcx

  Render::View::mScreenOffset = 0i64;
  v0 = UFG::qStringHash32("ViewPlat.Primitive", 0xFFFFFFFF);
  `anonymous namespace::gSimpleMaterial = Illusion::Factory::NewMaterial(
                                             "ViewPlat.Primitive",
                                             v0,
                                             5u,
                                             0i64,
                                             0i64,
                                             0i64);
  v1 = UFG::qStringHash32("SIMPLE", 0xFFFFFFFF);
  v2 = `anonymous namespace::gSimpleMaterial;
  v3 = v1;
  LOWORD(`anonymous namespace::gSimpleMaterial[1].mNode.mChild[0]) = 0;
  HIDWORD(v2[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v2[1].mTypeUID = -1957338719;
  LODWORD(v2[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v3;
  LODWORD(v2[1].mNode.mParent) = v4;
  v5 = `anonymous namespace::gSimpleMaterial;
  *(_WORD *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[12] = 0;
  *(_DWORD *)&v5[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v6 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v5[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v5[1].mStateBlockMask.mFlags[0]) = -1324127765;
  *(_DWORD *)&v5[1].mDebugName[4] = v6;
  v7 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[1].mMaterialUser.mOffset) = 0;
  *(&v7[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v8 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v7[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 315097330;
  v7[2].mNode.mUID = -1551679522;
  v7[1].mNumParams = v8;
  v9 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[2].mTypeUID) = 0;
  HIDWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v9[2].UFG::qResourceData + 22) = 1002903008;
  *(_DWORD *)&v9[2].mDebugName[28] = 1660426324;
  LODWORD(v9[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v10;
  v11 = `anonymous namespace::gSimpleMaterial;
  LOWORD(`anonymous namespace::gSimpleMaterial[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v11[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  LODWORD(v11[3].mNode.mChild[1]) = 1292158962;
  LODWORD(v11[2].mStateBlockMask.mFlags[0]) = v12;
  LODWORD(v11[3].mNode.mChild[0]) = 0;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, `anonymous namespace::gSimpleMaterial);
  VertsCircle = `anonymous namespace::GetVertsCircle(64, &UFG::qColour::White);
  if ( VertsCircle )
  {
    p_x = &VertsCircle[1].mPosition.x;
    *(_QWORD *)&VertsCircle->mPosition.x = 0i64;
    VertsCircle->mPosition.z = 0.0;
    if ( &VertsCircle[1] < &VertsCircle[66] )
    {
      do
      {
        *p_x = 0.0;
        p_x += 12;
      }
      while ( p_x < &VertsCircle[66].mPosition.x );
    }
  }
}

// File Line: 664
// RVA: 0xC850
void __fastcall Render::View::View(
        Render::View *this,
        Render::ViewSettings *settings,
        Illusion::SubmitContext *submit_context)
{
  Render::ViewSettings *mSettings; // rcx
  UFG::qMatrix44 *p_mProjection; // r8
  UFG::qMatrix44 *v6; // rax
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  Render::ViewSettings *v10; // rdx
  float z; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  int v18; // xmm0_4
  float w; // xmm0_4
  float v20; // xmm0_4
  int v21; // xmm0_4
  float v22; // xmm0_4
  int v23; // xmm0_4
  float y; // xmm5_4
  __int128 x_low; // xmm3
  __m128 v26; // xmm2
  float v27; // xmm4_4
  float v28; // xmm0_4
  __m128 y_low; // xmm6
  float x; // xmm4_4
  __m128 v31; // xmm2
  float v32; // xmm5_4
  float v33; // xmm0_4
  __m128 v34; // xmm6
  float v35; // xmm4_4
  __m128 v36; // xmm2
  float v37; // xmm5_4
  float v38; // xmm0_4
  __int128 v39; // xmm4
  float v40; // xmm5_4
  __m128 v41; // xmm2
  float v42; // xmm0_4
  float v43; // xmm5_4
  __m128 v44; // xmm6
  __m128 v45; // xmm2
  float v46; // xmm0_4
  __m128 v47; // xmm5
  __m128 v48; // xmm2
  float v49; // xmm0_4
  float v50; // xmm7_4
  UFG::qMatrix44 result; // [rsp+20h] [rbp-68h] BYREF

  this->mSettings = settings;
  this->mSubmitContext = submit_context;
  Render::ViewMetrics::Reset(&this->mViewMetrics);
  mSettings = this->mSettings;
  p_mProjection = &this->mSettings->mProjection;
  this->mLastBeginFrameCounter = 0;
  v6 = UFG::qMatrix44::operator*(&mSettings->mWorldView, &result, p_mProjection);
  v7 = v6->v1;
  v8 = v6->v2;
  v9 = v6->v3;
  this->mWorldViewProjection.v0 = v6->v0;
  this->mWorldViewProjection.v1 = v7;
  this->mWorldViewProjection.v2 = v8;
  this->mWorldViewProjection.v3 = v9;
  v10 = this->mSettings;
  this->mExtractedNearPlane = this->mSettings->mProjection.v3.z / this->mSettings->mProjection.v2.z;
  this->mExtractedFarPlane = (float)(v10->mProjection.v3.z - v10->mProjection.v3.w)
                           / (float)(v10->mProjection.v2.z - v10->mProjection.v2.w);
  UFG::qInverseAffine(&this->mViewWorld, &v10->mWorldView);
  v8.x = this->mWorldViewProjection.v3.z;
  v7.x = this->mWorldViewProjection.v2.z;
  z = this->mWorldViewProjection.v1.z;
  this->mFrustumPlanes[0].x = this->mWorldViewProjection.v0.z;
  this->mFrustumPlanes[0].y = z;
  this->mFrustumPlanes[0].z = v7.x;
  this->mFrustumPlanes[0].w = v8.x;
  v8.x = this->mWorldViewProjection.v2.w + this->mWorldViewProjection.v2.x;
  v9.x = this->mWorldViewProjection.v3.w + this->mWorldViewProjection.v3.x;
  v12 = this->mWorldViewProjection.v0.w + this->mWorldViewProjection.v0.x;
  this->mFrustumPlanes[1].y = this->mWorldViewProjection.v1.w + this->mWorldViewProjection.v1.x;
  this->mFrustumPlanes[1].z = v8.x;
  this->mFrustumPlanes[1].x = v12;
  this->mFrustumPlanes[1].w = v9.x;
  v8.x = this->mWorldViewProjection.v2.w - this->mWorldViewProjection.v2.x;
  v9.x = this->mWorldViewProjection.v3.w - this->mWorldViewProjection.v3.x;
  v13 = this->mWorldViewProjection.v0.w - this->mWorldViewProjection.v0.x;
  this->mFrustumPlanes[2].y = this->mWorldViewProjection.v1.w - this->mWorldViewProjection.v1.x;
  this->mFrustumPlanes[2].z = v8.x;
  this->mFrustumPlanes[2].x = v13;
  this->mFrustumPlanes[2].w = v9.x;
  v8.x = this->mWorldViewProjection.v2.w + this->mWorldViewProjection.v2.y;
  v14 = this->mWorldViewProjection.v3.w + this->mWorldViewProjection.v3.y;
  v15 = this->mWorldViewProjection.v0.w + this->mWorldViewProjection.v0.y;
  this->mFrustumPlanes[3].y = this->mWorldViewProjection.v1.w + this->mWorldViewProjection.v1.y;
  this->mFrustumPlanes[3].z = v8.x;
  this->mFrustumPlanes[3].x = v15;
  this->mFrustumPlanes[3].w = v14;
  v9.x = this->mWorldViewProjection.v3.w - this->mWorldViewProjection.v3.y;
  v8.x = this->mWorldViewProjection.v2.w - this->mWorldViewProjection.v2.y;
  v16 = this->mWorldViewProjection.v0.w - this->mWorldViewProjection.v0.y;
  this->mFrustumPlanes[4].y = this->mWorldViewProjection.v1.w - this->mWorldViewProjection.v1.y;
  this->mFrustumPlanes[4].z = v8.x;
  this->mFrustumPlanes[4].x = v16;
  this->mFrustumPlanes[4].w = v9.x;
  v8.x = this->mWorldViewProjection.v2.w - this->mWorldViewProjection.v2.z;
  v7.x = this->mWorldViewProjection.v1.w - this->mWorldViewProjection.v1.z;
  v17 = this->mWorldViewProjection.v3.w - this->mWorldViewProjection.v3.z;
  this->mFrustumPlanes[5].x = this->mWorldViewProjection.v0.w - this->mWorldViewProjection.v0.z;
  this->mFrustumPlanes[5].y = v7.x;
  this->mFrustumPlanes[5].z = v8.x;
  this->mFrustumPlanes[5].w = v17;
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[0].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(this->mFrustumPlanes[0].z) ^ _xmm[0];
  v18 = LODWORD(this->mFrustumPlanes[0].w) ^ _xmm[0];
  LODWORD(this->mFrustumPlanes[0].x) ^= _xmm[0];
  this->mFrustumPlanes[0].y = v8.x;
  this->mFrustumPlanes[0].z = v7.x;
  LODWORD(this->mFrustumPlanes[0].w) = v18;
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[1].y) ^ _xmm[0];
  v7.x = this->mFrustumPlanes[1].z;
  w = this->mFrustumPlanes[1].w;
  LODWORD(this->mFrustumPlanes[1].x) ^= _xmm[0];
  this->mFrustumPlanes[1].y = v8.x;
  LODWORD(this->mFrustumPlanes[1].z) = LODWORD(v7.x) ^ _xmm[0];
  LODWORD(this->mFrustumPlanes[1].w) = LODWORD(w) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[2].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(this->mFrustumPlanes[2].z) ^ _xmm[0];
  v20 = this->mFrustumPlanes[2].w;
  LODWORD(this->mFrustumPlanes[2].x) ^= _xmm[0];
  this->mFrustumPlanes[2].y = v8.x;
  this->mFrustumPlanes[2].z = v7.x;
  LODWORD(this->mFrustumPlanes[2].w) = LODWORD(v20) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[3].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(this->mFrustumPlanes[3].z) ^ _xmm[0];
  v21 = LODWORD(this->mFrustumPlanes[3].w) ^ _xmm[0];
  LODWORD(this->mFrustumPlanes[3].x) ^= _xmm[0];
  this->mFrustumPlanes[3].y = v8.x;
  this->mFrustumPlanes[3].z = v7.x;
  LODWORD(this->mFrustumPlanes[3].w) = v21;
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[4].y) ^ _xmm[0];
  v7.x = this->mFrustumPlanes[4].z;
  v22 = this->mFrustumPlanes[4].w;
  LODWORD(this->mFrustumPlanes[4].x) ^= _xmm[0];
  this->mFrustumPlanes[4].y = v8.x;
  LODWORD(this->mFrustumPlanes[4].z) = LODWORD(v7.x) ^ _xmm[0];
  LODWORD(this->mFrustumPlanes[4].w) = LODWORD(v22) ^ _xmm[0];
  LODWORD(v8.x) = LODWORD(this->mFrustumPlanes[5].y) ^ _xmm[0];
  LODWORD(v7.x) = LODWORD(this->mFrustumPlanes[5].z) ^ _xmm[0];
  v23 = LODWORD(this->mFrustumPlanes[5].w) ^ _xmm[0];
  LODWORD(this->mFrustumPlanes[5].x) ^= _xmm[0];
  this->mFrustumPlanes[5].y = v8.x;
  this->mFrustumPlanes[5].z = v7.x;
  LODWORD(this->mFrustumPlanes[5].w) = v23;
  y = this->mFrustumPlanes[0].y;
  x_low = LODWORD(this->mFrustumPlanes[0].x);
  v26 = (__m128)x_low;
  v27 = this->mFrustumPlanes[0].z;
  v26.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(y * y)) + (float)(v27 * v27);
  v28 = _mm_sqrt_ps(v26).m128_f32[0];
  v7.x = (float)(1.0 / v28) * this->mFrustumPlanes[0].w;
  this->mFrustumPlanes[0].x = *(float *)&x_low * (float)(1.0 / v28);
  this->mFrustumPlanes[0].y = y * (float)(1.0 / v28);
  this->mFrustumPlanes[0].z = v27 * (float)(1.0 / v28);
  this->mFrustumPlanes[0].w = v7.x;
  y_low = (__m128)LODWORD(this->mFrustumPlanes[1].y);
  x = this->mFrustumPlanes[1].x;
  v31 = y_low;
  v32 = this->mFrustumPlanes[1].z;
  v31.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(v32 * v32);
  v33 = _mm_sqrt_ps(v31).m128_f32[0];
  *(float *)&x_low = (float)(1.0 / v33) * this->mFrustumPlanes[1].w;
  this->mFrustumPlanes[1].x = x * (float)(1.0 / v33);
  this->mFrustumPlanes[1].y = y_low.m128_f32[0] * (float)(1.0 / v33);
  this->mFrustumPlanes[1].z = v32 * (float)(1.0 / v33);
  LODWORD(this->mFrustumPlanes[1].w) = x_low;
  v34 = (__m128)LODWORD(this->mFrustumPlanes[2].y);
  v35 = this->mFrustumPlanes[2].x;
  v36 = v34;
  v37 = this->mFrustumPlanes[2].z;
  v36.m128_f32[0] = (float)((float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(v35 * v35)) + (float)(v37 * v37);
  v38 = _mm_sqrt_ps(v36).m128_f32[0];
  *(float *)&x_low = (float)(1.0 / v38) * this->mFrustumPlanes[2].w;
  this->mFrustumPlanes[2].x = v35 * (float)(1.0 / v38);
  this->mFrustumPlanes[2].y = v34.m128_f32[0] * (float)(1.0 / v38);
  this->mFrustumPlanes[2].z = v37 * (float)(1.0 / v38);
  LODWORD(this->mFrustumPlanes[2].w) = x_low;
  v34.m128_i32[0] = LODWORD(this->mFrustumPlanes[3].y);
  v39 = LODWORD(this->mFrustumPlanes[3].x);
  v40 = this->mFrustumPlanes[3].z;
  v41 = (__m128)v39;
  v41.m128_f32[0] = (float)((float)(*(float *)&v39 * *(float *)&v39) + (float)(v34.m128_f32[0] * v34.m128_f32[0]))
                  + (float)(v40 * v40);
  v42 = _mm_sqrt_ps(v41).m128_f32[0];
  *(float *)&x_low = (float)(1.0 / v42) * this->mFrustumPlanes[3].w;
  this->mFrustumPlanes[3].x = *(float *)&v39 * (float)(1.0 / v42);
  this->mFrustumPlanes[3].y = v34.m128_f32[0] * (float)(1.0 / v42);
  this->mFrustumPlanes[3].z = v40 * (float)(1.0 / v42);
  LODWORD(this->mFrustumPlanes[3].w) = x_low;
  *(float *)&x_low = this->mFrustumPlanes[4].x;
  v43 = this->mFrustumPlanes[4].z;
  v44 = (__m128)LODWORD(this->mFrustumPlanes[4].y);
  v45 = v44;
  v45.m128_f32[0] = (float)((float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(*(float *)&x_low * *(float *)&x_low))
                  + (float)(v43 * v43);
  v46 = _mm_sqrt_ps(v45).m128_f32[0];
  *(float *)&v39 = (float)(1.0 / v46) * this->mFrustumPlanes[4].w;
  this->mFrustumPlanes[4].x = (float)(1.0 / v46) * *(float *)&x_low;
  this->mFrustumPlanes[4].y = v44.m128_f32[0] * (float)(1.0 / v46);
  this->mFrustumPlanes[4].z = v43 * (float)(1.0 / v46);
  LODWORD(this->mFrustumPlanes[4].w) = v39;
  v47 = (__m128)LODWORD(this->mFrustumPlanes[5].y);
  *(float *)&x_low = this->mFrustumPlanes[5].x;
  v48 = v47;
  *(float *)&v39 = this->mFrustumPlanes[5].z;
  v48.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(*(float *)&x_low * *(float *)&x_low))
                  + (float)(*(float *)&v39 * *(float *)&v39);
  v49 = _mm_sqrt_ps(v48).m128_f32[0];
  v50 = (float)(1.0 / v49) * this->mFrustumPlanes[5].w;
  this->mFrustumPlanes[5].x = (float)(1.0 / v49) * *(float *)&x_low;
  this->mFrustumPlanes[5].y = v47.m128_f32[0] * (float)(1.0 / v49);
  this->mFrustumPlanes[5].z = *(float *)&v39 * (float)(1.0 / v49);
  this->mFrustumPlanes[5].w = v50;
  Render::ViewMetrics::Reset(&this->mViewMetrics);
}

// File Line: 696
// RVA: 0xD2D0
void __fastcall Render::View::BeginTarget(
        Render::View *this,
        Illusion::Target *target,
        const char *description,
        unsigned int dest_slice_face,
        unsigned int dest_mip_level,
        Illusion::ViewportScissorState *vp_scissor,
        bool clear_on_resolve,
        bool ignore_resolve_depth,
        bool ps4_decompress_depth,
        bool d3d_disable_depth_copy)
{
  Illusion::SubmitContext *mSubmitContext; // rbx
  int v15; // esi
  Illusion::ViewportScissorState *v16; // rbx
  Illusion::SubmitContext *v17; // rax
  int v18; // esi
  char *v19; // rax
  char *v20; // r9
  Illusion::SubmitContext *v21; // rax
  UFG::qMatrix44 *p_mProjection; // rbx
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  Render::cbViewTransformState v26; // [rsp+30h] [rbp-50h] BYREF

  mSubmitContext = this->mSubmitContext;
  UFG::qMemSet(mSubmitContext->mStateValues.mParamValues, 0, 0x400u);
  v15 = 0;
  mSubmitContext->mStateValues.mSetValueMask.mFlags[1] = 0i64;
  mSubmitContext->mStateValues.mSetValueMask.mFlags[0] = 0i64;
  v16 = vp_scissor;
  if ( !vp_scissor )
  {
    v16 = (Illusion::ViewportScissorState *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x30u, 0x10u);
    Illusion::SetFullscreenViewportScissor(target, v16, dest_mip_level);
  }
  v17 = this->mSubmitContext;
  v17->mStateValues.mSetValueMask.mFlags[0] |= 0x1000ui64;
  v17->mStateValues.mParamValues[12] = v16;
  LOBYTE(v15) = clear_on_resolve;
  v18 = (d3d_disable_depth_copy ? 8 : 0) | (ps4_decompress_depth ? 4 : 0) | (ignore_resolve_depth ? 2 : 0) | v15;
  v19 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
  v20 = v19;
  if ( v19 )
  {
    *(_QWORD *)v19 = target;
    *((_DWORD *)v19 + 2) = dest_slice_face;
    *((_DWORD *)v19 + 3) = dest_mip_level;
    *((_DWORD *)v19 + 4) = v18;
    *((_QWORD *)v19 + 3) = description;
  }
  v21 = this->mSubmitContext;
  v21->mStateValues.mSetValueMask.mFlags[0] |= 0x800ui64;
  v21->mStateValues.mParamValues[11] = v20;
  ((void (__fastcall *)(Illusion::SubmitContext *, __int64))this->mSubmitContext->vfptr->AddRenderCommand)(
    this->mSubmitContext,
    14i64);
  ((void (__fastcall *)(Illusion::SubmitContext *, __int64, _QWORD, Illusion::ViewportScissorState *, __int64))this->mSubmitContext->vfptr->AddRenderCommand)(
    this->mSubmitContext,
    9i64,
    0i64,
    v16,
    -2i64);
  Render::ViewMetrics::BeginTarget(&this->mViewMetrics);
  p_mProjection = &this->mSettings->mProjection;
  v26.mPrev = &v26;
  v26.mNext = &v26;
  v26.mCallback = 0i64;
  v26.mStateParamIndex = Render::cbViewTransformState::sStateParamIndex;
  *(_WORD *)&v26.mFlags = 1;
  if ( (_WORD)Render::cbViewTransformState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbViewTransform");
    Render::cbViewTransformState::sStateParamIndex = Param;
    v26.mStateParamIndex = Param;
  }
  v26.mWorldViewProjection = &this->mWorldViewProjection;
  v26.mViewWorld = &this->mViewWorld;
  v26.mProjection = p_mProjection;
  v26.mScreenOffset = &Render::View::mScreenOffset;
  v26.mCached_Remote.m_Stream = 0i64;
  Render::cbViewTransformState::SetStateBlock(&v26, &this->mSubmitContext->mStateValues);
  mPrev = v26.mPrev;
  mNext = v26.mNext;
  v26.mPrev->mNext = v26.mNext;
  mNext->mPrev = mPrev;
}

// File Line: 768
// RVA: 0x15510
void __fastcall Render::View::EndTarget(Render::View *this)
{
  Render::ViewMetrics::EndTarget(&this->mViewMetrics);
  this->mSubmitContext->vfptr->AddRenderCommand(
    this->mSubmitContext,
    15,
    0,
    this->mSubmitContext->mStateValues.mParamValues[11]);
}

// File Line: 778
// RVA: 0xD1F0
void __fastcall Render::View::AddMetric_NumCompositeProcessed(Render::View *this, int count)
{
  this->mViewMetrics.mNumCompositeProcessed += count;
}

// File Line: 783
// RVA: 0xD1C0
void __fastcall Render::View::AddMetric_DrawComposite(Render::View *this, float time)
{
  this->mViewMetrics.mDrawComposite = time + this->mViewMetrics.mDrawComposite;
}

// File Line: 788
// RVA: 0xD1E0
void __fastcall Render::View::AddMetric_DrawScenery(Render::View *this, float time)
{
  this->mViewMetrics.mDrawScenery = time + this->mViewMetrics.mDrawScenery;
}

// File Line: 793
// RVA: 0xD220
void __fastcall Render::View::AddMetric_NumSkinnedModelsRendered(Render::View *this, int count)
{
  this->mViewMetrics.mNumSkinnedModelsRendered += count;
}

// File Line: 798
// RVA: 0xD210
void __fastcall Render::View::AddMetric_NumRigidModelsRendered(Render::View *this, int count)
{
  this->mViewMetrics.mNumRigidModelsRendered += count;
}

// File Line: 813
// RVA: 0xD200
void __fastcall Render::View::AddMetric_NumParticles(Render::View *this, int count)
{
  this->mViewMetrics.mNumParticles += count;
}

// File Line: 818
// RVA: 0x16020
void __fastcall Render::View::Metric_BeginTarget(Render::View *this)
{
  Render::ViewMetrics::BeginTarget(&this->mViewMetrics);
}

// File Line: 823
// RVA: 0x16030
void __fastcall Render::View::Metric_EndTarget(Render::View *this)
{
  Render::ViewMetrics::EndTarget(&this->mViewMetrics);
}

// File Line: 829
// RVA: 0x155C0
Illusion::StateValues *__fastcall Render::View::GetStateValues(Render::View *this)
{
  return &this->mSubmitContext->mStateValues;
}

// File Line: 835
// RVA: 0x155B0
Illusion::StateArgs *__fastcall Render::View::GetStateArgs(Render::View *this)
{
  return &this->mSubmitContext->mStateArgs;
}

// File Line: 840
// RVA: 0xD4D0
void __fastcall Render::View::Clear(
        Render::View *this,
        UFG::qColour *colour,
        unsigned int flags,
        float depth,
        unsigned int stencil)
{
  void *v8; // rbp
  char *v9; // rax

  v8 = this->mSubmitContext->mStateValues.mParamValues[11];
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x28u, 8u);
  if ( v9 )
  {
    *(_QWORD *)v9 = v8;
    *((_DWORD *)v9 + 2) = LODWORD(colour->r);
    *((_DWORD *)v9 + 3) = LODWORD(colour->g);
    *((_DWORD *)v9 + 4) = LODWORD(colour->b);
    *((_DWORD *)v9 + 5) = LODWORD(colour->a);
    *((_DWORD *)v9 + 6) = flags;
    *((float *)v9 + 7) = depth;
    *((_DWORD *)v9 + 8) = stencil;
  }
  ((void (__fastcall *)(Illusion::SubmitContext *, __int64))this->mSubmitContext->vfptr->AddRenderCommand)(
    this->mSubmitContext,
    16i64);
}

// File Line: 850
// RVA: 0x15F80
_BOOL8 __fastcall Render::View::IsInView(
        Render::View *this,
        Illusion::ModelHandle *model_handle,
        UFG::qMatrix44 *local_world,
        float *distance_from_near_plane)
{
  UFG::ModelData *mData; // rax
  float v6; // xmm1_4
  float x; // xmm2_4
  float v9; // xmm3_4
  int mLODBias; // xmm1_4
  UFG::qVector3 max; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 min; // [rsp+30h] [rbp-18h] BYREF

  mData = (UFG::ModelData *)model_handle->mData;
  v6 = *(float *)&mData->mModels.mData.mFlags;
  x = mData->mAABBMin.x;
  LODWORD(min.x) = mData->mModels.mData.mNumItems;
  min.y = v6;
  min.z = x;
  v9 = mData->mAABBMax.x;
  mLODBias = mData->mLODBias;
  max.x = mData->mAABBMin.z;
  LODWORD(max.y) = mLODBias;
  max.z = v9;
  TransformAABB(local_world, &min, &max);
  return (unsigned int)IntersectAABBFrustum(this->mFrustumPlanes, &min, &max, distance_from_near_plane) != 2;
}

// File Line: 866
// RVA: 0x15F60
_BOOL8 __fastcall Render::View::IsInView(
        Render::View *this,
        UFG::qVector3 *vmin,
        UFG::qVector3 *vmax,
        float *distance_from_near_plane)
{
  return (unsigned int)IntersectAABBFrustum(this->mFrustumPlanes, vmin, vmax, distance_from_near_plane) != 2;
}

// File Line: 875
// RVA: 0x155E0
__int64 __fastcall Render::View::GetTargetWidth(Render::View *this)
{
  return **(unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
}

// File Line: 884
// RVA: 0x155D0
__int64 __fastcall Render::View::GetTargetHeight(Render::View *this)
{
  return *(unsigned int *)(*(_QWORD *)this->mSubmitContext->mStateValues.mParamValues[11] + 4i64);
}

// File Line: 917
// RVA: 0xEB70
void __fastcall Render::View::Draw(
        Render::View *this,
        Illusion::Primitive *prim,
        Illusion::Material *material,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *p_mStateArgs; // rbx
  unsigned __int16 v9; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v10; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v11; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v12; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v13; // rax
  UFG::qMatrix44 *p_mWorldViewProjection; // r15
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v18; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rax
  Render::cbLocalTransformState arg; // [rsp+10h] [rbp-21h] BYREF
  Render::cbLocalProjectionState v26; // [rsp+38h] [rbp+7h] BYREF

  p_mStateArgs = &this->mSubmitContext->mStateArgs;
  if ( local_world )
  {
    p_mWorldViewProjection = &this->mWorldViewProjection;
    Render::cbLocalTransformState::cbLocalTransformState(
      &arg,
      &this->mSettings->mWorldView,
      &this->mWorldViewProjection,
      local_world);
    v26.mPrev = &v26;
    v26.mNext = &v26;
    v26.mCallback = 0i64;
    v26.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
    *(_WORD *)&v26.mFlags = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = Param;
      v26.mStateParamIndex = Param;
    }
    v26.mCached_Remote.m_Stream = 0i64;
    v26.mWorldViewProjection = p_mWorldViewProjection;
    v26.mLocalWorld = local_world;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, &v26);
    Illusion::SubmitContext::Draw(this->mSubmitContext, prim, material);
    mPrev = v26.mPrev;
    mNext = v26.mNext;
    v26.mPrev->mNext = v26.mNext;
    mNext->mPrev = mPrev;
    v26.mPrev = &v26;
    v26.mNext = &v26;
    v26.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v26.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v26.mStateParamIndex] )
    {
      v18 = &p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v26.mStateParamIndex >> 6];
      *v18 &= ~(1i64 << (v26.mStateParamIndex & 0x3F));
    }
    v19 = arg.mPrev;
    v20 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v20->mPrev = v19;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
      p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v21 = v26.mPrev;
    v22 = v26.mNext;
    v26.mPrev->mNext = v26.mNext;
    v22->mPrev = v21;
    v23 = arg.mPrev;
    v24 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v24->mPrev = v23;
  }
  else
  {
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == 0xFFFF )
    {
      v9 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
      Render::cbScreenProjectionState::sStateParamIndex = v9;
      arg.mStateParamIndex = v9;
    }
    Illusion::StateArgs::Set<Render::cbScreenProjectionState>(p_mStateArgs, (Render::cbScreenProjectionState *)&arg);
    Illusion::SubmitContext::Draw(this->mSubmitContext, prim, material);
    v10 = arg.mPrev;
    v11 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v11->mPrev = v10;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
      p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v12 = arg.mPrev;
    v13 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v13->mPrev = v12;
    arg.mPrev = &arg;
  }
}

// File Line: 953
// RVA: 0xE880
void __fastcall Render::View::Draw(
        Render::View *this,
        Render::Poly *poly,
        Illusion::Material *material,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *p_mStateArgs; // r12
  unsigned int v9; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v11; // rax
  unsigned __int16 Param; // ax
  UFG::qResourceData *mData; // rcx
  unsigned int v14; // eax
  __int64 v15; // rdi
  __int64 v16; // r14
  UFG::qBaseNodeRB *v17; // rax
  char *v18; // rax
  char *v19; // rcx
  __int64 v20; // rax
  Illusion::Mesh *v21; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v24; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rax
  Illusion::Primitive *v27; // rax
  Illusion::Primitive *v28; // rdi
  __int128 debug_name_override; // [rsp+28h] [rbp-19h]
  bool dupe_vertex_buffer[16]; // [rsp+38h] [rbp-9h] BYREF
  UFG::BitFlags128 v31; // [rsp+48h] [rbp+7h] BYREF
  Render::cbScreenProjectionState arg; // [rsp+58h] [rbp+17h] BYREF

  p_mStateArgs = &this->mSubmitContext->mStateArgs;
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&vertex_decl_handle);
    atexit(Render::View::Draw_::_2_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle.mData )
  {
    v9 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v11 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v11, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle, 0x3E5FDA3Eu, v9, Inventory);
    Render::Poly::DefaultModelInit();
  }
  if ( poly->mVertices )
  {
    v27 = Illusion::Primitive::Create("Poly");
    v28 = v27;
    if ( v27
      && Illusion::Primitive::SetBuffers(
           v27,
           TRIANGLESTRIP,
           poly->mVertices,
           4,
           (Illusion::VertexDecl *)vertex_decl_handle.mData,
           0i64,
           0,
           1) )
    {
      Render::View::Draw(this, v28, material, local_world);
    }
  }
  else if ( local_world )
  {
    Render::View::Draw(this, &Render::Poly::sModelHandle, local_world, 0, material);
  }
  else
  {
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 1;
    if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
      Render::cbScreenProjectionState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    Illusion::StateArgs::Set<Render::cbScreenProjectionState>(p_mStateArgs, &arg);
    debug_name_override = 0ui64;
    mData = Render::Poly::sModelHandle.mData;
    v14 = (unsigned int)Render::Poly::sModelHandle.mData[2].mNode.mChild[1];
    if ( v14 )
    {
      v15 = 0i64;
      v16 = v14;
      while ( 1 )
      {
        v17 = mData[2].mNode.mChild[0];
        if ( v17 )
          v18 = (char *)&v17[5].mChild[2] + (_QWORD)mData;
        else
          v18 = 0i64;
        v19 = &v18[v15];
        v20 = *(_QWORD *)&v18[v15];
        v21 = (Illusion::Mesh *)&v19[v20];
        if ( !v20 )
          v21 = 0i64;
        *(_OWORD *)dupe_vertex_buffer = debug_name_override;
        debug_name_override = (__int128)*Illusion::SubmitContext::Draw(
                                           this->mSubmitContext,
                                           &v31,
                                           v21,
                                           material,
                                           (UFG::BitFlags128 *)dupe_vertex_buffer,
                                           v21);
        ++this->mViewMetrics.mNumMeshsRendered;
        v15 += 8i64;
        if ( !--v16 )
          break;
        mData = Render::Poly::sModelHandle.mData;
      }
    }
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
    {
      v24 = &p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
      *v24 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    }
    v25 = arg.mPrev;
    v26 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v26->mPrev = v25;
    arg.mPrev = &arg;
    arg.mNext = &arg;
  }
}

// File Line: 1021
// RVA: 0xDDD0
UFG::BitFlags128 *__fastcall Render::View::Draw(
        Render::View *this,
        UFG::BitFlags128 *result,
        Illusion::Mesh *mesh,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *p_mStateArgs; // r14
  unsigned __int16 Param; // ax
  Render::ViewSettings *mSettings; // r13
  unsigned __int16 v11; // ax
  UFG::qMatrix44 *mWorldViewProjection; // rcx
  UFG::qMatrix44 *mLocalWorld; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  Render::cbLocalProjectionState v19; // [rsp+30h] [rbp-79h] BYREF
  unsigned __int16 v20; // [rsp+68h] [rbp-41h]
  __int16 v21; // [rsp+6Ah] [rbp-3Fh]
  Render::ViewSettings *v22; // [rsp+70h] [rbp-39h]
  UFG::qMatrix44 *v23; // [rsp+78h] [rbp-31h]
  __int64 v24; // [rsp+80h] [rbp-29h]
  Render::cbLocalTransformState arg; // [rsp+88h] [rbp-21h] BYREF
  __int64 v26; // [rsp+B0h] [rbp+7h]
  UFG::BitFlags128 v27; // [rsp+B8h] [rbp+Fh] BYREF
  UFG::BitFlags128 v28; // [rsp+C8h] [rbp+1Fh] BYREF
  Illusion::Material *v29; // [rsp+118h] [rbp+6Fh]
  UFG::BitFlags128 *v30; // [rsp+120h] [rbp+77h]

  v26 = -2i64;
  if ( mesh && local_world && v29 )
  {
    p_mStateArgs = &this->mSubmitContext->mStateArgs;
    v19.mPrev = &v19;
    v19.mNext = &v19;
    v19.mCallback = 0i64;
    LOWORD(v19.mPrev) = Render::cbLocalProjectionState::sStateParamIndex;
    WORD1(v19.mPrev) = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = Param;
      LOWORD(v19.mPrev) = Param;
    }
    *(_QWORD *)&v19.mStateParamIndex = 0i64;
    v19.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mWorldViewProjection;
    v19.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))local_world;
    Render::cbLocalTransformState::cbLocalTransformState(
      &arg,
      &this->mSettings->mWorldView,
      &this->mWorldViewProjection,
      local_world);
    mSettings = this->mSettings;
    v19.mWorldViewProjection = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mLocalWorld = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mCached_Remote.m_Stream = 0i64;
    v20 = Render::cbLocalTransformInverseState::sStateParamIndex;
    v21 = 1;
    if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
    {
      v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
      Render::cbLocalTransformInverseState::sStateParamIndex = v11;
      v20 = v11;
    }
    v24 = 0i64;
    v22 = mSettings;
    v23 = local_world;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, &v19);
    Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
      p_mStateArgs,
      (Render::cbLocalTransformInverseState *)&v19.mWorldViewProjection);
    v27 = *v30;
    Illusion::SubmitContext::Draw(this->mSubmitContext, &v28, mesh, v29, &v27, mesh);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(
      p_mStateArgs,
      (Render::cbLocalTransformState *)&v19);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(p_mStateArgs, &arg);
    Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(
      p_mStateArgs,
      (Render::cbLocalTransformState *)&v19.mWorldViewProjection);
    mWorldViewProjection = v19.mWorldViewProjection;
    mLocalWorld = v19.mLocalWorld;
    *(_QWORD *)&v19.mWorldViewProjection->v0.z = v19.mLocalWorld;
    *(_QWORD *)&mLocalWorld->v0.x = mWorldViewProjection;
    v19.mWorldViewProjection = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    v19.mLocalWorld = (UFG::qMatrix44 *)&v19.mWorldViewProjection;
    mPrev = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = mPrev;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    v16 = v19.mPrev;
    v17 = v19.mNext;
    v19.mPrev->mNext = v19.mNext;
    v17->mPrev = v16;
    v19.mPrev = &v19;
    v19.mNext = &v19;
    ++this->mViewMetrics.mNumMeshsRendered;
    result->mFlags[0] = v30->mFlags[0];
    result->mFlags[1] = v30->mFlags[1];
  }
  else
  {
    *result = *v30;
  }
  return result;
}

// File Line: 1065
// RVA: 0xE420
__int64 __fastcall Render::View::Draw(
        Render::View *this,
        Illusion::ModelHandle *model_handle,
        UFG::qMatrix44 *local_world,
        bool do_clip,
        Illusion::Material *force_mat)
{
  UFG::qResourceData *mData; // rbx
  unsigned int v8; // xmm2_4
  unsigned int mParent_high; // xmm1_4
  unsigned int mUID; // xmm3_4
  int v11; // xmm1_4
  Illusion::StateArgs *p_mStateArgs; // rdi
  unsigned __int16 Param; // ax
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 v15; // ax
  unsigned int v16; // r13d
  __int64 v17; // r14
  __int64 v18; // r15
  Illusion::Material *v19; // r12
  UFG::qBaseNodeRB *v20; // rax
  char *v21; // rcx
  char *v22; // rax
  __int64 v23; // rcx
  Illusion::Mesh *v24; // r8
  Illusion::Material *v25; // r9
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v34; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v35; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v36; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v37; // rcx
  UFG::BitFlags128 v39; // [rsp+30h] [rbp-A9h] BYREF
  Render::cbLocalProjectionState v40; // [rsp+40h] [rbp-99h] BYREF
  Render::cbLocalTransformInverseState arg; // [rsp+78h] [rbp-61h] BYREF
  UFG::BitFlags128 v42; // [rsp+B0h] [rbp-29h] BYREF
  Render::cbLocalTransformState v43; // [rsp+C0h] [rbp-19h] BYREF
  __int64 v44; // [rsp+E8h] [rbp+Fh]
  UFG::BitFlags128 v45; // [rsp+F0h] [rbp+17h] BYREF
  float v46; // [rsp+138h] [rbp+5Fh] BYREF

  v44 = -2i64;
  mData = model_handle->mData;
  if ( !local_world )
    return 0i64;
  if ( !mData )
    return 0i64;
  ++this->mViewMetrics.mNumModelsProcessed;
  if ( do_clip )
  {
    v8 = (unsigned int)mData[1].mNode.mChild[0];
    mParent_high = HIDWORD(mData[1].mNode.mParent);
    LODWORD(v39.mFlags[0]) = mData[1].mNode.mParent;
    *(unsigned __int64 *)((char *)v39.mFlags + 4) = __PAIR64__(v8, mParent_high);
    mUID = mData[1].mNode.mUID;
    v11 = HIDWORD(mData[1].mNode.mChild[1]);
    LODWORD(v42.mFlags[0]) = mData[1].mNode.mChild[1];
    HIDWORD(v42.mFlags[0]) = v11;
    LODWORD(v42.mFlags[1]) = mUID;
    TransformAABB(local_world, (UFG::qVector3 *)&v39, (UFG::qVector3 *)&v42);
    if ( (unsigned int)IntersectAABBFrustum(this->mFrustumPlanes, (UFG::qVector3 *)&v39, (UFG::qVector3 *)&v42, &v46) == 2 )
      return 0i64;
  }
  ++this->mViewMetrics.mNumModelsRendered;
  p_mStateArgs = &this->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(
    &v43,
    &this->mSettings->mWorldView,
    &this->mWorldViewProjection,
    local_world);
  v40.mPrev = &v40;
  v40.mNext = &v40;
  v40.mCallback = 0i64;
  v40.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v40.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v40.mStateParamIndex = Param;
  }
  v40.mCached_Remote.m_Stream = 0i64;
  v40.mWorldViewProjection = &this->mWorldViewProjection;
  v40.mLocalWorld = local_world;
  mSettings = this->mSettings;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v15 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v15;
    arg.mStateParamIndex = v15;
  }
  arg.mCached_Remote.m_Stream = 0i64;
  arg.mWorldView = &mSettings->mWorldView;
  arg.mLocalWorld = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &v43);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, &v40);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(p_mStateArgs, &arg);
  v39 = (UFG::BitFlags128)0i64;
  v16 = (unsigned int)mData[2].mNode.mChild[1];
  if ( v16 )
  {
    v17 = 0i64;
    v18 = v16;
    v19 = force_mat;
    do
    {
      v20 = mData[2].mNode.mChild[0];
      if ( v20 )
        v21 = (char *)mData[2].mNode.mChild + (_QWORD)v20;
      else
        v21 = 0i64;
      v22 = &v21[v17];
      v23 = *(_QWORD *)&v21[v17];
      if ( v23 )
        v24 = (Illusion::Mesh *)&v22[v23];
      else
        v24 = 0i64;
      v25 = (Illusion::Material *)v24->mMaterialHandle.mData;
      if ( v19 )
        v25 = v19;
      v42 = v39;
      v39 = *Illusion::SubmitContext::Draw(this->mSubmitContext, &v45, v24, v25, &v42, v24);
      ++this->mViewMetrics.mNumMeshsRendered;
      v17 += 8i64;
      --v18;
    }
    while ( v18 );
  }
  mPrev = v43.mPrev;
  mNext = v43.mNext;
  v43.mPrev->mNext = v43.mNext;
  mNext->mPrev = mPrev;
  v43.mPrev = &v43;
  v43.mNext = &v43;
  v43.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v43.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v43.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v43.mStateParamIndex >> 6] &= ~(1i64 << (v43.mStateParamIndex & 0x3F));
  v28 = v40.mPrev;
  v29 = v40.mNext;
  v40.mPrev->mNext = v40.mNext;
  v29->mPrev = v28;
  v40.mPrev = &v40;
  v40.mNext = &v40;
  v40.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v40.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v40.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v40.mStateParamIndex >> 6] &= ~(1i64 << (v40.mStateParamIndex & 0x3F));
  v30 = arg.mPrev;
  v31 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v31->mPrev = v30;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v32 = arg.mPrev;
  v33 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v33->mPrev = v32;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  v34 = v40.mPrev;
  v35 = v40.mNext;
  v40.mPrev->mNext = v40.mNext;
  v35->mPrev = v34;
  v40.mPrev = &v40;
  v40.mNext = &v40;
  v36 = v43.mPrev;
  v37 = v43.mNext;
  v43.mPrev->mNext = v43.mNext;
  v37->mPrev = v36;
  v43.mPrev = &v43;
  v43.mNext = &v43;
  return v16;
}

// File Line: 1132
// RVA: 0xE030
__int64 __fastcall Render::View::Draw(
        Render::View *this,
        Illusion::rModel *rmodel,
        UFG::qMatrix44 *local_world,
        bool do_clip)
{
  float z; // xmm2_4
  float y; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  Illusion::StateArgs *p_mStateArgs; // rsi
  __int64 v12; // rbx
  unsigned __int16 Param; // ax
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 v15; // ax
  float v16; // r9d
  __int64 v17; // r15
  Illusion::rMesh *v18; // r14
  Illusion::rMaterial *mData; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  void (__fastcall *mCallback)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v25)(Illusion::StateArg *, Illusion::StateValues *); // rax
  void (__fastcall *v26)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v27)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rcx
  UFG::BitFlags128 v33; // [rsp+30h] [rbp-81h] BYREF
  Render::cbLocalProjectionState v34; // [rsp+40h] [rbp-71h] BYREF
  UFG::qMatrix44 *v35; // [rsp+78h] [rbp-39h]
  __int64 v36; // [rsp+80h] [rbp-31h]
  UFG::BitFlags128 v37; // [rsp+88h] [rbp-29h] BYREF
  Render::cbLocalTransformState arg; // [rsp+98h] [rbp-19h] BYREF
  __int64 v39; // [rsp+C0h] [rbp+Fh]
  UFG::BitFlags128 v40; // [rsp+C8h] [rbp+17h] BYREF
  float centre_distance_to_nearplan[6]; // [rsp+108h] [rbp+57h] BYREF
  Illusion::rMaterial *retaddr; // [rsp+128h] [rbp+77h]

  v39 = -2i64;
  if ( !rmodel )
    return 0i64;
  if ( !local_world )
    return 0i64;
  ++this->mViewMetrics.mNumModelsProcessed;
  if ( do_clip )
  {
    z = rmodel->mAABBMin.z;
    y = rmodel->mAABBMin.y;
    *(float *)v33.mFlags = rmodel->mAABBMin.x;
    *(unsigned __int64 *)((char *)v33.mFlags + 4) = __PAIR64__(LODWORD(z), LODWORD(y));
    v9 = rmodel->mAABBMax.z;
    v10 = rmodel->mAABBMax.y;
    *(float *)v37.mFlags = rmodel->mAABBMax.x;
    *((float *)v37.mFlags + 1) = v10;
    *(float *)&v37.mFlags[1] = v9;
    TransformAABB(local_world, (UFG::qVector3 *)&v33, (UFG::qVector3 *)&v37);
    if ( (unsigned int)IntersectAABBFrustum(
                         this->mFrustumPlanes,
                         (UFG::qVector3 *)&v33,
                         (UFG::qVector3 *)&v37,
                         centre_distance_to_nearplan) == 2 )
      return 0i64;
  }
  ++this->mViewMetrics.mNumModelsRendered;
  p_mStateArgs = &this->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(
    &arg,
    &this->mSettings->mWorldView,
    &this->mWorldViewProjection,
    local_world);
  v34.mPrev = &v34;
  v34.mNext = &v34;
  v12 = 0i64;
  v34.mCallback = 0i64;
  v34.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  WORD1(v33.mFlags[0]) = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v34.mStateParamIndex = Param;
  }
  v34.mNext = 0i64;
  v33.mFlags[1] = (unsigned __int64)&this->mWorldViewProjection;
  v34.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)local_world;
  mSettings = this->mSettings;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = &v34.mCallback;
  v34.mWorldViewProjection = 0i64;
  LOWORD(v34.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v34.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v15 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v15;
    LOWORD(v34.mLocalWorld) = v15;
  }
  v36 = 0i64;
  v34.mCached_Remote.m_Stream = mSettings;
  v35 = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, &v34);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    p_mStateArgs,
    (Render::cbLocalTransformInverseState *)&v34.mCallback);
  v33 = (UFG::BitFlags128)0i64;
  v16 = *(float *)&rmodel->mMeshes.mData.mNumItems;
  centre_distance_to_nearplan[0] = v16;
  if ( v16 != 0.0 )
  {
    v17 = LODWORD(v16);
    do
    {
      v18 = &rmodel->mMeshes.mData.mItems[v12];
      mData = (Illusion::rMaterial *)v18->mMaterial.mData;
      if ( !mData )
        mData = Illusion::rMaterial::GetDefault();
      if ( retaddr )
        mData = retaddr;
      if ( mData )
      {
        v37 = v33;
        v33 = *Illusion::SubmitContext::Draw(this->mSubmitContext, &v40, v18, mData, &v37, v18);
        ++this->mViewMetrics.mNumMeshsRendered;
      }
      ++v12;
      --v17;
    }
    while ( v17 );
    v16 = centre_distance_to_nearplan[0];
  }
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v22 = v34.mPrev;
  v23 = v34.mNext;
  v34.mPrev->mNext = v34.mNext;
  v23->mPrev = v22;
  v34.mPrev = &v34;
  v34.mNext = &v34;
  BYTE3(v33.mFlags[0]) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v34.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v34.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v34.mStateParamIndex >> 6] &= ~(1i64 << (v34.mStateParamIndex & 0x3F));
  mCallback = v34.mCallback;
  v25 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v34.mStateParamIndex;
  *((_QWORD *)v34.mCallback + 1) = *(_QWORD *)&v34.mStateParamIndex;
  *v25 = mCallback;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = &v34.mCallback;
  BYTE3(v34.mLocalWorld) = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[SLOWORD(v34.mLocalWorld)].mNode.mNext == &p_mStateArgs->mStateArgs[SLOWORD(v34.mLocalWorld)] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v34.mLocalWorld) >> 6] &= ~(1i64 << ((__int64)v34.mLocalWorld & 0x3F));
  v26 = v34.mCallback;
  v27 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v34.mStateParamIndex;
  *((_QWORD *)v34.mCallback + 1) = *(_QWORD *)&v34.mStateParamIndex;
  *v27 = v26;
  v34.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v34.mCallback;
  *(_QWORD *)&v34.mStateParamIndex = &v34.mCallback;
  v28 = v34.mPrev;
  v29 = v34.mNext;
  v34.mPrev->mNext = v34.mNext;
  v29->mPrev = v28;
  v34.mPrev = &v34;
  v34.mNext = &v34;
  v30 = arg.mPrev;
  v31 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v31->mPrev = v30;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  return LODWORD(v16);
}

// File Line: 1205
// RVA: 0x14A40
void __fastcall Render::View::DrawInstanced(
        Render::View *this,
        Illusion::Mesh *mesh,
        Illusion::Buffer *instance_buf,
        unsigned int instance_count)
{
  Illusion::StateArgs *p_mStateArgs; // rbx
  Render::ViewSettings *mSettings; // r13
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v13; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v14; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  Render::cbLocalTransformState arg; // [rsp+20h] [rbp-49h] BYREF
  Render::cbLocalTransformInverseState v21; // [rsp+48h] [rbp-21h] BYREF
  UFG::qMatrix44 *retaddr; // [rsp+D8h] [rbp+6Fh]
  Illusion::Material *v23; // [rsp+E0h] [rbp+77h]
  char *v24; // [rsp+E8h] [rbp+7Fh]

  p_mStateArgs = &this->mSubmitContext->mStateArgs;
  Render::cbLocalTransformState::cbLocalTransformState(
    (Render::cbLocalTransformState *)&v21,
    &this->mSettings->mWorldView,
    &this->mWorldViewProjection,
    retaddr);
  mSettings = this->mSettings;
  v21.mPrev = &v21;
  v21.mNext = &v21;
  v21.mCallback = 0i64;
  v21.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
  *(_WORD *)&v21.mFlags = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = Param;
    v21.mStateParamIndex = Param;
  }
  v21.mCached_Remote.m_Stream = 0i64;
  v21.mWorldView = &mSettings->mWorldView;
  v21.mLocalWorld = retaddr;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(p_mStateArgs, &v21);
  Illusion::SubmitContext::DrawInstanced(this->mSubmitContext, mesh, instance_buf, instance_count, v23, 0i64, mesh, v24);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
  {
    v13 = &p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v13 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  v14 = v21.mPrev;
  v15 = v21.mNext;
  v21.mPrev->mNext = v21.mNext;
  v15->mPrev = v14;
  v21.mPrev = &v21;
  v21.mNext = &v21;
  v21.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[v21.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[v21.mStateParamIndex] )
    p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v21.mStateParamIndex >> 6] &= ~(1i64 << (v21.mStateParamIndex & 0x3F));
  v16 = v21.mPrev;
  v17 = v21.mNext;
  v21.mPrev->mNext = v21.mNext;
  v17->mPrev = v16;
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
}

// File Line: 1231
// RVA: 0xD590
Illusion::Material *__fastcall Render::View::CreateSimpleMaterial(
        unsigned int texture_name_uid,
        unsigned int raster_state_uid,
        unsigned int alpha_state_uid,
        bool depth_bias)
{
  Illusion::Material *v4; // rbx
  _WORD *v5; // rdi
  __int64 mOffset; // rax
  _WORD *v10; // rax
  int mNext; // eax
  __int64 v12; // rax
  unsigned int v13; // r8d
  __int64 v14; // rax
  _WORD *v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  _WORD *v18; // rax
  __int64 v19; // rax

  v4 = `anonymous namespace::gSimpleMaterial;
  v5 = 0i64;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != texture_name_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      texture_name_uid);
    mOffset = v4->mMaterialUser.mOffset;
    if ( mOffset )
      v10 = (_WORD *)((char *)&v4->mMaterialUser + mOffset);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  mNext = (int)v4[1].mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( mNext == 826356572 )
  {
    if ( alpha_state_uid == 721849354 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[1].mNode.mChild[1], v4[1].mTypeUID, 0x20D03CDDu);
      v12 = v4->mMaterialUser.mOffset;
      if ( v12 )
        *(_WORD *)((char *)&v4->mMaterialUser.mOffset + v12) |= 0x20u;
      else
        LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
      goto LABEL_24;
    }
  }
  else if ( mNext == 26403030 )
  {
    v13 = 685899938;
    if ( depth_bias )
      v13 = -1096278483;
    if ( LODWORD(v4[3].mNode.mChild[0]) != v13 )
    {
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mNumParams, (unsigned int)v4[3].mNode.mChild[1], v13);
      v14 = v4->mMaterialUser.mOffset;
      if ( v14 )
        v15 = (_WORD *)((char *)&v4->mMaterialUser + v14);
      else
        v15 = 0i64;
      *v15 |= 0x20u;
    }
  }
  if ( !alpha_state_uid )
  {
    v16 = *((_QWORD *)&v4[1].UFG::qResourceData + 11);
    alpha_state_uid = 0;
    if ( v16 )
      alpha_state_uid = *(_DWORD *)(v16 + 108);
    if ( alpha_state_uid == -1551679522 )
      raster_state_uid = -262489691;
  }
LABEL_24:
  if ( *(_DWORD *)&v4[2].mDebugName[28] != raster_state_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2].mDebugName[4],
      *((_DWORD *)&v4[2].UFG::qResourceData + 22),
      raster_state_uid);
    v17 = v4->mMaterialUser.mOffset;
    if ( v17 )
      v18 = (_WORD *)((char *)&v4->mMaterialUser + v17);
    else
      v18 = 0i64;
    *v18 |= 0x20u;
  }
  if ( v4[2].mNode.mUID != alpha_state_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v4[2],
      (unsigned int)v4[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      alpha_state_uid);
    v19 = v4->mMaterialUser.mOffset;
    if ( v19 )
      v5 = (_WORD *)((char *)&v4->mMaterialUser + v19);
    *v5 |= 0x20u;
  }
  return v4;
}

// File Line: 1340
// RVA: 0x16040
UFG::qMatrix44 *__fastcall Render::View::ScaleToFit(
        Render::View *this,
        UFG::qMatrix44 *xform,
        float scale,
        float scale_adjust)
{
  float v4; // xmm6_4
  float v5; // xmm1_4
  __m128 y_low; // xmm2
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  UFG::qVector4 v10; // xmm5
  UFG::qVector4 v11; // xmm4
  UFG::qVector4 v12; // xmm1

  v4 = scale;
  if ( (_S6 & 1) == 0 )
    _S6 |= 1u;
  if ( scale < 0.0 )
  {
    v5 = xform->v3.x - this->mViewWorld.v3.x;
    y_low = (__m128)LODWORD(xform->v3.y);
    v7 = xform->v3.z - this->mViewWorld.v3.z;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->mViewWorld.v3.y)
                                      * (float)(y_low.m128_f32[0] - this->mViewWorld.v3.y))
                              + (float)(v5 * v5))
                      + (float)(v7 * v7);
    v8 = _mm_sqrt_ps(y_low).m128_f32[0] * 0.034899496;
    v9 = FLOAT_0_000099999997;
    if ( v8 >= 0.000099999997 )
      v9 = v8;
    LODWORD(v4) = COERCE_UNSIGNED_INT((float)(v4 * scale_adjust) * v9) ^ _xmm[0];
  }
  v10 = xform->v1;
  v11 = xform->v2;
  v12 = xform->v3;
  sScaledXform.v0 = xform->v0;
  sScaledXform.v3 = v12;
  sScaledXform.v0.x = sScaledXform.v0.x * v4;
  sScaledXform.v0.y = sScaledXform.v0.y * v4;
  sScaledXform.v0.z = sScaledXform.v0.z * v4;
  sScaledXform.v0.w = sScaledXform.v0.w * v4;
  sScaledXform.v1.x = v10.x * v4;
  sScaledXform.v1.y = v10.y * v4;
  sScaledXform.v1.z = v10.z * v4;
  sScaledXform.v1.w = v10.w * v4;
  sScaledXform.v2.x = v11.x * v4;
  sScaledXform.v2.y = v11.y * v4;
  sScaledXform.v2.z = v11.z * v4;
  sScaledXform.v2.w = v11.w * v4;
  return &sScaledXform;
}

// File Line: 1366
// RVA: 0x16600
void __fastcall Render::View::SetSimpleMaterialShader(unsigned int shader_uid)
{
  Illusion::Material *v1; // rbx
  __int64 mOffset; // rax

  v1 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != shader_uid )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mNode.mChild[1],
      `anonymous namespace::gSimpleMaterial[1].mTypeUID,
      shader_uid);
    mOffset = v1->mMaterialUser.mOffset;
    if ( mOffset )
      *(_WORD *)((char *)&v1->mMaterialUser.mOffset + mOffset) |= 0x20u;
    else
      LOWORD(MEMORY[0]) = MEMORY[0] | 0x20;
  }
}

// File Line: 1374
// RVA: 0x13D80
void __fastcall Render::View::DrawGradient(
        Render::View *this,
        int x,
        int y,
        int width,
        int height,
        UFG::qColour *colour_left,
        UFG::qColour *colour_right)
{
  unsigned int **v8; // r10
  __m128i v9; // xmm0
  __m128i v10; // xmm1
  float v11; // xmm2_4
  float v12; // xmm9_4
  float v13; // xmm6_4
  float v14; // xmm8_4
  float v15; // xmm7_4
  UFG::qColour *v16; // r8
  UFG::qColour *v17; // rdx
  Illusion::Material *SimpleMaterial; // rax
  Render::Poly poly; // [rsp+80h] [rbp+8h] BYREF

  v8 = (unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
  v9 = _mm_cvtsi32_si128(**v8);
  v10 = _mm_cvtsi32_si128((*v8)[1]);
  poly.mVertices = 0i64;
  v11 = 1.0 / _mm_cvtepi32_ps(v9).m128_f32[0];
  *(float *)v9.m128i_i32 = 1.0 / _mm_cvtepi32_ps(v10).m128_f32[0];
  v12 = (float)x * v11;
  v13 = (float)(x + width) * v11;
  v14 = (float)y * *(float *)v9.m128i_i32;
  v15 = (float)(y + height) * *(float *)v9.m128i_i32;
  Render::Poly::Init(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
  v16 = colour_right;
  v17 = colour_left;
  poly.mVertices[1].mPosition.x = v12;
  poly.mVertices[1].mPosition.y = v14;
  poly.mVertices[1].mPosition.z = 0.0;
  poly.mVertices->mPosition.x = v13;
  poly.mVertices->mPosition.y = v14;
  poly.mVertices->mPosition.z = 0.0;
  poly.mVertices[2].mPosition.x = v13;
  poly.mVertices[2].mPosition.y = v15;
  poly.mVertices[2].mPosition.z = 0.0;
  poly.mVertices[3].mPosition.x = v12;
  poly.mVertices[3].mPosition.y = v15;
  poly.mVertices[3].mPosition.z = 0.0;
  Render::Poly::SetColours(&poly, v17, v16, v16, v17);
  SimpleMaterial = Render::View::CreateSimpleMaterial(0xB11369EB, 0x62F81854u, 0xA3833FDE, 0);
  Render::View::Draw(this, &poly, SimpleMaterial, 0i64);
}

// File Line: 1402
// RVA: 0x13F50
void __fastcall Render::View::DrawIcon(
        Render::View *this,
        unsigned int textureUID,
        int posX,
        int posY,
        int width,
        int height,
        UFG::qColour *colour,
        unsigned int alpha_state_uid)
{
  unsigned int **v10; // r10
  __m128i v11; // xmm1
  __m128i v12; // xmm2
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  Illusion::Material *SimpleMaterial; // rax
  Render::Poly poly; // [rsp+30h] [rbp-88h] BYREF

  if ( textureUID - 1 <= 0xFFFFFFFD )
  {
    v10 = (unsigned int **)this->mSubmitContext->mStateValues.mParamValues[11];
    v11 = _mm_cvtsi32_si128(**v10);
    v12 = _mm_cvtsi32_si128((*v10)[1]);
    poly.mVertices = 0i64;
    v13 = 1.0 / _mm_cvtepi32_ps(v11).m128_f32[0];
    v14 = 1.0 / _mm_cvtepi32_ps(v12).m128_f32[0];
    v15 = (float)posX * v13;
    v16 = (float)posY * v14;
    v17 = (float)(v13 * (float)width) + v15;
    v18 = (float)(v14 * (float)height) + v16;
    Render::Poly::Init(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
    poly.mVertices[1].mPosition.x = v15;
    poly.mVertices[1].mPosition.y = v16;
    poly.mVertices[1].mPosition.z = 0.0;
    poly.mVertices->mPosition.x = v17;
    poly.mVertices->mPosition.y = v16;
    poly.mVertices->mPosition.z = 0.0;
    poly.mVertices[2].mPosition.x = v17;
    poly.mVertices[2].mPosition.y = v18;
    poly.mVertices[2].mPosition.z = 0.0;
    poly.mVertices[3].mPosition.x = v15;
    poly.mVertices[3].mPosition.y = v18;
    poly.mVertices[3].mPosition.z = 0.0;
    Render::Poly::SetUVs(
      &poly,
      (float)(1.0 / (float)width) * 0.5,
      (float)(1.0 / (float)height) * 0.5,
      (float)(1.0 - (float)((float)(1.0 / (float)width) * 0.5)) - (float)((float)(1.0 / (float)width) * 0.5),
      (float)(1.0 - (float)((float)(1.0 / (float)height) * 0.5)) - (float)((float)(1.0 / (float)height) * 0.5));
    Render::Poly::SetColour(&poly, colour);
    SimpleMaterial = Render::View::CreateSimpleMaterial(textureUID, 0x62F81854u, alpha_state_uid, 0);
    Render::View::Draw(this, &poly, SimpleMaterial, 0i64);
  }
}

// File Line: 1452
// RVA: 0x14C50
void __fastcall Render::View::DrawSegment(
        Render::View *this,
        UFG::qVector3 *start,
        UFG::qVector3 *end,
        UFG::DrawInfo *info)
{
  char *v8; // rdi
  float z; // xmm1_4
  unsigned int v10; // edx
  int v11; // r8d
  float x; // eax
  float v13; // xmm1_4
  int v14; // ecx
  float v15; // eax

  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x60u, 0x10u);
  if ( v8 )
  {
    z = start->z;
    v10 = 1660426324;
    v11 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
    x = start->x;
    *((_DWORD *)v8 + 1) = LODWORD(start->y);
    *(float *)v8 = x;
    *((_DWORD *)v8 + 11) = v11;
    *((float *)v8 + 2) = z;
    v13 = end->z;
    v14 = (int)(float)(info->mColour2.r * 255.0) | (((int)(float)(info->mColour2.g * 255.0) | (((int)(float)(info->mColour2.b * 255.0) | ((int)(float)(info->mColour2.a * 255.0) << 8)) << 8)) << 8);
    v15 = end->x;
    *((_DWORD *)v8 + 13) = LODWORD(end->y);
    *((float *)v8 + 12) = v15;
    *((_DWORD *)v8 + 23) = v14;
    *((float *)v8 + 14) = v13;
    if ( info->mFaceCull )
    {
      if ( info->mDepthBuffer )
        v10 = 543723269;
      else
        v10 = 206781021;
    }
    else if ( info->mDepthBuffer )
    {
      v10 = 1099738947;
    }
    Render::View::CreateSimpleMaterial(0xB11369EB, v10, info->mAlphaBlend, info->mDepthBias);
    Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, (Render::vDynamic *)v8, 2);
  }
}

// File Line: 1469
// RVA: 0xF370
void __fastcall Render::View::DrawArrow(
        Render::View *this,
        UFG::qVector3 *p0,
        UFG::qVector3 *p1,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *xform)
{
  char *v9; // rax
  Render::vDynamic *v10; // rdi
  __m128 y_low; // xmm0
  __m128 v12; // xmm5
  float v13; // xmm13_4
  float v14; // xmm14_4
  float x; // xmm15_4
  __m128 v16; // xmm1
  float v17; // xmm6_4
  float v18; // xmm8_4
  float v19; // xmm5_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm11_4
  float v23; // xmm1_4
  float v24; // xmm8_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm8_4
  float v28; // xmm0_4
  int v29; // ecx
  int v30; // ecx
  int v31; // eax
  float r; // xmm0_4
  int v33; // ecx
  int v34; // eax
  float v35; // xmm0_4
  unsigned int v36; // edx
  float v37; // xmm0_4
  int v38; // ecx
  int v39; // ecx
  int v40; // eax
  float v41; // xmm0_4
  int v42; // ecx
  int v43; // eax
  float v44; // xmm0_4
  float y; // [rsp+40h] [rbp-B8h]
  float z; // [rsp+44h] [rbp-B4h]

  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x120u, 0x10u);
  v10 = (Render::vDynamic *)v9;
  if ( v9 )
  {
    y_low = (__m128)LODWORD(p1->y);
    y = p1->y;
    v12 = y_low;
    z = p1->z;
    v13 = p0->y;
    v14 = p0->z;
    v12.m128_f32[0] = y_low.m128_f32[0] - v13;
    x = p1->x;
    v16 = v12;
    v17 = p1->x - p0->x;
    v16.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v17 * v17))
                    + (float)((float)(z - v14) * (float)(z - v14));
    LODWORD(v18) = _mm_sqrt_ps(v16).m128_u32[0];
    LODWORD(v19) = COERCE_UNSIGNED_INT(y_low.m128_f32[0] - v13) ^ _xmm[0];
    v20 = v13 + (float)((float)((float)(y_low.m128_f32[0] - v13) * 15.0) * 0.0625);
    v21 = p0->x + (float)((float)(v17 * 15.0) * 0.0625);
    v22 = v14 + (float)((float)((float)(z - v14) * 15.0) * 0.0625);
    v23 = (float)(v19 * v19) + (float)(v17 * v17);
    if ( v23 <= 0.0001 )
    {
      v26 = 0.0;
      v25 = v18 * 0.03125;
      v27 = 0.0;
    }
    else
    {
      v24 = (float)(v18 * 0.03125) / fsqrt(v23);
      v25 = v24 * v19;
      v26 = v24 * v17;
      v27 = v24 * 0.0;
    }
    v28 = info->mColour1.r * 255.0;
    v29 = (int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8);
    *(float *)v9 = p0->x;
    *((float *)v9 + 1) = v13;
    *((float *)v9 + 2) = v14;
    *((_DWORD *)v9 + 11) = (int)v28 | (v29 << 8);
    v30 = ((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8;
    v31 = (int)(float)(info->mColour1.g * 255.0);
    r = info->mColour1.r;
    v10[1].mPosition.x = v21;
    v10[1].mPosition.y = v20;
    v10[1].mPosition.z = v22;
    v10[1].mColour = (int)(float)(r * 255.0) | ((v31 | v30) << 8);
    v33 = ((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8;
    v34 = (int)(float)(info->mColour1.g * 255.0);
    v35 = info->mColour1.r;
    v10[2].mPosition.x = v21 + v25;
    v10[2].mPosition.y = v20 + v26;
    v10[2].mPosition.z = v22 + v27;
    v10[2].mColour = (int)(float)(v35 * 255.0) | ((v34 | v33) << 8);
    v36 = 1660426324;
    v37 = info->mColour1.r * 255.0;
    v38 = (int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8);
    v10[3].mPosition.x = x;
    v10[3].mPosition.y = y;
    v10[3].mPosition.z = z;
    v10[3].mColour = (int)v37 | (v38 << 8);
    v39 = ((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8;
    v40 = (int)(float)(info->mColour1.g * 255.0);
    v41 = info->mColour1.r;
    v10[4].mPosition.x = v21 - v25;
    v10[4].mPosition.y = v20 - v26;
    v10[4].mPosition.z = v22 - v27;
    v10[4].mColour = (int)(float)(v41 * 255.0) | ((v40 | v39) << 8);
    v42 = ((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8;
    v43 = (int)(float)(info->mColour1.g * 255.0);
    v44 = info->mColour1.r;
    v10[5].mPosition.x = v21;
    v10[5].mPosition.y = v20;
    v10[5].mPosition.z = v22;
    v10[5].mColour = (int)(float)(v44 * 255.0) | ((v43 | v42) << 8);
    if ( info->mFaceCull )
    {
      if ( info->mDepthBuffer )
        v36 = 543723269;
      else
        v36 = 206781021;
    }
    else if ( info->mDepthBuffer )
    {
      v36 = 1099738947;
    }
    Render::View::CreateSimpleMaterial(0xB11369EB, v36, info->mAlphaBlend, info->mDepthBias);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v10, 6);
  }
}

// File Line: 1508
// RVA: 0x12C10
void __fastcall Render::View::DrawDebugPrimLineStrip(
        Render::View *this,
        UFG::qVector3 *line_points,
        const int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world)
{
  __int64 v5; // r14
  unsigned int v8; // esi
  char *v10; // rax
  Render::vDynamic *v11; // rbp
  int v12; // ebx
  __int64 v13; // r9
  char *p_z; // rax
  char *v15; // rcx
  unsigned __int64 v16; // rdx
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm2_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  __int64 v26; // rcx
  __int64 v27; // r8
  float *v28; // rdx
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  unsigned int v32; // edx

  v5 = num_points;
  v8 = 48 * num_points;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * num_points, 0x10u);
  v11 = (Render::vDynamic *)v10;
  if ( v10 )
  {
    v12 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
    UFG::qMemSet(v10, 0, v8);
    v13 = 0i64;
    if ( v5 >= 4 )
    {
      p_z = (char *)&v11[1].mPosition.z;
      v15 = (char *)&line_points[1].z;
      v16 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
      v13 = 4 * v16;
      do
      {
        v17 = *((_DWORD *)v15 - 5);
        v18 = *((_DWORD *)v15 - 4);
        v19 = *((_DWORD *)v15 - 3);
        p_z += 192;
        v15 += 48;
        *((_DWORD *)p_z - 62) = v17;
        *((_DWORD *)p_z - 61) = v18;
        *((_DWORD *)p_z - 60) = v19;
        *((_DWORD *)p_z - 51) = v12;
        v20 = *((_DWORD *)v15 - 13);
        v21 = *((_DWORD *)v15 - 12);
        *((_DWORD *)p_z - 50) = *((_DWORD *)v15 - 14);
        *((_DWORD *)p_z - 49) = v20;
        *((_DWORD *)p_z - 48) = v21;
        *((_DWORD *)p_z - 39) = v12;
        v22 = *((_DWORD *)v15 - 10);
        v23 = *((_DWORD *)v15 - 9);
        *((_DWORD *)p_z - 38) = *((_DWORD *)v15 - 11);
        *((_DWORD *)p_z - 37) = v22;
        *((_DWORD *)p_z - 36) = v23;
        *((_DWORD *)p_z - 27) = v12;
        v24 = *((_DWORD *)v15 - 7);
        v25 = *((_DWORD *)v15 - 6);
        *((_DWORD *)p_z - 26) = *((_DWORD *)v15 - 8);
        *((_DWORD *)p_z - 25) = v24;
        *((_DWORD *)p_z - 24) = v25;
        *((_DWORD *)p_z - 15) = v12;
        --v16;
      }
      while ( v16 );
    }
    if ( v13 < v5 )
    {
      v26 = (__int64)&v11[v13].mPosition.z;
      v27 = v5 - v13;
      v28 = &line_points[v13].z;
      do
      {
        v29 = *((_DWORD *)v28 - 2);
        v30 = *((_DWORD *)v28 - 1);
        v31 = *(_DWORD *)v28;
        v26 += 48i64;
        v28 += 3;
        *(_DWORD *)(v26 - 56) = v29;
        *(_DWORD *)(v26 - 52) = v30;
        *(_DWORD *)(v26 - 48) = v31;
        *(_DWORD *)(v26 - 12) = v12;
        --v27;
      }
      while ( v27 );
    }
    v32 = 1660426324;
    if ( info->mFaceCull )
    {
      if ( info->mDepthBuffer )
        v32 = 543723269;
      else
        v32 = 206781021;
    }
    else if ( info->mDepthBuffer )
    {
      v32 = 1099738947;
    }
    Render::View::CreateSimpleMaterial(0xB11369EB, v32, info->mAlphaBlend, info->mDepthBias);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v11, v5);
  }
}

// File Line: 1541
// RVA: 0x10790
void __fastcall Render::View::DrawDebugConnectedPrimLineStrip(
        Render::View *this,
        UFG::qVector3 *line_points,
        const int num_points,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        bool depth_test,
        bool alpha_test)
{
  __int64 v7; // rbp
  unsigned int v11; // ebx
  char *v12; // rax
  Render::vDynamic *v13; // rdi
  __int64 v14; // r10
  int v15; // r8d
  char *p_z; // rcx
  char *v17; // rdx
  unsigned __int64 v18; // r9
  int v19; // xmm0_4
  int v20; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  __int64 v27; // rcx
  float *v28; // rdx
  __int64 v29; // r9
  int v30; // xmm0_4
  int v31; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  unsigned int v34; // edx
  __int64 v35; // rcx
  unsigned int v36; // r8d

  v7 = num_points;
  v11 = 48 * (num_points + 1);
  v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v11, 0x10u);
  v13 = (Render::vDynamic *)v12;
  if ( v12 )
  {
    UFG::qMemSet(v12, 0, v11);
    v14 = 0i64;
    v15 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    if ( v7 >= 4 )
    {
      p_z = (char *)&v13[1].mPosition.z;
      v17 = (char *)&line_points[1].z;
      v18 = ((unsigned __int64)(v7 - 4) >> 2) + 1;
      v14 = 4 * v18;
      do
      {
        v19 = *((_DWORD *)v17 - 4);
        v20 = *((_DWORD *)v17 - 3);
        *((_DWORD *)p_z - 14) = *((_DWORD *)v17 - 5);
        p_z += 192;
        v17 += 48;
        *((_DWORD *)p_z - 61) = v19;
        *((_DWORD *)p_z - 60) = v20;
        *((_DWORD *)p_z - 51) = v15;
        v21 = *((_DWORD *)v17 - 13);
        v22 = *((_DWORD *)v17 - 12);
        *((_DWORD *)p_z - 50) = *((_DWORD *)v17 - 14);
        *((_DWORD *)p_z - 49) = v21;
        *((_DWORD *)p_z - 48) = v22;
        *((_DWORD *)p_z - 39) = v15;
        v23 = *((_DWORD *)v17 - 10);
        v24 = *((_DWORD *)v17 - 9);
        *((_DWORD *)p_z - 38) = *((_DWORD *)v17 - 11);
        *((_DWORD *)p_z - 37) = v23;
        *((_DWORD *)p_z - 36) = v24;
        *((_DWORD *)p_z - 27) = v15;
        v25 = *((_DWORD *)v17 - 7);
        v26 = *((_DWORD *)v17 - 6);
        *((_DWORD *)p_z - 26) = *((_DWORD *)v17 - 8);
        *((_DWORD *)p_z - 25) = v25;
        *((_DWORD *)p_z - 24) = v26;
        *((_DWORD *)p_z - 15) = v15;
        --v18;
      }
      while ( v18 );
    }
    if ( v14 < v7 )
    {
      v27 = (__int64)&v13[v14].mPosition.z;
      v28 = &line_points->z + 2 * v14 + v14;
      v29 = v7 - v14;
      do
      {
        v30 = *((_DWORD *)v28 - 1);
        v31 = *(_DWORD *)v28;
        *(float *)(v27 - 8) = *(v28 - 2);
        v27 += 48i64;
        v28 += 3;
        *(_DWORD *)(v27 - 52) = v30;
        *(_DWORD *)(v27 - 48) = v31;
        *(_DWORD *)(v27 - 12) = v15;
        --v29;
      }
      while ( v29 );
    }
    y = line_points->y;
    z = line_points->z;
    v34 = 1660426324;
    v35 = v7;
    v13[v35].mPosition.x = line_points->x;
    v13[v35].mPosition.y = y;
    v13[v35].mPosition.z = z;
    v13[v35].mColour = v15;
    v36 = 662883558;
    if ( alpha_test )
      v36 = -1551679522;
    if ( depth_test )
      v34 = 543723269;
    Render::View::CreateSimpleMaterial(0xB11369EB, v34, v36, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v13, v7 + 1);
  }
}

// File Line: 1594
// RVA: 0xEE40
void __fastcall Render::View::DrawArc(
        Render::View *this,
        UFG::qMatrix44 *xform,
        UFG::DrawInfo *info,
        float angleRadsStart,
        float angleRadsEnd,
        unsigned int segCount)
{
  float v8; // xmm7_4
  Render::vDynamic *v10; // r13
  float v11; // xmm6_4
  int v12; // ebx
  unsigned int v13; // edx
  int v14; // r9d
  Render::View *v15; // rcx
  __int64 v16; // rbp
  int v17; // eax
  int v18; // esi
  Render::vDynamic *v19; // r8

  v8 = angleRadsStart;
  v10 = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1) + 1;
  if ( angleRadsStart >= 0.0 )
  {
    if ( angleRadsStart > 6.2831855 )
      v8 = angleRadsStart + -6.2831855;
  }
  else
  {
    v8 = angleRadsStart + 6.2831855;
  }
  v11 = angleRadsEnd;
  if ( angleRadsEnd >= 0.0 )
  {
    if ( angleRadsEnd > 6.2831855 )
      v11 = angleRadsEnd + -6.2831855;
  }
  else
  {
    v11 = angleRadsEnd + 6.2831855;
  }
  if ( v8 == 0.0 && v11 == 6.2831855 )
    v12 = 0;
  else
    v12 = (v11 <= v8) + 1;
  v13 = 1660426324;
  if ( info->mFaceCull )
  {
    if ( info->mDepthBuffer )
      v13 = 543723269;
    else
      v13 = 206781021;
  }
  else if ( info->mDepthBuffer )
  {
    v13 = 1099738947;
  }
  Render::View::CreateSimpleMaterial(0xB11369EB, v13, info->mAlphaBlend, info->mDepthBias);
  Render::View::ScaleToFit(this, xform, info->mScale, Fit_scale_adjust_9);
  if ( !v12 )
  {
    v14 = segCount + 1;
    v15 = this;
LABEL_28:
    v19 = v10;
LABEL_29:
    Render::View::DrawDebugPrim(v15, DebugPrim_LineStrip, v19, v14);
    return;
  }
  v16 = (unsigned int)`anonymous namespace::AngleToSegment(v8, segCount);
  v17 = `anonymous namespace::AngleToSegment(v11, segCount);
  v18 = v17;
  if ( v12 == 1 )
  {
    if ( (_DWORD)v16 == v17 )
      return;
    v15 = this;
    v14 = v17 - v16 + 1;
    v19 = &v10[v16];
    goto LABEL_29;
  }
  if ( segCount > (unsigned int)v16 )
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, &v10[v16], segCount - v16 + 1);
  if ( v18 )
  {
    v14 = v18 + 1;
    v15 = this;
    goto LABEL_28;
  }
}

// File Line: 1673
// RVA: 0xF060
void __fastcall Render::View::DrawArcSolid(
        Render::View *this,
        UFG::qMatrix44 *xform,
        UFG::DrawInfo *info,
        float angleRadsStart,
        float angleRadsEnd,
        unsigned int segCount)
{
  float v8; // xmm7_4
  Render::vDynamic *VertsCircle; // rax
  Render::vDynamic *v10; // rbp
  float v11; // xmm6_4
  int v12; // esi
  unsigned int v13; // edx
  int v14; // r13d
  int v15; // r9d
  Render::vDynamic *v16; // r8
  Render::View *v17; // rcx
  __int64 v18; // r12
  int v19; // ebp
  Render::vDynamic *v20; // rcx
  Render::vDynamic *v21; // rdi
  float y; // xmm7_4
  float z; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm6_4
  Render::View *v26; // r15
  Render::vDynamic *vertices; // [rsp+48h] [rbp-60h]
  unsigned int angleRadsEnda; // [rsp+D0h] [rbp+28h]

  v8 = angleRadsStart;
  VertsCircle = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1);
  v10 = VertsCircle;
  vertices = VertsCircle;
  if ( angleRadsStart >= 0.0 )
  {
    if ( angleRadsStart > 6.2831855 )
      v8 = angleRadsStart + -6.2831855;
  }
  else
  {
    v8 = angleRadsStart + 6.2831855;
  }
  v11 = angleRadsEnd;
  if ( angleRadsEnd >= 0.0 )
  {
    if ( angleRadsEnd > 6.2831855 )
      v11 = angleRadsEnd + -6.2831855;
  }
  else
  {
    v11 = angleRadsEnd + 6.2831855;
  }
  if ( v8 == 0.0 && v11 == 6.2831855 )
    v12 = 0;
  else
    v12 = (v11 <= v8) + 1;
  angleRadsEnda = VertsCircle[1].mColour;
  v13 = 1660426324;
  v14 = (int)(float)(info->mColour2.r * 255.0) | (((int)(float)(info->mColour2.g * 255.0) | (((int)(float)(info->mColour2.b * 255.0) | ((int)(float)(info->mColour2.a * 255.0) << 8)) << 8)) << 8);
  if ( info->mFaceCull )
  {
    if ( info->mDepthBuffer )
      v13 = 543723269;
    else
      v13 = 206781021;
  }
  else if ( info->mDepthBuffer )
  {
    v13 = 1099738947;
  }
  Render::View::CreateSimpleMaterial(0xB11369EB, v13, info->mAlphaBlend, info->mDepthBias);
  Render::View::ScaleToFit(this, xform, info->mScale, Fit_scale_adjust_9);
  v10->mColour = v14;
  if ( !v12 )
  {
    v15 = segCount + 2;
    v16 = v10;
    v17 = this;
LABEL_29:
    Render::View::DrawDebugPrim(v17, DebugPrim_TriangleFan, v16, v15);
    return;
  }
  v18 = (unsigned int)`anonymous namespace::AngleToSegment(v8, segCount);
  v19 = `anonymous namespace::AngleToSegment(v11, segCount);
  if ( (_DWORD)v18 == v19 )
    return;
  v20 = vertices;
  v21 = &vertices[v18];
  if ( v12 == 1 )
  {
    y = v21->mPosition.y;
    z = v21->mPosition.z;
    *(_QWORD *)&v21->mPosition.y = 0i64;
    v21->mColour = v14;
    Render::View::DrawDebugPrim(this, DebugPrim_TriangleFan, v21, v19 - v18 + 2);
    v21->mPosition.y = y;
    v21->mPosition.z = z;
    v21->mColour = angleRadsEnda;
    return;
  }
  if ( segCount <= (unsigned int)v18 )
  {
    v26 = this;
  }
  else
  {
    v24 = v21->mPosition.y;
    v25 = v21->mPosition.z;
    *(_QWORD *)&v21->mPosition.y = 0i64;
    v21->mColour = v14;
    v26 = this;
    Render::View::DrawDebugPrim(this, DebugPrim_TriangleFan, v21, segCount - v18 + 2);
    v21->mPosition.y = v24;
    v21->mPosition.z = v25;
    v20 = vertices;
    v21->mColour = angleRadsEnda;
  }
  if ( v19 )
  {
    v16 = v20;
    v15 = v19 + 2;
    v17 = v26;
    goto LABEL_29;
  }
}

// File Line: 1828
// RVA: 0x103B0
void __fastcall Render::View::DrawCircle(
        Render::View *this,
        UFG::qMatrix44 *xform,
        UFG::DrawInfo *info,
        unsigned int segCount)
{
  Render::vDynamic *VertsCircle; // rax
  unsigned int v9; // edx
  Render::vDynamic *v10; // rsi

  VertsCircle = `anonymous namespace::GetVertsCircle(segCount, &info->mColour1);
  v9 = 1660426324;
  v10 = VertsCircle;
  if ( info->mFaceCull )
  {
    if ( info->mDepthBuffer )
      v9 = 543723269;
    else
      v9 = 206781021;
  }
  else if ( info->mDepthBuffer )
  {
    v9 = 1099738947;
  }
  Render::View::CreateSimpleMaterial(0xB11369EB, v9, info->mAlphaBlend, info->mDepthBias);
  Render::View::ScaleToFit(this, xform, info->mScale, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v10 + 1, segCount + 1);
}

// File Line: 2141
// RVA: 0x114D0
void __fastcall Render::View::DrawDebugPrimCircle(
        Render::View *this,
        UFG::qVector3 *centre,
        UFG::qVector3 *normal,
        const float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  char *v10; // r15
  float y; // xmm4_4
  __m128 x_low; // xmm2
  float z; // xmm5_4
  __m128 v14; // xmm3
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float x; // xmm7_4
  float v20; // xmm1_4
  __m128 z_low; // xmm6
  int v22; // edi
  char *v23; // rbx
  float v24; // xmm3_4
  float v25; // xmm7_4
  __m128 v26; // xmm2
  float v27; // xmm9_4
  float v28; // xmm8_4
  float v29; // xmm10_4
  float v30; // xmm9_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  UFG::qVector3 axis; // [rsp+58h] [rbp-D0h] BYREF
  UFG::qMatrix44 dest; // [rsp+70h] [rbp-B8h] BYREF

  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x5D0u, 0x10u);
  if ( v10 )
  {
    y = normal->y;
    x_low = (__m128)LODWORD(normal->x);
    z = normal->z;
    v14 = x_low;
    v14.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    v15 = 0.0;
    if ( v14.m128_f32[0] != 0.0 )
      v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    v16 = x_low.m128_f32[0] * v15;
    v17 = y * v15;
    v18 = z * v15;
    axis.x = v16;
    axis.y = v17;
    axis.z = v18;
    if ( v16 <= v17 || v16 <= v18 )
    {
      if ( v17 <= v16 || v17 <= v18 )
      {
        x = UFG::qVector3::msAxisX.x;
        v20 = UFG::qVector3::msAxisX.y;
        z_low = (__m128)LODWORD(UFG::qVector3::msAxisX.z);
      }
      else
      {
        x = UFG::qVector3::msAxisZ.x;
        v20 = UFG::qVector3::msAxisZ.y;
        z_low = (__m128)LODWORD(UFG::qVector3::msAxisZ.z);
      }
    }
    else
    {
      x = UFG::qVector3::msAxisY.x;
      v20 = UFG::qVector3::msAxisY.y;
      z_low = (__m128)LODWORD(UFG::qVector3::msAxisY.z);
    }
    v22 = 0;
    v23 = v10 + 8;
    v24 = (float)(v20 * v18) - (float)(z_low.m128_f32[0] * v17);
    z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v16) - (float)(x * v18);
    v25 = (float)(x * v17) - (float)(v20 * v16);
    v26 = z_low;
    v26.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v24 * v24)) + (float)(v25 * v25);
    v27 = radius / _mm_sqrt_ps(v26).m128_f32[0];
    v28 = v27 * v25;
    v29 = v27 * z_low.m128_f32[0];
    v30 = v27 * v24;
    do
    {
      UFG::qRotationMatrixAxis(&dest, &axis, (float)v22 * 0.20943952);
      v31 = (float)((float)((float)(dest.v1.y * v29) + (float)(dest.v0.y * v30)) + (float)(dest.v2.y * v28)) + centre->y;
      v32 = (float)((float)((float)(dest.v1.z * v29) + (float)(dest.v0.z * v30)) + (float)(dest.v2.z * v28)) + centre->z;
      *((float *)v23 - 2) = (float)((float)((float)(dest.v1.x * v29) + (float)(dest.v0.x * v30))
                                  + (float)(dest.v2.x * v28))
                          + centre->x;
      *((float *)v23 - 1) = v31;
      *(float *)v23 = v32;
      *((_DWORD *)v23 + 9) = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
      *((_WORD *)v23 + 2) = 0;
      ++v22;
      *((_WORD *)v23 + 3) = 0;
      v23 += 48;
    }
    while ( v22 <= 30 );
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x1502048u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, (Render::vDynamic *)v10, 31);
  }
}

// File Line: 2192
// RVA: 0x10490
void __fastcall Render::View::DrawCross(Render::View *this, UFG::qVector3 *vPosition, UFG::DrawInfo *info)
{
  float x; // xmm5_4
  float y; // xmm4_4
  float mScale; // xmm6_4
  float z; // xmm1_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm5_4
  float v13; // xmm4_4
  float v14; // xmm10_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  UFG::qVector3 end; // [rsp+28h] [rbp-29h] BYREF
  UFG::qVector3 start; // [rsp+34h] [rbp-1Dh] BYREF

  x = vPosition->x;
  y = vPosition->y;
  mScale = info->mScale;
  z = vPosition->z;
  end.x = vPosition->x + (float)((float)(UFG::qVector3::msAxisX.x * mScale) * 0.5);
  end.y = y + (float)((float)(UFG::qVector3::msAxisX.y * mScale) * 0.5);
  start.x = x - (float)((float)(UFG::qVector3::msAxisX.x * mScale) * 0.5);
  end.z = z + (float)((float)(UFG::qVector3::msAxisX.z * mScale) * 0.5);
  start.y = y - (float)((float)(UFG::qVector3::msAxisX.y * mScale) * 0.5);
  start.z = z - (float)((float)(UFG::qVector3::msAxisX.z * mScale) * 0.5);
  Render::View::DrawSegment(this, (UFG::qVector3 *)&start.z, (UFG::qVector3 *)&end.z, info, &UFG::qMatrix44::msIdentity);
  v10 = info->mScale;
  v11 = vPosition->x;
  v12 = vPosition->y;
  v13 = vPosition->z;
  start.x = vPosition->x + (float)((float)(UFG::qVector3::msAxisY.x * v10) * 0.5);
  start.z = v13 + (float)((float)(UFG::qVector3::msAxisY.z * v10) * 0.5);
  start.y = v12 + (float)((float)(UFG::qVector3::msAxisY.y * v10) * 0.5);
  end.x = v11 - (float)((float)(UFG::qVector3::msAxisY.x * v10) * 0.5);
  end.y = v12 - (float)((float)(UFG::qVector3::msAxisY.y * v10) * 0.5);
  end.z = v13 - (float)((float)(UFG::qVector3::msAxisY.z * v10) * 0.5);
  Render::View::DrawSegment(this, &end, &start, info, &UFG::qMatrix44::msIdentity);
  v14 = info->mScale;
  v15 = vPosition->x;
  v16 = vPosition->y;
  v17 = vPosition->z;
  start.x = vPosition->x + (float)((float)(UFG::qVector3::msAxisZ.x * v14) * 0.5);
  start.y = v16 + (float)((float)(UFG::qVector3::msAxisZ.y * v14) * 0.5);
  start.z = v17 + (float)((float)(UFG::qVector3::msAxisZ.z * v14) * 0.5);
  end.x = v15 - (float)((float)(v14 * UFG::qVector3::msAxisZ.x) * 0.5);
  end.y = v16 - (float)((float)(v14 * UFG::qVector3::msAxisZ.y) * 0.5);
  end.z = v17 - (float)((float)(v14 * UFG::qVector3::msAxisZ.z) * 0.5);
  Render::View::DrawSegment(this, &end, &start, info, &UFG::qMatrix44::msIdentity);
}

// File Line: 2220
// RVA: 0xFF30
void __fastcall Render::View::DrawBox(
        Render::View *this,
        UFG::qVector3 *boxMin,
        UFG::qVector3 *boxMax,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *xform)
{
  char *v9; // r14
  unsigned int v10; // edx
  float z; // xmm1_4
  float y; // xmm0_4
  int v13; // edi
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float x; // eax
  float v21; // xmm1_4
  float v22; // eax
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // eax
  float v29; // xmm1_4
  float v30; // eax
  float v31; // xmm2_4
  float v32; // eax
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  float v37; // eax
  float v38; // eax
  float v39; // xmm1_4
  float v40; // eax
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4

  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x300u, 0x10u);
  if ( v9 )
  {
    v10 = 1660426324;
    if ( info->mFaceCull )
    {
      if ( info->mDepthBuffer )
        v10 = 543723269;
      else
        v10 = 206781021;
    }
    else if ( info->mDepthBuffer )
    {
      v10 = 1099738947;
    }
    Render::View::CreateSimpleMaterial(0xB11369EB, v10, info->mAlphaBlend, info->mDepthBias);
    z = boxMax->z;
    y = boxMax->y;
    v13 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
    *(float *)v9 = boxMax->x;
    *((_DWORD *)v9 + 11) = v13;
    *((float *)v9 + 1) = y;
    *((float *)v9 + 2) = z;
    v14 = boxMin->z;
    v15 = boxMax->y;
    *((_DWORD *)v9 + 12) = LODWORD(boxMax->x);
    *((float *)v9 + 14) = v14;
    *((_DWORD *)v9 + 23) = v13;
    *((float *)v9 + 13) = v15;
    v16 = boxMax->y;
    v17 = boxMin->z;
    *((_DWORD *)v9 + 24) = LODWORD(boxMin->x);
    *((float *)v9 + 25) = v16;
    *((_DWORD *)v9 + 35) = v13;
    *((float *)v9 + 26) = v17;
    v18 = boxMax->z;
    v19 = boxMax->y;
    *((_DWORD *)v9 + 36) = LODWORD(boxMin->x);
    *((float *)v9 + 38) = v18;
    *((_DWORD *)v9 + 47) = v13;
    *((float *)v9 + 37) = v19;
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, (Render::vDynamic *)v9, 4);
    x = boxMax->x;
    v21 = boxMin->z;
    *((_DWORD *)v9 + 49) = LODWORD(boxMax->y);
    *((float *)v9 + 50) = v21;
    *((float *)v9 + 48) = x;
    *((_DWORD *)v9 + 59) = v13;
    v22 = boxMax->x;
    v23 = boxMin->z;
    *((_DWORD *)v9 + 61) = LODWORD(boxMin->y);
    *((float *)v9 + 62) = v23;
    *((_DWORD *)v9 + 71) = v13;
    *((float *)v9 + 60) = v22;
    v24 = boxMin->z;
    v25 = boxMin->y;
    *((_DWORD *)v9 + 72) = LODWORD(boxMin->x);
    *((float *)v9 + 73) = v25;
    *((float *)v9 + 74) = v24;
    *((_DWORD *)v9 + 83) = v13;
    v26 = boxMin->z;
    v27 = boxMax->y;
    *((_DWORD *)v9 + 84) = LODWORD(boxMin->x);
    *((_DWORD *)v9 + 95) = v13;
    *((float *)v9 + 85) = v27;
    *((float *)v9 + 86) = v26;
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 4, 4);
    v28 = boxMax->x;
    v29 = boxMin->z;
    *((_DWORD *)v9 + 97) = LODWORD(boxMin->y);
    *((float *)v9 + 98) = v29;
    *((float *)v9 + 96) = v28;
    *((_DWORD *)v9 + 107) = v13;
    v30 = boxMax->x;
    v31 = boxMax->z;
    *((_DWORD *)v9 + 109) = LODWORD(boxMin->y);
    *((float *)v9 + 110) = v31;
    *((_DWORD *)v9 + 119) = v13;
    *((float *)v9 + 108) = v30;
    v32 = boxMin->x;
    v33 = boxMin->y;
    v34 = boxMax->z;
    *((_DWORD *)v9 + 131) = v13;
    *((float *)v9 + 120) = v32;
    *((float *)v9 + 121) = v33;
    *((float *)v9 + 122) = v34;
    v35 = boxMin->z;
    v36 = boxMin->y;
    v37 = boxMin->x;
    *((_DWORD *)v9 + 143) = v13;
    *((float *)v9 + 133) = v36;
    *((float *)v9 + 134) = v35;
    *((float *)v9 + 132) = v37;
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 8, 4);
    v38 = boxMax->x;
    v39 = boxMax->z;
    *((_DWORD *)v9 + 145) = LODWORD(boxMin->y);
    *((float *)v9 + 146) = v39;
    *((float *)v9 + 144) = v38;
    *((_DWORD *)v9 + 155) = v13;
    v40 = boxMax->x;
    v41 = boxMax->z;
    *((_DWORD *)v9 + 157) = LODWORD(boxMax->y);
    *((float *)v9 + 158) = v41;
    *((_DWORD *)v9 + 167) = v13;
    *((float *)v9 + 156) = v40;
    v42 = boxMax->y;
    v43 = boxMax->z;
    *((_DWORD *)v9 + 168) = LODWORD(boxMin->x);
    *((float *)v9 + 169) = v42;
    *((float *)v9 + 170) = v43;
    *((_DWORD *)v9 + 179) = v13;
    v44 = boxMax->z;
    v45 = boxMin->y;
    *((_DWORD *)v9 + 180) = LODWORD(boxMin->x);
    *((float *)v9 + 181) = v45;
    *((float *)v9 + 182) = v44;
    *((_DWORD *)v9 + 191) = v13;
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, (Render::vDynamic *)v9 + 12, 4);
  }
}

// File Line: 2511
// RVA: 0x141A0
void __fastcall Render::View::DrawIcosahedronSolid(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info)
{
  int v6; // ebx
  __m128 v7; // xmm0
  float v8; // xmm8_4
  float v9; // xmm9_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm7_4
  float v14; // xmm6_4
  float v15; // xmm8_4
  char *v16; // rax
  __int64 v17; // rcx
  char *v18; // rax
  int v19; // ebx
  CB_ColourBiasScale *v20; // rdx
  char *v21; // rax
  float r; // ecx
  float b; // ecx
  Illusion::SubmitContext *mSubmitContext; // rax
  unsigned int v25; // edx
  Illusion::Material *SimpleMaterial; // rax
  Illusion::Material *v27; // rbx

  v6 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
  if ( !UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, spVerts_0) || sColourSolidV != v6 )
  {
    v7 = _mm_sqrt_ps((__m128)LODWORD(FLOAT_5_0));
    v7.m128_f32[0] = (float)(v7.m128_f32[0] * 2.0) + 10.0;
    v8 = 1.0 / (float)(_mm_sqrt_ps(v7).m128_f32[0] * 0.1545085);
    v9 = v8 * 0.309017;
    v10 = v8 * 0.5;
    v11 = v9;
    v12 = v9 * -0.5;
    v13 = v11 * 0.5;
    v14 = v10 * -0.5;
    v15 = v10 * 0.5;
    v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB40u, 0x10u);
    sColourSolidV = v6;
    *(_DWORD *)v16 = 0;
    spVerts_0 = (Render::vDynamic *)v16;
    *((float *)v16 + 1) = v13;
    *((float *)v16 + 2) = v14;
    *((float *)v16 + 12) = v13;
    *((float *)v16 + 13) = v15;
    *((_DWORD *)v16 + 14) = 0;
    *((_DWORD *)v16 + 26) = 0;
    *((float *)v16 + 24) = v12;
    *((float *)v16 + 25) = v15;
    *((_DWORD *)v16 + 36) = 0;
    *((float *)v16 + 37) = v13;
    *((float *)v16 + 38) = v15;
    *((_DWORD *)v16 + 50) = 0;
    *((float *)v16 + 48) = v12;
    *((float *)v16 + 49) = v15;
    *((float *)v16 + 60) = v13;
    *((_DWORD *)v16 + 62) = 0;
    *((float *)v16 + 61) = v15;
    *((float *)v16 + 73) = v13;
    *((float *)v16 + 74) = v15;
    *((_DWORD *)v16 + 72) = 0;
    *((_DWORD *)v16 + 84) = 0;
    *((float *)v16 + 85) = v12;
    *((float *)v16 + 86) = v15;
    *((float *)v16 + 96) = v14;
    *((_DWORD *)v16 + 97) = 0;
    *((float *)v16 + 98) = v13;
    *((float *)v16 + 109) = v13;
    *((float *)v16 + 110) = v15;
    *((_DWORD *)v16 + 108) = 0;
    *((_DWORD *)v16 + 121) = 0;
    *((float *)v16 + 120) = v15;
    *((float *)v16 + 122) = v13;
    *((float *)v16 + 133) = v12;
    *((_DWORD *)v16 + 132) = 0;
    *((float *)v16 + 134) = v15;
    *((float *)v16 + 145) = v13;
    *((float *)v16 + 146) = v14;
    *((_DWORD *)v16 + 144) = 0;
    *((_DWORD *)v16 + 156) = 0;
    *((float *)v16 + 157) = v12;
    *((float *)v16 + 158) = v14;
    *((float *)v16 + 168) = v15;
    *((_DWORD *)v16 + 169) = 0;
    *((float *)v16 + 170) = v12;
    *((float *)v16 + 181) = v13;
    *((float *)v16 + 182) = v14;
    *((_DWORD *)v16 + 180) = 0;
    *((_DWORD *)v16 + 193) = 0;
    *((float *)v16 + 192) = v14;
    *((float *)v16 + 194) = v12;
    *((float *)v16 + 205) = v12;
    *((_DWORD *)v16 + 204) = 0;
    *((float *)v16 + 206) = v14;
    *((float *)v16 + 217) = v12;
    *((float *)v16 + 218) = v15;
    *((_DWORD *)v16 + 216) = 0;
    *((_DWORD *)v16 + 230) = 0;
    *((float *)v16 + 228) = v13;
    *((float *)v16 + 229) = v14;
    *((float *)v16 + 240) = v12;
    *((_DWORD *)v16 + 242) = 0;
    *((float *)v16 + 241) = v14;
    *((float *)v16 + 253) = v12;
    *((float *)v16 + 254) = v14;
    *((_DWORD *)v16 + 252) = 0;
    *((_DWORD *)v16 + 266) = 0;
    *((float *)v16 + 264) = v12;
    *((float *)v16 + 265) = v14;
    *((float *)v16 + 276) = v13;
    *((_DWORD *)v16 + 278) = 0;
    *((float *)v16 + 277) = v14;
    *((float *)v16 + 288) = v12;
    *((float *)v16 + 289) = v15;
    *((_DWORD *)v16 + 290) = 0;
    *((_DWORD *)v16 + 301) = 0;
    *((float *)v16 + 300) = v14;
    *((float *)v16 + 302) = v13;
    *((float *)v16 + 312) = v14;
    *((_DWORD *)v16 + 313) = 0;
    *((float *)v16 + 314) = v12;
    *((float *)v16 + 324) = v12;
    *((float *)v16 + 325) = v14;
    *((_DWORD *)v16 + 326) = 0;
    *((_DWORD *)v16 + 337) = 0;
    *((float *)v16 + 336) = v14;
    *((float *)v16 + 338) = v12;
    *((float *)v16 + 348) = v14;
    *((_DWORD *)v16 + 349) = 0;
    *((float *)v16 + 350) = v13;
    *((float *)v16 + 360) = v13;
    *((float *)v16 + 361) = v15;
    *((_DWORD *)v16 + 362) = 0;
    *((_DWORD *)v16 + 373) = 0;
    *((float *)v16 + 372) = v15;
    *((float *)v16 + 374) = v12;
    *((float *)v16 + 384) = v15;
    *((_DWORD *)v16 + 385) = 0;
    *((float *)v16 + 386) = v13;
    *((float *)v16 + 396) = v13;
    *((float *)v16 + 397) = v14;
    *((_DWORD *)v16 + 398) = 0;
    *((_DWORD *)v16 + 409) = 0;
    *((float *)v16 + 408) = v15;
    *((float *)v16 + 410) = v13;
    *((float *)v16 + 420) = v15;
    *((_DWORD *)v16 + 421) = 0;
    *((float *)v16 + 422) = v12;
    *((float *)v16 + 433) = v13;
    *((float *)v16 + 434) = v15;
    *((_DWORD *)v16 + 432) = 0;
    *((_DWORD *)v16 + 445) = 0;
    *((float *)v16 + 444) = v14;
    *((float *)v16 + 446) = v13;
    *((float *)v16 + 456) = v12;
    *((_DWORD *)v16 + 458) = 0;
    *((float *)v16 + 457) = v15;
    *((float *)v16 + 469) = v13;
    *((float *)v16 + 470) = v15;
    *((_DWORD *)v16 + 468) = 0;
    *((_DWORD *)v16 + 482) = 0;
    *((float *)v16 + 480) = v13;
    *((float *)v16 + 481) = v15;
    *((float *)v16 + 492) = v15;
    *((_DWORD *)v16 + 493) = 0;
    *((float *)v16 + 494) = v13;
    *((float *)v16 + 505) = v13;
    *((float *)v16 + 506) = v14;
    *((_DWORD *)v16 + 504) = 0;
    *((_DWORD *)v16 + 518) = 0;
    *((float *)v16 + 516) = v12;
    *((float *)v16 + 517) = v15;
    *((float *)v16 + 528) = v14;
    *((_DWORD *)v16 + 529) = 0;
    *((float *)v16 + 530) = v12;
    *((float *)v16 + 541) = v13;
    *((float *)v16 + 542) = v14;
    *((_DWORD *)v16 + 540) = 0;
    *((_DWORD *)v16 + 553) = 0;
    v17 = 60i64;
    *((float *)v16 + 552) = v15;
    *((float *)v16 + 554) = v12;
    *((float *)v16 + 564) = v13;
    *((_DWORD *)v16 + 566) = 0;
    v18 = v16 + 44;
    *((float *)v18 + 554) = v15;
    *((float *)v18 + 566) = v12;
    *((float *)v18 + 567) = v14;
    *((_DWORD *)v18 + 565) = 0;
    *((_DWORD *)v18 + 578) = 0;
    *((float *)v18 + 577) = v14;
    *((float *)v18 + 579) = v12;
    *((float *)v18 + 589) = v12;
    *((_DWORD *)v18 + 591) = 0;
    *((float *)v18 + 590) = v14;
    *((float *)v18 + 602) = v12;
    *((float *)v18 + 603) = v14;
    *((_DWORD *)v18 + 601) = 0;
    *((_DWORD *)v18 + 615) = 0;
    *((float *)v18 + 613) = v13;
    *((float *)v18 + 614) = v14;
    *((float *)v18 + 625) = v15;
    *((_DWORD *)v18 + 626) = 0;
    *((float *)v18 + 627) = v12;
    *((float *)v18 + 638) = v12;
    *((float *)v18 + 639) = v15;
    *((_DWORD *)v18 + 637) = 0;
    *((_DWORD *)v18 + 651) = 0;
    *((float *)v18 + 649) = v12;
    *((float *)v18 + 650) = v14;
    *((float *)v18 + 661) = v14;
    *((_DWORD *)v18 + 662) = 0;
    *((float *)v18 + 663) = v13;
    *((float *)v18 + 674) = v12;
    *((float *)v18 + 675) = v15;
    *((_DWORD *)v18 + 673) = 0;
    *((_DWORD *)v18 + 686) = 0;
    *((float *)v18 + 685) = v15;
    *((float *)v18 + 687) = v13;
    *((float *)v18 + 697) = v13;
    *((_DWORD *)v18 + 699) = 0;
    *((float *)v18 + 698) = v14;
    do
    {
      *(_DWORD *)v18 = v6;
      v18 += 48;
      --v17;
    }
    while ( v17 );
  }
  v19 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
  if ( sColourSolidB == v19 && UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, pSolidColourBias) )
  {
    v20 = pSolidColourBias;
  }
  else
  {
    v21 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
    r = info->mColour1.r;
    sColourSolidB = v19;
    *((float *)v21 + 4) = r;
    v20 = (CB_ColourBiasScale *)v21;
    *((_DWORD *)v21 + 5) = LODWORD(info->mColour1.g);
    b = info->mColour1.b;
    pSolidColourBias = (CB_ColourBiasScale *)v21;
    *((float *)v21 + 6) = b;
    *((_DWORD *)v21 + 7) = LODWORD(info->mColour1.a);
    *(_QWORD *)v21 = 0i64;
    *((_QWORD *)v21 + 1) = 0i64;
  }
  mSubmitContext = this->mSubmitContext;
  mSubmitContext->mStateValues.mSetValueMask.mFlags[0] |= 0x4000ui64;
  mSubmitContext->mStateValues.mParamValues[14] = v20;
  v25 = 1660426324;
  if ( info->mFaceCull )
  {
    if ( info->mDepthBuffer )
      v25 = 543723269;
    else
      v25 = 206781021;
  }
  else if ( info->mDepthBuffer )
  {
    v25 = 1099738947;
  }
  SimpleMaterial = Render::View::CreateSimpleMaterial(0xB11369EB, v25, info->mAlphaBlend, info->mDepthBias);
  SimpleMaterial->mStateBlockMask.mFlags[0] |= 0x4000ui64;
  v27 = SimpleMaterial;
  Render::View::ScaleToFit(this, xform, info->mScale, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(this, DebugPrim_Triangle, spVerts_0, 60);
  v27->mStateBlockMask.mFlags[0] &= ~0x4000ui64;
}

// File Line: 2620
// RVA: 0x14E00
void __fastcall Render::View::DrawSphere(Render::View *this, UFG::qMatrix44 *xform, UFG::DrawInfo *info)
{
  float g; // xmm1_4
  bool mFaceCull; // bl
  bool mDepthBuffer; // r12
  float b; // xmm0_4
  float a; // xmm1_4
  float mScale; // xmm0_4
  __int128 x_low; // xmm13
  float x; // xmm0_4
  __m128 y_low; // xmm14
  __int128 z_low; // xmm15
  float y; // xmm0_4
  float v17; // xmm1_4
  float r; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm10_4
  __m128 v21; // xmm9
  float v22; // xmm11_4
  __m128 v23; // xmm2
  float v24; // xmm1_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  __m128 v28; // xmm8
  float v29; // xmm3_4
  __m128 v30; // xmm1
  __m128 v31; // xmm5
  __m128 v32; // xmm2
  float v33; // xmm4_4
  __m128 v34; // xmm3
  float v35; // xmm1_4
  float v36; // xmm3_4
  __m128 v37; // xmm12
  float v38; // xmm2_4
  __m128 v39; // xmm4
  float v40; // xmm1_4
  float v41; // xmm11_4
  float v42; // xmm12_4
  unsigned int v43; // esi
  Render::vDynamic *VertsCircle; // r15
  unsigned int v45; // edx
  float v46; // xmm9_4
  float v47; // xmm1_4
  float v48; // xmm4_4
  __m128 v49; // xmm3
  float v50; // xmm8_4
  float v51; // xmm14_4
  __m128 v52; // xmm2
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm8_4
  float v56; // xmm4_4
  __int128 v57; // xmm5
  float v58; // xmm8_4
  __m128 v59; // xmm2
  float v60; // xmm8_4
  __m128 v61; // xmm3
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm3_4
  __m128 v66; // xmm4
  __m128 v67; // xmm5
  float v68; // xmm7_4
  Render::vDynamic *v69; // r15
  int v70; // eax
  UFG::qMatrix44 xforma; // [rsp+40h] [rbp-C0h] BYREF
  float scale; // [rsp+80h] [rbp-80h]
  float z; // [rsp+84h] [rbp-7Ch]
  float v74; // [rsp+88h] [rbp-78h]
  void (__fastcall *mPreDrawCallback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+90h] [rbp-70h]
  UFG::DrawInfo infoa; // [rsp+98h] [rbp-68h] BYREF
  bool mDepthBias; // [rsp+1B8h] [rbp+B8h]
  float v78; // [rsp+1C8h] [rbp+C8h]

  g = info->mColour2.g;
  mFaceCull = info->mFaceCull;
  mDepthBuffer = info->mDepthBuffer;
  infoa.mColour2.r = info->mColour2.r;
  b = info->mColour2.b;
  infoa.mColour2.g = g;
  infoa.mFaceCull = mFaceCull;
  a = info->mColour2.a;
  infoa.mColour2.b = b;
  mScale = info->mScale;
  infoa.mDepthBuffer = mDepthBuffer;
  infoa.mAlphaBlend = AlphaState_none;
  x_low = LODWORD(xform->v2.x);
  scale = mScale;
  infoa.mScale = mScale;
  mDepthBias = info->mDepthBias;
  infoa.mDepthBias = mDepthBias;
  x = xform->v3.x;
  y_low = (__m128)LODWORD(xform->v2.y);
  z_low = LODWORD(xform->v2.z);
  mPreDrawCallback = info->mPreDrawCallback;
  infoa.mPreDrawCallback = mPreDrawCallback;
  v78 = x;
  y = xform->v3.y;
  infoa.mColour2.a = a;
  v17 = info->mColour2.g;
  v74 = y;
  z = xform->v3.z;
  r = info->mColour2.r;
  infoa.mColour1.g = v17;
  v19 = info->mColour2.a;
  infoa.mColour1.r = r;
  infoa.mColour1.b = info->mColour2.b;
  infoa.mColour1.a = v19;
  Render::View::DrawCircle(this, xform, &infoa, 0x40u);
  v20 = xform->v1.y;
  v21 = (__m128)LODWORD(xform->v1.x);
  v22 = xform->v1.z;
  v23 = v21;
  v23.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v20 * v20)) + (float)(v22 * v22);
  if ( v23.m128_f32[0] == 0.0 )
    v24 = 0.0;
  else
    v24 = 1.0 / _mm_sqrt_ps(v23).m128_f32[0];
  v25 = v21.m128_f32[0] * v24;
  v26 = v20 * v24;
  v27 = v22 * v24;
  v28 = y_low;
  xforma.v0.w = 0.0;
  xforma.v0.x = v25;
  xforma.v0.y = v26;
  xforma.v0.z = v27;
  v28.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(*(float *)&x_low * *(float *)&x_low))
                  + (float)(*(float *)&z_low * *(float *)&z_low);
  if ( v28.m128_f32[0] == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
  v30 = y_low;
  v32 = (__m128)z_low;
  v30.m128_f32[0] = y_low.m128_f32[0] * v29;
  v31 = v30;
  v31.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * v29) * v27) - (float)((float)(*(float *)&z_low * v29) * v26);
  v32.m128_f32[0] = (float)((float)(*(float *)&z_low * v29) * v25) - (float)((float)(*(float *)&x_low * v29) * v27);
  v33 = (float)((float)(*(float *)&x_low * v29) * v26) - (float)((float)(y_low.m128_f32[0] * v29) * v25);
  v34 = v32;
  v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v31.m128_f32[0] * v31.m128_f32[0]))
                  + (float)(v33 * v33);
  if ( v34.m128_f32[0] == 0.0 )
    v35 = 0.0;
  else
    v35 = 1.0 / _mm_sqrt_ps(v34).m128_f32[0];
  v31.m128_f32[0] = v31.m128_f32[0] * v35;
  xforma.v1.w = 0.0;
  xforma.v1.z = v33 * v35;
  xforma.v1.y = v32.m128_f32[0] * v35;
  LODWORD(xforma.v1.x) = v31.m128_i32[0];
  v37 = v31;
  v36 = (float)((float)(v33 * v35) * v26) - (float)((float)(v32.m128_f32[0] * v35) * v27);
  v37.m128_f32[0] = (float)(v31.m128_f32[0] * v27) - (float)((float)(v33 * v35) * v25);
  v38 = (float)((float)(v32.m128_f32[0] * v35) * v25) - (float)(v31.m128_f32[0] * v26);
  v39 = v37;
  v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v36 * v36)) + (float)(v38 * v38);
  if ( v39.m128_f32[0] == 0.0 )
    v40 = 0.0;
  else
    v40 = 1.0 / _mm_sqrt_ps(v39).m128_f32[0];
  v41 = v74;
  xforma.v2.w = 0.0;
  xforma.v3.w = 1.0;
  xforma.v2.y = v37.m128_f32[0] * v40;
  v42 = z;
  xforma.v3.x = v78;
  xforma.v3.z = z;
  xforma.v2.x = v36 * v40;
  xforma.v2.z = v38 * v40;
  xforma.v3.y = v74;
  v43 = 206781021;
  VertsCircle = `anonymous namespace::GetVertsCircle(64, &infoa.mColour1);
  if ( mFaceCull )
  {
    v45 = 206781021;
    if ( mDepthBuffer )
      v45 = 543723269;
  }
  else
  {
    v45 = 1660426324;
    if ( mDepthBuffer )
      v45 = 1099738947;
  }
  v46 = scale;
  Render::View::CreateSimpleMaterial(0xB11369EB, v45, 0x2782CCE6u, mDepthBias);
  Render::View::ScaleToFit(this, &xforma, scale, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, VertsCircle + 1, 65);
  if ( v28.m128_f32[0] == 0.0 )
    v47 = 0.0;
  else
    v47 = 1.0 / _mm_sqrt_ps(v28).m128_f32[0];
  v48 = xform->v0.y;
  v49 = (__m128)LODWORD(xform->v0.x);
  v50 = xform->v0.z;
  *(float *)&x_low = *(float *)&x_low * v47;
  v51 = y_low.m128_f32[0] * v47;
  *(float *)&z_low = *(float *)&z_low * v47;
  xforma.v0.w = 0.0;
  v52 = v49;
  LODWORD(xforma.v0.x) = x_low;
  xforma.v0.y = v51;
  LODWORD(xforma.v0.z) = z_low;
  v52.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48)) + (float)(v50 * v50);
  if ( v52.m128_f32[0] == 0.0 )
    v53 = 0.0;
  else
    v53 = 1.0 / _mm_sqrt_ps(v52).m128_f32[0];
  v54 = v49.m128_f32[0] * v53;
  v55 = v50 * v53;
  v56 = v48 * v53;
  v57 = z_low;
  v59 = (__m128)x_low;
  v59.m128_f32[0] = *(float *)&x_low * v55;
  *(float *)&v57 = (float)(*(float *)&z_low * v56) - (float)(v51 * v55);
  v58 = v51 * v54;
  v59.m128_f32[0] = v59.m128_f32[0] - (float)(*(float *)&z_low * v54);
  v61 = v59;
  v60 = v58 - (float)(*(float *)&x_low * v56);
  v61.m128_f32[0] = (float)((float)(v59.m128_f32[0] * v59.m128_f32[0]) + (float)(*(float *)&v57 * *(float *)&v57))
                  + (float)(v60 * v60);
  if ( v61.m128_f32[0] == 0.0 )
    v62 = 0.0;
  else
    v62 = 1.0 / _mm_sqrt_ps(v61).m128_f32[0];
  *(float *)&v57 = *(float *)&v57 * v62;
  xforma.v1.w = 0.0;
  v66 = (__m128)v57;
  LODWORD(xforma.v1.x) = v57;
  xforma.v1.y = v59.m128_f32[0] * v62;
  xforma.v1.z = v60 * v62;
  v63 = (float)(v59.m128_f32[0] * v62) * *(float *)&z_low;
  v64 = (float)((float)(v59.m128_f32[0] * v62) * *(float *)&x_low) - (float)(*(float *)&v57 * v51);
  v65 = (float)((float)(v60 * v62) * v51) - v63;
  v66.m128_f32[0] = (float)(*(float *)&v57 * *(float *)&z_low) - (float)((float)(v60 * v62) * *(float *)&x_low);
  v67 = v66;
  v67.m128_f32[0] = (float)((float)(v66.m128_f32[0] * v66.m128_f32[0]) + (float)(v65 * v65)) + (float)(v64 * v64);
  if ( v67.m128_f32[0] == 0.0 )
    v68 = 0.0;
  else
    v68 = 1.0 / _mm_sqrt_ps(v67).m128_f32[0];
  xforma.v3.x = v78;
  xforma.v3.y = v41;
  xforma.v3.z = v42;
  xforma.v2.w = 0.0;
  xforma.v3.w = 1.0;
  xforma.v2.x = v65 * v68;
  xforma.v2.y = v66.m128_f32[0] * v68;
  xforma.v2.z = v64 * v68;
  v69 = `anonymous namespace::GetVertsCircle(64, &infoa.mColour1);
  if ( mFaceCull )
  {
    v70 = 543723269;
  }
  else
  {
    v43 = 1660426324;
    v70 = 1099738947;
  }
  if ( mDepthBuffer )
    v43 = v70;
  Render::View::CreateSimpleMaterial(0xB11369EB, v43, 0x2782CCE6u, mDepthBias);
  Render::View::ScaleToFit(this, &xforma, v46, Fit_scale_adjust_9);
  Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v69 + 1, 65);
  if ( UFG::qColour::Zero.r != info->mColour1.r
    || UFG::qColour::Zero.g != info->mColour1.g
    || UFG::qColour::Zero.b != info->mColour1.b
    || UFG::qColour::Zero.a != info->mColour1.a )
  {
    Render::View::DrawIcosahedronSolid(this, xform, info);
  }
}

// File Line: 2709
// RVA: 0x13A50
void __fastcall Render::View::DrawFrustum(Render::View *this, UFG::qVector4 *frustumPlanes, UFG::qColour *colour)
{
  UFG::qVector4 *v4; // r14
  UFG::ePlaneIntersect v6; // esi
  UFG::ePlaneIntersect v7; // r13d
  UFG::ePlaneIntersect v8; // ebx
  UFG::ePlaneIntersect v9; // eax
  bool v10; // di
  bool v11; // r13
  bool v12; // r14
  bool v13; // si
  bool v14; // al
  float g; // xmm1_4
  float b; // xmm0_4
  float a; // xmm1_4
  float r; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  bool v22; // [rsp+40h] [rbp-C0h]
  UFG::DrawInfo info; // [rsp+48h] [rbp-B8h] BYREF
  UFG::qVector3 ray_pos; // [rsp+80h] [rbp-80h] BYREF
  UFG::qVector3 line_pos; // [rsp+8Ch] [rbp-74h] BYREF
  UFG::qVector3 v26; // [rsp+98h] [rbp-68h] BYREF
  UFG::qVector3 v27; // [rsp+A4h] [rbp-5Ch] BYREF
  UFG::qVector3 ray_dir; // [rsp+B0h] [rbp-50h] BYREF
  UFG::qVector3 line_dir; // [rsp+BCh] [rbp-44h] BYREF
  UFG::qVector3 v30; // [rsp+C8h] [rbp-38h] BYREF
  UFG::qVector3 v31; // [rsp+D4h] [rbp-2Ch] BYREF
  UFG::qVector3 hit_pos_p; // [rsp+E0h] [rbp-20h] BYREF
  UFG::qVector3 start; // [rsp+ECh] [rbp-14h] BYREF
  UFG::qVector3 v34; // [rsp+F8h] [rbp-8h] BYREF
  UFG::qVector3 v35; // [rsp+104h] [rbp+4h] BYREF
  UFG::qVector3 line_points; // [rsp+110h] [rbp+10h] BYREF
  UFG::qVector3 end; // [rsp+11Ch] [rbp+1Ch] BYREF
  UFG::qVector3 v38; // [rsp+128h] [rbp+28h] BYREF
  UFG::qVector3 v39; // [rsp+134h] [rbp+34h] BYREF
  bool v41; // [rsp+188h] [rbp+88h]
  bool v42; // [rsp+198h] [rbp+98h]

  v4 = frustumPlanes + 1;
  v6 = UFG::qIntersectPlanePlane(frustumPlanes + 4, frustumPlanes + 1, &ray_pos, &ray_dir);
  v7 = UFG::qIntersectPlanePlane(frustumPlanes + 4, frustumPlanes + 2, &line_pos, &line_dir);
  v8 = UFG::qIntersectPlanePlane(frustumPlanes + 3, frustumPlanes + 2, &v26, &v30);
  v9 = UFG::qIntersectPlanePlane(frustumPlanes + 3, v4, &v27, &v31);
  if ( v6 == PlaneIntersect_intersect
    && v7 == PlaneIntersect_intersect
    && v8 == PlaneIntersect_intersect
    && v9 == PlaneIntersect_intersect )
  {
    v10 = UFG::qIntersectDirLinePlane(&ray_pos, &ray_dir, frustumPlanes, &hit_pos_p);
    v11 = UFG::qIntersectDirLinePlane(&ray_pos, &ray_dir, frustumPlanes + 5, &line_points);
    v41 = UFG::qIntersectDirLinePlane(&line_pos, &line_dir, frustumPlanes, &start);
    v42 = UFG::qIntersectDirLinePlane(&line_pos, &line_dir, frustumPlanes + 5, &end);
    v22 = UFG::qIntersectDirLinePlane(&v26, &v30, frustumPlanes, &v34);
    v12 = UFG::qIntersectDirLinePlane(&v26, &v30, frustumPlanes + 5, &v38);
    v13 = UFG::qIntersectDirLinePlane(&v27, &v31, frustumPlanes, &v35);
    v14 = UFG::qIntersectDirLinePlane(&v27, &v31, frustumPlanes + 5, &v39);
    if ( v10 && v11 && v41 && v42 && v22 && v12 && v13 && v14 )
    {
      Render::View::DrawDebugConnectedPrimLineStrip(this, &hit_pos_p, 4, colour, &UFG::qMatrix44::msIdentity, 1, 0);
      Render::View::DrawDebugConnectedPrimLineStrip(this, &line_points, 4, colour, &UFG::qMatrix44::msIdentity, 1, 0);
      g = colour->g;
      info.mColour1.r = colour->r;
      b = colour->b;
      info.mColour1.g = g;
      a = colour->a;
      info.mColour1.b = b;
      r = colour->r;
      info.mAlphaBlend = AlphaState_none;
      *(_WORD *)&info.mDepthBuffer = 257;
      info.mColour2.r = r;
      v19 = colour->b;
      info.mColour1.a = a;
      info.mDepthBias = 0;
      info.mPreDrawCallback = 0i64;
      v20 = colour->g;
      info.mColour2.b = v19;
      info.mColour2.g = v20;
      v21 = colour->a;
      LODWORD(info.mScale) = (_DWORD)FLOAT_1_0;
      info.mColour2.a = v21;
      Render::View::DrawSegment(this, &hit_pos_p, &line_points, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(this, &start, &end, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(this, &v34, &v38, &info, &UFG::qMatrix44::msIdentity);
      Render::View::DrawSegment(this, &v35, &v39, &info, &UFG::qMatrix44::msIdentity);
    }
  }
}

// File Line: 2791
// RVA: 0xE830
void __fastcall Render::View::Draw(
        Render::View *this,
        Render::Poly *poly,
        unsigned int texture_name_uid,
        UFG::qMatrix44 *local_world,
        unsigned int raster_state_uid,
        unsigned int alpha_state_uid)
{
  Illusion::Material *SimpleMaterial; // rax

  SimpleMaterial = Render::View::CreateSimpleMaterial(texture_name_uid, raster_state_uid, alpha_state_uid, 0);
  Render::View::Draw(this, poly, SimpleMaterial, local_world);
}

// File Line: 2957
// RVA: 0x10A20
void __fastcall Render::View::DrawDebugPrim(
        Render::View *this,
        Render::DebugPrimType debug_prim_type,
        Render::vDynamic *vertices,
        int num_vertices)
{
  Illusion::SubmitContext *mSubmitContext; // rax
  __int64 p_mStateValues; // r15
  Illusion::StateArgs *p_mStateArgs; // rbx
  Illusion::Material *v10; // r13
  unsigned int v11; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v13; // rax
  Illusion::Primitive *v14; // rdi
  unsigned int v15; // r15d
  char *v16; // rax
  Render::vDynamic *v17; // rsi
  UFG::qMatrix44 *v18; // rsi
  unsigned __int16 v19; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v27; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v28; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v29; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v30; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v31; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v32; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v33; // rax
  Render::cbLocalTransformState arg; // [rsp+10h] [rbp-59h] BYREF
  Render::cbLocalProjectionState dupe_vertex_buffer[2]; // [rsp+38h] [rbp-31h] BYREF
  Illusion::StateValues *v36; // [rsp+B8h] [rbp+4Fh]
  Illusion::Primitive::Type prim_type; // [rsp+C0h] [rbp+57h]
  int num_verticesa; // [rsp+D0h] [rbp+67h]
  Illusion::Material *v39; // [rsp+D8h] [rbp+6Fh]
  UFG::qMatrix44 *vars0; // [rsp+E0h] [rbp+77h]
  void (__fastcall *retaddr)(Illusion::Material *, Render::View *, __int64, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+E8h] [rbp+7Fh]

  mSubmitContext = this->mSubmitContext;
  p_mStateValues = (__int64)&mSubmitContext->mStateValues;
  v36 = &mSubmitContext->mStateValues;
  p_mStateArgs = &mSubmitContext->mStateArgs;
  v10 = v39;
  if ( !v39 )
    v10 = `anonymous namespace::gSimpleMaterial;
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&vertex_decl_handle_0);
    atexit(Render::View::DrawDebugPrim_::_4_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_0.mData )
  {
    v11 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v13, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle_0, 0x3E5FDA3Eu, v11, Inventory);
  }
  v14 = Illusion::Primitive::Create("DrawDebugPrim");
  if ( v14 && vertices )
  {
    if ( UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, vertices) )
    {
      v17 = vertices;
    }
    else
    {
      v15 = 48 * num_vertices;
      v16 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * num_vertices, 0x10u);
      v17 = (Render::vDynamic *)v16;
      if ( !v16 )
        return;
      UFG::qMemCopy(v16, vertices, v15);
      p_mStateValues = (__int64)v36;
    }
    if ( Illusion::Primitive::SetBuffers(
           v14,
           prim_type,
           v17,
           num_verticesa,
           (Illusion::VertexDecl *)vertex_decl_handle_0.mData,
           0i64,
           0,
           1) )
    {
      v18 = vars0;
      if ( vars0 )
      {
        Render::cbLocalTransformState::cbLocalTransformState(
          &arg,
          &this->mSettings->mWorldView,
          &this->mWorldViewProjection,
          vars0);
        dupe_vertex_buffer[0].mPrev = dupe_vertex_buffer;
        dupe_vertex_buffer[0].mNext = dupe_vertex_buffer;
        dupe_vertex_buffer[0].mCallback = 0i64;
        dupe_vertex_buffer[0].mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
        *(_WORD *)&dupe_vertex_buffer[0].mFlags = 1;
        if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
        {
          Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
          Render::cbLocalProjectionState::sStateParamIndex = Param;
          dupe_vertex_buffer[0].mStateParamIndex = Param;
        }
        dupe_vertex_buffer[0].mCached_Remote.m_Stream = 0i64;
        dupe_vertex_buffer[0].mWorldViewProjection = &this->mWorldViewProjection;
        dupe_vertex_buffer[0].mLocalWorld = v18;
        Illusion::StateArgs::Set<Render::cbLocalTransformState>(p_mStateArgs, &arg);
        Illusion::StateArgs::Set<Render::cbLocalProjectionState>(p_mStateArgs, dupe_vertex_buffer);
        if ( retaddr )
          retaddr(v10, this, p_mStateValues, v14, p_mStateArgs);
        Illusion::SubmitContext::Draw(this->mSubmitContext, v14, v10);
        mPrev = dupe_vertex_buffer[0].mPrev;
        mNext = dupe_vertex_buffer[0].mNext;
        dupe_vertex_buffer[0].mPrev->mNext = dupe_vertex_buffer[0].mNext;
        mNext->mPrev = mPrev;
        dupe_vertex_buffer[0].mPrev = dupe_vertex_buffer;
        dupe_vertex_buffer[0].mNext = dupe_vertex_buffer;
        dupe_vertex_buffer[0].mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[dupe_vertex_buffer[0].mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[dupe_vertex_buffer[0].mStateParamIndex] )
        {
          v27 = &p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)dupe_vertex_buffer[0].mStateParamIndex >> 6];
          *v27 &= ~(1i64 << (dupe_vertex_buffer[0].mStateParamIndex & 0x3F));
        }
        v28 = arg.mPrev;
        v29 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v29->mPrev = v28;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
          p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v30 = dupe_vertex_buffer[0].mPrev;
        v31 = dupe_vertex_buffer[0].mNext;
        dupe_vertex_buffer[0].mPrev->mNext = dupe_vertex_buffer[0].mNext;
        v31->mPrev = v30;
        v32 = arg.mPrev;
        v33 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v33->mPrev = v32;
      }
      else
      {
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mCallback = 0i64;
        arg.mStateParamIndex = Render::cbScreenProjectionState::sStateParamIndex;
        *(_WORD *)&arg.mFlags = 1;
        if ( (_WORD)Render::cbScreenProjectionState::sStateParamIndex == 0xFFFF )
        {
          v19 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransform");
          Render::cbScreenProjectionState::sStateParamIndex = v19;
          arg.mStateParamIndex = v19;
        }
        Illusion::StateArgs::Set<Render::cbScreenProjectionState>(p_mStateArgs, (Render::cbScreenProjectionState *)&arg);
        if ( retaddr )
          retaddr(v10, this, p_mStateValues, v14, p_mStateArgs);
        Illusion::SubmitContext::Draw(this->mSubmitContext, v14, v10);
        v20 = arg.mPrev;
        v21 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v21->mPrev = v20;
        arg.mPrev = &arg;
        arg.mNext = &arg;
        arg.mIsSet = 0;
        if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)p_mStateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &p_mStateArgs->mStateArgs[arg.mStateParamIndex] )
          p_mStateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
        v22 = arg.mPrev;
        v23 = arg.mNext;
        arg.mPrev->mNext = arg.mNext;
        v23->mPrev = v22;
        arg.mPrev = &arg;
      }
    }
  }
}

// File Line: 3058
// RVA: 0x10E70
void __fastcall Render::View::DrawDebugPrimAABB(
        Render::View *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        UFG::qColour *colour)
{
  char *v8; // rbp
  float y; // xmm1_4
  float z; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm2_4
  float v32; // xmm0_4
  float x; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  float v48; // xmm1_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  char *v57; // r8
  int v58; // ebx
  __int64 v59; // r11
  Illusion::Material *v60; // rbx
  _WORD *v61; // rdi
  __int64 mOffset; // rax
  _WORD *v63; // rax
  __int64 v64; // rax
  _WORD *v65; // rax
  __int64 v66; // rax
  _WORD *v67; // rax
  __int64 v68; // rax

  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x480u, 0x10u);
  y = min->y;
  z = min->z;
  *(float *)v8 = min->x;
  *((float *)v8 + 1) = y;
  *((float *)v8 + 2) = z;
  v11 = min->y;
  v12 = min->z;
  *((_DWORD *)v8 + 12) = LODWORD(max->x);
  *((float *)v8 + 13) = v11;
  *((float *)v8 + 14) = v12;
  v13 = min->y;
  v14 = min->z;
  *((_DWORD *)v8 + 24) = LODWORD(max->x);
  *((float *)v8 + 25) = v13;
  *((float *)v8 + 26) = v14;
  v15 = max->y;
  v16 = min->z;
  *((_DWORD *)v8 + 36) = LODWORD(max->x);
  *((float *)v8 + 37) = v15;
  *((float *)v8 + 38) = v16;
  v17 = max->y;
  v18 = min->z;
  *((_DWORD *)v8 + 48) = LODWORD(max->x);
  *((float *)v8 + 49) = v17;
  *((float *)v8 + 50) = v18;
  v19 = max->y;
  v20 = min->z;
  *((_DWORD *)v8 + 60) = LODWORD(min->x);
  *((float *)v8 + 61) = v19;
  *((float *)v8 + 62) = v20;
  v21 = max->y;
  v22 = min->z;
  *((_DWORD *)v8 + 72) = LODWORD(min->x);
  *((float *)v8 + 73) = v21;
  *((float *)v8 + 74) = v22;
  v23 = min->y;
  v24 = min->z;
  *((_DWORD *)v8 + 84) = LODWORD(min->x);
  *((float *)v8 + 85) = v23;
  *((float *)v8 + 86) = v24;
  v25 = max->z;
  v26 = min->y;
  *((_DWORD *)v8 + 96) = LODWORD(min->x);
  *((float *)v8 + 97) = v26;
  *((float *)v8 + 98) = v25;
  v27 = min->y;
  v28 = max->z;
  *((_DWORD *)v8 + 108) = LODWORD(max->x);
  *((float *)v8 + 109) = v27;
  *((float *)v8 + 110) = v28;
  v29 = min->y;
  v30 = max->z;
  *((_DWORD *)v8 + 120) = LODWORD(max->x);
  *((float *)v8 + 121) = v29;
  *((float *)v8 + 122) = v30;
  v31 = max->y;
  v32 = max->z;
  *((_DWORD *)v8 + 132) = LODWORD(max->x);
  *((float *)v8 + 133) = v31;
  *((float *)v8 + 134) = v32;
  x = max->x;
  v34 = max->y;
  *((_DWORD *)v8 + 146) = LODWORD(max->z);
  *((float *)v8 + 144) = x;
  *((float *)v8 + 145) = v34;
  v35 = min->x;
  v36 = max->y;
  *((_DWORD *)v8 + 158) = LODWORD(max->z);
  *((float *)v8 + 156) = v35;
  *((float *)v8 + 157) = v36;
  v37 = min->x;
  v38 = max->y;
  *((_DWORD *)v8 + 170) = LODWORD(max->z);
  *((float *)v8 + 168) = v37;
  *((float *)v8 + 169) = v38;
  v39 = min->x;
  v40 = min->y;
  *((_DWORD *)v8 + 182) = LODWORD(max->z);
  *((float *)v8 + 180) = v39;
  *((float *)v8 + 181) = v40;
  v41 = min->x;
  v42 = min->y;
  *((_DWORD *)v8 + 194) = LODWORD(min->z);
  *((float *)v8 + 192) = v41;
  *((float *)v8 + 193) = v42;
  v43 = min->x;
  v44 = min->y;
  *((_DWORD *)v8 + 206) = LODWORD(max->z);
  *((float *)v8 + 204) = v43;
  *((float *)v8 + 205) = v44;
  v45 = min->y;
  v46 = max->x;
  *((_DWORD *)v8 + 218) = LODWORD(min->z);
  *((float *)v8 + 216) = v46;
  *((float *)v8 + 217) = v45;
  v47 = min->y;
  v48 = max->x;
  *((_DWORD *)v8 + 230) = LODWORD(max->z);
  *((float *)v8 + 228) = v48;
  *((float *)v8 + 229) = v47;
  v49 = max->x;
  v50 = max->y;
  *((_DWORD *)v8 + 242) = LODWORD(min->z);
  *((float *)v8 + 240) = v49;
  *((float *)v8 + 241) = v50;
  v51 = max->x;
  v52 = max->y;
  *((_DWORD *)v8 + 254) = LODWORD(max->z);
  *((float *)v8 + 252) = v51;
  *((float *)v8 + 253) = v52;
  v53 = min->x;
  v54 = max->y;
  *((_DWORD *)v8 + 266) = LODWORD(min->z);
  *((float *)v8 + 264) = v53;
  *((float *)v8 + 265) = v54;
  v55 = min->x;
  v56 = max->y;
  *((_DWORD *)v8 + 278) = LODWORD(max->z);
  *((float *)v8 + 276) = v55;
  *((float *)v8 + 277) = v56;
  v57 = v8 + 12;
  v58 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
  v59 = 24i64;
  do
  {
    *((_DWORD *)v57 + 8) = v58;
    *(_WORD *)v57 = 0;
    *((_WORD *)v57 + 1) = 0;
    v57 += 48;
    --v59;
  }
  while ( v59 );
  v60 = `anonymous namespace::gSimpleMaterial;
  v61 = 0i64;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    mOffset = v60->mMaterialUser.mOffset;
    if ( mOffset )
      v63 = (_WORD *)((char *)&v60->mMaterialUser + mOffset);
    else
      v63 = 0i64;
    *v63 |= 0x20u;
  }
  if ( LODWORD(v60[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == 26403030
    && LODWORD(v60[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v60[2].mNumParams,
      (unsigned int)v60[3].mNode.mChild[1],
      0x28E200A2u);
    v64 = v60->mMaterialUser.mOffset;
    if ( v64 )
      v65 = (_WORD *)((char *)&v60->mMaterialUser + v64);
    else
      v65 = 0i64;
    *v65 |= 0x20u;
  }
  if ( *(_DWORD *)&v60[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v60[2].mDebugName[4],
      *((_DWORD *)&v60[2].UFG::qResourceData + 22),
      0x20688F05u);
    v66 = v60->mMaterialUser.mOffset;
    if ( v66 )
      v67 = (_WORD *)((char *)&v60->mMaterialUser + v66);
    else
      v67 = 0i64;
    *v67 |= 0x20u;
  }
  if ( v60[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v60[2],
      (unsigned int)v60[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v68 = v60->mMaterialUser.mOffset;
    if ( v68 )
      v61 = (_WORD *)((char *)&v60->mMaterialUser + v68);
    *v61 |= 0x20u;
  }
  Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, (Render::vDynamic *)v8, 24);
}

// File Line: 3093
// RVA: 0x11970
void __fastcall Render::View::DrawDebugPrimCylinder(
        Render::View *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        const float radius)
{
  char *v6; // r15
  char *v7; // rsi
  char *v8; // r8
  __int128 y_low; // xmm5
  float v10; // xmm3_4
  float v11; // xmm10_4
  float v12; // xmm10_4
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  float v18; // xmm8_4
  float v19; // xmm2_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  int v23; // xmm2_4
  int v24; // xmm5_4
  int v25; // xmm3_4
  __m128 v26; // xmm10
  float v27; // xmm11_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm5_4
  float v31; // xmm12_4
  float v32; // xmm13_4
  __m128 v33; // xmm2
  float v34; // xmm14_4
  float v35; // xmm15_4
  float v36; // xmm10_4
  float v37; // xmm14_4
  float v38; // xmm2_4
  float v39; // xmm9_4
  __m128 v40; // xmm2
  float v41; // xmm0_4
  int v42; // r12d
  float v43; // xmm0_4
  int v44; // r12d
  int v45; // eax
  float v46; // xmm0_4
  float v47; // ecx
  int v48; // r12d
  __m128 v49; // xmm8
  float v50; // xmm13_4
  float x; // xmm14_4
  float v52; // xmm15_4
  char *v53; // rbx
  signed __int64 v54; // rsi
  char *v55; // rdi
  signed __int64 v56; // r15
  float v57; // xmm6_4
  float v58; // xmm0_4
  __m128 v59; // xmm9
  __m128 v60; // xmm8
  __m128 v61; // xmm7
  __m128 v62; // xmm11
  __m128 v63; // xmm1
  unsigned int v64; // edx
  unsigned int v65; // eax
  unsigned int v66; // edx
  unsigned int z_low; // edx
  unsigned int v68; // eax
  unsigned int v69; // edx
  float v70; // xmm1_4
  unsigned int v71; // edx
  __m128 v72; // xmm1
  __int16 v73; // ax
  unsigned int v74; // edx
  unsigned int v75; // edx
  __int16 v76; // ax
  unsigned int v77; // edx
  UFG::qVector3 *v78; // rdx
  unsigned int v79; // edx
  __m128 v80; // xmm1
  __int16 v81; // ax
  unsigned int v82; // edx
  unsigned int v83; // edx
  __int16 v84; // ax
  unsigned int v85; // edx
  int v86; // xmm0_4
  int v87; // xmm1_4
  float v88; // ecx
  __int16 v89; // ax
  int v90; // xmm0_4
  int v91; // xmm1_4
  int v92; // xmm2_4
  int v93; // xmm0_4
  int v94; // xmm0_4
  int v95; // xmm1_4
  int v96; // xmm0_4
  int v97; // xmm1_4
  int v98; // xmm2_4
  int v99; // xmm0_4
  Illusion::Material *v100; // rbx
  _WORD *v101; // r14
  __int64 mOffset; // rax
  _WORD *v103; // rax
  __int64 v104; // rax
  _WORD *v105; // rax
  __int64 v106; // rax
  _WORD *v107; // rax
  __int64 v108; // rax
  _WORD *v109; // rax
  void (__fastcall *v110)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // rdi
  Render::View *v111; // r15
  Illusion::Material *v112; // rbx
  __int64 v113; // rax
  _WORD *v114; // rax
  __int64 v115; // rax
  _WORD *v116; // rax
  __int64 v117; // rax
  _WORD *v118; // rax
  __int64 v119; // rax
  _WORD *v120; // rax
  Illusion::Material *v121; // rbx
  __int64 v122; // rax
  _WORD *v123; // rax
  __int64 v124; // rax
  _WORD *v125; // rax
  __int64 v126; // rax
  _WORD *v127; // rax
  __int64 v128; // rax
  _WORD *v129; // rax
  Illusion::Material *v130; // rbx
  __int64 v131; // rax
  _WORD *v132; // rax
  __int64 v133; // rax
  _WORD *v134; // rax
  __int64 v135; // rax
  _WORD *v136; // rax
  __int64 v137; // rax
  Render::vDynamic *vertices; // [rsp+40h] [rbp-80h]
  char *v139; // [rsp+48h] [rbp-78h]
  UFG::qVector3 v140; // [rsp+50h] [rbp-70h] BYREF
  UFG::qVector3 offset; // [rsp+5Ch] [rbp-64h] BYREF
  unsigned int v142; // [rsp+68h] [rbp-58h]
  float v143; // [rsp+6Ch] [rbp-54h]
  __m128 v144; // [rsp+70h] [rbp-50h]
  __m128 v145; // [rsp+80h] [rbp-40h]
  __m128 v146; // [rsp+90h] [rbp-30h]
  Render::vDynamic *v147; // [rsp+B0h] [rbp-10h]
  Render::vDynamic *v148; // [rsp+B8h] [rbp-8h]
  UFG::qMatrix44 v149; // [rsp+C0h] [rbp+0h] BYREF
  __m128 v150; // [rsp+100h] [rbp+40h]
  __m128 v151; // [rsp+110h] [rbp+50h]
  __m128 v152; // [rsp+120h] [rbp+60h]
  __m128 v153; // [rsp+130h] [rbp+70h]
  UFG::qMatrix44 dest; // [rsp+150h] [rbp+90h] BYREF
  Render::View *v155; // [rsp+280h] [rbp+1C0h]
  UFG::qVector3 *v156; // [rsp+288h] [rbp+1C8h]
  UFG::qVector3 *v157; // [rsp+290h] [rbp+1D0h]
  float v158; // [rsp+298h] [rbp+1D8h]
  float *v159; // [rsp+2A0h] [rbp+1E0h]
  void (__fastcall *vars0)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *); // [rsp+2B0h] [rbp+1F0h]

  v6 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  HIDWORD(vertices) = HIDWORD(v6);
  v139 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v147 = (Render::vDynamic *)v7;
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x7E0u, 0x10u);
  v148 = (Render::vDynamic *)v8;
  y_low = LODWORD(max->y);
  *(float *)&y_low = (float)(*(float *)&y_low - min->y) * 0.5;
  v10 = (float)(max->x - min->x) * 0.5;
  v13 = (__m128)y_low;
  v11 = max->z - min->z;
  v144.m128_f32[0] = v10;
  v12 = v11 * 0.5;
  LODWORD(offset.x) = y_low;
  v143 = v12;
  v13.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v10 * v10)) + (float)(v12 * v12);
  if ( v13.m128_f32[0] == 0.0 )
  {
    v14 = 0i64;
  }
  else
  {
    v14 = (__m128)(unsigned int)FLOAT_1_0;
    v14.m128_f32[0] = 1.0 / _mm_sqrt_ps(v13).m128_f32[0];
  }
  v15 = v14.m128_f32[0];
  v16 = v14.m128_f32[0];
  v14.m128_f32[0] = v14.m128_f32[0] * v12;
  v17 = v15 * *(float *)&y_low;
  v18 = v16 * v10;
  v19 = v14.m128_f32[0] * 0.0;
  if ( COERCE_FLOAT(LODWORD(v17) & _xmm) >= COERCE_FLOAT(v14.m128_i32[0] & _xmm) )
  {
    v22 = v17 - v19;
    v20 = v19 - v18;
    v21 = (float)(v18 * 0.0) - (float)(v17 * 0.0);
  }
  else
  {
    v20 = v19 - (float)(v18 * 0.0);
    v21 = v18 - (float)(v17 * 0.0);
    v22 = (float)(v17 * 0.0) - v14.m128_f32[0];
  }
  v26 = v14;
  v23 = LODWORD(v20) ^ _xmm[0];
  v24 = LODWORD(v22) ^ _xmm[0];
  v25 = LODWORD(v21) ^ _xmm[0];
  v26.m128_f32[0] = (float)(v14.m128_f32[0] * *(float *)&v23) - (float)(v17 * *(float *)&v25);
  v27 = (float)(v18 * *(float *)&v25) - (float)(v14.m128_f32[0] * *(float *)&v24);
  v28 = v18 * *(float *)&v23;
  v33 = v26;
  v29 = (float)(v17 * *(float *)&v24) - v28;
  LODWORD(v30) = COERCE_UNSIGNED_INT((float)(v17 * v29) - (float)(v14.m128_f32[0] * v27)) ^ _xmm[0];
  LODWORD(v31) = COERCE_UNSIGNED_INT((float)(v14.m128_f32[0] * v26.m128_f32[0]) - (float)(v18 * v29)) ^ _xmm[0];
  LODWORD(v32) = COERCE_UNSIGNED_INT((float)(v18 * v27) - (float)(v17 * v26.m128_f32[0])) ^ _xmm[0];
  v33.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
  if ( v33.m128_f32[0] == 0.0 )
    v34 = 0.0;
  else
    v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
  v35 = v34 * v26.m128_f32[0];
  v36 = v34 * v27;
  v37 = v34 * v29;
  v38 = (float)((float)(v30 * v30) + (float)(v31 * v31)) + (float)(v32 * v32);
  if ( v38 == 0.0 )
    v39 = 0.0;
  else
    v39 = 1.0 / fsqrt(v38);
  v40 = 0i64;
  v40.m128_f32[0] = (float)1;
  v144.m128_f32[0] = v39 * v30;
  *(unsigned __int64 *)((char *)v144.m128_u64 + 4) = COERCE_UNSIGNED_INT(v39 * v31);
  v145 = _mm_shuffle_ps(v40, v40, 81);
  v41 = v159[3];
  v146 = _mm_shuffle_ps(v40, v40, 69);
  v150 = _mm_shuffle_ps(v40, v40, 21);
  v146.m128_u64[0] = __PAIR64__(LODWORD(v17), LODWORD(v18));
  v144.m128_u64[1] = COERCE_UNSIGNED_INT(v39 * v32);
  v42 = (int)(float)(v41 * 255.0);
  v43 = v159[2];
  v145.m128_u64[0] = __PAIR64__(LODWORD(v36), LODWORD(v35));
  v44 = ((int)(float)(v43 * 255.0) | (v42 << 8)) << 8;
  v45 = (int)(float)(v159[1] * 255.0);
  v46 = *v159;
  v145.m128_u64[1] = LODWORD(v37);
  v47 = 0.0;
  v140.x = 0.0;
  v146.m128_u64[1] = v14.m128_u32[0];
  v48 = (int)(float)(v46 * 255.0) | ((v45 | v44) << 8);
  *(unsigned __int64 *)((char *)v144.m128_u64 + 4) = 0i64;
  v49 = v150;
  offset.z = 0.0;
  v140.z = 0.0;
  offset.y = 0.0;
  LODWORD(v159) = 0;
  v50 = v39 * v30;
  x = offset.x;
  v52 = v143;
  v142 = 0;
  v53 = v6 + 28;
  v54 = v7 - v6;
  LODWORD(vertices) = 0;
  v55 = v8 + 76;
  v140.y = 0.0;
  v56 = v139 - (char *)vertices;
  LODWORD(vertices) = 0;
  do
  {
    v57 = (float)SLODWORD(v47) * 0.31415927;
    offset.x = cosf(v57) * v158;
    v58 = sinf(v57);
    offset.z = 0.0;
    offset.y = v58 * v158;
    UFG::qTranslationMatrix(&dest, &offset);
    v59 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), v144), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), v145)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), v146)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), v49));
    v60 = _mm_add_ps(
            _mm_mul_ps(v49, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255)),
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), v144), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), v145)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), v146)));
    v61 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(v146, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170)),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), v144), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), v145))),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), v150));
    v62 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(v145, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85)),
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), v144), (__m128)0i64)),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), v146)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), v150));
    UFG::qTranslationMatrix(&v149, v156);
    v151 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)v149.v3));
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v149.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v149.v3));
    v63 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v149.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v149.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v149.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v149.v3));
    *((_DWORD *)v53 - 7) = v63.m128_i32[0];
    *((_DWORD *)v53 - 6) = _mm_shuffle_ps(v63, v63, 85).m128_u32[0];
    v64 = v144.m128_u32[1];
    *((_DWORD *)v53 - 5) = _mm_shuffle_ps(v63, v63, 170).m128_u32[0];
    *((_DWORD *)v53 + 4) = v48;
    if ( v64 <= 0x47FFEFFF )
    {
      if ( v64 >= 0x38800000 )
        v66 = v64 - 939524096;
      else
        v66 = (v64 & 0x7FFFFF | 0x800000) >> (113 - (v64 >> 23));
      v65 = (v66 + ((v66 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v65) = 0x7FFF;
    }
    z_low = LODWORD(v140.z);
    *((_WORD *)v53 - 8) = v65;
    if ( z_low <= 0x47FFEFFF )
    {
      if ( z_low >= 0x38800000 )
        v69 = z_low - 939524096;
      else
        v69 = (z_low & 0x7FFFFF | 0x800000) >> (113 - (z_low >> 23));
      v68 = (v69 + ((v69 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      LOWORD(v68) = 0x7FFF;
    }
    *((_WORD *)v53 - 7) = v68;
    v70 = x + v156->y;
    v140.x = v50 + v156->x;
    v140.y = v70;
    v140.z = v52 + v156->z;
    UFG::qTranslationMatrix(&v149, &v140);
    v151 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)v149.v3));
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v149.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v149.v3));
    v71 = LODWORD(offset.y);
    v72 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v149.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v149.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v149.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v149.v3));
    *(_DWORD *)&v53[v56 - 28] = v72.m128_i32[0];
    *(_DWORD *)&v53[v56 - 20] = _mm_shuffle_ps(v72, v72, 170).m128_u32[0];
    *(_DWORD *)&v53[v56 - 24] = _mm_shuffle_ps(v72, v72, 85).m128_u32[0];
    *(_DWORD *)&v53[v56 + 16] = v48;
    if ( v71 <= 0x47FFEFFF )
    {
      if ( v71 >= 0x38800000 )
        v74 = v71 - 939524096;
      else
        v74 = (v71 & 0x7FFFFF | 0x800000) >> (113 - (v71 >> 23));
      v73 = (unsigned __int16)v159 | ((v74 + ((v74 >> 13) & 1) + 4095) >> 13);
    }
    else
    {
      v73 = (unsigned __int16)v159 | 0x7FFF;
    }
    v75 = v142;
    *(_WORD *)&v53[v56 - 16] = v73;
    if ( v75 <= 0x47FFEFFF )
    {
      if ( v75 >= 0x38800000 )
        v77 = v75 - 939524096;
      else
        v77 = (v75 & 0x7FFFFF | 0x800000) >> (113 - (v75 >> 23));
      v76 = (v77 + ((v77 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v76 = 0x7FFF;
    }
    v78 = v157;
    *(_WORD *)&v53[v56 - 14] = v76;
    UFG::qTranslationMatrix(&v149, v78);
    v79 = LODWORD(v140.y);
    v151 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v59, v59, 255), (__m128)v149.v3));
    v152 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v60, v60, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v60, v60, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v60, v60, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v60, v60, 255), (__m128)v149.v3));
    v80 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v62, v62, 170), (__m128)v149.v2),
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 0), (__m128)v149.v0), (__m128)0i64),
                _mm_mul_ps(_mm_shuffle_ps(v62, v62, 85), (__m128)v149.v1))),
            _mm_mul_ps(_mm_shuffle_ps(v62, v62, 255), (__m128)v149.v3));
    v153 = _mm_add_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), (__m128)v149.v0), (__m128)0i64),
                 _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), (__m128)v149.v1)),
               _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), (__m128)v149.v2)),
             _mm_mul_ps(_mm_shuffle_ps(v61, v61, 255), (__m128)v149.v3));
    *(_DWORD *)&v53[v54 - 28] = v80.m128_i32[0];
    *(_DWORD *)&v53[v54 - 24] = _mm_shuffle_ps(v80, v80, 85).m128_u32[0];
    *(_DWORD *)&v53[v54 - 20] = _mm_shuffle_ps(v80, v80, 170).m128_u32[0];
    *(_DWORD *)&v53[v54 + 16] = v48;
    if ( v79 <= 0x47FFEFFF )
    {
      if ( v79 >= 0x38800000 )
        v82 = v79 - 939524096;
      else
        v82 = (v79 & 0x7FFFFF | 0x800000) >> (113 - (v79 >> 23));
      v81 = (v82 + ((v82 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v81 = 0x7FFF;
    }
    v83 = v144.m128_u32[2];
    *(_WORD *)&v53[v54 - 16] = v81;
    if ( v83 <= 0x47FFEFFF )
    {
      if ( v83 >= 0x38800000 )
        v85 = v83 - 939524096;
      else
        v85 = (v83 & 0x7FFFFF | 0x800000) >> (113 - (v83 >> 23));
      v84 = (v85 + ((v85 >> 13) & 1) + 4095) >> 13;
    }
    else
    {
      v84 = 0x7FFF;
    }
    *(_WORD *)&v53[v54 - 14] = v84;
    v86 = *((_DWORD *)v53 - 6);
    v87 = *((_DWORD *)v53 - 5);
    *((_DWORD *)v55 - 19) = *((_DWORD *)v53 - 7);
    *((_DWORD *)v55 - 18) = v86;
    v49 = v150;
    v88 = v140.x;
    v53 += 48;
    v55 += 96;
    *((_DWORD *)v55 - 41) = v87;
    LODWORD(v47) = LODWORD(v88) + 1;
    *((_WORD *)v55 - 80) = *((_WORD *)v53 - 32);
    v89 = *((_WORD *)v53 - 31);
    v140.x = v47;
    *((_WORD *)v55 - 79) = v89;
    *((_WORD *)v55 - 78) = *((_WORD *)v53 - 30);
    *((_WORD *)v55 - 77) = *((_WORD *)v53 - 29);
    v90 = *((_DWORD *)v53 - 13);
    v91 = *((_DWORD *)v53 - 12);
    *((_DWORD *)v55 - 38) = *((_DWORD *)v53 - 14);
    *((_DWORD *)v55 - 37) = v90;
    *((_DWORD *)v55 - 36) = v91;
    v92 = *((_DWORD *)v53 - 10);
    v93 = *((_DWORD *)v53 - 9);
    *((_DWORD *)v55 - 35) = *((_DWORD *)v53 - 11);
    *((_DWORD *)v55 - 34) = v92;
    *((_DWORD *)v55 - 33) = v93;
    *((_DWORD *)v55 - 32) = *((_DWORD *)v53 - 8);
    v94 = *(_DWORD *)&v53[v54 - 72];
    v95 = *(_DWORD *)&v53[v54 - 68];
    *((_DWORD *)v55 - 31) = *(_DWORD *)&v53[v54 - 76];
    *((_DWORD *)v55 - 30) = v94;
    *((_DWORD *)v55 - 29) = v95;
    *((_WORD *)v55 - 56) = *(_WORD *)&v53[v54 - 64];
    *((_WORD *)v55 - 55) = *(_WORD *)&v53[v54 - 62];
    *((_WORD *)v55 - 54) = *(_WORD *)&v53[v54 - 60];
    *((_WORD *)v55 - 53) = *(_WORD *)&v53[v54 - 58];
    v96 = *(_DWORD *)&v53[v54 - 52];
    v97 = *(_DWORD *)&v53[v54 - 48];
    *((_DWORD *)v55 - 26) = *(_DWORD *)&v53[v54 - 56];
    *((_DWORD *)v55 - 25) = v96;
    *((_DWORD *)v55 - 24) = v97;
    v98 = *(_DWORD *)&v53[v54 - 40];
    v99 = *(_DWORD *)&v53[v54 - 36];
    *((_DWORD *)v55 - 23) = *(_DWORD *)&v53[v54 - 44];
    *((_DWORD *)v55 - 22) = v98;
    *((_DWORD *)v55 - 21) = v99;
    *((_DWORD *)v55 - 20) = *(_DWORD *)&v53[v54 - 32];
  }
  while ( SLODWORD(v47) <= 20 );
  v100 = `anonymous namespace::gSimpleMaterial;
  v101 = 0i64;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    mOffset = v100->mMaterialUser.mOffset;
    if ( mOffset )
      v103 = (_WORD *)((char *)&v100->mMaterialUser + mOffset);
    else
      v103 = 0i64;
    *v103 |= 0x20u;
  }
  if ( LODWORD(v100[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == 26403030
    && LODWORD(v100[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v100[2].mNumParams,
      (unsigned int)v100[3].mNode.mChild[1],
      0x28E200A2u);
    v104 = v100->mMaterialUser.mOffset;
    if ( v104 )
      v105 = (_WORD *)((char *)&v100->mMaterialUser + v104);
    else
      v105 = 0i64;
    *v105 |= 0x20u;
  }
  if ( *(_DWORD *)&v100[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v100[2].mDebugName[4],
      *((_DWORD *)&v100[2].UFG::qResourceData + 22),
      0x20688F05u);
    v106 = v100->mMaterialUser.mOffset;
    if ( v106 )
      v107 = (_WORD *)((char *)&v100->mMaterialUser + v106);
    else
      v107 = 0i64;
    *v107 |= 0x20u;
  }
  if ( v100[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v100[2],
      (unsigned int)v100[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v108 = v100->mMaterialUser.mOffset;
    if ( v108 )
      v109 = (_WORD *)((char *)&v100->mMaterialUser + v108);
    else
      v109 = 0i64;
    *v109 |= 0x20u;
  }
  v110 = vars0;
  v111 = v155;
  Render::View::DrawDebugPrim(v155, DebugPrim_LineStrip, vertices, 21);
  v112 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v113 = v112->mMaterialUser.mOffset;
    if ( v113 )
      v114 = (_WORD *)((char *)&v112->mMaterialUser + v113);
    else
      v114 = 0i64;
    *v114 |= 0x20u;
  }
  if ( LODWORD(v112[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == 26403030
    && LODWORD(v112[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v112[2].mNumParams,
      (unsigned int)v112[3].mNode.mChild[1],
      0x28E200A2u);
    v115 = v112->mMaterialUser.mOffset;
    if ( v115 )
      v116 = (_WORD *)((char *)&v112->mMaterialUser + v115);
    else
      v116 = 0i64;
    *v116 |= 0x20u;
  }
  if ( *(_DWORD *)&v112[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v112[2].mDebugName[4],
      *((_DWORD *)&v112[2].UFG::qResourceData + 22),
      0x20688F05u);
    v117 = v112->mMaterialUser.mOffset;
    if ( v117 )
      v118 = (_WORD *)((char *)&v112->mMaterialUser + v117);
    else
      v118 = 0i64;
    *v118 |= 0x20u;
  }
  if ( v112[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v112[2],
      (unsigned int)v112[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v119 = v112->mMaterialUser.mOffset;
    if ( v119 )
      v120 = (_WORD *)((char *)&v112->mMaterialUser + v119);
    else
      v120 = 0i64;
    *v120 |= 0x20u;
  }
  Render::View::DrawDebugPrim(v111, DebugPrim_LineStrip, 0i64, 21);
  v121 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v122 = v121->mMaterialUser.mOffset;
    if ( v122 )
      v123 = (_WORD *)((char *)&v121->mMaterialUser + v122);
    else
      v123 = 0i64;
    *v123 |= 0x20u;
  }
  if ( LODWORD(v121[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == 26403030
    && LODWORD(v121[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v121[2].mNumParams,
      (unsigned int)v121[3].mNode.mChild[1],
      0x28E200A2u);
    v124 = v121->mMaterialUser.mOffset;
    if ( v124 )
      v125 = (_WORD *)((char *)&v121->mMaterialUser + v124);
    else
      v125 = 0i64;
    *v125 |= 0x20u;
  }
  if ( *(_DWORD *)&v121[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v121[2].mDebugName[4],
      *((_DWORD *)&v121[2].UFG::qResourceData + 22),
      0x20688F05u);
    v126 = v121->mMaterialUser.mOffset;
    if ( v126 )
      v127 = (_WORD *)((char *)&v121->mMaterialUser + v126);
    else
      v127 = 0i64;
    *v127 |= 0x20u;
  }
  if ( v121[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v121[2],
      (unsigned int)v121[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v128 = v121->mMaterialUser.mOffset;
    if ( v128 )
      v129 = (_WORD *)((char *)&v121->mMaterialUser + v128);
    else
      v129 = 0i64;
    *v129 |= 0x20u;
  }
  Render::View::DrawDebugPrim(v111, DebugPrim_LineStrip, v147, 21);
  v130 = `anonymous namespace::gSimpleMaterial;
  if ( LODWORD(`anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[0]) != -1324127765 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&`anonymous namespace::gSimpleMaterial[1].mDebugName[20],
      `anonymous namespace::gSimpleMaterial[1].mStateBlockMask.mFlags[1],
      0xB11369EB);
    v131 = v130->mMaterialUser.mOffset;
    if ( v131 )
      v132 = (_WORD *)((char *)&v130->mMaterialUser + v131);
    else
      v132 = 0i64;
    *v132 |= 0x20u;
  }
  if ( LODWORD(v130[1].mResourceHandles.UFG::qResourceData::mNode.mNext) == 26403030
    && LODWORD(v130[3].mNode.mChild[0]) != 685899938 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v130[2].mNumParams,
      (unsigned int)v130[3].mNode.mChild[1],
      0x28E200A2u);
    v133 = v130->mMaterialUser.mOffset;
    if ( v133 )
      v134 = (_WORD *)((char *)&v130->mMaterialUser + v133);
    else
      v134 = 0i64;
    *v134 |= 0x20u;
  }
  if ( *(_DWORD *)&v130[2].mDebugName[28] != 543723269 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v130[2].mDebugName[4],
      *((_DWORD *)&v130[2].UFG::qResourceData + 22),
      0x20688F05u);
    v135 = v130->mMaterialUser.mOffset;
    if ( v135 )
      v136 = (_WORD *)((char *)&v130->mMaterialUser + v135);
    else
      v136 = 0i64;
    *v136 |= 0x20u;
  }
  if ( v130[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v130[2],
      (unsigned int)v130[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0x2782CCE6u);
    v137 = v130->mMaterialUser.mOffset;
    if ( v137 )
      v101 = (_WORD *)((char *)&v130->mMaterialUser + v137);
    *v101 |= 0x20u;
  }
  vars0 = v110;
  Render::View::DrawDebugPrim(v111, DebugPrim_LineStrip, v148, 42);
} |= 0x20u;
  }
  vars0 = v110;
  Render::View::DrawDebugPrim(v111, DebugPrim_LineStrip, v148, 42);
}

// File Line: 3298
// RVA: 0x12E90
void __fastcall Render::View::DrawDebugPrimSphere(
        Render::View *this,
        UFG::qVector3 *centre,
        const float radius,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world,
        void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  char *v9; // rdi
  char *v10; // rax
  int v11; // ebp
  signed __int64 v12; // rsi
  int v13; // r15d
  float *p_z; // rbx
  signed __int64 v15; // rdi
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm3_4
  float x; // eax
  float v21; // xmm2_4
  float v22; // xmm2_4
  float y; // xmm1_4
  float v24; // xmm7_4
  float z; // xmm0_4
  Render::vDynamic *vertices; // [rsp+70h] [rbp-88h]
  Render::vDynamic *v27; // [rsp+78h] [rbp-80h]
  Render::vDynamic *v28; // [rsp+80h] [rbp-78h]

  vertices = (Render::vDynamic *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v9 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v27 = (Render::vDynamic *)v9;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x3F0u, 0x10u);
  v28 = (Render::vDynamic *)v10;
  if ( vertices && v9 && v10 )
  {
    v11 = 0;
    v12 = v9 - (char *)vertices;
    v13 = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    p_z = &vertices->mPosition.z;
    v15 = v10 - (char *)vertices;
    do
    {
      v16 = (float)v11 * 0.31415927;
      v17 = sinf(v16) * radius;
      v18 = cosf(v16);
      *p_z = v17;
      *(p_z - 2) = 0.0;
      v19 = v18 * radius;
      *(p_z - 1) = v18 * radius;
      x = centre->x;
      v21 = (float)(v18 * radius) + centre->y;
      *p_z = v17 + centre->z;
      *(p_z - 2) = x;
      *(p_z - 1) = v21;
      *((_DWORD *)p_z + 9) = v13;
      *((_WORD *)p_z + 2) = 0;
      *((_WORD *)p_z + 3) = 0;
      *(float *)((char *)p_z + v12 - 8) = v18 * radius;
      *(float *)((char *)p_z + v12) = v17;
      *(float *)((char *)p_z + v12 - 4) = 0.0;
      v22 = v17 + centre->z;
      y = centre->y;
      *(float *)((char *)p_z + v12 - 8) = (float)(v18 * radius) + centre->x;
      *(float *)((char *)p_z + v12) = v22;
      *(float *)((char *)p_z + v12 - 4) = y;
      *(_DWORD *)((char *)p_z + v12 + 36) = v13;
      *(_WORD *)((char *)p_z + v12 + 4) = 0;
      *(_WORD *)((char *)p_z + v12 + 6) = 0;
      *(float *)((char *)p_z + v15 - 8) = v18 * radius;
      *(float *)((char *)p_z + v15 - 4) = v17;
      *(float *)((char *)p_z + v15) = 0.0;
      v24 = v17 + centre->y;
      z = centre->z;
      *(float *)((char *)p_z + v15 - 8) = v19 + centre->x;
      *(float *)((char *)p_z + v15 - 4) = v24;
      *(float *)((char *)p_z + v15) = z;
      *(_DWORD *)((char *)p_z + v15 + 36) = v13;
      *(_WORD *)((char *)p_z + v15 + 4) = 0;
      ++v11;
      *(_WORD *)((char *)p_z + v15 + 6) = 0;
      p_z += 12;
    }
    while ( v11 <= 20 );
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, vertices, 21);
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v27, 21);
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0x2782CCE6u, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_LineStrip, v28, 21);
  }
}

// File Line: 3370
// RVA: 0x134E0
void __fastcall Render::View::DrawDebugPrimTri(
        Render::View *this,
        UFG::qVector3 *aVerts,
        UFG::qColour *colour,
        UFG::qMatrix44 *local_world)
{
  char *v7; // rax
  Render::vDynamic *v8; // rdi
  float x; // xmm6_4
  float y; // xmm3_4
  float v11; // xmm9_4
  float z; // xmm10_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm0_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  __m128 z_low; // xmm5
  float v23; // xmm6_4
  __m128 v24; // xmm4
  float v25; // xmm7_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4

  v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x90u, 0x10u);
  v8 = (Render::vDynamic *)v7;
  z_low = (__m128)LODWORD(aVerts[1].z);
  x = aVerts[1].x;
  y = aVerts[1].y;
  v11 = aVerts->y;
  z = aVerts->z;
  v13 = aVerts[2].x - x;
  v14 = aVerts[2].z - z_low.m128_f32[0];
  v15 = aVerts[2].y - y;
  v16 = x - aVerts->x;
  v17 = y - v11;
  v18 = (float)(v17 * v14) - (float)((float)(z_low.m128_f32[0] - z) * v15);
  v19 = v16 * v14;
  v20 = v16 * v15;
  v21 = 0.0;
  z_low.m128_f32[0] = (float)((float)(z_low.m128_f32[0] - z) * v13) - v19;
  v23 = v20 - (float)(v17 * v13);
  v24 = z_low;
  v24.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v18 * v18)) + (float)(v23 * v23);
  if ( v24.m128_f32[0] != 0.0 )
    v21 = 1.0 / _mm_sqrt_ps(v24).m128_f32[0];
  v25 = v18 * v21;
  v26 = z_low.m128_f32[0] * v21;
  v27 = v23 * v21;
  if ( v7 )
  {
    *(float *)v7 = aVerts->x;
    *((float *)v7 + 1) = v11;
    *((float *)v7 + 2) = z;
    *((_DWORD *)v7 + 11) = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 5) = v25;
    *((float *)v7 + 6) = v26;
    *((float *)v7 + 7) = v27;
    v28 = aVerts[1].y;
    v29 = aVerts[1].z;
    *((_DWORD *)v7 + 12) = LODWORD(aVerts[1].x);
    *((float *)v7 + 13) = v28;
    *((float *)v7 + 14) = v29;
    *((_DWORD *)v7 + 23) = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 17) = v25;
    *((float *)v7 + 18) = v26;
    *((float *)v7 + 19) = v27;
    v30 = aVerts[2].y;
    v31 = aVerts[2].z;
    *((_DWORD *)v7 + 24) = LODWORD(aVerts[2].x);
    *((float *)v7 + 25) = v30;
    *((float *)v7 + 26) = v31;
    *((_DWORD *)v7 + 35) = (int)(float)(colour->r * 255.0) | (((int)(float)(colour->g * 255.0) | (((int)(float)(colour->b * 255.0) | ((int)(float)(colour->a * 255.0) << 8)) << 8)) << 8);
    *((float *)v7 + 29) = v25;
    *((float *)v7 + 30) = v26;
    *((float *)v7 + 31) = v27;
    Render::View::CreateSimpleMaterial(0xB11369EB, 0x20688F05u, 0xA3833FDE, 0);
    Render::View::DrawDebugPrim(this, DebugPrim_Triangle, v8, 3);
  }
}

// File Line: 3422
// RVA: 0x137D0
void __fastcall Render::View::DrawDebugPrimTriStrip(
        Render::View *this,
        UFG::qVector3 *points,
        int num_points,
        UFG::DrawInfo *info,
        UFG::qMatrix44 *local_world)
{
  __int64 v5; // r14
  unsigned int v8; // esi
  char *v10; // rax
  Render::vDynamic *v11; // rbp
  int v12; // ebx
  __int64 v13; // r9
  char *p_z; // rax
  char *v15; // rcx
  unsigned __int64 v16; // rdx
  int v17; // xmm0_4
  int v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm2_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // xmm1_4
  int v25; // xmm2_4
  __int64 v26; // rcx
  __int64 v27; // r8
  float *v28; // rdx
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  unsigned int v32; // edx

  v5 = num_points;
  v8 = 48 * num_points;
  v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 48 * num_points, 0x10u);
  v11 = (Render::vDynamic *)v10;
  if ( v10 )
  {
    v12 = (int)(float)(info->mColour1.r * 255.0) | (((int)(float)(info->mColour1.g * 255.0) | (((int)(float)(info->mColour1.b * 255.0) | ((int)(float)(info->mColour1.a * 255.0) << 8)) << 8)) << 8);
    UFG::qMemSet(v10, 0, v8);
    v13 = 0i64;
    if ( v5 >= 4 )
    {
      p_z = (char *)&v11[1].mPosition.z;
      v15 = (char *)&points[1].z;
      v16 = ((unsigned __int64)(v5 - 4) >> 2) + 1;
      v13 = 4 * v16;
      do
      {
        v17 = *((_DWORD *)v15 - 5);
        v18 = *((_DWORD *)v15 - 4);
        v19 = *((_DWORD *)v15 - 3);
        p_z += 192;
        v15 += 48;
        *((_DWORD *)p_z - 62) = v17;
        *((_DWORD *)p_z - 61) = v18;
        *((_DWORD *)p_z - 60) = v19;
        *((_DWORD *)p_z - 51) = v12;
        v20 = *((_DWORD *)v15 - 13);
        v21 = *((_DWORD *)v15 - 12);
        *((_DWORD *)p_z - 50) = *((_DWORD *)v15 - 14);
        *((_DWORD *)p_z - 49) = v20;
        *((_DWORD *)p_z - 48) = v21;
        *((_DWORD *)p_z - 39) = v12;
        v22 = *((_DWORD *)v15 - 10);
        v23 = *((_DWORD *)v15 - 9);
        *((_DWORD *)p_z - 38) = *((_DWORD *)v15 - 11);
        *((_DWORD *)p_z - 37) = v22;
        *((_DWORD *)p_z - 36) = v23;
        *((_DWORD *)p_z - 27) = v12;
        v24 = *((_DWORD *)v15 - 7);
        v25 = *((_DWORD *)v15 - 6);
        *((_DWORD *)p_z - 26) = *((_DWORD *)v15 - 8);
        *((_DWORD *)p_z - 25) = v24;
        *((_DWORD *)p_z - 24) = v25;
        *((_DWORD *)p_z - 15) = v12;
        --v16;
      }
      while ( v16 );
    }
    if ( v13 < v5 )
    {
      v26 = (__int64)&v11[v13].mPosition.z;
      v27 = v5 - v13;
      v28 = &points[v13].z;
      do
      {
        v29 = *((_DWORD *)v28 - 2);
        v30 = *((_DWORD *)v28 - 1);
        v31 = *(_DWORD *)v28;
        v26 += 48i64;
        v28 += 3;
        *(_DWORD *)(v26 - 56) = v29;
        *(_DWORD *)(v26 - 52) = v30;
        *(_DWORD *)(v26 - 48) = v31;
        *(_DWORD *)(v26 - 12) = v12;
        --v27;
      }
      while ( v27 );
    }
    v32 = 1660426324;
    if ( info->mFaceCull )
    {
      if ( info->mDepthBuffer )
        v32 = 543723269;
      else
        v32 = 206781021;
    }
    else if ( info->mDepthBuffer )
    {
      v32 = 1099738947;
    }
    Render::View::CreateSimpleMaterial(0xB11369EB, v32, info->mAlphaBlend, info->mDepthBias);
    Render::View::DrawDebugPrim(this, DebugPrim_TriangleStrip, v11, v5);
  }
}

// File Line: 3514
// RVA: 0xF8A0
void __fastcall Render::View::DrawAxes(Render::View *this, UFG::qMatrix44 *xform, float scale, bool depthBuffer)
{
  Render::vDynamic *VertsAxes; // rax
  unsigned int v7; // edx
  Render::vDynamic *v8; // r14

  VertsAxes = `anonymous namespace::GetVertsAxes();
  v7 = 1660426324;
  v8 = VertsAxes;
  if ( depthBuffer )
    v7 = 543723269;
  Render::View::CreateSimpleMaterial(0xB11369EB, v7, 0x2782CCE6u, 0);
  Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, v8, 6);
  Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, v8 + 6, 4);
  Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, v8 + 10, 6);
  Render::View::DrawDebugPrim(this, DebugPrim_LineSegment, v8 + 16, 6);
}

