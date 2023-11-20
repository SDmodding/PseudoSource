// File Line: 168
// RVA: 0x146BC10
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_LightningTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_LightningTask,
    &Render::gTaskFunctionDeclData_LightningTask);
  return atexit(Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_LightningTask__);
}

// File Line: 204
// RVA: 0x1E5A40
char __fastcall Render::GetHeadTransform(Render::ElectrifiedObject *object, UFG::qMemoryStreamer *memory_streamer, UFG::qMatrix44 *result, float *alpha)
{
  Render::LightweightFXPosition *v4; // rax
  float *v5; // rbx
  UFG::qMatrix44 *v6; // rdi
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  char v10; // al
  UFG::SimComponent *v11; // rsi
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm2

  v4 = object->headLightWeightPosition.m_pPointer;
  v5 = alpha;
  v6 = result;
  if ( v4 )
  {
    v7 = UFG::qMatrix44::msIdentity.v1;
    v8 = UFG::qMatrix44::msIdentity.v2;
    v9 = UFG::qMatrix44::msIdentity.v3;
    result->v0 = UFG::qMatrix44::msIdentity.v0;
    result->v1 = v7;
    result->v2 = v8;
    result->v3 = v9;
    v7.x = v4->position.y;
    v8.x = v4->position.z;
    result->v3.x = v4->position.x;
    result->v3.w = 1.0;
    result->v3.y = v7.x;
    result->v3.z = v8.x;
    if ( alpha )
      *alpha = v4->alpha;
    v10 = 1;
  }
  else
  {
    v11 = object->headTransformNodeComponent.m_pPointer;
    if ( v11 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)object->headTransformNodeComponent.m_pPointer);
      v12 = *(UFG::qVector4 *)&v11[2].m_SafePointerList.mNode.mNext;
      v13 = *(UFG::qVector4 *)&v11[2].m_Flags;
      v14 = (UFG::qVector4)v11[2].m_BoundComponentHandles;
      v6->v0 = *(UFG::qVector4 *)&v11[2].vfptr;
      v6->v1 = v12;
      v6->v2 = v13;
      v6->v3 = v14;
      if ( v5 )
        *v5 = 1.0;
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
  }
  return v10;
}

// File Line: 238
// RVA: 0x1E5B40
char __fastcall Render::GetTailTransform(Render::ElectrifiedObject *object, UFG::qMemoryStreamer *memory_streamer, UFG::qMatrix44 *result, float *alpha)
{
  Render::LightweightFXPosition *v4; // rax
  float *v5; // rbx
  UFG::qMatrix44 *v6; // rdi
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  char v10; // al
  UFG::SimComponent *v11; // rsi
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm2

  v4 = object->tailLightWeightPosition.m_pPointer;
  v5 = alpha;
  v6 = result;
  if ( v4 )
  {
    v7 = UFG::qMatrix44::msIdentity.v1;
    v8 = UFG::qMatrix44::msIdentity.v2;
    v9 = UFG::qMatrix44::msIdentity.v3;
    result->v0 = UFG::qMatrix44::msIdentity.v0;
    result->v1 = v7;
    result->v2 = v8;
    result->v3 = v9;
    v7.x = v4->position.y;
    v8.x = v4->position.z;
    result->v3.x = v4->position.x;
    result->v3.w = 1.0;
    result->v3.y = v7.x;
    result->v3.z = v8.x;
    if ( alpha )
      *alpha = v4->alpha;
    v10 = 1;
  }
  else
  {
    v11 = object->tailTransformNodeComponent.m_pPointer;
    if ( v11 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)object->tailTransformNodeComponent.m_pPointer);
      v12 = *(UFG::qVector4 *)&v11[2].m_SafePointerList.mNode.mNext;
      v13 = *(UFG::qVector4 *)&v11[2].m_Flags;
      v14 = (UFG::qVector4)v11[2].m_BoundComponentHandles;
      v6->v0 = *(UFG::qVector4 *)&v11[2].vfptr;
      v6->v1 = v12;
      v6->v2 = v13;
      v6->v3 = v14;
      if ( v5 )
        *v5 = 1.0;
      v10 = 1;
    }
    else
    {
      v10 = 0;
    }
  }
  return v10;
}

