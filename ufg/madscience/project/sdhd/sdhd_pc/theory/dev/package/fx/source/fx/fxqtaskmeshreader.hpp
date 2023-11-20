// File Line: 29
// RVA: 0x1DDFF0
void __fastcall Render::FXqTaskMeshReader::FXqTaskMeshReader(Render::FXqTaskMeshReader *this)
{
  Render::FXqTaskMeshReader *v1; // rbx

  v1 = this;
  this->mModelAddrInMainMem = 0i64;
  this->mModelStream.mName = "<unassigned>";
  this->mModelStream.mMainMemoryAddress = 0i64;
  this->mModelStream.mState = 0;
  this->mMeshStream.mName = "<unassigned>";
  this->mMeshStream.mMainMemoryAddress = 0i64;
  this->mMeshStream.mState = 0;
  `eh vector constructor iterator'(
    this->mVertexBuffers,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  v1->mMemoryStreamer = 0i64;
  *(_QWORD *)&v1->mCurVertexForSequentialEmission = 0i64;
  v1->mIsInitialized = 0;
  v1->mMeshLoadedIndex = -1;
}

// File Line: 58
// RVA: 0x1E20B0
void __fastcall Render::FXqTaskMeshReader::LoadMesh(Render::FXqTaskMeshReader *this, unsigned int meshIndex, float startVertexForSequentialEmission)
{
  Render::FXqTaskMeshReader *v3; // r11
  char *v4; // rcx
  signed __int64 v5; // r9
  void *v6; // rax
  _DWORD *v7; // rcx
  unsigned int v8; // er8

  v3 = this;
  v4 = (char *)this->mModelAddrInMainMem;
  if ( v4 )
  {
    v5 = (signed __int64)&v4[*((_QWORD *)v3->mModelStream.mMainMemoryAddress + 23) + 184];
    v3->mMeshStream.mMainMemoryAddress = (void *)(v5 + *(unsigned int *)(v5 + 8i64 * meshIndex) + 4i64 * meshIndex);
    v3->mMeshLoadedIndex = meshIndex;
  }
  v6 = v3->mMeshStream.mMainMemoryAddress;
  v7 = (_DWORD *)*((_QWORD *)v6 + 14);
  v3->mVertexBuffers[0].mMainMemoryAddress = v7;
  v3->mVertexBuffers[1].mMainMemoryAddress = (void *)*((_QWORD *)v6 + 18);
  v8 = v7[27];
  v3->mNumVerticesInMesh = v8;
  if ( v8 )
  {
    v3->mCurVertexForSequentialEmission = (float)(signed int)((signed int)startVertexForSequentialEmission % v8);
    v3->mpVertexBuffers[0] = (Illusion::Buffer *)v3->mVertexBuffers[0].mMainMemoryAddress;
    v3->mpMainMemoryVertexBuffers[0] = (char *)v3->mVertexBuffers[0].mMainMemoryAddress
                                     + *((_QWORD *)v3->mVertexBuffers[0].mMainMemoryAddress + 12)
                                     + 96;
    v3->mpVertexBuffers[1] = (Illusion::Buffer *)v3->mVertexBuffers[1].mMainMemoryAddress;
    v3->mpMainMemoryVertexBuffers[1] = (char *)v3->mVertexBuffers[1].mMainMemoryAddress
                                     + *((_QWORD *)v3->mVertexBuffers[1].mMainMemoryAddress + 12)
                                     + 96;
  }
}

// File Line: 126
// RVA: 0x1E1E10
void __fastcall Render::FXqTaskMeshReader::GetRandomPointOnTriangle(UFG::qVector3 *triangleVertices, UFG::qVector3 *triangleNormals, int *seed, UFG::qVector3 *outPosition, UFG::qVector3 *outNormal)
{
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rbp
  int *v7; // rbx
  UFG::qVector3 *v8; // rsi
  float v9; // xmm11_4
  float v10; // xmm0_4
  float v11; // xmm12_4
  float v12; // xmm9_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm2_4
  float v18; // xmm5_4
  float v19; // xmm4_4
  float v20; // xmm11_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm12_4
  float v25; // xmm9_4
  float v26; // xmm5_4
  float v27; // xmm11_4
  float v28; // xmm2_4
  float v29; // xmm10_4

  v5 = triangleNormals;
  v6 = outPosition;
  v7 = seed;
  v8 = triangleVertices;
  v9 = UFG::qRandom(1.0, seed);
  v10 = UFG::qRandom(1.0, v7);
  v11 = v10;
  if ( (float)(v10 + v9) > 1.0 )
  {
    v9 = 1.0 - v9;
    v11 = 1.0 - v10;
  }
  v12 = (float)(1.0 - v9) - v11;
  v13 = (float)(v9 * v8->y) + (float)(v11 * v8[1].y);
  v14 = (float)(v9 * v8->z) + (float)(v11 * v8[1].z);
  v15 = v12 * v8[2].y;
  v16 = v12 * v8[2].z;
  v6->x = (float)((float)(v9 * v8->x) + (float)(v11 * v8[1].x)) + (float)(v12 * v8[2].x);
  v6->y = v13 + v15;
  v6->z = v14 + v16;
  v17 = v12 * v5[2].x;
  v18 = v9 * v5->y;
  v19 = v9 * v5->x;
  v20 = v9 * v5->z;
  v21 = v18 + (float)(v11 * v5[1].y);
  v22 = (float)(v19 + (float)(v11 * v5[1].x)) + v17;
  v23 = v12 * v5[2].y;
  v24 = v11 * v5[1].z;
  v25 = v12 * v5[2].z;
  outNormal->x = v22;
  v26 = v21 + v23;
  v27 = (float)(v20 + v24) + v25;
  outNormal->y = v26;
  outNormal->z = v27;
  v28 = (float)((float)(v26 * v26) + (float)(v22 * v22)) + (float)(v27 * v27);
  if ( v28 == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / fsqrt(v28);
  outNormal->z = v27 * v29;
  outNormal->x = v22 * v29;
  outNormal->y = v26 * v29;
}

// File Line: 235
// RVA: 0x1E15D0
UFG::qVector3 *__fastcall Render::FXqTaskMeshReader::DecompressNormalUByte4N(Render::FXqTaskMeshReader *this, UFG::qVector3 *result, unsigned int compressed)
{
  float v3; // xmm2_4
  float v4; // xmm4_4
  __m128 v5; // xmm5
  float v6; // xmm3_4
  __m128 v7; // xmm6
  UFG::qVector3 *v8; // rax

  v5 = 0i64;
  v3 = 0.0;
  v4 = (float)((float)((float)(unsigned __int8)compressed * 0.0039215689) - 0.5) * 2.0;
  v5.m128_f32[0] = (float)((float)((float)BYTE1(compressed) * 0.0039215689) - 0.5) * 2.0;
  v6 = (float)((float)((float)BYTE2(compressed) * 0.0039215689) - 0.5) * 2.0;
  v7 = v5;
  v7.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v4 * v4)) + (float)(v6 * v6);
  if ( v7.m128_f32[0] != 0.0 )
    v3 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v7));
  v8 = result;
  result->z = v6 * v3;
  result->x = v3 * v4;
  result->y = v3 * v5.m128_f32[0];
  return v8;
}

// File Line: 247
// RVA: 0x1E14A0
signed __int64 __fastcall Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(Render::FXqTaskMeshReader *this, Illusion::Buffer **pVBuf, void **mainMemoryVertexData, unsigned int vertexDeclNameUID, unsigned int cur_index, UFG::qVector3 *outPosition, UFG::qVector3 *outNormal)
{
  unsigned int v7; // ebx
  void *v8; // r9
  unsigned int v9; // er11
  unsigned __int64 v10; // r9
  unsigned int v11; // er11
  void *v12; // r10
  Illusion::Buffer *v13; // rax
  unsigned __int64 v14; // r8
  unsigned int v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector3 *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm1_4
  signed __int64 v21; // rax
  UFG::qVector3 result; // [rsp+28h] [rbp-40h]
  UFG::qString v23; // [rsp+38h] [rbp-30h]
  unsigned int v24; // [rsp+80h] [rbp+18h]
  unsigned int v25; // [rsp+84h] [rbp+1Ch]

  v7 = vertexDeclNameUID;
  v8 = *mainMemoryVertexData;
  if ( *mainMemoryVertexData )
  {
    v9 = (_DWORD)v8 + cur_index * (*pVBuf)->mElementByteSize;
    v10 = ((unsigned __int64)v8 + cur_index * (*pVBuf)->mElementByteSize) & 0xFFFFFFFFFFFFFFF0ui64;
    v11 = v9 & 0xF;
  }
  else
  {
    v10 = *(_QWORD *)&result.x;
    v11 = v24;
  }
  v12 = mainMemoryVertexData[1];
  if ( v12 )
  {
    v13 = pVBuf[1];
    v14 = ((unsigned __int64)v12 + cur_index * v13->mElementByteSize) & 0xFFFFFFFFFFFFFFF0ui64;
    v15 = ((_DWORD)v12 + cur_index * v13->mElementByteSize) & 0xF;
  }
  else
  {
    v14 = *(_QWORD *)&result.z;
    v15 = v25;
  }
  if ( v7 == 883623142 )
  {
    v16 = *(float *)(v11 + v10 + 4);
    v17 = *(float *)(v11 + v10 + 8);
    outPosition->x = *(float *)(v11 + v10);
    outPosition->y = v16;
    outPosition->z = v17;
    v18 = Render::FXqTaskMeshReader::DecompressNormalUByte4N(this, &result, *(_DWORD *)(v15 + v14));
    v19 = v18->y;
    v20 = v18->z;
    outNormal->x = v18->x;
    outNormal->y = v19;
    outNormal->z = v20;
    v21 = cur_index;
  }
  else
  {
    UFG::qString::qString(&v23);
    UFG::qString::Format(
      &v23,
      "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
      v7);
    UFG::qString::~qString(&v23);
    v21 = 0xFFFFFFFFi64;
  }
  return v21;
}

