// File Line: 29
// RVA: 0x1DDFF0
void __fastcall Render::FXqTaskMeshReader::FXqTaskMeshReader(Render::FXqTaskMeshReader *this)
{
  this->mModelAddrInMainMem = 0i64;
  this->mModelStream.mName = "<unassigned>";
  this->mModelStream.mMainMemoryAddress = 0i64;
  this->mModelStream.mState = 0;
  this->mMeshStream.mName = "<unassigned>";
  this->mMeshStream.mMainMemoryAddress = 0i64;
  this->mMeshStream.mState = 0;
  `eh vector constructor iterator(
    this->mVertexBuffers,
    0x18ui64,
    2,
    (void (__fastcall *)(void *))UFG::qMemoryStream<UFG::AIInterestComponent,432>::qMemoryStream<UFG::AIInterestComponent,432>);
  this->mMemoryStreamer = 0i64;
  *(_QWORD *)&this->mCurVertexForSequentialEmission = 0i64;
  this->mIsInitialized = 0;
  this->mMeshLoadedIndex = -1;
}

// File Line: 58
// RVA: 0x1E20B0
void __fastcall Render::FXqTaskMeshReader::LoadMesh(
        Render::FXqTaskMeshReader *this,
        unsigned int meshIndex,
        float startVertexForSequentialEmission)
{
  void *mModelAddrInMainMem; // rcx
  __int64 v5; // r9
  void *mMainMemoryAddress; // rax
  _DWORD *v7; // rcx
  unsigned int v8; // r8d

  mModelAddrInMainMem = this->mModelAddrInMainMem;
  if ( mModelAddrInMainMem )
  {
    v5 = (__int64)mModelAddrInMainMem + *((_QWORD *)this->mModelStream.mMainMemoryAddress + 23) + 184;
    this->mMeshStream.mMainMemoryAddress = (void *)(v5 + *(unsigned int *)(v5 + 8i64 * meshIndex) + 4i64 * meshIndex);
    this->mMeshLoadedIndex = meshIndex;
  }
  mMainMemoryAddress = this->mMeshStream.mMainMemoryAddress;
  v7 = (_DWORD *)*((_QWORD *)mMainMemoryAddress + 14);
  this->mVertexBuffers[0].mMainMemoryAddress = v7;
  this->mVertexBuffers[1].mMainMemoryAddress = (void *)*((_QWORD *)mMainMemoryAddress + 18);
  v8 = v7[27];
  this->mNumVerticesInMesh = v8;
  if ( v8 )
  {
    this->mCurVertexForSequentialEmission = (float)(int)((int)startVertexForSequentialEmission % v8);
    this->mpVertexBuffers[0] = (Illusion::Buffer *)this->mVertexBuffers[0].mMainMemoryAddress;
    this->mpMainMemoryVertexBuffers[0] = (char *)this->mVertexBuffers[0].mMainMemoryAddress
                                       + *((_QWORD *)this->mVertexBuffers[0].mMainMemoryAddress + 12)
                                       + 96;
    this->mpVertexBuffers[1] = (Illusion::Buffer *)this->mVertexBuffers[1].mMainMemoryAddress;
    this->mpMainMemoryVertexBuffers[1] = (char *)this->mVertexBuffers[1].mMainMemoryAddress
                                       + *((_QWORD *)this->mVertexBuffers[1].mMainMemoryAddress + 12)
                                       + 96;
  }
}

// File Line: 126
// RVA: 0x1E1E10
void __fastcall Render::FXqTaskMeshReader::GetRandomPointOnTriangle(
        UFG::qVector3 *triangleVertices,
        UFG::qVector3 *triangleNormals,
        unsigned int *seed,
        UFG::qVector3 *outPosition,
        UFG::qVector3 *outNormal)
{
  float v9; // xmm11_4
  float v10; // xmm0_4
  float v11; // xmm12_4
  float v12; // xmm9_4
  float v13; // xmm4_4
  float v14; // xmm3_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm5_4
  float v18; // xmm4_4
  float v19; // xmm11_4
  float v20; // xmm5_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  float v23; // xmm12_4
  float v24; // xmm9_4
  float v25; // xmm5_4
  float v26; // xmm11_4
  float v27; // xmm2_4
  float v28; // xmm10_4

  v9 = UFG::qRandom(1.0, seed);
  v10 = UFG::qRandom(1.0, seed);
  v11 = v10;
  if ( (float)(v10 + v9) > 1.0 )
  {
    v9 = 1.0 - v9;
    v11 = 1.0 - v10;
  }
  v12 = (float)(1.0 - v9) - v11;
  v13 = (float)(v9 * triangleVertices->y) + (float)(v11 * triangleVertices[1].y);
  v14 = (float)(v9 * triangleVertices->z) + (float)(v11 * triangleVertices[1].z);
  v15 = v12 * triangleVertices[2].y;
  v16 = v12 * triangleVertices[2].z;
  outPosition->x = (float)((float)(v9 * triangleVertices->x) + (float)(v11 * triangleVertices[1].x))
                 + (float)(v12 * triangleVertices[2].x);
  outPosition->y = v13 + v15;
  outPosition->z = v14 + v16;
  v17 = v9 * triangleNormals->y;
  v18 = v9 * triangleNormals->x;
  v19 = v9 * triangleNormals->z;
  v20 = v17 + (float)(v11 * triangleNormals[1].y);
  v21 = (float)(v18 + (float)(v11 * triangleNormals[1].x)) + (float)(v12 * triangleNormals[2].x);
  v22 = v12 * triangleNormals[2].y;
  v23 = v11 * triangleNormals[1].z;
  v24 = v12 * triangleNormals[2].z;
  outNormal->x = v21;
  v25 = v20 + v22;
  v26 = (float)(v19 + v23) + v24;
  outNormal->y = v25;
  outNormal->z = v26;
  v27 = (float)((float)(v25 * v25) + (float)(v21 * v21)) + (float)(v26 * v26);
  if ( v27 == 0.0 )
    v28 = 0.0;
  else
    v28 = 1.0 / fsqrt(v27);
  outNormal->z = v26 * v28;
  outNormal->x = v21 * v28;
  outNormal->y = v25 * v28;
}

// File Line: 235
// RVA: 0x1E15D0
UFG::qVector3 *__fastcall Render::FXqTaskMeshReader::DecompressNormalUByte4N(
        Render::FXqTaskMeshReader *this,
        UFG::qVector3 *result,
        unsigned int compressed)
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
    v3 = 1.0 / _mm_sqrt_ps(v7).m128_f32[0];
  v8 = result;
  result->z = v6 * v3;
  result->x = v3 * v4;
  result->y = v3 * v5.m128_f32[0];
  return v8;
}

// File Line: 247
// RVA: 0x1E14A0
__int64 __fastcall Render::FXqTaskMeshReader::DecodeVertexPositionAndNormal(
        Render::FXqTaskMeshReader *this,
        Illusion::Buffer **pVBuf,
        void **mainMemoryVertexData,
        unsigned int vertexDeclNameUID,
        unsigned int cur_index,
        UFG::qVector3 *outPosition,
        UFG::qVector3 *outNormal)
{
  __int64 v8; // r9
  int v9; // r11d
  unsigned __int64 v10; // r9
  unsigned int v11; // r11d
  void *v12; // r10
  Illusion::Buffer *v13; // rax
  unsigned __int64 v14; // r8
  unsigned int v15; // edx
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::qVector3 *v18; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  _QWORD result[2]; // [rsp+28h] [rbp-40h] BYREF
  UFG::qString v23; // [rsp+38h] [rbp-30h] BYREF
  unsigned int v24; // [rsp+80h] [rbp+18h]
  unsigned int v25; // [rsp+84h] [rbp+1Ch]

  v8 = (__int64)*mainMemoryVertexData;
  if ( *mainMemoryVertexData )
  {
    v9 = v8 + cur_index * (*pVBuf)->mElementByteSize;
    v10 = (v8 + cur_index * (*pVBuf)->mElementByteSize) & 0xFFFFFFFFFFFFFFF0ui64;
    v11 = v9 & 0xF;
  }
  else
  {
    v10 = result[0];
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
    v14 = result[1];
    v15 = v25;
  }
  if ( vertexDeclNameUID == 883623142 )
  {
    v16 = *(float *)(v11 + v10 + 4);
    v17 = *(float *)(v11 + v10 + 8);
    outPosition->x = *(float *)(v11 + v10);
    outPosition->y = v16;
    outPosition->z = v17;
    v18 = Render::FXqTaskMeshReader::DecompressNormalUByte4N(this, (UFG::qVector3 *)result, *(_DWORD *)(v15 + v14));
    y = v18->y;
    z = v18->z;
    outNormal->x = v18->x;
    outNormal->y = y;
    outNormal->z = z;
    return cur_index;
  }
  else
  {
    UFG::qString::qString(&v23);
    UFG::qString::Format(
      &v23,
      "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
      vertexDeclNameUID);
    UFG::qString::~qString(&v23);
    return 0xFFFFFFFFi64;
  }
}