// File Line: 296
// RVA: 0x1E5030
__int64 __fastcall Render::GenerateBoltsOnObject(Render::ElectrifiedObject *object, Render::ElectrifiedObjectSortContainer *container, UFG::qMemoryStreamer *memory_streamer, Render::Bolt *boltArray)
{
  UFG::qMemoryStreamer *v4; // rbx
  Render::ElectrifiedObject *v5; // r15
  unsigned int v6; // eax
  __int64 v7; // rdi
  unsigned int v8; // esi
  Render::LightningSettings *v9; // r14
  __m128 v10; // xmm1
  signed int v11; // ecx
  Illusion::Model *v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  unsigned int v15; // ecx
  Illusion::Model *v16; // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  unsigned int v19; // ecx
  unsigned int v20; // er12
  unsigned __int64 v21; // r15
  unsigned int v22; // er13
  int v23; // eax
  float v24; // xmm10_4
  float v25; // xmm12_4
  float v26; // xmm11_4
  float v27; // xmm14_4
  float v28; // xmm15_4
  float v29; // xmm13_4
  __int64 v30; // rbx
  int v31; // eax
  unsigned int v32; // ebx
  int v33; // er12
  unsigned __int64 v34; // rcx
  int *v35; // rbx
  int v36; // eax
  unsigned int v37; // ebx
  int v38; // er13
  float v39; // xmm6_4
  float v40; // xmm8_4
  float v41; // xmm9_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  int v45; // ebx
  int v46; // esi
  unsigned int v47; // er15
  float v48; // xmm13_4
  unsigned int v49; // er10
  __int64 v50; // r11
  float *v51; // r9
  signed __int64 v52; // rdx
  float *v53; // rcx
  float *v54; // rax
  signed int v55; // eax
  signed __int64 v56; // rax
  signed int v57; // eax
  float v58; // xmm0_4
  char v59; // dl
  float v60; // xmm10_4
  bool v61; // al
  bool v62; // cl
  unsigned int v63; // esi
  __int64 v64; // rbx
  float v65; // xmm2_4
  float v66; // xmm0_4
  __m128 v67; // xmm1
  signed int v68; // eax
  float v69; // xmm6_4
  float v70; // xmm6_4
  float v71; // xmm6_4
  unsigned int v73; // [rsp+20h] [rbp-A8h]
  signed int v74; // [rsp+24h] [rbp-A4h]
  float v75; // [rsp+28h] [rbp-A0h]
  UFG::qVector3 t; // [rsp+30h] [rbp-98h]
  __int128 v77; // [rsp+40h] [rbp-88h]
  float v78; // [rsp+50h] [rbp-78h]
  unsigned int v79; // [rsp+54h] [rbp-74h]
  unsigned __int64 v80; // [rsp+58h] [rbp-70h]
  unsigned __int64 v81; // [rsp+60h] [rbp-68h]
  Render::FXqTaskMeshReader v82; // [rsp+70h] [rbp-58h]
  char ptr; // [rsp+120h] [rbp+58h]
  __int64 v84; // [rsp+128h] [rbp+60h]
  __int64 v85; // [rsp+140h] [rbp+78h]
  __int64 v86; // [rsp+150h] [rbp+88h]
  __int64 v87; // [rsp+158h] [rbp+90h]
  __int64 v88; // [rsp+160h] [rbp+98h]
  __int64 v89; // [rsp+168h] [rbp+A0h]
  UFG::qMemoryStreamer *v90; // [rsp+170h] [rbp+A8h]
  float v91; // [rsp+178h] [rbp+B0h]
  int range; // [rsp+17Ch] [rbp+B4h]
  char v93; // [rsp+180h] [rbp+B8h]
  int v94; // [rsp+184h] [rbp+BCh]
  int *pseed; // [rsp+188h] [rbp+C0h]
  __int64 v96; // [rsp+198h] [rbp+D0h]
  UFG::qString v97; // [rsp+1A0h] [rbp+D8h]
  UFG::qString v98; // [rsp+1C8h] [rbp+100h]
  _QWORD *v99; // [rsp+2D8h] [rbp+210h]
  __int64 v100; // [rsp+2E0h] [rbp+218h]
  __int64 v101; // [rsp+2F0h] [rbp+228h]
  unsigned int v102; // [rsp+2F8h] [rbp+230h]
  __int64 vars0; // [rsp+300h] [rbp+238h]

  v96 = -2i64;
  v4 = memory_streamer;
  v5 = object;
  v6 = 800;
  v7 = vars0;
  if ( *(_DWORD *)(vars0 + 464) )
    v6 = 400;
  v79 = v6;
  v8 = v102;
  if ( v102 < v6 )
  {
    v9 = object->settings;
    if ( v9 )
    {
      v74 = 20;
      v10 = (__m128)*(unsigned int *)(vars0 + 460);
      v10.m128_f32[0] = v10.m128_f32[0] * v9->mEmissionRate;
      v11 = (signed int)v10.m128_f32[0];
      if ( (signed int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
        v10.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1 ^ 1) + v11);
      LODWORD(vars0) = (signed int)v10.m128_f32[0];
      if ( v5->framesElapsed == 1 )
        LODWORD(vars0) = v9->mEmissionInit + (signed int)v10.m128_f32[0];
      Render::FXqTaskMeshReader::FXqTaskMeshReader(&v82);
      v12 = v5->headModel;
      if ( v12 )
      {
        v82.mpVertexBuffers[0] = (Illusion::Buffer *)&seed;
        v82.mVertexBuffers[1].mName = (const char *)v4;
        v82.mModelAddrInMainMem = v12;
        *((_QWORD *)&v77 + 1) = v12;
        v81 = (unsigned __int64)&v12->mMeshOffsetTable
            + v12->mMeshOffsetTable.mOffset
            + *(unsigned int *)((char *)&v12->mMeshOffsetTable.mOffset + v12->mMeshOffsetTable.mOffset);
        *(&v82.mVertexBuffers[1].mState + 1) = 0;
        v13 = *(_QWORD *)(v81 + 112);
        v82.mModelStream.mName = (const char *)v13;
        v14 = *(_QWORD *)(v81 + 144);
        v82.mMeshStream.mName = *(const char **)(v81 + 144);
        v15 = *(_DWORD *)(v13 + 108);
        HIDWORD(v82.mVertexBuffers[1].mMainMemoryAddress) = v15;
        if ( v15 )
        {
          *(float *)&v82.mVertexBuffers[1].mMainMemoryAddress = (float)(0 % v15);
          *(_QWORD *)&v82.mMeshStream.mState = v13;
          v82.mVertexBuffers[0].mMainMemoryAddress = (void *)(*(_QWORD *)(v13 + 96) + v13 + 96);
          v82.mVertexBuffers[0].mName = (const char *)v14;
          *(_QWORD *)&v82.mVertexBuffers[0].mState = *(_QWORD *)(v14 + 96) + v14 + 96;
        }
        LOBYTE(v82.mVertexBuffers[1].mState) = 1;
      }
      Render::FXqTaskMeshReader::FXqTaskMeshReader((Render::FXqTaskMeshReader *)((char *)&v82 + 120));
      v16 = v5->tailModel;
      if ( v16 )
      {
        pseed = &seed;
        v90 = v4;
        v82.mpMainMemoryVertexBuffers[0] = v16;
        v82.mMemoryStreamer = (UFG::qMemoryStreamer *)v16;
        v82.mSeed = (int *)((char *)&v16->mMeshOffsetTable
                          + v16->mMeshOffsetTable.mOffset
                          + *(unsigned int *)((char *)&v16->mMeshOffsetTable.mOffset + v16->mMeshOffsetTable.mOffset));
        v94 = 0;
        v17 = *((_QWORD *)v82.mSeed + 14);
        v84 = v17;
        v18 = *((_QWORD *)v82.mSeed + 18);
        v85 = *((_QWORD *)v82.mSeed + 18);
        v19 = *(_DWORD *)(v17 + 108);
        range = v19;
        if ( v19 )
        {
          v91 = (float)(0 % v19);
          v86 = v17;
          v88 = *(_QWORD *)(v17 + 96) + v17 + 96;
          v87 = v18;
          v89 = *(_QWORD *)(v18 + 96) + v18 + 96;
        }
        v93 = 1;
      }
      v81 = v77;
      v20 = vars0;
      v21 = v77;
      v80 = v77;
      v22 = vars0;
      v23 = vars0;
      while ( 1 )
      {
        if ( v23 <= 0 || v74 <= 0 )
        {
LABEL_67:
          `eh vector destructor iterator(&ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
          `eh vector destructor iterator(&v82, 0x18ui64, 2, (void (__fastcall *)(void *))_);
          return v8;
        }
        v24 = 0.0;
        t.x = 0.0;
        v25 = 0.0;
        t.y = 0.0;
        v26 = 0.0;
        t.z = 0.0;
        v27 = 0.0;
        *(_QWORD *)&v77 = 0i64;
        v28 = 0.0;
        v29 = 0.0;
        v75 = 0.0;
        DWORD2(v77) = 0;
        if ( LOBYTE(v82.mVertexBuffers[1].mState) )
        {
          v30 = v81;
          v31 = UFG::qRandom(SHIDWORD(v82.mVertexBuffers[1].mMainMemoryAddress), (int *)v82.mpVertexBuffers[0]);
          v32 = *(_DWORD *)(v30 + 56);
          if ( v82.mVertexBuffers[0].mMainMemoryAddress )
          {
            v33 = LODWORD(v82.mVertexBuffers[0].mMainMemoryAddress)
                + v31 * *(_DWORD *)(*(_QWORD *)&v82.mMeshStream.mState + 104i64);
            v34 = ((_QWORD)v82.mVertexBuffers[0].mMainMemoryAddress
                 + (unsigned int)(v31 * *(_DWORD *)(*(_QWORD *)&v82.mMeshStream.mState + 104i64))) & 0xFFFFFFFFFFFFFFF0ui64;
            v81 = ((_QWORD)v82.mVertexBuffers[0].mMainMemoryAddress
                 + (unsigned int)(v31 * *(_DWORD *)(*(_QWORD *)&v82.mMeshStream.mState + 104i64))) & 0xFFFFFFFFFFFFFFF0ui64;
            v20 = v33 & 0xF;
          }
          else
          {
            v34 = v81;
          }
          if ( v32 == 883623142 )
          {
            v24 = *(float *)(v20 + v34);
            v25 = *(float *)(v20 + v34 + 4);
            v26 = *(float *)(v20 + v34 + 8);
            t.x = *(float *)(v20 + v34);
            t.y = v25;
            t.z = v26;
          }
          else
          {
            UFG::qString::qString(&v97);
            UFG::qString::Format(
              &v97,
              "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
              v32);
            UFG::qString::~qString(&v97);
          }
        }
        if ( v93 )
        {
          v35 = v82.mSeed;
          v36 = UFG::qRandom(range, pseed);
          v37 = v35[14];
          if ( v88 )
          {
            v38 = v88 + v36 * *(_DWORD *)(v86 + 104);
            v21 = (v88 + (unsigned int)(v36 * *(_DWORD *)(v86 + 104))) & 0xFFFFFFFFFFFFFFF0ui64;
            v80 = (v88 + (unsigned int)(v36 * *(_DWORD *)(v86 + 104))) & 0xFFFFFFFFFFFFFFF0ui64;
            v22 = v38 & 0xF;
          }
          if ( v37 == 883623142 )
          {
            v27 = *(float *)(v22 + v21);
            v28 = *(float *)(v22 + v21 + 4);
            v29 = *(float *)(v22 + v21 + 8);
            v75 = *(float *)(v22 + v21 + 8);
            LODWORD(v77) = *(_DWORD *)(v22 + v21);
            *(_QWORD *)((char *)&v77 + 4) = __PAIR__(LODWORD(v29), LODWORD(v28));
          }
          else
          {
            UFG::qString::qString(&v98);
            UFG::qString::Format(
              &v98,
              "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
              v37);
            UFG::qString::~qString(&v98);
          }
        }
        v39 = (float)((float)((float)(v25 * *(float *)(v100 + 16)) + (float)(v24 * *(float *)v100))
                    + (float)(v26 * *(float *)(v100 + 32)))
            + *(float *)(v100 + 48);
        v40 = (float)((float)((float)(v25 * *(float *)(v100 + 20)) + (float)(v24 * *(float *)(v100 + 4)))
                    + (float)(v26 * *(float *)(v100 + 36)))
            + *(float *)(v100 + 52);
        v41 = (float)((float)((float)(v25 * *(float *)(v100 + 24)) + (float)(v24 * *(float *)(v100 + 8)))
                    + (float)(v26 * *(float *)(v100 + 40)))
            + *(float *)(v100 + 56);
        v42 = (float)((float)((float)(v28 * *(float *)(v100 + 80)) + (float)(v27 * *(float *)(v100 + 64)))
                    + (float)(v29 * *(float *)(v100 + 96)))
            + *(float *)(v100 + 112);
        v43 = (float)((float)((float)(v28 * *(float *)(v100 + 84)) + (float)(v27 * *(float *)(v100 + 68)))
                    + (float)(v29 * *(float *)(v100 + 100)))
            + *(float *)(v100 + 116);
        v44 = (float)((float)((float)(v28 * *(float *)(v100 + 88)) + (float)(v27 * *(float *)(v100 + 72)))
                    + (float)(v29 * *(float *)(v100 + 104)))
            + *(float *)(v100 + 120);
        v78 = fsqrt(
                (float)((float)((float)(v39 - v42) * (float)(v39 - v42))
                      + (float)((float)(v40 - v43) * (float)(v40 - v43)))
              + (float)((float)(v41 - v44) * (float)(v41 - v44)));
        v45 = 0;
        v46 = 0;
        v47 = 0;
        v73 = 0;
        v48 = FLOAT_3_4028235e38;
        v49 = 0;
        if ( !*(_DWORD *)(v7 + 432) )
          goto LABEL_53;
        v50 = v7;
        v51 = (float *)(v7 + 388);
        do
        {
          v52 = 0i64;
          v53 = (float *)(v50 + 4);
          v54 = (float *)(v50 + 4);
          while ( (float)((float)((float)((float)(v40 * *v54) + (float)(*(v54 - 1) * v39)) + (float)(v41 * v54[1]))
                        + v54[2]) <= 0.0 )
          {
            ++v52;
            v54 += 4;
            if ( v52 >= 6 )
            {
              v55 = 1;
              goto LABEL_41;
            }
          }
          v55 = 0;
LABEL_41:
          v45 |= v55;
          v56 = 0i64;
          while ( (float)((float)((float)((float)(v43 * *v53) + (float)(*(v53 - 1) * v42)) + (float)(v44 * v53[1]))
                        + v53[2]) <= 0.0 )
          {
            ++v56;
            v53 += 4;
            if ( v56 >= 6 )
            {
              v57 = 1;
              goto LABEL_46;
            }
          }
          v57 = 0;
LABEL_46:
          v46 |= v57;
          v58 = fsqrt(
                  (float)((float)((float)(v39 - *(v51 - 1)) * (float)(v39 - *(v51 - 1)))
                        + (float)((float)(v40 - *v51) * (float)(v40 - *v51)))
                + (float)((float)(v41 - v51[1]) * (float)(v41 - v51[1])));
          if ( v58 < v48 )
          {
            v48 = v58;
            v73 = v49;
          }
          ++v49;
          v51 += 3;
          v50 += 96i64;
        }
        while ( v49 < *(_DWORD *)(v7 + 432) );
        if ( !v45 && !v46 )
          break;
        v59 = 1;
        v47 = v73;
LABEL_54:
        if ( v99[11] == v99[12] )
        {
          v60 = (float)((float)((float)(v24 - v27) * (float)(v24 - v27))
                      + (float)((float)(v25 - v28) * (float)(v25 - v28)))
              + (float)((float)(v26 - v75) * (float)(v26 - v75));
          v61 = v60 >= (float)(v9->mLengthMin * v9->mLengthMin);
          v62 = (float)(v9->mLengthMax * v9->mLengthMax) >= v60;
        }
        else
        {
          v61 = v78 >= v9->mLengthMin;
          v62 = v78 <= v9->mLengthMax;
        }
        if ( v61 && v62 && v59 )
        {
          v63 = v102;
          v64 = v101 + 72i64 * v102;
          UFG::qHalfVector3::operator=((UFG::qHalfVector3 *)(v101 + 72i64 * v102), &t);
          UFG::qHalfVector3::operator=((UFG::qHalfVector3 *)(v64 + 6), (UFG::qVector3 *)&v77);
          *(_QWORD *)(v64 + 16) = v99[10];
          v65 = *(float *)(v7 + 12 * (v47 + 32i64) + 8);
          v66 = *(float *)(v7 + 12 * (v47 + 32i64) + 4) - v40;
          v67 = (__m128)*(unsigned int *)(v7 + 12 * (v47 + 32i64));
          v67.m128_f32[0] = (float)((float)((float)(v67.m128_f32[0] - v39) * (float)(v67.m128_f32[0] - v39))
                                  + (float)(v66 * v66))
                          + (float)((float)(v65 - v41) * (float)(v65 - v41));
          v68 = (signed int)(float)((float)(3.0 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v67)) * 0.029999999)) + 0.5);
          if ( v68 <= 0 )
          {
            v68 = 0;
          }
          else if ( v68 >= 3 )
          {
            v68 = 3;
          }
          *(_DWORD *)(v64 + 32) = v68;
          *(_QWORD *)(v64 + 24) = *(_QWORD *)(v7 + 8i64 * v68 + 504);
          *(_QWORD *)(v64 + 40) = *(_QWORD *)(v100 + 128);
          *(_DWORD *)(v64 + 48) = *(_DWORD *)(v7 + 456);
          v69 = v9->mLifeMin;
          *(float *)(v64 + 52) = (float)(UFG::qRandom(1.0, &seed) * (float)(v9->mLifeMax - v69))
                               + (float)(v69 + *(float *)(v7 + 456));
          v70 = v9->mSpeedMin;
          *(float *)(v64 + 56) = (float)(UFG::qRandom(1.0, &seed) * (float)(v9->mSpeedMax - v70)) + v70;
          *(float *)(v64 + 60) = UFG::qRandom(6.2831855, &seed);
          v71 = v9->mCurveMin;
          *(float *)(v64 + 64) = (float)(UFG::qRandom(1.0, &seed) * (float)(v9->mCurveMax - v71)) + v71;
          v8 = v63 + 1;
          v102 = v8;
          v23 = vars0 - 1;
          LODWORD(vars0) = vars0 - 1;
        }
        else
        {
          --v74;
          v8 = v102;
          v23 = vars0;
        }
        v21 = v80;
        if ( v8 >= v79 )
          goto LABEL_67;
      }
      v47 = v73;
