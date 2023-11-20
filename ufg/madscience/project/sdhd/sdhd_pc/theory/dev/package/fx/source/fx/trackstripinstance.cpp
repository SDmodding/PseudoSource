// File Line: 16
// RVA: 0x1C1F30
void __fastcall Render::TrackStripInstance::TrackStripInstance(Render::TrackStripInstance *this)
{
  Render::TrackStripInstance *v1; // rbx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::TrackStripInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettings.mPrev);
  *(_QWORD *)&v1->mStrength = 0i64;
  v1->mStrip = 0i64;
}

// File Line: 21
// RVA: 0x1C4860
void __fastcall Render::TrackStripInstance::~TrackStripInstance(Render::TrackStripInstance *this)
{
  Render::TrackStripInstance *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v5; // rdx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v6; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v7; // rax

  v1 = this;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::TrackStripInstance::`vftable;
  v2 = (UFG::qResourceHandle *)&this->mSettings.mPrev;
  v3 = `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x69CE5438u);
    `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result = v3;
  }
  UFG::qResourceHandle::Close(v2, v3);
  UFG::qResourceHandle::~qResourceHandle(v2);
  v1->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  v5 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
}

// File Line: 40
// RVA: 0x1CFEF0
void __fastcall Render::TrackStripInstance::Init(Render::TrackStripInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *v2; // rax
  unsigned int v3; // ebx
  Render::TrackStripInstance *v4; // rdi
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  v2 = `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result;
  v3 = settingsId;
  v4 = this;
  if ( !`UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v5, 0x69CE5438u);
    `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result = v2;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v4->mSettings.mPrev, 0x69CE5438u, v3, v2);
}

// File Line: 46
// RVA: 0x1C63B0
void __fastcall Render::TrackStripInstance::Activate(Render::TrackStripInstance *this)
{
  if ( !this->mIsActive )
    *(_WORD *)&this->mIsActive = 1;
}

// File Line: 55
// RVA: 0x1CACF0
void __fastcall Render::TrackStripInstance::Deactivate(Render::TrackStripInstance *this, bool willLoopImmediately)
{
  bool v2; // zf

  if ( this->mIsActive )
  {
    v2 = this->mIsSuspended == 0;
    this->mIsActive = 0;
    if ( !v2 )
      this->mIsSuspended = 0;
  }
}

