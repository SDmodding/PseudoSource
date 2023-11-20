// File Line: 20
// RVA: 0x146B170
__int64 Render::_dynamic_initializer_for__gCoronaFlareManager__()
{
  UFG::qResourceHandle::qResourceHandle(&stru_142365D20);
  qword_142365D48 = 0i64;
  unk_142365D40 = 0i64;
  return atexit(Render::_dynamic_atexit_destructor_for__gCoronaFlareManager__);
}

// File Line: 31
// RVA: 0x1CD800
void __fastcall Render::CoronaFlareManager::Init(Render::CoronaFlareManager *this)
{
  Render::CoronaFlareManager *v1; // r14
  _WORD *v2; // rdi
  unsigned int v3; // ebp
  Illusion::Material *v4; // rsi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  UFG::qResourceWarehouse *v13; // rax
  __int64 v14; // rax
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  unsigned int v17; // eax

  v1 = this;
  v2 = 0i64;
  v3 = UFG::qStringHashUpper32("CoronaFlareMat", 0xFFFFFFFF);
  v4 = Illusion::Factory::NewMaterial("CoronaFlareMat", v3, 4u, 0i64, 0i64, 0i64);
  v5 = UFG::qStringHash32("CORONA", 0xFFFFFFFF);
  LOWORD(v4[1].mNode.mChild[0]) = 0;
  v6 = v5;
  HIDWORD(v4[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v7 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v4[1].mTypeUID = -1957338719;
  LODWORD(v4[1].mResourceHandles.mNode.mNext) = v6;
  LODWORD(v4[1].mNode.mParent) = v7;
  v8 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  *(_WORD *)&v4[1].mDebugName[12] = 0;
  v9 = v8;
  *(_DWORD *)&v4[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v10 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  LODWORD(v4[1].mStateBlockMask.mFlags[1]) = -1958479169;
  LODWORD(v4[1].mStateBlockMask.mFlags[0]) = v9;
  *(_DWORD *)&v4[1].mDebugName[4] = v10;
  LOWORD(v4[1].mMaterialUser.mOffset) = 0;
  *(&v4[1].mNumParams + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v11 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v4[2].mResourceHandles.mNode.mPrev) = 315097330;
  v4[2].mNode.mUID = 662883558;
  v4[1].mNumParams = v11;
  LOWORD(v4[2].mTypeUID) = 0;
  HIDWORD(v4[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v12 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  *((_DWORD *)&v4[2].0 + 22) = 1002903008;
  LODWORD(v4[2].mResourceHandles.mNode.mNext) = v12;
  *(_DWORD *)&v4[2].mDebugName[28] = -262489691;
  v13 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v13, (UFG::qResourceData *)&v4->mNode);
  if ( *(_DWORD *)&v4[2].mDebugName[28] != -262489691 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4[2].mDebugName[4], *((_DWORD *)&v4[2].0 + 22), 0xF05AB9A5);
    v14 = v4->mMaterialUser.mOffset;
    if ( v14 )
      v2 = (_WORD *)((char *)&v4->mMaterialUser + v14);
    *v2 |= 0x20u;
  }
  v15 = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v16 = UFG::qResourceWarehouse::Instance();
    v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = v15;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mCoronaFlareMat.mPrev, 0xB4C26312, v3, v15);
  v17 = UFG::qStringHash32("cbFlareSettings", 0xFFFFFFFF);
  v1->mStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             v17,
                                             "cbFlareSettings",
                                             0);
}

// File Line: 77
// RVA: 0x1C6BD0
void __fastcall Render::CoronaFlareManager::AddCoronaFlare(Render::CoronaFlareManager *this, Render::CoronaFlare *pCoronaFlare)
{
  __int64 v2; // rsi
  UFG::qArray<Render::CoronaFlare *,0> *v3; // rdi
  Render::CoronaFlare *v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  Render::CoronaFlare **v8; // rax

  v2 = this->mCoronaFlares.size;
  v3 = &this->mCoronaFlares;
  v4 = pCoronaFlare;
  v5 = this->mCoronaFlares.capacity;
  v6 = v2 + 1;
  if ( (signed int)v2 + 1 > v5 )
  {
    if ( v5 )
      v7 = 2 * v5;
    else
      v7 = 1;
    for ( ; v7 < v6; v7 *= 2 )
      ;
    if ( v7 <= 2 )
      v7 = 2;
    if ( v7 - v6 > 0x10000 )
      v7 = v2 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mCoronaFlares,
      v7,
      "qArray.Add");
  }
  v8 = v3->p;
  v3->size = v6;
  v8[v2] = v4;
}