LABEL_53:
      v59 = 0;
      goto LABEL_54;
    }
  }
  return v8;
}

// File Line: 437
// RVA: 0x1E6250
void __fastcall Render::WriteTerminalVertex(LightningJoint *joint, Render::BoltConstantData *params, float vTexcoord, void *mainMemoryVertexBuffer)
{
  Render::BoltConstantData *v4; // r11
  float v5; // xmm8_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  unsigned int v14; // ebx
  float v15; // er8
  unsigned int v16; // edx
  int v17; // er8
  __int16 v18; // r8
  unsigned int v19; // edx
  unsigned int v20; // edx
  int v21; // er8
  __int16 v22; // r8
  unsigned int v23; // edx
  float v24; // er8
  unsigned int v25; // edx
  int v26; // er8
  __int16 v27; // r8
  unsigned int v28; // edx
  unsigned int v29; // edx
  int v30; // er8
  unsigned int v31; // edx

  v4 = params;
  v5 = vTexcoord;
  v6 = (float)((float)((float)((float)(params->lengthOfBolt * params->settings->mWidthMax) * params->sizeScale)
                     - (float)((float)(params->lengthOfBolt * params->settings->mWidthMin) * params->sizeScale))
             * joint->width)
     + (float)((float)(params->lengthOfBolt * params->settings->mWidthMin) * params->sizeScale);
  v7 = (float)((float)((float)(joint->pos.y * params->mat.v1.x) + (float)(joint->pos.x * params->mat.v0.x))
             + (float)(joint->pos.z * params->mat.v2.x))
     + params->mat.v3.x;
  v8 = (float)((float)((float)(joint->pos.y * params->mat.v1.y) + (float)(joint->pos.x * params->mat.v0.y))
             + (float)(joint->pos.z * params->mat.v2.y))
     + params->mat.v3.y;
  v9 = (float)((float)((float)(joint->pos.y * params->mat.v1.z) + (float)(joint->pos.x * params->mat.v0.z))
             + (float)(joint->pos.z * params->mat.v2.z))
     + params->mat.v3.z;
  *(float *)mainMemoryVertexBuffer = v7;
  *((float *)mainMemoryVertexBuffer + 1) = v8;
  *((float *)mainMemoryVertexBuffer + 2) = v9;
  *((float *)mainMemoryVertexBuffer + 9) = v8;
  *((float *)mainMemoryVertexBuffer + 8) = v7;
  *((float *)mainMemoryVertexBuffer + 10) = v9;
  v10 = v6 * params->boltDirection.x;
  v11 = v6 * params->boltDirection.y;
  *((float *)mainMemoryVertexBuffer + 5) = v6 * params->boltDirection.z;
  *((float *)mainMemoryVertexBuffer + 3) = v10;
  *((float *)mainMemoryVertexBuffer + 4) = v11;
  v12 = COERCE_FLOAT(LODWORD(params->boltDirection.x) ^ _xmm[0]) * v6;
  v13 = COERCE_FLOAT(LODWORD(params->boltDirection.y) ^ _xmm[0]) * v6;
  *((float *)mainMemoryVertexBuffer + 13) = COERCE_FLOAT(LODWORD(params->boltDirection.z) ^ _xmm[0]) * v6;
  *((float *)mainMemoryVertexBuffer + 11) = v12;
  *((float *)mainMemoryVertexBuffer + 12) = v13;
  v14 = ((signed int)(float)(params->colour.g * 255.0) << 8) | ((signed int)(float)(params->colour.r * 255.0) | (((signed int)(float)(params->colour.b * 255.0) | ((signed int)(float)(params->colour.a * 255.0) << 8)) << 16)) & 0xFFFFFF00;
  *((_DWORD *)mainMemoryVertexBuffer + 7) = v14;
  v15 = (float)(signed int)params->settings->mTexturePageU * 0.5;
  v16 = LODWORD(v15) & 0x7FFFFFFF;
  v17 = (LODWORD(v15) >> 16) & 0x8000;
  if ( v16 <= 0x47FFEFFF )
  {
    if ( v16 >= 0x38800000 )
      v19 = v16 - 939524096;
    else
      v19 = (v16 & 0x7FFFFF | 0x800000) >> (113 - (v16 >> 23));
    v18 = ((((v19 >> 13) & 1) + v19 + 4095) >> 13) | v17;
  }
  else
  {
    v18 = v17 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 12) = v18;
  v20 = LODWORD(v5) & 0x7FFFFFFF;
  v21 = (LODWORD(v5) >> 16) & 0x8000;
  if ( (LODWORD(v5) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v20 >= 0x38800000 )
      v23 = v20 - 939524096;
    else
      v23 = (LODWORD(v5) & 0x7FFFFF | 0x800000u) >> (113 - (v20 >> 23));
    v22 = ((((v23 >> 13) & 1) + v23 + 4095) >> 13) | v21;
  }
  else
  {
    v22 = v21 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 13) = v22;
  *((_DWORD *)mainMemoryVertexBuffer + 15) = v14;
  v24 = (float)(v4->settings->mTexturePageU + 1) * 0.5;
  v25 = LODWORD(v24) & 0x7FFFFFFF;
  v26 = (LODWORD(v24) >> 16) & 0x8000;
  if ( v25 <= 0x47FFEFFF )
  {
    if ( v25 >= 0x38800000 )
      v28 = v25 - 939524096;
    else
      v28 = (v25 & 0x7FFFFF | 0x800000) >> (113 - (v25 >> 23));
    v27 = ((((v28 >> 13) & 1) + v28 + 4095) >> 13) | v26;
  }
  else
  {
    v27 = v26 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 28) = v27;
  v29 = LODWORD(v5) & 0x7FFFFFFF;
  v30 = (LODWORD(v5) >> 16) & 0x8000;
  if ( (LODWORD(v5) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v29 >= 0x38800000 )
      v31 = v29 - 939524096;
    else
      v31 = (LODWORD(v5) & 0x7FFFFF | 0x800000u) >> (113 - (v29 >> 23));
    *((_WORD *)mainMemoryVertexBuffer + 29) = v30 | ((((v31 >> 13) & 1) + v31 + 4095) >> 13);
  }
  else
  {
    *((_WORD *)mainMemoryVertexBuffer + 29) = v30 | 0x7FFF;
  }
}

