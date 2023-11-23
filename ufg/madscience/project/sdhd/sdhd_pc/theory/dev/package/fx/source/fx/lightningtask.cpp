// File Line: 168
// RVA: 0x146BC10
__int64 Render::_dynamic_initializer_for__gTaskFunctionDecl_LightningTask__()
{
  UFG::qTaskFunctionDecl::qTaskFunctionDecl(
    &Render::gTaskFunctionDecl_LightningTask,
    &Render::gTaskFunctionDeclData_LightningTask);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gTaskFunctionDecl_LightningTask__);
}

// File Line: 204
// RVA: 0x1E5A40
char __fastcall Render::GetHeadTransform(
        Render::ElectrifiedObject *object,
        UFG::qMemoryStreamer *memory_streamer,
        UFG::qMatrix44 *result,
        float *alpha)
{
  Render::LightweightFXPosition *m_pPointer; // rax
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  UFG::SimComponent *v11; // rsi
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 m_BoundComponentHandles; // xmm2

  m_pPointer = object->headLightWeightPosition.m_pPointer;
  if ( m_pPointer )
  {
    v7 = UFG::qMatrix44::msIdentity.v1;
    v8 = UFG::qMatrix44::msIdentity.v2;
    v9 = UFG::qMatrix44::msIdentity.v3;
    result->v0 = UFG::qMatrix44::msIdentity.v0;
    result->v1 = v7;
    result->v2 = v8;
    result->v3 = v9;
    v7.x = m_pPointer->position.y;
    v8.x = m_pPointer->position.z;
    result->v3.x = m_pPointer->position.x;
    result->v3.w = 1.0;
    result->v3.y = v7.x;
    result->v3.z = v8.x;
    if ( alpha )
      *alpha = m_pPointer->alpha;
    return 1;
  }
  else
  {
    v11 = object->headTransformNodeComponent.m_pPointer;
    if ( v11 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)object->headTransformNodeComponent.m_pPointer);
      v12 = *(UFG::qVector4 *)&v11[2].m_SafePointerList.mNode.mNext;
      v13 = *(UFG::qVector4 *)&v11[2].m_Flags;
      m_BoundComponentHandles = (UFG::qVector4)v11[2].m_BoundComponentHandles;
      result->v0 = *(UFG::qVector4 *)&v11[2].vfptr;
      result->v1 = v12;
      result->v2 = v13;
      result->v3 = m_BoundComponentHandles;
      if ( alpha )
        *alpha = 1.0;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 238
// RVA: 0x1E5B40
char __fastcall Render::GetTailTransform(
        Render::ElectrifiedObject *object,
        UFG::qMemoryStreamer *memory_streamer,
        UFG::qMatrix44 *result,
        float *alpha)
{
  Render::LightweightFXPosition *m_pPointer; // rax
  UFG::qVector4 v7; // xmm1
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm3
  UFG::SimComponent *v11; // rsi
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 m_BoundComponentHandles; // xmm2

  m_pPointer = object->tailLightWeightPosition.m_pPointer;
  if ( m_pPointer )
  {
    v7 = UFG::qMatrix44::msIdentity.v1;
    v8 = UFG::qMatrix44::msIdentity.v2;
    v9 = UFG::qMatrix44::msIdentity.v3;
    result->v0 = UFG::qMatrix44::msIdentity.v0;
    result->v1 = v7;
    result->v2 = v8;
    result->v3 = v9;
    v7.x = m_pPointer->position.y;
    v8.x = m_pPointer->position.z;
    result->v3.x = m_pPointer->position.x;
    result->v3.w = 1.0;
    result->v3.y = v7.x;
    result->v3.z = v8.x;
    if ( alpha )
      *alpha = m_pPointer->alpha;
    return 1;
  }
  else
  {
    v11 = object->tailTransformNodeComponent.m_pPointer;
    if ( v11 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)object->tailTransformNodeComponent.m_pPointer);
      v12 = *(UFG::qVector4 *)&v11[2].m_SafePointerList.mNode.mNext;
      v13 = *(UFG::qVector4 *)&v11[2].m_Flags;
      m_BoundComponentHandles = (UFG::qVector4)v11[2].m_BoundComponentHandles;
      result->v0 = *(UFG::qVector4 *)&v11[2].vfptr;
      result->v1 = v12;
      result->v2 = v13;
      result->v3 = m_BoundComponentHandles;
      if ( alpha )
        *alpha = 1.0;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}

// File Line: 296
// RVA: 0x1E5030
__int64 __fastcall Render::GenerateBoltsOnObject(
        Render::ElectrifiedObject *object,
        Render::ElectrifiedObjectSortContainer *container,
        UFG::qMemoryStreamer *memory_streamer,
        Render::Bolt *boltArray)
{
  unsigned int v6; // eax
  __int64 v7; // rdi
  unsigned int v8; // esi
  Render::LightningSettings *settings; // r14
  __m128 v10; // xmm1
  int v11; // ecx
  Illusion::Model *headModel; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  unsigned int v15; // ecx
  Illusion::Model *tailModel; // rcx
  __int64 v17; // r8
  __int64 v18; // r9
  unsigned int v19; // ecx
  unsigned int v20; // r12d
  unsigned __int64 v21; // r15
  unsigned int v22; // r13d
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
  int v33; // r12d
  unsigned __int64 v34; // rcx
  int *mSeed; // rbx
  int v36; // eax
  unsigned int v37; // ebx
  int v38; // r13d
  float v39; // xmm6_4
  float v40; // xmm8_4
  float v41; // xmm9_4
  float v42; // xmm3_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  int v45; // ebx
  int v46; // esi
  unsigned int v47; // r15d
  float v48; // xmm13_4
  unsigned int v49; // r10d
  __int64 v50; // r11
  float *v51; // r9
  __int64 v52; // rdx
  float *v53; // rcx
  float *v54; // rax
  int v55; // eax
  __int64 v56; // rax
  int v57; // eax
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
  int v68; // eax
  float mLifeMin; // xmm6_4
  float mSpeedMin; // xmm6_4
  float mCurveMin; // xmm6_4
  unsigned int v73; // [rsp+20h] [rbp-A8h]
  int v74; // [rsp+24h] [rbp-A4h]
  float v75; // [rsp+28h] [rbp-A0h]
  UFG::qVector3 t; // [rsp+30h] [rbp-98h] BYREF
  unsigned __int64 v77; // [rsp+40h] [rbp-88h] BYREF
  Illusion::Model *v78; // [rsp+48h] [rbp-80h]
  float v79; // [rsp+50h] [rbp-78h]
  unsigned int v80; // [rsp+54h] [rbp-74h]
  unsigned __int64 v81; // [rsp+58h] [rbp-70h]
  unsigned __int64 v82; // [rsp+60h] [rbp-68h]
  Render::FXqTaskMeshReader v83; // [rsp+70h] [rbp-58h] BYREF
  char ptr[8]; // [rsp+120h] [rbp+58h] BYREF
  __int64 v85; // [rsp+128h] [rbp+60h]
  __int64 v86; // [rsp+140h] [rbp+78h]
  __int64 v87; // [rsp+150h] [rbp+88h]
  __int64 v88; // [rsp+158h] [rbp+90h]
  __int64 v89; // [rsp+160h] [rbp+98h]
  __int64 v90; // [rsp+168h] [rbp+A0h]
  UFG::qMemoryStreamer *v91; // [rsp+170h] [rbp+A8h]
  float v92; // [rsp+178h] [rbp+B0h]
  int range; // [rsp+17Ch] [rbp+B4h]
  char v94; // [rsp+180h] [rbp+B8h]
  int v95; // [rsp+184h] [rbp+BCh]
  int *pseed; // [rsp+188h] [rbp+C0h]
  __int64 v97; // [rsp+198h] [rbp+D0h]
  UFG::qString v98; // [rsp+1A0h] [rbp+D8h] BYREF
  UFG::qString v99; // [rsp+1C8h] [rbp+100h] BYREF
  _QWORD *v100; // [rsp+2D8h] [rbp+210h]
  __int64 v101; // [rsp+2E0h] [rbp+218h]
  __int64 v102; // [rsp+2F0h] [rbp+228h]
  unsigned int v103; // [rsp+2F8h] [rbp+230h]
  __int64 vars0; // [rsp+300h] [rbp+238h]

  v97 = -2i64;
  v6 = 800;
  v7 = vars0;
  if ( *(_DWORD *)(vars0 + 464) )
    v6 = 400;
  v80 = v6;
  v8 = v103;
  if ( v103 < v6 )
  {
    settings = object->settings;
    if ( settings )
    {
      v74 = 20;
      v10 = (__m128)*(unsigned int *)(vars0 + 460);
      v10.m128_f32[0] = v10.m128_f32[0] * settings->mEmissionRate;
      v11 = (int)v10.m128_f32[0];
      if ( (int)v10.m128_f32[0] != 0x80000000 && (float)v11 != v10.m128_f32[0] )
        v10.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v10, v10)) & 1) + v11);
      LODWORD(vars0) = (int)v10.m128_f32[0];
      if ( object->framesElapsed == 1 )
        LODWORD(vars0) = settings->mEmissionInit + (int)v10.m128_f32[0];
      Render::FXqTaskMeshReader::FXqTaskMeshReader(&v83);
      headModel = object->headModel;
      if ( headModel )
      {
        v83.mpVertexBuffers[0] = (Illusion::Buffer *)&seed;
        v83.mVertexBuffers[1].mName = (const char *)memory_streamer;
        v83.mModelAddrInMainMem = headModel;
        v78 = headModel;
        v82 = (unsigned __int64)&headModel->mMeshOffsetTable
            + headModel->mMeshOffsetTable.mOffset
            + *(unsigned int *)((char *)&headModel->mMeshOffsetTable.mOffset + headModel->mMeshOffsetTable.mOffset);
        *(&v83.mVertexBuffers[1].mState + 1) = 0;
        v13 = *(_QWORD *)(v82 + 112);
        v83.mModelStream.mName = (const char *)v13;
        v14 = *(_QWORD *)(v82 + 144);
        v83.mMeshStream.mName = (const char *)v14;
        v15 = *(_DWORD *)(v13 + 108);
        HIDWORD(v83.mVertexBuffers[1].mMainMemoryAddress) = v15;
        if ( v15 )
        {
          *(float *)&v83.mVertexBuffers[1].mMainMemoryAddress = (float)(0 % v15);
          *(_QWORD *)&v83.mMeshStream.mState = v13;
          v83.mVertexBuffers[0].mMainMemoryAddress = (void *)(*(_QWORD *)(v13 + 96) + v13 + 96);
          v83.mVertexBuffers[0].mName = (const char *)v14;
          *(_QWORD *)&v83.mVertexBuffers[0].mState = *(_QWORD *)(v14 + 96) + v14 + 96;
        }
        LOBYTE(v83.mVertexBuffers[1].mState) = 1;
      }
      Render::FXqTaskMeshReader::FXqTaskMeshReader((Render::FXqTaskMeshReader *)v83.mpMainMemoryVertexBuffers);
      tailModel = object->tailModel;
      if ( tailModel )
      {
        pseed = &seed;
        v91 = memory_streamer;
        v83.mpMainMemoryVertexBuffers[0] = tailModel;
        v83.mMemoryStreamer = (UFG::qMemoryStreamer *)tailModel;
        v83.mSeed = (int *)((char *)&tailModel->mMeshOffsetTable
                          + tailModel->mMeshOffsetTable.mOffset
                          + *(unsigned int *)((char *)&tailModel->mMeshOffsetTable.mOffset
                                            + tailModel->mMeshOffsetTable.mOffset));
        v95 = 0;
        v17 = *((_QWORD *)v83.mSeed + 14);
        v85 = v17;
        v18 = *((_QWORD *)v83.mSeed + 18);
        v86 = v18;
        v19 = *(_DWORD *)(v17 + 108);
        range = v19;
        if ( v19 )
        {
          v92 = (float)(0 % v19);
          v87 = v17;
          v89 = *(_QWORD *)(v17 + 96) + v17 + 96;
          v88 = v18;
          v90 = *(_QWORD *)(v18 + 96) + v18 + 96;
        }
        v94 = 1;
      }
      v82 = v77;
      v20 = vars0;
      v21 = v77;
      v81 = v77;
      v22 = vars0;
      v23 = vars0;
      while ( 1 )
      {
        if ( v23 <= 0 || v74 <= 0 )
        {
LABEL_67:
          `eh vector destructor iterator(ptr, 0x18ui64, 2, (void (__fastcall *)(void *))_);
          `eh vector destructor iterator(&v83, 0x18ui64, 2, (void (__fastcall *)(void *))_);
          return v8;
        }
        v24 = 0.0;
        t.x = 0.0;
        v25 = 0.0;
        t.y = 0.0;
        v26 = 0.0;
        t.z = 0.0;
        v27 = 0.0;
        v77 = 0i64;
        v28 = 0.0;
        v29 = 0.0;
        v75 = 0.0;
        LODWORD(v78) = 0;
        if ( LOBYTE(v83.mVertexBuffers[1].mState) )
        {
          v30 = v82;
          v31 = UFG::qRandom(HIDWORD(v83.mVertexBuffers[1].mMainMemoryAddress), (unsigned int *)v83.mpVertexBuffers[0]);
          v32 = *(_DWORD *)(v30 + 56);
          if ( v83.mVertexBuffers[0].mMainMemoryAddress )
          {
            v33 = LODWORD(v83.mVertexBuffers[0].mMainMemoryAddress)
                + v31 * *(_DWORD *)(*(_QWORD *)&v83.mMeshStream.mState + 104i64);
            v34 = ((unsigned __int64)v83.mVertexBuffers[0].mMainMemoryAddress
                 + (unsigned int)(v31 * *(_DWORD *)(*(_QWORD *)&v83.mMeshStream.mState + 104i64))) & 0xFFFFFFFFFFFFFFF0ui64;
            v82 = v34;
            v20 = v33 & 0xF;
          }
          else
          {
            v34 = v82;
          }
          if ( v32 == 883623142 )
          {
            v24 = *(float *)(v20 + v34);
            v25 = *(float *)(v20 + v34 + 4);
            v26 = *(float *)(v20 + v34 + 8);
            t.x = v24;
            t.y = v25;
            t.z = v26;
          }
          else
          {
            UFG::qString::qString(&v98);
            UFG::qString::Format(
              &v98,
              "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
              v32);
            UFG::qString::~qString(&v98);
          }
        }
        if ( v94 )
        {
          mSeed = v83.mSeed;
          v36 = UFG::qRandom(range, (unsigned int *)pseed);
          v37 = mSeed[14];
          if ( v89 )
          {
            v38 = v89 + v36 * *(_DWORD *)(v87 + 104);
            v21 = (v89 + (unsigned int)(v36 * *(_DWORD *)(v87 + 104))) & 0xFFFFFFFFFFFFFFF0ui64;
            v81 = v21;
            v22 = v38 & 0xF;
          }
          if ( v37 == 883623142 )
          {
            v27 = *(float *)(v22 + v21);
            v28 = *(float *)(v22 + v21 + 4);
            v29 = *(float *)(v22 + v21 + 8);
            v75 = v29;
            v77 = __PAIR64__(LODWORD(v28), LODWORD(v27));
            *(float *)&v78 = v29;
          }
          else
          {
            UFG::qString::qString(&v99);
            UFG::qString::Format(
              &v99,
              "FXqTaskMeshReader error: Mesh is of the format %x. I cannot decode this format. Talk to Michael Riegger\n",
              v37);
            UFG::qString::~qString(&v99);
          }
        }
        v39 = (float)((float)((float)(v25 * *(float *)(v101 + 16)) + (float)(v24 * *(float *)v101))
                    + (float)(v26 * *(float *)(v101 + 32)))
            + *(float *)(v101 + 48);
        v40 = (float)((float)((float)(v25 * *(float *)(v101 + 20)) + (float)(v24 * *(float *)(v101 + 4)))
                    + (float)(v26 * *(float *)(v101 + 36)))
            + *(float *)(v101 + 52);
        v41 = (float)((float)((float)(v25 * *(float *)(v101 + 24)) + (float)(v24 * *(float *)(v101 + 8)))
                    + (float)(v26 * *(float *)(v101 + 40)))
            + *(float *)(v101 + 56);
        v42 = (float)((float)((float)(v28 * *(float *)(v101 + 80)) + (float)(v27 * *(float *)(v101 + 64)))
                    + (float)(v29 * *(float *)(v101 + 96)))
            + *(float *)(v101 + 112);
        v43 = (float)((float)((float)(v28 * *(float *)(v101 + 84)) + (float)(v27 * *(float *)(v101 + 68)))
                    + (float)(v29 * *(float *)(v101 + 100)))
            + *(float *)(v101 + 116);
        v44 = (float)((float)((float)(v28 * *(float *)(v101 + 88)) + (float)(v27 * *(float *)(v101 + 72)))
                    + (float)(v29 * *(float *)(v101 + 104)))
            + *(float *)(v101 + 120);
        v79 = fsqrt(
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
        if ( v100[11] == v100[12] )
        {
          v60 = (float)((float)((float)(v24 - v27) * (float)(v24 - v27))
                      + (float)((float)(v25 - v28) * (float)(v25 - v28)))
              + (float)((float)(v26 - v75) * (float)(v26 - v75));
          v61 = v60 >= (float)(settings->mLengthMin * settings->mLengthMin);
          v62 = (float)(settings->mLengthMax * settings->mLengthMax) >= v60;
        }
        else
        {
          v61 = v79 >= settings->mLengthMin;
          v62 = v79 <= settings->mLengthMax;
        }
        if ( v61 && v62 && v59 )
        {
          v63 = v103;
          v64 = v102 + 72i64 * v103;
          UFG::qHalfVector3::operator=((UFG::qHalfVector3 *)v64, &t);
          UFG::qHalfVector3::operator=((UFG::qHalfVector3 *)(v64 + 6), (UFG::qVector3 *)&v77);
          *(_QWORD *)(v64 + 16) = v100[10];
          v65 = *(float *)(v7 + 12 * (v47 + 32i64) + 8);
          v66 = *(float *)(v7 + 12 * (v47 + 32i64) + 4) - v40;
          v67 = (__m128)*(unsigned int *)(v7 + 12 * (v47 + 32i64));
          v67.m128_f32[0] = (float)((float)((float)(v67.m128_f32[0] - v39) * (float)(v67.m128_f32[0] - v39))
                                  + (float)(v66 * v66))
                          + (float)((float)(v65 - v41) * (float)(v65 - v41));
          v68 = (int)(float)((float)(3.0 - (float)(_mm_sqrt_ps(v67).m128_f32[0] * 0.029999999)) + 0.5);
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
          *(_QWORD *)(v64 + 40) = *(_QWORD *)(v101 + 128);
          *(_DWORD *)(v64 + 48) = *(_DWORD *)(v7 + 456);
          mLifeMin = settings->mLifeMin;
          *(float *)(v64 + 52) = (float)(UFG::qRandom(1.0, (unsigned int *)&seed)
                                       * (float)(settings->mLifeMax - mLifeMin))
                               + (float)(mLifeMin + *(float *)(v7 + 456));
          mSpeedMin = settings->mSpeedMin;
          *(float *)(v64 + 56) = (float)(UFG::qRandom(1.0, (unsigned int *)&seed)
                                       * (float)(settings->mSpeedMax - mSpeedMin))
                               + mSpeedMin;
          *(float *)(v64 + 60) = UFG::qRandom(6.2831855, (unsigned int *)&seed);
          mCurveMin = settings->mCurveMin;
          *(float *)(v64 + 64) = (float)(UFG::qRandom(1.0, (unsigned int *)&seed)
                                       * (float)(settings->mCurveMax - mCurveMin))
                               + mCurveMin;
          v8 = v63 + 1;
          v103 = v8;
          v23 = vars0 - 1;
          LODWORD(vars0) = vars0 - 1;
        }
        else
        {
          --v74;
          v8 = v103;
          v23 = vars0;
        }
        v21 = v81;
        if ( v8 >= v80 )
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
void __fastcall Render::WriteTerminalVertex(
        LightningJoint *joint,
        Render::BoltConstantData *params,
        float vTexcoord,
        float *mainMemoryVertexBuffer)
{
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm6_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  unsigned int v14; // ebx
  unsigned int v15; // edx
  int v16; // r8d
  __int16 v17; // r8
  unsigned int v18; // edx
  unsigned int v19; // edx
  int v20; // r8d
  __int16 v21; // r8
  unsigned int v22; // edx
  unsigned int v23; // edx
  int v24; // r8d
  __int16 v25; // r8
  unsigned int v26; // edx
  unsigned int v27; // edx
  int v28; // r8d
  unsigned int v29; // edx
  float v30; // [rsp+50h] [rbp+18h]
  float v31; // [rsp+50h] [rbp+18h]

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
  *mainMemoryVertexBuffer = v7;
  mainMemoryVertexBuffer[1] = v8;
  mainMemoryVertexBuffer[2] = v9;
  mainMemoryVertexBuffer[9] = v8;
  mainMemoryVertexBuffer[8] = v7;
  mainMemoryVertexBuffer[10] = v9;
  v10 = v6 * params->boltDirection.x;
  v11 = v6 * params->boltDirection.y;
  mainMemoryVertexBuffer[5] = v6 * params->boltDirection.z;
  mainMemoryVertexBuffer[3] = v10;
  mainMemoryVertexBuffer[4] = v11;
  v12 = COERCE_FLOAT(LODWORD(params->boltDirection.x) ^ _xmm[0]) * v6;
  v13 = COERCE_FLOAT(LODWORD(params->boltDirection.y) ^ _xmm[0]) * v6;
  mainMemoryVertexBuffer[13] = COERCE_FLOAT(LODWORD(params->boltDirection.z) ^ _xmm[0]) * v6;
  mainMemoryVertexBuffer[11] = v12;
  mainMemoryVertexBuffer[12] = v13;
  v14 = ((int)(float)(params->colour.g * 255.0) << 8) | (int)(float)(params->colour.r * 255.0) & 0xFFFFFF00 | (((int)(float)(params->colour.b * 255.0) | ((int)(float)(params->colour.a * 255.0) << 8)) << 16);
  *((_DWORD *)mainMemoryVertexBuffer + 7) = v14;
  v30 = (float)(int)params->settings->mTexturePageU * 0.5;
  v15 = fabs(v30);
  v16 = HIWORD(LODWORD(v30)) & 0x8000;
  if ( v15 <= 0x47FFEFFF )
  {
    if ( v15 >= 0x38800000 )
      v18 = v15 - 939524096;
    else
      v18 = (v15 & 0x7FFFFF | 0x800000) >> (113 - (v15 >> 23));
    v17 = ((((v18 >> 13) & 1) + v18 + 4095) >> 13) | v16;
  }
  else
  {
    v17 = v16 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 12) = v17;
  v19 = LODWORD(vTexcoord) & 0x7FFFFFFF;
  v20 = HIWORD(LODWORD(vTexcoord)) & 0x8000;
  if ( (LODWORD(vTexcoord) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v19 >= 0x38800000 )
      v22 = v19 - 939524096;
    else
      v22 = (LODWORD(vTexcoord) & 0x7FFFFF | 0x800000u) >> (113 - (v19 >> 23));
    v21 = ((((v22 >> 13) & 1) + v22 + 4095) >> 13) | v20;
  }
  else
  {
    v21 = v20 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 13) = v21;
  *((_DWORD *)mainMemoryVertexBuffer + 15) = v14;
  v31 = (float)(params->settings->mTexturePageU + 1) * 0.5;
  v23 = fabs(v31);
  v24 = HIWORD(LODWORD(v31)) & 0x8000;
  if ( v23 <= 0x47FFEFFF )
  {
    if ( v23 >= 0x38800000 )
      v26 = v23 - 939524096;
    else
      v26 = (v23 & 0x7FFFFF | 0x800000) >> (113 - (v23 >> 23));
    v25 = ((((v26 >> 13) & 1) + v26 + 4095) >> 13) | v24;
  }
  else
  {
    v25 = v24 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 28) = v25;
  v27 = LODWORD(vTexcoord) & 0x7FFFFFFF;
  v28 = HIWORD(LODWORD(vTexcoord)) & 0x8000;
  if ( (LODWORD(vTexcoord) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v27 >= 0x38800000 )
      v29 = v27 - 939524096;
    else
      v29 = (LODWORD(vTexcoord) & 0x7FFFFF | 0x800000u) >> (113 - (v27 >> 23));
    *((_WORD *)mainMemoryVertexBuffer + 29) = v28 | ((((v29 >> 13) & 1) + v29 + 4095) >> 13);
  }
  else
  {
    *((_WORD *)mainMemoryVertexBuffer + 29) = v28 | 0x7FFF;
  }
}

// File Line: 475
// RVA: 0x1E5D40
void __fastcall Render::WriteMiddleVertex(
        LightningJoint *joint,
        Render::BoltConstantData *params,
        float t,
        float vTexcoord,
        float alpha,
        float *mainMemoryVertexBuffer)
{
  float jitter; // xmm0_4
  float lengthOfBolt; // xmm9_4
  Render::LightningSettings *settings; // rax
  float v11; // xmm4_4
  float v12; // xmm11_4
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm10_4
  float v16; // xmm8_4
  float v17; // xmm6_4
  float v18; // xmm11_4
  float v19; // xmm1_4
  float v20; // xmm11_4
  float v21; // xmm8_4
  float v22; // xmm6_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  int v27; // r11d
  unsigned int v28; // edx
  int v29; // r8d
  __int16 v30; // r8
  unsigned int v31; // edx
  unsigned int v32; // edx
  int v33; // r8d
  __int16 v34; // r8
  unsigned int v35; // edx
  unsigned int v36; // edx
  int v37; // r8d
  __int16 v38; // r8
  unsigned int v39; // edx
  unsigned int v40; // edx
  int v41; // r8d
  unsigned int v42; // edx
  float alphaa; // [rsp+C0h] [rbp+28h]
  float alphab; // [rsp+C0h] [rbp+28h]

  jitter = joint->jitter;
  lengthOfBolt = params->lengthOfBolt;
  settings = params->settings;
  v11 = lengthOfBolt * settings->mJitterDistance.x;
  v12 = joint->pos.y + (float)((float)(v11 * joint->right.y) * jitter);
  v13 = joint->pos.x + (float)((float)(v11 * joint->right.x) * jitter);
  v14 = joint->pos.z + (float)((float)(v11 * joint->right.z) * jitter);
  v15 = (float)((float)((float)((float)(lengthOfBolt * settings->mWidthMax) * params->sizeScale)
                      - (float)((float)(lengthOfBolt * settings->mWidthMin) * params->sizeScale))
              * joint->width)
      + (float)((float)(lengthOfBolt * settings->mWidthMin) * params->sizeScale);
  v16 = (float)((float)((float)(v12 * params->mat.v1.x) + (float)(v13 * params->mat.v0.x))
              + (float)(v14 * params->mat.v2.x))
      + params->mat.v3.x;
  v17 = (float)((float)((float)(v12 * params->mat.v1.y) + (float)(v13 * params->mat.v0.y))
              + (float)(v14 * params->mat.v2.y))
      + params->mat.v3.y;
  v18 = (float)((float)((float)(v12 * params->mat.v1.z) + (float)(v13 * params->mat.v0.z))
              + (float)(v14 * params->mat.v2.z))
      + params->mat.v3.z;
  v19 = sinf(t * 3.1415927) * (float)((float)(params->speed * params->timeElapsed) + params->curve);
  v20 = v18 + (float)((float)(v19 * params->perpendicularMat.v2.z) * lengthOfBolt);
  v21 = v16 + (float)((float)(v19 * params->perpendicularMat.v2.x) * lengthOfBolt);
  v22 = v17 + (float)((float)(v19 * params->perpendicularMat.v2.y) * lengthOfBolt);
  *mainMemoryVertexBuffer = v21;
  mainMemoryVertexBuffer[1] = v22;
  mainMemoryVertexBuffer[2] = v20;
  mainMemoryVertexBuffer[8] = v21;
  mainMemoryVertexBuffer[9] = v22;
  mainMemoryVertexBuffer[10] = v20;
  v23 = v15 * params->boltDirection.x;
  v24 = v15 * params->boltDirection.y;
  mainMemoryVertexBuffer[5] = v15 * params->boltDirection.z;
  mainMemoryVertexBuffer[3] = v23;
  mainMemoryVertexBuffer[4] = v24;
  v25 = COERCE_FLOAT(LODWORD(params->boltDirection.x) ^ _xmm[0]) * v15;
  v26 = COERCE_FLOAT(LODWORD(params->boltDirection.y) ^ _xmm[0]) * v15;
  mainMemoryVertexBuffer[13] = COERCE_FLOAT(LODWORD(params->boltDirection.z) ^ _xmm[0]) * v15;
  mainMemoryVertexBuffer[11] = v25;
  mainMemoryVertexBuffer[12] = v26;
  v27 = (int)(float)(params->colour.r * 255.0) | (((int)(float)(params->colour.g * 255.0) | (((int)(float)(params->colour.b * 255.0) | ((int)(float)((float)(params->colour.a * alpha) * 255.0) << 8)) << 8)) << 8);
  *((_DWORD *)mainMemoryVertexBuffer + 7) = v27;
  alphaa = (float)(int)params->settings->mTexturePageU * 0.5;
  v28 = fabs(alphaa);
  v29 = HIWORD(LODWORD(alphaa)) & 0x8000;
  if ( v28 <= 0x47FFEFFF )
  {
    if ( v28 >= 0x38800000 )
      v31 = v28 - 939524096;
    else
      v31 = (v28 & 0x7FFFFF | 0x800000) >> (113 - (v28 >> 23));
    v30 = ((((v31 >> 13) & 1) + v31 + 4095) >> 13) | v29;
  }
  else
  {
    v30 = v29 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 12) = v30;
  v32 = LODWORD(vTexcoord) & 0x7FFFFFFF;
  v33 = HIWORD(LODWORD(vTexcoord)) & 0x8000;
  if ( (LODWORD(vTexcoord) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v32 >= 0x38800000 )
      v35 = v32 - 939524096;
    else
      v35 = (LODWORD(vTexcoord) & 0x7FFFFF | 0x800000u) >> (113 - (v32 >> 23));
    v34 = ((((v35 >> 13) & 1) + v35 + 4095) >> 13) | v33;
  }
  else
  {
    v34 = v33 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 13) = v34;
  *((_DWORD *)mainMemoryVertexBuffer + 15) = v27;
  alphab = (float)(params->settings->mTexturePageU + 1) * 0.5;
  v36 = fabs(alphab);
  v37 = HIWORD(LODWORD(alphab)) & 0x8000;
  if ( v36 <= 0x47FFEFFF )
  {
    if ( v36 >= 0x38800000 )
      v39 = v36 - 939524096;
    else
      v39 = (v36 & 0x7FFFFF | 0x800000) >> (113 - (v36 >> 23));
    v38 = ((((v39 >> 13) & 1) + v39 + 4095) >> 13) | v37;
  }
  else
  {
    v38 = v37 | 0x7FFF;
  }
  *((_WORD *)mainMemoryVertexBuffer + 28) = v38;
  v40 = LODWORD(vTexcoord) & 0x7FFFFFFF;
  v41 = HIWORD(LODWORD(vTexcoord)) & 0x8000;
  if ( (LODWORD(vTexcoord) & 0x7FFFFFFFu) <= 0x47FFEFFF )
  {
    if ( v40 >= 0x38800000 )
      v42 = v40 - 939524096;
    else
      v42 = (LODWORD(vTexcoord) & 0x7FFFFF | 0x800000u) >> (113 - (v40 >> 23));
    *((_WORD *)mainMemoryVertexBuffer + 29) = v41 | ((((v42 >> 13) & 1) + v42 + 4095) >> 13);
  }
  else
  {
    *((_WORD *)mainMemoryVertexBuffer + 29) = v41 | 0x7FFF;
  }
}

// File Line: 524
// RVA: 0x1E5C40
__int64 __fastcall Render::KillExpiredBolts(Render::Bolt *boltArray, int numBolts, float simTime)
{
  signed int v3; // r9d
  UFG::qHalfFloat *p_z; // r8
  __m128i v6; // xmm1
  __m128 v7; // xmm4
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __int64 v11; // [rsp+40h] [rbp-18h]

  v3 = 0;
  if ( numBolts > 0 )
  {
    p_z = &boltArray->tailOffset.z;
    do
    {
      if ( simTime <= *(float *)&p_z[21].mRep )
      {
        ++v3;
        p_z += 36;
      }
      else
      {
        v6 = *(__m128i *)&boltArray[--numBolts].headOffset.x.mRep;
        v7 = *(__m128 *)&boltArray[numBolts].startTime;
        v8 = *(__m128i *)&boltArray[numBolts].settings;
        v9 = *(__m128i *)&boltArray[numBolts].jointChainSegmentCount;
        v11 = *(_QWORD *)&boltArray[numBolts].curve;
        p_z[-5].mRep = _mm_cvtsi128_si32(v6);
        p_z[-4].mRep = _mm_extract_epi16(v6, 1);
        p_z[-3].mRep = _mm_extract_epi16(v6, 2);
        p_z[-2].mRep = _mm_extract_epi16(v6, 3);
        p_z[-1].mRep = _mm_extract_epi16(v6, 4);
        p_z->mRep = _mm_extract_epi16(v6, 5);
        *(_DWORD *)&p_z[19].mRep = v7.m128_i32[0];
        *(_DWORD *)&p_z[21].mRep = _mm_shuffle_ps(v7, v7, 85).m128_u32[0];
        *(_DWORD *)&p_z[11].mRep = _mm_cvtsi128_si32(v9);
        *(_QWORD *)&p_z[3].mRep = v8.m128i_i64[0];
        *(_DWORD *)&p_z[25].mRep = _mm_shuffle_ps(v7, v7, 255).m128_u32[0];
        *(_DWORD *)&p_z[23].mRep = _mm_shuffle_ps(v7, v7, 170).m128_u32[0];
        *(_DWORD *)&p_z[27].mRep = v11;
        *(_QWORD *)&p_z[7].mRep = _mm_srli_si128(v8, 8).m128i_u64[0];
        *(_QWORD *)&p_z[15].mRep = _mm_srli_si128(v9, 8).m128i_u64[0];
      }
    }
    while ( v3 < numBolts );
  }
  return (unsigned int)numBolts;
}

// File Line: 550
// RVA: 0x1E2D50
void __fastcall Render::LightningTask(
        int worker_id,
        UFG::qMemoryStreamer *memory_streamer,
        _DWORD *_lightningInfo,
        _DWORD *_outInfo)
{
  __int64 v4; // rbx
  Render::Bolt *v6; // rax
  _WORD *v7; // rsi
  unsigned int v8; // edx
  unsigned int v9; // r15d
  unsigned int v10; // eax
  __int64 v11; // r13
  __int64 v12; // r14
  Render::ElectrifiedObjectSortContainer *v13; // rdi
  bool HeadTransform; // bl
  bool TailTransform; // al
  int v16; // r8d
  __int64 v17; // rax
  float v18; // xmm2_4
  unsigned int v19; // r9d
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
  unsigned int numBolts; // eax
  void **p_electrifiedObjectPtr; // rdi
  Render::ElectrifiedObjectSortContainer *v39; // r14
  char *v40; // rbx
  int v41; // eax
  unsigned int v42; // edx
  float v43; // xmm13_4
  LightningJoint **p_jointChain; // r12
  __int64 v45; // rcx
  LightningJoint *v46; // rdi
  float *v47; // rax
  float x; // xmm6_4
  float y; // xmm10_4
  float v50; // xmm0_4
  _OWORD *v51; // r14
  UFG::qVector4 v52; // xmm1
  UFG::qVector4 v53; // xmm0
  UFG::qVector4 v54; // xmm1
  __int64 v55; // rax
  float v56; // xmm14_4
  float v57; // xmm15_4
  int v58; // xmm0_4
  _OWORD *v59; // r14
  UFG::qVector4 v60; // xmm1
  UFG::qVector4 v61; // xmm0
  UFG::qVector4 v62; // xmm1
  __m128 x_low; // xmm7
  unsigned int v64; // ecx
  float v65; // xmm12_4
  float v66; // xmm9_4
  float v67; // xmm8_4
  float v68; // xmm6_4
  __m128 v69; // xmm5
  float v70; // xmm4_4
  float v71; // xmm6_4
  float v72; // xmm4_4
  __m128 v73; // xmm2
  float v74; // xmm1_4
  float v75; // xmm7_4
  float v76; // xmm8_4
  float v77; // xmm6_4
  unsigned int v78; // r8d
  unsigned int v79; // edx
  int v80; // ecx
  float v81; // xmm2_4
  float v82; // xmm1_4
  float v83; // xmm3_4
  __int64 v84; // r14
  __int64 v85; // rax
  float v86; // xmm14_4
  float v87; // xmm11_4
  float v88; // xmm9_4
  float v89; // xmm7_4
  float v90; // xmm12_4
  float v91; // xmm10_4
  float v92; // xmm8_4
  float v93; // xmm6_4
  float v94; // xmm4_4
  float v95; // xmm15_4
  float v96; // xmm0_4
  float v97; // xmm2_4
  float v98; // xmm13_4
  float v99; // xmm0_4
  float v100; // xmm3_4
  float v101; // xmm5_4
  float v102; // xmm14_4
  float v103; // xmm12_4
  float v104; // xmm11_4
  float v105; // xmm15_4
  __m128 z_low; // xmm3
  float v107; // xmm14_4
  float v108; // xmm15_4
  float v109; // xmm15_4
  __m128 y_low; // xmm2
  float v111; // xmm1_4
  float v112; // xmm4_4
  float v113; // xmm8_4
  __m128 v114; // xmm2
  float v115; // xmm0_4
  __m128 v116; // xmm2
  __m128 v117; // xmm1
  float v118; // xmm7_4
  float v119; // xmm2_4
  float v120; // xmm7_4
  __m128 v121; // xmm5
  float v122; // xmm2_4
  float v123; // xmm7_4
  __m128 v124; // xmm6
  float v125; // xmm6_4
  unsigned int v126; // xmm5_4
  unsigned int v127; // xmm1_4
  unsigned int v128; // xmm6_4
  float v129; // xmm7_4
  float v130; // xmm4_4
  __m128 v131; // xmm2
  float v132; // xmm1_4
  float v133; // xmm1_4
  UFG::qColour *v134; // rax
  float g; // xmm1_4
  float b; // xmm0_4
  float a; // xmm1_4
  float v138; // xmm0_4
  float v139; // xmm1_4
  float v140; // xmm6_4
  _DWORD *v141; // rdx
  unsigned int v142; // [rsp+40h] [rbp-C0h]
  unsigned int v143; // [rsp+40h] [rbp-C0h]
  unsigned int v144; // [rsp+44h] [rbp-BCh]
  float w; // [rsp+48h] [rbp-B8h]
  float v146; // [rsp+48h] [rbp-B8h]
  int v147; // [rsp+50h] [rbp-B0h]
  unsigned int v148; // [rsp+50h] [rbp-B0h]
  float v149; // [rsp+50h] [rbp-B0h]
  float v150; // [rsp+50h] [rbp-B0h]
  float lifetime; // [rsp+58h] [rbp-A8h]
  float lifetimea; // [rsp+58h] [rbp-A8h]
  float v153; // [rsp+5Ch] [rbp-A4h]
  float v154; // [rsp+5Ch] [rbp-A4h]
  float v155; // [rsp+64h] [rbp-9Ch]
  int v156; // [rsp+68h] [rbp-98h]
  Render::Bolt *boltArray; // [rsp+70h] [rbp-90h]
  int boltArrayb; // [rsp+70h] [rbp-90h]
  float boltArrayc; // [rsp+70h] [rbp-90h]
  float boltArraya; // [rsp+70h] [rbp-90h]
  float z; // [rsp+78h] [rbp-88h]
  float v162; // [rsp+7Ch] [rbp-84h]
  UFG::qVector3 forward; // [rsp+80h] [rbp-80h] BYREF
  __int64 v164; // [rsp+90h] [rbp-70h]
  __int64 v165; // [rsp+98h] [rbp-68h]
  float v166; // [rsp+A0h] [rbp-60h]
  UFG::qVector4 v167; // [rsp+B0h] [rbp-50h]
  UFG::qVector4 v168; // [rsp+C0h] [rbp-40h]
  UFG::qVector4 v169; // [rsp+D0h] [rbp-30h]
  UFG::qVector4 v170; // [rsp+E0h] [rbp-20h]
  UFG::qVector4 v171; // [rsp+F0h] [rbp-10h]
  UFG::qVector4 v172; // [rsp+100h] [rbp+0h]
  UFG::qVector4 v173; // [rsp+110h] [rbp+10h]
  UFG::qVector4 v174; // [rsp+120h] [rbp+20h]
  UFG::qVector3 translation; // [rsp+130h] [rbp+30h] BYREF
  Render::LightningSettings *v176; // [rsp+140h] [rbp+40h]
  __int64 v177; // [rsp+148h] [rbp+48h]
  UFG::qVector3 v178; // [rsp+150h] [rbp+50h] BYREF
  UFG::qVector3 scale; // [rsp+15Ch] [rbp+5Ch] BYREF
  UFG::qVector3 up; // [rsp+168h] [rbp+68h] BYREF
  __m128 v181; // [rsp+180h] [rbp+80h]
  __m128 v182; // [rsp+190h] [rbp+90h]
  __m128 v183; // [rsp+1A0h] [rbp+A0h]
  __m128 v184; // [rsp+1B0h] [rbp+B0h]
  __m128 v185; // [rsp+1C0h] [rbp+C0h]
  __m128 v186; // [rsp+1D0h] [rbp+D0h]
  __m128 v187; // [rsp+1E0h] [rbp+E0h]
  __m128 v188; // [rsp+1F0h] [rbp+F0h]
  int v189; // [rsp+200h] [rbp+100h]
  int v190; // [rsp+210h] [rbp+110h]
  Render::BoltConstantData params; // [rsp+220h] [rbp+120h] BYREF
  UFG::qMatrix44 dest; // [rsp+2F0h] [rbp+1F0h] BYREF
  UFG::qMatrix44 v193; // [rsp+330h] [rbp+230h] BYREF
  UFG::qMatrix44 v194; // [rsp+370h] [rbp+270h] BYREF
  UFG::qColour result; // [rsp+3B0h] [rbp+2B0h] BYREF
  Render::ElectrifiedObjectSortContainer left[300]; // [rsp+3C0h] [rbp+2C0h] BYREF
  int v198; // [rsp+B6D0h] [rbp+B5D0h]

  LODWORD(v4) = 0;
  seed = _lightningInfo[134];
  _outInfo[3] = 0;
  v6 = (Render::Bolt *)*((_QWORD *)_lightningInfo + 59);
  v7 = (_WORD *)*((_QWORD *)_lightningInfo + 55);
  v164 = 0i64;
  boltArray = v6;
  if ( v6 )
  {
    v8 = _lightningInfo[120];
    v166 = *((float *)_lightningInfo + 114);
    v9 = 0;
    v156 = 0;
    v198 = 0;
    v10 = Render::KillExpiredBolts(v6, v8, v166);
    v11 = *((_QWORD *)_lightningInfo + 61);
    v144 = v10;
    if ( v11 != *((_QWORD *)_lightningInfo + 62) )
    {
      do
      {
        if ( v9 >= 0x12C )
          break;
        if ( !*(_DWORD *)(v11 + 112) )
        {
          v12 = v9;
          v13 = &left[v12];
          left[v12].electrifiedObjectPtr = (void *)v11;
          HeadTransform = Render::GetHeadTransform(
                            (Render::ElectrifiedObject *)v11,
                            memory_streamer,
                            &left[v12].headTransformWS,
                            &left[v12].headAlpha);
          TailTransform = Render::GetTailTransform(
                            (Render::ElectrifiedObject *)v11,
                            memory_streamer,
                            &left[v12].tailTransformWS,
                            &left[v12].tailAlpha);
          if ( HeadTransform && TailTransform )
          {
            v16 = _lightningInfo[108];
            v17 = 0i64;
            v18 = FLOAT_3_4028235e38;
            v19 = 0;
            if ( v16 >= 4 )
            {
              v20 = (float *)(_lightningInfo + 98);
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
                left[v9].distanceToNearestCamera = v18;
                v26 = (float)((float)((float)(v24 - v13->headTransformWS.v3.y) * (float)(v24 - v13->headTransformWS.v3.y))
                            + (float)((float)(v23 - v13->headTransformWS.v3.x) * (float)(v23 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v25 - v13->headTransformWS.v3.z) * (float)(v25 - v13->headTransformWS.v3.z));
                if ( v26 < v18 )
                  v18 = v26;
                v27 = v20[4];
                v28 = v20[5];
                v29 = v20[6];
                left[v9].distanceToNearestCamera = v18;
                v30 = (float)((float)((float)(v28 - v13->headTransformWS.v3.y) * (float)(v28 - v13->headTransformWS.v3.y))
                            + (float)((float)(v27 - v13->headTransformWS.v3.x) * (float)(v27 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v29 - v13->headTransformWS.v3.z) * (float)(v29 - v13->headTransformWS.v3.z));
                if ( v30 < v18 )
                  v18 = v30;
                v31 = v20[7];
                v32 = v20[8];
                v33 = v20[9];
                left[v9].distanceToNearestCamera = v18;
                v34 = (float)((float)((float)(v32 - v13->headTransformWS.v3.y) * (float)(v32 - v13->headTransformWS.v3.y))
                            + (float)((float)(v31 - v13->headTransformWS.v3.x) * (float)(v31 - v13->headTransformWS.v3.x)))
                    + (float)((float)(v33 - v13->headTransformWS.v3.z) * (float)(v33 - v13->headTransformWS.v3.z));
                if ( v34 < v18 )
                  v18 = v34;
                v20 += 12;
                left[v9].distanceToNearestCamera = v18;
                --v22;
              }
              while ( v22 );
            }
            if ( v19 < v16 )
            {
              v35 = (float *)&_lightningInfo[3 * v17 + 98];
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
                left[v9].distanceToNearestCamera = v18;
                --v36;
              }
              while ( v36 );
            }
            ++v9;
          }
        }
        v11 = *(_QWORD *)(v11 + 8);
      }
      while ( v11 != *((_QWORD *)_lightningInfo + 62) );
      v142 = v9;
      v9 = 0;
      LODWORD(v4) = v142;
    }
    UFG::qQuickSortImpl<Render::ElectrifiedObjectSortContainer,UFG::qLess<Render::ElectrifiedObjectSortContainer>>(
      left,
      (Render::ElectrifiedObjectSortContainer *)&dest.v3.z + (int)v4,
      0);
    if ( (_DWORD)v4 )
    {
      numBolts = v144;
      p_electrifiedObjectPtr = &left[0].electrifiedObjectPtr;
      v39 = left;
      v4 = (unsigned int)v4;
      do
      {
        numBolts = Render::GenerateBoltsOnObject(
                     (Render::ElectrifiedObject *)*p_electrifiedObjectPtr,
                     v39++,
                     memory_streamer,
                     boltArray,
                     numBolts,
                     (Render::LightningTaskParam *)_lightningInfo);
        p_electrifiedObjectPtr += 19;
        --v4;
      }
      while ( v4 );
      v144 = numBolts;
    }
    v40 = (char *)*((_QWORD *)_lightningInfo + 56);
    v41 = 0;
    v42 = 0;
    v143 = 0;
    if ( v144 )
    {
      v43 = *(float *)&FLOAT_1_0;
      p_jointChain = &boltArray->jointChain;
      while ( 1 )
      {
        v45 = (__int64)p_jointChain[2];
        v46 = *p_jointChain;
        v176 = (Render::LightningSettings *)*(p_jointChain - 1);
        v47 = *(float **)(v45 + 64);
        v177 = v45;
        if ( v47 )
        {
          x = v47[1];
          y = v47[2];
          lifetime = v43;
          v171 = UFG::qMatrix44::msIdentity.v0;
          v172 = UFG::qMatrix44::msIdentity.v1;
          v173 = UFG::qMatrix44::msIdentity.v2;
          v50 = v47[4];
          v174 = UFG::qMatrix44::msIdentity.v3;
          v162 = v50;
          z = v47[3];
        }
        else
        {
          v51 = *(_OWORD **)(v45 + 32);
          if ( !v51 )
            goto LABEL_88;
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v45 + 32));
          v45 = v177;
          v42 = v143;
          v52 = (UFG::qVector4)v51[9];
          v171 = (UFG::qVector4)v51[8];
          v53 = (UFG::qVector4)v51[10];
          v172 = v52;
          v54 = (UFG::qVector4)v51[11];
          v173 = v53;
          v174 = v54;
          y = v54.y;
          x = v54.x;
          v162 = v43;
          lifetime = v54.w;
          z = v54.z;
        }
        v55 = *(_QWORD *)(v45 + 72);
        v153 = x;
        if ( v55 )
        {
          v56 = *(float *)(v55 + 4);
          v57 = *(float *)(v55 + 8);
          w = v43;
          v167 = UFG::qMatrix44::msIdentity.v0;
          v168 = UFG::qMatrix44::msIdentity.v1;
          v169 = UFG::qMatrix44::msIdentity.v2;
          v58 = *(_DWORD *)(v55 + 12);
          v170 = UFG::qMatrix44::msIdentity.v3;
          LODWORD(v165) = v58;
          v155 = *(float *)(v55 + 16);
        }
        else
        {
          v59 = *(_OWORD **)(v45 + 56);
          if ( !v59 )
            goto LABEL_88;
          UFG::TransformNodeComponent::UpdateWorldTransform(*(UFG::TransformNodeComponent **)(v45 + 56));
          v60 = (UFG::qVector4)v59[9];
          v167 = (UFG::qVector4)v59[8];
          v61 = (UFG::qVector4)v59[10];
          v168 = v60;
          v62 = (UFG::qVector4)v59[11];
          v169 = v61;
          v170 = v62;
          v57 = v62.y;
          v56 = v62.x;
          v155 = v43;
          w = v62.w;
          *(float *)&v165 = v62.z;
        }
        x_low = (__m128)LODWORD(v171.x);
        v147 = ((((*((unsigned __int16 *)p_jointChain - 10) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*((_WORD *)p_jointChain - 10) & 0x3FF | (8 * (*((_WORD *)p_jointChain - 10) & 0x8000))) << 13);
        boltArrayb = ((((*((unsigned __int16 *)p_jointChain - 11) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*((_WORD *)p_jointChain - 11) & 0x3FF | (8 * (*((_WORD *)p_jointChain - 11) & 0x8000))) << 13);
        v64 = *((unsigned __int16 *)p_jointChain - 7);
        v190 = ((((*((unsigned __int16 *)p_jointChain - 12) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(p_jointChain - 3) & 0x3FF | (8 * (*(_WORD *)(p_jointChain - 3) & 0x8000))) << 13);
        v65 = (float)((float)((float)(*(float *)&v190 * v171.x) + (float)(*(float *)&boltArrayb * v172.x))
                    + (float)(*(float *)&v147 * v173.x))
            + x;
        translation.x = v65;
        v66 = (float)((float)((float)(*(float *)&v190 * v171.y) + (float)(*(float *)&boltArrayb * v172.y))
                    + (float)(*(float *)&v147 * v173.y))
            + y;
        translation.y = v66;
        v67 = (float)((float)((float)(*(float *)&v190 * v171.z) + (float)(*(float *)&boltArrayb * v172.z))
                    + (float)(*(float *)&v147 * v173.z))
            + z;
        translation.z = v67;
        LODWORD(boltArrayc) = ((((v64 >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((v64 & 0x3FF | (8 * (v64 & 0xFFFF8000))) << 13);
        v148 = ((((*((unsigned __int16 *)p_jointChain - 8) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*(_WORD *)(p_jointChain - 2) & 0x3FF | (8 * (*(_WORD *)(p_jointChain - 2) & 0x8000))) << 13);
        v69 = (__m128)v148;
        v189 = ((((*((unsigned __int16 *)p_jointChain - 9) >> 10) & 0x1F) + 112) << 23) & 0x7F800000 | ((*((_WORD *)p_jointChain - 9) & 0x3FF | (8 * (*((_WORD *)p_jointChain - 9) & 0x8000))) << 13);
        v68 = (float)((float)((float)(*(float *)&v148 * v168.x) + (float)(v167.x * *(float *)&v189))
                    + (float)(boltArrayc * v169.x))
            + v56;
        v69.m128_f32[0] = (float)((float)((float)(*(float *)&v148 * v168.y) + (float)(v167.y * *(float *)&v189))
                                + (float)(boltArrayc * v169.y))
                        + v57;
        v70 = (float)((float)((float)(*(float *)&v148 * v168.z) + (float)(v167.z * *(float *)&v189))
                    + (float)(boltArrayc * v169.z))
            + *(float *)&v165;
        if ( v65 != v68 || v66 != v69.m128_f32[0] || v67 != v70 )
        {
          if ( v171.x == v167.x
            && v171.y == v167.y
            && v171.z == v167.z
            && v171.w == v167.w
            && v172.x == v168.x
            && v172.y == v168.y
            && v172.z == v168.z
            && v172.w == v168.w
            && v173.x == v169.x
            && v173.y == v169.y
            && v173.z == v169.z
            && v173.w == v169.w
            && v153 == v56
            && y == v57
            && z == *(float *)&v165
            && lifetime == w )
          {
            x_low.m128_f32[0] = (float)((float)(v171.x * v171.x) + (float)(v171.y * v171.y)) + (float)(v171.z * v171.z);
            LODWORD(v146) = _mm_sqrt_ps(x_low).m128_u32[0];
          }
          else
          {
            v146 = v43;
          }
          v71 = v68 - v65;
          v69.m128_f32[0] = v69.m128_f32[0] - v66;
          v72 = v70 - v67;
          v73 = v69;
          v73.m128_f32[0] = (float)((float)(v69.m128_f32[0] * v69.m128_f32[0]) + (float)(v71 * v71))
                          + (float)(v72 * v72);
          if ( v73.m128_f32[0] == 0.0 )
            v74 = 0.0;
          else
            v74 = v43 / _mm_sqrt_ps(v73).m128_f32[0];
          *(_QWORD *)&up.x = 0i64;
          up.z = 1.0;
          scale.y = 1.0;
          scale.z = 1.0;
          forward.x = v71 * v74;
          forward.y = v69.m128_f32[0] * v74;
          LODWORD(scale.x) = _mm_sqrt_ps(v73).m128_u32[0];
          forward.z = v72 * v74;
          UFG::qScaleMatrix(&v193, &scale);
          if ( !UFG::qMakeMatrix(&dest, &forward, &up, &translation, 0.001) )
          {
            v178.x = 0.0;
            *(_QWORD *)&v178.y = 1065353216i64;
            UFG::qMakeMatrix(&dest, &forward, &v178, &translation, 0.001);
          }
          v75 = *((float *)p_jointChain + 6);
          v76 = v166;
          v77 = *((float *)p_jointChain + 7);
          boltArraya = v166 - v75;
          lifetimea = (float)(v166 - v75) / (float)(v77 - v75);
          v78 = (int)(float)(powf(2.0, (float)(*((_DWORD *)p_jointChain + 2) + 1)) + v43);
          v165 = v78;
          if ( v76 <= v77 && v76 >= v75 && v78 >= 2 )
          {
            v79 = v78 - 1;
            v80 = v198;
            if ( v156 + 6 * (v78 - 1) > 0x6D60 )
            {
              v141 = _outInfo;
              v41 = v164;
              _outInfo[3] = 1;
              goto LABEL_94;
            }
            if ( v198 + 8 * v79 > 0x2710 )
            {
              v141 = _outInfo;
              v41 = v164;
              _outInfo[3] = 2;
              goto LABEL_94;
            }
            v154 = v43 / (float)(int)v79;
            v186 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v0, (__m128)v193.v0, 0), (__m128)dest.v0),
                           (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v0, (__m128)v193.v0, 85), (__m128)dest.v1)),
                       _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v0, (__m128)v193.v0, 170), (__m128)dest.v2)),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v0, (__m128)v193.v0, 255), (__m128)dest.v3));
            v81 = v46->pos.x;
            v188 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps((__m128)dest.v0, _mm_shuffle_ps((__m128)v193.v3, (__m128)v193.v3, 0)),
                           (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v3, (__m128)v193.v3, 85), (__m128)dest.v1)),
                       _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v3, (__m128)v193.v3, 170), (__m128)dest.v2)),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v3, (__m128)v193.v3, 255), (__m128)dest.v3));
            v187 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v1, (__m128)v193.v1, 0), (__m128)dest.v0),
                           (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v1, (__m128)v193.v1, 85), (__m128)dest.v1)),
                       _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v1, (__m128)v193.v1, 170), (__m128)dest.v2)),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v1, (__m128)v193.v1, 255), (__m128)dest.v3));
            v185 = _mm_add_ps(
                     _mm_add_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v2, (__m128)v193.v2, 0), (__m128)dest.v0),
                           (__m128)0i64),
                         _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v2, (__m128)v193.v2, 85), (__m128)dest.v1)),
                       _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v2, (__m128)v193.v2, 170), (__m128)dest.v2)),
                     _mm_mul_ps(_mm_shuffle_ps((__m128)v193.v2, (__m128)v193.v2, 255), (__m128)dest.v3));
            v82 = v46->pos.y;
            v83 = v46->pos.z;
            v84 = v79;
            v85 = v79;
            v86 = _mm_shuffle_ps(v187, v187, 85).m128_f32[0];
            v87 = _mm_shuffle_ps(v187, v187, 170).m128_f32[0];
            v88 = _mm_shuffle_ps(v186, v186, 85).m128_f32[0];
            v89 = _mm_shuffle_ps(v186, v186, 170).m128_f32[0];
            v90 = _mm_shuffle_ps(v188, v188, 85).m128_f32[0];
            v149 = (float)((float)((float)(v187.m128_f32[0] * v82) + (float)(v186.m128_f32[0] * v81))
                         + (float)(v185.m128_f32[0] * v83))
                 + v188.m128_f32[0];
            v91 = _mm_shuffle_ps(v188, v188, 170).m128_f32[0];
            v92 = _mm_shuffle_ps(v185, v185, 85).m128_f32[0];
            v93 = _mm_shuffle_ps(v185, v185, 170).m128_f32[0];
            v94 = v46[v85].pos.z;
            v95 = (float)((float)((float)(v86 * v82) + (float)(v88 * v81)) + (float)(v92 * v83)) + v90;
            v96 = v89 * v81;
            v97 = v46[v85].pos.y;
            v98 = (float)(v87 * v82) + v96;
            v99 = v93 * v83;
            v100 = v46[v85].pos.x;
            v101 = (float)((float)((float)(v187.m128_f32[0] * v97) + (float)(v186.m128_f32[0] * v100))
                         + (float)(v185.m128_f32[0] * v94))
                 + v188.m128_f32[0];
            v102 = (float)((float)((float)(v86 * v97) + (float)(v88 * v100)) + (float)(v92 * v94)) + v90;
            v103 = 0.0;
            v104 = (float)((float)((float)(v87 * v97) + (float)(v89 * v100)) + (float)(v93 * v94)) + v91;
            v105 = (float)(v95 - v102) * (float)(v95 - v102);
            z_low = (__m128)LODWORD(forward.z);
            y_low = (__m128)LODWORD(forward.y);
            v107 = 0.0;
            v108 = (float)(v105 + (float)((float)(v149 - v101) * (float)(v149 - v101)))
                 + (float)((float)((float)((float)(v98 + v99) + v91) - v104)
                         * (float)((float)((float)(v98 + v99) + v91) - v104));
            v43 = *(float *)&FLOAT_1_0;
            v150 = fsqrt(v108);
            v109 = (float)(25.0 / (float)(int)v78) * v176->mTexCoordScale;
            y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(forward.x * forward.x))
                              + (float)(z_low.m128_f32[0] * z_low.m128_f32[0]);
            if ( y_low.m128_f32[0] == 0.0 )
              v111 = 0.0;
            else
              v111 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
            v112 = forward.x * v111;
            v113 = forward.y * v111;
            z_low.m128_f32[0] = forward.z * v111;
            v114 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
            v181.m128_f32[0] = forward.x * v111;
            v181.m128_f32[1] = forward.y * v111;
            v181.m128_u64[1] = COERCE_UNSIGNED_INT(forward.z * v111);
            v114.m128_f32[0] = (float)((float)(v114.m128_f32[0] * v114.m128_f32[0])
                                     + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                             + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
            if ( v114.m128_f32[0] == 0.0 )
            {
              v116 = 0i64;
            }
            else
            {
              v115 = _mm_sqrt_ps(v114).m128_f32[0];
              v116 = (__m128)(unsigned int)FLOAT_1_0;
              v116.m128_f32[0] = 1.0 / v115;
            }
            v117 = v116;
            v118 = v116.m128_f32[0];
            v119 = v116.m128_f32[0] * UFG::qVector3::msDirUp.z;
            v117.m128_f32[0] = v117.m128_f32[0] * UFG::qVector3::msDirUp.y;
            v120 = v118 * UFG::qVector3::msDirUp.x;
            v121 = v117;
            v121.m128_f32[0] = (float)(v117.m128_f32[0] * z_low.m128_f32[0]) - (float)(v119 * v113);
            v124 = v121;
            v122 = (float)(v119 * v112) - (float)(v120 * z_low.m128_f32[0]);
            v123 = (float)(v120 * v113) - (float)(v117.m128_f32[0] * v112);
            v124.m128_f32[0] = (float)((float)(v121.m128_f32[0] * v121.m128_f32[0]) + (float)(v122 * v122))
                             + (float)(v123 * v123);
            if ( v124.m128_f32[0] == 0.0 )
              v125 = 0.0;
            else
              v125 = 1.0 / _mm_sqrt_ps(v124).m128_f32[0];
            *(float *)&v126 = v121.m128_f32[0] * v125;
            *(float *)&v127 = v125 * v122;
            *(float *)&v128 = v125 * v123;
            v182.m128_u64[0] = __PAIR64__(v127, v126);
            v182.m128_u64[1] = v128;
            v129 = (float)(v113 * *(float *)&v128) - (float)(z_low.m128_f32[0] * *(float *)&v127);
            z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * *(float *)&v126) - (float)(v112 * *(float *)&v128);
            v130 = (float)(v112 * *(float *)&v127) - (float)(v113 * *(float *)&v126);
            v131 = z_low;
            v131.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v129 * v129))
                             + (float)(v130 * v130);
            if ( v131.m128_f32[0] != 0.0 )
              v107 = 1.0 / _mm_sqrt_ps(v131).m128_f32[0];
            v132 = *((float *)p_jointChain + 9);
            v184.m128_i32[3] = 1065353216;
            v184.m128_i32[0] = LODWORD(UFG::qVector3::msZero.x);
            v183.m128_f32[0] = v129 * v107;
            v183.m128_f32[1] = z_low.m128_f32[0] * v107;
            v183.m128_u64[1] = COERCE_UNSIGNED_INT(v130 * v107);
            *(unsigned __int64 *)((char *)v184.m128_u64 + 4) = *(_QWORD *)&UFG::qVector3::msZero.y;
            UFG::qRotationMatrixX(&v194, v132);
            params.perpendicularMat.v0 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 0),
                                                                  v181),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 85),
                                                                v182)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 170),
                                                              v183)),
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v0, (__m128)v194.v0, 255),
                                                            v184));
            params.perpendicularMat.v1 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 255),
                                                            v184),
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 0),
                                                                  v181),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 85),
                                                                v182)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v1, (__m128)v194.v1, 170),
                                                              v183)));
            params.settings = v176;
            params.lengthOfBolt = v150;
            v133 = *((float *)p_jointChain + 10);
            params.perpendicularMat.v3 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 85),
                                                                v182),
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 0),
                                                                  v181),
                                                                (__m128)0i64)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 170),
                                                              v183)),
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v3, (__m128)v194.v3, 255),
                                                            v184));
            params.curve = v133;
            params.mat.v0 = (UFG::qVector4)v186;
            params.mat.v1 = (UFG::qVector4)v187;
            params.perpendicularMat.v2 = (UFG::qVector4)_mm_add_ps(
                                                          _mm_mul_ps(
                                                            _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 255),
                                                            v184),
                                                          _mm_add_ps(
                                                            _mm_add_ps(
                                                              _mm_add_ps(
                                                                _mm_mul_ps(
                                                                  _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 0),
                                                                  v181),
                                                                (__m128)0i64),
                                                              _mm_mul_ps(
                                                                _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 85),
                                                                v182)),
                                                            _mm_mul_ps(
                                                              _mm_shuffle_ps((__m128)v194.v2, (__m128)v194.v2, 170),
                                                              v183)));
            params.mat.v2 = (UFG::qVector4)v185;
            params.boltDirection.y = forward.y;
            params.mat.v3 = (UFG::qVector4)v188;
            params.timeElapsed = boltArraya;
            params.speed = *((float *)p_jointChain + 8);
            params.boltDirection.x = forward.x;
            params.boltDirection.z = forward.z;
            v134 = Render::ComputeInterpolatedColour(
                     &result,
                     v176->mColorAlphaKeys,
                     v176->mColorKeyPositions,
                     v176->mAlphaKeyPositions,
                     lifetimea);
            g = v134->g;
            params.colour.r = v134->r;
            b = v134->b;
            params.colour.g = g;
            a = v134->a;
            params.colour.b = b;
            params.transformScale = v146;
            v138 = *(float *)(v177 + 116);
            params.colour.a = a;
            params.sizeScale = v138;
            params.orientation = UFG::qRandom(1.0, (unsigned int *)&seed);
            if ( (_DWORD)v165 != 1 )
            {
              v139 = v162;
              LODWORD(v164) = v84 + v164;
              v140 = 0.0;
              v156 += 6 * v84;
              v198 += 2 * v84;
              do
              {
                Render::WriteMiddleVertex(
                  v46,
                  &params,
                  v140,
                  v103,
                  (float)((float)(v155 - v162) * v140) + v139,
                  v40,
                  memory_streamer);
                v139 = v162;
                v140 = v140 + v154;
                v103 = v103 + v109;
                v7[2] = v9 + 2;
                v7[3] = v9 + 2;
                *v7 = v9;
                v7[1] = v9 + 1;
                v7[4] = v9 + 1;
                v7[5] = v9 + 3;
                v7 += 6;
                v9 += 2;
                ++v46;
                v40 += 64;
                --v84;
              }
              while ( v84 );
              v43 = *(float *)&FLOAT_1_0;
            }
            Render::WriteTerminalVertex(v46, &params, v103, v40, memory_streamer);
            v198 += 2;
            v9 += 2;
            v40 += 64;
          }
        }
        v42 = v143;
LABEL_88:
        ++v42;
        p_jointChain += 9;
        v143 = v42;
        if ( v42 >= v144 )
        {
          v41 = v164;
          v80 = v198;
          goto LABEL_93;
        }
      }
    }
    v80 = 0;
LABEL_93:
    v141 = _outInfo;
LABEL_94:
    *v141 = v41;
    v141[2] = v156;
    v141[1] = v80;
    v141[4] = v144;
  }
}