// File Line: 87
// RVA: 0x1D3120
void __fastcall Render::CoronaFlareManager::Render(Render::CoronaFlareManager *this, Render::View *view, float fTime)
{
  float v3; // xmm9_4
  Render::CoronaFlareManager *v4; // r14
  Render::View *v5; // r15
  __int64 v6; // r12
  int v7; // xmm3_4
  int v8; // xmm10_4
  int v9; // xmm11_4
  Render::CoronaFlare *v10; // rdx
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm13_4
  int v14; // xmm12_4
  UFG::qResourceData *v15; // rbp
  __m128 v16; // xmm2
  float v17; // xmm6_4
  float v18; // xmm6_4
  int v19; // xmm2_4
  int v20; // xmm1_4
  int v21; // xmm15_4
  float v22; // xmm14_4
  float v23; // xmm15_4
  float v24; // xmm0_4
  float v25; // xmm7_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  unsigned int v28; // esi
  float v29; // xmm0_4
  float v30; // xmm7_4
  float v31; // xmm14_4
  float v32; // xmm13_4
  float v33; // xmm0_4
  float v34; // xmm15_4
  float v35; // xmm7_4
  float v36; // xmm14_4
  float v37; // xmm15_4
  UFG::qResourceData *v38; // rbx
  signed __int64 v39; // rdi
  unsigned int v40; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v41; // rax
  UFG::qResourceData *v42; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v43; // rax
  unsigned int v44; // er8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v45; // rax
  char *v46; // rbx
  float v47; // xmm5_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm5_4
  unsigned int v51; // edi
  Illusion::StateValues *v52; // rax
  float v53; // [rsp+30h] [rbp-158h]
  float v54; // [rsp+34h] [rbp-154h]
  float v55; // [rsp+38h] [rbp-150h]
  float v56; // [rsp+3Ch] [rbp-14Ch]
  float v57; // [rsp+40h] [rbp-148h]
  float v58; // [rsp+44h] [rbp-144h]
  float v59; // [rsp+50h] [rbp-138h]
  float v60; // [rsp+60h] [rbp-128h]
  UFG::qMatrix44 local_world; // [rsp+70h] [rbp-118h]
  Render::Poly poly; // [rsp+B0h] [rbp-D8h]
  float v63; // [rsp+190h] [rbp+8h]
  float v64; // [rsp+1A8h] [rbp+20h]

  v3 = *(float *)&FLOAT_1_0;
  v4 = this;
  v5 = view;
  Render::Poly::Poly(&poly, -0.5, -0.5, 1.0, 1.0, 0.0);
  Render::View::GetStateValues(v5);
  v6 = 0i64;
  if ( v4->mCoronaFlares.size )
  {
    v7 = _xmm[0];
    while ( 1 )
    {
      v8 = LODWORD(v5->mViewWorld.v2.x) ^ v7;
      v9 = LODWORD(v5->mViewWorld.v2.y) ^ v7;
      v10 = v4->mCoronaFlares.p[v6];
      v11 = v10->mTransform.v3.x;
      v12 = v10->mTransform.v3.y;
      v13 = v10->mTransform.v3.z;
      v14 = LODWORD(v5->mViewWorld.v2.z) ^ v7;
      v15 = v10->mSettings.mData;
      v16 = (__m128)LODWORD(v10->mTransform.v3.y);
      v58 = v10->mTransform.v3.y;
      v16.m128_f32[0] = (float)((float)((float)(v16.m128_f32[0] - v5->mViewWorld.v3.y)
                                      * (float)(v16.m128_f32[0] - v5->mViewWorld.v3.y))
                              + (float)((float)(v10->mTransform.v3.x - v5->mViewWorld.v3.x)
                                      * (float)(v10->mTransform.v3.x - v5->mViewWorld.v3.x)))
                      + (float)((float)(v10->mTransform.v3.z - v5->mViewWorld.v3.z)
                              * (float)(v10->mTransform.v3.z - v5->mViewWorld.v3.z));
      v54 = v10->mTransform.v3.z;
      LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v16);
      if ( !BYTE1(v15[1].mNode.mParent) )
        goto LABEL_6;
      v18 = (float)(v17 - *((float *)&v15[1].mNode.mChild[1] + 1)) / *(float *)&v15[1].mNode.mUID;
      if ( v18 > 0.0 )
        break;
      v18 = 0.0;
LABEL_7:
      v19 = LODWORD(v5->mViewWorld.v1.x) ^ v7;
      v20 = LODWORD(v5->mViewWorld.v1.y) ^ v7;
      v21 = LODWORD(v5->mViewWorld.v1.z) ^ v7;
      v22 = (float)(*(float *)&v20 * *(float *)&v14) - (float)(*(float *)&v21 * *(float *)&v9);
      v59 = v22;
      v23 = (float)(*(float *)&v21 * *(float *)&v8) - (float)(*(float *)&v19 * *(float *)&v14);
      v63 = (float)(*(float *)&v19 * *(float *)&v9) - (float)(*(float *)&v20 * *(float *)&v8);
      v60 = v23;
      v64 = (float)(v63 * *(float *)&v9) - (float)(v23 * *(float *)&v14);
      v55 = (float)(v22 * *(float *)&v14) - (float)(v63 * *(float *)&v8);
      v56 = v10->mTransform.v3.w;
      v53 = (float)(v23 * *(float *)&v8) - (float)(v22 * *(float *)&v9);
      v24 = v3
          / (float)((float)((float)((float)(v12 * v5->mWorldViewProjection.v1.w)
                                  + (float)(v11 * v5->mWorldViewProjection.v0.w))
                          + (float)(v13 * v5->mWorldViewProjection.v2.w))
                  + v5->mWorldViewProjection.v3.w);
      v25 = (float)((float)((float)((float)(v11 * v5->mWorldViewProjection.v0.y)
                                  + (float)(v12 * v5->mWorldViewProjection.v1.y))
                          + (float)(v13 * v5->mWorldViewProjection.v2.y))
                  + v5->mWorldViewProjection.v3.y)
          * v24;
      if ( LODWORD(v15[1].mNode.mChild[1]) && v25 <= 0.0 )
      {
        if ( v25 >= 0.0 )
          v26 = 0.0;
        else
          v26 = FLOAT_N1_0;
      }
      else
      {
        v26 = v3;
      }
      v27 = (float)((float)((float)((float)((float)(v11 * v5->mWorldViewProjection.v0.x)
                                          + (float)(v12 * v5->mWorldViewProjection.v1.x))
                                  + (float)(v13 * v5->mWorldViewProjection.v2.x))
                          + v5->mWorldViewProjection.v3.x)
                  * v24)
          * *((float *)&v15[1].mNode.mParent + 1);
      v28 = 0;
      v29 = v27 * v22;
      v30 = (float)((float)((float)(COERCE_FLOAT(LODWORD(v25) & _xmm) * (float)(v3 - *((float *)v15[1].mNode.mChild + 1)))
                          + *((float *)v15[1].mNode.mChild + 1))
                  * v26)
          * *(float *)v15[1].mNode.mChild;
      v31 = v30 * v55;
      v32 = (float)((float)((float)(v30 * v64) + v29) + (float)(*(float *)&v8 * 0.0)) + (float)(v11 * 0.0);
      v33 = v27 * v23;
      v34 = v30;
      v35 = (float)((float)(v30 + v27) + v56) * 0.0;
      v36 = (float)((float)(v31 + v33) + (float)(*(float *)&v9 * 0.0)) + (float)(v12 * 0.0);
      v37 = (float)((float)((float)(v34 * v53) + (float)(v27 * v63)) + (float)(*(float *)&v14 * 0.0))
          + (float)(v54 * 0.0);
      if ( LOBYTE(v15[1].mNode.mParent) )
      {
        v57 = v10->mTransform.v3.x;
        do
        {
          v38 = v4->mCoronaFlareMat.mData;
          v39 = 28i64 * v28;
          v40 = *(_DWORD *)((char *)&v15[1].mResourceHandles.mNode.mNext + v39);
          if ( v38[2].mTypeUID != v40 )
          {
            UFG::qResourceHandle::Init(
              (UFG::qResourceHandle *)&v38[2].mNode.mUID,
              *(_DWORD *)&v38[2].mDebugName[4],
              v40);
            v41 = v38[1].mResourceHandles.mNode.mPrev;
            if ( v41 )
              v41 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v41 + (_QWORD)v38 + 120);
            LOWORD(v41->mPrev) |= 0x20u;
          }
          v42 = v4->mCoronaFlareMat.mData;
          v43 = v42[2].mResourceHandles.mNode.mNext;
          if ( v43 )
          {
            v44 = HIDWORD(v43[6].mNext);
            if ( LODWORD(v42[3].mNode.mChild[1]) != v44 )
            {
              UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v42[2].mDebugName[28], v42[3].mNode.mUID, v44);
              v45 = v42[1].mResourceHandles.mNode.mPrev;
              if ( v45 )
                v45 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)v45 + (_QWORD)v42 + 120);
              LOWORD(v45->mPrev) |= 0x20u;
            }
          }
          v46 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x70u, 0x10u);
          if ( v46 )
          {
            v47 = *(float *)((char *)&v15[1].mResourceHandles.mNode.mNext + v39 + 4);
            v48 = *(float *)((char *)&v15[1].mTypeUID + v39);
            v49 = *(float *)((char *)&v15[1].mResourceHandles.mNode.mNext + v39 + 4) * 0.0;
            local_world.v0.x = (float)(v59 * v47) * v48;
            local_world.v0.w = v48 * v49;
            local_world.v0.z = (float)(v63 * v47) * v48;
            local_world.v0.y = (float)(v60 * v47) * v48;
            local_world.v1.z = v53 * v47;
            local_world.v1.w = v47 * 0.0;
            local_world.v1.y = v55 * v47;
            local_world.v1.x = v64 * v47;
            local_world.v2.y = *(float *)&v9 * v47;
            local_world.v2.z = *(float *)&v14 * v47;
            local_world.v2.w = v47 * 0.0;
            local_world.v2.x = v47 * *(float *)&v8;
            v50 = (float)((float)(3.0 - (float)(v18 * 2.0)) * (float)(v18 * v18))
                * *(float *)((char *)&v15[1].mResourceHandles.mNode.mPrev + v39 + 4);
            v51 = SLOWORD(v4->mStateBlockIndex);
            local_world.v3.x = v57 + (float)(v50 * v32);
            local_world.v3.y = v58 + (float)(v36 * v50);
            local_world.v3.z = v54 + (float)(v37 * v50);
            local_world.v3.w = v56 + (float)(v35 * v50);
            v52 = Render::View::GetStateValues(v5);
            if ( v51 >= 0x40 )
              v52->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)v51 - 64);
            else
              v52->mSetValueMask.mFlags[0] |= 1i64 << v51;
            v52->mParamValues[(signed __int16)v51] = v46;
            Render::View::Draw(v5, &poly, (Illusion::Material *)v4->mCoronaFlareMat.mData, &local_world);
          }
          ++v28;
        }
        while ( v28 < LOBYTE(v15[1].mNode.mParent) );
        v3 = *(float *)&FLOAT_1_0;
      }
      v7 = _xmm[0];
      v6 = (unsigned int)(v6 + 1);
      if ( (unsigned int)v6 >= v4->mCoronaFlares.size )
        return;
    }
    if ( v18 < v3 )
      goto LABEL_7;
LABEL_6:
    v18 = v3;
    goto LABEL_7;
  }
}