// File Line: 475
// RVA: 0x1E5D40
void __fastcall Render::WriteMiddleVertex(LightningJoint *joint, Render::BoltConstantData *params, float t, float vTexcoord, float alpha, void *mainMemoryVertexBuffer)
{
  float v6; // xmm0_4
  Render::BoltConstantData *v7; // rbx
  float v8; // xmm9_4
  float v9; // xmm12_4
  Render::LightningSettings *v10; // rax
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm11_4
  float v17; // xmm5_4
  float v18; // xmm7_4
  float v19; // xmm1_4
  float v20; // xmm10_4
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm11_4
  float v24; // xmm0_4
  float v25; // xmm11_4
  float v26; // xmm8_4
  float v27; // xmm6_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  int v32; // er11
  float v33; // er8
  unsigned int v34; // edx
  int v35; // er8
  __int16 v36; // r8
  unsigned int v37; // edx
  unsigned int v38; // edx
  int v39; // er8
  __int16 v40; // r8
  unsigned int v41; // edx
  float v42; // er8
  unsigned int v43; // edx
  int v44; // er8
  __int16 v45; // r8
  unsigned int v46; // edx
  unsigned int v47; // edx
  int v48; // er8
  unsigned int v49; // edx

  v6 = joint->jitter;
  v7 = params;
  v8 = params->lengthOfBolt;
  v9 = vTexcoord;
  v10 = params->settings;
  v11 = params->lengthOfBolt * v10->mJitterDistance.x;
  v12 = (float)(v11 * joint->right.y) * v6;
  v13 = (float)(v11 * joint->right.x) * v6;
  v14 = (float)(v11 * joint->right.z) * v6;
  v15 = params->sizeScale;
  v16 = joint->pos.y + v12;
  v17 = joint->pos.x + v13;
  v18 = joint->pos.z + v14;
  v19 = (float)(params->lengthOfBolt * v10->mWidthMin) * v15;
  v20 = (float)((float)((float)((float)(params->lengthOfBolt * v10->mWidthMax) * v15) - v19) * joint->width) + v19;
  v21 = (float)((float)((float)(v16 * params->mat.v1.x) + (float)(v17 * params->mat.v0.x))
              + (float)(v18 * params->mat.v2.x))
      + params->mat.v3.x;
  v22 = (float)((float)((float)(v16 * params->mat.v1.y) + (float)(v17 * params->mat.v0.y))
              + (float)(v18 * params->mat.v2.y))
      + params->mat.v3.y;
  v23 = (float)((float)((float)(v16 * params->mat.v1.z) + (float)(v17 * params->mat.v0.z))
              + (float)(v18 * params->mat.v2.z))
      + params->mat.v3.z;
  v24 = sinf(t * 3.1415927) * (float)((float)(v7->speed * v7->timeElapsed) + v7->curve);
  v25 = v23 + (float)((float)(v24 * v7->perpendicularMat.v2.z) * v8);
  v26 = v21 + (float)((float)(v24 * v7->perpendicularMat.v2.x) * v8);
  v27 = v22 + (float)((float)(v24 * v7->perpendicularMat.v2.y) * v8);
  *(float *)mainMemoryVertexBuffer = v26;
  *((float *)mainMemoryVertexBuffer + 1) = v27;
  *((float *)mainMemoryVertexBuffer + 2) = v25;
  *((float *)mainMemoryVertexBuffer + 8) = v26;
  *((float *)mainMemoryVertexBuffer + 9) = v27;
  *((float *)mainMemoryVertexBuffer + 10) = v25;
  v28 = v20 * v7->boltDirection.x;
  v29 = v20 * v7->boltDirection.y;
  *((float *)mainMemoryVertexBuffer + 5) = v20 * v7->boltDirection.z;
  *((float *)mainMemoryVertexBuffer + 3) = v28;
  *((float *)mainMemoryVertexBuffer + 4) = v29;
  v30 = COERCE_FLOAT(LODWORD(v7->boltDirection.x) ^ _xmm[0]) * v20;
  v31 = COERCE_FLOAT(LODWORD(v7->boltDirection.y) ^ _xmm[0]) * v20;
  *((float *)mainMemoryVertexBuffer + 13) = COERCE_FLOAT(LODWORD(v7->boltDirection.z) ^ _xmm[0]) * v20;
  *((float *)mainMemoryVertexBuffer + 11) = v30;
  *((float *)mainMemoryVertexBuffer + 12) = v31;
  v32 = (signed int)(float)(v7->colour.r * 255.0) | (((signed int)(float)(v7->colour.g * 255.0) | (((signed int)(float)(v7->colour.b * 255.0) | ((signed int)(float)((float)(v7->colour.a * alpha) * 255.0) << 8)) << 8)) << 8);
  *((_DWORD *)mainMemoryVertexBuffer + 7) = v32;
  v33 = (float)(signed int)v7->settings->mTexturePageU * 0.5;
  v34 = LODWORD(v33) & 0x7FFFFFFF;
  v35 = (LODWORD(v33) >> 16) & 0x8000;
  if ( v34 <= 0x47FFEFFF )
  {
    if ( v34 >= 0x38800000 )
      v37 = v34 - 939524096;
    else
      v37 = (v34 & 0x7FFFFF | 0x800000) >> (113 - (v34 >> 23));
    v36 = ((((v37 >> 13) & 1) + v37 + 4095) >> 13) | v35;
  }
  else
  {
    v36 = v35 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 12) = v36;
  v38 = LODWORD(v9) & 0x7FFFFFFF;
  v39 = (LODWORD(v9) >> 16) & 0x8000;
  if ( (LODWORD(v9) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v38 >= 0x38800000 )
      v41 = v38 - 939524096;
    else
      v41 = (LODWORD(v9) & 0x7FFFFF | 0x800000u) >> (113 - (v38 >> 23));
    v40 = ((((v41 >> 13) & 1) + v41 + 4095) >> 13) | v39;
  }
  else
  {
    v40 = v39 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 13) = v40;
  *((_DWORD *)mainMemoryVertexBuffer + 15) = v32;
  v42 = (float)(v7->settings->mTexturePageU + 1) * 0.5;
  v43 = LODWORD(v42) & 0x7FFFFFFF;
  v44 = (LODWORD(v42) >> 16) & 0x8000;
  if ( v43 <= 0x47FFEFFF )
  {
    if ( v43 >= 0x38800000 )
      v46 = v43 - 939524096;
    else
      v46 = (v43 & 0x7FFFFF | 0x800000) >> (113 - (v43 >> 23));
    v45 = ((((v46 >> 13) & 1) + v46 + 4095) >> 13) | v44;
  }
  else
  {
    v45 = v44 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 28) = v45;
  v47 = LODWORD(v9) & 0x7FFFFFFF;
  v48 = (LODWORD(v9) >> 16) & 0x8000;
  if ( (LODWORD(v9) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v47 >= 0x38800000 )
      v49 = v47 - 939524096;
    else
      v49 = (LODWORD(v9) & 0x7FFFFF | 0x800000u) >> (113 - (v47 >> 23));
    *((_WORD *)mainMemoryVertexBuffer + 29) = v48 | ((((v49 >> 13) & 1) + v49 + 4095) >> 13);
  }
  else
  {
    *((_WORD *)mainMemoryVertexBuffer + 29) = v48 | 0x7FFF;
  }
}

