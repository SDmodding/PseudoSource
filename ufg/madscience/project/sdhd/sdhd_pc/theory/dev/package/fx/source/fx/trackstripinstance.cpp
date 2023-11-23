// File Line: 16
// RVA: 0x1C1F30
void __fastcall Render::TrackStripInstance::TrackStripInstance(Render::TrackStripInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::TrackStripInstance::`vftable;
  UFG::qResourceHandle::qResourceHandle(&this->mSettings);
  *(_QWORD *)&this->mStrength = 0i64;
  this->mStrip = 0i64;
}

// File Line: 21
// RVA: 0x1C4860
void __fastcall Render::TrackStripInstance::~TrackStripInstance(Render::TrackStripInstance *this)
{
  Render::TrackStripSettingsHandle *p_mSettings; // rdi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mPrev; // rcx
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *mNext; // rax

  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::TrackStripInstance::`vftable;
  p_mSettings = &this->mSettings;
  Inventory = `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x69CE5438u);
    `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(p_mSettings, Inventory);
  UFG::qResourceHandle::~qResourceHandle(p_mSettings);
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
}

// File Line: 40
// RVA: 0x1CFEF0
void __fastcall Render::TrackStripInstance::Init(Render::TrackStripInstance *this, unsigned int settingsId)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mSettingsId = settingsId;
  Inventory = `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x69CE5438u);
    `UFG::qGetResourceInventory<Render::TrackStripSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettings, 0x69CE5438u, settingsId, Inventory);
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
    v2 = !this->mIsSuspended;
    this->mIsActive = 0;
    if ( !v2 )
      this->mIsSuspended = 0;
  }
}