// File Line: 83
// RVA: 0x1DA040
void __fastcall Render::TrackStripInstance::Update(Render::TrackStripInstance *this, UFG::qVector3 *cam_pos, float simTime)
{
  float v3; // xmm14_4
  Render::TrackStripInstance *v4; // rdi
  Render::PolyStrip *v5; // rax
  float v6; // xmm6_4
  Render::PolyStrip *v7; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v8; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v9; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v10; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v11; // rax
  Render::FXInstance *v12; // rax
  UFG::SimComponent *v13; // rbx
  UFG::qMatrix44 *v14; // rdx
  float *v15; // rax
  float v16; // xmm5_4
  float v17; // xmm11_4
  __m128 v18; // xmm12
  float v19; // xmm13_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm9_4
  float v23; // xmm1_4
  signed int v24; // er15
  float v25; // xmm15_4
  Render::PolyStrip *v26; // rsi
  __m128 v27; // xmm2
  Render::PolyStrip *v28; // rax
  UFG::qResourceData *v29; // rbx
  Render::PolyStrip *v30; // rax
  float *v31; // rax
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float *v35; // rax
  float *v36; // rax
  Render::PolyStrip *v37; // rcx
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  Render::PolyStrip *v44; // rcx
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v51; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v52; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v53; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v54; // rax
  Render::PolyStrip *v55; // r9
  signed __int64 v56; // r13
  float v57; // xmm2_4
  signed __int64 v58; // rdx
  signed __int64 v59; // r8
  signed __int64 v60; // r10
  float v61; // xmm0_4
  float v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  Render::PolyStrip *v67; // rcx
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm3_4
  float v75; // xmm4_4
  float v76; // xmm5_4
  float v77; // xmm2_4
  unsigned int v78; // edx
  int v79; // er8
  unsigned __int16 v80; // r8
  unsigned int v81; // edx
  Render::PolyStrip *v82; // rcx
  float v83; // xmm0_4
  float v84; // xmm1_4
  float v85; // xmm0_4
  float v86; // xmm1_4
  float v87; // xmm0_4
  float v88; // xmm1_4
  unsigned int v89; // edx
  int v90; // er8
  unsigned __int16 v91; // r8
  unsigned int v92; // edx
  float v93; // xmm0_4
  float v94; // xmm1_4
  float v95; // xmm0_4
  float v96; // xmm1_4
  float v97; // xmm1_4
  float v98; // xmm0_4
  Render::PolyStrip *v99; // rcx
  float v100; // xmm0_4
  float v101; // xmm1_4
  float v102; // xmm0_4
  float v103; // xmm1_4
  float v104; // xmm0_4
  float v105; // xmm1_4
  Render::PolyStrip *v106; // rcx
  float v107; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm0_4
  float v110; // xmm1_4
  float v111; // xmm0_4
  float v112; // xmm1_4
  UFG::qMatrix44 dst; // [rsp+40h] [rbp-108h]

  v3 = simTime;
  v4 = this;
  if ( this->mSettings.mData )
  {
    v5 = this->mStrip;
    if ( v5 && v5->mUserData != this )
      this->mStrip = 0i64;
    v6 = 0.0;
    if ( this->mStrength > 0.0 )
    {
      v12 = this->mContainer;
      v13 = v12->mParentNode.m_pPointer;
      if ( !v13 || v12->mBasisRelativeToParent )
      {
        v14 = &v12->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12->mParentNode.m_pPointer);
        v14 = (UFG::qMatrix44 *)&v13[2];
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        v14,
        (UFG::qResourceHandle *)&v4->mContainer->mSettings.mPrev,
        v4->mComponentIndex,
        v4->mStartTime);
      v15 = (float *)v4->mSettings.mData;
      v16 = v15[24];
      v17 = dst.v3.x + (float)(COERCE_FLOAT(LODWORD(dst.v1.x) ^ _xmm[0]) * v16);
      v18 = (__m128)LODWORD(dst.v3.y);
      v18.m128_f32[0] = dst.v3.y + (float)(COERCE_FLOAT(LODWORD(dst.v1.y) ^ _xmm[0]) * v16);
      v19 = dst.v3.z + (float)(COERCE_FLOAT(LODWORD(dst.v1.z) ^ _xmm[0]) * v16);
      v20 = (float)(dst.v1.x * v16) + dst.v3.x;
      v21 = (float)(dst.v1.y * v16) + dst.v3.y;
      v22 = (float)(dst.v1.z * v16) + dst.v3.z;
      v23 = v4->mStrength;
      if ( v23 <= 0.30000001 )
      {
        v23 = FLOAT_0_30000001;
      }
      else if ( v23 >= 1.0 )
      {
        v23 = *(float *)&FLOAT_1_0;
      }
      v24 = (signed int)(float)(v23 * 255.0) << 24;
      v25 = v15[27];
      v26 = v4->mStrip;
      if ( !v26
        || (v27 = v18,
            v27.m128_f32[0] = (float)((float)((float)(v18.m128_f32[0] - v26->mPrevVertL.mPosition.y)
                                            * (float)(v18.m128_f32[0] - v26->mPrevVertL.mPosition.y))
                                    + (float)((float)(v17 - v26->mPrevVertL.mPosition.x)
                                            * (float)(v17 - v26->mPrevVertL.mPosition.x)))
                            + (float)((float)(v19 - v26->mPrevVertL.mPosition.z)
                                    * (float)(v19 - v26->mPrevVertL.mPosition.z)),
            LODWORD(v6) = (unsigned __int128)_mm_sqrt_ps(v27),
            v6 >= v15[25]) )
      {
        if ( !v26 || v26->mNumVerts == 48 || v6 > v15[26] )
        {
          v28 = Render::PolyStripManager::AllocStrip(&Render::gPolyStripManager);
          v4->mStrip = v28;
          v28->mUserData = v4;
          v4->mStrip->mShaderUID = (unsigned int)v4->mSettings.mData[1].mNode.mParent;
          v4->mStrip->mTextureUID = HIDWORD(v4->mSettings.mData[1].mNode.mParent);
          v4->mStrip->mSettingsUID = v4->mSettings.mData->mNode.mUID;
          v4->mStrip->mTimeOfCreation = v3;
          v29 = v4->mSettings.mData;
          v4->mStrip->mLifeTime = (float)(UFG::qRandom(1.0, &UFG::qDefaultSeed)
                                        * (float)(*((float *)&v29[1].mNode.mUID + 1) - *(float *)&v29[1].mNode.mUID))
                                + *(float *)&v29[1].mNode.mUID;
          if ( !v26 )
          {
            v30 = v4->mStrip;
            v30->mPrevVertL.mPosition.x = v17;
            LODWORD(v30->mPrevVertL.mPosition.y) = v18.m128_i32[0];
            v30->mPrevVertL.mPosition.z = v19;
            v31 = (float *)v4->mStrip;
            v32 = dst.v2.x;
            v31[11] = dst.v2.x;
            v33 = dst.v2.y;
            v31[12] = dst.v2.y;
            v34 = dst.v2.z;
            v31[13] = dst.v2.z;
            v4->mStrip->mPrevVertL.mColour = v24;
            v4->mStrip->mPrevVertL.mTexCoord0[0] = 0;
            v4->mStrip->mPrevVertL.mTexCoord0[1] = 0;
            v35 = (float *)v4->mStrip;
            v35[18] = v20;
            v35[19] = v21;
            v35[20] = v22;
            v36 = (float *)v4->mStrip;
            v36[23] = v32;
            v36[24] = v33;
            v36[25] = v34;
            v4->mStrip->mPrevVertR.mColour = v24;
            v4->mStrip->mPrevVertR.mTexCoord0[0] = 15360;
            v4->mStrip->mPrevVertR.mTexCoord0[1] = 0;
            return;
          }
          v37 = v4->mStrip;
          v38 = v26->mPrevVertL.mPosition.y;
          v39 = v26->mPrevVertL.mPosition.z;
          v37->mPrevVertL.mPosition.x = v26->mPrevVertL.mPosition.x;
          v37->mPrevVertL.mPosition.y = v38;
          v37->mPrevVertL.mPosition.z = v39;
          v37->mPrevVertL.mTexCoord0[0] = v26->mPrevVertL.mTexCoord0[0];
          v37->mPrevVertL.mTexCoord0[1] = v26->mPrevVertL.mTexCoord0[1];
          v37->mPrevVertL.mTexCoord1[0] = v26->mPrevVertL.mTexCoord1[0];
          v37->mPrevVertL.mTexCoord1[1] = v26->mPrevVertL.mTexCoord1[1];
          v40 = v26->mPrevVertL.mNormal.y;
          v41 = v26->mPrevVertL.mNormal.z;
          v37->mPrevVertL.mNormal.x = v26->mPrevVertL.mNormal.x;
          v37->mPrevVertL.mNormal.y = v40;
          v37->mPrevVertL.mNormal.z = v41;
          v42 = v26->mPrevVertL.mTangent.y;
          v43 = v26->mPrevVertL.mTangent.z;
          v37->mPrevVertL.mTangent.x = v26->mPrevVertL.mTangent.x;
          v37->mPrevVertL.mTangent.y = v42;
          v37->mPrevVertL.mTangent.z = v43;
          v37->mPrevVertL.mColour = v26->mPrevVertL.mColour;
          v4->mStrip->mPrevVertL.mTexCoord0[0] = 0;
          v4->mStrip->mPrevVertL.mTexCoord0[1] = 0;
          v44 = v4->mStrip;
          v45 = v26->mPrevVertR.mPosition.y;
          v46 = v26->mPrevVertR.mPosition.z;
          v44->mPrevVertR.mPosition.x = v26->mPrevVertR.mPosition.x;
          v44->mPrevVertR.mPosition.y = v45;
          v44->mPrevVertR.mPosition.z = v46;
          v44->mPrevVertR.mTexCoord0[0] = v26->mPrevVertR.mTexCoord0[0];
          v44->mPrevVertR.mTexCoord0[1] = v26->mPrevVertR.mTexCoord0[1];
          v44->mPrevVertR.mTexCoord1[0] = v26->mPrevVertR.mTexCoord1[0];
          v44->mPrevVertR.mTexCoord1[1] = v26->mPrevVertR.mTexCoord1[1];
          v47 = v26->mPrevVertR.mNormal.y;
          v48 = v26->mPrevVertR.mNormal.z;
          v44->mPrevVertR.mNormal.x = v26->mPrevVertR.mNormal.x;
          v44->mPrevVertR.mNormal.y = v47;
          v44->mPrevVertR.mNormal.z = v48;
          v49 = v26->mPrevVertR.mTangent.y;
          v50 = v26->mPrevVertR.mTangent.z;
          v44->mPrevVertR.mTangent.x = v26->mPrevVertR.mTangent.x;
          v44->mPrevVertR.mTangent.y = v49;
          v44->mPrevVertR.mTangent.z = v50;
          v44->mPrevVertR.mColour = v26->mPrevVertR.mColour;
          v4->mStrip->mPrevVertR.mTexCoord0[0] = 15360;
          v4->mStrip->mPrevVertR.mTexCoord0[1] = 0;
        }
        v51 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v4->mStrip;
        v52 = v51->mPrev;
        v53 = v51->mNext;
        v52->mNext = v53;
        v53->mPrev = v52;
        v51->mPrev = v51;
        v51->mNext = v51;
        v54 = stru_142366970.mNode.mNext;
        stru_142366970.mNode.mNext = v51;
        v51->mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
        v51->mNext = v54;
        v54->mPrev = v51;
        v55 = v4->mStrip;
        v56 = v55->mNumVerts;
        v57 = (float)v55->mNumVerts * 0.16666667;
        v58 = v56;
        v59 = (signed int)v56 + 1;
        v60 = (signed int)v56 + 2;
        v61 = v55->mPrevVertL.mPosition.y;
        v62 = v55->mPrevVertL.mPosition.z;
        v55->mVerts[v58].mPosition.x = v55->mPrevVertL.mPosition.x;
        v55->mVerts[v58].mPosition.y = v61;
        v55->mVerts[v58].mPosition.z = v62;
        v55->mVerts[v58].mTexCoord0[0] = v55->mPrevVertL.mTexCoord0[0];
        v55->mVerts[v58].mTexCoord0[1] = v55->mPrevVertL.mTexCoord0[1];
        v55->mVerts[v58].mTexCoord1[0] = v55->mPrevVertL.mTexCoord1[0];
        v55->mVerts[v58].mTexCoord1[1] = v55->mPrevVertL.mTexCoord1[1];
        v63 = v55->mPrevVertL.mNormal.y;
        v64 = v55->mPrevVertL.mNormal.z;
        v55->mVerts[v58].mNormal.x = v55->mPrevVertL.mNormal.x;
        v55->mVerts[v58].mNormal.y = v63;
        v55->mVerts[v58].mNormal.z = v64;
        v65 = v55->mPrevVertL.mTangent.y;
        v66 = v55->mPrevVertL.mTangent.z;
        v55->mVerts[v58].mTangent.x = v55->mPrevVertL.mTangent.x;
        v55->mVerts[v58].mTangent.y = v65;
        v55->mVerts[v58].mTangent.z = v66;
        v55->mVerts[v58].mColour = v55->mPrevVertL.mColour;
        v67 = v4->mStrip;
        v68 = v67->mPrevVertR.mPosition.y;
        v69 = v67->mPrevVertR.mPosition.z;
        v55->mVerts[v59].mPosition.x = v67->mPrevVertR.mPosition.x;
        v55->mVerts[v59].mPosition.y = v68;
        v55->mVerts[v59].mPosition.z = v69;
        v55->mVerts[v59].mTexCoord0[0] = v67->mPrevVertR.mTexCoord0[0];
        v55->mVerts[v59].mTexCoord0[1] = v67->mPrevVertR.mTexCoord0[1];
        v55->mVerts[v59].mTexCoord1[0] = v67->mPrevVertR.mTexCoord1[0];
        v55->mVerts[v59].mTexCoord1[1] = v67->mPrevVertR.mTexCoord1[1];
        v70 = v67->mPrevVertR.mNormal.y;
        v71 = v67->mPrevVertR.mNormal.z;
        v55->mVerts[v59].mNormal.x = v67->mPrevVertR.mNormal.x;
        v55->mVerts[v59].mNormal.y = v70;
        v55->mVerts[v59].mNormal.z = v71;
        v72 = v67->mPrevVertR.mTangent.y;
        v73 = v67->mPrevVertR.mTangent.z;
        v55->mVerts[v59].mTangent.x = v67->mPrevVertR.mTangent.x;
        v55->mVerts[v59].mTangent.y = v72;
        v55->mVerts[v59].mTangent.z = v73;
        v55->mVerts[v59].mColour = v67->mPrevVertR.mColour;
        v55->mVerts[v60].mPosition.x = v17;
        LODWORD(v55->mVerts[v60].mPosition.y) = v18.m128_i32[0];
        v55->mVerts[v60].mPosition.z = v19;
        v74 = dst.v2.x;
        v55->mVerts[v60].mNormal.x = dst.v2.x;
        v75 = dst.v2.y;
        v55->mVerts[v60].mNormal.y = dst.v2.y;
        v76 = dst.v2.z;
        v55->mVerts[v60].mNormal.z = dst.v2.z;
        v55->mVerts[v60].mColour = v24;
        v55->mVerts[(signed int)v56 + 2].mTexCoord0[0] = 0;
        v77 = (float)(v57 + 1.0) * v25;
        v78 = LODWORD(v77) & 0x7FFFFFFF;
        v79 = (LODWORD(v77) >> 16) & 0x8000;
        if ( (LODWORD(v77) & 0x7FFFFFFFu) <= 0x47FFEFFF )
        {
          if ( v78 >= 0x38800000 )
            v81 = v78 - 939524096;
          else
            v81 = (LODWORD(v77) & 0x7FFFFF | 0x800000u) >> (113 - (v78 >> 23));
          v80 = ((((v81 >> 13) & 1) + v81 + 4095) >> 13) | v79;
        }
        else
        {
          v80 = v79 | 0x7FFF;
        }
        v55->mVerts[(signed int)v56 + 2].mTexCoord0[1] = v80;
        v82 = v4->mStrip;
        v83 = v82->mPrevVertR.mPosition.y;
        v84 = v82->mPrevVertR.mPosition.z;
        v55->mVerts[(signed int)v56 + 3].mPosition.x = v82->mPrevVertR.mPosition.x;
        v55->mVerts[(signed int)v56 + 3].mPosition.y = v83;
        v55->mVerts[(signed int)v56 + 3].mPosition.z = v84;
        v55->mVerts[(signed int)v56 + 3].mTexCoord0[0] = v82->mPrevVertR.mTexCoord0[0];
        v55->mVerts[(signed int)v56 + 3].mTexCoord0[1] = v82->mPrevVertR.mTexCoord0[1];
        v55->mVerts[(signed int)v56 + 3].mTexCoord1[0] = v82->mPrevVertR.mTexCoord1[0];
        v55->mVerts[(signed int)v56 + 3].mTexCoord1[1] = v82->mPrevVertR.mTexCoord1[1];
        v85 = v82->mPrevVertR.mNormal.y;
        v86 = v82->mPrevVertR.mNormal.z;
        v55->mVerts[(signed int)v56 + 3].mNormal.x = v82->mPrevVertR.mNormal.x;
        v55->mVerts[(signed int)v56 + 3].mNormal.y = v85;
        v55->mVerts[(signed int)v56 + 3].mNormal.z = v86;
        v87 = v82->mPrevVertR.mTangent.y;
        v88 = v82->mPrevVertR.mTangent.z;
        v55->mVerts[(signed int)v56 + 3].mTangent.x = v82->mPrevVertR.mTangent.x;
        v55->mVerts[(signed int)v56 + 3].mTangent.y = v87;
        v55->mVerts[(signed int)v56 + 3].mTangent.z = v88;
        v55->mVerts[(signed int)v56 + 3].mColour = v82->mPrevVertR.mColour;
        v55->mVerts[(signed int)v56 + 4].mPosition.x = v20;
        v55->mVerts[(signed int)v56 + 4].mPosition.y = v21;
        v55->mVerts[(signed int)v56 + 4].mPosition.z = v22;
        v55->mVerts[(signed int)v56 + 4].mNormal.x = v74;
        v55->mVerts[(signed int)v56 + 4].mNormal.y = v75;
        v55->mVerts[(signed int)v56 + 4].mNormal.z = v76;
        v55->mVerts[(signed int)v56 + 4].mColour = v24;
        v55->mVerts[(signed int)v56 + 4].mTexCoord0[0] = 15360;
        v89 = LODWORD(v77) & 0x7FFFFFFF;
        v90 = (LODWORD(v77) >> 16) & 0x8000;
        if ( (LODWORD(v77) & 0x7FFFFFFFu) <= 0x47FFEFFF )
        {
          if ( v89 >= 0x38800000 )
            v92 = v89 - 939524096;
          else
            v92 = (LODWORD(v77) & 0x7FFFFF | 0x800000u) >> (113 - (v89 >> 23));
          v91 = ((((v92 >> 13) & 1) + v92 + 4095) >> 13) | v90;
        }
        else
        {
          v91 = v90 | 0x7FFF;
        }
        v55->mVerts[(signed int)v56 + 4].mTexCoord0[1] = v91;
        v93 = v55->mVerts[(signed int)v56 + 2].mPosition.y;
        v94 = v55->mVerts[(signed int)v56 + 2].mPosition.z;
        v55->mVerts[(signed int)v56 + 5].mPosition.x = v55->mVerts[(signed int)v56 + 2].mPosition.x;
        v55->mVerts[(signed int)v56 + 5].mPosition.y = v93;
        v55->mVerts[(signed int)v56 + 5].mPosition.z = v94;
        v55->mVerts[(signed int)v56 + 5].mTexCoord0[0] = v55->mVerts[(signed int)v56 + 2].mTexCoord0[0];
        v55->mVerts[(signed int)v56 + 5].mTexCoord0[1] = v55->mVerts[(signed int)v56 + 2].mTexCoord0[1];
        v55->mVerts[(signed int)v56 + 5].mTexCoord1[0] = v55->mVerts[(signed int)v56 + 2].mTexCoord1[0];
        v55->mVerts[(signed int)v56 + 5].mTexCoord1[1] = v55->mVerts[(signed int)v56 + 2].mTexCoord1[1];
        v95 = v55->mVerts[(signed int)v56 + 2].mNormal.y;
        v96 = v55->mVerts[(signed int)v56 + 2].mNormal.z;
        v55->mVerts[(signed int)v56 + 5].mNormal.x = v55->mVerts[(signed int)v56 + 2].mNormal.x;
        v55->mVerts[(signed int)v56 + 5].mNormal.y = v95;
        v55->mVerts[(signed int)v56 + 5].mNormal.z = v96;
        v97 = v55->mVerts[(signed int)v56 + 2].mTangent.y;
        v98 = v55->mVerts[(signed int)v56 + 2].mTangent.z;
        v55->mVerts[(signed int)v56 + 5].mTangent.x = v55->mVerts[(signed int)v56 + 2].mTangent.x;
        v55->mVerts[(signed int)v56 + 5].mTangent.y = v97;
        v55->mVerts[(signed int)v56 + 5].mTangent.z = v98;
        v55->mVerts[(signed int)v56 + 5].mColour = v55->mVerts[(signed int)v56 + 2].mColour;
        v4->mStrip->mNumVerts = v56 + 6;
        v99 = v4->mStrip;
        v100 = v55->mVerts[(signed int)v56 + 2].mPosition.y;
        v101 = v55->mVerts[(signed int)v56 + 2].mPosition.z;
        v99->mPrevVertL.mPosition.x = v55->mVerts[(signed int)v56 + 2].mPosition.x;
        v99->mPrevVertL.mPosition.y = v100;
        v99->mPrevVertL.mPosition.z = v101;
        v99->mPrevVertL.mTexCoord0[0] = v55->mVerts[(signed int)v56 + 2].mTexCoord0[0];
        v99->mPrevVertL.mTexCoord0[1] = v55->mVerts[(signed int)v56 + 2].mTexCoord0[1];
        v99->mPrevVertL.mTexCoord1[0] = v55->mVerts[(signed int)v56 + 2].mTexCoord1[0];
        v99->mPrevVertL.mTexCoord1[1] = v55->mVerts[(signed int)v56 + 2].mTexCoord1[1];
        v102 = v55->mVerts[(signed int)v56 + 2].mNormal.y;
        v103 = v55->mVerts[(signed int)v56 + 2].mNormal.z;
        v99->mPrevVertL.mNormal.x = v55->mVerts[(signed int)v56 + 2].mNormal.x;
        v99->mPrevVertL.mNormal.y = v102;
        v99->mPrevVertL.mNormal.z = v103;
        v104 = v55->mVerts[(signed int)v56 + 2].mTangent.y;
        v105 = v55->mVerts[(signed int)v56 + 2].mTangent.z;
        v99->mPrevVertL.mTangent.x = v55->mVerts[(signed int)v56 + 2].mTangent.x;
        v99->mPrevVertL.mTangent.y = v104;
        v99->mPrevVertL.mTangent.z = v105;
        v99->mPrevVertL.mColour = v55->mVerts[(signed int)v56 + 2].mColour;
        v106 = v4->mStrip;
        v107 = v55->mVerts[(signed int)v56 + 4].mPosition.y;
        v108 = v55->mVerts[(signed int)v56 + 4].mPosition.z;
        v106->mPrevVertR.mPosition.x = v55->mVerts[(signed int)v56 + 4].mPosition.x;
        v106->mPrevVertR.mPosition.y = v107;
        v106->mPrevVertR.mPosition.z = v108;
        v106->mPrevVertR.mTexCoord0[0] = v55->mVerts[(signed int)v56 + 4].mTexCoord0[0];
        v106->mPrevVertR.mTexCoord0[1] = v55->mVerts[(signed int)v56 + 4].mTexCoord0[1];
        v106->mPrevVertR.mTexCoord1[0] = v55->mVerts[(signed int)v56 + 4].mTexCoord1[0];
        v106->mPrevVertR.mTexCoord1[1] = v55->mVerts[(signed int)v56 + 4].mTexCoord1[1];
        v109 = v55->mVerts[(signed int)v56 + 4].mNormal.y;
        v110 = v55->mVerts[(signed int)v56 + 4].mNormal.z;
        v106->mPrevVertR.mNormal.x = v55->mVerts[(signed int)v56 + 4].mNormal.x;
        v106->mPrevVertR.mNormal.y = v109;
        v106->mPrevVertR.mNormal.z = v110;
        v111 = v55->mVerts[(signed int)v56 + 4].mTangent.y;
        v112 = v55->mVerts[(signed int)v56 + 4].mTangent.z;
        v106->mPrevVertR.mTangent.x = v55->mVerts[(signed int)v56 + 4].mTangent.x;
        v106->mPrevVertR.mTangent.y = v111;
        v106->mPrevVertR.mTangent.z = v112;
        v106->mPrevVertR.mColour = v55->mVerts[(signed int)v56 + 4].mColour;
      }
    }
    else
    {
      v7 = this->mStrip;
      if ( v7 )
      {
        if ( !v7->mNumVerts )
        {
          v8 = v7->mPrev;
          v9 = v7->mNext;
          v8->mNext = v9;
          v9->mPrev = v8;
          v7->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&v7->mPrev;
          v7->mNext = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&v7->mPrev;
          v10 = v7->mPrev;
          v11 = v7->mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v7->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&v7->mPrev;
          v7->mNext = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)&v7->mPrev;
          v7->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)unk_142366958;
          unk_142366958 = v7;
          --unk_142366964;
        }
      }
      v4->mStrip = 0i64;
    }
  }
}