// File Line: 524
// RVA: 0x1E5C40
__int64 __fastcall Render::KillExpiredBolts(Render::Bolt *boltArray, unsigned int numBolts, float simTime)
{
  signed int v3; // er9
  float v4; // xmm5_4
  UFG::qHalfFloat *v5; // r8
  __m128i v6; // xmm1
  __m128 v7; // xmm4
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __int64 v10; // ST40_8

  v3 = 0;
  v4 = simTime;
  if ( (signed int)numBolts > 0 )
  {
    v5 = &boltArray->tailOffset.z;
    do
    {
      if ( v4 <= *(float *)&v5[21].mRep )
      {
        ++v3;
        v5 += 36;
      }
      else
      {
        v6 = *(__m128i *)&boltArray[--numBolts].headOffset.x.mRep;
        v7 = *(__m128 *)&boltArray[numBolts].startTime;
        v8 = *(__m128i *)&boltArray[numBolts].settings;
        v9 = *(__m128i *)&boltArray[numBolts].jointChainSegmentCount;
        v10 = *(_QWORD *)&boltArray[numBolts].curve;
        v5[-5].mRep = _mm_cvtsi128_si32(v6);
        v5[-4].mRep = _mm_extract_epi16(v6, 1);
        v5[-3].mRep = _mm_extract_epi16(v6, 2);
        v5[-2].mRep = _mm_extract_epi16(v6, 3);
        v5[-1].mRep = _mm_extract_epi16(v6, 4);
        v5->mRep = _mm_extract_epi16(v6, 5);
        *(_DWORD *)&v5[19].mRep = v7.m128_i32[0];
        *(_DWORD *)&v5[21].mRep = (unsigned __int128)_mm_shuffle_ps(v7, v7, 85);
        *(_DWORD *)&v5[11].mRep = _mm_cvtsi128_si32(v9);
        _mm_storel_epi64((__m128i *)&v5[3], v8);
        *(_DWORD *)&v5[25].mRep = (unsigned __int128)_mm_shuffle_ps(v7, v7, 255);
        *(_DWORD *)&v5[23].mRep = (unsigned __int128)_mm_shuffle_ps(v7, v7, 170);
        *(_DWORD *)&v5[27].mRep = v10;
        _mm_storel_epi64((__m128i *)&v5[7], _mm_srli_si128(v8, 8));
        _mm_storel_epi64((__m128i *)&v5[15], _mm_srli_si128(v9, 8));
      }
    }
    while ( v3 < (signed int)numBolts );
  }
  return numBolts;
}