// File Line: 83
// RVA: 0x1DA040
void __fastcall Render::TrackStripInstance::Update(
        Render::TrackStripInstance *this,
        UFG::qVector3 *cam_pos,
        float simTime)
{
  Render::PolyStrip *mStrip; // rax
  float v6; // xmm6_4
  Render::PolyStrip *v7; // rdx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v8; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v9; // rax
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v10; // rcx
  UFG::qNode<Render::PolyStrip,Render::PolyStrip> *v11; // rax
  Render::FXInstance *mContainer; // rax
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qMatrix44 *p_mBasis; // rdx
  float *mData; // rax
  float v16; // xmm5_4
  float v17; // xmm11_4
  __int128 y_low; // xmm12
  float v19; // xmm13_4
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm9_4
  float mStrength; // xmm1_4
  unsigned int v24; // r15d
  float v25; // xmm15_4
  Render::PolyStrip *v26; // rsi
  __m128 v27; // xmm2
  Render::PolyStrip *v28; // rax
  UFG::qResourceData *v29; // rbx
  Render::PolyStrip *v30; // rax
  Render::PolyStrip *v31; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Render::PolyStrip *v35; // rax
  Render::PolyStrip *v36; // rax
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
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mPrev; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v54; // rax
  Render::PolyStrip *v55; // r9
  __int64 mNumVerts; // r13
  float v57; // xmm2_4
  __int64 v58; // rdx
  __int64 v59; // r8
  __int64 v60; // r10
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
  int v79; // r8d
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
  int v90; // r8d
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
  UFG::qMatrix44 dst; // [rsp+40h] [rbp-108h] BYREF

  if ( this->mSettings.mData )
  {
    mStrip = this->mStrip;
    if ( mStrip && mStrip->mUserData != this )
      this->mStrip = 0i64;
    v6 = 0.0;
    if ( this->mStrength > 0.0 )
    {
      mContainer = this->mContainer;
      m_pPointer = mContainer->mParentNode.m_pPointer;
      if ( !m_pPointer || mContainer->mBasisRelativeToParent )
      {
        p_mBasis = &mContainer->mBasis;
      }
      else
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mContainer->mParentNode.m_pPointer);
        p_mBasis = (UFG::qMatrix44 *)&m_pPointer[2];
      }
      Render::FXInstance::CalcBasisHelper(
        &dst,
        p_mBasis,
        &this->mContainer->mSettings,
        this->mComponentIndex,
        this->mStartTime);
      mData = (float *)this->mSettings.mData;
      v16 = mData[24];
      v17 = dst.v3.x + (float)(COERCE_FLOAT(LODWORD(dst.v1.x) ^ _xmm[0]) * v16);
      y_low = LODWORD(dst.v3.y);
      *(float *)&y_low = dst.v3.y + (float)(COERCE_FLOAT(LODWORD(dst.v1.y) ^ _xmm[0]) * v16);
      v19 = dst.v3.z + (float)(COERCE_FLOAT(LODWORD(dst.v1.z) ^ _xmm[0]) * v16);
      v20 = (float)(dst.v1.x * v16) + dst.v3.x;
      v21 = (float)(dst.v1.y * v16) + dst.v3.y;
      v22 = (float)(dst.v1.z * v16) + dst.v3.z;
      mStrength = this->mStrength;
      if ( mStrength <= 0.30000001 )
      {
        mStrength = FLOAT_0_30000001;
      }
      else if ( mStrength >= 1.0 )
      {
        mStrength = *(float *)&FLOAT_1_0;
      }
      v24 = (int)(float)(mStrength * 255.0) << 24;
      v25 = mData[27];
      v26 = this->mStrip;
      if ( !v26
        || (v27 = (__m128)y_low,
            v27.m128_f32[0] = (float)((float)((float)(*(float *)&y_low - v26->mPrevVertL.mPosition.y)
                                            * (float)(*(float *)&y_low - v26->mPrevVertL.mPosition.y))
                                    + (float)((float)(v17 - v26->mPrevVertL.mPosition.x)
                                            * (float)(v17 - v26->mPrevVertL.mPosition.x)))
                            + (float)((float)(v19 - v26->mPrevVertL.mPosition.z)
                                    * (float)(v19 - v26->mPrevVertL.mPosition.z)),
            v6 = _mm_sqrt_ps(v27).m128_f32[0],
            v6 >= mData[25]) )
      {
        if ( !v26 || v26->mNumVerts == 48 || v6 > mData[26] )
        {
          v28 = Render::PolyStripManager::AllocStrip(&Render::gPolyStripManager);
          this->mStrip = v28;
          v28->mUserData = this;
          this->mStrip->mShaderUID = (unsigned int)this->mSettings.mData[1].mNode.mParent;
          this->mStrip->mTextureUID = HIDWORD(this->mSettings.mData[1].mNode.mParent);
          this->mStrip->mSettingsUID = this->mSettings.mData->mNode.mUID;
          this->mStrip->mTimeOfCreation = simTime;
          v29 = this->mSettings.mData;
          this->mStrip->mLifeTime = (float)(UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed)
                                          * (float)(*((float *)&v29[1].mNode.mUID + 1) - *(float *)&v29[1].mNode.mUID))
                                  + *(float *)&v29[1].mNode.mUID;
          if ( !v26 )
          {
            v30 = this->mStrip;
            v30->mPrevVertL.mPosition.x = v17;
            LODWORD(v30->mPrevVertL.mPosition.y) = y_low;
            v30->mPrevVertL.mPosition.z = v19;
            v31 = this->mStrip;
            x = dst.v2.x;
            v31->mPrevVertL.mNormal.x = dst.v2.x;
            y = dst.v2.y;
            v31->mPrevVertL.mNormal.y = dst.v2.y;
            z = dst.v2.z;
            v31->mPrevVertL.mNormal.z = dst.v2.z;
            this->mStrip->mPrevVertL.mColour = v24;
            this->mStrip->mPrevVertL.mTexCoord0[0] = 0;
            this->mStrip->mPrevVertL.mTexCoord0[1] = 0;
            v35 = this->mStrip;
            v35->mPrevVertR.mPosition.x = v20;
            v35->mPrevVertR.mPosition.y = v21;
            v35->mPrevVertR.mPosition.z = v22;
            v36 = this->mStrip;
            v36->mPrevVertR.mNormal.x = x;
            v36->mPrevVertR.mNormal.y = y;
            v36->mPrevVertR.mNormal.z = z;
            this->mStrip->mPrevVertR.mColour = v24;
            this->mStrip->mPrevVertR.mTexCoord0[0] = 15360;
            this->mStrip->mPrevVertR.mTexCoord0[1] = 0;
            return;
          }
          v37 = this->mStrip;
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
          this->mStrip->mPrevVertL.mTexCoord0[0] = 0;
          this->mStrip->mPrevVertL.mTexCoord0[1] = 0;
          v44 = this->mStrip;
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
          this->mStrip->mPrevVertR.mTexCoord0[0] = 15360;
          this->mStrip->mPrevVertR.mTexCoord0[1] = 0;
        }
        v51 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)this->mStrip;
        mPrev = v51->mPrev;
        mNext = v51->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v51->mPrev = v51;
        v51->mNext = v51;
        v54 = stru_142366970.mNode.mNext;
        stru_142366970.mNode.mNext = v51;
        v51->mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_142366970;
        v51->mNext = v54;
        v54->mPrev = v51;
        v55 = this->mStrip;
        mNumVerts = v55->mNumVerts;
        v57 = (float)v55->mNumVerts * 0.16666667;
        v58 = mNumVerts;
        v59 = (int)mNumVerts + 1;
        v60 = (int)mNumVerts + 2;
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
        v67 = this->mStrip;
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
        LODWORD(v55->mVerts[v60].mPosition.y) = y_low;
        v55->mVerts[v60].mPosition.z = v19;
        v74 = dst.v2.x;
        v55->mVerts[v60].mNormal.x = dst.v2.x;
        v75 = dst.v2.y;
        v55->mVerts[v60].mNormal.y = dst.v2.y;
        v76 = dst.v2.z;
        v55->mVerts[v60].mNormal.z = dst.v2.z;
        v55->mVerts[v60].mColour = v24;
        v55->mVerts[(int)mNumVerts + 2].mTexCoord0[0] = 0;
        v77 = (float)(v57 + 1.0) * v25;
        v78 = LODWORD(v77) & 0x7FFFFFFF;
        v79 = HIWORD(LODWORD(v77)) & 0x8000;
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
        v55->mVerts[(int)mNumVerts + 2].mTexCoord0[1] = v80;
        v82 = this->mStrip;
        v83 = v82->mPrevVertR.mPosition.y;
        v84 = v82->mPrevVertR.mPosition.z;
        v55->mVerts[(int)mNumVerts + 3].mPosition.x = v82->mPrevVertR.mPosition.x;
        v55->mVerts[(int)mNumVerts + 3].mPosition.y = v83;
        v55->mVerts[(int)mNumVerts + 3].mPosition.z = v84;
        v55->mVerts[(int)mNumVerts + 3].mTexCoord0[0] = v82->mPrevVertR.mTexCoord0[0];
        v55->mVerts[(int)mNumVerts + 3].mTexCoord0[1] = v82->mPrevVertR.mTexCoord0[1];
        v55->mVerts[(int)mNumVerts + 3].mTexCoord1[0] = v82->mPrevVertR.mTexCoord1[0];
        v55->mVerts[(int)mNumVerts + 3].mTexCoord1[1] = v82->mPrevVertR.mTexCoord1[1];
        v85 = v82->mPrevVertR.mNormal.y;
        v86 = v82->mPrevVertR.mNormal.z;
        v55->mVerts[(int)mNumVerts + 3].mNormal.x = v82->mPrevVertR.mNormal.x;
        v55->mVerts[(int)mNumVerts + 3].mNormal.y = v85;
        v55->mVerts[(int)mNumVerts + 3].mNormal.z = v86;
        v87 = v82->mPrevVertR.mTangent.y;
        v88 = v82->mPrevVertR.mTangent.z;
        v55->mVerts[(int)mNumVerts + 3].mTangent.x = v82->mPrevVertR.mTangent.x;
        v55->mVerts[(int)mNumVerts + 3].mTangent.y = v87;
        v55->mVerts[(int)mNumVerts + 3].mTangent.z = v88;
        v55->mVerts[(int)mNumVerts + 3].mColour = v82->mPrevVertR.mColour;
        v55->mVerts[(int)mNumVerts + 4].mPosition.x = v20;
        v55->mVerts[(int)mNumVerts + 4].mPosition.y = v21;
        v55->mVerts[(int)mNumVerts + 4].mPosition.z = v22;
        v55->mVerts[(int)mNumVerts + 4].mNormal.x = v74;
        v55->mVerts[(int)mNumVerts + 4].mNormal.y = v75;
        v55->mVerts[(int)mNumVerts + 4].mNormal.z = v76;
        v55->mVerts[(int)mNumVerts + 4].mColour = v24;
        v55->mVerts[(int)mNumVerts + 4].mTexCoord0[0] = 15360;
        v89 = LODWORD(v77) & 0x7FFFFFFF;
        v90 = HIWORD(LODWORD(v77)) & 0x8000;
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
        v55->mVerts[(int)mNumVerts + 4].mTexCoord0[1] = v91;
        v93 = v55->mVerts[(int)mNumVerts + 2].mPosition.y;
        v94 = v55->mVerts[(int)mNumVerts + 2].mPosition.z;
        v55->mVerts[(int)mNumVerts + 5].mPosition.x = v55->mVerts[(int)mNumVerts + 2].mPosition.x;
        v55->mVerts[(int)mNumVerts + 5].mPosition.y = v93;
        v55->mVerts[(int)mNumVerts + 5].mPosition.z = v94;
        v55->mVerts[(int)mNumVerts + 5].mTexCoord0[0] = v55->mVerts[(int)mNumVerts + 2].mTexCoord0[0];
        v55->mVerts[(int)mNumVerts + 5].mTexCoord0[1] = v55->mVerts[(int)mNumVerts + 2].mTexCoord0[1];
        v55->mVerts[(int)mNumVerts + 5].mTexCoord1[0] = v55->mVerts[(int)mNumVerts + 2].mTexCoord1[0];
        v55->mVerts[(int)mNumVerts + 5].mTexCoord1[1] = v55->mVerts[(int)mNumVerts + 2].mTexCoord1[1];
        v95 = v55->mVerts[(int)mNumVerts + 2].mNormal.y;
        v96 = v55->mVerts[(int)mNumVerts + 2].mNormal.z;
        v55->mVerts[(int)mNumVerts + 5].mNormal.x = v55->mVerts[(int)mNumVerts + 2].mNormal.x;
        v55->mVerts[(int)mNumVerts + 5].mNormal.y = v95;
        v55->mVerts[(int)mNumVerts + 5].mNormal.z = v96;
        v97 = v55->mVerts[(int)mNumVerts + 2].mTangent.y;
        v98 = v55->mVerts[(int)mNumVerts + 2].mTangent.z;
        v55->mVerts[(int)mNumVerts + 5].mTangent.x = v55->mVerts[(int)mNumVerts + 2].mTangent.x;
        v55->mVerts[(int)mNumVerts + 5].mTangent.y = v97;
        v55->mVerts[(int)mNumVerts + 5].mTangent.z = v98;
        v55->mVerts[(int)mNumVerts + 5].mColour = v55->mVerts[(int)mNumVerts + 2].mColour;
        this->mStrip->mNumVerts = mNumVerts + 6;
        v99 = this->mStrip;
        v100 = v55->mVerts[(int)mNumVerts + 2].mPosition.y;
        v101 = v55->mVerts[(int)mNumVerts + 2].mPosition.z;
        v99->mPrevVertL.mPosition.x = v55->mVerts[(int)mNumVerts + 2].mPosition.x;
        v99->mPrevVertL.mPosition.y = v100;
        v99->mPrevVertL.mPosition.z = v101;
        v99->mPrevVertL.mTexCoord0[0] = v55->mVerts[(int)mNumVerts + 2].mTexCoord0[0];
        v99->mPrevVertL.mTexCoord0[1] = v55->mVerts[(int)mNumVerts + 2].mTexCoord0[1];
        v99->mPrevVertL.mTexCoord1[0] = v55->mVerts[(int)mNumVerts + 2].mTexCoord1[0];
        v99->mPrevVertL.mTexCoord1[1] = v55->mVerts[(int)mNumVerts + 2].mTexCoord1[1];
        v102 = v55->mVerts[(int)mNumVerts + 2].mNormal.y;
        v103 = v55->mVerts[(int)mNumVerts + 2].mNormal.z;
        v99->mPrevVertL.mNormal.x = v55->mVerts[(int)mNumVerts + 2].mNormal.x;
        v99->mPrevVertL.mNormal.y = v102;
        v99->mPrevVertL.mNormal.z = v103;
        v104 = v55->mVerts[(int)mNumVerts + 2].mTangent.y;
        v105 = v55->mVerts[(int)mNumVerts + 2].mTangent.z;
        v99->mPrevVertL.mTangent.x = v55->mVerts[(int)mNumVerts + 2].mTangent.x;
        v99->mPrevVertL.mTangent.y = v104;
        v99->mPrevVertL.mTangent.z = v105;
        v99->mPrevVertL.mColour = v55->mVerts[(int)mNumVerts + 2].mColour;
        v106 = this->mStrip;
        v107 = v55->mVerts[(int)mNumVerts + 4].mPosition.y;
        v108 = v55->mVerts[(int)mNumVerts + 4].mPosition.z;
        v106->mPrevVertR.mPosition.x = v55->mVerts[(int)mNumVerts + 4].mPosition.x;
        v106->mPrevVertR.mPosition.y = v107;
        v106->mPrevVertR.mPosition.z = v108;
        v106->mPrevVertR.mTexCoord0[0] = v55->mVerts[(int)mNumVerts + 4].mTexCoord0[0];
        v106->mPrevVertR.mTexCoord0[1] = v55->mVerts[(int)mNumVerts + 4].mTexCoord0[1];
        v106->mPrevVertR.mTexCoord1[0] = v55->mVerts[(int)mNumVerts + 4].mTexCoord1[0];
        v106->mPrevVertR.mTexCoord1[1] = v55->mVerts[(int)mNumVerts + 4].mTexCoord1[1];
        v109 = v55->mVerts[(int)mNumVerts + 4].mNormal.y;
        v110 = v55->mVerts[(int)mNumVerts + 4].mNormal.z;
        v106->mPrevVertR.mNormal.x = v55->mVerts[(int)mNumVerts + 4].mNormal.x;
        v106->mPrevVertR.mNormal.y = v109;
        v106->mPrevVertR.mNormal.z = v110;
        v111 = v55->mVerts[(int)mNumVerts + 4].mTangent.y;
        v112 = v55->mVerts[(int)mNumVerts + 4].mTangent.z;
        v106->mPrevVertR.mTangent.x = v55->mVerts[(int)mNumVerts + 4].mTangent.x;
        v106->mPrevVertR.mTangent.y = v111;
        v106->mPrevVertR.mTangent.z = v112;
        v106->mPrevVertR.mColour = v55->mVerts[(int)mNumVerts + 4].mColour;
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
          v7->mPrev = v7;
          v7->mNext = v7;
          v10 = v7->mPrev;
          v11 = v7->mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v7->mPrev = v7;
          v7->mNext = v7;
          v7->mPrev = (UFG::qNode<Render::PolyStrip,Render::PolyStrip> *)unk_142366958;
          unk_142366958 = v7;
          --unk_142366964;
        }
      }
      this->mStrip = 0i64;
    }
  }
}