// File Line: 550
// RVA: 0x1E2D50
void __fastcall Render::LightningTask(int worker_id, UFG::qMemoryStreamer *memory_streamer, void *_lightningInfo, void *_outInfo)
{
  __int64 v4; // rbx
  Render::LightningTaskParam *taskParams; // r12
  Render::Bolt *v6; // rax
  _WORD *v7; // rsi
  unsigned int v8; // edx
  unsigned int v9; // er15
  unsigned int v10; // eax
  Render::ElectrifiedObject *v11; // r13
  __int64 v12; // r14
  Render::ElectrifiedObjectSortContainer *v13; // rdi
  bool v14; // bl
  bool v15; // al
  signed int v16; // er8
  signed __int64 v17; // rax
  float v18; // xmm2_4
  unsigned int v19; // er9
  float *v20; // rcx
  unsigned int v21; // eax
  __int64 v22; // rdx
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float *v35; // rcx
  __int64 v36; // rax
  unsigned int v37; // ST40_4
  unsigned int numBolts; // eax
  Render::ElectrifiedObject **v39; // rdi
  Render::ElectrifiedObjectSortContainer *v40; // r14
  char *v41; // rbx
  int v42; // eax
  unsigned int v43; // edx
  float v44; // xmm13_4
  signed __int64 v45; // r12
  __int64 v46; // rcx
  LightningJoint *v47; // rdi
  float *v48; // rax
  float v49; // xmm6_4
  float v50; // xmm10_4
  _OWORD *v51; // r14
  __int128 v52; // xmm1
  __int128 v53; // xmm0
  __int128 v54; // xmm1
  __int64 v55; // rax
  float v56; // xmm14_4
  float v57; // xmm15_4
  _OWORD *v58; // r14
  __int128 v59; // xmm1
  __int128 v60; // xmm0
  __int128 v61; // xmm1
  __m128 v62; // xmm7
  float v63; // ST50_4
  float v64; // ST70_4
  unsigned int v65; // ecx
  float v66; // xmm12_4
  float v67; // xmm9_4
  float v68; // xmm8_4
  float v69; // edx
  float v70; // ST50_4
  float v71; // xmm6_4
  __m128 v72; // xmm5
  float v73; // xmm4_4
  float v74; // xmm6_4
  float v75; // xmm4_4
  __m128 v76; // xmm2
  float v77; // xmm1_4
  float v78; // xmm7_4
  float v79; // xmm8_4
  float v80; // xmm6_4
  unsigned int v81; // er8
  unsigned int v82; // edx
  unsigned int v83; // ecx
  bool v84; // cf
  bool v85; // zf
  int v86; // ecx
  float v87; // xmm2_4
  __m128 v88; // xmm13
  __m128 v89; // xmm12
  float v90; // xmm1_4
  float v91; // xmm3_4
  __int64 v92; // r14
  signed __int64 v93; // rax
  float v94; // xmm14_4
  float v95; // xmm11_4
  float v96; // xmm9_4
  float v97; // xmm7_4
  float v98; // xmm0_4
  float v99; // ST50_4
  float v100; // xmm10_4
  float v101; // xmm8_4
  float v102; // xmm6_4
  float v103; // xmm4_4
  float v104; // xmm15_4
  float v105; // xmm0_4
  float v106; // xmm2_4
  float v107; // xmm0_4
  float v108; // xmm3_4
  float v109; // xmm5_4
  float v110; // xmm14_4
  float v111; // xmm12_4
  float v112; // xmm11_4
  float v113; // xmm15_4
  __m128 v114; // xmm8
  __m128 v115; // xmm3
  float v116; // xmm14_4
  float v117; // xmm15_4
  float v118; // xmm15_4
  __m128 v119; // xmm2
  float v120; // xmm1_4
  float v121; // xmm4_4
  float v122; // xmm8_4
  __m128 v123; // xmm2
  float v124; // xmm0_4
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  float v127; // xmm7_4
  float v128; // xmm2_4
  float v129; // xmm7_4
  __m128 v130; // xmm5
  float v131; // xmm2_4
  float v132; // xmm7_4
  __m128 v133; // xmm6
  float v134; // xmm6_4
  unsigned int v135; // xmm5_4
  unsigned int v136; // xmm1_4
  unsigned int v137; // xmm6_4
  float v138; // xmm7_4
  float v139; // xmm4_4
  __m128 v140; // xmm2
  float v141; // xmm1_4
  float v142; // xmm1_4
  UFG::qColour *v143; // rax
  float v144; // xmm1_4
  float v145; // xmm0_4
  float v146; // xmm1_4
  float v147; // xmm0_4
  float v148; // xmm1_4
  float v149; // xmm6_4
  _DWORD *v150; // rdx
  unsigned int v151; // [rsp+40h] [rbp-C0h]
  unsigned int v152; // [rsp+44h] [rbp-BCh]
  float v153; // [rsp+48h] [rbp-B8h]
  float v154; // [rsp+48h] [rbp-B8h]
  float v155; // [rsp+50h] [rbp-B0h]
  float lifetime; // [rsp+58h] [rbp-A8h]
  float lifetimea; // [rsp+58h] [rbp-A8h]
  float v158; // [rsp+5Ch] [rbp-A4h]
  float v159; // [rsp+5Ch] [rbp-A4h]
  float v160; // [rsp+64h] [rbp-9Ch]
  int v161; // [rsp+68h] [rbp-98h]
  Render::Bolt *boltArray; // [rsp+70h] [rbp-90h]
  float boltArraya; // [rsp+70h] [rbp-90h]
  float v164; // [rsp+78h] [rbp-88h]
  float v165; // [rsp+7Ch] [rbp-84h]
  UFG::qVector3 forward; // [rsp+80h] [rbp-80h]
  __int64 v167; // [rsp+90h] [rbp-70h]
  __int64 v168; // [rsp+98h] [rbp-68h]
  float v169; // [rsp+A0h] [rbp-60h]
  char v170[64]; // [rsp+B0h] [rbp-50h]
  char v171[64]; // [rsp+F0h] [rbp-10h]
  UFG::qVector3 translation; // [rsp+130h] [rbp+30h]
  Render::LightningSettings *v173; // [rsp+140h] [rbp+40h]
  __int64 v174; // [rsp+148h] [rbp+48h]
  UFG::qVector3 v175; // [rsp+150h] [rbp+50h]
  UFG::qVector3 scale; // [rsp+15Ch] [rbp+5Ch]
  UFG::qVector3 up; // [rsp+168h] [rbp+68h]
  __m128 v178; // [rsp+180h] [rbp+80h]
  __m128 v179; // [rsp+190h] [rbp+90h]
  __m128 v180; // [rsp+1A0h] [rbp+A0h]
  __m128 v181; // [rsp+1B0h] [rbp+B0h]
  UFG::qVector4 v182; // [rsp+1C0h] [rbp+C0h]
  UFG::qVector4 v183; // [rsp+1D0h] [rbp+D0h]
  UFG::qVector4 v184; // [rsp+1E0h] [rbp+E0h]
  UFG::qVector4 v185; // [rsp+1F0h] [rbp+F0h]
  float v186; // [rsp+200h] [rbp+100h]
  float v187; // [rsp+210h] [rbp+110h]
  Render::BoltConstantData params; // [rsp+220h] [rbp+120h]
  UFG::qMatrix44 dest; // [rsp+2F0h] [rbp+1F0h]
  __m128 v190; // [rsp+330h] [rbp+230h]
  __m128 v191; // [rsp+340h] [rbp+240h]
  __m128 v192; // [rsp+350h] [rbp+250h]
  __m128 v193; // [rsp+360h] [rbp+260h]
  UFG::qMatrix44 v194; // [rsp+370h] [rbp+270h]
  UFG::qColour result; // [rsp+3B0h] [rbp+2B0h]
  Render::ElectrifiedObjectSortContainer left[300]; // [rsp+3C0h] [rbp+2C0h]
  UFG::qMemoryStreamer *memory_streamera; // [rsp+B6C8h] [rbp+B5C8h]
  int v198; // [rsp+B6D0h] [rbp+B5D0h]
  _DWORD *v199; // [rsp+B6D8h] [rbp+B5D8h]

  v199 = _outInfo;
  memory_streamera = memory_streamer;
  LODWORD(v4) = 0;
  taskParams = (Render::LightningTaskParam *)_lightningInfo;
  seed = *((_DWORD *)_lightningInfo + 134);
  *((_DWORD *)_outInfo + 3) = 0;
  v6 = (Render::Bolt *)*((_QWORD *)_lightningInfo + 59);
  v7 = (_WORD *)*((_QWORD *)_lightningInfo + 55);
  v167 = 0i64;
  boltArray = v6;
  if ( v6 )
  {
    v8 = *((_DWORD *)_lightningInfo + 120);
    v169 = *((float *)_lightningInfo + 114);
    v9 = 0;
    v161 = 0;
    v198 = 0;
    v10 = Render::KillExpiredBolts(v6, v8, v169);
    v11 = (Render::ElectrifiedObject *)taskParams->electrifiedObjectListStart;
    v152 = v10;
    if ( v11 != taskParams->electrifiedObjectListEnd )
    {
      do
      {
        if ( v9 >= 0x12C )
          break;
        if ( v11->status == Status_Active )
        {
          v12 = v9;
          v13 = &left[v12];
          left[v12].electrifiedObjectPtr = v11;
          v14 = Render::GetHeadTransform(v11, memory_streamera, &left[v12].headTransformWS, &left[v12].headAlpha);
          v15 = Render::GetTailTransform(v11, memory_streamera, &left[v12].tailTransformWS, &left[v12].tailAlpha);
          if ( v14 && v15 )
          {
            v16 = taskParams->numFrustums;
            v17 = 0i64;
            v18 = FLOAT_3_4028235e38;
            v19 = 0;
            if ( v16 >= 4 )
            {
              v20 = &taskParams->cameraPositions[0].z;
              v21 = ((unsigned int)(v16 - 4) >> 2) + 1;
              v22 = v21;
              v19 = 4 * v21;
              v17 = 4i64 * v21;
              do
              {
                if ( (float)((float)((float)((float)(*(v20 - 1) - v13->headTransformWS.v3.y)
                                           * (float)(*(v20 - 1) - v13->headTransformWS.v3.y))
                                   + (float)((float)(*(v20 - 2) - v13->headTransformWS.v3.x)
                                           * (float)(*(v20 - 2) - v13->headTransformWS.v3.x)))
                           + (float)((float)(*v20 - v13->headTransformWS.v3.z)
                                   * (float)(*v20 - v13->headTransformWS.v3.z))) < v18 )
                  v18 = (float)((float)((float)(*(v20 - 1) - v13->headTransformWS.v3.y)
                                      * (float)(*(v20 - 1) - v13->headTransformWS.v3.y))
                              + (float)((float)(*(v20 - 2) - v13->headTransformWS.v3.x)
                                      * (float)(*(v20 - 2) - v13->headTransformWS.v3.x)))
                      + (float)((float)(*v20 - v13->headTransformWS.v3.z) * (float)(*v20 - v13->headTransformWS.v3.z));
                v23 = v20[1];
                v24 = v20[2];
                v25 = v20[3];
                left[v12].distanceToNearestCamera = v18;
                v26 = (float)((float)((float)(v24 - v13->headTransformWS.v3.y) * (float)(v24 - v13->headTransformWS.v3.y))
                            + (float)((float)(v23 - v13->headTransformWS.v3.x) * (float)(v23 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v25 - v13->headTransformWS.v3.z) * (float)(v25 - v13->headTransformWS.v3.z));
                if ( v26 < v18 )
                  v18 = v26;
                v27 = v20[4];
                v28 = v20[5];
                v29 = v20[6];
                left[v12].distanceToNearestCamera = v18;
                v30 = (float)((float)((float)(v28 - v13->headTransformWS.v3.y) * (float)(v28 - v13->headTransformWS.v3.y))
                            + (float)((float)(v27 - v13->headTransformWS.v3.x) * (float)(v27 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v29 - v13->headTransformWS.v3.z) * (float)(v29 - v13->headTransformWS.v3.z));
                if ( v30 < v18 )
                  v18 = v30;
                v31 = v20[7];
                v32 = v20[8];
                v33 = v20[9];
                left[v12].distanceToNearestCamera = v18;
                v34 = (float)((float)((float)(v32 - v13->headTransformWS.v3.y) * (float)(v32 - v13->headTransformWS.v3.y))
                            + (float)((float)(v31 - v13->headTransformWS.v3.x) * (float)(v31 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v33 - v13->headTransformWS.v3.z) * (float)(v33 - v13->headTransformWS.v3.z));
                if ( v34 < v18 )
                  v18 = v34;
                v20 += 12;
                left[v12].distanceToNearestCamera = v18;
                --v22;
              }
              while ( v22 );
            }
            if ( v19 < v16 )
            {
              v35 = (float *)((char *)taskParams + 4 * (3 * v17 + 98));
              v36 = v16 - v19;
              do
              {
                if ( (float)((float)((float)((float)(*(v35 - 1) - v13->headTransformWS.v3.y)
                                           * (float)(*(v35 - 1) - v13->headTransformWS.v3.y))
                                   + (float)((float)(*(v35 - 2) - v13->headTransformWS.v3.x)
                                           * (float)(*(v35 - 2) - v13->headTransformWS.v3.x)))
                           + (float)((float)(*v35 - v13->headTransformWS.v3.z)
                                   * (float)(*v35 - v13->headTransformWS.v3.z))) < v18 )
                  v18 = (float)((float)((float)(*(v35 - 1) - v13->headTransformWS.v3.y)
                                      * (float)(*(v35 - 1) - v13->headTransformWS.v3.y))
                              + (float)((float)(*(v35 - 2) - v13->headTransformWS.v3.x)
                                      * (float)(*(v35 - 2) - v13->headTransformWS.v3.x)))
                      + (float)((float)(*v35 - v13->headTransformWS.v3.z) * (float)(*v35 - v13->headTransformWS.v3.z));
                v35 += 3;
                left[v12].distanceToNearestCamera = v18;
                --v36;
              }
              while ( v36 );
            }
            ++v9;
          }
        }
        v11 = (Render::ElectrifiedObject *)v11->mNext;
      }
      while ( v11 != taskParams->electrifiedObjectListEnd );
      v37 = v9;
      v9 = 0;
      LODWORD(v4) = v37;
    }
    UFG::qQuickSortImpl<Render::ElectrifiedObjectSortContainer,UFG::qLess<Render::ElectrifiedObjectSortContainer>>(
      left,
      (Render::ElectrifiedObjectSortContainer *)&dest.v3.z + (signed int)v4,
      0);
    if ( (_DWORD)v4 )
    {
      numBolts = v152;
      v39 = (Render::ElectrifiedObject **)&left[0].electrifiedObjectPtr;
      v40 = left;
      v4 = (unsigned int)v4;
      do
      {
        numBolts = Render::GenerateBoltsOnObject(*v39, v40, memory_streamera, boltArray, numBolts, taskParams);
        ++v40;
        v39 += 19;
        --v4;
      }
      while ( v4 );
      v152 = numBolts;
    }
    v41 = (char *)taskParams->vertexBuffer;
    v42 = 0;
    v43 = 0;
    v151 = 0;
    if ( v152 )
    {
      v44 = *(float *)&FLOAT_1_0;
      v45 = (signed __int64)&boltArray->jointChain;
      while ( 1 )
      {
        v46 = *(_QWORD *)(v45 + 16);
        v47 = *(LightningJoint **)v45;
        v173 = *(Render::LightningSettings **)(v45 - 8);
        v48 = *(float **)(v46 + 64);
        v174 = v46;
        if ( v48 )
        {
          v49 = v48[1];
          v50 = v48[2];
          lifetime = v44;
          *(UFG::qMatrix44 *)v171 = UFG::qMatrix44::msIdentity;
          v165 = v48[4];
          v164 = v48[3];
        }
        else
        {
          v51 = *(_OWORD **)(v46 + 32);
          if ( !v51 )
            goto LABEL_88;
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v46 + 32));
          v46 = v174;
          v43 = v151;
          v52 = v51[9];
          *(_OWORD *)v171 = v51[8];
          v53 = v51[10];
          *(_OWORD *)&v171[16] = v52;
          v54 = v51[11];
          *(_OWORD *)&v171[32] = v53;
          *(_OWORD *)&v171[48] = v54;
          v50 = *(float *)&v171[52];
          v49 = *(float *)&v54;
          v165 = v44;
          lifetime = *((float *)&v54 + 3);
          v164 = *((float *)&v54 + 2);
        }
        v55 = *(_QWORD *)(v46 + 72);
        v158 = v49;
        if ( v55 )
        {
          v56 = *(float *)(v55 + 4);
          v57 = *(float *)(v55 + 8);
          v153 = v44;
          *(UFG::qMatrix44 *)v170 = UFG::qMatrix44::msIdentity;
          LODWORD(v168) = *(_DWORD *)(v55 + 12);
          v160 = *(float *)(v55 + 16);
        }
        else
        {
          v58 = *(_OWORD **)(v46 + 56);
          if ( !v58 )
            goto LABEL_88;
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v46 + 56));
          v59 = v58[9];
          *(_OWORD *)v170 = v58[8];
          v60 = v58[10];
          *(_OWORD *)&v170[16] = v59;
          v61 = v58[11];
          *(_OWORD *)&v170[32] = v60;
          *(_OWORD *)&v170[48] = v61;
          v57 = *(float *)&v170[52];
          v56 = *(float *)&v61;
          v160 = v44;
          v153 = *((float *)&v61 + 3);
          LODWORD(v168) = DWORD2(v61);
        }
        v62 = (__m128)*(unsigned int *)v171;
        LODWORD(v63) = (((((unsigned int)*(unsigned __int16 *)(v45 - 20) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(v45 - 20) & 0x3FF | 8 * (*(_WORD *)(v45 - 20) & 0x8000)) << 13);
        LODWORD(v64) = (((((unsigned int)*(unsigned __int16 *)(v45 - 22) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(v45 - 22) & 0x3FF | 8 * (*(_WORD *)(v45 - 22) & 0x8000)) << 13);
        v65 = *(unsigned __int16 *)(v45 - 14);
        LODWORD(v187) = (((((unsigned int)*(unsigned __int16 *)(v45 - 24) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(v45 - 24) & 0x3FF | 8 * (*(_WORD *)(v45 - 24) & 0x8000)) << 13);
        v66 = (float)((float)((float)(v187 * *(float *)v171) + (float)(v64 * *(float *)&v171[16]))
                    + (float)(v63 * *(float *)&v171[32]))
            + v49;
        translation.x = v66;
        v67 = (float)((float)((float)(v187 * *(float *)&v171[4]) + (float)(v64 * *(float *)&v171[20]))
                    + (float)(v63 * *(float *)&v171[36]))
            + v50;
        translation.y = (float)((float)((float)(v187 * *(float *)&v171[4]) + (float)(v64 * *(float *)&v171[20]))
                              + (float)(v63 * *(float *)&v171[36]))
                      + v50;
        v68 = (float)((float)((float)(v187 * *(float *)&v171[8]) + (float)(v64 * *(float *)&v171[24]))
                    + (float)(v63 * *(float *)&v171[40]))
            + v164;
        translation.z = (float)((float)((float)(v187 * *(float *)&v171[8]) + (float)(v64 * *(float *)&v171[24]))
                              + (float)(v63 * *(float *)&v171[40]))
                      + v164;
        LODWORD(v69) = ((((v65 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v65 & 0x3FF | 8 * (v65 & 0xFFFF8000)) << 13);
        LODWORD(v70) = (((((unsigned int)*(unsigned __int16 *)(v45 - 16) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(v45 - 16) & 0x3FF | 8 * (*(_WORD *)(v45 - 16) & 0x8000)) << 13);
        v72 = (__m128)LODWORD(v70);
        LODWORD(v186) = (((((unsigned int)*(unsigned __int16 *)(v45 - 18) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(v45 - 18) & 0x3FF | 8 * (*(_WORD *)(v45 - 18) & 0x8000)) << 13);
        v71 = (float)((float)((float)(v70 * *(float *)&v170[16]) + (float)(*(float *)v170 * v186))
                    + (float)(v69 * *(float *)&v170[32]))
            + v56;
        v72.m128_f32[0] = (float)((float)((float)(v70 * *(float *)&v170[20]) + (float)(*(float *)&v170[4] * v186))
                                + (float)(v69 * *(float *)&v170[36]))
                        + v57;
        v73 = (float)((float)((float)(v70 * *(float *)&v170[24]) + (float)(*(float *)&v170[8] * v186))
                    + (float)(v69 * *(float *)&v170[40]))
            + *(float *)&v168;
        if ( v66 != v71 || v67 != v72.m128_f32[0] || v68 != v73 )
        {
          if ( *(float *)v171 != *(float *)v170
            || *(float *)&v171[4] != *(float *)&v170[4]
            || *(float *)&v171[8] != *(float *)&v170[8]
            || *(float *)&v171[12] != *(float *)&v170[12]
            || *(float *)&v171[16] != *(float *)&v170[16]
            || *(float *)&v171[20] != *(float *)&v170[20]
            || *(float *)&v171[24] != *(float *)&v170[24]
            || *(float *)&v171[28] != *(float *)&v170[28]
            || *(float *)&v171[32] != *(float *)&v170[32]
            || *(float *)&v171[36] != *(float *)&v170[36]
            || *(float *)&v171[40] != *(float *)&v170[40]
            || *(float *)&v171[44] != *(float *)&v170[44]
            || v158 != v56
            || v50 != v57
            || v164 != *(float *)&v168
            || lifetime != v153 )
          {
            v154 = v44;
          }
          else
          {
            v62.m128_f32[0] = (float)((float)(*(float *)v171 * *(float *)v171)
                                    + (float)(*(float *)&v171[4] * *(float *)&v171[4]))
                            + (float)(*(float *)&v171[8] * *(float *)&v171[8]);
            LODWORD(v154) = (unsigned __int128)_mm_sqrt_ps(v62);
          }
          v74 = v71 - v66;
          v72.m128_f32[0] = v72.m128_f32[0] - v67;
          v75 = v73 - v68;
          v76 = v72;
          v76.m128_f32[0] = (float)((float)(v72.m128_f32[0] * v72.m128_f32[0]) + (float)(v74 * v74))
                          + (float)(v75 * v75);
          if ( v76.m128_f32[0] == 0.0 )
            v77 = 0.0;
          else
            v77 = v44 / COERCE_FLOAT(_mm_sqrt_ps(v76));
          *(_QWORD *)&up.x = 0i64;
          up.z = 1.0;
          scale.y = 1.0;
          scale.z = 1.0;
          forward.x = v74 * v77;
          forward.y = v72.m128_f32[0] * v77;
          LODWORD(scale.x) = (unsigned __int128)_mm_sqrt_ps(v76);
          forward.z = v75 * v77;
          UFG::qScaleMatrix((UFG::qMatrix44 *)&v190, &scale);
          if ( !UFG::qMakeMatrix(&dest, &forward, &up, &translation, 0.001) )
          {
            v175.x = 0.0;
            *(_QWORD *)&v175.y = 1065353216i64;
            UFG::qMakeMatrix(&dest, &forward, &v175, &translation, 0.001);
          }
          v78 = *(float *)(v45 + 24);
          v79 = v169;
          v80 = *(float *)(v45 + 28);
          boltArraya = v169 - v78;
          lifetimea = (float)(v169 - v78) / (float)(*(float *)(v45 + 28) - v78);
          v81 = (signed int)(float)(powf(2.0, (float)(*(_DWORD *)(v45 + 8) + 1)) + v44);
          v168 = v81;
          if ( v79 <= v80 && v79 >= v78 && v81 >= 2 )
          {
            v82 = v81 - 1;
            v83 = v161 + 6 * (v81 - 1);
            v84 = v83 < 0x6D60;
            v85 = v83 == 28000;
            v86 = v198;
            if ( !v84 && !v85 )
            {
              v150 = v199;
              v42 = v167;
              v199[3] = 1;
              goto LABEL_94;
            }
            if ( v198 + 8 * v82 > 0x2710 )
            {
              v150 = v199;
              v42 = v167;
              v199[3] = 2;
              goto LABEL_94;
            }
            v159 = v44 / (float)(signed int)v82;
            v183 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(_mm_shuffle_ps(v190, v190, 0), (__m128)dest.v0),
                                          (__m128)0i64),
                                        _mm_mul_ps(_mm_shuffle_ps(v190, v190, 85), (__m128)dest.v1)),
                                      _mm_mul_ps(_mm_shuffle_ps(v190, v190, 170), (__m128)dest.v2)),
                                    _mm_mul_ps(_mm_shuffle_ps(v190, v190, 255), (__m128)dest.v3));
            v87 = v47->pos.x;
            v88 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v191, v191, 0), (__m128)dest.v0), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v191, v191, 85), (__m128)dest.v1)),
                      _mm_mul_ps(_mm_shuffle_ps(v191, v191, 170), (__m128)dest.v2)),
                    _mm_mul_ps(_mm_shuffle_ps(v191, v191, 255), (__m128)dest.v3));
            v89 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v192, v192, 0), (__m128)dest.v0), (__m128)0i64),
                        _mm_mul_ps(_mm_shuffle_ps(v192, v192, 85), (__m128)dest.v1)),
                      _mm_mul_ps(_mm_shuffle_ps(v192, v192, 170), (__m128)dest.v2)),
                    _mm_mul_ps(_mm_shuffle_ps(v192, v192, 255), (__m128)dest.v3));
            v185 = (UFG::qVector4)_mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps((__m128)dest.v0, _mm_shuffle_ps(v193, v193, 0)),
                                          (__m128)0i64),
                                        _mm_mul_ps(_mm_shuffle_ps(v193, v193, 85), (__m128)dest.v1)),
                                      _mm_mul_ps(_mm_shuffle_ps(v193, v193, 170), (__m128)dest.v2)),
                                    _mm_mul_ps(_mm_shuffle_ps(v193, v193, 255), (__m128)dest.v3));
            v184 = (UFG::qVector4)v88;
            v182 = (UFG::qVector4)v89;
            v90 = v47->pos.y;
            v91 = v47->pos.z;
            v92 = v82;
            v93 = v82;
            LODWORD(v94) = (unsigned __int128)_mm_shuffle_ps(v88, v88, 85);
            LODWORD(v95) = (unsigned __int128)_mm_shuffle_ps(v88, v88, 170);
            LODWORD(v96) = (unsigned __int128)_mm_shuffle_ps((__m128)v183, (__m128)v183, 85);
            LODWORD(v97) = (unsigned __int128)_mm_shuffle_ps((__m128)v183, (__m128)v183, 170);
            v98 = v89.m128_f32[0];
            v89.m128_i32[0] = (unsigned __int128)_mm_shuffle_ps((__m128)v185, (__m128)v185, 85);
            v99 = (float)((float)((float)(v88.m128_f32[0] * v90) + (float)(v183.x * v87)) + (float)(v98 * v91)) + v185.x;
            LODWORD(v100) = (unsigned __int128)_mm_shuffle_ps((__m128)v185, (__m128)v185, 170);
            LODWORD(v101) = (unsigned __int128)_mm_shuffle_ps((__m128)v182, (__m128)v182, 85);
            LODWORD(v102) = (unsigned __int128)_mm_shuffle_ps((__m128)v182, (__m128)v182, 170);
            v103 = v47[v93].pos.z;
            v104 = (float)((float)((float)(v94 * v90) + (float)(v96 * v87)) + (float)(v101 * v91)) + v89.m128_f32[0];
            v105 = v97 * v87;
            v106 = v47[v93].pos.y;
            v88.m128_f32[0] = (float)(v95 * v90) + v105;
            v107 = v102 * v91;
            v108 = v47[v93].pos.x;
            v109 = (float)((float)((float)(v184.x * v106) + (float)(v183.x * v108)) + (float)(v182.x * v103)) + v185.x;
            v110 = (float)((float)((float)(v94 * v106) + (float)(v96 * v108)) + (float)(v101 * v103)) + v89.m128_f32[0];
            v111 = 0.0;
            v112 = (float)((float)((float)(v95 * v106) + (float)(v97 * v108)) + (float)(v102 * v103)) + v100;
            v113 = (float)(v104 - v110) * (float)(v104 - v110);
            v114 = (__m128)LODWORD(forward.y);
            v115 = (__m128)LODWORD(forward.z);
            v119 = v114;
            v116 = 0.0;
            v117 = (float)(v113 + (float)((float)(v99 - v109) * (float)(v99 - v109)))
                 + (float)((float)((float)((float)(v88.m128_f32[0] + v107) + v100) - v112)
                         * (float)((float)((float)(v88.m128_f32[0] + v107) + v100) - v112));
            v44 = *(float *)&FLOAT_1_0;
            v155 = fsqrt(v117);
            v118 = (float)(25.0 / (float)(signed int)v81) * v173->mTexCoordScale;
            v119.m128_f32[0] = (float)((float)(v114.m128_f32[0] * v114.m128_f32[0]) + (float)(forward.x * forward.x))
                             + (float)(v115.m128_f32[0] * v115.m128_f32[0]);
            if ( v119.m128_f32[0] == 0.0 )
              v120 = 0.0;
            else
              v120 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v119));
            v121 = forward.x * v120;
            v122 = forward.y * v120;
            v115.m128_f32[0] = forward.z * v120;
            v123 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
            v178.m128_f32[0] = forward.x * v120;
            v178.m128_f32[1] = forward.y * v120;
            v178.m128_u64[1] = COERCE_UNSIGNED_INT(forward.z * v120);
            v123.m128_f32[0] = (float)((float)(v123.m128_f32[0] * v123.m128_f32[0])
                                     + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                             + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
            if ( v123.m128_f32[0] == 0.0 )
            {
              v125 = 0i64;
            }
            else
            {
              LODWORD(v124) = (unsigned __int128)_mm_sqrt_ps(v123);
              v125 = (__m128)(unsigned int)FLOAT_1_0;
              v125.m128_f32[0] = 1.0 / v124;
            }
            v126 = v125;
            v127 = v125.m128_f32[0];
            v128 = v125.m128_f32[0] * UFG::qVector3::msDirUp.z;
            v126.m128_f32[0] = v126.m128_f32[0] * UFG::qVector3::msDirUp.y;
            v129 = v127 * UFG::qVector3::msDirUp.x;
            v130 = v126;
            v130.m128_f32[0] = (float)(v126.m128_f32[0] * v115.m128_f32[0]) - (float)(v128 * v122);
            v133 = v130;
            v131 = (float)(v128 * v121) - (float)(v129 * v115.m128_f32[0]);
            v132 = (float)(v129 * v122) - (float)(v126.m128_f32[0] * v121);
            v133.m128_f32[0] = (float)((float)(v130.m128_f32[0] * v130.m128_f32[0]) + (float)(v131 * v131))
                             + (float)(v132 * v132);
            if ( v133.m128_f32[0] == 0.0 )
              v134 = 0.0;
            else
              v134 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v133));
            *(float *)&v135 = v130.m128_f32[0] * v134;
            *(float *)&v136 = v134 * v131;
            *(float *)&v137 = v134 * v132;
            v179.m128_u64[0] = __PAIR__(v136, v135);
            v179.m128_u64[1] = v137;
            v138 = (float)(v122 * *(float *)&v137) - (float)(v115.m128_f32[0] * *(float *)&v136);
            v115.m128_f32[0] = (float)(v115.m128_f32[0] * *(float *)&v135) - (float)(v121 * *(float *)&v137);
            v139 = (float)(v121 * *(float *)&v136) - (float)(v122 * *(float *)&v135);
            v140 = v115;
            v140.m128_f32[0] = (float)((float)(v115.m128_f32[0] * v115.m128_f32[0]) + (float)(v138 * v138))
                             + (float)(v139 * v139);
            if ( v140.m128_f32[0] != 0.0 )
              v116 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v140));
            v141 = *(float *)(v45 + 36);
            v181.m128_i32[3] = 1065353216;
            *(UFG::qVector3 *)v181.m128_f32 = UFG::qVector3::msZero;
            v180.m128_f32[0] = v138 * v116;
            v180.m128_f32[1] = v115.m128_f32[0] * v116;
            v180.m128_u64[1] = COERCE_UNSIGNED_INT(v139 * v116);
            UFG::qRotationMatrixX(&v194, v141);
            params.perpendicularMat.v0 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 0),
                                                                  v178),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 85),
                                                                v179)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 170),
                                                              v180)),
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 255),
                                                            v181));
            params.perpendicularMat.v1 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 255),
                                                            v181),
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 0),
                                                                  v178),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 85),
                                                                v179)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 170),
                                                              v180)));
            params.settings = v173;
            params.lengthOfBolt = v155;
            v142 = *(float *)(v45 + 40);
            params.perpendicularMat.v3 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 85),
                                                                v179),
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 0),
                                                                  v178),
                                                                (__m128)0i64)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 170),
                                                              v180)),
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 255),
                                                            v181));
            params.curve = v142;
            params.mat.v0 = v183;
            params.mat.v1 = v184;
            params.perpendicularMat.v2 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 255),
                                                            v181),
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 0),
                                                                  v178),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 85),
                                                                v179)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 170),
                                                              v180)));
            params.mat.v2 = v182;
            params.boltDirection.y = forward.y;
            params.mat.v3 = v185;
            params.timeElapsed = boltArraya;
            params.speed = *(float *)(v45 + 32);
            params.boltDirection.x = forward.x;
            params.boltDirection.z = forward.z;
            v143 = Render::ComputeInterpolatedColour(
                     &result,
                     v173->mColorAlphaKeys,
                     v173->mColorKeyPositions,
                     v173->mAlphaKeyPositions,
                     lifetimea);
            v144 = v143->g;
            params.colour.r = v143->r;
            v145 = v143->b;
            params.colour.g = v144;
            v146 = v143->a;
            params.colour.b = v145;
            params.transformScale = v154;
            v147 = *(float *)(v174 + 116);
            params.colour.a = v146;
            params.sizeScale = v147;
            params.orientation = UFG::qRandom(1.0, &seed);
            if ( (_DWORD)v168 != 1 )
            {
              v148 = v165;
              LODWORD(v167) = v92 + v167;
              v149 = 0.0;
              v161 += 6 * v92;
              v198 += 2 * v92;
              do
              {
                Render::WriteMiddleVertex(
                  v47,
                  &params,
                  v149,
                  v111,
                  (float)((float)(v160 - v165) * v149) + v148,
                  v41,
                  memory_streamera);
                v148 = v165;
                v149 = v149 + v159;
                v111 = v111 + v118;
                v7[2] = v9 + 2;
                v7[3] = v9 + 2;
                *v7 = v9;
                v7[1] = v9 + 1;
                v7[4] = v9 + 1;
                v7[5] = v9 + 3;
                v7 += 6;
                v9 += 2;
                ++v47;
                v41 += 64;
                --v92;
              }
              while ( v92 );
              v44 = *(float *)&FLOAT_1_0;
            }
            Render::WriteTerminalVertex(v47, &params, v111, v41, memory_streamera);
            v198 += 2;
            v9 += 2;
            v41 += 64;
          }
        }
        v43 = v151;
LABEL_88:
        ++v43;
        v45 += 72i64;
        v151 = v43;
        if ( v43 >= v152 )
        {
          v42 = v167;
          v86 = v198;
          goto LABEL_93;
        }
      }
    }
    v86 = 0;
LABEL_93:
    v150 = v199;
LABEL_94:
    *v150 = v42;
    v150[2] = v161;
    v150[1] = v86;
    v150[4] = v152;
  }
}

